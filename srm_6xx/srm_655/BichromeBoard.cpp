// BEGIN CUT HERE
/*
SRM 655 Div2 Easy (250)

PROBLEM STATEMENT
We have a rectangular board divided into a grid of unit squares.
We are going to color each square either white or black.

You are given the vector <string> board.
Each character in board represents one unit square.
If board[i][j] is 'B', the corresponding square must be black.
If board[i][j] is 'W', the corresponding square must be white.
Finally, if board[i][j] is '?', you get to choose the color for this square: either white or black.

Two squares are adjacent if they share a common side.
We want to color the board in such a way that no two adjacent squares share the same color.
Return "Possible" (quotes for clarity) if it can be done, or "Impossible" otherwise.


DEFINITION
Class:BichromeBoard
Method:ableToDraw
Parameters:vector <string>
Returns:string
Method signature:string ableToDraw(vector <string> board)


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element in board will contain between 1 and 50 characters, inclusive.
-Each element in board will contain the same number of characters.
-Each character in board will be one of 'W', 'B', '?'.


EXAMPLES

0)
{"W?W",
 "??B",
 "???"}

Returns: "Possible"

The solution is:

WBW
BWB
WBW


1)
{"W??W"}

Returns: "Impossible"

The four possible colorings of this board are WWWW, WWBW, WBWW, and WBBW.
In each of them there is at least one pair of adjacent squares that share the same color.
Thus, there is no way to get a pattern with the desired property.


2)
{"??"}

Returns: "Possible"

There are 2 ways:
WB and BW


3)
{"W???",
 "??B?",
 "W???",
 "???W"}

Returns: "Possible"


4)
{"W???",
 "??B?",
 "W???",
 "?B?W"}

Returns: "Impossible"


5)
{"B"}

Returns: "Possible"

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class BichromeBoard {
	bool possible(vector <string> &board, int c) {
		for (int i = 0; i < (int)board.size(); ++i) {
			for (int j = 0; j < (int)board[0].length(); ++j) {
				if (board[i][j] != '?' && board[i][j] != "BW"[(i + j + c) % 2]) {
					return false;
				}
			}
		}
		return true;
	}
public:
	string ableToDraw(vector <string> board) {
		if (possible(board, 0) || possible(board, 1)) {
			return "Possible";
		}
		return "Impossible";
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
			string Arr0[] = {"W?W",
 "??B",
 "???"};
			string Arg1 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, ableToDraw(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"W??W"};
			string Arg1 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, ableToDraw(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"??"};
			string Arg1 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, ableToDraw(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"W???",
 "??B?",
 "W???",
 "???W"};
			string Arg1 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, ableToDraw(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"W???",
 "??B?",
 "W???",
 "?B?W"};
			string Arg1 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, ableToDraw(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"B"};
			string Arg1 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, ableToDraw(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BichromeBoard ___test;
	___test.run_test(-1);
}
// END CUT HERE
