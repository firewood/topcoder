#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef long long LL;
#define MOD 1000000007LL

static inline int popcount_ll(LL b) {
#ifdef __GNUC__
	return __builtin_popcountll(b);
#elif _MSC_VER >= 1400
	return (int)__popcnt64(b);
#else
	b = (b & 0x5555555555555555LL) + (b >> 1 & 0x5555555555555555LL);
	b = (b & 0x3333333333333333LL) + (b >> 2 & 0x3333333333333333LL);
	b = (b & 0x0f0f0f0f0f0f0f0fLL) + (b >> 4 & 0x0f0f0f0f0f0f0f0fLL);
	b += b >> 8;
	b += b >> 16;
	return (int)((b + (b >> 32)) & 0x7F);
#endif
}

struct modll {
	long long x;
	modll() { }
	modll(long long _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(const modll &r) { return (x + r.x) % MOD; }
	modll operator+=(const modll &r) { return x = (x + r.x) % MOD; }
	modll operator-(const modll &r) { return (x + MOD - r.x) % MOD; }
	modll operator-=(const modll &r) { return x = (x + MOD - r.x) % MOD; }
	modll operator*(const modll &r) { return (x * r.x) % MOD; }
	modll operator*(int r) { return (x * r) % MOD; }
	modll operator*=(const modll &r) { return x = (x * r.x) % MOD; }
	static modll modinv(int a) { return modpow(a, MOD - 2); }
	static modll modpow(int a, int b) {
		modll x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

int main(int argc, char *argv[]) {
	int N, k;
	cin >> N >> k;
	LL a[64];
	for (int i = 0; i < k; ++i) {
		cin >> a[i];
	}
	sort(a, a + k);
	LL prev = 0;
	modll ans = 1;
	for (int i = 0; i < k; ++i) {
		if ((a[i] & prev) != prev) {
			ans = 0;
		}
		int inc = popcount_ll(prev ^ a[i]);
		for (int j = 2; j <= inc; ++j) {
			ans *= j;
		}
		prev = a[i];
	}
	int inc = N - popcount_ll(prev);
	for (int j = 2; j <= inc; ++j) {
		ans *= j;
	}
	cout << ans << endl;
	return 0;
}
