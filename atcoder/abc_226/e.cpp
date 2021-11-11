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

static const int64_t MOD = 998244353;

struct modint {
	int64_t x;
	modint() { }
	modint(int _x) : x(_x) { }
	operator int() const { return (int)x; }
	modint operator+(int y) { return (x + y + MOD) % MOD; }
	modint operator+=(int y) { x = (x + y + MOD) % MOD; return *this; }
	modint operator-(int y) { return (x - y + MOD) % MOD; }
	modint operator-=(int y) { x = (x - y + MOD) % MOD; return *this; }
	modint operator*(int y) { return (x * y) % MOD; }
	modint operator*=(int y) { x = (x * y) % MOD; return *this; }
	modint operator/(int y) { return (x * modpow(y, MOD - 2)) % MOD; }
	modint operator/=(int y) { x = (x * modpow(y, MOD - 2)) % MOD; return *this; }
	static modint modinv(int a) { return modpow(a, MOD - 2); }
	static modint modpow(int a, int b) {
		modint x = a, r = 1;
		for (; b > 0; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

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

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> U, std::vector<int64_t> V) {
	modint ans = 1;
	UnionFind uf(N);
	for (int i = 0; i < M; ++i) {
		uf.unite(U[i], V[i]);
	}
	vector<int> edges(N);
	for (int i = 0; i < M; ++i) {
		edges[uf.root(U[i])] += 1;
	}
	for (int i = 0; i < N; ++i) {
		if (uf.root(i) == i) {
			ans *= (uf.size(i) == edges[i]) ? 2 : 0;
		}
	}
	return ans;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> U(M), V(M);
	for (int i = 0; i < M; i++) {
		std::cin >> U[i] >> V[i];
		--U[i];
		--V[i];
	}
	cout << solve(N, M, U, V) << endl;
	return 0;
}
