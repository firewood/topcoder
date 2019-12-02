// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long LL;
static const LL MOD = 1000000007;

int main(int argc, char* argv[]) {

#ifdef _MSC_VER
	while (true)
#endif
	{
		LL n = -1, ans = 0, x;
		cin >> n;
		if (n < 0) return 0;
		vector<LL> a(n);
		map<LL, LL> dp;
		dp[0] = 1;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			map<LL, LL> nx;
			for (auto kv : dp) {
				LL p = kv.first >> 36;
				LL q = (kv.first >> 18) & 0x1FFFF;
				LL r = kv.first & 0x1FFFF;
				if (p == x) {
					LL y = ((p + 1) << 36) | (q << 18) | r;
					nx[y] = (nx[y] + kv.second) % MOD;
				}
				if (q == x) {
					LL y = (p << 36) | ((q + 1) << 18) | r;
					nx[y] = (nx[y] + kv.second) % MOD;
				}
				if (r == x) {
					LL y = (p << 36) | (q << 18) | (r + 1);
					nx[y] = (nx[y] + kv.second) % MOD;
				}
			}
			dp = nx;
		}
		for (auto kv : dp) {
			ans = (ans + kv.second) % MOD;
		}
		cout << ans << endl;
	}
	return 0;
}
