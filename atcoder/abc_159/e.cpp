// E.

#include <iostream>
#include <sstream>
#include <algorithm>
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

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int h = -1, w, k;
		cin >> h >> w >> k;
		if (h < 0) return 0;
		vector<string> s(h);
		for (int i = 0; i < h; ++i) {
			cin >> s[i];
		}
		int ans = 1 << 30;
		int bm = 1 << (h - 1);
		for (int b = 0; b < bm; ++b) {
			vector<int> cnt(10);
			int divs = popcount(b);
			int columns = 0;
			for (int col = 0; col < w; ++col) {
				bool ok = true;
				int gi = 0;
				for (int row = 0; row < h; ++row) {
					cnt[gi] += s[row][col] != '0';
					if (cnt[gi] > k) {
						ok = false;
					}
					if (b & 1 << row) {
						++gi;
					}
				}
				if (ok) {
					++columns;
				} else {
					if (!columns) {
						goto next;
					} else {
						--col;
						++divs;
						cnt = vector<int>(10);
						columns = 0;
					}
				}
			}
			ans = min(ans, divs);
		next: {}
		}
		cout << ans << endl;
	}
	return 0;
}
