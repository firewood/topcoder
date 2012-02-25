// BEGIN CUT HERE
/*
// SRM 500 Div2 Easy Medium Hard (250 500 1000)

// PROBLEM STATEMENT
// Elly and Kriss play a game. The game is played on a single row
that consists of N cells;
we will call it the board. The cells of the board are numbered 0 through N-1,
from the left to the right. Each cell of the board is either empty or occupied
by a single checker. The girls take alternating turns, until one of them
cannot make a move. The girl who is unable to make a move loses the game.

In each move the current player selects a cell containing a checker and
performs one of the following two types of moves:

A step, in which the checker is moved one cell to the right. The step can
only be made if the target cell is empty.
A jump, in which the checker jumps three cells to the right. The jump can
only be made if the target cell is empty and the cells it jumped over contain
two other checkers.

Once a checker reaches the rightmost cell, it disappears immediately and
no longer plays any role in the game.

The initial layout of the board will be given as a string board. The i-th
character of board will be '.' (a period) if the i-th cell is empty at the
beginning, and it will be 'o' (lowercase letter o) if the i-th cell initially
contains a checker. Assume that both girls play optimally. Return "YES"
(quotes for clarity) if the first player wins the game and "NO" otherwise.

DEFINITION
Class:EllysCheckers
Method:getWinner
Parameters:string
Returns:string
Method signature:string getWinner(string board)


NOTES
-If there is a checker on the rightmost cell in the beginning of the game,
 it disappears instantly (before the first move is made), as if it were never there.
-The rules of the game ensure that each cell contains at most one checker
 at any time, and that no checker can jump beyond the last cell.


CONSTRAINTS
-board will contain between 1 and 20 characters, inclusive.
-Each character of board will be either '.' or 'o'.


EXAMPLES

0)
".o..."

Returns: "YES"

With only one checker it is pretty obvious who will win.

1)
"..o..o"

Returns: "YES"

Don't forget to ignore checkers on the rightmost cell.

2)
".o...ooo..oo.."

Returns: "NO"

Here one can jump the checker from cell 5 to cell 8.

3)
"......o.ooo.o......"

Returns: "YES"

4)
".o..o...o....o.....o"

Returns: "NO"

*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
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

typedef map<int, int> IntMap;

class EllysCheckers {
	int N;
	IntMap m;

	int rec(int B) {
		B &= ~1;
		if (B == 0) {
			return 0;
		}
		if (m.find(B) != m.end()) {
			return m[B];
		}
		int &res = m[B];
		res = 0;

		int i, t;
		for (i = N-1; i >= 1; --i) {
			int current = (1 << i);
			int next = (1 << (i-1));
			if ((B & current) != 0 && (B & next) == 0) {
				t = rec((B & ~current) | next);
				if (!t) {
					res = 1;
					return res;
				}
			}
		}
		for (i = N-1; i >= 3; --i) {
			int current = (1 << i);
			int a = (1 << (i-1));
			int b = (1 << (i-2));
			int c = (1 << (i-3));
			if ((B & current) == 0) {
				continue;
			}
			if ((B&a)!=0 && (B&b)!=0 && (B&c)==0) {
				t = rec((B & ~current) | c);
				if (!t) {
					res = 1;
					return res;
				}
			}
		}

		return res;
	}

public:
	string getWinner(string board) {
		N = board.length();
		m.clear();
		int B = 0;
		int i;
		for (i = 0; i < N; ++i) {
			if (board[i] != '.') {
				B |= (1 << (N-i-1));
			}
		}
		return rec(B) ? "YES" : "NO";
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
			string Arg0 = ".o...";
			string Arg1 = "YES";

			verify_case(n, Arg1, getWinner(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "..o..o";
			string Arg1 = "YES";

			verify_case(n, Arg1, getWinner(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = ".o...ooo..oo..";
			string Arg1 = "NO";

			verify_case(n, Arg1, getWinner(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "......o.ooo.o......";
			string Arg1 = "YES";

			verify_case(n, Arg1, getWinner(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = ".o..o...o....o.....o";
			string Arg1 = "NO";

			verify_case(n, Arg1, getWinner(Arg0));
		}
		n++;


		//@@
		if ((Case == -1) || (Case == n)){
			string Arg0 = "....o";
			string Arg1 = "NO";

			verify_case(n, Arg1, getWinner(Arg0));
		}
		n++;
		//@@
		if ((Case == -1) || (Case == n)){
			string Arg0 = "...o.";
			string Arg1 = "YES";

			verify_case(n, Arg1, getWinner(Arg0));
		}
		n++;
		//@@
		if ((Case == -1) || (Case == n)){
			string Arg0 = "oooo";
			string Arg1 = "NO";

			verify_case(n, Arg1, getWinner(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysCheckers ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
