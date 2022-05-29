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

typedef long double LD;
typedef pair<int64_t, int64_t> II;
typedef pair<int64_t, II> III;

static const int64_t INF = 1LL << 60;
static const int64_t MOD = 998244353;
static const size_t TABLE_SIZE = 1000000;		// 1e6

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

modint solve(int N, int M, int K) {
	modint ans;
	if (K == 0) {
		ans = modint::modpow(M, N);
	} else {
		vector<modint> dp(M +1, 0), sum(M + 1, 0);
		for (int i = 1; i <= M; ++i) {
			dp[i] = 1;
			sum[i] = sum[i - 1] + dp[i];
		}
		for (int i = 1; i < N; ++i) {
			vector<modint> next(M + 1, 0), next_sum(M + 1, 0);
			for (int j = 1; j <= M; ++j) {
				if (j > K) {
					next[j] = sum[j - K];
				}
				if (j + K <= M) {
					next[j] += sum[M] - sum[j + K - 1];
				}
				next_sum[j] = next_sum[j - 1] + next[j];
			}
			dp = next;
			sum = next_sum;
		}
		ans = accumulate(dp.begin(), dp.end(), modint(0));
	}
	return ans;
}

int main() {
	int N, M, K;
	std::cin >> N >> M >> K;
	cout << solve(N, M, K) << endl;
	return 0;
}
