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

vector<modint> solve(int64_t N, std::vector<int> A) {
	vector<modint> dp(10, 0);
	dp[(A[0] + A[1]) % 10] += 1;
	dp[(A[0] * A[1]) % 10] += 1;
	for (int i = 2; i < N; ++i) {
		vector<modint> next(10, 0);
		for (int d = 0; d < 10; ++d) {
			next[(d + A[i]) % 10] += dp[d];
			next[(d * A[i]) % 10] += dp[d];
		}
		dp = next;
	}
	return dp;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	vector<modint> ans = solve(N, A);
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;
}
