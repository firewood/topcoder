// BEGIN CUT HERE
/*
SRM 610 Div1 Easy (250)
SRM 610 Div1 Medium (500)

PROBLEM STATEMENT
A chessboard consists of alternating black and white squares: every square differs in color from
the squares that are adjacent to it vertically and horizontally.

You are given a rectangular board of black and white squares in a vector <string> board.
However, the coloring of the squares might not match the chessboard coloring scheme. Each string in
board represents a row of squares of the board, and each character (all either 'B' or 'W') represents
a square in that row. Return the minimum number of squares that would need their color swapped for
the given board to become a valid chessboard.


DEFINITION
Class:BrokenChessboard
Method:minimumFixes
Parameters:vector <string>
Returns:int
Method signature:int minimumFixes(vector <string> board)


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will contain between 1 and 50 characters, inclusive.
-Each element of board will be the same length.
-Each character of each element of board will be either 'B' or 'W'.


EXAMPLES

0)
{"BWB",
 "BBW",
 "BWW"}

Returns: 2

There are two ways to fix this board:

BWB  WBW
WBW  BWB
BWB  WBW


The result on the left would require changing 2 squares (center-left and bottom-right).
The result on the right would mean changing 7 squares, so the former is a better choice.


1)
{"WW",
 "WW"}

Returns: 2

Either of the two valid boards we could make would take exactly 2 changes.


2)
{"BWB",
 "WBW",
 "BWB"}

Returns: 0

This board is already valid, so no fixes are needed.


3)
{"B",
 "W",
 "B",
 "B"}

Returns: 1

The board is not square, but anyways it only needs 1 square changed.


4)
{"BWBBB",
 "WWBBW",
 "BBBBW",
 "WBWBB"}

Returns: 7

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class BrokenChessboard {
public:
	int minimumFixes(vector <string> board) {
		int ans = 1 << 30;
		for (int i = 0; i < 2; ++i) {
			int cnt = 0;
			for (int r = 0; r != board.size(); ++r) {
				for (int c = 0; c != board[r].length(); ++c) {
					cnt += board[r][c] == (((i + r + c) % 2) ? 'W' : 'B');
				}
			}
			ans = min(ans, cnt);
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
			string Arr0[] = {"BWB",
 "BBW",
 "BWW"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumFixes(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"WW",
 "WW"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumFixes(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"BWB",
 "WBW",
 "BWB"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumFixes(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"B",
 "W",
 "B",
 "B"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumFixes(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"BWBBB",
 "WWBBW",
 "BBBBW",
 "WBWBB"};
			int Arg1 = 7;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumFixes(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BrokenChessboard ___test;
	___test.run_test(-1);
}
// END CUT HERE
