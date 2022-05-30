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

using namespace std;

class BIT {
	std::vector<int64_t> bit;
	int64_t size;
public:
	BIT() { }
	BIT(int64_t sz) { init(sz); }
	void init(int64_t sz) {
		bit = std::vector<int64_t>((size = sz) + 1);
	}
	int64_t sum(int64_t i) {
		int64_t s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(int64_t i, int64_t x) {
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

int main() {
	int64_t N, M, Q;
	cin >> N >> M >> Q;
	vector<int64_t> t(Q), a(Q), b(Q), c(Q), ans(Q);
	BIT bit(200002);
	map<int64_t, int> const_rows;
	map<int, vector<int>> recalc_indexes;
	for (int i = 0; i < Q; ++i) {
		cin >> t[i];
		switch (t[i]) {
		case 1:
			cin >> a[i] >> b[i] >> c[i];
			bit.add(a[i], c[i]);
			bit.add(b[i] + 1, -c[i]);
			break;
		case 2:
			cin >> a[i] >> c[i];
			const_rows[a[i]] = i;
			break;
		case 3:
			cin >> a[i] >> b[i];
			ans[i] = bit.sum(b[i]);
			auto it = const_rows.find(a[i]);
			if (it != const_rows.end()) {
				recalc_indexes[it->second].emplace_back(i);
			}
			break;
		}
	}
	bit = BIT(200002);
	for (int i = 0; i < Q; ++i) {
		switch (t[i]) {
		case 1:
			bit.add(a[i], c[i]);
			bit.add(b[i] + 1, -c[i]);
			break;
		case 2:
			for (auto x : recalc_indexes[i]) {
				ans[x] += c[i] - bit.sum(b[x]);
			}
			break;
		case 3:
			cout << ans[i] << endl;
			break;
		}
	}
	return 0;
}
