// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1;
		cin >> n;
		if (n < 0) return 0;
		vector<pair<LL, int>> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i].first;
			v[i].second = i;
		}
		sort(v.rbegin(), v.rend());
		vector<vector<LL>> dp(n + 1, vector<LL>(n + 1));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= i; ++j) {
				dp[j + 1][i - j] = max(dp[j + 1][i - j], dp[j][i - j] + v[i].first * abs(j - v[i].second));
				dp[j][i - j + 1] = max(dp[j][i - j + 1], dp[j][i - j] + v[i].first * abs(n - 1 - (i - j) - v[i].second));
			}
		}
		LL ans = 0;
		for (int i = 0; i <= n; ++i) {
			ans = max(ans, dp[i][n - i]);
		}
		cout << ans << endl;
	}
	return 0;
}
