// F.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

static const int MOD = 1000000007;

struct modll {
	long long x;
	modll() : x(0) { }
	modll(long long _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(const modll &r) { return (x + r.x) % MOD; }
	modll operator+=(const modll &r) { return x = (x + r.x) % MOD; }
	modll operator-(const modll &r) { return (x + MOD - r.x) % MOD; }
	modll operator-=(const modll &r) { return x = (x + MOD - r.x) % MOD; }
	modll operator*(const modll &r) { return (x * r.x) % MOD; }
	modll operator*(int r) { return (x * r) % MOD; }
	modll operator*=(const modll &r) { return x = (x * r.x) % MOD; }
	modll inverse() {
		modll r = 1, a = x;
		for (int b = MOD - 2; b; b >>= 1) {
			if (b & 1) {
				r *= a;
			}
			a *= a;
		}
		return r;
	}
};

int main(int argc, char *argv[]) {
	int N;
	cin >> N;
	string s;
	cin >> s;
	modll dp[301][301][301];
	dp[0][0][0] = 1;
	if (N <= 300) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j <= i; ++j) {
				int l = max(0, j - 1);
				for (int k = 0; k <= i; ++k) {
					if (j == k) {
						dp[i + 1][j + 1][k] += dp[i][j][k];
						dp[i + 1][j + 1][k + 1] += dp[i][j][k];
						dp[i + 1][l][l] += dp[i][j][k];
					} else {
						dp[i + 1][j + 1][k] += dp[i][j][k] * 2;
						dp[i + 1][l][k] += dp[i][j][k];
					}
				}
			}
		}
		cout << dp[N][s.length()][s.length()] << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}
