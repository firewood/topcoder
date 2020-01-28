// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		const int INF = 1 << 29;
		int h = -1, n = -1;
		cin >> h >> n;
		if (h < 0) return 0;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i] >> b[i];
		}
		vector<int> dp(20002, INF);
		dp[0] = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = a[i]; j <= 20000; ++j) {
				dp[j] = min(dp[j], dp[j - a[i]] + b[i]);
			}
		}
		int ans = INF;
		for (int i = h; i <= 20000; ++i) {
			ans = min(ans, dp[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
