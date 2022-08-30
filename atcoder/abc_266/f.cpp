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

struct Tree {
	int64_t size;
	vector<vector<pair<int, int>>> edges;
	vector<int> vis;
	vector<int> node_history;
	vector<int> edge_history;
	vector<int> dis;

	Tree(int64_t size_) : size(size_), edges(size), vis(size) { }

	void build_bidirectional_edges(std::vector<int>& from, std::vector<int>& to) {
		for (size_t i = 0; i < from.size(); ++i) {
			edges[from[i]].emplace_back(make_pair(int(to[i]), int(i)));
			edges[to[i]].emplace_back(make_pair(int(from[i]), int(i)));
		}
		dis.resize(from.size());
	}

	void dfs(int n, int from, int from_ei) {
		node_history.emplace_back(from);
		edge_history.emplace_back(from_ei);
		if (!vis[n]) {
			vis[n] = 1;
			for (auto kv : edges[n]) {
				int to = kv.first, ei = kv.second;
				if (to != from && vis[to] != 2) {
					dfs(to, n, ei);
				}
			}
		} else {
			for (int i = int(edge_history.size()) - 1; i >= 0; --i) {
				dis[edge_history[i]] = 1;
				if (node_history[i] == n) break;
			}
		}
		node_history.pop_back();
		edge_history.pop_back();
		vis[n] = 2;
	}
};

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	UnionFind(int size) : _parent(size, -1), _size(size, 1) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b); if (ra == rb) { return; }
		if (_size[ra] < _size[rb]) swap(ra, rb);
		_parent[rb] = ra, _size[ra] += _size[rb];
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};

void solve(int N, std::vector<int> u, std::vector<int> v, int Q, std::vector<int> x, std::vector<int> y) {
	Tree tree(N);
	tree.build_bidirectional_edges(u, v);
	tree.dfs(0, -1, -1);

	UnionFind uf(N);
	for (int i = 0; i < N; ++i) {
		if (!tree.dis[i]) {
			uf.unite(u[i], v[i]);
		}
	}

	for (int i = 0; i < Q; ++i) {
		bool ans = uf.root(x[i]) == uf.root(y[i]);
		cout << (ans ? "Yes" : "No") << endl;
	}
}

int main() {
	int N, Q;
	std::cin >> N;
	std::vector<int> u(N), v(N);
	for (int i = 0; i < N; i++) {
		std::cin >> u[i] >> v[i];
		--u[i], --v[i];
	}
	std::cin >> Q;
	std::vector<int> x(Q), y(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> x[i] >> y[i];
		--x[i], --y[i];
	}
	solve(N, u, v, Q, x, y);
	return 0;
}
