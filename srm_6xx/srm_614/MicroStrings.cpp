// BEGIN CUT HERE
/*
SRM 614 Div2 Easy (250)

PROBLEM STATEMENT
John couldn't handle long strings so he came up with the idea of MicroStrings.

You are given two positive ints: A and D. These determine an infinite decreasing arithmetic progression: A, A-D, A-2D, and so on. Clearly, only finitely many elements of such a progression are non-negative.

Each such progression defines one MicroString, as follows: You take all the non-negative elements, convert each of them into a string, and then concatenate those strings (in order).

For example, let A=12 and D=5. For these values we get the arithmetic progression (12, 7, 2, -3, -8, ...). The non-negative elements are 12, 7, and 2. The corresponding strings are "12", "7", and "2". Their concatenation is the following MicroString: "1272".

Given A and D, return the MicroString they define.


DEFINITION
Class:MicroStrings
Method:makeMicroString
Parameters:int, int
Returns:string
Method signature:string makeMicroString(int A, int D)


NOTES
-When converting a number to a string, the string must not have unnecessary leading zeros.


CONSTRAINTS
-A will be between 1 and 200, inclusive.
-D will be between 1 and 200, inclusive.


EXAMPLES

0)
12
5

Returns: "1272"

This is the example from the problem statement.


1)
3
2

Returns: "31"


2)
31
40

Returns: "31"


3)
30
6

Returns: "3024181260"

The number 0 is also non-negative. When we convert it into a string, we get the string "0".

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class MicroStrings {
public:
	string makeMicroString(int A, int D) {
		string ans;
		while (A >= 0) {
			char buf[256];
			sprintf(buf, "%d", A);
			ans += buf;
			A -= D;
		}
		return ans;
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
			int Arg0 = 12;
			int Arg1 = 5;
			string Arg2 = "1272";

			verify_case(n, Arg2, makeMicroString(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			string Arg2 = "31";

			verify_case(n, Arg2, makeMicroString(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 31;
			int Arg1 = 40;
			string Arg2 = "31";

			verify_case(n, Arg2, makeMicroString(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 30;
			int Arg1 = 6;
			string Arg2 = "3024181260";

			verify_case(n, Arg2, makeMicroString(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MicroStrings ___test;
	___test.run_test(-1);
}
// END CUT HERE
