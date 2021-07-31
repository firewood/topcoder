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

int64_t solve(int64_t N, int64_t M, int64_t K, std::vector<int> U, std::vector<int> V) {
	vector<vector<int>> edges(N);
	for (int i = 0; i < M; ++i) {
		edges[U[i]].push_back(V[i]);
		edges[V[i]].push_back(U[i]);
	}
	vector<modint> dp(N, 0);
	dp[0] = 1;
	modint prev_sum = 1;
	for (int k = 0; k < K; ++k) {
		vector<modint> next(N, 0);
		modint next_sum = 0;
		for (int i = 0; i < N; ++i) {
			next[i] += prev_sum - dp[i];
			for (auto node : edges[i]) {
				next[i] -= dp[node];
			}
			next_sum += next[i];
		}
		dp = next;
		prev_sum = next_sum;
	}
	return dp[0];
}

int main() {
	int64_t N, M, K;
	std::cin >> N >> M >> K;
	std::vector<int> U(M), V(M);
	for (int i = 0; i < M; i++) {
		std::cin >> U[i] >> V[i];
		--U[i]; --V[i];
	}
	cout << solve(N, M, K, U, V) << endl;
	return 0;
}
