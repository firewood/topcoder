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

typedef pair<int, int> II;
static const int INF = 1 << 30;

// 01-BFS
int solve(int N, int M, int K, std::vector<int> u, std::vector<int> v, std::vector<int> a, std::vector<int> s) {
	vector<vector<vector<int>>> edges(2, vector<vector<int>>(N + 2));
	vector<vector<int>> costs(2, vector<int>(N + 2, INF));
	vector<int> has_sw(N + 2);
	deque<II> q;
	for (int i = 0; i < M; ++i) {
		edges[a[i]][u[i]].emplace_back(v[i]);
		edges[a[i]][v[i]].emplace_back(u[i]);
	}
	for (auto x : s) {
		has_sw[x] = 1;
	}
	costs[1][1] = 0;
	q.push_front(II(1, 1));
	while (!q.empty()) {
		II top = q.front();
		q.pop_front();
		int state = top.first, node = top.second, cost = costs[state][node];
		for (const auto next_node : edges[state][node]) {
			const int next_cost = cost + 1;
			if (next_cost < costs[state][next_node]) {
				costs[state][next_node] = next_cost;
				q.push_back(II(state, next_node));
			}
		}
		if (has_sw[node] && cost < costs[!state][node]) {
			costs[!state][node] = cost;
			q.push_front(II(!state, node));
		}
	}
	int ans = min(costs[0][N], costs[1][N]);
	return ans < INF ? ans : -1;
}

int main() {
	int64_t N, M, K;
	std::cin >> N >> M >> K;
	std::vector<int> u(M), v(M), a(M);
	for (int i = 0; i < M; i++) {
		std::cin >> u[i] >> v[i] >> a[i];
	}
	std::vector<int> s(K);
	for (int i = 0; i < K; i++) {
		std::cin >> s[i];
	}
	cout << solve(N, M, K, u, v, a, s) << endl;
	return 0;
}
