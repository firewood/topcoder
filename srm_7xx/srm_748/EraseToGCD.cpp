// BEGIN CUT HERE
/*
SRM 748 Div1 Easy (250)

PROBLEM STATEMENT

You have a sequence S of small positive integers.
You want to erase some (possibly none but not all) elements of S in such a way that the greatest common divisor of the resulting sequence becomes exactly goal.

Let W be the number of ways in which the above can be done.
Compute and return the value (W modulo (10^9 + 7)).


DEFINITION
Class:EraseToGCD
Method:countWays
Parameters:vector <int>, int
Returns:int
Method signature:int countWays(vector <int> S, int goal)


NOTES
-Two ways of erasing are different if the sets of indices of erased elements differ.


CONSTRAINTS
-S will have between 1 and 500 elements, inclusive.
-Each element of S will be between 1 and 1000, inclusive.
-goal will be between 1 and 1000, inclusive.


EXAMPLES

0)
{6, 4, 30, 90, 66}
2

Returns: 15

We must keep the element at index 1 (value 4) because if we don't, all elements that remain will be divisible by 3.
In addition to that element we need to keep at least one other element.
Any such solution will already have the correct GCD.


1)
{8, 8, 8}
4

Returns: 0

Each possible subsequence has GCD = 8, and 8 is not 4.


2)
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
1

Returns: 983

Almost all of the 1023 possible ways of erasing work.


3)
{2, 2, 2, 2, 2}
2

Returns: 31

All ways of erasing work (and are counted as distinct ways).

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

static const LL MOD = 1000000007LL;

// BEGIN CUT HERE
#ifndef __GNUC__
long long __gcd(long long a, long long b) { return b ? __gcd(b, a % b) : a; }
#endif
// END CUT HERE

class EraseToGCD {
public:
	int countWays(vector <int> S, int goal) {
		static LL dp[501][1001];
		memset(dp, 0, sizeof(dp));
		int n = (int)S.size();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= 1000; ++j) {
				dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
				LL k = __gcd(j, S[i]);
				dp[i + 1][k] = (dp[i + 1][k] + dp[i][j]) % MOD;
			}
			dp[i + 1][S[i]] = (dp[i + 1][S[i]] + 1) % MOD;
		}
		return (int)dp[n][goal];
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {6, 4, 30, 90, 66};
			int Arg1 = 2;
			int Arg2 = 15;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8, 8, 8};
			int Arg1 = 4;
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			int Arg1 = 1;
			int Arg2 = 983;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 2, 2, 2, 2};
			int Arg1 = 2;
			int Arg2 = 31;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EraseToGCD ___test;
	___test.run_test(-1);
}
// END CUT HERE
