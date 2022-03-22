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

int64_t solve(int64_t N, int64_t M, int64_t K, int64_t S, int64_t T, int64_t X, std::vector<int> U, std::vector<int> V) {
	vector<vector<modint>> dp(N, vector<modint>(2, 0));
	dp[S][0] = 1;
	for (int t = 0; t < K; ++t) {
		vector<vector<modint>> next(N, vector<modint>(2, 0));
		for (int i = 0; i < M; ++i) {
			int a = U[i], b = V[i];
			next[b][b == X] += dp[a][0];
			next[b][b != X] += dp[a][1];
			next[a][a == X] += dp[b][0];
			next[a][a != X] += dp[b][1];
		}
		dp = next;
	}
	return dp[T][0];
}

int main() {
	int64_t N, M, K, S, T, X;
	std::cin >> N >> M >> K >> S >> T >> X;
	--S, --T, --X;
	std::vector<int> U(M), V(M);
	for (int i = 0; i < M; i++) {
		std::cin >> U[i] >> V[i];
		--U[i], --V[i];
	}
	cout << solve(N, M, K, S, T, X, U, V) << endl;
	return 0;
}
