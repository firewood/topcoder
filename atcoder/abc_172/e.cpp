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

static const int64_t MOD = 1000000007;
static const size_t TABLE_SIZE = 1000000;		// 1e6

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
	static modint permutation(int n, int r);
	static modint combination(int n, int r);
	static modint nHr(int n, int r);
};

static vector<modint> fact(TABLE_SIZE + 1, 0), inv(TABLE_SIZE + 1, 0);

static __inline void build_fact_table() {
	if (!fact[0]) {
		fact[0] = 1;
		for (int i = 1; i <= TABLE_SIZE; ++i) {
			fact[i] = fact[i - 1] * i;
		}
		inv[TABLE_SIZE] = modint::modinv(fact[TABLE_SIZE]);
		for (int i = TABLE_SIZE; i >= 1; --i) {
			inv[i - 1] = inv[i] * i;
		}
	}
}

modint modint::permutation(int n, int r) {
	if (r > n) return 0;
	build_fact_table();
	return fact[n] * inv[n - r];
}

modint modint::combination(int n, int r) {
	if (r > n) return 0;
	build_fact_table();
	return (fact[n] * inv[r]) * inv[n - r];
}

modint modint::nHr(int n, int r) {
	return combination(n + r - 1, r);
}

modint solve(int64_t N, int64_t M) {
	modint ans = 0;
	for (int i = 0; i <= N; ++i) {
		modint c = modint::combination(N, i) * modint::permutation(M, i) * modint::permutation(M - i, N - i) * modint::permutation(M - i, N - i);
		ans += (i % 2) ? modint(MOD - c) : c;
	}
	return ans;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	cout << solve(N, M) << endl;
	return 0;
}
