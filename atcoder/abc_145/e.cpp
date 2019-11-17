// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> II;

int main(int argc, char* argv[]) {

#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, t = -1;
		cin >> n >> t;
		if (n <= 0 || t < 0) return 0;
		vector<II> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i].first >> v[i].second;
		}
		sort(v.begin(), v.end());
		int ans = 0;
		vector<int> dp(t + 1, -1);
		dp[0] = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = t - 1; j >= 0; --j) {
				if (dp[j] >= 0) {
					ans = max(ans, dp[j] + v[i].second);
				}
				int k = j - v[i].first;
				if (k >= 0 && dp[k] >= 0) {
					dp[j] = max(dp[j], dp[k] + v[i].second);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
