#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

static const LL INF = 1LL << 60;
static const long long MOD = 1000000007;
static const size_t MAX_N = 1000001;

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

int combination(int n, int r) {
	if (r > n) return 0;
	if (r == 0 || r == n) return 1;
	if (r == 1) return n;
	if (r == 2) return ((n * LL(n - 1)) / 2) % MOD;

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
	return (fact[n] * inv[r]) * inv[n - r];
}

int nHr(int n, int r) {
	return combination(n + r - 1, r);
}

int solve(int n, int a, int b) {
	if (n - a - b < 0) return 0;
	modll x4 = nHr(n - a - b + 1, 2);
	modll x2 = modll(n - a + 1) * (n - b + 1) - x4 * 2;
	modll all = modll(n - a + 1) * (n - b + 1);
	all *= all;
	return all - x2 * x2;
}

int main() {
	int t, n, a, b;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n >> a >> b;
		cout << solve(n, a, b) << endl;
	}
	return 0;
}
