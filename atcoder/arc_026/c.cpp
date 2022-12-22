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

typedef pair<int64_t, int64_t> II;

int64_t solve(int64_t N, int64_t L, std::vector<int64_t> l, std::vector<int64_t> r, std::vector<int64_t> c) {
	map<int64_t, int64_t> m;
	vector<II> v;
	for (int i = 0; i < N; ++i) {
		v.emplace_back(r[i], i);
	}
	sort(v.begin(), v.end());
	m[0] = 0;
	for (auto kv : v) {
		int64_t i = kv.second;
		auto it = m.lower_bound(l[i]);
		int64_t cost = it->second + c[i];
		while (m.rbegin()->second > cost) {
			m.erase(m.rbegin()->first);
		}
		if (m.rbegin()->first < r[i]) {
			m[r[i]] = cost;
		}
	}
	return m[L];
}

int main() {
	int64_t N, L;
	std::cin >> N >> L;
	std::vector<int64_t> l(N), r(N), c(N);
	for (int i = 0; i < N; i++) {
		std::cin >> l[i] >> r[i] >> c[i];
	}
	cout << solve(N, L, l, r, c) << endl;
	return 0;
}
