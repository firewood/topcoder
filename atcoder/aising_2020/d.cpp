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
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1;
		cin >> n;
		if (n < 0) return 0;
		string x;
		cin >> x;
		int cnt = count(x.begin(), x.end(), '1');
		vector<vector<int>> m(2, vector<int>(n, 1));
		int d[2] = { max(cnt - 1, 1), cnt + 1 };
		int r[2] = {};
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 2; ++j) {
				if (i) {
					m[j][n - 1 - i] = (m[j][n - i] * 2) % d[j];
				}
				if (x[n - 1 - i] != '0') {
					r[j] = (r[j] + m[j][n - 1 - i]) % d[j];
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			if (cnt == 0) {
				cout << 1 << endl;
			} else if (cnt == 1 && x[i] != '0') {
				cout << 0 << endl;
			} else {
				int ans = 1;
				int inc = x[i] == '0';
				int a = (r[inc] + (inc ? 1 : -1) * m[inc][i] + d[inc]) % d[inc];
				while (a) {
					++ans;
					a = a % popcount(a);
				}
				cout << ans << endl;
			}
		}
	}
	return 0;
}
