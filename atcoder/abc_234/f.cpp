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

int64_t solve(std::string S) {
	static const int COMBSZ = 5002;
	static vector<vector<modint>> C(COMBSZ, vector<modint>(COMBSZ, 0));
	for (int i = 0; i < COMBSZ; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
		}
	}

	vector<modint> dp(5002, 0);
	dp[0] = 1;
	int sum = 0;
	for (int i = 0; i < 26; ++i) {
		vector<modint> next = dp;
		int c = count(S.begin(), S.end(), char('a' + i));
		for (int j = 1; j <= c; ++j) {
			for (int k = 0; k <= sum; ++k) {
				if (dp[k] != 0) {
					next[k + j] += dp[k] * C[k + j][j];
				}
			}
		}
		sum += c;
		dp = next;
	}
	return accumulate(dp.begin(), dp.end(), modint(0)) - 1;
}

int main() {
	std::string S;
	std::cin >> S;
	cout << solve(S) << endl;
	return 0;
}
