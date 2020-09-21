#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
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

void solve(long long N, std::vector<int>& A) {
	modll ans = 0, sum = 0;
	for (LL i = 0; i < N; ++i) {
		ans += sum * A[i];
		sum += A[i];
	}
	cout << ans << endl;
}

int main() {
	long long N;
	cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	solve(N, A);
	return 0;
}
