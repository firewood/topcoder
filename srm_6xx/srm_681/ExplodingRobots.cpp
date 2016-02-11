// BEGIN CUT HERE
/*
SRM 681 Div2 Medium (500)

PROBLEM STATEMENT

You have two robots.
Currently, the robots are standing on two different points on an infinite two-dimensional plane.
You are given the ints x1, y1, x2, and y2.
These are the initial coordinates of both robots: one is located at (x1,y1), the other one is at (x2,y2).

The robots know four instructions: U, D, L, and R.
These represent moving 1 unit up, down, left, and right.
More formally, U increases the robot's y coordinate by 1, D decreases the y coordinate by 1, L decreases the x coordinate by 1, and R increases the x coordinate by 1.

You are going to send both robots the same sequence of instructions at the same time.
This sequence of instructions is given in the string instructions.

Both robots are going to execute this sequence of instructions.
They will spend exactly one second executing each instruction.
Unfortunately, your robots are a bit buggy.
It is possible that they will ignore some instructions and spend the corresponding seconds just standing in place.
Each robot has its own bugs and therefore the two robots may ignore different subsets of instructions.
(It is possible that a robot will ignore all instructions, and it is also possible that a robot will execute all instructions it was given.)

The robots will explode if they ever occupy the same point at the same time.

Return the string "Explosion" if it is possible that your two robots will explode.
Otherwise, return "Safe".


DEFINITION
Class:ExplodingRobots
Method:canExplode
Parameters:int, int, int, int, string
Returns:string
Method signature:string canExplode(int x1, int y1, int x2, int y2, string instructions)


CONSTRAINTS
-x1,y1,x2,y2 will be between -25 and 25, inclusive.
-(x1,y1) will be different from (x2,y2).
-instructions will have between 1 and 50 characters, inclusive.
-Each character of instructions will be 'U', 'R', 'L', or 'D'.


EXAMPLES

0)
1
0
2
0
"L"

Returns: "Explosion"

We have two robots.
One starts at coordinates (1,0), the other at (2,0).
We send them a command to move left.
If the first robot ignores it and the second robot moves left, they will collide and explode.


1)
1
0
2
0
"U"

Returns: "Safe"

We have the same starting positions as in Example 0, but this time we send a command to go up.
Regardless of whether they ignore it or perform it, they cannot collide.


2)
1
0
2
0
"UL"

Returns: "Explosion"

In this case, one possible scenario where the robots collide is when the first robot performs the instructions "U", and the second robot performs the instructions "UL".


3)
3
3
5
5
"LURLL"

Returns: "Safe"


4)
10
5
-9
-10
"LULULULLLUULRULULULULULULLULULLULD"

Returns: "Explosion"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class ExplodingRobots {
public:
	string canExplode(int x1, int y1, int x2, int y2, string instructions) {
		int dx = abs(x1 - x2), dy = abs(y1 - y2);
		for (char c : instructions) {
			switch (c) {
			case 'U':
			case 'D':
				dy = max(0, dy - 1);
				break;
			case 'R':
			case 'L':
				dx = max(0, dx - 1);
				break;
			}
		}
		return (dx == 0 && dy == 0) ? "Explosion" : "Safe";
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
			int Arg1 = 0;
			int Arg2 = 2;
			int Arg3 = 0;
			string Arg4 = "L";
			string Arg5 = "Explosion";

			verify_case(n, Arg5, canExplode(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 0;
			int Arg2 = 2;
			int Arg3 = 0;
			string Arg4 = "U";
			string Arg5 = "Safe";

			verify_case(n, Arg5, canExplode(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 0;
			int Arg2 = 2;
			int Arg3 = 0;
			string Arg4 = "UL";
			string Arg5 = "Explosion";

			verify_case(n, Arg5, canExplode(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			int Arg2 = 5;
			int Arg3 = 5;
			string Arg4 = "LURLL";
			string Arg5 = "Safe";

			verify_case(n, Arg5, canExplode(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 5;
			int Arg2 = -9;
			int Arg3 = -10;
			string Arg4 = "LULULULLLUULRULULULULULULLULULLULD";
			string Arg5 = "Explosion";

			verify_case(n, Arg5, canExplode(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ExplodingRobots ___test;
	___test.run_test(-1);
}
// END CUT HERE
