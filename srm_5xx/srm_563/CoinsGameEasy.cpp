// BEGIN CUT HERE
/*
// SRM 563 Div2 Medium (550)

// PROBLEM STATEMENT
// We are playing a game with a pair of coins on a rectangular board.
The board is divided into unit square cells.
Each cell is either empty, or it contains an obstacle.
The board is given to you as a vector <string> board.
The character '#' represents an obstacle, '.' is an empty cell, and 'o' is an empty cell with a coin.
You may assume that there are exactly two coins on the board, and that initially they lie in different cells.


Next to the board, there are 4 buttons labeled "Left", "Right", "Up", and "Down".
The game is played by pushing these buttons.
When you push a button, all coins will try to move one cell in the corresponding direction.
For each coin, there can be three different outcomes:

If the next cell in the chosen direction contains an obstacle, the coin remains in its current cell.
If there is no next cell in the chosen direction (i.e., if the coin is already on the corresponding edge of the board), the coin falls off the board.
In all other cases, the coin moves one cell in the chosen direction. Note that this includes the case when the destination cell currently contains another coin.


The goal of the game is to make exactly one coin fall off the board.
If that is impossible, or if you need to push more than 10 buttons in order to achieve the goal, return -1.
Otherwise, return the smallest number of times you need to push a button in order to achieve the goal.


DEFINITION
Class:CoinsGameEasy
Method:minimalSteps
Parameters:vector <string>
Returns:int
Method signature:int minimalSteps(vector <string> board)


NOTES
-There may be some sequences of moves that will cause both coins to end in the same cell. Note that when trying to win the game such moves should be avoided.


CONSTRAINTS
-board will contain between 1 and 20 elements, inclusive.
-Every element of board will have the same length, and this length will be between 1 and 20, inclusive.
-Each character in each element of board will be one of '#', 'o' and '.'.
-There will be exactly 2 'o' in board.


EXAMPLES

0)
{"oo"}

Returns: 1

Push the Left button. The left coin will fall, the right one will move one step left and it will still be on the board.


1)
{".#", 
 ".#", 
 ".#",
 "o#",
 "o#",
 "##"}

Returns: 4

You need to push the Up button 4 times in a row.


2)
{"..",
 "..",
 "..",
 "o#",
 "o#",
 "##"}

Returns: 3

As in Example 1, this game can be won by pushing the Up button 4 times. However, there is also a shorter solution: push Up, Right, and Right, in this order.


3)
{"###",
 ".o.",
 "###",
 ".o.",
 "###"}

Returns: -1


4)
{"###",
 ".o.",
 "#.#",
 ".o.",
 "###"}

Returns: 3


5)
{"###########",
 "........#o#",
 "###########",
 ".........o#",
 "###########"}

Returns: 10


6)
{"############",
 ".........#o#",
 "############",
 "..........o#",
 "############"}

Returns: -1

You need at least 11 steps to win the game, so you should return -1.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <deque>

using namespace std;

typedef pair<int, int> II;
typedef pair<II, II> IIII;
typedef deque<IIII> IIIIQ;

class CoinsGameEasy {

public:
	int minimalSteps(vector <string> board) {
		int w = (int)board[0].length();
		int h = (int)board.size();
		II a(-1,-1),b(-1,-1);
		int i, j;
		for (i = 0; i < h; ++i) {
			for (j = 0; j < w; ++j) {
				if (board[i][j] == 'o') {
					if (a.first<0) {
						a = II(i,j);
					} else {
						b = II(i,j);
					}
				}
			}
		}
		int ans = 0;
		IIIIQ q;
		q.push_back(IIII(a,b));
		while (++ans <= 10) {
			IIIIQ next;
			while (q.size() > 0) {
				IIII p = q.front();
				q.pop_front();
				const int dx[] = {-1,1,0,0};
				const int dy[] = {0,0,-1,1};
				int d;
				for (d = 0; d < 4; ++d) {
					II r(p.first.first+dy[d],p.first.second+dx[d]);
					II s(p.second.first+dy[d],p.second.second+dx[d]);
					bool rvalid = r.first >= 0 && r.first < h && r.second >= 0 && r.second < w;
					bool svalid = s.first >= 0 && s.first < h && s.second >= 0 && s.second < w;
					if (!rvalid && !svalid) {
						continue;
					}
					bool rwall = rvalid && board[r.first][r.second] == '#';
					bool swall = svalid && board[s.first][s.second] == '#';
					if (!rvalid && svalid || rvalid && !svalid) {
						return ans;
					}
					if (rwall) {
						r = p.first;
					}
					if (swall) {
						s = p.second;
					}
					next.push_back(IIII(r, s));
				}
			}
			q = next;
		}
		return -1;
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
			string Arr0[] = {"oo"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalSteps(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".#", 
 ".#", 
 ".#",
 "o#",
 "o#",
 "##"};
			int Arg1 = 4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalSteps(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..",
 "..",
 "..",
 "o#",
 "o#",
 "##"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalSteps(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"###",
 ".o.",
 "###",
 ".o.",
 "###"};
			int Arg1 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalSteps(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"###",
 ".o.",
 "#.#",
 ".o.",
 "###"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalSteps(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"###########",
 "........#o#",
 "###########",
 ".........o#",
 "###########"};
			int Arg1 = 10;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalSteps(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"############",
 ".........#o#",
 "############",
 "..........o#",
 "############"};
			int Arg1 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalSteps(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CoinsGameEasy ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
