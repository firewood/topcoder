// BEGIN CUT HERE
/*
SRM 785 Div2 Easy (250)

PROBLEM STATEMENT

We call a number a palindrome if it reads the same from left to right as it does from right to left.
For example, some palindromic numbers are 6, 11, 121, 666, 100001, and 123454321.
Note that the number 47740 is not a palindrome (as you are not allowed to have unnecessary leading zeros).

Elly has the integer X. Now she wants to find the lowest integer 1 ? Y ? 1,000, such that the product X * Y is a palindrome (if there is such a number). 

Let's look at several examples:

If X = 42, then Y is 6 (42 * 6 = 252).
If X = 121, then Y = 1 (121 * 1 = 121).
If X = 1337, then Y = 143 (1337 * 143 = 191191).
If X = 13, then Y = 38 (13 * 38 = 494).
If X = 100, then no Y can make it a palindrome.
If X = 39325, then Y = 1337 would make it a palindrome (39325 * 1337 = 52577525), but this Y isn't in the bounds [1, 1000].

Given the int X, return the lowest integer Y in the interval [1, 1000] that makes the product X * Y a palindrome, or -1 if there is no such Y.


DEFINITION
Class:EllysPalMulDiv2
Method:getMin
Parameters:int
Returns:int
Method signature:int getMin(int X)


CONSTRAINTS
-X will be between 1 and 100,000, inclusive.


EXAMPLES

0)
42

Returns: 6


1)
121

Returns: 1


2)
1337

Returns: 143


3)
13

Returns: 38


4)
100

Returns: -1


5)
39325

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

typedef long long LL;

class EllysPalMulDiv2 {
	LL gen_palindrome(LL high, LL middle) {
		LL r = middle >= 0 ? high * 10 + middle : high;
		if (high >= 10 || middle >= 0) {
			for (LL low = high; low > 0; low /= 10) {
				r = r * 10 + (low % 10);
			}
		}
		return r;
	}

public:
	int getMin(int X) {
		const LL INF = 1LL << 60;
		LL ans = INF;
		for (LL i = 1; i <= 100000; ++i) {
			for (LL d = -1; d < 10; ++d) {
				LL p = gen_palindrome(i, d);
				LL y = p / X;
				if (y <= 1000 && X * y == p) {
					ans = min(ans, y);
				}
			}
		}
		return ans < INF ? ans : -1;
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
			int Arg0 = 42;
			int Arg1 = 6;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 121;
			int Arg1 = 1;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1337;
			int Arg1 = 143;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 13;
			int Arg1 = 38;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = -1;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 39325;
			int Arg1 = -1;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1;
			int Arg1 = 1;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 29857;
			int Arg1 = 274;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysPalMulDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
