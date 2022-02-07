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

modint solve(int N, int K, std::vector<int> P, std::vector<int> Q) {
	vector<pair<int, int>> v;
	for (int i = 0; i < N; ++i) {
		v.emplace_back(make_pair(P[i], Q[i]));
	}
	sort(v.begin(), v.end());
	vector<vector<modint>> dp(N + 1, vector<modint>(N + 1, 0));
	dp[N][0] = 1;
	for (int i = 0; i < N; ++i) {
		vector<vector<modint>> next(N + 1, vector<modint>(N + 1, 0));
		int x = v[i].second;
		for (int j = 0; j <= N; ++j) {
			for (int k = 0; k < N; ++k) {
				if (x < j) {
					next[j][k + 1] += dp[j][k];
				}
				next[min(j, x)][k] += dp[j][k];
			}
		}
		dp = next;
	}
	modint ans = 0;
	for (int j = 0; j <= N; ++j) {
		ans += dp[j][K];
	}
	return ans;
}

int main() {
	int N, K;
	std::cin >> N >> K;
	std::vector<int> P(N);
	for (int i = 0; i < N; i++) {
		std::cin >> P[i];
		--P[i];
	}
	std::vector<int> Q(N);
	for (int i = 0; i < N; i++) {
		std::cin >> Q[i];
		--Q[i];
	}
	cout << solve(N, K, P, Q) << endl;
	return 0;
}
