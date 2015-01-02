// BEGIN CUT HERE
/*
SRM 637 Div1 Medium (500)

PROBLEM STATEMENT
Cat Snuke and wolf Sothe are playing the Path Game.

The Path Game is played on a rectangular grid of square cells.
The grid has 2 rows and some positive number of columns.
Each cell is either black or white.

A left-to-right path in the grid is a sequence of white cells such that the first cell in the sequence is in the leftmost column, the last cell in the sequence is in the rightmost column, and each pair of consecutive cells shares a common side.

The initial coloring of the grid is such that there is at least one left-to-right path.
You are given this initial coloring as a vector <string> board with two elements.
For each i and j, board[i][j] is either '#' (representing a black cell) or '.' (representing a white cell).

The players take alternating turns.
In each turn, the current player has to choose and color one white cell black.
Snuke goes first.
The game ends when there is no longer a left-to-right path on the board.
The last player who colored a cell loses the game.
In other words, the loser is the player who was forced to block the last left-to-right path.

Assume that both players play the game optimally.
Return "Snuke" (quotes for clarity) if Snuke wins the game, and "Sothe" otherwise.


DEFINITION
Class:PathGame
Method:judge
Parameters:vector <string>
Returns:string
Method signature:string judge(vector <string> board)


CONSTRAINTS
-board will contain 2 elements.
-Each element in board will contain between 1 and 1000 characters, inclusive.
-All elements in board will have the same length.
-Each character in board will be '#' or '.'.
-The grid described by board will contain a left-to-right path.


EXAMPLES

0)
{"#.."
,"..."}

Returns: "Snuke"

Snuke has exactly one winning move: he must color the lower right cell.
After this move the resulting grid will still contain a left-to-right path.
Sothe will then have four possible moves, but each of those loses the game immediately.


1)
{"#"
,"."}

Returns: "Sothe"

Snuke has to color the only white cell black, and he immediately loses the game.


2)
{"....."
,"..#.."}

Returns: "Sothe"


3)
{".#..."
,"....."}

Returns: "Snuke"


4)
{".....#..#........##......."
,"..........#..........#...."}

Returns: "Snuke"

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

typedef set<int> IntSet;

class PathGame {

	int W;
	int b[1002];
	int memo[3][1000][3];

	int get_grundy_number(int L, int N, int R) {
		if (N <= 1) {
			return N >= 1 && (L | R) < 3;
		}
		int &ret = memo[L][N][R];
		if (ret >= 0) {
			return ret;
		}

		IntSet s;
		for (int i = 0; i < N; ++i) {
			if (i == 0) {
				if ((L & 2) == 0) {
					s.insert(get_grundy_number(1, N-1, R));
				}
				if ((L & 1) == 0) {
					s.insert(get_grundy_number(2, N-1, R));
				}
			} else if (i == N-1) {
				if ((R & 2) == 0) {
					s.insert(get_grundy_number(L, N-1, 1));
				}
				if ((R & 1) == 0) {
					s.insert(get_grundy_number(L, N-1, 2));
				}
			} else {
				s.insert(get_grundy_number(L, i, 1) ^ get_grundy_number(1, N-i-1, R));
				s.insert(get_grundy_number(L, i, 2) ^ get_grundy_number(2, N-i-1, R));
			}
		}
		for (ret = 0; s.count(ret) > 0; ++ret) {
			;
		}
		return ret;
	}

	bool solve(void) {
		int g = 0;
		int pos = 1;
		while (pos <= W) {
			while (pos <= W && b[pos] != 0) {
				++pos;
			}
			int s = pos;
			while (pos <= W && b[pos] == 0) {
				++pos;
			}
			g ^= get_grundy_number(b[s - 1], pos - s, b[pos]);
		}
		return g != 0;
	}

public:
	string judge(vector <string> board) {
		W = (int)board[0].length();
		memset(b, 0, sizeof(b));
		memset(memo, -1, sizeof(memo));
		for (int i = 0; i < W; ++i) {
			b[i + 1] = (board[0][i] == '#') + (board[1][i] == '#') * 2;
		}
		return solve() ? "Snuke" : "Sothe";
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
			string Arr0[] = {"#.."
,"..."};
			string Arg1 = "Snuke";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, judge(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#"
,"."};
			string Arg1 = "Sothe";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, judge(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"....."
,"..#.."};
			string Arg1 = "Sothe";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, judge(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".#..."
,"....."};
			string Arg1 = "Snuke";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, judge(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".....#..#........##......."
,"..........#..........#...."};
			string Arg1 = "Snuke";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, judge(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "..", ".." };
			string Arg1 = "Sothe";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, judge(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "..#", "#.." };
			string Arg1 = "Sothe";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, judge(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PathGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
