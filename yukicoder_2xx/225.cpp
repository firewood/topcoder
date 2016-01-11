#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	int N, M;
	string S, T;
	cin >> N >> M >> S >> T;
	int dp[1001][1001] = {}, slen = S.length(), tlen = T.length();
	for (int j = 1; j <= tlen; ++j) {
		dp[0][j] = j;
	}
	for (int i = 1; i <= slen; ++i) {
		for (int j = 1; j <= tlen; ++j) {
			int cost = min(dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1);
			if (j > 1) {
				cost = min(cost, dp[i][j - 1] + 1);
			}
			if (S[i - 1] == T[j - 1]) {
				cost = min(cost, dp[i - 1][j - 1]);
			}
			dp[i][j] = cost;
		}
	}
	int ans = dp[slen][tlen];
	cout << ans << endl;
	return 0;
}
