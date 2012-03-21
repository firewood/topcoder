// BEGIN CUT HERE
/*
// SRM 538 Div2 Easy (300)

// PROBLEM STATEMENT
// The Very Heterogeneous State of Feudalia's army is designing a new spy robot.
Currently, the robot can only accept two commands: L and R. L moves the robot
one unit of distance to the left, and R moves the robot one unit to the right.
A program for the robot is a sequence of commands. For a given program, its
reach is the distance between the starting point and the farthest point visited
during the execution of the program. For example, the reach of the program
"LLLR" is 3, because after the first three steps we reach a location 3 units
away from the starting point.

Unfortunately, Feudalia is world famous for the ineptitude of its public
officials. Some coffee was spilled all over the program before it could be
installed to the robot. Therefore, some of the commands may now be illegible.
Your task is to repair the program by replacing each illegible command with an
L or an R. 
If there are multiple ways to repair the program, you have to pick one that
maximizes its reach.

You are given a string program which describes the program in its current state.
The i-th character in program represents the i-th command that is executed and
will be 'L', 'R' or '?' (quotes for clarity). 'L' represents a legible move left,
'R' a legible move right and '?' a command that is illegible so you can choose
'L' or 'R' in its place. Return the largest reach a repaired program can have.

DEFINITION
Class:LeftOrRight
Method:maxDistance
Parameters:string
Returns:int
Method signature:int maxDistance(string program)


CONSTRAINTS
-program will contain between 1 and 50 characters, inclusive.
-Each character of program will be 'L', 'R' or '?' (quotes for clarity).


EXAMPLES

0)
"LLLRLRRR"

Returns: 3

All commands are legible. The reach of this program is 3: both after three steps
and after five steps we are 3 units to the left of the starting location.


1)
"R???L"

Returns: 4

We can replace all of the question marks with a right command.


2)
"??????"

Returns: 6


3)
"LL???RRRRRRR???"

Returns: 11


4)
"L?L?"

Returns: 4

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

class LeftOrRight {

public:
	int maxDistance(string program) {
		int res = 0;
		int R[64] = {0};
		int L[64] = {0};
		int i;
		int rm = 0, lm = 0;
		for (i = 0; i < (int)program.length(); ++i) {
			switch (program[i]) {
			case 'R':
				R[i+1] = R[i] - 1;
				L[i+1] = L[i] - 1;
				break;
			case 'L':
				R[i+1] = R[i] + 1;
				L[i+1] = L[i] + 1;
				break;
			default:
				R[i+1] = R[i] - 1;
				L[i+1] = L[i] + 1;
				break;
			}
			rm = min(rm, R[i+1]);
			lm = max(lm, L[i+1]);
		}
		return max(-rm, lm);
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
			string Arg0 = "LLLRLRRR";
			int Arg1 = 3;

			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "R???L";
			int Arg1 = 4;

			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "??????";
			int Arg1 = 6;

			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "LL???RRRRRRR???";
			int Arg1 = 11;

			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "L?L?";
			int Arg1 = 4;

			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LeftOrRight ___test;
	___test.run_test(0);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
