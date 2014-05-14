// BEGIN CUT HERE
/*
TCO 2014 Round 1A Hard (1000)

PROBLEM STATEMENT
Elly has a row of N lamps, conveniently numbered from 0 to N-1. Some of them are initially lit and the rest are not. She can control the lamps using a controller. On the controller there is a row of N buttons. Clicking the button with index i changes the state of lamp i: it goes off, if it was on, and it goes on if it was off.

Unfortunately the controller has some defects. Each of the buttons correctly changes the state of the corresponding lamp. However, it is possible that some of the buttons also change the state of one or both adjacent lamps as well. This means that pressing the button with index i has the following effects:

The state of lamp i changes.
If there is a lamp with index i-1, its state might change.
If there is a lamp with index i+1, its state might change.

The girl does not initially know which lamps change their state when each of the buttons is pressed. She knows, however, that every time she clicks a particular button, the same set of lamps will change their states.

Elly wants to reach a configuration in which the number of lamps that are turned on is minimized. Help her determine how many of them will remain lit in the worst possible case. (That is, for the worst possible way how the buttons change the state of the lamps.) She can use each of the buttons as many times as she likes, in any order she likes.

You will be given a string lamps, which gives information about the initial state of the lamps. The i-th character of lamps will be 'Y' if the i-th lamp is lit, and 'N', if it is not. Return the minimal number of lit lamps the girl can get in the worst possible case.


DEFINITION
Class:EllysLamps
Method:getMin
Parameters:string
Returns:int
Method signature:int getMin(string lamps)


NOTES
-The defects in the switches might not be symmetric. This means that if a lamp with index i happens to change the state of lamp i+1, this does not necessarily mean that the using the switch of lamp i+1 changes the state of lamp i.


CONSTRAINTS
-lamps will contain between 1 and 50 elements, inclusive.
-Each element of lamps will be either 'Y' or 'N'.


EXAMPLES

0)
"YNNYN"

Returns: 2

In this case Elly will only make things worse (or the same) by pressing buttons. For example, suppose that:

buttons 0 and 1 each change the state of both lamps 0 and 1
buttons 2 and 3 each change the state of both lamps 2 and 3
button 4 only changes the state of lamp 4

In this situation, Elly cannot reach any configuration with fewer than two lit lamps.


1)
"NNN"

Returns: 0

Obviously, with no initially lit lamps, Elly can just sit and relax.


2)
"YY"

Returns: 0

If one of the lamps influences the other one, then Elly can use it and turn both off with one button press. Otherwise, each button changes the state of its lamp only, thus Elly can turn them both off by pressing both buttons.


3)
"YNYYYNNNY"

Returns: 3


4)
"YNYYYYNYNNYYNNNNNNYNYNYNYNNYNYYYNY"

Returns: 13

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class EllysLamps {
public:
	int getMin(string lamps) {
		int ans = 0;
		int yc = 0;
		int N = (int)lamps.size();
		for (int i = 1; i < N; ++i) {
			if (lamps[i - 1] != lamps[i]) {
				++ans;
				++i;
				yc = 0;
			} else {
				++yc;
				if (yc >= 2 && lamps[i] == 'Y') {
					++ans;
					++i;
					yc = 0;
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
			string Arg0 = "YNNYN";
			int Arg1 = 2;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "NNN";
			int Arg1 = 0;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "YY";
			int Arg1 = 0;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "YNYYYNNNY";
			int Arg1 = 3;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "YNYYYYNYNNYYNNNNNNYNYNYNYNNYNYYYNY";
			int Arg1 = 13;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysLamps ___test;
	___test.run_test(-1);
}
// END CUT HERE
