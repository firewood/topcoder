// BEGIN CUT HERE
/*
SRM 757 Div2 Medium (500)

PROBLEM STATEMENT

There is a very simple way to draw mazes using ASCII characters.
One sample maze with three entrances is shown below.
(The '#'s represent walls, the '.'s represent empty cells.)

#######.#####
......#.#...#
#.###.#.#.#.#
#.#.......#.#
#.#######.#.#
#.......#.#.#
#########.###


Here is the construction of such a maze in more detail.
Let's take a look at an unfinished maze that has walls everywhere.

#############
#.#.#.#.#.#.#
#############
#.#.#.#.#.#.#
#############
#.#.#.#.#.#.#
#############


Rows and columns of the bitmap are numbered starting from 0 in the top left corner.
Notice that the cells with both coordinates odd are still empty.
These cells are called rooms.
The cells that share a side with a room are called hallways and the remaining cells are called pillars.
Hence, pillars have both coordinates even. 
Pillars will always be walls.
Some hallways will eventually be empty while others will be walls.

You are given ints R, C, and X.
Your task is to design any maze with R rows and C columns of rooms (that is, 2R+1 rows of characters, each containing 2C+1 characters).
The maze must have the following additional properties:

Each room must be reachable from each other room, without leaving the maze.
There have to be exactly X exits (i.e., empty hallways on the boundary of the maze).
The total number of wall cells ('#' characters) must be maximized.

Return a vector <string> with the resulting maze. Any valid answer will be accepted.


DEFINITION
Class:FillInTheMaze
Method:filled
Parameters:int, int, int
Returns:vector <string>
Method signature:vector <string> filled(int R, int C, int X)


CONSTRAINTS
-R will be between 1 and 24, inclusive.
-C will be between 1 and 24, inclusive.
-X will be between 1 and 2R+2C, inclusive.


EXAMPLES

0)
3
6
3

Returns: {"#######.#####",
          "......#.#...#",
		  "#.###.#.#.#.#",
		  "#.#.......#.#",
		  "#.#######.#.#",
		  "#.......#.#.#",
		  "#########.###" }

These dimensions correspond to the examples in the problem statement. The maze shown in the statement is indeed one of the optimal solutions.


1)
1
3
2

Returns: {"#######", ".......", "#######" }

A very simple maze with just one row of rooms and with two exits.


2)
2
2
8

Returns: {"#.#.#", ".....", "#.###", ".....", "#.#.#" }

The returned maze:

#.#.#
.....
#.###
.....
#.#.#

Notice the one hallway that remained a wall. An answer without that wall would not be accepted, as the number of '#'s would not be as large as possible.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class FillInTheMaze {
public:
	vector <string> filled(int R, int C, int X) {
		vector <string> ans;
		for (int i = 0; i < 2 * R + 1; ++i) {
			if (i % 2) {
				ans.push_back("#" + string(2 * C - 1, '.') + "#");
			} else {
				ans.push_back(string(2 * C + 1, '#'));
			}
		}
		for (int i = 1; i < 2 * R; ++i) {
			ans[i][1] = '.';
		}
		for (int i = 0; i < R; ++i) {
			if (X > 0) --X, ans[i * 2 + 1][0] = '.';
			if (X > 0) --X, ans[i * 2 + 1][2 * C] = '.';
		}
		for (int i = 0; i < C; ++i) {
			if (X > 0) --X, ans[0][i * 2 + 1] = '.';
			if (X > 0) --X, ans[2 * R][i * 2 + 1] = '.';
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 6;
			int Arg2 = 3;
			string Arr3[] = {"#######.#####", "......#.#...#", "#.###.#.#.#.#", "#.#.......#.#", "#.#######.#.#", "#.......#.#.#", "#########.###" };

			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, filled(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 3;
			int Arg2 = 2;
			string Arr3[] = {"#######", ".......", "#######" };

			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, filled(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 8;
			string Arr3[] = {"#.#.#", ".....", "#.###", ".....", "#.#.#" };

			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, filled(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FillInTheMaze ___test;
	___test.run_test(-1);
}
// END CUT HERE
