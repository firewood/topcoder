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

static int64_t MOD;

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

vector<modint> solve(int64_t N, int64_t P) {
	MOD = P;
	vector<vector<modint>> dp(2, vector<modint>(N + 3, 0));
	dp[0][0] = 1;
	dp[1][1] = 1;
	for (int nn = 1; nn < N; ++nn) {
		vector<vector<modint>> next(2, vector<modint>(N + 3, 0));
		for (int i = 0; i < N; ++i) {
			next[0][i + 0] += dp[0][i] + dp[1][i];
			next[0][i + 1] += dp[0][i] * 3;
			next[1][i + 1] += dp[1][i];
			next[1][i + 2] += dp[0][i] * 2;
		}
		dp = next;
	}
	return vector<modint>(dp[0].begin() + 1, dp[0].begin() + N);
}

int main() {
	int64_t N, P;
	std::cin >> N >> P;
	vector<modint> ans = solve(N, P);
	for (size_t i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
