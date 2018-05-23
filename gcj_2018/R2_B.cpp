// Google Code Jam 2018 Round 2
// Problem B. Graceful Chainsaw Jugglers

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

typedef long long LL;

unsigned long long xor128(void)
{
	static unsigned long long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	unsigned long long t;
	t = (x ^ (x << 11));x = y;y = z;z = w; return(w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

int solve_rand(int x, int y) {
	int ans = 0;
	int mp = max(1, min(x, y) + 1);
	for (int z = 0; z < 20000000; ++z) {
		int p = min(x, y);
		int q = max(x, y);
		int t = 0;
		for (int len = 0; q >= len; ++len) {
			int mpcnt = xor128() % mp;
			int pcnt = 0;
			for (int plen = 0; q >= len && p >= plen && pcnt <= mpcnt; ++plen) {
				++pcnt;
				++t;
				p -= plen;
				q -= len;
			}
		}
		ans = max(ans, t);
	}
	return ans - 1;
}

int solve(int a, int b) {
	static int dp[30][512][512];
	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 0;
	int ma = sqrt(a) + 1;
	for (int t = 0; t <= ma; ++t) {
		for (int p = 0; p <= a; ++p) {
			for (int q = 0; q <= b; ++q) {
				if (dp[t][p][q] >= 0) {
					dp[t + 1][p][q] = max(dp[t][p][q], dp[t + 1][p][q]);
					int ar = a - p, br = b - q;
					for (int nb = 0; ar >= t && br >= nb; ++nb) {
						ar -= t, br -= nb;
						int &x = dp[t + 1][a - ar][b - br];
						x = max(x, dp[t][p][q] + nb + 1);
					}
				}
			}
		}
	}
	int ans = 0;
	for (int p = 0; p <= a; ++p) {
		for (int q = 0; q <= b; ++q) {
			ans = max(ans, dp[ma + 1][p][q]);
		}
	}
	return ans - 1;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int r, b;
		cin >> r >> b;
		cout << "Case #" << t << ": " << solve(r, b) << endl;
	}
	return 0;
}
