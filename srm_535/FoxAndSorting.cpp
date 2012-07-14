// BEGIN CUT HERE
/*
// SRM 535 Div2 Hard (1000)

// PROBLEM STATEMENT
// Fox Jiro and Eel Saburo are good friends. Saburo uses a strange way to
compare integers. Please help Jiro understand it.

For a positive integer n, let d(n) be the sum of its digits in base 10.
For example, d(407) = 4+0+7 = 11.

When comparing two different integers x and y, Saburo first compares their
sums of digits, i.e., the values d(x) and d(y). If they differ, the one
with the smaller sum is smaller.
For example, for Saburo 50 is smaller than 16, because d(50) < d(16).

If the numbers have the same sum of digits, Saburo compares them
lexicographically (i.e., as strings).
For example, for Saburo the number 111 is smaller than the number 3,
because d(111) = d(3) and "111" < "3".
Also, the number 470 is smaller than 4700, because "470" < "4700".

Let A be the sequence of integers {0, 1, ..., 999999999999999998, 999999999999999999 (10^18 - 1)}.
Let B be the sequence A, ordered according to Saburo's rules.
You are given a long long idx, representing a 1-based index into B.
Return the corresponding element of B.


DEFINITION
Class:FoxAndSorting
Method:get
Parameters:long long
Returns:long long
Method signature:long long get(long long idx)


NOTES
-Given two distinct strings A and B, we say that A is lexicographically
 smaller than B if either A is a prefix of B, or A has a smaller character
 than B on the first position on which they differ.


CONSTRAINTS
-idx will be between 1 and 1,000,000,000,000,000,000 (10^18), inclusive.


EXAMPLES

0)
10

Returns: 100000000

First 10 elements of B are: {0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000}.


1)
1000000000000000000

Returns: 999999999999999999

The last element.


2)
58

Returns: 100000000100


3)
314159265358979

Returns: 646003042230121105


4)
271828182845904523

Returns: 132558071125756493

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

#define MAX_DIGITS 18
#define MAX_SUM 9*MAX_DIGITS

typedef long long LL;

class FoxAndSorting {

	LL dp[MAX_DIGITS+1][MAX_SUM+1];

	LL rec(int digits, int sum) {
		LL &res = dp[digits][sum];
		if (res < 0) {
			res = 0;
			if (sum == 0) {
				++res;
			}

			int d;
			for (d = 0; d <= 9 && d <= sum; ++d) {
				if (digits > 0 && (d > 0 || digits < MAX_DIGITS)) {
					res += rec(digits - 1, sum - d);
				}
			}
		}
		return res;
	}

public:
	long long get(long long idx) {
		memset(dp, -1, sizeof(dp));

		int sum;
		for (sum = 0; idx > rec(MAX_DIGITS, sum) ; ++sum) {
			idx -= rec(MAX_DIGITS, sum);
		}

		LL ans = 0;
		int pos;
		for (pos = MAX_DIGITS; pos > 0; --pos) {
			if (sum == 0) {
				if (idx == 1) {
					break;
				} else {
					--idx;
				}
			}
			int d;
			for (d = 0; d <= 9 && d <= sum; ++d) {
				if (d > 0 || pos < MAX_DIGITS) {
					if (idx <= rec(pos-1, sum - d)) {
						ans = ans * 10 + d;
						sum -= d;
						break;
					}
					idx -= rec(pos-1, sum - d);
				}
			}
		}
		return ans;
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
			long long Arg0 = 10LL;
			long long Arg1 = 100000000LL;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1000000000000000000LL;
			long long Arg1 = 999999999999999999LL;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 58LL;
			long long Arg1 = 100000000100LL;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 314159265358979LL;
			long long Arg1 = 646003042230121105LL;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 271828182845904523LL;
			long long Arg1 = 132558071125756493LL;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndSorting ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
