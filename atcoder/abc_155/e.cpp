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
		string s;
		cin >> s;
		if (s.empty()) return 0;
		int len = (int)s.length();
		int dp[1000002][2] = {};
		dp[0][0] = 0, dp[0][1] = 1;
		for (int i = 0; i < len; ++i) {
			int d = s[i] - '0';
			dp[i + 1][0] = min(dp[i][0] + d, dp[i][1] + 10 - d);
			dp[i + 1][1] = min(dp[i + 1][0] + 1, dp[i][1] + 10 - d - 1);
		}
		cout << dp[len][0] << endl;
	}
	return 0;
}
