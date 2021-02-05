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

LL solve(long long N, std::string S) {
	if (S[0] == 'W') return 0;
	vector<int> left(N * 2, 1);
	for (int i = 1; i < N * 2; ++i) {
		left[i] = left[i - 1] ^ (S[i - 1] == S[i]);
	}
	if (accumulate(left.begin(), left.end(), 0) != N || left[N * 2 - 1] != 0) {
		return 0;
	}
	modll ans = 1;
	int lc = 0;
	for (int i = 0; i < N * 2; ++i) {
		if (left[i]) {
			++lc;
		} else {
			ans *= lc--;
		}
	}
	for (int i = 1; i <= N; ++i) {
		ans *= i;
	}
	return ans;
}

int main() {
    long long N;
	std::string S;
	std::cin >> N >> S;
	cout << solve(N, S) << endl;
	return 0;
}
