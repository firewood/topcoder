// BEGIN CUT HERE
/*
SRM 735 Div2 Easy (250)

PROBLEM STATEMENT

You have a very simple calculator that has a display and two buttons.
The buttons are labelled "-2" and "+3".
Whenever you press a button, the corresponding operation is applied to the number shown on the display.
For example, if the display shows the number 10, pressing the "-2" button changes it to 10-2 = 8, while pressing the "+3" button changes it to 10+3 = 13.

You are given the ints a and b.
The display currently shows the integer a.
You would like to change the displayed number to b.
Calculate and return the smallest total number of buttons you need to press.


DEFINITION
Class:BinaryCalculator
Method:minimumSteps
Parameters:int, int
Returns:int
Method signature:int minimumSteps(int a, int b)


CONSTRAINTS
-a will be between 1 and 100, inclusive.
-b will be between 1 and 100, inclusive.


EXAMPLES

0)
10
14

Returns: 3

One solution is to press the button +3 to get 13, then -2 to get 11 and finally +3 to get 14.
There are other ways of obtaining the same result, but none of them is shorter than 3 presses.


1)
23
23

Returns: 0

As a = b, you don't need to press any buttons.


2)
18
12

Returns: 3

The only optimal solution is to press "-2" three times in a row.


3)
23
62

Returns: 13

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class BinaryCalculator {
public:
	int minimumSteps(int a, int b) {
		int ans = 1 << 30;
		for (int i = 0; i < 1000; ++i) {
			for (int j = 0; j < 1000; ++j) {
				if (a - 2 * i + 3 * j == b) {
					ans = min(ans, i + j);
				}
			}
		}
		return ans;
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
			int Arg0 = 10;
			int Arg1 = 14;
			int Arg2 = 3;

			verify_case(n, Arg2, minimumSteps(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 23;
			int Arg1 = 23;
			int Arg2 = 0;

			verify_case(n, Arg2, minimumSteps(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 18;
			int Arg1 = 12;
			int Arg2 = 3;

			verify_case(n, Arg2, minimumSteps(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 23;
			int Arg1 = 62;
			int Arg2 = 13;

			verify_case(n, Arg2, minimumSteps(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BinaryCalculator ___test;
	___test.run_test(-1);
}
// END CUT HERE
