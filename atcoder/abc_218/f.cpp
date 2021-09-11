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
#include <bitset>

using namespace std;

static const int64_t INF = 1LL << 60;

struct Dijkstra {
	int64_t size;
	vector<int64_t> edge_from;
	vector<int64_t> edge_to;
	vector<int64_t> edge_cost;
	vector<vector<int64_t>> edge_index;

	Dijkstra(int64_t size_) : size(size_), edge_index(size_) { }

	void build_unidirectional_edges(std::vector<int64_t>& from, std::vector<int64_t>& to, std::vector<int64_t> cost = {}) {
		edge_from = from;
		edge_to = to;
		edge_cost = !cost.empty() ? cost : std::vector<int64_t>(from.size(), 1);
		for (int i = 0; i < from.size(); ++i) {
			edge_index[from[i]].emplace_back(i);
		}
	}

	vector<int64_t> get_min_costs(int64_t start) {
		vector<int64_t> min_costs(size, INF);
		priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>, greater<>> q;
		min_costs[start] = 0;
		q.emplace(make_pair(0, start));
		while (!q.empty()) {
			auto top = q.top();
			q.pop();
			int64_t cost = top.first, node = top.second;
			if (cost > min_costs[node]) continue;
			for (auto ei : edge_index[node]) {
				int64_t next_node = edge_to[ei];
				int64_t next_cost = cost + edge_cost[ei];
				if (next_cost < min_costs[next_node]) {
					min_costs[next_node] = next_cost;
					q.emplace(make_pair(next_cost, next_node));
				}
			}
		}
		return min_costs;
	}

	vector<set<int64_t>> get_passed_edges(int64_t start) {
		vector<int64_t> min_costs(size, INF);
		vector<set<int64_t>> passed_edges(size);
		priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>, greater<>> q;
		min_costs[start] = 0;
		q.emplace(make_pair(0, start));
		while (!q.empty()) {
			auto top = q.top();
			q.pop();
			int64_t cost = top.first, node = top.second;
			if (cost > min_costs[node]) continue;
			for (auto ei : edge_index[node]) {
				int64_t next_node = edge_to[ei];
				int64_t next_cost = cost + edge_cost[ei];
				if (next_cost < min_costs[next_node]) {
					min_costs[next_node] = next_cost;
					passed_edges[next_node] = passed_edges[node];
					passed_edges[next_node].insert(ei);
					q.emplace(make_pair(next_cost, next_node));
				}
			}
		}
		return passed_edges;
	}
};

vector<int64_t> solve(int N, int M, std::vector<int64_t> s, std::vector<int64_t> t) {
	Dijkstra dijkstra(N);
	dijkstra.build_unidirectional_edges(s, t);
	set<int64_t> passed_edges = dijkstra.get_passed_edges(0)[N - 1];
	int64_t min_cost = passed_edges.empty() ? -1 : passed_edges.size();
	vector<int64_t> ans(M);
	for (int i = 0; i < M; ++i) {
		if (passed_edges.find(i) == passed_edges.end()) {
			ans[i] = min_cost;
		} else {
			dijkstra.edge_cost[i] = INF;
			ans[i] = dijkstra.get_min_costs(0)[N - 1];
			dijkstra.edge_cost[i] = 1;
		}
	}
	return ans;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int64_t> s(M), t(M);
	for (int i = 0; i < M; i++) {
		std::cin >> s[i] >> t[i];
		s[i]--;
		t[i]--;
	}
	auto ans = solve(N, M, s, t);
	for (auto cost : ans) {
		cout << (cost < INF ? cost : -1) << endl;
	}
	return 0;
}
