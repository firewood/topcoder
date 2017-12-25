// BEGIN CUT HERE
/*
SRM 725 Div2 Easy (250)

PROBLEM STATEMENT

You have an 8x8 chessboard.
Each cell is either empty or contains a single rook.
You are given a description of the chessboard in the vector <string> board.
Empty cells are represented by '.' (period), rooks are represented by 'R'.

You would like to know the maximum number of rooks that appear in the same row or in the same column.
Return this count.


DEFINITION
Class:FiveRooksDiv2
Method:findMax
Parameters:vector <string>
Returns:int
Method signature:int findMax(vector <string> board)


CONSTRAINTS
-board will have exactly 8 elements.
-Each element of board will have exactly 8 characters.
-Each character of board will be '.' or 'R'.


EXAMPLES

0)
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

Returns: 8


1)
{
"R......R",
".R....R.",
"..R..R..",
"...RR...",
"...RR...",
"..R..R..",
".R....R.",
"R......R"
}


Returns: 2


2)
{
"R.R.R.RR",
"........",
"R.R.R.RR",
"........",
"........",
"........",
"R.R.R.RR",
"........"
}

Returns: 5


3)
{
"R.R.R.RR",
"........",
"R.R.R.RR",
"R.R.R.RR",
"R.R.R.RR",
"R.R.R.RR",
"R.R.R.RR",
"........"
}

Returns: 6


4)
{
"........",
"........",
"........",
"........",
"........",
"........",
"........",
"........"
}

Returns: 0


*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class FiveRooksDiv2 {
public:
	int findMax(vector <string> board) {
		int ans = 0;
		int h = (int)board.size(), w = (int)board[0].length();
		for (int i = 0; i < h; ++i) {
			ans = max(ans, (int)count(board[i].begin(), board[i].end(), 'R'));
		}
		for (int j = 0; j < w; ++j) {
			int cnt = 0;
			for (int i = 0; i < h; ++i) {
				cnt += board[i][j] == 'R';
			}
			ans = max(ans, cnt);
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
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR"
};
			int Arg1 = 8;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findMax(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"R......R",
".R....R.",
"..R..R..",
"...RR...",
"...RR...",
"..R..R..",
".R....R.",
"R......R"
}
;
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findMax(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"R.R.R.RR",
"........",
"R.R.R.RR",
"........",
"........",
"........",
"R.R.R.RR",
"........"
}

;
			int Arg1 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findMax(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"R.R.R.RR",
"........",
"R.R.R.RR",
"R.R.R.RR",
"R.R.R.RR",
"R.R.R.RR",
"R.R.R.RR",
"........"
};
			int Arg1 = 6;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findMax(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"........",
"........",
"........",
"........",
"........",
"........",
"........",
"........"
}
;
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findMax(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FiveRooksDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
