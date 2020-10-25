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

int main() {
	int n, m, c, x;
	cin >> n >> m;
	vector<int> a(n), b(m), combo(m);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i] >> c;
		for (int j = 0; j < c; ++j) {
			cin >> x;
			combo[i] |= 1 << (x - 1);
		}
	}
	int x1, y1, x2, y2;
	LL ans = 0;
	for (int c1 = (1 << 9) - 1; c1 < (1 << n); c1 = (((c1 & ~y1) / x1) >> 1) | y1) {
		LL sum = 0;
		for (int i = 0; i < n; ++i) {
			if (c1 & (1 << i)) {
				sum += a[i];
			}
		}
		for (int i = 0; i < m; ++i) {
			if (popcount(c1 & combo[i]) >= 3) {
				sum += b[i];
			}
		}
		ans = max(ans, sum);
		x1 = c1 & -c1, y1 = c1 + x1;
	}
	cout << ans << endl;
	return 0;
}
