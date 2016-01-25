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
		long double p, P[COMBSZ], Q[COMBSZ], R[COMBSZ];
		long double ans = 0;
		cin >> N >> K >> p;

		P[0] = 1, Q[0] = 1, R[0] = 1;
		for (int i = 1; i < COMBSZ; ++i) {
			P[i] = P[i - 1] * p;
			Q[i] = Q[i - 1] * (1 - p);
			R[i] = R[i - 1] * 0.5;
		}

		static long double C[COMBSZ][COMBSZ];
		C[0][0] = 1;
		for (int i = 1; i < COMBSZ; ++i) {
			C[i][0] = C[i - 1][0] * (1 - p);
			for (int j = 1; j < COMBSZ; ++j) {
				C[i][j] = C[i - 1][j - 1] * p + C[i - 1][j] * (1 - p);
			}
		}

		for (int g = K; g <= N; ++g) {
			int x = N / g, r = N - x * g, y = min(x, r);
			int a = y;
			int b = x - a;
			long double e = 0;
			for (int k = K; k <= g + 1; ++k) {
				e += C[g + 1][k] * (double)a;
			}
			for (int k = K; k <= g; ++k) {
				e += C[g][k] * (double)b;
			}
			if (g == 38) {
				++g;
				--g;
			}
			if (e > ans) {
				cout << g << endl;
				ans = max(ans, e);
			}

			if (r >= K) {
				e = 0;
				for (int k = K; k <= g; ++k) {
					e += C[g][k] * (double)x;
				}
				for (int k = K; k <= r; ++k) {
					e += C[r][k];
				}
				ans = max(ans, e);


				if (r > 0) {
					e = 0;
					for (int k = K; k <= g; ++k) {
						e += C[g][k] * (double)(x - 1);
					}
					for (int k = K; k <= g + r; ++k) {
						e += C[g + r][k];
					}
					ans = max(ans, e);
				}
			}
		}

		printf("Case #%d: %.7Lf\n", t, ans);
	}
	return 0;
}
