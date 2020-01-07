// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
LL MOD = 1000000007;

struct modll {
	long long x;
	modll() { }
	modll(long long _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(const modll& r) { return (x + r.x) % MOD; }
	modll operator+=(const modll& r) { return x = (x + r.x) % MOD; }
	modll operator-(const modll& r) { return (x + MOD - r.x) % MOD; }
	modll operator-=(const modll& r) { return x = (x + MOD - r.x) % MOD; }
	modll operator*(const modll& r) { return (x * r.x) % MOD; }
	modll operator*(int r) { return (x * r) % MOD; }
	modll operator*=(const modll& r) { return x = (x * r.x) % MOD; }
	static modll modinv(int a) { return modpow(a, MOD - 2); }
	static modll modpow(int a, int b) {
		modll x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

int main(int argc, char* argv[]) {
	LL n;
	cin >> n >> MOD;
	vector<modll> fact(n + 1);
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = fact[i - 1] * i;
	}
	modll ans = 0;
	for (int i = 1; i <= n; ++i) {
		modll x = fact[i];
		x *= fact[n - i];
		x *= (n - i + 1);
		x *= (n - i + 1);
		ans += x;
	}
	cout << ans << endl;
	return 0;
}
