// BEGIN CUT HERE
/*
SRM 640 Div2 Easy (250)

PROBLEM STATEMENT
Christmas is just around the corner, and Alice just decorated her Christmas tree.
There are N stars and N-1 ribbons on the tree.
Each ribbon connects two of the stars in such a way that all stars and ribbons hold together.
(In other words, the stars and ribbons are the vertices and edges of a tree.)

The stars are numbered 1 through N.
Additionally, each star has some color.
You are given the colors of stars as a vector <int> col with N elements.
For each i, col[i] is the color of star i+1.
(Different integers represent different colors.)

You are also given a description of the ribbons: two vector <int>s x and y with N-1 elements each.
For each i, there is a ribbon that connects the stars with numbers x[i] and y[i].

According to Alice, a ribbon that connects two stars with different colors is beautiful, while a ribbon that connects two same-colored stars is not.
Compute and return the number of beautiful ribbons in Alice's tree.


DEFINITION
Class:ChristmasTreeDecorationDiv2
Method:solve
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int solve(vector <int> col, vector <int> x, vector <int> y)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-The number of elements in col will be exactly N.
-The number of elements in x will be exactly N - 1.
-The number of elements in y will be the same as the number of elements in x.
-All elements of x and y will be between 1 and N, inclusive.
-For each i, the numbers x[i] and y[i] will be different.
-The graph formed by the N-1 ribbons will be connected.


EXAMPLES

0)
{1,2,3,3}
{1,2,3}
{2,3,4}

Returns: 2

There are two beautiful ribbons: the one that connects stars 1 and 2, and the one that connects stars 2 and 3.
The other ribbon is not beautiful because stars 3 and 4 have the same color.

1)
{1,3,5}
{1,3}
{2,2}

Returns: 2



2)
{1,1,3,3}
{1,3,2}
{2,1,4}

Returns: 2



3)
{5,5,5,5}
{1,2,3}
{2,3,4}

Returns: 0



4)
{9,1,1}
{3,2}
{2,1}

Returns: 1

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class ChristmasTreeDecorationDiv2 {

public:
	int solve(vector <int> col, vector <int> x, vector <int> y) {
		int result = 0;
		for (int i = 0; i < (int)x.size(); ++i) {
			result += col[x[i]-1] != col[y[i]-1];
		}
		return result;
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
			int Arr0[] = {1,2,3,3};
			int Arr1[] = {1,2,3};
			int Arr2[] = {2,3,4};
			int Arg3 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,3,5};
			int Arr1[] = {1,3};
			int Arr2[] = {2,2};
			int Arg3 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,3,3};
			int Arr1[] = {1,3,2};
			int Arr2[] = {2,1,4};
			int Arg3 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,5,5,5};
			int Arr1[] = {1,2,3};
			int Arr2[] = {2,3,4};
			int Arg3 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9,1,1};
			int Arr1[] = {3,2};
			int Arr2[] = {2,1};
			int Arg3 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ChristmasTreeDecorationDiv2 ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
