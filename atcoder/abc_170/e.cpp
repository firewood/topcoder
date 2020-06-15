#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <cmath>
#include <cassert>

using namespace std;

template<typename T, size_t SIZE, T DEF_VAL, const T& Compare(const T&, const T&)>
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
		val[i] = value;
		while (i > 1) i >>= 1, val[i] = Compare(val[i * 2], val[i * 2 + 1]);
	}
};
typedef SegmentTree<int, 1 << 18, 1 << 30, min> MinSegTree;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, q, a, b, c, d;
		cin >> n >> q;
		if (n < 0) return 0;
		vector<map<int, int>> m(200002);
		vector<int> r(n), g(n);
		MinSegTree st;
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			r[i] = a;
			g[i] = b;
			m[b][a] += 1;
		}
		for (int i = 1; i <= 200000; ++i) {
			if (!m[i].empty()) {
				st.update(i, m[i].rbegin()->first);
			}
		}
		for (int tt = 0; tt < q; ++tt) {
			cin >> c >> d;
			--c;
			int prev_g = g[c];
			bool f = false;
			{
				auto it = m[prev_g].rbegin();
				f = it->first == r[c] && it->second == 1;
			}
			if (m[prev_g][r[c]] == 1) {
				m[prev_g].erase(r[c]);
			} else {
				m[prev_g][r[c]] -= 1;
			}
			if (f) {
				int r = 1 << 30;
				if (!m[prev_g].empty()) {
					r = m[prev_g].rbegin()->first;
				}
				st.update(prev_g, r);
			}
			g[c] = d;
			f = m[d].empty() || m[d].rbegin()->first < r[c];
			m[d][r[c]] += 1;
			if (f) {
				st.update(d, r[c]);
			}
			cout << st.get(1, 200001) << endl;
		}
	}
	return 0;
}
