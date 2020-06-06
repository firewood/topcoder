// K.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef pair<int, int> II;
typedef pair<int, II> III;

typedef pair<int, int> II;
II DEF_VAL = make_pair(0, 0);

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
//		val[i] = Compare(val[i], value);
		val[i] = value;
		while (i > 1) i >>= 1, val[i] = Compare(val[i * 2], val[i * 2 + 1]);
	}
};
typedef SegmentTree<II, 1 << 18, max> MaxSegTree;

int main() {
	int n, m, a;
	cin >> n;
	vector<vector<int>> t(n);
	vector<int> k(n), c(n);
	for (int i = 0; i < n; ++i) {
		cin >> k[i];
		t[i].resize(k[i]);
		for (int j = 0; j < k[i]; ++j) {
			cin >> t[i][j];
		}
	}

	MaxSegTree st[2];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2 && j < k[i]; ++j) {
			st[j].update(i, II(t[i][j], i));
			c[i] += 1;
		}
	}

	cin >> m;
	for (int w = 0; w < m; ++w) {
		cin >> a;
		II x(-1, -1), y(-1, -1);
		x = st[0].get(0, n);
		if (a >= 2) {
			y = st[1].get(0, n);
		}
		if (y.first > x.first) {
			cout << y.first << endl;
			int i = y.second;
			x = II(-1, -1);
			if (c[i] < k[i]) {
				x = II(t[i][c[i]], i);
				c[i] += 1;
			}
			st[1].update(i, x);
		} else {
			cout << x.first << endl;
			int i = x.second;
			y = st[1].get(i, i + 1);
			if (y.first > 0) {
				st[0].update(i, y);
			}
			x = II(-1, -1);
			if (c[i] < k[i]) {
				x = II(t[i][c[i]], i);
				c[i] += 1;
			}
			st[y.first > 0].update(i, x);
		}
	}
	return 0;
}
