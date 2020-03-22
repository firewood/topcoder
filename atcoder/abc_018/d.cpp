// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
#include <map>
#include <bitset>

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
		int n = -1, m, p, q, r = -1;
		cin >> n >> m >> p >> q >> r;
		if (n < 0) return 0;
		vector<int> x(r), y(r), z(r);
		for (int i = 0; i < r; ++i) {
			cin >> x[i] >> y[i] >> z[i];
			--x[i], --y[i];
		}
		int ans = 0;
		int mcovered[1 << 18] = {};
		int values[1 << 18] = {};
		int bm = 1 << n;
		for (int b = 1; b < bm; ++b) {
			if (popcount(b) != p) continue;
			vector<int> v(m);
			for (int i = 0; i < r; ++i) {
				if (b & (1 << x[i])) {
					v[y[i]] += z[i];
				}
			}
			sort(v.rbegin(), v.rend());
			ans = max(ans, accumulate(v.begin(), v.begin() + q, 0));
		}
		cout << ans << endl;
	}
	return 0;
}
