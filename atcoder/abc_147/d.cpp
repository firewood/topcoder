// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
const LL MOD = 1000000007;

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
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1;
		cin >> n;
		if (n < 0) return 0;
		vector<LL> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		modll ans = 0, inv = modll::modinv(2);
		for (int b = 0; b < 60; ++b) {
			LL c = (1LL << b);
			int pos = 0, neg = 0;
			for (int i = 0; i < n; ++i) {
				if (a[i] & c) {
					++pos;
				} else {
					++neg;
				}
			}
			for (int i = 0; i < n; ++i) {
				modll e;
				if (a[i] & c) {
					e = neg;
				} else {
					e = pos;
				}
				e *= (c % MOD);
				e *= inv;
				ans += e;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
