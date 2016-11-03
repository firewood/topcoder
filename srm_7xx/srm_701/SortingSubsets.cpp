// BEGIN CUT HERE
/*
SRM 701 Div2 Medium (500)

PROBLEM STATEMENT

You are given a vector <int> a.
The elements of a are not necessarily distinct.

You want to rearrange the elements of a into a non-decreasing order.
What is the smallest possible number of elements you have to move?

Formally, the operation looks as follows:

You select some set of positions in a.
You permute the elements on the chosen positions arbitrarily.

Compute and return the smallest possible size of the set of selected positions.


DEFINITION
Class:SortingSubsets
Method:getMinimalSize
Parameters:vector <int>
Returns:int
Method signature:int getMinimalSize(vector <int> a)


CONSTRAINTS
-a will contain between 1 and 50 elements, inclusive.  
-Each element of a will be between 1 and 100, inclusive.  


EXAMPLES

0)
{3, 2, 1}

Returns: 2

One can take the first and the last element and swap them.  


1)
{1, 2, 3, 4}

Returns: 0

The array is already sorted, so we can select an empty set of positions.


2)
{4, 4, 4, 3, 3, 3}

Returns: 6

Here all elements must be taken and permuted.  


3)
{11, 11, 49, 7, 11, 11, 7, 7, 11, 49, 11}

Returns: 7

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

class SortingSubsets {
public:
	int getMinimalSize(vector <int> a) {
		vector<int> b = a;
		sort(b.begin(), b.end());
		int ans = 0;
		for (int i = 0; i != a.size(); ++i) {
			ans += a[i] != b[i];
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
			int Arr0[] = {3, 2, 1};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMinimalSize(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMinimalSize(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 4, 4, 3, 3, 3};
			int Arg1 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMinimalSize(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {11, 11, 49, 7, 11, 11, 7, 7, 11, 49, 11};
			int Arg1 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMinimalSize(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SortingSubsets ___test;
	___test.run_test(-1);
}
// END CUT HERE
