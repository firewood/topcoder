// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;

static const LL MOD = 1000000007;

int main(int argc, char *argv[]) {
	static LL dp[4][100002];
	dp[0][0] = 1;
	string s;
	cin >> s;
	for (int i = 0; i < (int)s.length(); ++i) {
		for (int j = 0; j < 4; ++j) {
			dp[j][i + 1] = s[i] == '?' ? ((dp[j][i] * 3) % MOD) : dp[j][i];
		}
		if (s[i] == 'A' || s[i] == '?') {
			dp[1][i + 1] = (dp[1][i + 1] + dp[0][i]) % MOD;
		}
		if (s[i] == 'B' || s[i] == '?') {
			dp[2][i + 1] = (dp[2][i + 1] + dp[1][i]) % MOD;
		}
		if (s[i] == 'C' || s[i] == '?') {
			dp[3][i + 1] = (dp[3][i + 1] + dp[2][i]) % MOD;
		}
	}
	cout << dp[3][(int)s.length()] << endl;
	return 0;
}
