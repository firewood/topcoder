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
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

int64_t solve(std::string S) {
	const int N = S.length();
	vector<modint> dbl(N, 1), tbl(N, 1);
	for (int i = 1; i < N; ++i) {
		dbl[i] = dbl[i - 1] * 2;
	}
	for (int i = 1; i < N; ++i) {
		tbl[i] = tbl[i - 1] * 10 + dbl[i - 1];
	}
	modint ans = 0;
	for (int i = 0; i < N; ++i) {
		ans += tbl[N - 1 - i] * dbl[i] * int(S[i] - '0');
	}
	return ans;
}

int main() {
	std::string S;
	std::cin >> S;
	cout << solve(S) << endl;
	return 0;
}
