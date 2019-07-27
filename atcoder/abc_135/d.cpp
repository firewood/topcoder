// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
const LL MOD = 1000000007;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int len = (int)s.length();
	vector<vector<LL>> dp(len + 1, vector<LL>(13));
	dp[0][0] = 1;
	LL r = 1;
	for (int i = 0; i < len; ++i) {
		int col = len - i - 1;
		for (int d = 0; d < 10; ++d) {
			if (s[col] == '?' || (s[col] - '0') == d) {
				for (int j = 0; j < 13; ++j) {
					LL w = (r * d + j) % 13;
					dp[i + 1][w] = (dp[i + 1][w] + dp[i][j]) % MOD;
				}
			}
		}
		r = (r * 10) % 13;
	}
	LL ans = dp[len][5];
	cout << ans << endl;
	return 0;
}
