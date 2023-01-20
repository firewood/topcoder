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

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> c, std::vector<int64_t> a, std::vector<int64_t> b, std::vector<int64_t> r) {
	int64_t ans = 0;
	vector<int64_t> vis(N);
	vector<vector<II>> edges(N);
	for (int i = 0; i < M; ++i) {
		edges[a[i]].emplace_back(b[i], r[i]);
		edges[b[i]].emplace_back(a[i], r[i]);
	}

	priority_queue<II, vector<II>, greater<>> q;
	for (int i = 0; i < N; ++i) {
		q.emplace(c[i], i);
	}
	while (!q.empty()) {
		int64_t cost = q.top().first, i = q.top().second;
		q.pop();
		if (vis[i]) continue;
		vis[i] = 1;
		ans += cost;
		for (auto kv : edges[i]) {
			int64_t next = kv.first, road_cost = kv.second;
			if (vis[next]) continue;
			q.emplace(road_cost, next);
		}
	}
	return ans;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> c(N);
	for (int i = 0; i < N; i++) {
		std::cin >> c[i];
	}
	std::vector<int64_t> a(M), b(M), r(M);
	for (int i = 0; i < M; i++) {
		std::cin >> a[i] >> b[i] >> r[i];
		--a[i]; --b[i];
	}
	cout << solve(N, M, c, a, b, r) << endl;
	return 0;
}
