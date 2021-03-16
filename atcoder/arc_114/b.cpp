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

typedef long long LL;

static const LL INF = 1LL << 60;
static const long long MOD = 998244353;

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

struct modll {
	long long x;
	modll() { }
	modll(int _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(int y) { return (x + y + MOD) % MOD; }
	modll operator+=(int y) { x = (x + y + MOD) % MOD; return *this; }
	modll operator-(int y) { return (x - y + MOD) % MOD; }
	modll operator-=(int y) { x = (x - y + MOD) % MOD; return *this; }
	modll operator*(int y) { return (x * y) % MOD; }
	modll operator*=(int y) { x = (x * y) % MOD; return *this; }
	modll operator/(int y) { return (x * modpow(y, MOD - 2)) % MOD; }
	modll operator/=(int y) { x = (x * modpow(y, MOD - 2)) % MOD; return *this; }
	static modll modinv(int a) { return modpow(a, MOD - 2); }
	static modll modpow(int a, int b) {
		modll x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

LL solve(long long N, std::vector<long long>& f) {
	modll ans = 1;
	UnionFind uf(N);
	for (int i = 0; i < N; i++) {
		uf.unite(i, f[i]);
	}
	for (int i = 0; i < N; i++) {
		if (i == uf.root(i)) ans *= 2;
	}
	ans -= 1;
	return ans;
}

LL solve2(long long N, std::vector<long long>& f) {
	modll ans = 0;
	for (int b = 1; b < (1 << N); ++b) {
		bool ok = true;
		vector<LL> v;
		vector<int> used(N);
		for (int i = 0; i < N; i++) {
			if (b & (1 << i)) {
				if (used[f[i]]) {
					ok = false;
					break;
				}
				v.emplace_back(f[i]);
				used[f[i]] = 1;
				if (b & (1 << f[i])) {
					;
				} else {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			ans += 1;
		}
	}
	return ans;
}

int main() {
	long long N;
	std::cin >> N;
	std::vector<long long> f(N);
	for (int i = 0; i < N; i++) {
		std::cin >> f[i];
		--f[i];
	}
	cout << solve(N, f) << endl;

#if 0
	cout << solve2(N, f) << endl;
	for (int t = 0; t < 10000; ++t) {
		N = 1 + (rand() % 6);
		f.resize(N);
		for (int i = 0; i < N; ++i) {
			f[i] = rand() % N;
		}
		LL a = solve(N, f);
		LL b = solve2(N, f);
		if (a != b) {
			cerr << "FAILED" << endl;
			a += 0;
		}
	}
#endif
	return 0;
}
