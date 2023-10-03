#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <atcoder/lazysegtree>

using namespace std;

struct Data {
	int left[2], right[2], mx[2], len;
	Data() : left{ 0,0 }, right{ 0,0 }, mx{ 0,0 }, len(0) { }
	Data(int x) : left{ 0,0 }, right{ 0,0 }, mx{ 0,0 }, len(1) {
		left[x] = right[x] = mx[x] = 1;
	}

	Data flipped() const {
		Data res(*this);
		swap(res.left[0], res.left[1]);
		swap(res.right[0], res.right[1]);
		swap(res.mx[0], res.mx[1]);
		return res;
	}

	static Data merge(const Data left, const Data right) {
		Data res;
		for (int i = 0; i < 2; ++i) {
			res.left[i] = left.left[i] + (left.left[i] == left.len ? right.left[i] : 0);
			res.right[i] = right.right[i] + (right.right[i] == right.len ? left.right[i] : 0);
			res.mx[i] = max({ left.mx[i], right.mx[i], left.right[i] + right.left[i] });
		}
		res.len = left.len + right.len;
		return res;
	}

	static Data empty() {
		return Data();
	}

	static Data mapping(int a, Data b) {
		return a ? b.flipped() : b;
	}

	static int composition(int a, int b) {
		return a ^ b;
	}

	static int id() {
		return 0;
	}
};

int main() {
	int N, Q, c, L, R;
	cin >> N >> Q;
	string x;
	cin >> x;

	Data data;
	vector<Data> init(N);
	for (int i = 0; i < N; ++i) {
		init[i] = Data(x[i] != '0');
	}
	atcoder::lazy_segtree<Data, Data::merge, Data::empty, int, Data::mapping, Data::composition, Data::id> seg(init);

	for (int q = 0; q < Q; ++q) {
		cin >> c >> L >> R;
		--L;
		if (c == 1) {
			seg.apply(L, R, 1);
		}
		if (c == 2) {
			int ans = seg.prod(L, R).mx[1];
			cout << ans << endl;
		}
	}
	return 0;
}
