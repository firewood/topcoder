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

void solve(int N, int M, std::vector<int> &A, std::vector<int> &B) {
	UnionFind uf(N);
	for (int i = 0; i < M; ++i) {
		uf.unite(A[i], B[i]);
	}
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		ans = max(ans, uf.size(uf.root(i)));
	}
	cout << ans << endl;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	std::vector<int> A(M), B(M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &A[i], &B[i]);
		A[i]--, B[i]--;
	}
	solve(N, M, A, B);
	return 0;
}
