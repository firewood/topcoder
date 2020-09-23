#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

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

void solve(long long N, long long M, std::vector<long long> &x, std::vector<long long> &y) {
	int mat[12][12] = {};
	for (int i = 0; i < M; i++) {
		mat[x[i]][y[i]] = 1;
	}
	int ans = 0;
	for (int b = 1; b < (1 << N); ++b) {
		bool ok = true;
		for (int i = 0; i < N; ++i) {
			if (b & (1 << i)) {
				for (int j = i + 1; j < N; ++j) {
					if (b & (1 << j)) {
						if (!mat[i][j]) ok = false;
					}
				}
			}
		}
		if (ok) {
			ans = max(ans, (int)popcount(b));
		}
	}
	cout << ans << endl;
}

int main() {
	long long N, M;
	std::cin >> N >> M;
	std::vector<long long> x(M), y(M);
	for (int i = 0; i < M; i++) {
		std::cin >> x[i] >> y[i];
		x[i]--, y[i]--;
	}
	solve(N, M, x, y);
	return 0;
}
