// BEGIN CUT HERE
/*
TCO20 R3B Easy (300)

PROBLEM STATEMENT

There is a R times C grid.
Rows are numbered from 0 to R-1 (going north to south) and columns 0 to C-1 (going west to east).
Cell in row r, column c is denoted (r, c).
You start in the cell (0, 0).

There are a few obstacles (at most three of them).
For each valid i, there is an obstacle in the cell (obsr[i], obsc[i]).

None of the obstacles are in cells that lie on the border of the grid.

You can travel along the grid by making steps in the four cardinal directions: 'N' (row -= 1), 'S' (row += 1), 'E' (column += 1) and 'W' (column -= 1).

Your task is to visit at least half of all cells in the grid - that is, at least R*C/2 cells, rounded up. You cannot visit the same cell twice, and you cannot visit a cell with an obstacle.


Return your sequence of movements.


DEFINITION
Class:VisitALot
Method:travel
Parameters:int, int, vector <int>, vector <int>
Returns:string
Method signature:string travel(int R, int C, vector <int> obsr, vector <int> obsc)


NOTES
-For the given constraints a solution always exists. Any valid solution will be accepted.
-The cell (0, 0) counts as visited at the beginning of your travel. Note that this means that you cannot return into this cell.


CONSTRAINTS
-R will be between 2 and 50, inclusive.
-C will be between 2 and 50, inclusive.
-obsr will contain between 0 and 3 elements, inclusive.
-obsc will contain the same number of elements as obsr.
-Each element of obsr will be between 1 and R-2, inclusive.
-Each element of obsc will be between 1 and C-2, inclusive.
-Cells with obstacles will be distinct.


EXAMPLES

0)
2
3
{}
{}

Returns: "SENE"

For a grid this small there cannot be any obstacles.

The sample solution is longer than needed: it visits five of the six cells. "SE" and "EE" are two of the shortest valid solutions - each of them visits three of the six cells.


1)
6
5
{1, 1, 4}
{1, 3, 1}

Returns: "SSEESWWSSEENEE"

The grid is shown below: 0 represents your starting spot, X are obstacles.

0....
.X.X.
.....
.....
.X...
.....

The path described by the example output is shown below as 0123456789ABCDE. It visits exactly half of the cells in this grid.

0....
1X.X.
234..
765..
8XCDE
9AB..


2)
7
8
{}
{}

Returns: "EEEEEEESWWWWWWWSEEEEEEESWWWWWWWSEEEEEEESWWWWWWWSEEEEEEE"

The example return value shown above describes a path that visits the entire grid.

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class VisitALot {
	int r;
	int c;
	vector<vector<int>> b;
	// ‰EŽè–@
	string dfs(int y, int x, int d, int remain) {
		const int dy[4] = { 0, 1, 0, -1 };
		const int dx[4] = { 1, 0, -1, 0 };
		const char dc[4] = { 'E', 'S', 'W', 'N' };
		const int order[3] = { 1, 0, 3 };
		for (int i = 0; i < 3; ++i) {
			int dir = (d + order[i]) % 4;
			int ny = y + dy[dir], nx = x + dx[dir];
			if (nx >= 0 && nx < c && ny >= 0 && ny < r && b[ny][nx] == 0) {
				b[ny][nx] = 1;
				string ret = string(1, dc[dir]);
				if (remain == 1) {
					return ret;
				}
				string sub = dfs(ny, nx, dir, remain - 1);
				if (!sub.empty()) {
					return ret + sub;
				}
				b[ny][nx] = 0;
			}
		}
		return "";
	}
public:
	string travel(int R, int C, vector <int> obsr, vector <int> obsc) {
		r = R, c = C;
		b = vector<vector<int>>(R, vector<int>(C));
		for (int i = 0; i < (int)obsr.size(); ++i) {
			b[obsr[i]][obsc[i]] = -1;
		}
		b[0][0] = 1;
		return dfs(0, 0, 0, (R * C + 1) / 2 - 1);
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
			int Arg0 = 2;
			int Arg1 = 3;
			// int Arr2[] = {};
			// int Arr3[] = {};
			string Arg4 = "SENE";

			vector <int> Arg2;
			vector <int> Arg3;
			verify_case(n, Arg4, travel(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 5;
			int Arr2[] = {1, 1, 4};
			int Arr3[] = {1, 3, 1};
			string Arg4 = "SSEESWWSSEENEE";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, travel(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 8;
			// int Arr2[] = {};
			// int Arr3[] = {};
			string Arg4 = "EEEEEEESWWWWWWWSEEEEEEESWWWWWWWSEEEEEEESWWWWWWWSEEEEEEE";

			vector <int> Arg2;
			vector <int> Arg3;
			verify_case(n, Arg4, travel(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 50;
			int Arg1 = 50;
			int Arr2[] = { 1,2,3 };
			int Arr3[] = { 1,2,3 };
			string Arg4 = "EEEEEEESWWWWWWWSEEEEEEESWWWWWWWSEEEEEEESWWWWWWWSEEEEEEE";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, travel(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 5;
			int Arg1 = 5;
			int Arr2[] = {1,2,2};
			int Arr3[] = {1,2,3};
			string Arg4 = "EEEEEEESWWWWWWWSEEEEEEESWWWWWWWSEEEEEEESWWWWWWWSEEEEEEE";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, travel(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 33;
			int Arg1 = 23;
			int Arr2[] = { 23,10,23 };
			int Arr3[] = { 21,20,17 };
			string Arg4 = "EEEEEEESWWWWWWWSEEEEEEESWWWWWWWSEEEEEEESWWWWWWWSEEEEEEE";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, travel(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	VisitALot ___test;
	___test.run_test(-1);
}
// END CUT HERE
