// BEGIN CUT HERE
/*
SRM 770 Div2 Easy (250)

PROBLEM STATEMENT

You are given two nonnegative integers P and Q.
Your task is to make the integers equal in as many steps as possible.
In each step you can do one of two things:

Add any prime number to P.
Subtract any prime number from Q.

If it's not possible to make P and Q equal, return -1.
Otherwise, return a nonnegative integer: the maximum (not minimum!) number of steps you can make.


DEFINITION
Class:MaximumMoves
Method:getMaximumMoves
Parameters:long long, long long
Returns:long long
Method signature:long long getMaximumMoves(long long P, long long Q)


NOTES
-Primes are positive integers with exactly two positive integer divisors. The smallest few primes are 2, 3, 5, 7, 11, 13, ... 
-In particular, the numbers 0 and 1 are not prime numbers.


CONSTRAINTS
-P will be between 0 and 10^18, inclusive.
-Q will be between 0 and 10^18, inclusive.


EXAMPLES

0)
5
9

Returns: 2

In one optimal solution we first subtract 2 from Q and then add 2 to P. After these two steps both numbers are equal (both are 7).

1)
5
10

Returns: 2

In one optimal solution we first subtract 2 from Q and then add 3 to P. After these two steps both numbers are equal (both are 8).


2)
5
6

Returns: -1

There's no way to make these P and Q equal.


3)
10
2

Returns: -1

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

class MaximumMoves {
public:
	long long getMaximumMoves(long long P, long long Q) {
		long long d = Q - P;
		return (d == 0 || d >= 2) ? d / 2 : -1;
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
			long long Arg0 = 5LL;
			long long Arg1 = 9LL;
			long long Arg2 = 2LL;

			verify_case(n, Arg2, getMaximumMoves(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 5LL;
			long long Arg1 = 10LL;
			long long Arg2 = 2LL;

			verify_case(n, Arg2, getMaximumMoves(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 5LL;
			long long Arg1 = 6LL;
			long long Arg2 = -1LL;

			verify_case(n, Arg2, getMaximumMoves(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 10LL;
			long long Arg1 = 2LL;
			long long Arg2 = -1LL;

			verify_case(n, Arg2, getMaximumMoves(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MaximumMoves ___test;
	___test.run_test(-1);
}
// END CUT HERE
