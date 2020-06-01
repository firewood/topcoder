// L.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;
II DEF_VAL = make_pair(1 << 30, 1 << 30);

template<typename T, size_t SIZE, const T& Compare(const T&, const T&)>
class SegmentTree {
	vector<T> val;
public:
	SegmentTree() : val(SIZE * 2, DEF_VAL) { }
	T get(int a, int b, int l = 0, int r = SIZE, size_t i = 1) {
		if (r <= a || b <= l) return DEF_VAL;
		if (a <= l && r <= b) return val[i];
		return Compare(get(a, b, l, (l + r) / 2, i * 2), get(a, b, (l + r) / 2, r, i * 2 + 1));
	}
	void update(size_t i, T value) {
		i += SIZE;
		val[i] = Compare(val[i], value);
		while (i > 1) i >>= 1, val[i] = Compare(val[i * 2], val[i * 2 + 1]);
	}
};
typedef SegmentTree<II, 1 << 18, min> MinSegTree;

int main(int argc, char* argv[]) {
	int n, k, d;
	cin >> n >> k >> d;
	vector<int> a(n + 1), mn(n + 1);
	MinSegTree st;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		st.update(i + 1, II(a[i], i));
	}
	int right = n - (k - 1) * d - 1;
	if (right < 0) {
		cout << -1 << endl;
	} else {
		int prev = -d;
		for (int i = 0; i < k; ++i) {
			II next = st.get(prev + d + 1, right + 2);
			cout << " " << next.first;
			prev = next.second;
			right += d;
		}
		cout << endl;
	}
	return 0;
}
