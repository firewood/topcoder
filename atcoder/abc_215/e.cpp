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

int64_t solve(int64_t N, std::string S) {
	vector<vector<modint>> dp(1024, vector<modint>(10, 0));
	for (int i = 0; i < N; ++i) {
		vector<vector<modint>> next = dp;
		int ch = S[i] - 'A';
		int chf = 1 << ch;
		next[chf][ch] += 1;
		for (int b = 1; b < 1024; ++b) {
			if (b & chf) {
				next[b][ch] += dp[b][ch];
			} else {
				for (int d = 0; d < 10; ++d) {
					next[b | chf][ch] += dp[b][d];
				}
			}
		}
		dp = next;
	}
	modint ans = 0;
	for (int i = 1; i < 1024; ++i) {
		ans += accumulate(dp[i].begin(), dp[i].end(), modint(0));
	}
	return ans;
}

int main() {
	int64_t N;
	std::string S;
	std::cin >> N >> S;
	cout << solve(N, S) << endl;
	return 0;
}
