// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
const LL MOD = 998244353;

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

int main(int argc, char *argv[]) {
	int sh, sw, eh, ew;
	cin >> sh >> sw >> eh >> ew;
	vector<modll> dp(eh + 1, 0);
	dp[sh] = 1;
	for (int i = sh + 1; i <= eh; ++i) {
		dp[i] = dp[i - 1] * sw;
	}
	for (int col = sw + 1; col <= ew; ++col) {
		vector<modll> next(eh + 1, 0);
		modll sum = 0;
		for (int row = sh; row <= eh; ++row) {
			next[row] = dp[row] * row + next[row - 1] * col - dp[row - 1] * (row - 1) * (col - 1);
		}
		dp = next;
	}
	cout << dp[eh] << endl;
	return 0;
}
