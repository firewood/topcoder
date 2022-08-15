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

vector<int> solve(int N, int M, int E, std::vector<int> U, std::vector<int> V, int Q, std::vector<int> X) {
	vector<int> ans(Q), dmg(E);
	for (int i = 0; i < Q; ++i) {
		dmg[X[i]] = 1;
	}
	UnionFind uf(N + 1);
	for (int i = 0; i < E; ++i) {
		if (!dmg[i]) {
			uf.unite(min(U[i], N), min(V[i], N));
		}
	}
	for (int i = Q - 1; i >= 0; --i) {
		ans[i] = uf.size(N) - 1;
		uf.unite(min(U[X[i]], N), min(V[X[i]], N));
	}
	return ans;
}

int main() {
	int N, M, E, Q;
	std::cin >> N >> M >> E;
	std::vector<int> U(E), V(E);
	for (int i = 0; i < E; i++) {
		std::cin >> U[i] >> V[i];
		--U[i];
		--V[i];
	}
	std::cin >> Q;
	std::vector<int> X(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> X[i];
		--X[i];
	}
	vector<int> ans = solve(N, M, E, U, V, Q, X);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
