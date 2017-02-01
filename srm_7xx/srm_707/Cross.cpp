// BEGIN CUT HERE
/*
SRM 707 Div2 Easy (250)

PROBLEM STATEMENT
There is a rectangular board that is divided into n rows by m columns of cells.
Each cell is either black or white.
You are given the description of the board in the vector <string> board.
Each character in board represents one cell.
More precisely, the character board[i][j] represents the cell at coordinates (row i, column j).
The character '#' represents a black cell, the character '.' is a white cell.

You want to find a cross on this board.
A cross is a configuration of 5 black cells placed like this:

 #
###
 #

Formally, there is a cross centered at (x, y) if the following five cells are all black: (x, y), (x+1, y), (x-1, y), (x, y-1), and (x, y+1).
Note that other cells adjacent to the cross may also be black, it is still a valid cross.

Return "Exists" if there is at least one cross on the given board.
Otherwise, return "Does not exist".
Note that the return value is case-sensitive.


DEFINITION
Class:Cross
Method:exist
Parameters:vector <string>
Returns:string
Method signature:string exist(vector <string> board)


CONSTRAINTS
-n, m will be between 3 and 50, inclusive.
-board will contain exactly n elements.
-Each element in board will contain exactly m characters.
-Each character in board will be either '#' or '.'.


EXAMPLES

0)
{".##",
 "###",
 "##."}

Returns: "Exist"

There is a cross centered at (1,1).


1)
{".##",
 "###",
 "#.."}

Returns: "Does not exist"

This time there is no cross.


2)
{"######",
 "######",
 "######",
 "######",
 "######",
 "######",
 "######"}

Returns: "Exist"


3)
{".#.#",
 "#.#.",
 ".#.#",
 "#.#."}

Returns: "Does not exist"


4)
{".#.#",
 "###.",
 ".###",
 "#.#."}

Returns: "Exist"

*/
// END CUT HERE
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Cross {
	public:
	string exist(vector <string> board) {
		int H = (int)board.size();
		int W = (int)board[0].length();
		for (int i = 1; i < (H - 1); ++i) {
			for (int j = 1; j < (W - 1); ++j) {
				if (board[i - 1][j] == '#' && board[i][j - 1] == '#' && board[i][j] == '#' && board[i][j + 1] == '#' && board[i + 1][j] == '#') {
					return "Exist";
				}
			}
		}
		return "Does not exist";
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
			string Arr0[] = {".##",
 "###",
 "##."};
			string Arg1 = "Exist";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, exist(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".##",
 "###",
 "#.."};
			string Arg1 = "Does not exist";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, exist(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"######",
 "######",
 "######",
 "######",
 "######",
 "######",
 "######"};
			string Arg1 = "Exist";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, exist(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".#.#",
 "#.#.",
 ".#.#",
 "#.#."};
			string Arg1 = "Does not exist";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, exist(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".#.#",
 "###.",
 ".###",
 "#.#."};
			string Arg1 = "Exist";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, exist(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Cross ___test;
	___test.run_test(-1);
}
// END CUT HERE
