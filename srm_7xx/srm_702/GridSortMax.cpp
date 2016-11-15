// BEGIN CUT HERE
/*
SRM 702 Div1 Easy (300)

PROBLEM STATEMENT

Charlie has a grid of n rows by m columns.
The rows are numbered 0 through n-1 from top to bottom.
The columns are numbered 0 through m-1 from left to right.

Each cell of the grid contains a positive integer.
The integers in Charlie's grid are a permutation of the numbers 1 through n*m.
(I.e., each of these numbers occurs in the grid exactly once.)

Given a grid, its value list is a sequence constructed by listing all values in the grid in row major order.
That is, we first list the values in row 0 from left to right, then the values in row 1 from left to right, and so on.

You are given the ints n and m: the dimensions of Charlie's grid.
You are also given a vector <int> grid: the value list for Charlie's grid.
(Formally, grid[i*m+j] is the value stored in row i, column j of the grid.)

In Charlie's eyes, the most beautiful of all grids is the sorted grid: the grid whose value list is the ordered ordered sequence {1,2,3,...,n*m}.

Given a grid, its similarity string is a string of zeroes and ones that describes the similarity between that particular grid and the sorted grid. More precisely:

The similarity string is a string of length n*m.
For each i, character i of the similarity string is '1' if both grids have the same i-th element in their value lists, and it is '0' if those values differ. (All indices in the previous sentence are 0-based.)

For example, suppose n=2 and m=3. The sorted grid has the value list {1,2,3,4,5,6}, and its similarity string is "111111". Another possible grid with these dimensions has the value list {1,5,2,4,3,6}. The similarity string for this grid is "100101".

Charlie can modify his grid in two ways: He may swap any two rows, and he may swap any two columns.
He wants to use these operations to obtain a grid with the lexicographically largest possible similarity string.
Find and return that string.


DEFINITION
Class:GridSortMax
Method:findMax
Parameters:int, int, vector <int>
Returns:string
Method signature:string findMax(int n, int m, vector <int> grid)


CONSTRAINTS
-n,m will be between 1 and 50, inclusive.
-grid will be a permutation of [1,...,n*m]


EXAMPLES

0)
2
2
{
 1,2,
 3,4
}

Returns: "1111"

Charlie's grid is the sorted grid.
Its similarity string is therefore "1111".
Charlie should make no changes to the grid, as this is already the lexicographically largest of all possible strings.


1)
2
2
{
 2,1,
 3,4
}

Returns: "1100"

The similarity string for Charlie's current grid is "0011", as the values 3 and 4 are in the same places as in the sorted grid.
Charlie should swap the two columns.
That swap will produce a grid with the similarity string "1100": now the values 1 and 2 are in their correct places but the values 3 and 4 aren't.


2)
2
2
{
 4,2,
 3,1
}

Returns: "1001"


3)
1
10
{10,6,2,3,5,7,1,9,4,8}

Returns: "1111111111"


4)
3
5
{
 5,2,10,7,9,
 3,4,14,11,1,
 15,12,6,8,13
}

Returns: "101100100100000"


5)
6
2
{
 3,9,
 5,1,
 10,6,
 2,7,
 8,11,
 12,4
}

Returns: "100000101010"

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

class GridSortMax {
public:
	string findMax(int n, int m, vector <int> grid) {
		int row[2501], col[2501];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				row[grid[i * m + j]] = i;
				col[grid[i * m + j]] = j;
			}
		}
		int srcrow[50], dstrow[50], srccol[50], dstcol[50];
		memset(srcrow, -1, sizeof(srcrow));
		memset(dstrow, -1, sizeof(dstrow));
		memset(srccol, -1, sizeof(srccol));
		memset(dstcol, -1, sizeof(dstcol));
		string ans;
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < m; ++c) {
				int i = r * m + c + 1;
				if (srcrow[row[i]] < 0 && dstrow[r] < 0 && (srccol[col[i]] == c || (srccol[col[i]] < 0 && dstcol[c] < 0))) {
					srcrow[row[i]] = r;
					dstrow[r] = row[i];
				}
				if (srcrow[row[i]] == r && srccol[col[i]] < 0 && dstcol[c] < 0) {
					srccol[col[i]] = c;
					dstcol[c] = col[i];
				}
				ans += (srcrow[row[i]] == r && srccol[col[i]] == c) ? '1' : '0';
			}
		}
		return ans;
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
			int Arg1 = 2;
			int Arr2[] = {
 1,2,
 3,4
};
			string Arg3 = "1111";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, findMax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arr2[] = {
 2,1,
 3,4
};
			string Arg3 = "1100";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, findMax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arr2[] = {
 4,2,
 3,1
};
			string Arg3 = "1001";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, findMax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 10;
			int Arr2[] = {10,6,2,3,5,7,1,9,4,8};
			string Arg3 = "1111111111";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, findMax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 5;
			int Arr2[] = {
 5,2,10,7,9,
 3,4,14,11,1,
 15,12,6,8,13
};
			string Arg3 = "101100100100000";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, findMax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 2;
			int Arr2[] = {
 3,9,
 5,1,
 10,6,
 2,7,
 8,11,
 12,4
};
			string Arg3 = "100000101010";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, findMax(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GridSortMax ___test;
	___test.run_test(-1);
}
// END CUT HERE
