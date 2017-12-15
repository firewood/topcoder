// BEGIN CUT HERE
/*
SRM 725 Div1 Easy (250)

PROBLEM STATEMENT

You have an 8x8 chessboard.
Each cell is either empty or contains a single rook.
You are given a description of the chessboard in the vector <string> board.
Empty cells are represented by '.' (period), rooks are represented by 'R'.
The character board[r][c] describes the cell in row r, column c.
(Hence, both rows and columns are numbered from 0 to 7.)

There are many rooks. More precisely, it is guaranteed that the board has strictly more rooks than empty squares.

Your task is to choose exactly five rooks.
The five chosen rooks will remain on the chessboard, all other rooks will be removed.
The five rooks must be chosen in such a way that on the resulting chessboard no two of them will attack each other.
In other words, the five chosen rooks must be in five distinct rows and at the same time they must be in five distinct columns.
It is guaranteed that for the given constraints such a set of five rooks always exists.

Return a vector <int> with exactly 10 elements.
The first two elements denote the row and column of the first rook, the third and fourth element describe the second rook, and so on.
If there are multiple solutions, you may return any one of them.


DEFINITION
Class:FiveRooks
Method:find
Parameters:vector <string>
Returns:vector <int>
Method signature:vector <int> find(vector <string> board)


CONSTRAINTS
-board will have exactly 8 elements.
-Each element of board will have exactly 8 characters.
-Each character of board will be '.' or 'R'.
-There are strictly more 'R' characters than '.' characters within all elements of board.


EXAMPLES

0)
{
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"R.......",
"........",
"........",
"........"
}

Returns: {0, 7, 1, 3, 2, 4, 3, 6, 4, 0 }

The return value corresponds to the following chosen rooks:

{
"RRRRRRR*",
"RRR*RRRR",
"RRRR*RRR",
"RRRRRR*R",
"*.......",
"........",
"........",
"........"
}


1)
{
"R.R.R.R.",
".R.R.R.R",
"R.R.R.R.",
".R.RRR.R",
"R.R.R.R.",
".R.R.R.R",
"R.R.R.R.",
".R.R.R.R"
}

Returns: {0, 0, 1, 7, 2, 6, 3, 5, 4, 4 }


2)
{
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR"
}

Returns: {0, 7, 1, 3, 2, 4, 3, 6, 4, 0 }


3)
{
".RRRRRR.",
"RRRRRRRR",
"....RRRR",
"...RRRR.",
"..RRRR..",
".RRRR...",
"RRRR....",
"RRR....."
}


Returns: {1, 7, 2, 6, 3, 5, 4, 4, 5, 3 }


4)
{
".RRRRRR.",
"RRRRRRRR",
"....RRRR",
"...RRRR.",
"..RRRR..",
".RRRR...",
"RRRRRRRR",
".RRRRRR."
}

Returns: {1, 7, 2, 6, 3, 5, 4, 4, 5, 3 }


5)

{
".RRRRRR.",
"RRRRRRRR",
".RRRR...",
"..RRRR..",
"...RRRR.",
"....RRRR",
"RRRRRRRR",
".RRRRRR."
}

Returns: {1, 7, 3, 5, 4, 4, 6, 2, 7, 1 }

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

class FiveRooks {
public:
	vector <int> find(vector <string> board) {
		int si = 0;
		int seq[8] = {};
		for (int i = 0; i < 8; ++i) {
			bool f = false;
			for (int j = 0; j < 8; ++j) {
				if (board[i][j] != '.') {
					f = true;
				}
			}
			if (f) {
				seq[si++] = i;
			}
		}
		vector <int> ans;
		do {
			int u[8] = {};
			int rows = 0;
			int i;
			for (i = 0; i < 5; ++i) {
				int row = seq[i];
				bool ok = false;
				for (int j = 0; j < 8; ++j) {
					if (!u[j] && board[row][j] != '.') {
						++rows;
						u[j] = i + 1;
						break;
					}
				}
			}
			if (rows >= 5) {
				for (int i = 0; i < 5; ++i) {
					ans.push_back(seq[i]);
					for (int j = 0; j < 8; ++j) {
						if (u[j] == (i + 1)) {
							ans.push_back(j);
							break;
						}
					}
				}
			}
		} while (ans.empty() && next_permutation(seq, seq + si));
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"R.......",
"........",
"........",
"........"
};
			int Arr1[] = {0, 7, 1, 3, 2, 4, 3, 6, 4, 0 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"R.R.R.R.",
".R.R.R.R",
"R.R.R.R.",
".R.RRR.R",
"R.R.R.R.",
".R.R.R.R",
"R.R.R.R.",
".R.R.R.R"
};
			int Arr1[] = {0, 0, 1, 7, 2, 6, 3, 5, 4, 4 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR"
};
			int Arr1[] = {0, 7, 1, 3, 2, 4, 3, 6, 4, 0 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
".RRRRRR.",
"RRRRRRRR",
"....RRRR",
"...RRRR.",
"..RRRR..",
".RRRR...",
"RRRR....",
"RRR....."
}
;
			int Arr1[] = {1, 7, 2, 6, 3, 5, 4, 4, 5, 3 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
".RRRRRR.",
"RRRRRRRR",
"....RRRR",
"...RRRR.",
"..RRRR..",
".RRRR...",
"RRRRRRRR",
".RRRRRR."
};
			int Arr1[] = {1, 7, 2, 6, 3, 5, 4, 4, 5, 3 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = 
{
".RRRRRR.",
"RRRRRRRR",
".RRRR...",
"..RRRR..",
"...RRRR.",
"....RRRR",
"RRRRRRRR",
".RRRRRR."
};
			int Arr1[] = {1, 7, 3, 5, 4, 4, 6, 2, 7, 1 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;





		if ((Case == -1) || (Case == n)) {
			string Arr0[] = {
				"R......R",
				".R......",
				"..R.....",
				"...R....",
				"R.......",
				"........",
				"........",
				"........"
			};
			int Arr1[] = { 0, 7, 1, 3, 2, 4, 3, 6, 4, 0 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FiveRooks ___test;
	___test.run_test(-1);
}
// END CUT HERE
