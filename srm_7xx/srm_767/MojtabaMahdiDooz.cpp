// BEGIN CUT HERE
/*
SRM 767 Div2 Easy (250)

PROBLEM STATEMENT

Mahdi is learning the game Dooz by observing Mojtaba who's playing it.

The game is played on a 1 times n board.
Mojtaba has several marbles: exactly one white marble (denoted 'W'), and zero or more black ones (denoted 'B').
At the beginning of the game, the white marble is placed onto the leftmost cell of the board, and the black marbles are placed onto other cells, one per cell.
Some cells may remain empty (denoted '-').

Mojtaba then moves the white marble.
In each move he can do one of two things:

If the cell immediately to the right of the white marble is empty, Mojtaba moves the white marble one cell to the right.
If the cell immediately to the right of the white marble contains a black marble and the next cell after that is empty, Mojtaba jumps the white marble over the black marble, which moves the white marble two cells to the right.

Given the initial state of the game, print the final state of the game.


DEFINITION
Class:MojtabaMahdiDooz
Method:play
Parameters:string
Returns:string
Method signature:string play(string board)


CONSTRAINTS
-Length of board will be between 1 and 50, inclusive.
-Character 0 of board will be 'W'.
-Each other character of board will be '-' or 'B'.


EXAMPLES

0)
"W----"

Returns: "----W"

As there are no obstacles, Mojtaba can move the white marble all the way to the right.


1)
"WB-B-B-"

Returns: "-B-B-BW"

On this board Mojtaba will make three moves of the second type (jumps over a single black marble).


2)
"W--BB---"

Returns: "--WBB---"

We cannot jump over more than one black marble, so the best we can do is to move the white marble two steps to the right.


3)
"W"

Returns: "W"


4)
"W-B--B---BB-"

Returns: "--B--B--WBB-"

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class MojtabaMahdiDooz {
public:
	string play(string board) {
		string ans = board;
		int len = board.length();
		for (int i = 1; i < len; ++i) {
			if (ans[i - 1] == 'W' && ans[i] == '-') {
				swap(ans[i - 1], ans[i]);
			}
			if (i >= 2 && ans[i - 2] == 'W' && ans[i] == '-') {
				swap(ans[i - 2], ans[i]);
			}
		}
		return ans;
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
			string Arg0 = "W----";
			string Arg1 = "----W";

			verify_case(n, Arg1, play(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "WB-B-B-";
			string Arg1 = "-B-B-BW";

			verify_case(n, Arg1, play(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "W--BB---";
			string Arg1 = "--WBB---";

			verify_case(n, Arg1, play(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "W";
			string Arg1 = "W";

			verify_case(n, Arg1, play(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "W-B--B---BB-";
			string Arg1 = "--B--B--WBB-";

			verify_case(n, Arg1, play(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MojtabaMahdiDooz ___test;
	___test.run_test(-1);
}
// END CUT HERE
