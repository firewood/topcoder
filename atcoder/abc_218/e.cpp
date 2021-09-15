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

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> A, std::vector<int64_t> B, std::vector<int64_t> C) {
	int64_t ans = 0;
	UnionFind uf(N);
	vector<int> seq(M);
	iota(seq.begin(), seq.end(), 0);
	sort(seq.begin(), seq.end(), [&](int lhs, int rhs) {
		return C[lhs] < C[rhs];
	});
	for (int i = 0; i < M; ++i) {
		int64_t a = A[seq[i]], b = B[seq[i]], c = C[seq[i]];
		if (c > 0 && uf.root(a) == uf.root(b)) {
			ans += c;
		} else {
			uf.unite(a, b);
		}
	}
	return ans;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> A(M), B(M), C(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i] >> C[i];
		--A[i];
		--B[i];
	}
	cout << solve(N, M, A, B, C) << endl;
	return 0;
}
