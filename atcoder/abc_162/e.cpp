// E.

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
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, k = -1;		// equal or less than 100000
		cin >> n >> k;
		if (n < 0) return 0;
		vector<modll> cnt(k + 1, 0);
		modll ans = modll::modpow(k, n);
		for (int i = k; i >= 2; --i) {
			cnt[i] = modll::modpow(k / i, n);
			for (int j = i * 2; j <= k; j += i) {
				cnt[i] -= cnt[j];
			}
			modll x = i - 1;
			x *= cnt[i];
			ans += x;
		}
		cout << ans << endl;
	}
	return 0;
}
