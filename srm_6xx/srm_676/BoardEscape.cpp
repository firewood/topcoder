// BEGIN CUT HERE
/*
SRM 676 Div1 Medium (450)

PROBLEM STATEMENT

Alice and Bob have a rectangular board divided into a grid with r rows and c columns.
The grid is described by the vector <string> s.
Each character of s represents one cell.
There are four types of cells:

'E' denotes an exit. There may be arbitrarily many exits, possibly zero.
'T' means the square contains a single token. There may be arbitrarily many tokens, possibly zero.
'#' denotes an obstacle.
'.' denotes an empty cell.

Alice and Bob will play a game on this board.
The game is parameterized by the int k.
Each token initially has the number k on it.
The players will take alternating turns, starting with Alice.
A player's turn consists of the following steps:

The player chooses a single token on the board and moves it one square up, down, left, or right. The token cannot go over the edge of the board and it cannot enter a cell with an obstacle. The token may be moved into a cell that already contains other token(s). During the game, arbitrarily many tokens may share the same cell.
If this token is on an exit, it disappears from the board.
Otherwise, subtract one from the number on the token. If the number on the token is zero, remove it from the board. (The numbers on other tokens do not change.)

The first player unable to make a move loses the game.

You are given the vector <string> s and the int k
Compute the winner of the game, assuming both Alice and Bob play optimally.
Return the winner's name: either "Alice" or "Bob".


DEFINITION
Class:BoardEscape
Method:findWinner
Parameters:vector <string>, int
Returns:string
Method signature:string findWinner(vector <string> s, int k)


CONSTRAINTS
-r,c will be between 1 and 50, inclusive.
-s will contain exactly r elements, each consisting of c characters.
-Each character of each element of s will be one of 'T', 'E', '#', or '.'.
-k will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{"TE"}
2

Returns: "Alice"

Alice can move the token directly to the exit on her first move, making Bob unable to move.


1)
{"E#E",
"#T#",
"E#E"}
1000000

Returns: "Bob"

Alice is unable to make the first move in this case.


2)
{"T.T.T.",
".E.E.E"}
1

Returns: "Alice"


3)
{"TTE"}
6

Returns: "Alice"


4)
{"..........................",
"......TTT..TTT..T...T.....",
".....T.....T..T.TT.TT.....",
"......TTT..TTT..T.T.T.....",
".........T.T.T..T...T.....",
"......TTT..T..T.T...T.....",
"..........................",
"...E#E#E#E#E#E#E#E#E#E#...",
"..........................",
"......TTT..TTT...TTT......",
".....T........T.T.........",
"......TTT.....T..TTT......",
".....T...T...T..T...T.....",
"......TTT....T...TTT......",
"..........................",
"...#E#E#E#E#E#E#E#E#E#E...",
"..........................",
"....TT...T...T..T.TTT.T...",
"...T.....T...T..T.T...T...",
"...T.TT..T...TTTT.TT..T...",
"...T..T..T...T..T.T.......",
"....TT...TTT.T..T.T...T...",
".........................."}
987654321

Returns: "Bob"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class BoardEscape {
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
			string Arr0[] = { "TE" };
			int Arg1 = 2;
			string Arg2 = "Alice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "E#E",
				"#T#",
				"E#E" };
			int Arg1 = 1000000;
			string Arg2 = "Bob";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "T.T.T.",
				".E.E.E" };
			int Arg1 = 1;
			string Arg2 = "Alice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "TTE" };
			int Arg1 = 6;
			string Arg2 = "Alice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "..........................",
				"......TTT..TTT..T...T.....",
				".....T.....T..T.TT.TT.....",
				"......TTT..TTT..T.T.T.....",
				".........T.T.T..T...T.....",
				"......TTT..T..T.T...T.....",
				"..........................",
				"...E#E#E#E#E#E#E#E#E#E#...",
				"..........................",
				"......TTT..TTT...TTT......",
				".....T........T.T.........",
				"......TTT.....T..TTT......",
				".....T...T...T..T...T.....",
				"......TTT....T...TTT......",
				"..........................",
				"...#E#E#E#E#E#E#E#E#E#E...",
				"..........................",
				"....TT...T...T..T.TTT.T...",
				"...T.....T...T..T.T...T...",
				"...T.TT..T...TTTT.TT..T...",
				"...T..T..T...T..T.T.......",
				"....TT...TTT.T..T.T...T...",
				".........................." };
			int Arg1 = 987654321;
			string Arg2 = "Bob";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "T....E" };
			int Arg1 = 3;
			string Arg2 = "Alice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "T....E" };
			int Arg1 = 2;
			string Arg2 = "Bob";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;





		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "T." };
			int Arg1 = 3;
			string Arg2 = "Alice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "T." };
			int Arg1 = 2;
			string Arg2 = "Bob";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			string Arr0[] = { ".TET",".E.E" };
			int Arg1 = 2;
			string Arg2 = "Alice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;



	}

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BoardEscape ___test;
	___test.run_test(-1);
}
// END CUT HERE
