// C.

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

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<int> sw(m), p(m);
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int s;
			cin >> s;
			sw[i] |= 1 << (s - 1);
		}
	}
	for (int i = 0; i < m; ++i) {
		cin >> p[i];
	}
	int ans = 0;
	for (int i = 0; i < (1 << n); ++i) {
		int j;
		for (j = 0; j < m; ++j) {
			if ((popcount(i & sw[j]) & 1) != p[j]) {
				break;
			}
		}
		ans += j >= m;
	}
	cout << ans << endl;
	return 0;
}
