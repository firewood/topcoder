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

int64_t solve(int N, std::vector<int> a) {
	modint ans = 0;
	for (int r = 1; r <= N; ++r) {
		vector<vector<modint>> dp(N + 1, vector<modint>(N + 1, 0));
		dp[0][0] = 1;
		for (int i = 0; i < N; ++i) {
			vector<vector<modint>> next = dp;
			for (int k = 0; k < r; ++k) {
				int nr = (k + a[i]) % r;
				for (int j = 0; j <= i; ++j) {
					next[j + 1][nr] += dp[j][k];
				}
			}
			dp = next;
		}
		ans += dp[r][0];
	}
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	cout << solve(N, a) << endl;
	return 0;
}
