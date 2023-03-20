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
#include <atcoder/fenwicktree>
#include <atcoder/segtree>

using namespace std;

typedef pair<int64_t, int64_t> II;

static const int64_t INF = 1LL << 60;

II op(II a, II b) { return min(a, b); }
II e() { return { INF, INF }; }

struct Tree {
	int64_t _size;
	vector<vector<II>> _edges;
	vector<int64_t> visited;
	vector<int64_t> weight;
	vector<int> node_to_index;
	vector<int> edge_left;
	vector<int> edge_right;
	atcoder::fenwick_tree<int64_t> fw;
	atcoder::segtree<II, op, e> segtree;

	Tree(int64_t size) : _size(size), _edges(size), node_to_index(size), edge_left(size), edge_right(size), fw(400004), segtree(400004) { }

	void build_edges(const vector<int64_t>& a, const vector<int64_t>& b, const vector<int64_t>& c) {
		weight = c;
		for (size_t i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i], i);
			_edges[b[i]].emplace_back(a[i], i);
		}
	}

	// euler tour
	void dfs(int node, int parent, int depth) {
		node_to_index[node] = int(visited.size());
		segtree.set(int(visited.size()), II(depth, node));
		visited.emplace_back(node);
		for (auto kv : _edges[node]) {
			if (kv.first != parent) {
				edge_left[kv.second] = int(visited.size());
				fw.add(int(visited.size()), weight[kv.second]);
				dfs(int(kv.first), node, depth + 1);
				edge_right[kv.second] = int(visited.size());
				fw.add(int(visited.size()), -weight[kv.second]);
				segtree.set(int(visited.size()), II(depth, node));
				visited.emplace_back(node);
			}
		}
	}
};

vector<int64_t> solve(int64_t N, vector<int64_t> u, vector<int64_t> v, vector<int64_t> w, int64_t Q, vector<int64_t> types, vector<int64_t> a, vector<int64_t> b) {
	vector<int64_t> ans;
	Tree tree(N);
	tree.build_edges(u, v, w);
	tree.dfs(0, -1, 0);
	for (int q = 0; q < Q; ++q) {
		if (types[q] == 1) {
			int64_t i = a[q] - 1, diff = b[q] - w[i];
			w[i] += diff;
			tree.fw.add(tree.edge_left[i], diff);
			tree.fw.add(tree.edge_right[i], -diff);
		} else {
			int64_t from = a[q] - 1, to = b[q] - 1;
			if (tree.node_to_index[from] > tree.node_to_index[to]) {
				swap(from, to);
			}
			int64_t lca = tree.segtree.prod(tree.node_to_index[from], tree.node_to_index[to] + 1).second;
			int64_t cost = tree.fw.sum(0, tree.node_to_index[from] + 1) + tree.fw.sum(0, tree.node_to_index[to] + 1) - tree.fw.sum(0, tree.node_to_index[lca] + 1) * 2;
			ans.emplace_back(cost);
		}
	}
	return ans;
}

int main() {
	int64_t N, Q;
	cin >> N;
	vector<int64_t> u(N - 1), v(N - 1), w(N - 1);
	for (int i = 0; i < N - 1; i++) {
		cin >> u[i] >> v[i] >> w[i];
		--u[i]; --v[i];
	}
	cin >> Q;
	vector<int64_t> types(Q), a(Q), b(Q);
	for (int i = 0; i < Q; ++i) {
		cin >> types[i] >> a[i] >> b[i];
	}
	vector<int64_t> ans = solve(N, u, v, w, Q, types, a, b);
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;
}
