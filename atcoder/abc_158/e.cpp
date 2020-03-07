// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
LL MOD;
static const size_t MAX_N = 2000001;

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
		LL ans = 0;
		int n = -1, p;
		cin >> n >> p;
		if (n < 0) return 0;
		string s;
		cin >> s;
		if (p == 2 || p == 5) {
			for (int i = 0; i < n; ++i) {
				if (((s[i] - '0') % p) == 0) {
					ans += i + 1;
				}
			}
		} else {
			int dp[10000] = {1};
			MOD = p;
			modll d = 1, x = 0;
			for (int i = n - 1; i >= 0; --i) {
				x += d * (s[i] - '0');
				ans += dp[x];
				dp[x] += 1;
				d *= 10;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
