// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	int N, M, K;
	cin >> N >> M >> K;
	int col[100];
	LL pc[100][100];
	for (int i = 0; i < N; ++i) {
		cin >> col[i];
		col[i];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> pc[i][j];
		}
	}
	LL dp[102][102][102];
	memset(dp, 0x3f, sizeof(dp));
	if (col[0]) {
		dp[0][1][col[0] - 1] = 0;
	} else {
		for (int j = 0; j < M; ++j) {
			dp[0][1][j] = pc[0][j];
		}
	}
	for (int i = 1; i < N; ++i) {
		int cs = 1, cm = min(i, K);
		for (int c = cs; c <= cm; ++c) {
			for (int j = 0; j < M; ++j) {
				if (dp[i - 1][c][j] < 0x3f3f3f3f3f3f3f3fLL) {
					if (col[i]) {
						int k = col[i] - 1;
						LL &x = dp[i][c + 1 - (j == k)][k];
						x = min(x, dp[i - 1][c][j]);
					} else {
						for (int k = 0; k < M; ++k) {
							LL &x = dp[i][c + 1 - (j == k)][k];
							x = min(x, dp[i - 1][c][j] + pc[i][k]);
						}
					}
				}
			}
		}
	}
	LL ans = 0x3f3f3f3f3f3f3f3fLL;
	for (int j = 0; j < M; ++j) {
		ans = min(ans, dp[N - 1][K][j]);
	}
	cout << (ans < 0x3f3f3f3f3f3f3f3fLL ? ans : -1) << endl;
	return 0;
}
