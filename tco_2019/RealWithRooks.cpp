// BEGIN CUT HERE
/*
TCO 2019 Japan Regional Easy (300)

PROBLEM STATEMENT

You have an empty R x C chessboard and N colorless rooks.
You are going to paint each rook either white or black.
Then, you are going to place each rook onto some empty square of the chessboard.
Your goal is to create a configuration that maximizes the number of attacking pairs of rooks.

Recall that two rooks attack each other if:

They have opposite colors.
They are in the same row or in the same column.
In that row or column, all squares that are between the two rooks are empty.

Return a vector <string> describing any one optimal placement of the rooks.
The returned vector <string> must have R elements, each of those must have C characters, and each of those must be '.' (empty square), 'W' (white rook) or 'B' (black rook).


DEFINITION
Class:RealWithRooks
Method:construct
Parameters:int, int, int
Returns:vector <string>
Method signature:vector <string> construct(int R, int C, int N)


CONSTRAINTS
-R will be between 1 and 50, inclusive.
-C will be between 1 and 50, inclusive.
-N will be between 1 and R*C, inclusive.


EXAMPLES

0)
2
4
8

Returns: {"WBWB", "BWBW" }

In this test case you need to fill the whole board. There are still many ways to do so. You need to choose the colors in a way that maximizes the number of attacking pairs.


1)
5
5
9

Returns: {"W.B.W", ".....", "B.W.B", ".....", "W.B.W" }


2)
4
7
3

Returns: {".......", ".W...BW", ".......", "......." }


3)
5
6
27

Returns: {"..WBWB", ".WBWBW", "WBWBWB", "BWBWBW", "WBWBWB" }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class RealWithRooks {
public:
	vector <string> construct(int R, int C, int N) {
		vector <string> ans(R, string(C, '.'));
		int mx = 1 << 30;
		for (int r = 1; r <= R; ++r) {
			for (int c = 1; c <= C; ++c) {
				if (r * c >= N) {
					if (r + c < mx) {
						ans = vector <string>(R, string(C, '.'));
						mx = r + c;
						int cnt = 0;
						for (int i = 0; i < r; ++i) {
							for (int j = 0; j < c; ++j) {
								if (++cnt <= N) {
									ans[i][j] = (i + j) % 2 ? 'B' : 'W';
								}
							}
						}
					}
					break;
				}
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 4;
			int Arg2 = 8;
			string Arr3[] = {"WBWB", "BWBW" };

			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, construct(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 5;
			int Arg2 = 9;
			string Arr3[] = {"W.B.W", ".....", "B.W.B", ".....", "W.B.W" };

			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, construct(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 7;
			int Arg2 = 3;
			string Arr3[] = {".......", ".W...BW", ".......", "......." };

			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, construct(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 6;
			int Arg2 = 27;
			string Arr3[] = {"..WBWB", ".WBWBW", "WBWBWB", "BWBWBW", "WBWBWB" };

			vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, construct(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RealWithRooks ___test;
	___test.run_test(-1);
}
// END CUT HERE
