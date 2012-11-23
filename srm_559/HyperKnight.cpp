// BEGIN CUT HERE
/*
// SRM 559 Div1 Easy (250)

// PROBLEM STATEMENT
// Fernando loves to play chess. One day he decided to play chess on an unusually large rectangular board. To compensate for the board's size he also decided to change the distance a knight can move in a single jump.

To describe the moves easily, we will now introduce a coordinate system. Each cell of the chessboard can be described using two integers (r,c): its row number and its column number. Now, if we have a piece at (r,c), the move (x,y) takes the piece to the cell (r+x,c+y).

The new chess piece will be called an (a,b)-hyperknight. The hyperknight always has 8 possible moves: (+a,+b), (+a,-b), (-a,+b), (-a,-b), (+b,+a), (+b,-a), (-b,+a), and (-b,-a). Note that the original chess knight is a (2,1)-hyperknight.

Of course, as the chessboard is finite, it is not always possible to make each of the 8 moves. Some of them may cause our hyperknight to leave the chessboard. A move is called valid if the destination cell is on the chessboard. Fernando would like to know the number of cells on his board such that his hyperknight will have exactly k valid moves from that cell.

You are given the ints a, b, numRows, numColumns and k. The values numRows and numColumns define the number of rows and number of columns on the chessboard, respectively. The other three values were already explained above. Compute and return the number of cells on the chessboard that have exactly k valid (a,b)-hyperknight moves.

DEFINITION
Class:HyperKnight
Method:countCells
Parameters:int, int, int, int, int
Returns:long long
Method signature:long long countCells(int a, int b, int numRows, int numColumns, int k)


NOTES
-If you wish, you may assume that the rows are numbered 0 through numRows-1 and columns 0 through numColumns-1. However, note that the actual row/column numbers do not matter, as long as they are consecutive.


CONSTRAINTS
-a will be between 1 and 1,000,000,000 (10^9), inclusive.
-b will be between 1 and 1,000,000,000 (10^9), inclusive.
-a will not be equal to b.
-numRows will be between 1 and 1,000,000,000 (10^9), inclusive.
-numColumns will be between 1 and 1,000,000,000 (10^9), inclusive.
-2*max(a,b) will be strictly less than min(numRows,numColumns).
-k will be between 0 and 8, inclusive.


EXAMPLES

0)
2
1
8
8
4

Returns: 20

This is a standard chessboard. We have a traditional chess knight and we are looking for cells such that the knight has exactly 4 valid moves.


1)
3
2
8
8
2

Returns: 16


2)
1
3
7
11
0

Returns: 0


3)
3
2
10
20
8

Returns: 56


4)
1
4
100
10
6

Returns: 564


5)
2
3
1000000000
1000000000
8

Returns: 999999988000000036

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class HyperKnight {

public:
	long long countCells(int a, int b, int numRows, int numColumns, int k) {
		LL res = 0;
		LL A = min(a, b);
		LL B = max(a, b);
		LL H = numRows;
		LL W = numColumns;
		LL dx[] = {A,A,-A,-A,B,B,-B,-B};
		LL dy[] = {B,-B,B,-B,A,-A,A,-A};
		LL bh[] = {0,A,B,H-B,H-A,H};
		LL bw[] = {0,A,B,W-B,W-A,W};
		int i, j, l, c;
		for (i = 0; i < 5; ++i) {
			for (j = 0; j < 5; ++j) {
				c = 0;
				for (l = 0; l < 8; ++l) {
					LL x = bw[j] + dx[l];
					LL y = bh[i] + dy[l];
					if (x >= 0 && x < W && y >= 0 && y < H) {
						++c;
					}
				}
				if (c == k) {
					res += (bh[i+1] - bh[i]) * (bw[j+1] - bw[j]);
				}
			}
		}
		return res;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;
			int Arg2 = 8;
			int Arg3 = 8;
			int Arg4 = 4;
			long long Arg5 = 20LL;

			verify_case(n, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			int Arg2 = 8;
			int Arg3 = 8;
			int Arg4 = 2;
			long long Arg5 = 16LL;

			verify_case(n, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 3;
			int Arg2 = 7;
			int Arg3 = 11;
			int Arg4 = 0;
			long long Arg5 = 0LL;

			verify_case(n, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			int Arg2 = 10;
			int Arg3 = 20;
			int Arg4 = 8;
			long long Arg5 = 56LL;

			verify_case(n, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 4;
			int Arg2 = 100;
			int Arg3 = 10;
			int Arg4 = 6;
			long long Arg5 = 564LL;

			verify_case(n, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 3;
			int Arg2 = 1000000000;
			int Arg3 = 1000000000;
			int Arg4 = 8;
			long long Arg5 = 999999988000000036LL;

			verify_case(n, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	HyperKnight ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
