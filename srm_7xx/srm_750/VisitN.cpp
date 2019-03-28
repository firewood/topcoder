// BEGIN CUT HERE
/*
SRM 750 Div2 Medium (500)

PROBLEM STATEMENT

You are on a 30x30 chessboard.
The rows of the chessboard are numbered 0 through 29 from the north to the south.
The columns of the chessboard are numbered 0 through 29 from the west to the east.
Your starting cell is (r,c).

Your task is to visit exactly n cells of the chessboard (including the one where you start).
You can move in steps.
In each step you can move one cell in one of the four cardinal directions: north, south, east, or west.
We will denote these movements 'N', 'S', 'E', and 'W'.
You may visit the same cell multiple times.
You may not leave the chessboard. (E.g., if you are in row 0, you cannot move north.)

Return a string with at most 2000 characters: any sequence of moves that never leaves the chessboard and visits exactly n distinct cells.


DEFINITION
Class:VisitN
Method:visit
Parameters:int, int, int
Returns:string
Method signature:string visit(int n, int r, int c)


CONSTRAINTS
-n will be between 1 and 900, inclusive.
-r will be between 0 and 29, inclusive.
-c will be between 0 and 29, inclusive.


EXAMPLES

0)
1
4
7

Returns: ""

The only way to visit exactly one cell is to make no steps at all.


1)
2
4
7

Returns: "N"

By taking a step north we have visited two cells: the cell (4,7) where we started and the cell (3,7) we just reached.


2)
2
0
17

Returns: "W"

This time we are on the north end of the chessboard, so we cannot take a step north. Other valid solutions include "E", "S", and "SNSNSNS".


3)
4
1
1

Returns: "NWEE"

Note that this path visits the cell (0,1) twice, so the number of distinct cells it visits is 4, not 5.


4)
10
5
13

Returns: "NWSSEENNSSWS"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class VisitN {
public:
	string visit(int n, int r, int c) {
		string seq = string(r, 'N') + string(c, 'W');
		for (int i = 0; i < 15; ++i) {
			seq += string(29, 'S') + "E" + string(29, 'N') + "E";
		}
		int vis[30][30] = {};
		string ans;
		for (char ch : seq) {
			if (!vis[r][c]) {
				vis[r][c] = 1;
				if (--n <= 0) {
					break;
				}
			}
			ans += ch;
			if (ch == 'N') --r;
			if (ch == 'E') ++c;
			if (ch == 'W') --c;
			if (ch == 'S') ++r;
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
			int Arg0 = 1;
			int Arg1 = 4;
			int Arg2 = 7;
			string Arg3 = "";

			verify_case(n, Arg3, visit(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 4;
			int Arg2 = 7;
			string Arg3 = "N";

			verify_case(n, Arg3, visit(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 0;
			int Arg2 = 17;
			string Arg3 = "W";

			verify_case(n, Arg3, visit(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 1;
			int Arg2 = 1;
			string Arg3 = "NWEE";

			verify_case(n, Arg3, visit(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 5;
			int Arg2 = 13;
			string Arg3 = "NWSSEENNSSWS";

			verify_case(n, Arg3, visit(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 898;
			int Arg1 = 29;
			int Arg2 = 0;
			string Arg3 = "NWSSEENNSSWS";

			verify_case(n, Arg3, visit(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	VisitN ___test;
	___test.run_test(-1);
}
// END CUT HERE
