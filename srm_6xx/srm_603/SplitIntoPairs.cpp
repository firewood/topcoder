// BEGIN CUT HERE
/*
SRM 603 Div2 Medium (500)

PROBLEM STATEMENT
You are given a vector <int> A with N elements, where N is even.
Note that some elements of A may be negative.
You are also given a int X which is guaranteed to be negative.
You must divide the elements of A into N/2 disjoint pairs.
(That is, each element of A must be in exactly one of those pairs.)
Your goal is to maximize the number of pairs in which the product of the two elements is greater than or equal to X.
Return the largest possible number of such pairs.

DEFINITION
Class:SplitIntoPairs
Method:makepairs
Parameters:vector <int>, int
Returns:int
Method signature:int makepairs(vector <int> A, int X)


CONSTRAINTS
-A will contain between 2 and 50 elements, inclusive.
-The number of elements in A will be even.
-Each element in A will be between -1,000,000,000 and 1,000,000,000, inclusive.
-X will be between -1,000,000,000 and -1, inclusive.


EXAMPLES

0)
{2,-1}
-1

Returns: 0

One possible pair has product -2, which is lower than needed.


1)
{1,-1}
-1

Returns: 1

Here product is -1, it's enough.


2)
{-5,-4,2,3}
-1

Returns: 2

If first pair contains numbers -5 and -4, and second contains 2 and 3, both will have positive product.


3)
{5,-7,8,-2,-5,3}
-7

Returns: 3

Acceptable splitting is {5,8}, {-7,-5} and {-2,3}.


4)
{3,4,5,6,6,-6,-4,-10,-1,-9}
-2

Returns: 4


5)
{1000000,1000000}
-5

Returns: 1

Beware overflow.

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

using namespace std;

typedef long long LL;

class SplitIntoPairs {
public:
	int makepairs(vector <int> A, int X) {
		sort(A.begin(), A.end());
		int ans = 0;
		for (int i = 0; i < (int)A.size(); i += 2) {
			LL p = (LL)A[i] * A[i+1];
			ans += p >= X;
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
			int Arr0[] = {2,-1};
			int Arg1 = -1;
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, makepairs(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,-1};
			int Arg1 = -1;
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, makepairs(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-5,-4,2,3};
			int Arg1 = -1;
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, makepairs(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,-7,8,-2,-5,3};
			int Arg1 = -7;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, makepairs(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,4,5,6,6,-6,-4,-10,-1,-9};
			int Arg1 = -2;
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, makepairs(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000000,1000000};
			int Arg1 = -5;
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, makepairs(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SplitIntoPairs ___test;
	___test.run_test(-1);
}
// END CUT HERE
