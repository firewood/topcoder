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
		for (LL i = 1; i < n; ++i) {
			for (LL j = i + 1; j <= n; ++j) {
				LL d = min(j - i, abs(i - x) + 1 + abs(j - y));
				ans[d - 1] += 1;
			}
		}
		for (auto x : ans) {
			cout << x << endl;
		}
	}
	return 0;
}
