// BEGIN CUT HERE
/*
TCO13 Round 1B Medium (500)

PROBLEM STATEMENT
Elly has placed several (possibly none) figurines on a rectangular board
with several rows and columns. Now Kristina wants to remove all figurines from the board.
In a single move she selects either up to R consecutive rows, or
up to C consecutive columns and removes all remaining figurines that are located there.
The girl wonders what is the minimal number of moves in which she can clear the entire board.

The position of the figurines will be given to you in the vector <string> board.
The j-th character of the i-th element of board will be '.' if the cell is empty,
or 'X' if it contains a figurine.
The maximal number of cleared rows in a single move will be given in the int R.
The maximal number of cleared columns in a single move will be given in the int C.
Return the minimal number of moves that is sufficient to clear the entire board.


DEFINITION
Class:EllysFigurines
Method:getMoves
Parameters:vector <string>, int, int
Returns:int
Method signature:int getMoves(vector <string> board, int R, int C)


NOTES
-In a single move the girl can only select a consecutive group of rows or columns to be cleared. In other words, in each move Kristina first decides whether she wants rows or columns, then she picks the index i of the first chosen row/column, then the number k of chosen rows/columns, and finally she removes all figurines from the rows/columns with indices i, i+1, i+2, ..., i+k-1.


CONSTRAINTS
-board will contain between 1 and 15 elements, inclusive.
-Each element of board will contain between 1 and 15 characters, inclusive.
-All elements of board will contain the same number of characters.
-Each character of board will be either '.' or 'X'.
-R will be between 1 and 15, inclusive.
-C will be between 1 and 15, inclusive.


EXAMPLES

0)
{".X.X.",
 "XX..X",
 ".XXX.",
 "...X.",
 ".X.XX"}
1
2

Returns: 3

In this case in a single move Elly can remove all figurines from a single row, all figurines from a single column or all figurines from two consecutive columns.
One way to achieve the optimal answer here would be to remove the figurines from the first and second column in the first move, then the ones from the fourth and fifth column in the second move, and finally the remaining ones on the third row in the third move.
Another solution would be to erase only columns, again using three moves.


1)
{".X.X.",
 "XX..X",
 ".X.X.",
 "...X.",
 ".X.XX"}
2
2

Returns: 2

Almost the same as the first example, but without the figurine in the middle and the number of maximal rows removed is increased by one.
This time, the only optimal solution is to clear the first two columns in one move and the last two in another move.


2)
{"XXXXXXX"}
2
3

Returns: 1

The maximal allowed number of cleared rows or columns might be greater than the corresponding dimension of the board. The optimal solution for this board is to clear the only row in one move.


3)
{"XXXXX",
 "X....",
 "XXX..",
 "X....",
 "XXXXX"}
1
1

Returns: 4

Here clearing rows 1, 3 and 5, together with column 1 yields the best result 4.


4)
{"XXX..XXX..XXX.",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X...XXX..XXX.",
 "..............",
 "...XX...XXX...",
 "....X......X..",
 "....X....XXX..",
 "....X......X..",
 "...XXX..XXX..."}
1
2

Returns: 7

Good luck in TCO 13!

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class EllysFigurines {
public:
	int getMoves(vector <string> board, int R, int C) {
		int ans = 2000000000;
		int i, j;
		int H = (int)board.size();
		int W = (int)board[0].length();

		int d[16] = {};
		for (i = 0; i < H; ++i) {
			for (j = 0; j < W; ++j) {
				if (board[i][j] != '.') {
					d[i] |= (1<<j);
				}
			}
		}

		int m = 1 << W;
		for (int b = 0; b < m; ++b) {
			int cnt = 0;
			for (i = 0; i < W; ++i) {
				if ((1<<i) & b) {
					++cnt;
					i += C - 1;
				}
			}
			for (i = 0; i < H; ++i) {
				if (d[i] & ~b) {
					++cnt;
					i += R - 1;
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
			string Arr0[] = {".X.X.",
 "XX..X",
 ".XXX.",
 "...X.",
 ".X.XX"};
			int Arg1 = 1;
			int Arg2 = 2;
			int Arg3 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, getMoves(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".X.X.",
 "XX..X",
 ".X.X.",
 "...X.",
 ".X.XX"};
			int Arg1 = 2;
			int Arg2 = 2;
			int Arg3 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, getMoves(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"XXXXXXX"};
			int Arg1 = 2;
			int Arg2 = 3;
			int Arg3 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, getMoves(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"XXXXX",
 "X....",
 "XXX..",
 "X....",
 "XXXXX"};
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, getMoves(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"XXX..XXX..XXX.",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X...XXX..XXX.",
 "..............",
 "...XX...XXX...",
 "....X......X..",
 "....X....XXX..",
 "....X......X..",
 "...XXX..XXX..."};
			int Arg1 = 1;
			int Arg2 = 2;
			int Arg3 = 7;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, getMoves(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysFigurines ___test;
	___test.run_test(-1);
}
// END CUT HERE
