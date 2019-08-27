// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef long long LL;

static const LL MOD = 1e9 + 7;

class BIT {
	std::vector<LL> bit;
	int size;
public:
	BIT() { }
	BIT(int sz) { init(sz); }
	void init(int sz) {
		bit.resize((size = sz) + 1);
	}
	LL sum(int i) {
		LL s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(int i, LL x) {
		if (i == 163) {
			++i;
			--i;
		}

		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

struct modll {
	long long x;
	modll() { }
	modll(long long _x) : x(_x % MOD) { }
	operator int() const { return (int)x; }
	modll operator+(const modll& r) { return (x + r.x) % MOD; }
	modll operator+=(const modll& r) { return x = (x + r.x) % MOD; }
	modll operator-(const modll& r) { return (x + MOD - r.x) % MOD; }
	modll operator-=(const modll& r) { return x = (x + MOD - r.x) % MOD; }
	modll operator*(const modll& r) { return (x * r.x) % MOD; }
	modll operator*(int r) { return (x * r) % MOD; }
	modll operator*=(const modll& r) { return x = (x * r.x) % MOD; }
	static modll modinv(int a) { return modpow(a, MOD - 2); }
	static modll modpow(int a, int b) {
		modll x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

int main(int argc, char *argv[]) {
	LL n, k, sum = 0;
	cin >> n >> k;
	vector<int> a(n);
	map<int, LL> m;
	map<int, LL> under;
	BIT bit(2000);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		m[a[i]] += 1;
	}
	for (auto kv : m) {
		under[kv.first] = sum;
		sum += kv.second;
	}
	modll ans = 0;
	for (int i = 0; i < n; ++i) {
		bit.add(a[i], 1);
		modll inv = i + 1 - bit.sum(a[i]);
		inv *= k;
		ans += inv;
		modll x = (k * (k - 1)) / 2;
		x *= under[a[i]];
		ans += x;
	}
	cout << ans << endl;
	return 0;
}
