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
	vector<int64_t> _h;
	vector<int64_t> edge_costs;
	vector<vector<pair<int64_t, int64_t>>> edges;

	Dijkstra(int64_t size_) : size(size_), edges(size) { }

	void build_unidirectional_edges(std::vector<int64_t>& from, std::vector<int64_t>& to, std::vector<int64_t> costs = {}) {
		edge_costs = !costs.empty() ? costs : std::vector<int64_t>(from.size(), 1);
		for (int i = 0; i < from.size(); ++i) {
			edges[from[i]].emplace_back(make_pair(to[i], i));
		}
	}

	void build_bidirectional_edges(std::vector<int64_t>& from, std::vector<int64_t>& to, std::vector<int64_t> costs = {}) {
		edge_costs = !costs.empty() ? costs : std::vector<int64_t>(from.size(), 1);
		for (int i = 0; i < from.size(); ++i) {
			edges[from[i]].emplace_back(make_pair(to[i], i));
			edges[to[i]].emplace_back(make_pair(from[i], i));
		}
	}

	vector<int64_t> get_min_costs(int64_t start) {
		vector<int64_t> min_costs(size, INF);
		priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>, greater<>> q;
		min_costs[start] = 0;
		q.emplace(make_pair(0, start));
		while (!q.empty()) {
			int64_t cost = q.top().first, node = q.top().second;
			q.pop();
			if (cost > min_costs[node]) continue;
			for (auto kv : edges[node]) {
				int64_t next_node = kv.first, edge_index = kv.second;
				int64_t next_cost = cost + edge_costs[edge_index];
				if (next_cost < min_costs[next_node]) {
					min_costs[next_node] = next_cost;
					q.emplace(make_pair(next_cost, next_node));
				}
			}
		}
		return min_costs;
	}

	vector<int64_t> get_max_costs(int64_t start) {
		vector<int64_t> max_costs(size, -INF);
		priority_queue<pair<int64_t, int64_t>> q;
		max_costs[start] = 0;
		q.emplace(make_pair(0, start));
		while (!q.empty()) {
			int64_t cost = q.top().first, node = q.top().second;
			q.pop();
			if (cost < max_costs[node]) continue;
			for (auto kv : edges[node]) {
				int64_t next_node = kv.first;
				int64_t diff = _h[node] - _h[next_node];
				int64_t next_cost = cost + (diff >= 0 ? diff : diff * 2);
				if (next_cost > max_costs[next_node]) {
					max_costs[next_node] = next_cost;
					q.emplace(make_pair(next_cost, next_node));
				}
			}
		}
		return max_costs;
	}
};

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> H, std::vector<int64_t> U, std::vector<int64_t> V) {
	Dijkstra dijkstra(N);
	dijkstra._h = H;
	dijkstra.build_bidirectional_edges(U, V);
	vector<int64_t> costs = dijkstra.get_max_costs(0);
	return *max_element(costs.begin(), costs.end());
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> H(N);
	for (int i = 0; i < N; i++) {
		std::cin >> H[i];
	}
	std::vector<int64_t> U(M), V(M);
	for (int i = 0; i < M; i++) {
		std::cin >> U[i] >> V[i];
		--U[i];
		--V[i];
	}
	cout << solve(N, M, H, U, V) << endl;
	return 0;
}
