// BEGIN CUT HERE
/*
SRM 631 Div1 Easy (250)

PROBLEM STATEMENT

Cat Taro and Fox Jiro work with a square grid with N rows and N columns (N is even).
Each cell of the grid is painted either black or white.
You are given a vector <string> grid which represents the current state of the grid.
Each element of grid represents one row of the grid.
In grid, the character 'W' represents a white cell, and the character 'B' represents a black cell. 

Taro works with the rows of the grid.
He will take zero or more turns. In each turn he can choose any row of the grid and perform one of the following operations:

Paint all black cells of the row white.
Paint all white cells of the row black.

Jiro works with the columns of the grid.
He thinks that a column is bad if there are more than N/2 consecutive cells of the same color in the column.
He is happy only if there are no bad columns in the grid.

Return the minimum number of turns that Taro must perform in order to make Jiro happy.


DEFINITION
Class:TaroJiroGrid
Method:getNumber
Parameters:vector <string>
Returns:int
Method signature:int getNumber(vector <string> grid)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-N will be even.
-grid will contain exactly N elements.
-Each element of grid will contain exactly N characters.
-Each character in grid will be 'W' or 'B'.


EXAMPLES

0)
{"WB",
 "BB"}

Returns: 1

Initially, Jiro is not happy because all cells of the column 1 (0-based index) are black. In one operation, Taro can paint the first row white. After the operation, Jiro will be happy about the grid. Thus, the answer is 1.


1)
{"WB",
 "WW"}

Returns: 1


2)
{"WB",
 "WB"}

Returns: 2

In this case, Taro should paint the first row white, and the second one black (or vice versa). Note that it is not possible to make Jiro happy in fewer than two operations.


3)
{"WBBW",
 "WBWB",
 "WWBB",
 "BWWW"}

Returns: 2


4)
{"WBBWBB",
 "BBWBBW",
 "WWBWBW",
 "BWWBBB",
 "WBWBBW",
 "WWWBWB"}

Returns: 1

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TaroJiroGrid {

	bool check(const vector <string> &grid) {
		int N = (int)grid.size();
		int t = N / 2;
		for (int i = 0; i < N; ++i) {
			int cnt = 1;
			for (int j = 1; j < N; ++j) {
				if (grid[j-1][i] == grid[j][i]) {
					++cnt;
					if (cnt > t) {
						return false;
					}
				} else {
					cnt = 1;
				}
			}
		}
		return true;
	}

public:
	int getNumber(vector <string> grid) {
		int N = (int)grid.size();
		if (check(grid)) {
			return 0;
		}
		for (int i = 0; i < N; ++i) {
			vector <string> x = grid;
			x[i] = string(N, 'B');
			if (check(x)) {
				return 1;
			}
			x[i] = string(N, 'W');
			if (check(x)) {
				return 1;
			}
		}
		return 2;
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
			string Arr0[] = {"WB",
 "BB"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"WB",
 "WW"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"WB",
 "WB"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"WBBW",
 "WBWB",
 "WWBB",
 "BWWW"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"WBBWBB",
 "BBWBBW",
 "WWBWBW",
 "BWWBBB",
 "WBWBBW",
 "WWWBWB"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
				"WW",
				"BB" };
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TaroJiroGrid ___test;
	___test.run_test(-1);
}
// END CUT HERE
