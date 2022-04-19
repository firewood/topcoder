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

int64_t solve(int64_t N, int64_t M, int64_t K) {
	vector<modint> dp(51 * 51, 0);
	dp[0] = 1;
	for (int i = 0; i < N; ++i) {
		vector<modint> next(51 * 51, 0);
		for (int j = 0; j <= i * M; ++j) {
			for (int k = 1; k <= M; ++k) {
				next[j + k] += dp[j];
			}
		}
		dp = next;
	}
	return accumulate(dp.begin(), dp.begin() + K + 1, modint(0));
}

int main() {
	int64_t N, M, K;
	std::cin >> N >> M >> K;
	cout << solve(N, M, K) << endl;
	return 0;
}
