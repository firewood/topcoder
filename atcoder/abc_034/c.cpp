// C.

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

static const int MOD = 1000000007;

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
	modll inverse() {
		modll r = 1;
		modll a = x;
		int b = MOD - 2;
		while (b) {
			if (b & 1) {
				r *= a;
			}
			a *= a;
			b >>= 1;
		}
		return r;
	}
};

int main(int argc, char *argv[])
{
	int W, H;
	cin >> W >> H;
	--W, --H;
	modll ans = 1;
	for (int i = H + 1; i <= W + H; ++i) {
		ans *= i;
	}
	for (int i = 1; i <= W; ++i) {
		ans *= modll(i).inverse();
	}
	cout << ans << endl;
	return 0;
}
