// BEGIN CUT HERE
/*
// SRM 508 Div2 Hard (1000)

問題
R以下のN個の数値において、和と論理和が等しい組み合わせの数を求める。

*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

#define MOD 1000000009
#define MAX_N 10
#define MAX_R 16384

class YetAnotherORProblem2 {

	public:
	int countSequences(int N, int R) {
		static int dp[MAX_N+1][MAX_R];
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;

		int i, j, k;
		for (i = 1; i <= N; ++i) {
			for (j = 0; j < MAX_R; ++j) {
				for (k = j; k >= 0; --k) {
					k &= j;
					if (k <= R) {
						dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % MOD;
					}
				}
			}
		}

		int res = 0;
		for (j = 0; j < MAX_R; ++j) {
			res = (res + dp[N][j]) % MOD;
		}
		return res;
	}
};

// BEGIN CUT HERE
static void Test(int N, int R, int expected)
{
	YetAnotherORProblem2 ___test;
	int result = ___test.countSequences(N, R);
	printf("result: %s, returned %d, expected %d\n", result == expected ? "OK" : "FAILED", result, expected);
}

int main() {
	// example 0
	Test(2, 2, 7);

	// example 1
	Test(2, 3, 9);

	// example 2
	Test(3, 3, 16);

	// example 3
	Test(7, 1023, 73741815);

	return 0;
}
// END CUT HERE
