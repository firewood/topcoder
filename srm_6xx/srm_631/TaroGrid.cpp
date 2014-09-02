// BEGIN CUT HERE
/*
SRM 631 Div2 Easy (250)

PROBLEM STATEMENT

Cat Taro has a square grid with N rows and N columns.
Each cell of the grid is painted either black or white.
You are given a vector <string> grid which represents the current state of the grid.
Each element of grid represents one row of the grid.
In grid, the character 'W' represents a white cell, and the character 'B' represents a black cell. 

Taro wants to choose a set of consecutive cells that are in the same column and are painted in the same color.
Return the largest number of cells he can choose.


DEFINITION
Class:TaroGrid
Method:getNumber
Parameters:vector <string>
Returns:int
Method signature:int getNumber(vector <string> grid)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-grid will contain exactly N elements.
-Each element of grid will contain exactly N characters.
-Each character in grid will be 'W' or 'B'.


EXAMPLES

0)
{"W"}

Returns: 1


1)
{"WB",
 "BW"}

Returns: 1


2)
{"BWW",
 "BBB",
 "BWB"}

Returns: 3

He can choose the entire leftmost column (i.e., character 0 of each element of grid).


3)
{"BWBW",
 "BBWB",
 "WWWB",
 "BWWW"}

Returns: 3


4)
{"BWB",
 "BBW",
 "BWB"}

Returns: 3


5)
{"BBWWBBWW",
 "BBWWBBWW",
 "WWBBWWBB",
 "WWBBWWBB",
 "BBWWBBWW",
 "BBWWBBWW",
 "WWBBWWBB",
 "WWBBWWBB"}

Returns: 2

Note that the chosen cells must be consecutive.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TaroGrid {
public:
	int getNumber(vector <string> grid) {
		int ans = 1;
		int N = (int)grid.size();
		for (int c = 0; c < N; ++c) {
			int cnt = 1;
			for (int r = 1; r < N; ++r) {
				if (grid[r - 1][c] == grid[r][c]) {
					++cnt;
					ans = max(ans, cnt);
				} else {
					cnt = 1;
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
			string Arr0[] = {"W"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"WB",
 "BW"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"BWW",
 "BBB",
 "BWB"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"BWBW",
 "BBWB",
 "WWWB",
 "BWWW"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"BWB",
 "BBW",
 "BWB"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"BBWWBBWW",
 "BBWWBBWW",
 "WWBBWWBB",
 "WWBBWWBB",
 "BBWWBBWW",
 "BBWWBBWW",
 "WWBBWWBB",
 "WWBBWWBB"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TaroGrid ___test;
	___test.run_test(-1);
}
// END CUT HERE
