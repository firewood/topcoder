// BEGIN CUT HERE
/*
SRM 700 Div2 Medium (450)

PROBLEM STATEMENT

You are playing a treasure hunt game.
The game is played on a rectangular board that is divided into a grid of unit squares.
You are given the layout of the board in the vector <string> board.
Each character in board represents one square of the board.
The meanings of the characters in board:

'O' (capital oh): This square contains a landmark.
'.': This square is empty.
'?': You do not know the contents of this square. It may contain a landmark and it may be empty.

A treasure is buried under one of the squares.
You know something about its location:

The row in which the treasure is buried is between T and B, inclusive, where T is the topmost row that contains a landmark and B is the bottommost row that contains a landmark.

The column in which the treasure is buried is between L and R, inclusive, where L is the leftmost column that contains a landmark and R is the rightmost column that contains a landmark.

Thus, you can narrow your search space to a sub-rectangle of the original grid.

Suppose k is the number of grid squares which are unknown to you.
In other words, let k be the number of '?' characters in board.
There are 2^k different boards that correspond to the information you have.
For each of those boards, compute the number of squares that may contain the treasure.
Find and return the sum of those 2^k numbers.


DEFINITION
Class:XMarksTheSpot
Method:countArea
Parameters:vector <string>
Returns:int
Method signature:int countArea(vector <string> board)


CONSTRAINTS
-board will have between 1 and 50 elements, inclusive.
-Each element of board will be the same length.
-Each element of board will have between 1 and 50 characters, inclusive.
-Each character of each element of board will be "O", ".", or "?".
-The number of "?" characters among all elements of board is at most 19.
-There will be at least one "O" character among all elements of board.


EXAMPLES

0)
{
"?.",
".O"
}

Returns: 5

If the top left corner is empty, we only have 1 possible location of the treasure: the bottom right corner.
If the top left corner is a landmark, the treasure can be anywhere in the grid: 4 possible locations.
The return value is therefore 1 + 4 = 5.


1)
{
"???",
"?O?",
"???"
}

Returns: 1952


2)
{
"...?.",
"?....",
".O...",
"..?..",
"....?"
}

Returns: 221


3)
{"OOOOOOOOOOOOOOOOOOOOO"}

Returns: 21


4)
{"?????????OO??????????"}

Returns: 9963008


5)
{
"OOO",
"O?O",
"OOO",
"..."
}

Returns: 18

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> IIVec;

class XMarksTheSpot {
public:
	int countArea(vector <string> board) {
		IIVec v;
		int H = (int)board.size(), W = (int)board[0].length();
		int L = W, R = -1, T = H, B = -1;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				switch (board[i][j]) {
				case 'O':
					T = min(T, i);
					B = max(B, i);
					L = min(L, j);
					R = max(R, j);
					break;
				case '?':
					v.push_back(II(i, j));
					break;
				}
			}
		}
		int ans = 0;
		int m = 1 << v.size();
		for (int i = 0; i < m; ++i) {
			int t = T, b = B, l = L, r = R;
			for (int j = 0; j != v.size(); ++j) {
				if (i & (1 << j)) {
					t = min(t, v[j].first);
					b = max(b, v[j].first);
					l = min(l, v[j].second);
					r = max(r, v[j].second);
				}
			}
			ans += (b - t + 1) * (r - l + 1);
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
			string Arr0[] = {
"?.",
".O"
};
			int Arg1 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countArea(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"???",
"?O?",
"???"
};
			int Arg1 = 1952;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countArea(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"...?.",
"?....",
".O...",
"..?..",
"....?"
};
			int Arg1 = 221;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countArea(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"OOOOOOOOOOOOOOOOOOOOO"};
			int Arg1 = 21;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countArea(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"?????????OO??????????"};
			int Arg1 = 9963008;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countArea(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"OOO",
"O?O",
"OOO",
"..."
};
			int Arg1 = 18;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countArea(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	XMarksTheSpot ___test;
	___test.run_test(-1);
}
// END CUT HERE
