// BEGIN CUT HERE
/*
SRM 720 Div2 Easy (250)

PROBLEM STATEMENT

You are given ints n,k and a vector <int> grid.

Cat Noku has constructed a 2d matrix of integers with dimensions n by n. 
Each element of the matrix is between 0 and k-1, inclusive.
You are given the 2d matrix in a special format, in the vector <int> grid.
grid has exactly n * n elements.
The value grid[ i*n+j ] corresponds to the entry in the i-th row and j-th column of Cat Noku's matrix for all 0 ? i,j ? n-1.
You would like to check if each row and column has exactly k distinct integers.
If this is the case, return the string "Good", otherwise, return "Bad". (Note that the return value is case-sensitive.)


DEFINITION
Class:DistinctGridEasy
Method:checkGrid
Parameters:int, int, vector <int>
Returns:string
Method signature:string checkGrid(int n, int k, vector <int> grid)


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-k will be between 1 and n, inclusive.
-grid will contain exactly n*n elements.
-Each element of grid will be between 0 and k-1, inclusive.


EXAMPLES

0)
3
3
{
0,1,2,
1,2,0,
2,0,1
}

Returns: "Good"

Here, Cat Noku has a 3 by 3 grid, and he wants to check whether each row and column has 3 distinct integers.
In this case, the condition is satisfied, so we return "Good".


1)
3
3
{
0,1,2,
1,2,0,
2,0,0
}

Returns: "Bad"

In this case, this grid is not good because the last column only has 2 distinct integers.


2)
5
2
{
0,0,0,0,1,
0,1,0,0,0,
0,0,1,0,0,
1,0,0,0,0,
0,0,0,1,0
}

Returns: "Good"


3)
5
3
{
2,2,0,0,1,
0,1,2,2,0,
0,2,1,0,0,
1,0,0,0,2,
0,0,2,1,0
}

Returns: "Good"


4)
7
4
{
3,2,1,0,3,2,1,
3,2,1,3,2,1,2,
2,0,3,1,1,0,3,
1,3,0,2,0,3,0,
0,3,1,2,3,2,1,
1,1,1,2,1,0,3,
3,1,2,0,3,2,3
}

Returns: "Bad"

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

class DistinctGridEasy {
public:
	string checkGrid(int n, int k, vector <int> grid) {
		for (int i = 0; i < n; ++i) {
			set<int> a, b;
			for (int j = 0; j < n; ++j) {
				a.insert(grid[i*n + j]);
				b.insert(grid[j*n + i]);
			}
			if (a.size() != k || b.size() != k) {
				return "Bad";
			}
		}
		return "Good";
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
			int Arg0 = 3;
			int Arg1 = 3;
			int Arr2[] = {
0,1,2,
1,2,0,
2,0,1
};
			string Arg3 = "Good";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, checkGrid(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			int Arr2[] = {
0,1,2,
1,2,0,
2,0,0
};
			string Arg3 = "Bad";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, checkGrid(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 2;
			int Arr2[] = {
0,0,0,0,1,
0,1,0,0,0,
0,0,1,0,0,
1,0,0,0,0,
0,0,0,1,0
};
			string Arg3 = "Good";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, checkGrid(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 3;
			int Arr2[] = {
2,2,0,0,1,
0,1,2,2,0,
0,2,1,0,0,
1,0,0,0,2,
0,0,2,1,0
};
			string Arg3 = "Good";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, checkGrid(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 4;
			int Arr2[] = {
3,2,1,0,3,2,1,
3,2,1,3,2,1,2,
2,0,3,1,1,0,3,
1,3,0,2,0,3,0,
0,3,1,2,3,2,1,
1,1,1,2,1,0,3,
3,1,2,0,3,2,3
};
			string Arg3 = "Bad";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, checkGrid(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DistinctGridEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
