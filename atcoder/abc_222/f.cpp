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

typedef long double LD;
typedef pair<int64_t, int64_t> II;
typedef pair<int64_t, II> III;

static const int64_t INF = 1LL << 60;

struct Tree {
	int64_t _size;
	vector<vector<II>> _edges;
	vector<int64_t> _edge_costs;
	vector<int64_t> _vis;
	vector<vector<II>> _subtree_costs;

	Tree(int64_t size) : _size(size), _edges(size), _vis(size), _subtree_costs(size) { }

	void build_bidirectional_edges(const vector<int64_t>& from, const vector<int64_t>& to, const vector<int64_t>& costs) {
		for (size_t i = 0; i < from.size(); ++i) {
			_edges[from[i]].emplace_back(to[i], costs[i]);
			_edges[to[i]].emplace_back(from[i], costs[i]);
		}
	}

	int64_t dfs1(int64_t n, const vector<int64_t>& node_costs) {
		_vis[n] += 1;
		int64_t max_subtree_cost = 0;
		for (auto kv : _edges[n]) {
			if (_vis[kv.first] <= 0) {
				int64_t subtree_cost = dfs1(kv.first, node_costs) + kv.second;
				max_subtree_cost = max(max_subtree_cost, subtree_cost);
				_subtree_costs[n].emplace_back(subtree_cost, kv.first);
			}
		}
		_subtree_costs[n].emplace_back(0, -1);
		sort(_subtree_costs[n].rbegin(), _subtree_costs[n].rend());
		return max(max_subtree_cost, node_costs[n]);
	}

	int64_t dfs2(int64_t n, int64_t max_cost, const vector<int64_t>& node_costs, vector<int64_t>& max_costs) {
		_vis[n] += 1;
		int64_t mx = 0;
		for (auto kv : _edges[n]) {
			if (_vis[kv.first] <= 1) {
				int is_next_node_max_cost = _subtree_costs[n].front().second == kv.first;
				int64_t max_other_tree_cost = max({ max_cost, node_costs[n], _subtree_costs[n][is_next_node_max_cost].first });
				int64_t cost = dfs2(kv.first, max_other_tree_cost + kv.second, node_costs, max_costs) + kv.second;
				mx = max(mx, cost);
			}
		}
		max_costs[n] = max(mx, max_cost);
		return max(mx, node_costs[n]);
	}
};

vector<int64_t> solve(int64_t N, std::vector<int64_t> A, std::vector<int64_t> B, std::vector<int64_t> C, std::vector<int64_t> D) {
	vector<int64_t> ans(N);
	Tree tree(N);
	tree.build_bidirectional_edges(A, B, C);
	tree.dfs1(0, D);
	tree.dfs2(0, 0, D, ans);
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N - 1), B(N - 1), C(N - 1);
	for (int i = 0; i < N - 1; i++) {
		std::cin >> A[i] >> B[i] >> C[i];
		--A[i]; --B[i];
	}
	std::vector<int64_t> D(N);
	for (int i = 0; i < N; i++) {
		std::cin >> D[i];
	}
	vector<int64_t> ans = solve(N, A, B, C, D);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
