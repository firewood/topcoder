// BEGIN CUT HERE
/*
SRM 590 Div2 Medium (500)

// PROBLEM STATEMENT
// Fox Ciel is teaching her friend Jiro to play Go.
Ciel has just placed some white and some black tokens onto a board.
She now wants Jiro to find the best possible move.
(This is defined more precisely below.)


You are given a vector <string> board.
Character j of element i of board represents the cell (i,j) of the board:
'o' is a cell with a white token, 'x' a cell with a black token, and '.' is an empty cell.
At least one cell on the board will be empty.


Jiro's move will consist of adding a single black token to the board.
The token must be placed onto an empty cell.
Once Jiro places the token, some white tokens will be removed from the board according to the rules described in the next paragraphs.


The white tokens on the board can be divided into connected components using the following rules:
If two white tokens lie in cells that share an edge, they belong to the same component.
Being in the same component is transitive: if X lies in the same component as Y and Y lies in the same component as Z, then X lies in the same component as Z.


Each component of white tokens is processed separately.
For each component of white tokens we check whether it is adjacent to an empty cell.
(That is, whether there are two cells that share an edge such that one of them is empty and the other contains a white token from the component we are processing.)
If there is such an empty cell, the component is safe and its tokens remain on the board.
If there is no such empty cell, the component is killed and all its tokens are removed from the board.


Jiro's score is the total number of white tokens removed from the board after he makes his move.
Return the maximal score he can get for the given board.


DEFINITION
Class:FoxAndGo
Method:maxKill
Parameters:vector <string>
Returns:int
Method signature:int maxKill(vector <string> board)


NOTES
-The position described by board does not have to be a valid Go position. In particular, there can already be components of white tokens that have no adjacent empty cell.
-Please ignore official Go rules. The rules described in the problem statement are slightly different. For example, in this problem the black tokens cannot be killed, and it is allowed to place the black token into any empty cell.


CONSTRAINTS
-n will be between 2 and 19, inclusive.
-board will contain exactly n elements.
-Each element in board will contain exactly n characters.
-Each character in board will be 'o', 'x' or '.'.
-There will be at least one '.' in board.


EXAMPLES

0)
{".....",
 "..x..",
 ".xox.",
 ".....",
 "....."}


Returns: 1

To kill the only white token, Jiro must place his black token into the cell (3,2). (Both indices are 0-based.)

1)
{"ooooo",
 "xxxxo",
 "xxxx.",
 "xxxx.",
 "ooooo"}


Returns: 6

By placing the token to the cell (2,4) Jiro kills 6 white tokens. The other possible move only kills 5 tokens.

2)
{".xoxo",
 "ooxox",
 "oooxx",
 "xoxox",
 "oxoox"}


Returns: 13

There is only one possible move. After Jiro makes it, all the white tokens are killed.

3)
{".......",
 ".......",
 ".......",
 "xxxx...",
 "ooox...",
 "ooox...",
 "ooox..."}


Returns: 9

Regardless of where Jiro moves, the 9 white tokens in the lower left corner will be killed.

4)
{".......",
 ".xxxxx.",
 ".xooox.",
 ".xo.ox.",
 ".xooox.",
 ".xxxxx.",
 "......."}


Returns: 8



5)
{"o.xox.o",
 "..xox..",
 "xxxoxxx",
 "ooo.ooo",
 "xxxoxxx",
 "..xox..",
 "o.xox.o"}


Returns: 12



6)
{".......",
 "..xx...",
 ".xooox.",
 ".oxxox.",
 ".oxxxo.",
 "...oo..",
 "......."}

Returns: 4



7)
{".ox....",
 "xxox...",
 "..xoox.",
 "..xoox.",
 "...xx..",
 ".......",
 "......."}
 

Returns: 5



8)
{"...................",
 "...................",
 "...o..........o....",
 "................x..",
 "...............x...",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "................o..",
 "..x................",
 "...............x...",
 "...................",
 "..................."}


Returns: 0



*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class FoxAndGo {

	int N;
	vector <string> b;

	int dfs(int x, int y) {
		const int dx[] = {-1,1,0,0};
		const int dy[] = {0,0,-1,1};
		if (x < 0 || x >= N || y < 0 || y >= N) {
			return 0;
		}
		if (b[y][x] == 'x') {
			return 0;
		}
		if (b[y][x] == '.') {
			return -1;
		}
		b[y][x] = 'x';
		int sum = 1;
		for (int i = 0; i < 4; ++i) {
			int r = dfs(x + dx[i], y + dy[i]);
			if (r < 0) {
				b[y][x] = '.';
				return -1;
			}
			sum += r;
		}
		return sum;
	}

public:
	int maxKill(vector <string> board) {
		N = (int)board.size();
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (board[i][j] == '.') {
					int sum = 0;
					b = board;
					b[i][j] = 'x';
					for (int y = 0; y < N; ++y) {
						for (int x = 0; x < N; ++x) {
							int r = dfs(x, y);
							if (r > 0) {
								sum += r;
							}
						}
					}
					ans = max(ans, sum);
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
			string Arr0[] = {".....",
 "..x..",
 ".xox.",
 ".....",
 "....."}
;
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxKill(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ooooo",
 "xxxxo",
 "xxxx.",
 "xxxx.",
 "ooooo"}
;
			int Arg1 = 6;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxKill(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".xoxo",
 "ooxox",
 "oooxx",
 "xoxox",
 "oxoox"}
;
			int Arg1 = 13;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxKill(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".......",
 ".......",
 ".......",
 "xxxx...",
 "ooox...",
 "ooox...",
 "ooox..."}
;
			int Arg1 = 9;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxKill(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".......",
 ".xxxxx.",
 ".xooox.",
 ".xo.ox.",
 ".xooox.",
 ".xxxxx.",
 "......."}
;
			int Arg1 = 8;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxKill(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"o.xox.o",
 "..xox..",
 "xxxoxxx",
 "ooo.ooo",
 "xxxoxxx",
 "..xox..",
 "o.xox.o"}
;
			int Arg1 = 12;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxKill(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".......",
 "..xx...",
 ".xooox.",
 ".oxxox.",
 ".oxxxo.",
 "...oo..",
 "......."};
			int Arg1 = 4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxKill(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".ox....",
 "xxox...",
 "..xoox.",
 "..xoox.",
 "...xx..",
 ".......",
 "......."}
 ;
			int Arg1 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxKill(Arg0));
		}
		n++;

		// test_case_8
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...................",
 "...................",
 "...o..........o....",
 "................x..",
 "...............x...",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "................o..",
 "..x................",
 "...............x...",
 "...................",
 "..................."}
;
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxKill(Arg0));
		}
		n++;


		// test_case_17
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"oo.ooo", "oooooo", ".oo.oo", "oo.ooo", ".oo.oo", "ooooo."};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxKill(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndGo ___test;
//	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
