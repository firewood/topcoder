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

int combination(int n, int r) {
	if (r > n) return 0;
	r = min(r, n - r);
	if (r == 0) return 1;
	if (r == 1) return n;
	if (r == 2) return ((n * LL(n - 1)) / 2) % MOD;
	modll a = 1, b = 1;
	for (int i = 0; i < r; ++i) {
		a *= n - i;
		b *= i + 1;
	}
	return a * modll::modinv(b);
}

// d•¡‘g‡‚¹
int nHr(int n, int r) {
	return combination(n + r - 1, r);
}

LL solve(int N, std::vector<int> &A) {
	modll ans = 1;
	int prev = 1, count = 0;
	for (auto x : A) {
		if (x == -1) {
			++count;
		} else {
			ans *= nHr(count + 1, x - prev);
			prev = x;
			count = 0;
		}
	}
	return ans;
}

int main() {
    int N;
	std::cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, A) << endl;
	return 0;
}
