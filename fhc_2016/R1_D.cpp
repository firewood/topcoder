//
// Facebook Hacker Cup 2016 Round 1
// D. Boomerang Tournament
//

/*
Constraints

1 <= T <= 250
N = 2K where K is an integer and 0 <= K <= 4

*/

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		int W[16][16];
		int dp[5][1 << 16][16];
		memset(dp, 0x3f, sizeof(dp));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> W[i][j];
				dp[0][1 << i][i] = N / 2;
			}
		}

		int k, wr = N / 2;
		for (k = 0; (1 << k) < N; ++k, wr /= 2) {
			int x1, y1, x2, y2;
			for (int c1 = (1 << (1 << k)) - 1; c1 < (1 << N); c1 = (((c1 & ~y1) / x1) >> 1) | y1) {
				for (int c2 = (1 << (1 << k)) - 1; c2 < (1 << N); c2 = (((c2 & ~y2) / x2) >> 1) | y2) {
					if ((c1 & c2) == 0) {
						for (int i = 0; i < N; ++i) {
							if (c1 & (1 << i)) {
								int &r = dp[k + 1][c1 | c2][i];
								r = min(r, dp[k][c1][i]);
								if (dp[k][c1][i] == wr) {
									for (int j = 0; j < N; ++j) {
										if (dp[k][c2][j] == wr && W[i][j]) {
											r = wr / 2;
										}
									}
								}
							}
						}
					}
					x2 = c2 & -c2, y2 = c2 + x2;
				}
				x1 = c1 & -c1, y1 = c1 + x1;
			}
		}

		cout << "Case #" << t << ":" << endl;
		for (int i = 0; i < N; ++i) {
			int win = dp[k][(1 << N) - 1][i] + 1;
			int lose = 1;
			for (int j = 0; j < N; ++j) {
				if (i != j && !W[i][j]) {
					lose = N / 2 + 1;
				}
			}
			cout << win << " " << lose << endl;
		}
	}
	return 0;
}
