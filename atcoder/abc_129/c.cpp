// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

static const int MOD = 1000000007;

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<int> broken(100002), dp(n + 2);
	for (int i = 0; i < m; ++i) {
		int a;
		cin >> a;
		broken[a] = 1;
	}
	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= 2; ++j) {
			if (dp[i] && !broken[i + j]) {
				dp[i + j] += dp[i];
				dp[i + j] %= MOD;
			}
		}
	}
	cout << dp[n] << endl;
	return 0;
}
