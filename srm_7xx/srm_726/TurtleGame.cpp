// BEGIN CUT HERE
/*
SRM 726 Div2 Medium (500)

PROBLEM STATEMENT
Hero and Jack have a rectangular board that is divided into a grid of unit square cells.
Some of the cells may already be missing from the board.

Turtles like to walk across their board.
Each turtle will always enter the top left cell of the board and then it will walk to the bottom right cell.
During the walk the turtle moves in steps, and each step must take the turtle either one cell down or one cell to the right.
Obviously, a turtle cannot visit a cell that is already missing from the board.
The sequence of cells visited by a turtle along its walk will be called a turtle path.

We say that a board is turtle-friendly if a turtle can still complete its walk on the board.
In other words, a turtle-friendly board is a board that contains at least one turtle path.
In particular, note that a turtle-friendly board must contain both the top left cell and the bottom right cell.

Hero and Jack are now going to play a game with their board.
They will take alternating turns, with Hero being the first one to play.
In each turn, the active player has to remove one cell from the board.
The game continues as long as the board remains turtle-friendly.
The player who causes the board to stop being turtle-friendly loses the game.

You are given the vector <string> board that represents the initial state of the board:
the character '.' represents a cell that is still present, the character '#' is a cell that has already been removed.
It is guaranteed that board represents a turtle-friendly board.

Return "Win" if Hero can win the game regardless of how Jack plays.
Otherwise, return "Lose".

DEFINITION
Class:TurtleGame
Method:getwinner
Parameters:vector <string>
Returns:string
Method signature:string getwinner(vector <string> board)


CONSTRAINTS
-board will contain between 2 and 20 elements, inclusive.
-All elements in board will contain the same sumber of characters.
-Each element in board will contain between 2 and 20 characters, inclusive.
-Each character in board will be either '.' or '#'.
-It is guaranteed that there is at least one undestroyed turtle path.


EXAMPLES

0)
{"..",
 ".."}

Returns: "Win"

This board contains two different turtle paths.
Hero has two moves that don't lose him the game: he can remove either the top right or the bottom left cell.
Each of these moves will leave only one of the two turtle paths, and Jack will have no valid moves left.
Jack's move will create a board that is not turtle-friendly, which means that Hero will win the game.


1)
{"...",
 ".#.",
 ".#.",
 "..."}

Returns: "Lose"

Again there are only two turtle paths.
However, now they are longer.
Regardless of which cell Hero removes (other than the top left and the bottom right cell), his move will create three cells that can be destroyed "for free".
Since 3 is an odd number, Jack will be the one to remove the last of these three cells. In the following turn Hero will lose the game.


2)
{".##",
 "..#",
 "#.."}

Returns: "Lose"


3)
{"....",
 "...#",
 "#...",
 "...."}

Returns: "Win"


4)
{"...#.",
 "....#",
 "#....",
 "..##."}

Returns: "Win"


5)
{"..........",
 "........#."}

Returns: "Lose"

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>
#include <bitset>

using namespace std;

typedef bitset<400> Bits;

class TurtleGame {
	int h;
	int w;
	unordered_map<Bits, int> cmemo;
	unordered_map<Bits, int> memo;
	Bits corner;

	bool check(const Bits &b) {
		if (cmemo[b]) {
			return cmemo[b] - 1 != 0;
		}
		Bits c;
		c[0] = 1;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				int k = i * w + j;
				if ((i || j) && !b[k]) {
					if ((i && c[k - w]) || (j && c[k - 1])) {
						c[k] = 1;
					}
				}
			}
		}
		cmemo[b] = c[h * w - 1] + 1;
		return cmemo[b] - 1 != 0;
	}

	bool win(Bits &b) {
		if (memo[b]) {
			return memo[b] - 1 != 0;
		}
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				int k = i * w + j;
				if (!corner[k] && !b[k]) {
					b[k] = 1;
					if (check(b)) {
						if (!win(b)) {
							b[k] = 0;
							memo[b] = 2;
							return true;
						}
					}
					b[k] = 0;
				}
			}
		}
		memo[b] = 1;
		return false;
	}

public:
	string getwinner(vector <string> board) {
		h = (int)board.size();
		w = (int)board[0].length();
		cmemo.clear();
		memo.clear();
		corner = Bits();
		corner[0] = 1, corner[h * w - 1] = 1;
		Bits b;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (board[i][j] == '#') {
					b[i * w + j] = 1;
				}
			}
		}
		return win(b) ? "Win" : "Lose";
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
			string Arr0[] = {"..",
 ".."};
			string Arg1 = "Win";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getwinner(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...",
 ".#.",
 ".#.",
 "..."};
			string Arg1 = "Lose";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getwinner(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".##",
 "..#",
 "#.."};
			string Arg1 = "Lose";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getwinner(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"....",
 "...#",
 "#...",
 "...."};
			string Arg1 = "Win";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getwinner(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...#.",
 "....#",
 "#....",
 "..##."};
			string Arg1 = "Win";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getwinner(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..........",
 "........#."};
			string Arg1 = "Lose";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getwinner(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			string Arr0[] = {
				"..........#.......",
				"..........#....#..",
				"...........#...#..",
				".....#..#........#",
				".........##....#..",
				".....#............",
				".............#....",
				"...#...........#.." };
			string Arg1 = "Lose";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getwinner(Arg0));
		}
		n++;
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TurtleGame ___test;
	___test.run_test(1);
	___test.run_test(-1);
}
// END CUT HERE
