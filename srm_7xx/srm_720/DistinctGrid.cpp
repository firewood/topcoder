// BEGIN CUT HERE
/*
SRM 720 Div1 Medium (450)

PROBLEM STATEMENT

Given the integers n, k, construct an n by n grid of integers where each row and column has at most k distinct integers.
The returned grid must have the maximum number of distinct integers.

Return your answer as a vector <int> with exactly n * n elements.
Element i*n+j of your return value denotes the value of the integer in the i-th row and j-th column of the grid.

If there are multiple optimal solutions, you may return any of them.
The integers in your solution can be arbitrary, as long as they fit into a signed 32-bit integer variable.


DEFINITION
Class:DistinctGrid
Method:findGrid
Parameters:int, int
Returns:vector <int>
Method signature:vector <int> findGrid(int n, int k)


CONSTRAINTS
-n will be between 3 and 50, inclusive.
-k will be between 1 and n/2, inclusive.


EXAMPLES

0)
3
1

Returns: {0, 0, 0, 0, 0, 0, 0, 0, 0 }

The returned value shown above represents the following grid:

{
  0,0,0,
  0,0,0,
  0,0,0
}


1)
6
3

Returns: {1, 0, 0, 0, 0, 2, 0, 3, 0, 0, 4, 0, 0, 0, 5, 6, 0, 0, 0, 0, 7, 8, 0, 0, 0, 9, 0, 0, 10, 0, 11, 0, 0, 0, 0, 12 }

The returned value shown above represents the following grid:

{
  1,0,0,0,0,2,
  0,3,0,0,4,0,
  0,0,5,6,0,0,
  0,0,7,8,0,0,
  0,9,0,0,10,0,
  11,0,0,0,0,12
}


2)
4
2

Returns: {123, 999, 999, 999, 999, 999, 999, 456, 999, 789, 999, 999, 999, 999, 240, 999 }

The returned value shown above represents the following grid:

{
  123,999,999,999,
  999,999,999,456,
  999,789,999,999,
  999,999,240,999
};

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class DistinctGrid {
public:
	vector <int> findGrid(int n, int k) {
		vector <int> ans(n * n);
		int pos = 0;
		for (int i = 1; i < k; ++i) {
			for (int j = 0; j < n; ++j) {
				ans[pos % (n * n)] = pos + 1;
				pos += n + 1;
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
			int Arg0 = 3;
			int Arg1 = 1;
			int Arr2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findGrid(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 3;
			int Arr2[] = {1, 0, 0, 0, 0, 2, 0, 3, 0, 0, 4, 0, 0, 0, 5, 6, 0, 0, 0, 0, 7, 8, 0, 0, 0, 9, 0, 0, 10, 0, 11, 0, 0, 0, 0, 12 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findGrid(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 2;
			int Arr2[] = {123, 999, 999, 999, 999, 999, 999, 456, 999, 789, 999, 999, 999, 999, 240, 999 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findGrid(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DistinctGrid ___test;
	___test.run_test(-1);
}
// END CUT HERE
