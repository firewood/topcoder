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

int64_t solve(int64_t N, std::vector<int64_t> a, std::vector<int64_t> b) {
	vector<modint> dp(3001, 0);
	dp[0] = 1;
	for (int i = 0; i < N; ++i) {
		vector<modint> next(3001, 0);
		modint sum = 0;
		for (int j = 0; j <= b[i]; ++j) {
			sum += dp[j];
			if (j >= a[i]) {
				next[j] = sum;
			}
		}
		dp = next;
	}
	return accumulate(dp.begin() + a[N - 1], dp.begin() + b[N - 1] + 1, modint(0));
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	std::vector<int64_t> b(N);
	for (int i = 0; i < N; i++) {
		std::cin >> b[i];
	}
	cout << solve(N, a, b) << endl;
	return 0;
}
