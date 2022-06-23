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

int64_t solve(int64_t N, std::vector<int64_t> X, std::vector<int64_t> C) {
	int64_t ans = 0;
	UnionFind uf(N);
	for (int i = 0; i < N; ++i) {
		if (uf.root(i) != uf.root(X[i])) {
			uf.unite(i, X[i]);
		} else {
			int64_t node = X[i], cost = C[i];
			while (node != i) {
				cost = min(cost, C[node]);
				node = X[node];
			}
			ans += cost;
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> X(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i];
		--X[i];
	}
	std::vector<int64_t> C(N);
	for (int i = 0; i < N; i++) {
		std::cin >> C[i];
	}
	cout << solve(N, X, C) << endl;
	return 0;
}
