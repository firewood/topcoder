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

modint solve(int64_t N, int64_t M) {
	vector<modint> dp(61, 0);
	for (int i = 0; i <= 60 && i < N; ++i) {
		vector<modint> next(61, 0);
		modint sum = i == 0;
		for (int j = 0; j <= 60; ++j) {
			int b = max(int64_t(0), min(M, int64_t(2LL << j) - 1) - int64_t(1LL << j) + 1) % MOD;
			next[j] = sum * b;
			sum += dp[j];
		}
		dp = next;
	}
	return accumulate(dp.begin(), dp.end(), modint(0));
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	cout << solve(N, M) << endl;
	return 0;
}
