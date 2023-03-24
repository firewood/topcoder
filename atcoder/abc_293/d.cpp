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

void solve(int64_t N, int64_t M, std::vector<int64_t> A, std::vector<std::string> B, std::vector<int64_t> C, std::vector<std::string> D) {
	int ac = 0, bc = 0;
	UnionFind uf(N);
	for (int i = 0; i < M; ++i) {
		uf.unite(A[i], C[i]);
	}
	vector<int> cnt(N);
	for (int i = 0; i < M; ++i) {
		cnt[uf.root(A[i])] += 1;
	}
	for (int i = 0; i < N; ++i) {
		if (uf.root(i) == i) {
			if (cnt[i] == uf.size(i)) {
				++ac;
			} else {
				++bc;
			}
		}
	}
	cout << ac << " " << bc << endl;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> A(M);
	std::vector<std::string> B(M);
	std::vector<int64_t> C(M);
	std::vector<std::string> D(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i] >> C[i] >> D[i];
		--A[i];
		--C[i];
	}
	solve(N, M, A, B, C, D);
	return 0;
}
