#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	getline(cin, s);
	int N = atoi(s.c_str());
	int C[16], V[16];
	getline(cin, s);
	stringstream sa(s);
	for (int i = 0; i < N; ++i) {
		sa >> C[i];
	}
	getline(cin, s);
	stringstream sb(s);
	for (int i = 0; i < N; ++i) {
		sb >> V[i];
	}

	int dp[2][10002];
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i < N; ++i) {
		int prev = i & 1;
		int curr = prev ^ 1;
		memcpy(dp + curr, dp + prev, sizeof(dp[0]));
		for (int t = 0; t <= T; ++t) {
			int x = dp[prev][t];
			if (x >= 0) {
				int v = V[i];
				for (int j = t + C[i]; v > 0 && j <= T; j += C[i]) {
					x += v;
					v /= 2;
					dp[curr][j] = max(dp[curr][j], x);
				}
			}
		}
	}
	int ans = 0;
	for (int t = 0; t <= T; ++t) {
		ans = max(ans, dp[N & 1][t]);
	}
	cout << ans << endl;
	return 0;
}
