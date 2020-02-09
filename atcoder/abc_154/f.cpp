// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
#include <map>

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

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL r1 = -1, c1 = -1, r2 = -1, c2 = -1;
		cin >> r1 >> c1 >> r2 >> c2;
		if (r1 < 0) return 0;
		modll ans = 0;

		for (LL r = r1; r <= r2; ++r) {
			modll a = combination(c2 + r + 1, c2);
			ans += a;
			if (c1 > 0) {
				a = combination(c1 + r, c1 - 1);
				ans -= a;
			}
//			cout << (c2 + r) << "," << (c2 - 1) << "," << a << endl;
		}
		cout << ans << endl;
	}
	return 0;
}
