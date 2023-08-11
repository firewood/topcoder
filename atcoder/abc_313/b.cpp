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
	UnionFind(size_t size) : _parent(size, -1), _size(size, 1) { }
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

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> A, std::vector<int64_t> B) {
	UnionFind uf(N);
	vector<int> cnt(N);
	for (int i = 0; i < M; ++i) {
		uf.unite(A[i], B[i]);
		cnt[B[i]] += 1;
	}
	if (uf.size(0) == N && count(cnt.begin(), cnt.end(), 0) == 1) {
		return find(cnt.begin(), cnt.end(), 0) - cnt.begin() + 1;
	} else {
		return -1;
	}
}

int main() {
#if DEBUG
	freopen("in_1.txt", "r", stdin);
#endif
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> A(M), B(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i];
		--A[i];
		--B[i];
	}
	cout << solve(N, M, A, B) << endl;
	return 0;
}
