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
#include <functional>

using namespace std;

typedef pair<int, int> II;
typedef pair<int, II> III;

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

vector<int> solve(int N, int M, int Q, std::vector<int> a, std::vector<int> b, std::vector<int> c, std::vector<int> u, std::vector<int> v, std::vector<int> w) {
	vector<int> ans(Q);
	vector<III> edges;
	for (int i = 0; i < M; ++i) {
		edges.emplace_back(III(c[i], II(i, 0)));
	}
	for (int i = 0; i < Q; ++i) {
		edges.emplace_back(III(w[i], II(i, 1)));
	}
	sort(edges.begin(), edges.end());
	UnionFind uf(N);
	for (auto kv : edges) {
		int i = kv.second.first;
		if (kv.second.second == 0) {
			if (uf.root(a[i]) != uf.root(b[i])) {
				uf.unite(a[i], b[i]);
			}
		} else {
			if (uf.root(u[i]) != uf.root(v[i])) {
				ans[i] = 1;
			}
		}
	}
	return ans;
}

int main() {
	int N, M, Q;
	std::cin >> N >> M >> Q;
	std::vector<int> a(M), b(M), c(M);
	for (int i = 0; i < M; i++) {
		std::cin >> a[i] >> b[i] >> c[i];
		--a[i];
		--b[i];
	}
	std::vector<int> u(Q), v(Q), w(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> u[i] >> v[i] >> w[i];
		--u[i];
		--v[i];
	}
	vector<int> ans = solve(N, M, Q, a, b, c, u, v, w);
	for (int i = 0; i < Q; ++i) {
		cout << (ans[i] ? "Yes" : "No") << endl;
	}
	return 0;
}
