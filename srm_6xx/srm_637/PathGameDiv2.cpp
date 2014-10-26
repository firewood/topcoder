// BEGIN CUT HERE
/*
SRM 637 Div2 Medium (500)

PROBLEM STATEMENT
Cat Snuke is playing the Path Game.

The Path Game is played on a rectangular grid of square cells.
The grid has 2 rows and some positive number of columns.
Each cell is either black or white.

A left-to-right path in the grid is a sequence of white cells such that the first cell in the sequence is in the leftmost column, the last cell in the sequence is in the rightmost column, and each pair of consecutive cells shares a common side.

The initial coloring of the grid is such that there is at least one left-to-right path.
You are given this initial coloring as a vector <string> board with two elements.
For each i and j, board[i][j] is either '#' (representing a black cell) or '.' (representing a white cell).

Snuke may color some of the white cells black.
After he does so, there must still be at least one left-to-right path left on the board.
The goal of the game is to color as many cells black as possible.
Compute and return the largest number of cells Snuke can color black.
(Note that the cells that are already black do not count.)


DEFINITION
Class:PathGameDiv2
Method:calc
Parameters:vector <string>
Returns:int
Method signature:int calc(vector <string> board)


CONSTRAINTS
-board will contain 2 elements.
-Each element in board will contain between 1 and 50 characters, inclusive.
-All elements in board will have the same length.
-Each character in board will be '#' or '.'.
-The grid described by board will contain a left-to-right path.


EXAMPLES

0)
{"#...."
,"...#."}

Returns: 2

Snuke can color at most two white cells black.
One possible final state of the board looks as follows:

#....
..###


1)
{"#"
,"."}

Returns: 0

Snuke can't color any cells.


2)
{"."
,"."}

Returns: 1


3)
{"....#.##.....#..........."
,"..#......#.......#..#...."}

Returns: 13

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class PathGameDiv2 {
public:
	int calc(vector <string> board) {
		int ans = 0;
		int N = (int)board[0].size();
		board[0] += "..";
		board[1] += "..";
		for (int pos = 1; pos < N; ++pos) {
			if (board[0][pos] == '.' && board[1][pos] == '.') {
				if (board[0][pos-1] != '.' && board[1][pos + 1] == '.') {
					++ans;
					board[0][pos] = '#';
				}
				if (board[1][pos-1] != '.' && board[0][pos + 1] == '.') {
					++ans;
					board[1][pos] = '#';
				}
			}
		}

		int a = board[0].find('#');
		int b = board[1].find('#');
		int c = min((a >= 0 ? a : N), (b >= 0 ? b : N));
		ans += c;

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
			string Arr0[] = {"#...."
,"...#."};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, calc(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#"
,"."};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, calc(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"."
,"."};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, calc(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"....#.##.....#..........."
,"..#......#.......#..#...."};
			int Arg1 = 13;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, calc(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PathGameDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
