// A.

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <stdio.h>

typedef long long LL;

int main(int argc, char* argv[]) {
	char buffer[3072000];
	LL cnt[20][20] = {};
	LL sum[20][20] = {};
	LL n = 0, ans = 0;
	char c, *bufptr = buffer;
	fread(buffer, 1, 3072000, stdin);
	while ((c = *bufptr++) >= '0') {
		n = (n * 10) + (c - '0');
	}
	for (LL i = 0; i < n; ++i) {
		LL x = 0, two = 0, five = 9, df = 0;
		while ((c = *bufptr++) >= ' ') {
			if (c == '.') {
				df = -1;
			} else {
				x = (x * 10) + c - '0';
				five += df;
			}
		}
		two = __builtin_ctzll(x);
		x >>= two;
		two += five;
		while (x % 5 == 0) {
			++five;
			x /= 5;
		}
		cnt[two > 18 ? 18 : two][five] += 1;
	}
	for (int i = 0; i <= 18; ++i) {
		sum[i][0] = cnt[18 - i][18];
		for (int j = 1; j <= 18; ++j) {
			sum[i][j] += sum[i][j - 1] + cnt[18 - i][18 - j];
		}
	}
	for (int i = 1; i <= 18; ++i) {
		for (int j = 0; j <= 18; ++j) {
			sum[i][j] += sum[i - 1][j];
		}
	}
	for (int i = 0; i <= 18; ++i) {
		for (int j = 0; j <= 18; ++j) {
			ans += sum[i][j] * cnt[i][j];
			if (i >= 9 && j >= 9) {
				ans -= cnt[i][j];
			}
		}
	}
	printf("%lld\n", ans >> 1);
	return 0;
}
