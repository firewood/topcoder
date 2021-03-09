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

#ifdef __GNUC__
#define popcount __builtin_popcount
#elif _MSC_VER >= 1400
#include <intrin.h>
#define popcount __popcnt
#else
static inline int popcount(unsigned int b) {
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	return (b + (b >> 16)) & 0x3F;
}
#endif

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

// 桁DP
LL solve(std::string N, long long K) {
	// 文字 -> 数値
	char t[256] = {};
	for (int i = 0; i < 10; ++i) {
		t['0' + i] = i;
	}
	for (int i = 0; i < 6; ++i) {
		t['A' + i] = 10 + i;
	}

	int eq = 1 << t[N[0]];		// Nと等しく、上位からi桁までの数値の種類
	vector<modll> dp(17, 0);	// Nより小さくn種類の数字を使う個数
	dp[1] = t[N[0]] - 1;		// 最上位で、1以上、Nの最上位の桁未満の個数
	for (size_t i = 1; i < N.length(); ++i) {
		vector<modll> next(17, 0);

		for (int j = 1; j <= 16; ++j) {
			// 既出の種類を使う場合
			next[j] += dp[j] * j;

			// まだ使っていない種類の場合
			if (j < 16) next[j + 1] += dp[j] * (16 - j);
		}

		// 上位がNと一致し、この桁で小さくなるもの
		for (int j = 0; j < t[N[i]]; ++j) {
			next[popcount(eq | (1 << j))] += 1;
		}

		// 最上位が0でこの桁で1-Fになるもの
		next[1] += 15;

		dp = next;
		eq |= 1 << t[N[i]];
	}
	return dp[K] + int(popcount(eq) == K);
}

int main() {
    std::string N;
	long long K;
	std::cin >> N >> K;
	cout << solve(N, K) << endl;
	return 0;
}
