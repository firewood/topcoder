// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>

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

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, a, x, y, ans = 0;
		cin >> n;
		if (n < 0) return 0;
		vector<vector<int>> p(n);
		vector<vector<int>> q(n);
		for (int i = 0; i < n; ++i) {
			cin >> a;
			for (int j = 0; j < a; ++j) {
				cin >> x >> y;
				if (y) {
					p[i].push_back(x - 1);
				} else {
					q[i].push_back(x - 1);
				}
			}
		}
		int bm = 1 << n;
		for (int b = 0; b < bm; ++b) {
			bool ok = true;
			for (int i = 0; i < n; ++i) {
				if ((1 << i) & b) {
					for (int j : p[i]) {
						if (((1 << j) & b) == 0) {
							ok = false;
						}
					}
					for (int j : q[i]) {
						if ((1 << j) & b) {
							ok = false;
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
	return 0;
}
