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
#include <atcoder/modint>

using namespace std;

using mint = atcoder::modint998244353;

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

mint solve(int N, int M, std::vector<int> P) {
	UnionFind uf(N);
	for (int i = 0; i < N; ++i) {
		uf.unite(i, P[i]);
	}
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		cnt += uf.root(i) == i;
	}
	return (mint(M).pow(N) - mint(M).pow(cnt)) / 2;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> P(N);
	for (int i = 0; i < N; i++) {
		std::cin >> P[i];
		--P[i];
	}
	cout << solve(N, M, P).val() << endl;
	return 0;
}
