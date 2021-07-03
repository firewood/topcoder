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

static const int64_t MOD = 1000000007;

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

int64_t solve(int64_t N, std::vector<int64_t> A) {
	modint ans = 0;
	vector<vector<modint>> dp(N + 1, vector<modint>(N + 1, 0)), tot(N + 1, vector<modint>(N + 1, 0));
	tot[0][0] = 1;
	int64_t sum = 0;
	for (int i = 0; i < N; ++i) {
		sum += A[i];
		for (int j = 1; j <= N; ++j) {
			dp[i][j] = tot[j - 1][sum % j];
		}
		for (int j = 1; j <= N; ++j) {
			tot[j][sum % (j + 1)] += dp[i][j];
		}
	}
	for (int i = 0; i < N; ++i) {
		ans += dp[N - 1][i + 1];
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
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, std::move(A)) << endl;
	return 0;
}
