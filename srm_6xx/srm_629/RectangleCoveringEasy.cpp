// BEGIN CUT HERE
/*
SRM 629 Div2 Easy (250)

PROBLEM STATEMENT

There is a rectangular hole in the ground.
You are given the dimensions of this rectangle: ints holeH and holeW.

You have a rectangular board.
You are given its dimensions: ints boardH and boardW.
You would like to use the board to cover the hole.

There are some rules you must follow when covering the hole:

You may rotate the board, but you must place it so that the sides of the board are parallel to the sides of the hole.
The board must cover the entire hole.
All corners of the board must be strictly outside the hole. (That is, they are not allowed to lie on the boundary of the hole.)

If you can cover the hole using the board you have, return 1. Otherwise, return -1.


DEFINITION
Class:RectangleCoveringEasy
Method:solve
Parameters:int, int, int, int
Returns:int
Method signature:int solve(int holeH, int holeW, int boardH, int boardW)


CONSTRAINTS
-holeW, holeH, boardW, and boardH will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
1
1
1
1

Returns: -1

The vertices of the board must not be on the boundary of the hole.


1)
3
5
4
6

Returns: 1

One possibility is to place the board so that it extends over the hole by 0.5 on each side.


2)
10
20
25
15

Returns: 1

Here we have to rotate the board by 90 degrees.


3)
3
10
3
12

Returns: 1

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class RectangleCoveringEasy {
public:
	int solve(int holeH, int holeW, int boardH, int boardW) {
		int hh = min(holeH, holeW);
		int hw = max(holeH, holeW);
		int bh = min(boardH, boardW);
		int bw = max(boardH, boardW);
		if ((bh > hh && bw >= hw) || (bh >= hh && bw > hw)) {
			return 1;
		}
		return -1;
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
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 1;
			int Arg4 = -1;

			verify_case(n, Arg4, solve(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 5;
			int Arg2 = 4;
			int Arg3 = 6;
			int Arg4 = 1;

			verify_case(n, Arg4, solve(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 20;
			int Arg2 = 25;
			int Arg3 = 15;
			int Arg4 = 1;

			verify_case(n, Arg4, solve(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 10;
			int Arg2 = 3;
			int Arg3 = 12;
			int Arg4 = 1;

			verify_case(n, Arg4, solve(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RectangleCoveringEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
