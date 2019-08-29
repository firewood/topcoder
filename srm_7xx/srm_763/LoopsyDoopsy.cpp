// BEGIN CUT HERE
/*
SRM 763 Div2 Easy (250)

PROBLEM STATEMENT

The number of loops in a digit is the number of closed regions you produce when you write the digit on paper. 
For example, "1" has no loops, "9" has one loop, and "8" has two.
(As the number of loops depends on the font you use, the exact numbers of loops we are using in this problem are given in the Notes.)

By extension, the number of loops in any nonnegative integer is the total number of loops in its individual digits.
For example, "2461" has two loops and "1890" has four.

You are given the int loops.
Find the smallest nonnegative integer with exactly loops loops and return it as a string.
Note that the returned string cannot have unnecessary leading zeros.


DEFINITION
Class:LoopsyDoopsy
Method:getSmallestNumber
Parameters:int
Returns:string
Method signature:string getSmallestNumber(int loops)


NOTES
-The digits 0 through 9 have 1, 0, 0, 0, 1, 0, 1, 0, 2, and 1 loops, respectively.


CONSTRAINTS
-loops will be between 1 and 2,500, inclusive.


EXAMPLES

0)
1

Returns: "0"

0, 4, 6, 9, 10, 24 are some of the non-negative integers with exactly 1 loop.


1)
2

Returns: "8"

8, 49, 66, 100 are some of the non-negative integers with exactly 2 loops.


2)
40

Returns: "88888888888888888888"

Watch out for integer overflow.

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

class LoopsyDoopsy {
public:
	string getSmallestNumber(int loops) {
		if (loops == 1) {
			return "0";
		}
		return (loops % 2 ? "4" : "") + string(loops / 2, '8');
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
			int Arg0 = 1;
			string Arg1 = "0";

			verify_case(n, Arg1, getSmallestNumber(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			string Arg1 = "8";

			verify_case(n, Arg1, getSmallestNumber(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 40;
			string Arg1 = "88888888888888888888";

			verify_case(n, Arg1, getSmallestNumber(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LoopsyDoopsy ___test;
	___test.run_test(-1);
}
// END CUT HERE
