#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;
static const LL INF = 1LL << 60;

static const long long MOD = 1000000007;
static const size_t MAX_N = 1000001;

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

void solve(long long H, long long W, std::vector<std::string> &S) {
	vector<vector<modll>> dp(H, vector<modll>(W, 0));
	vector<vector<modll>> hsum = dp, vsum = dp, dsum = dp;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (i == 0 && j == 0) {
				dp[i][j] = 1;
				continue;
			}
			if (j > 0) {
				if (S[i][j - 1] != '#') {
					modll h = dp[i][j - 1];
					h += hsum[i][j - 1];
					dp[i][j] += h;
					hsum[i][j] = h;
				}
			}
			if (i > 0) {
				if (S[i - 1][j] != '#') {
					modll v = dp[i - 1][j];
					v += vsum[i - 1][j];
					dp[i][j] += v;
					vsum[i][j] = v;
				}
			}
			if (i > 0 && j > 0) {
				if (S[i - 1][j - 1] != '#') {
					modll d = dp[i - 1][j - 1];
					d += dsum[i - 1][j - 1];
					dp[i][j] += d;
					dsum[i][j] = d;
				}
			}
		}
	}
	modll ans = dp[H - 1][W - 1];
	cout << ans << endl;
}

int main() {
	long long H, W;
	std::cin >> H >> W;
	std::vector<std::string> S(H);
	for (int i = 0; i < H; i++) {
		std::cin >> S[i];
	}
	solve(H, W, S);
	return 0;
}
