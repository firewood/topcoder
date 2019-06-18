// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL n, ga, sa, ba, gb, sb, bb;
	cin >> n >> ga >> sa >> ba >> gb >> sb >> bb;
	for (int t = 0; t < 2; ++t) {
		vector<LL> dp(n + 1);
		iota(dp.begin(), dp.end(), 0);
		for (LL i = ga; i <= n; ++i) {
			dp[i] = max(dp[i], dp[i - ga] + gb);
		}
		for (LL i = sa; i <= n; ++i) {
			dp[i] = max(dp[i], dp[i - sa] + sb);
		}
		for (LL i = ba; i <= n; ++i) {
			dp[i] = max(dp[i], dp[i - ba] + bb);
		}
		n = *max_element(dp.begin(), dp.end());
		swap(ga, gb);
		swap(sa, sb);
		swap(ba, bb);
	}
	cout << n << endl;
	return 0;
}
