#include <iostream>
#include <algorithm>
#include <sstream>
#include <numeric>

using namespace std;

int main(int argc, char *argv[])
{
	cout.precision(12);
	int N, K;
	cin >> N >> K;

	int dp[2][2][80] = {};
	dp[0][0][0] = 1;
	for (int i = 1; i <= N; ++i) {
		int next = i & 1;
		int prev = next ^ 1;
		for (int j = 0; j <= 60; ++j) {
			dp[0][next][j] = 0;
		}
		for (int j = 0; j <= 60; ++j) {
			if (dp[0][prev][j]) {
				for (int k = 1; k <= 6; ++k) {
					dp[0][next][j + k] += dp[0][prev][j];
				}
			}
		}
	}

	dp[1][0][0] = 1;
	for (int i = 1; i <= N; ++i) {
		int next = i & 1;
		int prev = next ^ 1;
		for (int j = 0; j <= 60; ++j) {
			dp[1][next][j] = 0;
		}
		for (int j = 0; j <= 60; ++j) {
			if (dp[1][prev][j]) {
				if (i <= K) {
					for (int k = 0; k < 6; ++k) {
						dp[1][next][j + 4 + (k % 3)] += dp[1][prev][j];
					}
				} else {
					for (int k = 1; k <= 6; ++k) {
						dp[1][next][j + k] += dp[1][prev][j];
					}
				}
			}
		}
	}

	double ans = 0;
	double tot = accumulate(dp[0][N & 1], dp[0][N & 1] + 61, 0);
	for (int i = 2; i <= 60; ++i) {
		double win = accumulate(dp[0][N & 1], dp[0][N & 1] + i, 0);
		ans += (dp[1][N & 1][i] / tot) * (win / tot);
	}
	cout << ans << endl;
	return 0;
}
