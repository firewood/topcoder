#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int edit_distance(const vector<int>& a, const vector<int>& b) {
	vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));
	iota(dp[0].begin(), dp[0].end(), 0);
	for (int i = 0; i != a.size(); ++i) {
		dp[i][0] = i;
		for (int j = 0; j != b.size(); ++j) {
			dp[i + 1][j + 1] = min({
				dp[i][j + 1] + 1,
				dp[i + 1][j] + 1,
				dp[i][j] + (a[i] != b[j])
			});
		}
	}
	return dp[a.size()][b.size()];
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	int ans = edit_distance(a, b);
	cout << ans << endl;
	return 0;
}
