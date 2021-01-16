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
typedef pair<LL, LL> II;

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

modll solve(long long H, long long W, long long K, std::vector<long long> &h, std::vector<long long> &w, std::vector<std::string> &c) {
	vector<modll> dp(W, 0);
	dp[0] = modll::modpow(3, H * W - K);
	modll tt = modll::modinv(3) * 2;
	map<II, int> m;
	for (int i = 0; i < K; i++) {
		m[II(h[i], w[i])] = c[i][0];
	}
	for (int i = 0; i < H; ++i) {
		vector<modll> next(W, 0);
		for (int j = 0; j < W; ++j) {
			modll x = dp[j];
			II key(i, j);
			if (m.find(key) == m.end()) {
				next[j] = x * tt;
				if (j < W - 1) {
					dp[j + 1] += x * tt;
				}
			} else {
				if (m[key] == 'X' || m[key] == 'D') {
					next[j] = x;
				}
				if (j < W - 1) {
					if (m[key] == 'X' || m[key] == 'R') {
						dp[j + 1] += x;
					}
				}
			}
		}
		if (i == H - 1) {
			return dp[W - 1];
		}
		dp = next;
	}
}

int main() {
    long long H;
	std::cin >> H;
	long long W;
	std::cin >> W;
	long long K;
	std::cin >> K;
	std::vector<long long> h(K);
	std::vector<long long> w(K);
	std::vector<std::string> c(K);
	for (int i = 0; i < K; i++) {
		std::cin >> h[i]; h[i]--;
		std::cin >> w[i]; w[i]--;
		std::cin >> c[i];
	}
	cout << solve(H, W, K, h, w, c) << endl;
	return 0;
}
