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

typedef pair<int, int64_t> II;

static const int64_t INF = 1LL << 60;

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

vector<int64_t> solve(int N, int M, int Q, std::vector<int> A, std::vector<int> B, std::vector<int64_t> C, std::vector<int> X, std::vector<int> Y) {
	vector<int64_t> ans(Q, -INF), cost(N, 0), vis(N);
	vector<vector<II>> edges(N);
	for (int i = 0; i < M; ++i) {
		edges[A[i]].emplace_back(II(B[i], C[i]));
		edges[B[i]].emplace_back(II(A[i], -C[i]));
	}
	UnionFind uf(N);
	for (int i = 0; i < N; ++i) {
		if (!vis[i]) {
			bool is_inf = false;
			vis[i] = 1;
			vector<int> q = { i };
			for (int j = 0; j < q.size(); ++j) {
				int node = q[j];
				for (auto kv : edges[node]) {
					int next_node = kv.first;
					int64_t next_cost = cost[node] + kv.second;
					if (!vis[next_node]) {
						cost[next_node] = next_cost;
						uf.unite(node, next_node);
						q.emplace_back(next_node);
					} else if (cost[next_node] != next_cost) {
						is_inf = true;
					}
					vis[next_node] += 1;
				}
			}
			if (is_inf) {
				cost[uf.root(i)] = INF;
			}
		}
	}
	for (int i = 0; i < Q; ++i) {
		int from = X[i], to = Y[i], rf = uf.root(from), tf = uf.root(to);
		if (rf == tf) {
			ans[i] = cost[rf] == INF ? INF : (cost[to] - cost[from]);
		}
	}
	return ans;
}

int main() {
	int N, M, Q;
	std::cin >> N >> M >> Q;
	vector<int> A(M), B(M);
	vector<int64_t> C(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i] >> C[i];
		--A[i]; --B[i];
	}
	std::vector<int> X(Q), Y(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> X[i] >> Y[i];
		--X[i]; --Y[i];
	}
	vector<int64_t> ans = solve(N, M, Q, A, B, C, X, Y);
	for (size_t i = 0; i < ans.size(); ++i) {
		if (ans[i] == INF) {
			cout << "inf";
		} else if (ans[i] == -INF) {
			cout << "nan";
		} else {
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
