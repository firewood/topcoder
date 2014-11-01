// BEGIN CUT HERE
/*
SRM 608 Div2 Easy (250)

PROBLEM STATEMENT
A robot is placed on an infinitely long line. Initially the position of the robot is 0. Cat Snuke sends commands to move this robot.

You are given a string commands. For each i, the i-th character of commands (0-based index) represents the i-th command Snuke sends. If the i-th character of commands is 'R', the robot moves one unit to the right (i.e., from position x to position x+1). If this character is 'L', the robot moves one unit to the left (i.e., from position x to position x-1). The robot has a built-in safety mechanism that prevents it from going too far and losing the signal. The safety mechanism makes sure that the robot always stays between the positions -A and B, inclusive. If the robot receives the command 'R' when the robot is at B, or the command 'L' when the robot is at -A, the command will be ignored.

You are given the string commands and the ints A and B. Return the final position of the robot.


DEFINITION
Class:OneDimensionalRobotEasy
Method:finalPosition
Parameters:string, int, int
Returns:int
Method signature:int finalPosition(string commands, int A, int B)


CONSTRAINTS
-commands will contain between 1 and 50 characters, inclusive.
-Each character in commands will be either 'R' or 'L'.
-A and B will be between 1 and 50, inclusive.


EXAMPLES

0)
"RRLRRLLR"
10
10

Returns: 2

The robot will move as follows: 0 -> 1 -> 2 -> 1 -> 2 -> 3 -> 2 -> 1 -> 2.


1)
"RRRRR"
3
4

Returns: 4

The robot will move as follows: 0 -> 1 -> 2 -> 3 -> 4 -> 4.


2)
"LLLLLLLLLLR"
2
6

Returns: -1

The robot will move as follows: 0 -> -1 -> -2 -> -2 -> -2 -> -2 -> -2 -> -2 -> -2 -> -2 -> -2 -> -1.


3)
"RRRRRRRLRRLRRRRRRRRRRRRLRLRRRRRRRRLRRRRRLRRRRRRRRR"
5
20

Returns: 20


4)
"RLRLLLLLLLRLLLRLLLLLLLLRLLLLLRLLLRRLLLLLRLLLLLRLLL"
34
15

Returns: -30

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class OneDimensionalRobotEasy {
public:
	int finalPosition(string commands, int A, int B) {
		int pos = 0;
		for (char c : commands) {
			if (c == 'L') {
				pos = max(-A, pos - 1);
			} else {
				pos = min(B, pos + 1);
			}
		}
		return pos;
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
			string Arg0 = "RRLRRLLR";
			int Arg1 = 10;
			int Arg2 = 10;
			int Arg3 = 2;

			verify_case(n, Arg3, finalPosition(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RRRRR";
			int Arg1 = 3;
			int Arg2 = 4;
			int Arg3 = 4;

			verify_case(n, Arg3, finalPosition(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "LLLLLLLLLLR";
			int Arg1 = 2;
			int Arg2 = 6;
			int Arg3 = -1;

			verify_case(n, Arg3, finalPosition(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RRRRRRRLRRLRRRRRRRRRRRRLRLRRRRRRRRLRRRRRLRRRRRRRRR";
			int Arg1 = 5;
			int Arg2 = 20;
			int Arg3 = 20;

			verify_case(n, Arg3, finalPosition(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RLRLLLLLLLRLLLRLLLLLLLLRLLLLLRLLLRRLLLLLRLLLLLRLLL";
			int Arg1 = 34;
			int Arg2 = 15;
			int Arg3 = -30;

			verify_case(n, Arg3, finalPosition(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OneDimensionalRobotEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
