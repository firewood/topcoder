// BEGIN CUT HERE
/*
// SRM 508 Div2 Hard (1000)

// PROBLEM STATEMENT
// NOTE: This problem statement contains subscripts
that may not display properly if viewed outside of the applet.

You're given ints N and R. Count the number of sequences A0, A1, ..., AN-1
such that each Ai is an integer satisfying 0 <= Ai <= R and
A0 + A1 + ... + AN-1 = A0 | A1 | ... | AN-1.
The '|' symbol stands for bitwise OR of the operands.
Return the number of such sequences modulo 1,000,000,009.

DEFINITION
Class:YetAnotherORProblem2
Method:countSequences
Parameters:int, int
Returns:int
Method signature:int countSequences(int N, int R)


NOTES
-If a and b are single bits then a | b is defined as max(a, b).
For two integers, A and B, in order to calculate A | B,
they need to be represented in binary: A = (an...a1)2, B = (bn...b1)2
(if the lengths of their representations are different,
the shorter one is prepended with the necessary number of leading zeroes).
Then A | B = C = (cn...c1)2, where ci = ai | bi.
For example, 10 | 3 = (1010)2 | (0011)2 = (1011)2 = 11.


CONSTRAINTS
-N will be between 2 and 10, inclusive.
-R will be between 1 and 15000, inclusive.


EXAMPLES

0)
2
2

Returns: 7

The possible sequences are: {0,0}, {0,1}, {0,2}, {1,0}, {1,2}, {2,0}, {2,1}.


1)
2
3

Returns: 9

Now we can also have {0,3} and {3,0}.


2)
3
3

Returns: 16


3)
7
1023

Returns: 73741815

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
