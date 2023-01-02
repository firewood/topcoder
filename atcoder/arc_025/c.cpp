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

static const int64_t INF = 1LL << 60;

struct Dijkstra {
	int64_t size;
	vector<vector<pair<int, int64_t>>> edges;
	vector<int> used_edges;

	Dijkstra(int64_t size_) : size(size_), edges(size) { }

	void build_bidirectional_edges(std::vector<int64_t>& from, std::vector<int64_t>& to, std::vector<int64_t> costs) {
		for (size_t i = 0; i < from.size(); ++i) {
			edges[from[i]].emplace_back(make_pair(int(to[i]), costs[i]));
			edges[to[i]].emplace_back(make_pair(int(from[i]), costs[i]));
		}
	}

	int64_t dijkstra(int64_t start, int64_t R, int64_t T) {
		int64_t cnt = 0;
		vector<int64_t> min_r_costs(size, INF), min_t_costs(size, INF);
		priority_queue<pair<int64_t, pair<int, int>>, vector<pair<int64_t, pair<int, int>>>, greater<>> q;
		auto push_rabbit = [&](int64_t cost, int64_t node) {
			for (auto kv : edges[node]) {
				int64_t next_node = kv.first, next_cost = cost + kv.second * T * 2;
				if (next_cost < min_r_costs[next_node]) {
					min_r_costs[next_node] = next_cost;
					q.emplace(make_pair(next_cost, make_pair(int(next_node), 0)));
				}
			}
		};
		auto push_turtle = [&](int64_t cost, int64_t node) {
			for (auto kv : edges[node]) {
				int64_t next_node = kv.first, next_cost = cost + kv.second * R * 2;
				if (next_cost < min_t_costs[next_node]) {
					min_t_costs[next_node] = next_cost;
					q.emplace(make_pair(next_cost, make_pair(int(next_node), 1)));
				}
			}
		};
		min_r_costs[start] = 0;
		min_t_costs[start] = 0;
		push_rabbit(0, start);
		push_turtle(1, start);
		int nodes = 0;
		while (!q.empty()) {
			int64_t cost = q.top().first, node = q.top().second.first, type = q.top().second.second;
			q.pop();
			if (type == 0) {
				if (cost == min_r_costs[node]) {
					cnt += nodes - (T > R);
					push_rabbit(cost, node);
				}
			} else {
				if (cost == min_t_costs[node]) {
					++nodes;
					push_turtle(cost, node);
				}
			}
		}
		return cnt;
	}
};

int64_t solve(int64_t N, int64_t M, int64_t R, int64_t T, std::vector<int64_t> a, std::vector<int64_t> b, std::vector<int64_t> c) {
	int64_t ans = 0;
	Dijkstra dijkstra(N);
	dijkstra.build_bidirectional_edges(a, b, c);
	for (int i = 0; i < N; ++i) {
		ans += dijkstra.dijkstra(i, R, T);
	}
	return ans;
}

int main() {
	int64_t N, M, R, T;
	std::cin >> N >> M >> R >> T;
	std::vector<int64_t> a(M), b(M), c(M);
	for (int i = 0; i < M; i++) {
		std::cin >> a[i] >> b[i] >> c[i];
		--a[i]; --b[i];
	}
	cout << solve(N, M, R, T, a, b, c) << endl;
	return 0;
}
