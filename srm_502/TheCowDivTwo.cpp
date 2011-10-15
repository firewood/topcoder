// BEGIN CUT HERE
/*
// SRM 502 Div2 Hard (1000)
// PROBLEM STATEMENT
// Farmer John had N cows numbered 0 to N-1. One day he saw K cows running away from his farm.
Fox Brus computed the sum of the numbers of the escaped cows.
She only told John that the sum was divisible by N.


Your task is to help John by counting the number of possible sets of escaped cows.
This number may be very big, so return it modulo 1,000,000,007.

DEFINITION
Class:TheCowDivTwo
Method:find
Parameters:int, int
Returns:int
Method signature:int find(int N, int K)


CONSTRAINTS
-N will be between 1 and 1,000, inclusive.
-K will be between 1 and 47, inclusive.
-K will be less than or equal to N.


EXAMPLES

0)
7
4

Returns: 5

7 cows are numbered 0 to 6 and 4 of them run away.
Possible sets of escaped cows are {0, 1, 2, 4}, {0, 3, 5, 6}, {1, 2, 5, 6}, {1, 3, 4, 6}, {2, 3, 4, 5}.

1)
1
1

Returns: 1



2)
58
4

Returns: 7322



3)
502
7

Returns: 704466492



4)
1000
47

Returns: 219736903



#line 67 "TheCowDivTwo.cpp"
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

typedef long long LL;

class TheCowDivTwo {

public:
	int find(int N, int K) {
		const int M = 1000000007;
		LL dp[48][1001] = {0};
		int i, j, k;
		dp[0][0] = 1;
		for (i = 0; i < N; ++i) {
			LL prev[48][1001];
			memcpy(prev, dp, sizeof(dp));
			for (j = 1; j <= K; ++j) {
				for (k = 0; k < N; ++k) {
					// j•C‚Â‚©‚Á‚Ä—]‚è‚ªk
					dp[j][k] += prev[j - 1][(k - i + N) % N];
					dp[j][k] %= M;
				}
			}
		}

		return (int)dp[K][0];
	}
};

// BEGIN CUT HERE
template <typename T> static T __str_to_val(const char *p)
{
	return p;
}
template <> static int __str_to_val(const char *p)
{
	return atoi(p);
}
template <typename T> vector<T> getVector(const char *s)
{
	static const int buffer_size = 1024000;
	static char buffer[buffer_size];
	strcpy(buffer, s);
	vector <T> v;
	char *p = strtok(buffer, " ,");
	while (p) {
		v.push_back(__str_to_val<T>(p));
		p = strtok(NULL, " ,");
	}
	return v;
}

static void Test(int N, int K, int expected)
{
	TheCowDivTwo ___test;
	int result = ___test.find(N, K);
	printf("result: %s, returned %d, expected %d\n", result == expected ? "OK" : "FAILED", result, expected);
}

int main() {
	Test(7, 4, 5);
	Test(1, 1, 1);
	Test(58, 4, 7322);
	Test(502, 7, 704466492);
	Test(1000, 47, 219736903);
	return 0;
}
// END CUT HERE
