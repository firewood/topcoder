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

static const size_t TABLE_SIZE = 256000;

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

static modint fact[TABLE_SIZE + 1], inv[TABLE_SIZE + 1];

void build_fact_table() {
	fact[0] = 1;
	for (int i = 1; i <= TABLE_SIZE; ++i) {
		fact[i] = fact[i - 1] * i;
	}
	inv[TABLE_SIZE] = modint::modinv(fact[TABLE_SIZE]);
	for (int i = TABLE_SIZE; i >= 1; --i) {
		inv[i - 1] = inv[i] * i;
	}
}

modint combination(int n, int r) {
	if (r > n) return 0;
	return (fact[n] * inv[r]) * inv[n - r];
}

modint solve(int N) {
	modint ans = fact[N * N], d = fact[N * N - N * 2 + 1] * fact[N] * fact[N];
	for (int i = N; i <= N * N - N + 1; ++i) {
		ans -= combination(i - 1, N - 1) * combination(N * N - i, N - 1) * d;
	}
	return ans;
}

int main() {
	build_fact_table();
	int N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
