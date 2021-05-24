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

int solve(long long H, long long W, std::vector<std::string> &S) {
	modll ans = 1;
	for (int i = 0; i < H + W - 1; ++i) {
		int rc = 0, bc = 0;
		for (int c = 0; c < W; ++c) {
			int r = i - c;
			if (r >= 0 && r < H) {
				rc += S[r][c] == 'R';
				bc += S[r][c] == 'B';
			}
		}
		if (rc && bc) {
			return 0;
		}
		if (rc == 0 && bc == 0) {
			ans *= 2;
		}
	}
	return ans;
}

int main() {
    long long H, W;
	std::cin >> H >> W;
	std::vector<std::string> S(H);
	for (int i = 0; i < H; i++) {
		std::cin >> S[i];
	}
	cout << solve(H, W, S) << endl;
	return 0;
}
