// E.

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
	int N, C;
	cin >> N >> C;
	modll dp[401][401];
	dp[0][0] = 1;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;	
		modll x(1);
		for (int j = 0; j <= C; ++j) {
			for (int k = 0; j + k <= C; ++k) {
				dp[i + 1][j + k] += dp[i][k] * x;
			}
			x *= a;
		}
	}
	cout << dp[N][C] << endl;
	return 0;
}
