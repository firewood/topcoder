// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
const LL MOD = 1000000007;
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

modll combination(LL n, LL r) {
	static modll fact[MAX_N + 1], inv[MAX_N + 1];
	if (!fact[0]) {
		fact[0] = 1;
		for (int i = 1; i <= MAX_N; ++i) {
			fact[i] = fact[i - 1] * i;
		}
		inv[MAX_N] = modll::modinv(fact[MAX_N]);
		for (int i = MAX_N; i >= 1; --i) {
			inv[i - 1] = inv[i] * i;
		}
	}
	if (r > n) {
		return 0;
	}
	return (fact[n] * inv[r]) * inv[n - r];
}

// d•¡‘g‡‚¹
modll nHr(LL n, LL r) {
	return combination(n + r - 1, r);
}

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int k = -1;
		cin >> k;
		string s;
		cin >> s;
		if (k < 0) return 0;

		vector<modll> f25(k + 1), f26(k + 1);
		f25[0] = 1, f26[0] = 1;
		for (int i = 1; i <= k; ++i) {
			f25[i] = f25[i - 1] * 25;
			f26[i] = f26[i - 1] * 26;
		}

		int len = (int)s.length();
		modll ans = 0;
		for (int i = 0; i <= k; ++i) {
			ans += combination(len + i - 1, len - 1) * f25[i] * f26[k - i];
		}

		cout << ans << endl;
	}
	return 0;
}
