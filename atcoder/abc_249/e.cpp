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

int64_t MOD;

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

int64_t solve(int N, int P) {
	MOD = P;
	vector<int> ten = { 1,10,100,1000,10000 };
	vector<vector<modint>> dp(N + 1, vector<modint>(N + 1, 0)), sum(N + 1, vector<modint>(N + 2, 0));
	dp[0][0] = modint::modinv(25) * 26;
	for (int i = 1; i <= N; ++i) {
		sum[0][i] = dp[0][0];
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j <= N; ++j) {
			for (int k = 1; k <= 4 && i - k - 1 >= 0; ++k) {
				int ed = max(j - ten[k - 1] + 1, 0), st = max(j - ten[k] + 1, 0);
				dp[i][j] += (sum[i - k - 1][ed] - sum[i - k - 1][st]) * 25;
			}
			sum[i][j + 1] = sum[i][j] + dp[i][j];
		}
	}
	modint ans = 0;
	for (int j = 1; j < N; ++j) {
		ans += dp[j][N];
	}
	return ans;
}

int main() {
	int N, P;
	std::cin >> N >> P;
	cout << solve(N, P) << endl;
	return 0;
}
