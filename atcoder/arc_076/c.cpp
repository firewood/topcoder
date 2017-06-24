// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

static const int MOD = 1000000007;

struct modll {
	long long x;
	modll() : x(0) { }
	modll(long long _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(const modll &r) { return (x + r.x) % MOD; }
	modll operator+=(const modll &r) { return x = (x + r.x) % MOD; }
	modll operator-(const modll &r) { return (x + MOD - r.x) % MOD; }
	modll operator-=(const modll &r) { return x = (x + MOD - r.x) % MOD; }
	modll operator*(const modll &r) { return (x * r.x) % MOD; }
	modll operator*(int r) { return (x * r) % MOD; }
	modll operator*=(const modll &r) { return x = (x * r.x) % MOD; }
	modll inverse() {
		modll r = 1, a = x;
		for (int b = MOD - 2; b; b >>= 1) {
			if (b & 1) {
				r *= a;
			}
			a *= a;
		}
		return r;
	}
};

int main(int argc, char *argv[])
{
	int n, m;
	cin >> n >> m;
	modll ans = 0;
	int a = min(n, m), b = max(n, m);
	if (a == b) {
		ans = 2;
		for (int i = 1; i <= a; ++i) {
			ans *= i;
			ans *= i;
		}
	} else if ((a + 1) == b) {
		ans = 1;
		for (int i = 1; i <= a; ++i) {
			ans *= i;
			ans *= i;
		}
		ans *= b;
	}
	cout << ans << endl;
	return 0;
}
