// BEGIN CUT HERE
/*
// SRM 530 Div2 Medium (500)

// PROBLEM STATEMENT
// Like all other software engineers, Gogo likes to cut and eat cake.
He used a rectangular baking dish to make a cake. The dish is divided into
a grid of unit square cells. Initially, all the cells contained the cake.

Gogo's friend John wanted to eat the cake. Gogo gave John a rectangular cake
cutter with the following properties:

The cake cutter is divided into a grid of cells. The cells are of the same size
as the cells of the dish.
The cake cutter contains cells of two types: used cells and ignored cells.
Each of the first row, the last row, the first column, and the last column
of the cutter contains at least one used cell.

When used, the cake cutter must be placed on the dish according to the following rules:

Each cell of the cutter must contain a single cell of the dish.
It is not allowed to flip or rotate the cutter. Rows and columns of the cutter
must correspond to some consecutive rows and some consecutive columns of the dish
in the given orientation. (See the last two examples.)
Each used cell of the cutter must be placed onto a cell that still contains cake.
The ignored cells may be placed onto any cells.


When the cake cutter is used in the way described above, it removes the cake
from all the used cells. John may have used the cake cutter multiple times,
one after another.

After John went home, Gogo examined the cake that remained in the dish.
He now wants to check whether John really cut the cake according to the above rules.
You are given vector <string>s cake and cutter. The remaining cake is described
by cake. More precisely, cake[i][j] is 'X' if the cell in the i-th row and
j-th column of the dish still contains cake; otherwise cake[i][j] is '.' (a period).
The cake cutter is described by cutter. More precisely, cutter[i][j] is '.'
(a period) if the cell in the i-th row and j-th column of the cutter is used,
and 'X' if the cell is ignored.

Return "YES" (quotes for clarity) if it is possible that John only ate the cake
by using the cutter in the way described above. Return "NO" otherwise.

DEFINITION
Class:GogoXCake
Method:solve
Parameters:vector <string>, vector <string>
Returns:string
Method signature:string solve(vector <string> cake, vector <string> cutter)


NOTES
-The used cells in the cutter do not have to be contiguous.


CONSTRAINTS
-cake will contain between 1 and 50 elements, inclusive.
-Each element of cake will contain between 1 and 50 characters, inclusive.
-All elements of cake will contain the same number of characters.
-Each character in each element of cake will be either '.' or 'X'.
-There will be at least one '.' in cake
-cutter will contain between 1 and R elements, inclusive, where R is the number of elements in cake.
-Each element of cutter will contain between 1 and C characters, inclusive, where C is the number of characters in each element of cake.
-All elements of cutter will contain the same number of characters.
-Each character in each element of cutter will be either '.' or 'X'.
-Each of the first row, the first column, the last row, and the last column of the cutter will contain at least one '.'.


EXAMPLES

0)
{"X.X"
,"..."
,"..."
,"X.X"}
{".X"
,".."
,"X."}

Returns: "YES"



1)
{"..XX"
,"...X"
,"X..."
,"XX.."}
{".."
,".."}

Returns: "NO"



2)
{"...X..."}
{"..."}

Returns: "YES"



3)
{".X."
,"X.X"
,".X."}
{"."}

Returns: "YES"



4)
{"XXXXXXX"
,"X.....X"
,"X.....X"
,"X.....X"
,"XXXXXXX"}
{".X."
,"XXX"
,".X."}

Returns: "NO"



5)
{".."
,"X."
,".X"}
{".."
,".X"
,"X."}

Returns: "NO"

You may not flip the cutter.

6)
{"X.."
,".XX"
,".XX"}
{".XX"
,".XX"
,"X.."}

Returns: "NO"

You may not rotate the cutter.

*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

// cake: 'X' = contains, '.' = not exist
// cutter: '.' = used, 'X' = ignored

class GogoXCake {

	bool check(int left, int top, StrVec &k, const StrVec &c, bool modify) {
		int height = c.size();
		int width = c[0].length();
		int x, y;
		for (y = 0; y < height; ++y) {
			for (x = 0; x < width; ++x) {
				if (c[y][x] == '.') {
					if (k[top+y][left+x] == '.') {
						if (modify) {
							k[top+y][left+x] = 'X';
						}
					} else {
						return false;
					}
				}
			}
		}
		return true;
	}

public:
	string solve(vector <string> cake, vector <string> cutter) {
		int cake_height = cake.size();
		int cake_width = cake[0].length();
		int cutter_height = cutter.size();
		int cutter_width = cutter[0].length();
		int x, y;
		for (y = 0; y <= (cake_height-cutter_height); ++y) {
			for (x = 0; x <= (cake_width-cutter_width); ++x) {
				if (check(x, y, cake, cutter, false)) {
					// restore cakes if cutter fits
					check(x, y, cake, cutter, true);
				}
			}
		}
		for (y = 0; y < cake_height; ++y) {
			for (x = 0; x < cake_width; ++x) {
				if (cake[y][x] != 'X') {
					return "NO";
				}
			}
		}
		return "YES";
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
			string Arr0[] = {"X.X"
,"..."
,"..."
,"X.X"};
			string Arr1[] = {".X"
,".."
,"X."};
			string Arg2 = "YES";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, solve(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..XX"
,"...X"
,"X..."
,"XX.."};
			string Arr1[] = {".."
,".."};
			string Arg2 = "NO";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, solve(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...X..."};
			string Arr1[] = {"..."};
			string Arg2 = "YES";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, solve(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".X."
,"X.X"
,".X."};
			string Arr1[] = {"."};
			string Arg2 = "YES";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, solve(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"XXXXXXX"
,"X.....X"
,"X.....X"
,"X.....X"
,"XXXXXXX"};
			string Arr1[] = {".X."
,"XXX"
,".X."};
			string Arg2 = "NO";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, solve(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".."
,"X."
,".X"};
			string Arr1[] = {".."
,".X"
,"X."};
			string Arg2 = "NO";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, solve(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"X.."
,".XX"
,".XX"};
			string Arr1[] = {".XX"
,".XX"
,"X.."};
			string Arg2 = "NO";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, solve(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GogoXCake ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
