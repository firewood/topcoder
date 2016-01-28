//
// Facebook Hacker Cup 2016 Round 2
// B. Carnival Coins
//

/*
Constraints

1 <= T <= 100
1 <= N <= 3,000
1 <= K <= 3,000
0 <= p <= 1

*/

#include <algorithm>
#include <numeric>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

#define COMBSZ 3004

int main(int argc, char *argv[])
{
	cin.precision(16);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N, K;
		long double p, ans = 0;
		cin >> N >> K >> p;

		static long double C[COMBSZ][COMBSZ];
		C[0][0] = 1;
		for (int i = 1; i < COMBSZ; ++i) {
			C[i][0] = C[i - 1][0] * (1 - p);
			for (int j = 1; j < COMBSZ; ++j) {
				C[i][j] = C[i - 1][j - 1] * p + C[i - 1][j] * (1 - p);
			}
		}

		long double dp[COMBSZ];
		for (int i = 0; i <= N; ++i) {
			dp[i] = (i < K) ? 0 : accumulate(C[i] + K, C[i] + i + 1, 0.0L);
		}
		for (int i = K; i <= N; ++i) {
			for (int j = K; j < i; ++j) {
				dp[i] = max(dp[i], dp[j] + dp[i - j]);
			}
		}
		ans = dp[N];

		printf("Case #%d: %.7Lf\n", t, ans);
	}
	return 0;
}
