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

int64_t solve(int64_t X) {
	modint ans = 1;
	map<int64_t, int64_t> m;
	m[X] = 1;
	while (true) {
		auto it = m.rbegin();
		int64_t x = it->first;
		int64_t y = it->second;
		if (x <= 4) {
			break;
		}
		m.erase(x);
		m[x / 2] += y;
		m[x / 2] %= (MOD - 1);
		m[(x + 1) / 2] += y;
		m[(x + 1) / 2] %= (MOD - 1);
	}
	for (auto kv : m) {
		ans *= modint::modpow(kv.first, kv.second);
	}
	return ans;
}

int main() {
	int64_t X;
	std::cin >> X;
	cout << solve(X) << endl;
	return 0;
}
