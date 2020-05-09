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

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL n = -1, x, y;
		cin >> n >> x >> y;
		if (n < 0) return 0;
		vector<LL> ans(n - 1);
		LL d = y + 1 - x;
		for (LL k = 1; k <= d / 2; ++k) {
			ans[k - 1] = d;
		}
		if ((d % 2) == 0) {
			ans[d / 2 - 1] /= 2;
		}
		for (LL i = 1; i < x; ++i) {
			for (LL j = 2; j <= n; ++j) {
				LL d = j - i;
				if (j > x && j <= y) {
					d = min(d, x - i + 1 + (y - j));
				}
				if (j > y) {
					d = x - i + 1 + j - y;
				}
				if (d > 0) {
					ans[d - 1] += 1;
				}
			}
		}
		for (LL j = y + 1; j <= n; ++j) {
			for (LL i = x; i < j; ++i) {
				LL d = j - i;
				if (i >= x && i <= y) {
					d = min(d, i - x + 1 + j - y);
				}
				if (d > 0) {
					ans[d - 1] += 1;
				}
			}
		}
		for (auto x : ans) {
			cout << x << endl;
		}
	}
	return 0;
}
