#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
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
	int cnt = 0;
	modll ans = 0;
	vector<vector<int>> l2r(H, vector<int>(W)), r2l(H, vector<int>(W));
	vector<vector<int>> t2b(H, vector<int>(W)), b2t(H, vector<int>(W));
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; ++x) {
			if (S[y][x] == '#') continue;
			++cnt;
			l2r[y][x] = 1 + (x > 0 ? l2r[y][x - 1] : 0);
			t2b[y][x] = 1 + (y > 0 ? t2b[y - 1][x] : 0);
		}
	}
	for (int y = H - 1; y >= 0; --y) {
		for (int x = W - 1; x >= 0; --x) {
			if (S[y][x] == '#') continue;
			r2l[y][x] = 1 + (x < W - 1 ? r2l[y][x + 1] : 0);
			b2t[y][x] = 1 + (y < H - 1 ? b2t[y + 1][x] : 0);
		}
	}
	vector<modll> pow2(H * W + 1, 1);
	for (int i = 1; i <= cnt; ++i) {
		pow2[i] = pow2[i - 1] * 2;
	}
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; ++x) {
			int sum = l2r[y][x] + r2l[y][x] + t2b[y][x] + b2t[y][x] - 3;
			if (sum > 0) {
				ans += pow2[cnt - sum] * (pow2[sum] - 1);
			}
		}
	}
	cout << ans << endl;
}

int main() {
    long long H;
	std::cin >> H;
	long long W;
	std::cin >> W;
	std::vector<std::string> S(H);
	for (int i = 0; i < H; i++) {
		std::cin >> S[i];
	}
	solve(H, W, S);
	return 0;
}
