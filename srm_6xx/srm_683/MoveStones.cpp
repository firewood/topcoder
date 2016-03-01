// BEGIN CUT HERE
/*
SRM 683 Div1 Easy (250)

PROBLEM STATEMENT

There are n piles of stones arranged around a circle.
The piles are numbered 0 through n-1, in order.
In other words: 
For each valid i, piles i and i+1 are adjacent.
Piles 0 and n-1 are also adjacent.

You are given two vector <int>s a and b, each with n elements.
For each i, a[i] is the current number of stones in pile i, and b[i] is the desired number of stones for this pile.
You want to move some stones to create the desired configuration.
In each step you can take any single stone from any pile and move the stone to any adjacent pile.
Find and return the smallest number of steps needed to create the desired configuration, or -1 if the desired distribution of stones cannot be reached.


DEFINITION
Class:MoveStones
Method:get
Parameters:vector <int>, vector <int>
Returns:long long
Method signature:long long get(vector <int> a, vector <int> b)


NOTES
-At any moment during the game some piles may be empty. Empty piles still remain in place. For example, if pile 5 is empty, you are not allowed to move a stone from pile 4 directly to pile 6 in a single step. Instead, you must place the stone onto the empty pile 5 first.


CONSTRAINTS
-n will be between 1 and 1000, inclusive.
-a will have exactly n elements.
-b will have exactly n elements.
-Each element of a and b will be between 0 and 10^9, inclusive.


EXAMPLES

0)
{12}
{12}

Returns: 0

The desired configuration is the same as the initial configuration.
No steps are needed.


1)
{10}
{9}

Returns: -1

We cannot add or remove stones, we can only move them around the circle.


2)
{0, 5}
{5, 0}

Returns: 5


3)
{1, 2, 3}
{3, 1, 2}

Returns: 2

Move one stone from pile 1 to pile 0 and another stone from pile 2 to pile 0.


4)
{1, 0, 1, 1, 0}

{0, 3, 0, 0, 0}

Returns: 4


5)
{1000000000, 0, 0, 0, 0, 0}
{0, 0, 0, 1000000000, 0, 0}

Returns: 3000000000

Watch out for integer overflow.

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;
typedef vector<LL> LLVec;

class MoveStones {
public:
	long long get(vector <int> a, vector <int> b) {
		if (a == b) {
			return 0;
		}
		if (accumulate(a.begin(), a.end(), 0LL) != accumulate(b.begin(), b.end(), 0LL)) {
			return -1;
		}
		int N = (int)a.size();
		LLVec v(N + 1);
		for (int i = 0; i < N; ++i) {
			v[i + 1] = v[i] + a[i] - b[i];
		}
		v.erase(v.begin());
		sort(v.begin(), v.end());
		LL m = v[N / 2];
		LL ans = 0;
		for (LL c : v) {
			ans += abs(c - m);
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {12};
			int Arr1[] = {12};
			long long Arg2 = 0LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10};
			int Arr1[] = {9};
			long long Arg2 = -1LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 5};
			int Arr1[] = {5, 0};
			long long Arg2 = 5LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3};
			int Arr1[] = {3, 1, 2};
			long long Arg2 = 2LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 0, 1, 1, 0}
;
			int Arr1[] = {0, 3, 0, 0, 0};
			long long Arg2 = 4LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000000000, 0, 0, 0, 0, 0};
			int Arr1[] = {0, 0, 0, 1000000000, 0, 0};
			long long Arg2 = 3000000000LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2 };
			;
			int Arr1[] = { 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0 };
			long long Arg2 = 5LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

	}


// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MoveStones ___test;
	___test.run_test(-1);
}
// END CUT HERE
