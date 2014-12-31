// BEGIN CUT HERE
/*
SRM 642 Div2 Medium (500)

PROBLEM STATEMENT

Leo has N lights in a row.
The lights are numbered 1 through N.
Each light is either on or off.

Leo wants to turn all the lights off.
He has N switches he may use.
The switches are also numbered 1 through N.
For each i, switch number i toggles the state of all lights whose numbers are multiples of i.
(For example, switch 3 will toggle the state of light 3, light 6, light 9, and so on.)

You are given the current state of all lights as a string state with N characters.
For each valid i, state[i] is either 'Y' (meaning that light i+1 is currently on) or 'N' (meaning that the light is off).
Determine the smallest number of switches Leo needs to press in order to turn off all the lights.
If there is no way to turn off all the lights, return -1 instead.


DEFINITION
Class:LightSwitchingPuzzle
Method:minFlips
Parameters:string
Returns:int
Method signature:int minFlips(string state)


CONSTRAINTS
-state will contain between 1 and 1000 characters, inclusive.
-Each character of state will be either 'Y' or 'N'.


EXAMPLES

0)
"YYYYYY"

Returns: 1

We can turn off all the lights by pressing switch 1.


1)
"YNYNYNYNY"

Returns: 2

We cannot turn these lights off in a single step.
It can be done in two steps.
One possible solution looks as follows:
First, press the second switch.
This will toggle lights with numbers 2, 4, 6, and 8.
The state of the lights after this change will be "YYYYYYYYY".
Next, press the first switch to toggle all lightbulbs.


2)
"NNNNNNNNNN"

Returns: 0

All the lights are already off. 


3)
"YYYNYYYNYYYNYYNYYYYN"

Returns: 4


4)
"NYNNYNNNYNNNNYNNNNNYNNNNNNYNNNNNNNY"

Returns: 12

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class LightSwitchingPuzzle {
public:
	int minFlips(string state) {
		int ans = 0;
		for (int i = 0; i < (int)state.length(); ++i) {
			if (state[i] == 'Y') {
				++ans;
				for (int j = i; j < (int)state.length(); j += (i + 1)) {
					state[j] = (state[j] == 'Y') ? 'N' : 'Y';
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
			string Arg0 = "YYYYYY";
			int Arg1 = 1;

			verify_case(n, Arg1, minFlips(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "YNYNYNYNY";
			int Arg1 = 2;

			verify_case(n, Arg1, minFlips(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "NNNNNNNNNN";
			int Arg1 = 0;

			verify_case(n, Arg1, minFlips(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "YYYNYYYNYYYNYYNYYYYN";
			int Arg1 = 4;

			verify_case(n, Arg1, minFlips(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "NYNNYNNNYNNNNYNNNNNYNNNNNNYNNNNNNNY";
			int Arg1 = 12;

			verify_case(n, Arg1, minFlips(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LightSwitchingPuzzle ___test;
	___test.run_test(-1);
}
// END CUT HERE
