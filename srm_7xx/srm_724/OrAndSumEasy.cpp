// BEGIN CUT HERE
/*
SRM 724 Div2 Medium (500)

PROBLEM STATEMENT
You are given two non-negative integers: the long longs pairOr and pairSum.

Determine whether it is possible that for two non-negative integers A and B we have both:

A or B = pairOr
A + B = pairSum

Above, "or" denotes the bitwise-or operator.
Each bit of the result is the logical or of the corresponding bits of the operands.
For example, in base 2 we have (1100 or 0101) = 1101.
The same equation with the numbers written in base 10 looks as follows: (12 or 5) = 13.

Return "Possible" if we can find such A and B, and "Impossible" if not.


DEFINITION
Class:OrAndSumEasy
Method:isPossible
Parameters:long long, long long
Returns:string
Method signature:string isPossible(long long pairOr, long long pairSum)


CONSTRAINTS
-pairOr will be between 0 and 1,000,000,000,000,000,000 (10^18), inclusive.
-pairSum will be between 0 and 1,000,000,000,000,000,000 (10^18), inclusive.


EXAMPLES

0)
7
11

Returns: "Possible"

One of the solution is: A = 5 and B = 6.


1)
11
7

Returns: "Impossible"

We can show the sum should be at least as large as or, so it is impossible.


2)
999799115789631487
999999999999999999

Returns: "Possible"

One of the solution is a = 111111111111111111, b = 888888888888888888.


3)
1
100

Returns: "Impossible"


4)
0
0

Returns: "Possible"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class OrAndSumEasy {
	bool possible(long long pairOr, long long pairSum) {
		int i, j, k;
		for (i = 0; i <= 60; ++i) {
			for (j = 0; j <= 1; ++j) {
				k = (pairSum & 1) ^ j;
				if ((j | k) == (pairOr & 1)) {
					break;
				}
			}
			if (j >= 2) {
				return false;
			}
			pairOr >>= 1;
			pairSum = (pairSum - j - k) >> 1;
		}
		return true;
	}

public:
	string isPossible(long long pairOr, long long pairSum) {
		return possible(pairOr, pairSum) ? "Possible" : "Impossible";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 7LL;
			long long Arg1 = 11LL;
			string Arg2 = "Possible";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 11LL;
			long long Arg1 = 7LL;
			string Arg2 = "Impossible";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 999799115789631487LL;
			long long Arg1 = 999999999999999999LL;
			string Arg2 = "Possible";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 100LL;
			string Arg2 = "Impossible";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 0LL;
			long long Arg1 = 0LL;
			string Arg2 = "Possible";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OrAndSumEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
