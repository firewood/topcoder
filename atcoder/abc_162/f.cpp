// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
typedef long long LL;

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL n = -1, ans = -1;
		cin >> n;
		if (n < 0) return 0;
		vector<LL> a(n);
		for (LL i = 0; i < n; ++i) {
			cin >> a[i];
		}
		vector<LL> dp[3];
		for (int i = 0; i < 3; ++i) {
			dp[i] = vector<LL>(n + 8);
		}
		for (LL i = 0; i < n; ++i) {
			dp[0][i + 4]= dp[0][i + 2] + a[i];
			dp[1][i + 4] = max(dp[0][i + 1], dp[1][i + 2]) + a[i];
			dp[2][i + 4] = max({ dp[0][i], dp[1][i + 1], dp[2][i + 2] }) + a[i];
		}
		if ((n % 2) == 0) {
			ans = max({ dp[0][n - 2 + 4], dp[1][n - 1 + 4] });
		} else {
			ans = max({ dp[0][n - 3 + 4], dp[1][n - 2 + 4], dp[2][n - 1 + 4] });
		}
		cout << ans << endl;
	}
	return 0;
}
