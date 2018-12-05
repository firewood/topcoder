// BEGIN CUT HERE
/*
SRM 742 Div2 Medium (500)

PROBLEM STATEMENT

You have a 50 times 50 chessboard. Both rows and columns of the chessboard are numbered from 0 to 49, inclusive.

A queen is a chess piece that attacks all cells that are in the same row, in the same column, or on the same diagonal.
In this problem we will be using at most sixteen queens.

Some queens are already placed on the board.
You are given their coordinates in the vector <int>s row and col.
More precisely, for each valid i there is a queen on the cell (row[i], col[i]).
These queens are placed in such a way that no two of them attack each other.

You want to place add additional queens onto the chessboard in such a way that in the final configuration no two queens will attack each other.
Find any one valid solution.

Return a vector <int> with the coordinates of the added queens.
More precisely, if you want to place queens onto the cells (r0, c0), (r1, c1), and so on, return the vector <int> { r0, c0, r1, c1, ... }.


DEFINITION
Class:SixteenQueens
Method:addQueens
Parameters:vector <int>, vector <int>, int
Returns:vector <int>
Method signature:vector <int> addQueens(vector <int> row, vector <int> col, int add)


NOTES
-For the given constraints a solution always exists. Any valid solution will be accepted.


CONSTRAINTS
-row will have between 0 and 16 elements, inclusive.
-Each element of row will be between 0 and 49, inclusive.
-col will have the same number of elements as row.
-Each element of col will be between 0 and 49, inclusive.
-The queens described by row and col stand on distinct cells and they do not attack each other.
-add will be between 0 and 16, inclusive.
-The number of elements in row plus the value of add will be at most 16.


EXAMPLES

0)
{3}
{5}
1

Returns: {0, 0 }

There is a queen at (3,5). We are asked to add one more queen. In the example output shown above we place it at (0,0).


1)
{0}
{1}
1

Returns: {4, 7 }

There is a queen at (0,1). This time we cannot place the second queen at (0,0) because the two queens would attack each other.


2)
{0}
{1}
3

Returns: {4, 7, 15, 0, 49, 49 }

Adding three queens.


3)
{14, 19}
{3, 47}
0

Returns: { }

The easiest inputs are those where you don't have to add any new queens.


4)
{}
{}
2

Returns: {0, 0, 1, 2 }

There can be zero queens on the board before you start adding the new ones.


5)
{1,2,3}
{7,2,19}
1

Returns: {0, 1 }

There are three queens already on the board: at (1,7), (2,2), and (3,19). Our solution proposes to put the fourth queen onto the cell (0,1). There are many other valid solutions, and any of those will be accepted as well.

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

class SixteenQueens {
	int used[50][50] = {};
	void fill(int r, int c, int dy, int dx) {
		for (int i = -50; i <= 50; ++i) {
			int a = r + i * dy, b = c + i * dx;
			if (a >= 0 && a < 50 && b >= 0 && b < 50) {
				used[a][b] = 1;
			}
		}
	}
	void fill(int r, int c) {
		fill(r, c, 1, 0);
		fill(r, c, 0, 1);
		fill(r, c, 1, 1);
		fill(r, c, 1, -1);
	}
public:
	vector <int> addQueens(vector <int> row, vector <int> col, int add) {
		memset(used, 0, sizeof(used));
		for (int i = 0; i < (int)row.size(); ++i) {
			fill(row[i], col[i]);
		}
		vector <int> ans;
		for (int k = 0; k < add; ++k) {
			for (int i = 0; i < 50; ++i) {
				for (int j = 0; j < 50; ++j) {
					if (!used[i][j]) {
						ans.push_back(i);
						ans.push_back(j);
						fill(i, j);
						i = 50;
						break;
					}
				}
			}
		}
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
			int Arr0[] = {3};
			int Arr1[] = {5};
			int Arg2 = 1;
			int Arr3[] = {0, 0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, addQueens(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			int Arr1[] = {1};
			int Arg2 = 1;
			int Arr3[] = {4, 7 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, addQueens(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			int Arr1[] = {1};
			int Arg2 = 3;
			int Arr3[] = {4, 7, 15, 0, 49, 49 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, addQueens(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {14, 19};
			int Arr1[] = {3, 47};
			int Arg2 = 0;
//			int Arr3[] = { };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg3;
			verify_case(n, Arg3, addQueens(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			// int Arr0[] = {};
			// int Arr1[] = {};
			int Arg2 = 2;
			int Arr3[] = {0, 0, 1, 2 };

			vector <int> Arg0;
			vector <int> Arg1;
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, addQueens(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3};
			int Arr1[] = {7,2,19};
			int Arg2 = 1;
			int Arr3[] = {0, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, addQueens(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SixteenQueens ___test;
	___test.run_test(-1);
}
// END CUT HERE
