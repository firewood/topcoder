// BEGIN CUT HERE
/*
// SRM 509 Div2 Hard (1000)

// PROBLEM STATEMENT
// Little Arthur loves numbers. This time he is playing a game called Number Labyrinth.

The game is played on an R x C board; rows are numbered 0 to R - 1 from top
to bottom and columns are numbered 0 to C - 1 from left to right. The cell
in row r and column c is said to have coordinates (r, c). Each cell of the
board either contains a single-digit number (0 to 9) or is empty. The board
is given as vector <string> board where the j-th character of the i-th element
represents the cell at row i and column j; this element is a digit character
('0' - '9') if the cell contains the respective single-digit number or '.'
if the cell is empty.

The goal of the game is to get from cell (r1, c1) to cell (r2, c2) with the
fewest number of moves. A move is a jump of length d in a horizontal or
vertical direction from a cell with a number d; more formally, if Arthur's
position is (r, c) and the cell contains a number d, he can move to cell
(r - d, c), (r + d, c), (r, c - d), or (r, c + d). Note that an empty cell
or a cell with number 0 is a dead-end. Arthur is also not allowed to leave
the board at any time.

Furthermore, before performing moves Arthur is allowed to write any
single-digit numbers in at most K empty cells.

Given board, r1, c1, r2, c2, and K, return the minimum number of moves
Arthur needs to reach the goal. Return -1 if it is impossible to reach the goal.

DEFINITION
Class:NumberLabyrinthDiv2
Method:getMinimumNumberOfMoves
Parameters:vector <string>, int, int, int, int, int
Returns:int
Method signature:int getMinimumNumberOfMoves(vector <string> board, int r1, int c1, int r2, int c2, int K)


CONSTRAINTS
-R and C will each be between 1 and 50, inclusive.
-board will contain exactly R elements.
-Each element of board will contain exactly C characters.
-Each element of board will contain only the following characters: '.', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'.
-r1 and r2 will each be between 0 and R - 1, inclusive.
-c1 and c2 will each be between 0 and C - 1, inclusive.
-(r1, c1) and (r2, c2) will represent different cells.
-K will be between 0 and 50, inclusive.


EXAMPLES

0)
{"...2",
 "....",
 "3..."}
0
0
2
3
0

Returns: -1


There is no way to reach the goal because cell (r1, c1) does not contain a number and Arthur is not allowed to write any.

1)
{"...2",
 "....",
 "3..."}
0
0
2
3
1

Returns: 2

This time the goal is reachable. Two possible ways are:

- writing number 3 in cell (0, 0) allowing him to perform moves (0, 0) -> (0, 3) -> (2, 3);

- writing number 2 in cell (0, 0) allowing him to perform moves (0 ,0) -> (2, 0) -> (2, 3).


2)
{"...3",
 "....",
 "2..."}
0
0
2
3
3

Returns: 3

This time it is impossible to reach the goal in two or less moves. However, Arthur can write new numbers in at most 3 cells, which allows him to reach the goal in 3 moves. For example, Arthur can write 2 in cell (0, 0), 2 in cell (0, 2), and 1 in cell (2, 2), enabling him to perform moves (0, 0) -> (0, 2) -> (2, 2) -> (2, 3).


3)
{"55255",
 ".0.0.",
 "..9..",
 "..3..",
 "3.9.3",
 "44.44"}
3
2
4
2
10

Returns: 6

This time the finish cell is right next to the starting cell. However, because of the configuration of the board quite a few moves have to be performed.


4)
{"920909949",
 "900020000",
 "009019039",
 "190299149",
 "999990319",
 "940229120",
 "000409399",
 "999119320",
 "009939999"}
7
3
1
1
50

Returns: 10

There are lots of dead-ends here, and a large K does not help this time as no cell is empty.

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

struct P {
	int x;
	int y;
	int z;
	P(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};
typedef vector<P> PVec;

const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};

class NumberLabyrinthDiv2 {

public:
	int getMinimumNumberOfMoves(vector <string> board, int r1, int c1, int r2, int c2, int K) {
		int W = board[0].length();
		int H = board.size();
		int dist[50][50];
		memset(dist, -1, sizeof(dist));
		PVec q;
		int a, b, d, dir, i, k, x, y, z;
		q.push_back(P(c1, r1, 0));
		for (k = 0; k <= K; ++k) {
			PVec kq;
			while (q.size() > 0) {
				PVec next;
				for (i = 0; i < (int)q.size(); ++i) {
					x = q[i].x;
					y = q[i].y;
					z = q[i].z;
					if (dist[y][x] >= 0 && dist[y][x] < z) {
						continue;
					}
					dist[y][x] = z++;
					if (board[y][x] == '.') {
						board[y][x] = '1';
						for (d = 1; d <= 9; ++d) {
							for (dir = 0; dir < 4; ++dir) {
								a = x + dx[dir] * d;
								b = y + dy[dir] * d;
								if (a >= 0 && a < W && b >= 0 && b < H) {
									kq.push_back(P(a, b, z));
								}
							}
						}
					} else {
						d = board[y][x] - '0';
						if (d <= 0) {
							continue;
						}
						for (dir = 0; dir < 4; ++dir) {
							a = x + dx[dir] * d;
							b = y + dy[dir] * d;
							if (a >= 0 && a < W && b >= 0 && b < H) {
								next.push_back(P(a, b, z));
							}
						}
					}
				}
				q = next;
			}
			q = kq;
		}

		return dist[r2][c2];
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
			string Arr0[] = {"...2",
 "....",
 "3..."};
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 2;
			int Arg4 = 3;
			int Arg5 = 0;
			int Arg6 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...2",
 "....",
 "3..."};
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 2;
			int Arg4 = 3;
			int Arg5 = 1;
			int Arg6 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...3",
 "....",
 "2..."};
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 2;
			int Arg4 = 3;
			int Arg5 = 3;
			int Arg6 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"55255",
 ".0.0.",
 "..9..",
 "..3..",
 "3.9.3",
 "44.44"};
			int Arg1 = 3;
			int Arg2 = 2;
			int Arg3 = 4;
			int Arg4 = 2;
			int Arg5 = 10;
			int Arg6 = 6;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"920909949",
 "900020000",
 "009019039",
 "190299149",
 "999990319",
 "940229120",
 "000409399",
 "999119320",
 "009939999"};
			int Arg1 = 7;
			int Arg2 = 3;
			int Arg3 = 1;
			int Arg4 = 1;
			int Arg5 = 50;
			int Arg6 = 10;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"4...0"};
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 0;
			int Arg4 = 4;
			int Arg5 = 0;
			int Arg6 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"49.18846913023488.09377.", "2943667.250.2430780.0468", "575.31.7.3.5.540.6.2.226", ".36.9083921.507357.31450", ".42.8777.168331.54.0473.", "12346856197.515420056160", "550.13.58193.39125.776..", "616.4.2962986703..6.25.6", "..04315.2.06.244421..328", "1.5533.021772.65.609.723", "9338875.5.4833.865286823", "3312.4669935592.98810896", "2.28940272666.22.5731.3.", "70199.3..57..71897149376", "93..41.02090....65852.2.", "53519..74868.58357356132", "909....3137.466.10627470", "..761.8..4.84.0619772156", "3...55.52605594221.9.242", "..93.294364.0343.4.42295", "5.141582555793.1.20.8447", "810.5.5..82.20177815.28.", "48.114.97090.3..020223.9", ".21.490.40.74.4..2..6..6", "1..41.0214480487591987.7", "..75.70.5.58.701.4.18680", "4..089978515.1662.418446", "8473.4445360.297..290852", "99640..84703049772997534", "2525399.525744480501...8", "1748.9144697278..2436.07", "50.3.7.114.31295871.1.90", "0338152661.79...3946.2.8", "9170.40176...15633112.26"
			};

			int Arg1 = 31;
			int Arg2 = 21;
			int Arg3 = 1;
			int Arg4 = 0;
			int Arg5 = 2;
			int Arg6 = 8;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NumberLabyrinthDiv2 ___test;
//	___test.run_test(1);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
