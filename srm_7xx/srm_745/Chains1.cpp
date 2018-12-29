// BEGIN CUT HERE
/*
SRM 745 Level 2 (300)

PROBLEM STATEMENT
All problems in this problem set are about "chains": collections of nested ranges of integers. All problems are independent, but use the same definitions. Each problem statement contains the definitions it needs. If a term appears in multiple problems, the definition is always identical.

Definitions follow. The defined term is always in uppercase.

An INTERVAL [x,y) with x <= y is the set of integers that are greater than or equal to x, and strictly less than y.

There is only one EMPTY INTERVAL but it has multiple equivalent notations. For example, [0,0) and [3,3) both denote the empty interval. Note that [3,0) is not a valid interval, because an interval [x,y) must have x <= y.


An interval I1 is called a PROPER SUBSET of an interval I2 if I2 contains all elements of I1 and at least one other element.

A CHAIN is a nonempty sequence of intervals such that each interval (except for the last one) is a proper subset of the next interval.

A CHAIN OF ORDER n is any chain such that the last interval in the chain is either the interval [0,n) or its proper subset.

The LENGTH OF A CHAIN is the number of intervals that form it. (I.e., a chain is a sequence of objects, and when we talk about its length, we mean the length of that sequence.)

A MAXIMAL CHAIN OF ORDER n is any chain such that no other chain of order n has a greater length.

You are given the int n.
Compute and return the number of maximal chains of order n.


DEFINITION
Class:Chains1
Method:countMaximalChains
Parameters:int
Returns:long long
Method signature:long long countMaximalChains(int n)


NOTES
-For the given constraints it is guaranteed that the correct return value fits into a long long.


CONSTRAINTS
-n will be between 1 and 50, inclusive.


EXAMPLES

0)
2

Returns: 2

The two maximal chains of order 2 are the following:

[0,0), [0,1), [0,2)
[0,0), [1,2), [0,2)

Note that the chain [1,1), [0,1), [0,2) is the same chain as the first chain listed above. This is because [0,0) and [1,1) are two equivalent ways of writing the empty interval.

In other words, the two maximal chains of order 2 are:

the empty interval, [0,1), [0,2)
the empty interval, [1,2), [0,2)

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

class Chains1 {
public:
	long long countMaximalChains(int n) {
		LL dp[64][64] = {};
		for (int i = 1; i <= n; ++i) {
			dp[0][i] = 1;
		}
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j <= (n - i + 1); ++j) {
				dp[i][j - 1] += dp[i - 1][j];
				dp[i][j] += dp[i - 1][j];
			}
		}
		return dp[n-1][1];
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			long long Arg1 = 2LL;

			verify_case(n, Arg1, countMaximalChains(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 3;
			long long Arg1 = 4LL;

			verify_case(n, Arg1, countMaximalChains(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1;
			long long Arg1 = 1LL;

			verify_case(n, Arg1, countMaximalChains(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 4;
			long long Arg1 = 8LL;

			verify_case(n, Arg1, countMaximalChains(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 31;
			long long Arg1 = 8LL;

			verify_case(n, Arg1, countMaximalChains(Arg0));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Chains1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
