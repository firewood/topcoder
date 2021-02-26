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
static const long long MOD = 998244353;

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

int solve(int N, int M, int K) {
	if (N == 1) {
		return modll::modpow(K, M);
	}
	if (M == 1) {
		return modll::modpow(K, N);
	}
	modll ans = 0;
	for (int i = 1; i <= K; ++i) {
		modll a = modll::modpow(i, N) - modll::modpow(i - 1, N);
		modll b = modll::modpow(K - i + 1, M);
		ans += a * b;
	}
	return ans;
}

int main() {
	int N, M, K;
	std::cin >> N >> M >> K;
	cout << solve(N, M, K) << endl;
	return 0;
}
