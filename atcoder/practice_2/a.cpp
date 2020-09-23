#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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

typedef long long LL;

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	UnionFind(int size) : _parent(size, -1), _size(size, 1) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b); if (ra == rb) { return; }
		if (_size[ra] >= _size[rb]) { _parent[rb] = ra, _size[ra] += _size[rb]; } else { _parent[ra] = rb, _size[rb] += _size[ra]; }
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};

void solve(long long N, long long Q, std::vector<long long> &t, std::vector<long long> &u, std::vector<long long> &v) {
	UnionFind uf(N);
	for (LL i = 0; i < Q; ++i) {
		if (t[i] == 0) {
			uf.unite(u[i], v[i]);
		} else {
			cout << (uf.root(u[i]) == uf.root(v[i])) << endl;
		}
	}
}

int main() {
    long long N;
	std::cin >> N;
	long long Q;
	std::cin >> Q;
	std::vector<long long> t(Q);
	std::vector<long long> u(Q);
	std::vector<long long> v(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> t[i];
		std::cin >> u[i];
		std::cin >> v[i];
	}
	solve(N, Q, t, u, v);
	return 0;
}
