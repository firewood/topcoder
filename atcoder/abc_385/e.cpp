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

int solve(int N, std::vector<int> u, std::vector<int> v) {
	int ans = N;

	vector<vector<int>> edges(N);
	for (int i = 0; i < int(u.size()); ++i) {
		edges[u[i]].emplace_back(v[i]);
		edges[v[i]].emplace_back(u[i]);
	}

	for (int i = 0; i < N; ++i) {
		vector<int> cnt;
		for (const auto &x : edges[i]) {
			cnt.emplace_back(int(edges[x].size()));
		}
		sort(cnt.rbegin(), cnt.rend());
		for (int j = 0; j < int(cnt.size()); ++j) {
			ans = min(ans, N - (1 + cnt[j] * (j + 1)));
		}
	}

	return ans;
}

int main() {
	int N;
	cin >> N;
	vector<int> u(N-1), v(N-1);
	for (int i = 0; i < N-1; i++) {
		std::cin >> u[i] >> v[i];
		--u[i];
		--v[i];
	}
	cout << solve(N, u, v) << endl;
	return 0;
}
