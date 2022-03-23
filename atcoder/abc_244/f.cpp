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

static const int INF = 1LL << 29;

int64_t solve(int N, int M, std::vector<int> u, std::vector<int> v) {
	int sz = 1 << N, ans = 0;
	vector<vector<int>> e(N);
	for (int i = 0; i < M; ++i) {
		e[u[i]].emplace_back(v[i]);
		e[v[i]].emplace_back(u[i]);
	}
	vector<vector<int>> min_cost(sz, vector<int>(N, INF));
	vector<II> q;
	for (int i = 0; i < N; ++i) {
		min_cost[1 << i][i] = 1;
		q.emplace_back(II(1 << i, i));
	}
	for (int cost = 2; !q.empty(); ++cost) {
		vector<II> nq;
		for (auto kv : q) {
			int b = kv.first, node = kv.second;
			for (auto next_node : e[node]) {
				int nb = b ^ (1 << next_node);
				if (cost < min_cost[nb][next_node]) {
					min_cost[nb][next_node] = cost;
					nq.emplace_back(II(nb, next_node));
				}
			}
		}
		q = nq;
	}
	for (int i = 1; i < sz; ++i) {
		ans += *min_element(min_cost[i].begin(), min_cost[i].end());
	}
	return ans;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> u(M), v(M);
	for (int i = 0; i < M; i++) {
		std::cin >> u[i] >> v[i];
		--u[i], --v[i];
	}
	cout << solve(N, M, u, v) << endl;
	return 0;
}
