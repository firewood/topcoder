// BEGIN CUT HERE
/*
SRM 623 Div1 Easy (300)

PROBLEM STATEMENT
A square board is divided into N rows by N columns of unit square cells.
Some cells of the board are empty.
Each of the other cells contains either an apple or a pear.
You are given the current state of the board as a vector <string> board.
In board, the character '.' denotes an empty cell, 'A' denotes an apple, and 'P' denotes a pear.

You are allowed to perform at most K moves.
In each move, you can pick up one fruit (an apple or a pear) and place it onto any empty cell.
(The new cell doesn't have to be adjacent to the old one.)
Note that you cannot remove fruit from the board, you are only allowed to move it onto different cells.

A rectangular section of the board is called uniform if each cell in the rectangle contains an apple. After you are done moving the fruit, you want to have a uniform rectangle that is as large as possible somewhere on the board.
Return the largest possible area of such a rectangle. If there are no apples, return 0.


DEFINITION
Class:UniformBoard
Method:getBoard
Parameters:vector <string>, int
Returns:int
Method signature:int getBoard(vector <string> board, int K)


CONSTRAINTS
-N will be between 1 and 20, inclusive.
-board will contain exactly N elements.
-Each element of board will contain exactly N characters.
-Each character in board will be '.', 'A', or 'P'.
-K will be between 0 and 1000, inclusive.


EXAMPLES

0)
{"AP",
 ".A"}
0

Returns: 1

You cannot move anything.
The largest uniform rectangle on the board is a 1x1 rectangle that consists of a single cell with an apple.


1)
{"AP",
 ".A"}
1

Returns: 2

You are allowed to make one move.
You can move one of the apples onto the currently empty cell, thus creating a 1x2 rectangle of apples.


2)
{"PPP",
 "APA",
 "A.P"}
2

Returns: 3

In two moves you can create a 1x3 rectangle of apples.


3)
{"AAA",
 "PPP",
 "AAA"}
10

Returns: 3

You are allowed to make at most 10 moves.
However, you cannot make any moves because there are no empty cells.


4)
{"."}
1000

Returns: 0


5)
{"PPAAPA..AP",
 "PPA.APAP..",
 "..P.AA.PPP",
 "P.P..APAA.",
 "P.P..P.APA",
 "PPA..AP.AA",
 "APP..AAPAA",
 "P.P.AP...P",
 ".P.A.PAPPA",
 "..PAPAP..P"}
10

Returns: 15

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class UniformBoard {

public:
	int getBoard(vector <string> board, int K) {
		int N = (int)board.size();
		int total[256] = {};
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				total[board[i][j]] += 1;
			}
		}

		int ans = 0;
		for (int sy = 0; sy < N; ++sy) {
			for (int ey = sy; ey < N; ++ey) {
				for (int sx = 0; sx < N; ++sx) {
					for (int ex = sx; ex < N; ++ex) {
						int sz = (ex - sx + 1) * (ey - sy + 1);
						if (total['A'] < sz) {
							break;
						}

						int count[256] = {};
						for (int y = sy; y <= ey; ++y) {
							for (int x = sx; x <= ex; ++x) {
								count[board[y][x]] += 1;
							}
						}
						int sum = count['.'] + count['P'] * 2;
						if (count['A'] >= sz || (total['.'] > 0 && sum <= K)) {
							ans = max(ans, sz);
						}
					}
				}
			}
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
			string Arr0[] = {"AP",
 ".A"};
			int Arg1 = 0;
			int Arg2 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getBoard(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"AP",
 ".A"};
			int Arg1 = 1;
			int Arg2 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getBoard(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"PPP",
 "APA",
 "A.P"};
			int Arg1 = 2;
			int Arg2 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getBoard(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"AAA",
 "PPP",
 "AAA"};
			int Arg1 = 10;
			int Arg2 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getBoard(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"."};
			int Arg1 = 1000;
			int Arg2 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getBoard(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"PPAAPA..AP",
 "PPA.APAP..",
 "..P.AA.PPP",
 "P.P..APAA.",
 "P.P..P.APA",
 "PPA..AP.AA",
 "APP..AAPAA",
 "P.P.AP...P",
 ".P.A.PAPPA",
 "..PAPAP..P"};
			int Arg1 = 10;
			int Arg2 = 15;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getBoard(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	UniformBoard ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
