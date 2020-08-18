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
		vector<vector<vector<LL>>> dp(2, vector<vector<LL>>(c + 1, vector<LL>(4)));
		for (int i = 1; i <= r; ++i) {
			int curr = i & 1, prev = curr ^ 1;
			for (int j = 1; j <= c; ++j) {
				dp[curr][j] = dp[curr][j - 1];
				dp[curr][j][0] = max(dp[curr][j][0], *max_element(dp[prev][j].begin(), dp[prev][j].end()));
				II key(i, j);
				if (m.find(key) != m.end()) {
					for (int k = 3; k > 0; --k) {
						dp[curr][j][k] = max(dp[curr][j][k], dp[curr][j][k - 1] + m[key]);
					}
				}
			}
		}
		LL ans = *max_element(dp[r & 1][c].begin(), dp[r & 1][c].end());
		cout << ans << endl;
	}
	return 0;
}
