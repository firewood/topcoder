// BEGIN CUT HERE
/*
SRM 605 Div2 Medium (500)

PROBLEM STATEMENT
Alien Fred wants to destroy the Earth.
But before he does that, he wants to play the following game.

He has a rectangular board divided into unit cells.
Each cell is initially painted black or white.
You are given a vector <string> board.
The character board[i][j] represents the cell with coordinates (i, j).
Each of those characters is either 'B' (representing a black cell) or 'W' (representing a white cell).
The game is played in turns.
In each turn Fred can choose any row of the board and repaint all black cells of the row to white, and vice versa.
(Note that he can only select rows, not columns. 
Formally, he can choose an index i and change all characters of board[i].)

Fred wants to have a large white square somewhere on his board.
The sides of Fred's square must be parallel to the sides of the board.
The white square may be a part of a larger white area. 
(I.e., the cells that touch the square may be both black and white.)
Find a sequence of turns that produces the largest possible white square somewhere on the board, and return the area of that square.


DEFINITION
Class:AlienAndGame
Method:getNumber
Parameters:vector <string>
Returns:int
Method signature:int getNumber(vector <string> board)


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will contain between 1 and 50 characters, inclusive.
-Each element of board will contain the same number of characters.
-Each character in each element of board will be either 'B' or 'W'.


EXAMPLES

0)
{"BB",
 "WW"}

Returns: 4

The optimal strategy is to repaint row 0. After this change the entire board will be white, and thus we have a 2*2 white square.


1)
{"W"}

Returns: 1

Sometimes the optimal strategy requires no repainting.


2)
{"WBBB",
 "WBBB",
 "WWWW"}

Returns: 9

We should repaint row 0 and then repaint row 1. 
The resulting board will contain a 3*3 white square (in rows 0-2 and columns 1-3).


3)
{"W",
 "B",
 "W",
 "W",
 "W"}

Returns: 1


4)
{"BWBBWBB",
 "WWBWWBW",
 "BBBBBBW",
 "WBBBBWB",
 "BBWWWWB",
 "WWWWWWW",
 "BBWWBBB"}

Returns: 9

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class AlienAndGame {
public:
	int getNumber(vector <string> board) {
		int H = (int)board.size();
		int W = (int)board[0].length();
		int cnt[64][64] = {};
		int ans = 1;
		for (int i = 0; i < H; ++i) {
			cnt[i][0] = 1;
			for (int j = 1; j < W; ++j) {
				if (board[i][j-1] == board[i][j]) {
					int k = cnt[i][j-1] + 1;
					cnt[i][j] = k;
					int l;
					for (l = 1; l <= i; ++l) {
						k = min(k, cnt[i-l][j]);
						if (k <= l) {
							break;
						}
						ans = max(ans, (l+1)*(l+1));
					}
				} else {
					cnt[i][j] = 1;
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
			string Arr0[] = {"BB",
 "WW"};
			int Arg1 = 4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"W"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"WBBB",
 "WBBB",
 "WWWW"};
			int Arg1 = 9;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"W",
 "B",
 "W",
 "W",
 "W"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"BWBBWBB",
 "WWBWWBW",
 "BBBBBBW",
 "WBBBBWB",
 "BBWWWWB",
 "WWWWWWW",
 "BBWWBBB"};
			int Arg1 = 9;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AlienAndGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
