// BEGIN CUT HERE
/*
SRM 683 Div2 Medium (500)

PROBLEM STATEMENT

There are n piles of stones arranged in a line.
The piles are numbered 0 through n-1, in order.
In other words, for each valid i, piles i and i+1 are adjacent.

You are given two vector <int>s a and b, each with n elements.
For each i, a[i] is the current number of stones in pile i, and b[i] is the desired number of stones for this pile.
You want to move some stones to create the desired configuration.
In each step you can take any single stone from any pile and move the stone to any adjacent pile.
Find and return the smallest number of steps needed to create the desired configuration, or -1 if the desired distribution of stones cannot be reached.


DEFINITION
Class:MoveStonesEasy
Method:get
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int get(vector <int> a, vector <int> b)


NOTES
-At any moment during the game some piles may be empty. Empty piles still remain in place. For example, if pile 5 is empty, you are not allowed to move a stone from pile 4 directly to pile 6 in a single step. Instead, you must place the stone onto the empty pile 5 first.


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-a will have exactly n elements.
-b will have exactly n elements.
-Each element of a and b will be between 0 and 1,000,000 (10^6), inclusive.


EXAMPLES

0)
{1, 2}
{2, 1}

Returns: 1

We need to move one stone from pile 1 to pile 0.


1)
{10, 0}
{0, 10}

Returns: 10


2)
{0, 0, 1}
{1, 0, 0}

Returns: 2

Note that in a single step we can only move a stone between adjacent piles. 
Hence, we need two steps to move a stone from pile 2 to pile 0.


3)
{12, 12}
{12, 12}

Returns: 0

The desired configuration of stones is the same as the current configuration.
No steps necessary.


4)
{5}
{6}

Returns: -1

We cannot add or remove stones, we can only move them between piles.


5)
{3,10,0,4,0,0,0,1,0}
{5,5,0,7,0,0,0,0,1}

Returns: 9

  Move 2 stones from pile 1 to pile 0.
  Move 3 stones from pile 1 to pile 2.
  Move 3 stones from pile 2 to pile 3.
  Move 1 stone between two last piles.

The total number of steps is 2 + 3 + 3 + 1 = 9.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class MoveStonesEasy {
public:
	int get(vector <int> a, vector <int> b) {
		int ans = 0;
		a.push_back(0);
		b.push_back(0);
		for (int i = 0; i != a.size() - 1; ++i) {
			int d = a[i] - b[i];
			a[i + 1] += d;
			ans += abs(d);
		}
		return a.back() == 0 ? ans : -1;
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
			int Arr0[] = {1, 2};
			int Arr1[] = {2, 1};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 0};
			int Arr1[] = {0, 10};
			int Arg2 = 10;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 1};
			int Arr1[] = {1, 0, 0};
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {12, 12};
			int Arr1[] = {12, 12};
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5};
			int Arr1[] = {6};
			int Arg2 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,10,0,4,0,0,0,1,0};
			int Arr1[] = {5,5,0,7,0,0,0,0,1};
			int Arg2 = 9;

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
	MoveStonesEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
