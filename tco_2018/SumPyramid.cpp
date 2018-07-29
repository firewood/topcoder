// BEGIN CUT HERE
/*
TCO18 R4 Easy (250)

PROBLEM STATEMENT

A sum pyramid is a two-dimensional arrangement of numbers into a pyramid-like shape in which each number (except for the numbers in the bottom row) is the sum of the two numbers that are diagonally below its place.
Here's an example of a sum pyramid:

      25
   12   13
 7    5    8

Note that 12 = 7+5, 13 = 5+8, and 25 = 12+13.

Each row of the sum pyramid is called a level. The sum pyramid shown above has three levels. Note that the number of elements in the bottom row is equal to the number of levels.

You are given the ints levels and top. Consider all sum pyramids with the following properties:

All numbers in the pyramid are nonnegative integers.
The pyramid has levels levels.
The number on the top of the pyramid is top.

Compute and return the number of such pyramids, modulo 10^9 + 7.


DEFINITION
Class:SumPyramid
Method:countPyramids
Parameters:int, int
Returns:int
Method signature:int countPyramids(int levels, int top)


CONSTRAINTS
-levels will be between 1 and 1000, inclusive.
-top will be between 0 and 1000, inclusive.


EXAMPLES

0)
1
47

Returns: 1

In this case the only valid pyramid is just the single number 47.


1)
2
10

Returns: 11

Three of the eleven valid pyramids:


  10       10        10
10  0     4  6      1  9


2)
3
2

Returns: 4

The four pyramids look as follows:


  2       2       2       2
 2 0     1 1     1 1     0 2
2 0 0   1 0 1   0 1 0   0 0 2


3)
5
7

Returns: 18

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
static LL C[1002][1002];
static LL dp[1002][1002];

class SumPyramid {
public:
	int countPyramids(int levels, int top) {
		if (!C[0][0]) {
			for (LL i = 0; i <= 1000; ++i) {
				C[i][0] = 1;
				for (LL j = 1; j <= i; ++j) {
					C[i][j] = min(9999LL, C[i - 1][j - 1] + C[i - 1][j]);
				}
			}
		}
		for (int i = 0; i <= top; ++i) {
			dp[0][i] = 1;
		}
		for (LL i = 1; i < levels; ++i) {
			for (LL j = 0; j <= top; ++j) {
				dp[i][j] = dp[i - 1][j];
				LL k = j - C[levels - 1][i];
				if (k >= 0) {
					dp[i][j] = (dp[i][j] + dp[i][k]) % MOD;
				}
			}
		}
		return dp[levels - 1][top];
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
			int Arg0 = 1;
			int Arg1 = 47;
			int Arg2 = 1;

			verify_case(n, Arg2, countPyramids(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 10;
			int Arg2 = 11;

			verify_case(n, Arg2, countPyramids(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			int Arg2 = 4;

			verify_case(n, Arg2, countPyramids(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 7;
			int Arg2 = 18;

			verify_case(n, Arg2, countPyramids(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1000;
			int Arg1 = 1000;
			int Arg2 = 1005;

			verify_case(n, Arg2, countPyramids(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arg0 = 5;
			int Arg1 = 1000;
			int Arg2 = 448070112;

			verify_case(n, Arg2, countPyramids(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 10;
			int Arg1 = 1000;
			int Arg2 = 659293026;

			verify_case(n, Arg2, countPyramids(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 70;
			int Arg1 = 1000;
			int Arg2 = 42840;

			verify_case(n, Arg2, countPyramids(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SumPyramid ___test;
	___test.run_test(-1);
}
// END CUT HERE
