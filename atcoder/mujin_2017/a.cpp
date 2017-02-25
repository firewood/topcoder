// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;
static const LL MOD = 1000000007LL;

class BIT {
	std::vector<int> bit;
	int size;
public:
	BIT() { }
	BIT(int sz) { init(sz); }
	void init(int sz) {
		bit = std::vector<int>((size = sz) + 1);
	}
	int sum(int i) {
		int s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(int i, int x) {
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

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

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	BIT bit(262144);
	int cnt = 0, spc = 0, prev = 0, r = 0;
	for (int i = 1; i <= N; ++i) {
		int a;
		cin >> a;
		int left = (i - spc + 1) / 2;
		bit.add(left, 1);
		bit.add(i + 1, -1);
		r += a - (prev + 1);
		if (r > 0) {
			--r;
			++spc;
		}
		prev = a;
	}
	modll ans = 1;
	for (int i = 1; i <= N; ++i) {
		ans *= bit.sum(i);
	}
	cout << ans << endl;
	return 0;
}
