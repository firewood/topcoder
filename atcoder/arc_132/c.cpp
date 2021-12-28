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

int64_t solve(int64_t n, int64_t d, std::vector<int64_t> a) {
	vector<modint> dp(1 << (d * 2 + 1), 0);
	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		vector<modint> next(1 << (d * 2 + 1), 0);
		int pos = find(a.begin(), a.end(), i) - a.begin();
		bool found = pos < n;
		if (found && abs(pos - i) > d) {
			return 0;
		}
		for (int b = 0; b < (1 << (d * 2 + 1)); ++b) {
			if (dp[b] == 0) continue;
			if (found) {
				next[b >> 1] += dp[b];
			} else {
				for (int j = 0; j < d * 2 + 1; ++j) {
					int k = i + j - d;
					if ((b & (1 << j)) == 0 && k >= 0 && k < n && a[k] < 0) {
						next[(b | (1 << j)) >> 1] += dp[b];
					}
				}
			}
		}
		dp = next;
	}
	return accumulate(dp.begin(), dp.end(), modint(0));
}

int main() {
	int64_t n, d;
	std::cin >> n >> d;
	std::vector<int64_t> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		--a[i];
	}
	cout << solve(n, d, a) << endl;
	return 0;
}
