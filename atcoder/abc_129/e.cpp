// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
const LL MOD = 1000000007;
static const size_t MAX_N = 200050;

struct modll {
	long long x;
	modll() { }
	modll(long long _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(const modll& r) { return (x + r.x) % MOD; }
	modll operator+=(const modll & r) { return x = (x + r.x) % MOD; }
	modll operator-(const modll & r) { return (x + MOD - r.x) % MOD; }
	modll operator-=(const modll & r) { return x = (x + MOD - r.x) % MOD; }
	modll operator*(const modll & r) { return (x * r.x) % MOD; }
	modll operator*(int r) { return (x * r) % MOD; }
	modll operator*=(const modll & r) { return x = (x * r.x) % MOD; }
	static modll modinv(int a) { return modpow(a, MOD - 2); }
	static modll modpow(int a, int b) {
		modll x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	modll dp[2] = { 0,1 };
	for (char c : s) {
		dp[0] *= 3;
		if (c != '0') {
			dp[0] += dp[1];
			dp[1] *= 2;
		}
	}
	modll ans = dp[0] + dp[1];
	cout << ans << endl;
	return 0;
}
