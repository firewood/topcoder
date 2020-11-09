#include <algorithm>
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

void solve(string N) {
	const int INF = 1 << 30;
	int ans = INF;
	int len = N.length();
	int bm = 1 << len;
	for (int b = 1; b < bm; ++b) {
		int sum = 0;
		for (int i = 0; i < len; ++i) {
			if (b & (1 << i)) {
				sum += N[i] - '0';
			}
		}
		if ((sum % 3) == 0) {
			ans = min(ans, (int)(len - popcount(b)));
		}
	}
	if (ans == INF) ans = -1;
	cout << ans << endl;
}

int main() {
	string N;
	std::cin >> N;
	solve(N);
	return 0;
}
