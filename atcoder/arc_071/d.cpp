#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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

static const long long MOD = 1000000007;

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

modll get_all_sum(const std::vector<int>& x) {
	int size = (int)x.size();
	modll r = 0, sum = 0;
	for (int i = 1; i < size; ++i) {
		r += modll(x[i] - x[i - 1]) * min(i, size - i) * max(size - i, i);
	}
	return r;
}

void solve(int n, int m, std::vector<int> &x, std::vector<int> &y) {
	modll ans = get_all_sum(x) * get_all_sum(y);
	cout << ans << endl;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> x(n), y(m);
	for (int i = 0; i < n; i++) {
		std::cin >> x[i];
	}
	for (int i = 0; i < m; i++) {
		std::cin >> y[i];
	}
	solve(n, m, x, y);
	return 0;
}
