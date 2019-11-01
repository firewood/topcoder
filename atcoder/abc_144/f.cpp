// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	cout.precision(10);
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, m = -1;
		cin >> n >> m;
		if (n <= 0) return 0;
		vector<vector<int>> fwd(n);
		vector<double> dp(n, 0);
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			fwd[a - 1].push_back(b - 1);
		}
		double ans = 1e9;
		for (int i = 0; i < n - 1; ++i) {
			for (int j = n - 2; j >= 0; --j) {
				double sum = 0, mx = 0;
				for (int next : fwd[j]) {
					double d = dp[next] + 1;
					sum += d;
					mx = max(mx, d);
				}
				if (i == j && fwd[j].size() >= 2) {
					dp[j] = (sum - mx) / (fwd[j].size() - 1);
				} else {
					dp[j] = sum / fwd[j].size();
				}
			}
			ans = min(ans, dp[0]);
		}
		cout << ans << endl;
	}
	return 0;
}
