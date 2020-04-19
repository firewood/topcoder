// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;

const LL MOD = 1000000007;
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

LL range_sum(LL a, LL b) {
	return (b * (b + 1)) / 2 - ((a - 1) * a) / 2;
}

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, k = -1;
		cin >> n >> k;
		if (n < 0) return 0;
		modll ans = 0;
		for (int i = k; i <= n + 1; ++i) {
			LL lower = range_sum(0, i - 1);
			LL upper = range_sum(n + 1 - i, n);
			ans += (upper - lower + 1) % MOD;
		}
		cout << ans << endl;
	}
	return 0;
}
