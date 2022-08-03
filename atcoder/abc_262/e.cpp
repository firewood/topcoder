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

modint solve(int N, int M, int K, std::vector<int> U, std::vector<int> V) {
	modint ans = 0;
	vector<int> cnt(N);
	for (int i = 0; i < M; ++i) {
		cnt[U[i]]++;
		cnt[V[i]]++;
	}
	int even = 0;
	for (int i = 0; i < N; ++i) {
		even += (cnt[i] % 2) == 0;
	}
	int odd = N - even;
	for (int i = 0; i <= min(odd, K); i += 2) {
		ans += modint::combination(odd, i) * modint::combination(even, K - i);
	}
	return ans;
}

int main() {
	int N, M, K;
	std::cin >> N >> M >> K;
	std::vector<int> U(M), V(M);
	for (int i = 0; i < M; i++) {
		std::cin >> U[i] >> V[i];
		--U[i], --V[i];
	}
	cout << solve(N, M, K, U, V) << endl;
	return 0;
}
