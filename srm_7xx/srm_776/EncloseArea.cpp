// BEGIN CUT HERE
/*
SRM 776 Div1 Easy (350)

PROBLEM STATEMENT

You can order a custom rectangular chessboard.
Both the number of rows and the number of columns must be between 1 and 50, inclusive.

You have a sufficient supply of walls.
Each wall exactly fits onto a diagonal of a cell of the chessboard.
Your task is to place some of these walls onto some of the diagonals of your chessboard cells in such a way that:

The walls form a single continuous boundary of a region of the chessboard.
The area of that region is exactly A.

Return a vector <string> containing any valid solution. Use the character '.' for empty cells and '/' and '\' for cells that contain walls.
Any valid solution will be accepted.
If there is no solution, return an empty vector <string> instead.


DEFINITION
Class:EncloseArea
Method:enclose
Parameters:int
Returns:vector <string>
Method signature:vector <string> enclose(int A)


NOTES
-The boundary of the region enclosed by the walls must not touch or intersect itself, and it may not branch anywhere. In other words, each endpoint of each wall must touch exactly one other wall, and there must be just one connected component of walls.
-The returned vector <string> must describe a rectangular chessboard. I.e., all elements of the return value must have the same length.


CONSTRAINTS
-A will be between 1 and 2500, inclusive.


EXAMPLES

0)
12

Returns: {"........", "../\\....", "./..\\...", ".\\...\\..", "..\\../..", "...\\/...", "........", "........" }

Note that the backslashes in the example output are escaped, i.e., each backslash is shown as \\

Below we show a nicer formatting of the return value:

........
../\....
./..\...
.\...\..
..\../..
...\/...
........
........


1)
7

Returns: { }

It is not possible to enclose a region with area 7.


2)
2498

Returns: { }

It is also impossible to enclose a region with area 2498. Remember the constraints on the chessboard size.


3)
10

Returns: {"./\\..", "/./..", "\\.\\/\\", ".\\../", "..\\/." }

Below we show a nicer formatting of the return value:

./\..
/./..
\.\/\
.\../
..\/.


4)
26

Returns: {"/\\/\\/\\", "\\..../", "/....\\", "\\..../", "/....\\", "\\/\\/\\/" }

Below we show a nicer formatting of the return value:

/\/\/\
\..../
/....\
\..../
/....\
\/\/\/

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class EncloseArea {
public:
	vector <string> enclose(int A) {
		const int SZ = 50;
		int r = SZ * SZ - ((SZ / 2) - 1) * 4 - 2;
		vector<string> ans(SZ, string(SZ, '.'));
		if ((A % 2) != 0 || A > r) {
			return {};
		}

		int u[50][50][2] = {};
		auto fill = [&](int y, int x) {
			u[y][x][1] = u[y][x + 1][0] = u[y + 1][x][1] = u[y + 1][x + 1][0] = 1;
			A -= 2;
		};
		for (int i = 0; i < SZ; i += 2) {
			for (int j = 0; j < SZ && A > 0; j += 2) {
				fill(i, j);
				if (i < (SZ - 2) && j < (SZ - 2) && A > 0) {
					fill(i + 1, j + 1);
				}
			}
		}
		for (int i = 0; i < SZ; ++i) {
			for (int j = 0; j < SZ; ++j) {
				ans[i][j] = u[i][j][0] == u[i][j][1] ? '.' : (((i + j) % 2) ? '\\' : '/');
			}
		}
		return ans;
	}

	// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T>& V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <string>& Expected, const vector <string>& Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) {
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 12;
			string Arr1[] = { "........", "../\\....", "./..\\...", ".\\...\\..", "..\\../..", "...\\/...", "........", "........" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, enclose(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 7;

			vector <string> Arg1;
			verify_case(n, Arg1, enclose(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 2498;

			vector <string> Arg1;
			verify_case(n, Arg1, enclose(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 10;
			string Arr1[] = { "./\\..", "/./..", "\\.\\/\\", ".\\../", "..\\/." };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, enclose(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 26;
			string Arr1[] = { "/\\/\\/\\", "\\..../", "/....\\", "\\..../", "/....\\", "\\/\\/\\/" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, enclose(Arg0));
		}
		n++;

	}

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EncloseArea ___test;
	___test.run_test(-1);
}
// END CUT HERE
