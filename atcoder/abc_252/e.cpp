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
	vector<int64_t> edge_costs;
	vector<vector<pair<int, int>>> edges;
	vector<int> used_edges;
	vector<int64_t> min_costs;

	Dijkstra(int64_t size_) : size(size_), edges(size) { }

	void build_unidirectional_edges(std::vector<int64_t>& from, std::vector<int64_t>& to, std::vector<int64_t> costs = {}) {
		edge_costs = !costs.empty() ? costs : std::vector<int64_t>(from.size(), 1);
		for (size_t i = 0; i < from.size(); ++i) {
			edges[from[i]].emplace_back(make_pair(int(to[i]), int(i)));
		}
	}

	void build_bidirectional_edges(std::vector<int64_t>& from, std::vector<int64_t>& to, std::vector<int64_t> costs = {}) {
		edge_costs = !costs.empty() ? costs : std::vector<int64_t>(from.size(), 1);
		for (size_t i = 0; i < from.size(); ++i) {
			edges[from[i]].emplace_back(make_pair(int(to[i]), int(i)));
			edges[to[i]].emplace_back(make_pair(int(from[i]), int(i)));
		}
	}

	vector<int> dijkstra(int64_t start) {
		priority_queue<pair<int64_t, pair<int, int>>, vector<pair<int64_t, pair<int, int>>>, greater<>> q;
		auto push_edges = [&](int64_t cost, int64_t node) {
			for (auto kv : edges[node]) {
				int64_t next_node = kv.first, next_cost = cost + edge_costs[kv.second];
				if (next_cost < min_costs[next_node]) {
					min_costs[next_node] = next_cost;
					q.emplace(make_pair(next_cost, make_pair(int(next_node), kv.second)));
				}
			}
		};
		used_edges.clear();
		min_costs = vector<int64_t>(size, 1LL << 60);
		min_costs[start] = 0;
		push_edges(0, start);
		while (!q.empty()) {
			int64_t cost = q.top().first, node = q.top().second.first, edge = q.top().second.second;
			q.pop();
			if (cost == min_costs[node]) {
				used_edges.emplace_back(int(edge));
				push_edges(cost, node);
			}
		}
		return used_edges;
	}

	vector<int64_t>& get_min_costs(int64_t start) {
		dijkstra(start);
		return min_costs;
	}

	vector<int>& get_used_edges(int64_t start) {
		dijkstra(start);
		return used_edges;
	}
};

vector<int> solve(int64_t N, int64_t M, std::vector<int64_t> A, std::vector<int64_t> B, std::vector<int64_t> C) {
	Dijkstra tree(N);
	tree.build_bidirectional_edges(A, B, C);
	return tree.get_used_edges(0);
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> A(M), B(M), C(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i] >> C[i];
		--A[i];
		--B[i];
	}
	vector<int> ans = solve(N, M, A, B, C);
	for (size_t i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << ans[i] + 1;
	}
	cout << endl;
	return 0;
}
