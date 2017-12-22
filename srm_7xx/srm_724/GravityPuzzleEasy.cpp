// BEGIN CUT HERE
/*
SRM 724 Div2 Easy (250)

PROBLEM STATEMENT
We have a rectangular board divided into unit square cells.
The board is mounted on a wall, with rows going horizontally and columns vertically.
Each cell contains at most one box.
You are given the current state of the board in the vector <string> board.
The elements of board describe the rows of the board from top to bottom.
(I.e., board[0] describes the topmost row of the board, and so on.)
The characters of board[r] describe the cells in row r from left to right, with '.' being an empty cell and '#' a cell with a box.

Due to gravity, each box will fall down: whenever a cell below a box is empty, the box can fall into that cell. Thus, if you have a column with k boxes, those will eventually occupy the bottommost k cells in that column.

Please return a vector <string> describing the state of the board after all boxes finish falling down.


DEFINITION
Class:GravityPuzzleEasy
Method:solve
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> solve(vector <string> board)


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element in board will contain between 1 and 50 characters, inclusive.
-Each element in board will contain the same number of characters.
-Each character in board will be '.' or '#'.


EXAMPLES

0)
{"#",
 ".",
 "."}

Returns: {".", ".", "#" }

This box will fall to the bottom, so we get:

.
.
#


1)
{"##",
 ".#",
 "#."}

Returns: {"..", "##", "##" }

This time we have 2 boxes in each column.


2)
{"..#.#",
 "#.#..",
 "...##"}

Returns: {".....", "..#.#", "#.###" }


3)
{"#####",
 "#####",
 "#####",
 "#####"}

Returns: {"#####", "#####", "#####", "#####" }


4)
{"."}

Returns: {"." }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class GravityPuzzleEasy {
public:
	vector <string> solve(vector <string> board) {
		vector <string> ans = board;
		for (int i = board.size() - 1; i >= 0; --i) {
			for (int j = 0; j < (int)ans[i].length(); ++j) {
				for (int k = i - 1; k >= 0; --k) {
					if (ans[i][j] == '.' && ans[k][j] != '.') {
						swap(ans[i][j], ans[k][j]);
						break;
					}
				}
			}
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
			string Arr0[] = {"#",
 ".",
 "."};
			string Arr1[] = {".", ".", "#" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"##",
 ".#",
 "#."};
			string Arr1[] = {"..", "##", "##" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..#.#",
 "#.#..",
 "...##"};
			string Arr1[] = {".....", "..#.#", "#.###" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#####",
 "#####",
 "#####",
 "#####"};
			string Arr1[] = {"#####", "#####", "#####", "#####" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"."};
			string Arr1[] = {"." };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GravityPuzzleEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
