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
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

int64_t solve(int64_t N, std::vector<int64_t> W) {
	int sum = accumulate(W.begin(), W.end(), 0);
	if (sum % 2) return 0;
	sum /= 2;
	vector<modint> fact(101, 1);
	for (int i = 2; i <= 100; ++i) {
		fact[i] = fact[i - 1] * i;
	}
	vector<vector<modint>> dp(N + 1, vector<modint>(sum + 1, 0));
	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = sum; j >= W[i]; --j) {
			for (int k = 0; k <= i; ++k) {
				dp[k + 1][j] += dp[k][j - W[i]];
			}
		}
	}
	modint ans = 0;
	for (int i = 1; i < N; i++) {
		ans += dp[i][sum] * fact[i] * fact[N - i];
	}
	return ans;
}

int main() {
#if DEBUG || _DEBUG
	freopen("in.txt", "r", stdin);
//	freopen("in_1.txt", "r", stdin);
#endif
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> W(N);
	for (int i = 0; i < N; i++) {
		std::cin >> W[i];
	}
	cout << solve(N, std::move(W)) << endl;
	return 0;
}
