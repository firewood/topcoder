// BEGIN CUT HERE
/*
SRM 676 Div2 Medium (550)

PROBLEM STATEMENT

Alice and Bob have a rectangular board divided into a grid with r rows and c columns.
The grid is described by the vector <string> s.
Each character of s represents one cell.
There are four types of cells:

'E' denotes an exit. There may be arbitrarily many exits, possibly zero.
'T' means the square contains a single token. Initially there will be exactly one token on the entire board.
'#' denotes an obstacle.
'.' denotes an empty cell.

Alice and Bob will play a game on this board.
The game is parameterized by the int k.
The token initially has the number k on it.
The players will take alternating turns, starting with Alice.
A player's turn consists of the following steps:

The player moves the token one square up, down, left, or right. The token cannot go over the edge of the board and it cannot enter a cell with an obstacle.
If this token is on an exit, it disappears from the board.
Otherwise, subtract one from the number on the token. If the number on the token is zero, remove it from the board.

The first player unable to make a move loses the game.
(This happens when the token is stuck and also when it already left the board.)

You are given the vector <string> s and the int k
Compute the winner of the game, assuming both Alice and Bob play optimally.
Return the winner's name: either "Alice" or "Bob".
Note that the return value is case-sensitive.


DEFINITION
Class:BoardEscapeDiv2
Method:findWinner
Parameters:vector <string>, int
Returns:string
Method signature:string findWinner(vector <string> s, int k)


CONSTRAINTS
-r,c will be between 1 and 50, inclusive.
-s will contain exactly r elements, each consisting of c characters.
-Each character of each element of s will be one of 'T', 'E', '#', or '.'.
-There will be exactly 1 'T' charcters within all elements of s.
-k will be between 1 and 100, inclusive.


EXAMPLES

0)
{"T.#",
 "#.E"}
3

Returns: "Alice"

The token starts in row 0, column 0.
At the beginning of the game the number on the token is 3.
In her first move Alice must push the token to the right and decrease the number to 2.
Bob can then move the token either left (back where it started) or down.
Either way, after Bob's move the number on the token will be 1.
Regardless of which option Bob chose, Alice can always make the token disappear in her second move:
either she reaches the exit, or the token disappears on its own after its counter reaches zero.
Afterwards Bob cannot make his second move and therefore Alice wins the game.

1)
{"E#E",
 "#T#",
 "E#E"}
99

Returns: "Bob"

As the token is stuck between obstacles, Alice has no valid move to make and therefore she immediately loses the game.


2)
{"#E...",
 "#...E",
 "E.T#.",
 "..#.."}
13

Returns: "Alice"



3)
{"TE"}
50

Returns: "Alice"



4)
{".T."}
1

Returns: "Alice"



5)
{"..........................",
 "......EEE..EEE..E...E.....",
 ".....E.....E..E.EE.EE.....",
 "......EEE..EEE..E.E.E.....",
 ".........E.E.E..E...E.....",
 "......EEE..E..E.E...E.....",
 "..........................",
 "...E#E#E#E#E#E#E#E#E#E#...",
 "..........................",
 "......EEE..EEE...EEE......",
 ".....E........E.E.........",
 "......EEE.....E..EEE......",
 ".....E...E...E..E...E.....",
 "......EEE....E...EEE......",
 "..........................",
 "...#E#E#E#E#E#E#E#E#E#E...",
 "..........................",
 "....EE...E...E..E.EEE.E...",
 "...E.....E...E..E.E...E...",
 "...E.EE..E...EEEE.EE..E...",
 "...E..E..E...E..E.E.......",
 "....EE...EEE.E..E.E...E...",
 "T........................."}
100

Returns: "Bob"



*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class BoardEscapeDiv2 {
	int W;
	int H;
	vector <string> b;
	int memo[64][64][8];

	int check(int x, int y, int k) {
		if (b[y][x] == 'E' || k <= 0) {
			return 0;
		}
		int &r = memo[y][x][k];
		if (r >= 0) {
			return r;
		}
		int g[8] = {};
		const int dx[] = { -1, 1, 0, 0 };
		const int dy[] = { 0, 0, -1, 1 };
		for (int d = 0; d < 4; ++d) {
			int xx = x + dx[d], yy = y + dy[d];
			if (xx >= 0 && xx < W && yy >= 0 && yy < H) {
				if (b[yy][xx] != '#') {
					g[check(xx, yy, k - 1)] = 1;
				}
			}
		}
		for (int i = 0; i < 8; ++i) {
			if (!g[i]) {
				r = i;
				break;
			}
		}
		return r;
	}

public:
	string findWinner(vector <string> s, int k) {
		if (k >= 4) {
			k = 4 + k % 4;
		}
		W = s[0].length();
		H = s.size();
		b = s;
		memset(memo, -1, sizeof(memo));
		int win = 0;
		for (int y = 0; y != s.size(); ++y) {
			for (int x = 0; x != s[0].length(); ++x) {
				if (s[y][x] == 'T') {
					win ^= check(x, y, k);
				}
			}
		}
		return win ? "Alice" : "Bob";
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
			string Arr0[] = {"T.#",
 "#.E"};
			int Arg1 = 3;
			string Arg2 = "Alice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"E#E",
 "#T#",
 "E#E"};
			int Arg1 = 99;
			string Arg2 = "Bob";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#E...",
 "#...E",
 "E.T#.",
 "..#.."};
			int Arg1 = 13;
			string Arg2 = "Alice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"TE"};
			int Arg1 = 50;
			string Arg2 = "Alice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".T."};
			int Arg1 = 1;
			string Arg2 = "Alice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..........................",
 "......EEE..EEE..E...E.....",
 ".....E.....E..E.EE.EE.....",
 "......EEE..EEE..E.E.E.....",
 ".........E.E.E..E...E.....",
 "......EEE..E..E.E...E.....",
 "..........................",
 "...E#E#E#E#E#E#E#E#E#E#...",
 "..........................",
 "......EEE..EEE...EEE......",
 ".....E........E.E.........",
 "......EEE.....E..EEE......",
 ".....E...E...E..E...E.....",
 "......EEE....E...EEE......",
 "..........................",
 "...#E#E#E#E#E#E#E#E#E#E...",
 "..........................",
 "....EE...E...E..E.EEE.E...",
 "...E.....E...E..E.E...E...",
 "...E.EE..E...EEEE.EE..E...",
 "...E..E..E...E..E.E.......",
 "....EE...EEE.E..E.E...E...",
 "T........................."};
			int Arg1 = 100;
			string Arg2 = "Bob";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BoardEscapeDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
