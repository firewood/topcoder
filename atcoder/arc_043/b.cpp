#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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

typedef long long LL;

static const long long MOD = 1000000007;

struct modll {
	long long x;
	modll() { }
	modll(int _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(int y) { return (x + y + MOD) % MOD; }
	modll operator+=(int y) { x = (x + y + MOD) % MOD; return *this; }
	modll operator-(int y) { return (x - y + MOD) % MOD; }
	modll operator-=(int y) { x = (x - y + MOD) % MOD; return *this; }
	modll operator*(int y) { return (x * y) % MOD; }
	modll operator*=(int y) { x = (x * y) % MOD; return *this; }
	modll operator/(int y) { return (x * modpow(y, MOD - 2)) % MOD; }
	modll operator/=(int y) { x = (x * modpow(y, MOD - 2)) % MOD; return *this; }
	static modll modinv(int a) { return modpow(a, MOD - 2); }
	static modll modpow(int a, int b) {
		modll x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

void solve(long long N, std::vector<int> &D) {
	sort(D.begin(), D.end());
	vector<vector<modll>> dp(D.back() + 1, vector<modll>(4, 0));
	for (int i = 0, d = 1; d <= D.back(); ++d) {
		dp[d] = dp[d - 1];
		while (i < N && D[i] == d) {
			++i;
			dp[d][0] += 1;
			for (int j = 0; j < 3; ++j) {
				dp[d][j + 1] += dp[d / 2][j];
			}
		}
	}
	modll ans = dp[D.back()][3];
	cout << ans << endl;
}

int main() {
    long long N;
	std::cin >> N;
	std::vector<int> D(N);
	for (int i = 0; i < N; i++) {
		std::cin >> D[i];
	}
	solve(N, D);
	return 0;
}
