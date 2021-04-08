#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
#include <cassert>

using namespace std;

typedef long long LL;
typedef long double LD;
const LL MOD = 1000000007;
const LD EPS = 1e-10;
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

modll combination_fast(int n, int r) {
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

modll combination(int n, int r) {
	if (r > n) return 0;
	r = min(r, n - r);
	if (r == 0) return 1;
	if (r == 1) return n;
	if (r == 2) return (((long long)n * (n - 1)) / 2) % MOD;
	modll a = 1, b = 1;
	for (int i = 0; i < r; ++i) {
		a *= n - i;
		b *= i + 1;
	}
	return a * modll::modinv(b);
}

// 重複組合せ
modll nHr(int n, int r) {
	return combination(n + r - 1, r);
}

int main(int argc, char* argv[]) {
	modll x = 100;
	vector<int> r;
	for (int i = 0; i < 100; ++i) {
		r.push_back(rand() + 2);
		x *= r.back();
	}
	for (int a : r) {
		x /= a;
	}
	assert(x == 100);

	for (int a = 1; a <= 100; ++a) {
		for (int b = 1; b <= 100; ++b) {
			assert(combination(a, b) == combination_fast(a, b));
		}
	}

	return 0;
}
