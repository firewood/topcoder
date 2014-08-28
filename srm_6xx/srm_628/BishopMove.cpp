// BEGIN CUT HERE
/*
SRM 628 Div2 Easy (250)

PROBLEM STATEMENT
Janusz is learning how to play chess.
He is using the standard chessboard with 8 rows and 8 columns.
Both the rows and the columns are numbered 0 through 7.
Thus, we can describe each cell using its two coordinates: (row, column).

Janusz recently learned about one of the chess pieces: the bishop.
The bishop is a piece that moves diagonally by an arbitrary number of cells.
Formally, if a bishop is currently on the cell (r,c) of an empty chessboard,
the set of all cells reachable in a single move contains the following cells:

All cells of the form (r+k,c+k), where k is a positive integer.
All cells of the form (r+k,c-k), where k is a positive integer.
All cells of the form (r-k,c+k), where k is a positive integer.
All cells of the form (r-k,c-k), where k is a positive integer.

(Of course, the bishop's destination must always be a valid cell on the chessboard.)

Janusz took an empty chessboard and he placed a single bishop onto the cell (r1,c1).
He now wants to move it to the cell (r2,c2) using as few moves as possible.

You are given the ints r1, c1, r2, and c2.
Compute and return the smallest number of moves a bishop needs to get from (r1,c1) to (r2,c2).
If it is impossible for a bishop to reach the target cell, return -1 instead.

DEFINITION
Class:BishopMove
Method:howManyMoves
Parameters:int, int, int, int
Returns:int
Method signature:int howManyMoves(int r1, int c1, int r2, int c2)


CONSTRAINTS
-r1,c1,r2,c2 will be between 0 and 7, inclusive.


EXAMPLES

0)
4
6
7
3

Returns: 1

The bishop can go from (4,6) to (7,3) in a single move.


1)
2
5
2
5

Returns: 0

The bishop is already where it should be, no moves are necessary.


2)
1
3
5
5

Returns: 2

In the first move Janusz can move the bishop to the cell (4,6).
Please note that this is the largest possible return value: whenever there is a solution, there is a solution that uses at most two moves.


3)
4
6
7
4

Returns: -1

If the bishop starts at (4,6), it can never reach (7,4).

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class BishopMove {

public:
	int howManyMoves(int r1, int c1, int r2, int c2) {
		int b[8][8];
		memset(b, -1, sizeof(b));
		b[r1][c1] = 0;
		for (int m = 0; m < 8; ++m) {
			for (int r = 0; r < 8; ++r) {
				for (int c = 0; c < 8; ++c) {
					if (b[r][c] == m) {
						for (int i = 1; i <= 8; ++i) {
							for (int j = 0; j < 4; ++j) {
								int dx[] = { -1, -1, 1, 1 };
								int dy[] = { -1, 1, -1, 1 };
								int x = c + dx[j] * i, y = r + dy[j] * i;
								if (x >= 0 && y >= 0 && x < 8 && y < 8 && b[y][x] < 0) {
									b[y][x] = m + 1;
								}
							}
						}
					}
				}
			}
		}
		return b[r2][c2];
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
			int Arg0 = 4;
			int Arg1 = 6;
			int Arg2 = 7;
			int Arg3 = 3;
			int Arg4 = 1;

			verify_case(n, Arg4, howManyMoves(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 5;
			int Arg2 = 2;
			int Arg3 = 5;
			int Arg4 = 0;

			verify_case(n, Arg4, howManyMoves(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 3;
			int Arg2 = 5;
			int Arg3 = 5;
			int Arg4 = 2;

			verify_case(n, Arg4, howManyMoves(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 6;
			int Arg2 = 7;
			int Arg3 = 4;
			int Arg4 = -1;

			verify_case(n, Arg4, howManyMoves(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BishopMove ___test;
	___test.run_test(-1);
}
// END CUT HERE
