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

int solve(int N, int M, std::vector<int> A, std::vector<int> B) {
	int ans = 0;
	UnionFind uf(N);
	for (int i = 0; i < M; ++i) {
		int a = A[i], b = B[i];
		if (uf.root(a) == uf.root(b)) {
			++ans;
		} else {
			uf.unite(a, b);
		}
	}
	return ans;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> A(M), B(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i];
		--A[i]; --B[i];
	}
	cout << solve(N, M, A, B) << endl;
	return 0;
}
