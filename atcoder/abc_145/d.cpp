// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const LL MOD = 1000000007;
static const size_t MAX_N = 1000001;

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

vector<modll> fact, inv;

LL combination(LL n, LL r) {
	if (r > n) {
		return 0;
	}
	return (fact[n] * inv[r]) * inv[n - r];
}

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int x = -1, y = -1;
		cin >> x >> y;
		if (x < 0 || y < 0) return 0;

		int xy = x + y;
		fact.resize(xy + 1);
		inv.resize(xy + 1);
		fact[0] = 1;
		for (int i = 1; i <= xy; ++i) {
			fact[i] = fact[i - 1] * i;
		}
		inv[xy] = modll::modinv(fact[xy]);
		for (int i = xy; i >= 1; --i) {
			inv[i - 1] = inv[i] * i;
		}

		modll ans = 0;
		for (int i = 0; i <= x; ++i) {
			int rx = x - i, ry = y - i * 2;
			if (rx == ry * 2) {
				ans += combination(i + ry, ry);
			}
		}

		cout << ans << endl;
	}
	return 0;
}
