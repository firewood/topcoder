// BEGIN CUT HERE
/*
// SRM 554 Div1 Easy (250)

// PROBLEM STATEMENT
// 
John and Brus are building towers using toy bricks.
They have two types of bricks: red and blue ones.
The number of red bricks they have is redCount and each of them has a height of redHeight.
The number of blue bricks they have is blueCount and each of them has a height of blueHeight.

A tower is built by placing bricks one atop another.
A brick can be placed either on the ground, or on a brick of a different color.
(I.e., you are not allowed to put two bricks of the same color immediately on one another.)
A tower has to consist of at least one brick.
The height of a tower is the sum of all heights of bricks that form the tower.
Two towers are considered to be different if they have different heights.
(Two towers of the same height are considered the same, even if they differ in the number and colors of bricks that form them.)

You are given the ints redCount, redHeight, blueCount and blueHeight.
Return the number of different towers that John and Brus can build.


DEFINITION
Class:TheBrickTowerEasyDivOne
Method:find
Parameters:int, int, int, int
Returns:int
Method signature:int find(int redCount, int redHeight, int blueCount, int blueHeight)


CONSTRAINTS
-redCount will be between 1 and 474,747,474, inclusive.
-redHeight will be between 1 and 474,747,474, inclusive.
-blueCount will be between 1 and 474,747,474, inclusive.
-blueHeight will be between 1 and 474,747,474, inclusive.


EXAMPLES

0)
1
2
3
4

Returns: 4

John and Brus have 1 red brick of height 2 and 3 blue bricks of height 4. Using these bricks, it's possible to build 4 towers:
red (height 2);
blue (height 4);
red, blue (height 6);
blue, red, blue (height 10).


1)
4
4
4
7

Returns: 12


2)
7
7
4
4

Returns: 13


3)
47
47
47
47

Returns: 94

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

class TheBrickTowerEasyDivOne {

public:
	int find(int redCount, int redHeight, int blueCount, int blueHeight) {
		int res = 0;
		int a = min(redCount, blueCount);
		int b = max(redCount, blueCount);
		if (redHeight == blueHeight) {
			res = (a * 2) + (b > a);
		} else {
			res = (a * 3) + (b > a);
		}
		return res;
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
			int Arg1 = 2;
			int Arg2 = 3;
			int Arg3 = 4;
			int Arg4 = 4;

			verify_case(n, Arg4, find(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;
			int Arg2 = 4;
			int Arg3 = 7;
			int Arg4 = 12;

			verify_case(n, Arg4, find(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 7;
			int Arg2 = 4;
			int Arg3 = 4;
			int Arg4 = 13;

			verify_case(n, Arg4, find(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 47;
			int Arg1 = 47;
			int Arg2 = 47;
			int Arg3 = 47;
			int Arg4 = 94;

			verify_case(n, Arg4, find(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheBrickTowerEasyDivOne ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
