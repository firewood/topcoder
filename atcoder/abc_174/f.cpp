// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

typedef pair<int, int> II;

class BIT {
	std::vector<int> bit;
	int size;
public:
	BIT() { }
	BIT(int sz) { init(sz); }
	void init(int sz) {
		bit = std::vector<int>((size = sz) + 1);
	}
	int sum(int i) {
		int s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(int i, int x) {
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, q, l, r;
		cin >> n >> q;
		if (n <= 0) return 0;
		vector<int> col(n), last(n), ans(q);
		for (int i = 0; i < n; ++i) {
			cin >> col[i];
			--col[i];
		}
		vector<pair<II, int>> query(q);
		for (int t = 0; t < q; ++t) {
			query[t].second = t;
			cin >> query[t].first.second >> query[t].first.first;
		}
		sort(query.begin(), query.end());
		int qi = 0;
		BIT bit(n);
		for (int i = 0; i < n; ++i) {
			if (last[col[i]]) {
				bit.add(last[col[i]], -1);
			}
			last[col[i]] = i + 1;
			bit.add(last[col[i]], 1);
			while (qi < q && query[qi].first.first == i + 1) {
				ans[query[qi].second] = bit.sum(i + 1) - bit.sum(query[qi].first.second - 1);
				++qi;
			}
		}
		for (int t = 0; t < q; ++t) {
			cout << ans[t] << endl;
		}
	}
	return 0;
}
