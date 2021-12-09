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

static const int64_t MOD = 998244353;

struct modint {
	int64_t x;
	modint() { }
	modint(int _x) : x(_x) { }
	operator int() const { return (int)x; }
	modint operator+(int y) { return (x + y + MOD) % MOD; }
	modint operator+=(int y) { x = (x + y + MOD) % MOD; return *this; }
	modint operator-(int y) { return (x - y + MOD) % MOD; }
	modint operator-=(int y) { x = (x - y + MOD) % MOD; return *this; }
	modint operator*(int y) { return (x * y) % MOD; }
	modint operator*=(int y) { x = (x * y) % MOD; return *this; }
	modint operator/(int y) { return (x * modpow(y, MOD - 2)) % MOD; }
	modint operator/=(int y) { x = (x * modpow(y, MOD - 2)) % MOD; return *this; }
	static modint modinv(int a) { return modpow(a, MOD - 2); }
	static modint modpow(int a, int b) {
		modint x = a, r = 1;
		for (; b > 0; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

modint combination_slow(int n, int r) {
    if (r > n) return 0;
    r = min(r, n - r);
    if (r == 0) return 1;
    if (r == 1) return n;
    if (r == 2) return (((long long)n * (n - 1)) / 2) % MOD;
    modint a = 1, b = 1;
    for (int i = 0; i < r; ++i) {
        a *= n - i;
        b *= i + 1;
    }
    return a * modint::modinv(b);
}

modint solve(int d) {
    return combination_slow(d * 2, d) * modint::modinv(2);
}

int main() {
    int d;
	std::cin >> d;
	cout << solve(d) << endl;
	return 0;
}
