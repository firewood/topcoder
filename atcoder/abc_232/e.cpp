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
static const size_t MAX_N = 1000001;

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

modint combination(int64_t n, int64_t r) {
	static modint fact[MAX_N + 1], inv[MAX_N + 1];
	if (!fact[0]) {
		fact[0] = 1;
		for (int i = 1; i <= MAX_N; ++i) {
			fact[i] = fact[i - 1] * i;
		}
		inv[MAX_N] = modint::modinv(fact[MAX_N]);
		for (int i = MAX_N; i >= 1; --i) {
			inv[i - 1] = inv[i] * i;
		}
	}
	if (r > n) {
		return 0;
	}
	return (fact[n] * inv[r]) * inv[n - r];
}

modint solve(int H, int W, int K, std::vector<int> x, std::vector<int> y) {
	auto gen = [&](int H, const vector<int>& x) {
		vector<vector<modint>> dp(K + 1, vector<modint>(2));
		dp[0][0] = x[0] == x[1];
		dp[0][1] = x[0] != x[1];
		for (int i = 0; i < K; ++i) {
			dp[i + 1][0] = dp[i][1];
			dp[i + 1][1] = dp[i][0] * (H - 1) + dp[i][1] * (H - 2);
		}
		return dp;
	};
	vector<vector<modint>> hdp = gen(H, x), wdp = gen(W, y);
	modint ans = 0;
	for (int hop = 0; hop <= K; ++hop) {
		ans += hdp[hop][0] * wdp[K - hop][0] * combination(K, hop);
	}
	return ans;
}

int main() {
	int H, W, K;
	std::cin >> H >> W >> K;
	std::vector<int> x(2), y(2);
	for (int i = 0; i < 2; i++) {
		std::cin >> x[i] >> y[i];
		--x[i];
		--y[i];
	}
	cout << solve(H, W, K, x, y) << endl;
	return 0;
}
