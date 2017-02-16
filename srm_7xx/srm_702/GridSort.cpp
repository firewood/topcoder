// BEGIN CUT HERE
/*
SRM 702 Div2 Medium (500)

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

Charlie can modify his grid in two ways: He may swap any two rows, and he may swap any two columns.
Charlie now wonders whether there is a sequence of swaps that would sort his grid - that is, rearrange its elements in such a way that the value list of the new grid will be the ordered sequence (1,2,3,...,n*m).

If it is possible to sort Charlie's grid, return "Possible". Otherwise, return "Impossible".


DEFINITION
Class:GridSort
Method:sort
Parameters:int, int, vector <int>
Returns:string
Method signature:string sort(int n, int m, vector <int> grid)


CONSTRAINTS
-n,m will be between 1 and 50, inclusive.
-grid will be a permutation of [1,...,n*m].


EXAMPLES

0)
2
2
{
 1,2,
 3,4
}

Returns: "Possible"

This grid is already sorted, so Charlie doesn't need to do anything.


1)
2
2
{
 3,4,
 1,2
}

Returns: "Possible"

Charlie can sort this grid by swapping rows 0 and 1.


2)
2
2
{
 4,3,
 1,2
}

Returns: "Impossible"


3)
1
10
{4,5,1,2,9,8,3,10,7,6}

Returns: "Possible"


4)
3
5
{
 10,6,8,9,7,
 5,1,3,4,2,
 15,11,13,14,12
}

Returns: "Possible"


5)
6
2
{
 11,12,
 2,1,
 9,10,
 7,8,
 6,5,
 3,4
}

Returns: "Impossible"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class GridSort {
public:
	string sort(int n, int m, vector <int> grid) {
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (grid[j * m] < grid[i * m]) {
					for (int k = 0; k < m; ++k) {
						swap(grid[i * m + k], grid[j * m + k]);
					}
				}
			}
		}
		for (int i = 0; i < m; ++i) {
			for (int j = i + 1; j < m; ++j) {
				if (grid[j] < grid[i]) {
					for (int k = 0; k < n; ++k) {
						swap(grid[k * m + i], grid[k * m + j]);
					}
				}
			}
		}
		for (int i = 0; i < n * m; ++i) {
			if (grid[i] != (i + 1)) {
				return "Impossible";
			}
		}
		return "Possible";
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
			string Arg3 = "Possible";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, sort(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arr2[] = {
 3,4,
 1,2
};
			string Arg3 = "Possible";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, sort(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arr2[] = {
 4,3,
 1,2
};
			string Arg3 = "Impossible";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, sort(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 10;
			int Arr2[] = {4,5,1,2,9,8,3,10,7,6};
			string Arg3 = "Possible";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, sort(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 5;
			int Arr2[] = {
 10,6,8,9,7,
 5,1,3,4,2,
 15,11,13,14,12
};
			string Arg3 = "Possible";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, sort(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 2;
			int Arr2[] = {
 11,12,
 2,1,
 9,10,
 7,8,
 6,5,
 3,4
};
			string Arg3 = "Impossible";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, sort(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GridSort ___test;
	___test.run_test(-1);
}
// END CUT HERE
