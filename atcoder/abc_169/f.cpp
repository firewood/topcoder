// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;

const LL MOD = 998244353;
static const size_t MAX_N = 400000;

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

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, s, a;
		cin >> n >> s;
		if (n < 0) return 0;
		modll ans = 0;
		vector<modll> dp(s + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < n; ++i) {
			cin >> a;
			vector<modll> next(s + 1);
			for (int j = 0; j <= s; ++j) {
				next[j] = dp[j] * 2;
			}
			for (int j = a; j <= s; ++j) {
				next[j] += dp[j - a];
			}
			dp = next;
		}
		cout << dp[s] << endl;
	}
	return 0;
}
