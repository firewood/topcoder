// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		int r = -1, c, k;
		cin >> r >> c >> k;
		if (r < 0) return 0;
		map<II, LL> m;
		for (LL i = 0; i < k; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			m[II(a, b)] = c;
		}
		vector<vector<vector<LL>>> dp(2, vector<vector<LL>>(4, vector<LL>(c + 1)));
		for (int i = 1; i <= r; ++i) {
			int curr = i & 1, prev = curr ^ 1;
			for (int j = 1; j <= c; ++j) {
				for (int k = 0; k <= 3; ++k) {
					dp[curr][k][j] = dp[curr][k][j - 1];
				}
				LL& zero = dp[curr][0][j];
				for (int k = 0; k <= 3; ++k) {
					zero = max(zero, dp[prev][k][j]);
				}
				II key(i, j);
				if (m.find(key) != m.end()) {
					for (int k = 3; k > 0; --k) {
						dp[curr][k][j] = max(dp[curr][k][j], dp[curr][k - 1][j] + m[II(i, j)]);
					}
				}
			}
		}
		LL ans = 0;
		for (int k = 0; k <= 3; ++k) {
			ans = max(ans, dp[r & 1][k][c]);
		}
		cout << ans << endl;
	}
	return 0;
}
