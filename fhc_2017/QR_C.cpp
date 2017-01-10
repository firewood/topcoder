//
// Facebook Hacker Cup 2017 Qualification Round
// C. Fighting the Zombie
//

#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	double dp[21][21][401] = {};
	for (int y = 1; y <= 20; ++y) {
		double p = 1.0 / y;
		dp[y][0][0] = 1.0;
		for (int i = 0; i < 20; ++i) {
			for (int j = 1; j <= y; ++j) {
				for (int k = j; k <= 400; ++k) {
					dp[y][i + 1][k] += dp[y][i][k - j] * p;
				}
			}
		}
	}

//	cout.precision(10);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int H, S;
		cin >> H >> S;
		double ans = 0;
		for (int i = 0; i < S; ++i) {
			string s;
			cin >> s;
			int x, y, z;
			char d;
			if (sscanf(s.c_str(), "%d%c%d+%d", &x, &d, &y, &z) == 4) {
				;
			} else if (sscanf(s.c_str(), "%d%c%d-%d", &x, &d, &y, &z) == 4) {
				z = -z;
			} else if (sscanf(s.c_str(), "%d%c%d", &x, &d, &y) == 3) {
				z = 0;
			}
			if ((x * y + z) >= H) {
				double tot = 0;
				for (int i = max(0, H - z); i <= 400; ++i) {
					tot += dp[y][x][i];
				}
				ans = max(ans, tot);
			}
		}

//		cout << "Case #" << t << ": " << ans << endl;
		printf("Case #%d: %.9lf\n", t, ans);
	}
	return 0;
}
