// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int dp[101][10] = {};
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int s;
		cin >> s;
		for (int j = 0; j < 10; ++j) {
			dp[i + 1][j] = dp[i][j];
		}
		for (int j = 0; j < 10; ++j) {
			int k = dp[i][j] + s;
			dp[i + 1][k % 10] = max(dp[i + 1][k % 10], k);
		}
	}
	int ans = *max_element(dp[n] + 1, dp[n] + 10);
	cout << ans << endl;
	return 0;
}
