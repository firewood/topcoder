// BEGIN CUT HERE
/*
SRM 657 Div2 Easy (250)

PROBLEM STATEMENT
Cat Snuke is playing a puzzle called Eight Rooks Puzzle.

In this puzzle, he must put exactly eight rooks onto an 8x8 chessboard. No two rooks must be in the same row, and no two rooks must be in the same column.

You are given a vector <string> board. The j-th character of the i-th element of board is either 'R' or '.'. If this is 'R', the cell in row i, column j contains a rook. Otherwise the cell doesn't contain a rook.

Determine whether Snuke solved the puzzle correctly. If he solved the puzzle correctly, return "Correct". Otherwise return "Incorrect".


DEFINITION
Class:EightRooks
Method:isCorrect
Parameters:vector <string>
Returns:string
Method signature:string isCorrect(vector <string> board)


CONSTRAINTS
-board will contain exactly 8 elements.
-Each element of board will contain exactly 8 characters.
-Each character in board will be either 'R' or '.'.


EXAMPLES

0)
{"R.......",
 ".R......",
 "..R.....",
 "...R....",
 "....R...",
 ".....R..",
 "......R.",
 ".......R"}

Returns: "Correct"


1)
{"........",
 "....R...",
 "........",
 ".R......",
 "........",
 "........",
 "..R.....",
 "........"}

Returns: "Incorrect"

The number of rooks is not eight.


2)
{"......R.",
 "....R...",
 "...R....",
 ".R......",
 "R.......",
 ".....R..",
 "..R.....",
 ".......R"}

Returns: "Correct"


3)
{"......R.",
 "....R...",
 "...R....",
 ".R......",
 "R.......",
 ".......R",
 "..R.....",
 ".......R"}

Returns: "Incorrect"

The rightmost column contains two rooks.


4)
{"........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........"}

Returns: "Incorrect"

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

class EightRooks {
public:
	string isCorrect(vector <string> board) {
		for (int i = 0; i < 8; ++i) {
			int xc = 0, yc = 0;
			for (int j = 0; j < 8; ++j) {
				xc += board[i][j] == 'R';
				yc += board[j][i] == 'R';
			}
			if (xc != 1 || yc != 1) {
				return "Incorrect";
			}
		}
		return "Correct";
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
			string Arr0[] = {"R.......",
 ".R......",
 "..R.....",
 "...R....",
 "....R...",
 ".....R..",
 "......R.",
 ".......R"};
			string Arg1 = "Correct";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isCorrect(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"........",
 "....R...",
 "........",
 ".R......",
 "........",
 "........",
 "..R.....",
 "........"};
			string Arg1 = "Incorrect";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isCorrect(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"......R.",
 "....R...",
 "...R....",
 ".R......",
 "R.......",
 ".....R..",
 "..R.....",
 ".......R"};
			string Arg1 = "Correct";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isCorrect(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"......R.",
 "....R...",
 "...R....",
 ".R......",
 "R.......",
 ".......R",
 "..R.....",
 ".......R"};
			string Arg1 = "Incorrect";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isCorrect(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........"};
			string Arg1 = "Incorrect";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isCorrect(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EightRooks ___test;
	___test.run_test(-1);
}
// END CUT HERE
