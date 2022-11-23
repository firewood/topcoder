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

typedef pair<int, int> II;
typedef pair<int64_t, II> III;

static const int64_t INF = 1LL << 60;

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

int64_t solve(int N, int M, std::vector<int> X, std::vector<int> Y, std::vector<int> A, std::vector<int> B, std::vector<int> Z) {
	int64_t ans = INF;
	for (int f = 0; f < 4; ++f) {
		int64_t sum = 0;
		int size = N;
		vector<III> q;

		if (f & 1) {
			int xn = size++;
			for (int i = 0; i < N; ++i) {
				q.emplace_back(III(X[i], II(i, xn)));
			}
		}
		if (f & 2) {
			int yn = size++;
			for (int i = 0; i < N; ++i) {
				q.emplace_back(III(Y[i], II(i, yn)));
			}
		}
		for (int i = 0; i < M; ++i) {
			q.emplace_back(III(Z[i], II(A[i], B[i])));
		}

		UnionFind uf(size);
		sort(q.begin(), q.end());
		for (auto kv : q) {
			int a = kv.second.first, b = kv.second.second;
			if (uf.root(a) != uf.root(b)) {
				sum += kv.first;
				uf.unite(a, b);
			}
		}
		if (uf.size(0) == size) {
			ans = min(ans, sum);
		}
	}
	return ans;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> X(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i];
	}
	std::vector<int> Y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> Y[i];
	}
	std::vector<int> A(M), B(M), Z(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i] >> Z[i];
		--A[i]; --B[i];
	}
	cout << solve(N, M, X, Y, A, B, Z) << endl;
	return 0;
}
