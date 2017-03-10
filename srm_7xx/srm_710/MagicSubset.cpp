// BEGIN CUT HERE
/*
SRM 710 Div2 Easy (250)

PROBLEM STATEMENT
You are given n stones labeled from 0 to n-1.
Each stone has an integer value: the value of stone i is value[i].
Note that some of those values may be negative or zero.

You would like to choose a subset of stones such that the sum of their values is maximized.
(You are allowed to choose the empty subset. In that case, the sum of the values of the chosen stones is zero.)

This would be an easy problem, but there is a catch: the stone labeled 0 has magical properties.
If you include this stone into your chosen subset, its entire sum is multiplied by -1.
(The value of stone 0 still contributes to the sum. See Example 1.)

You are given the vector <int> value containing n elements: the values of your stones.
Find and return the maximum sum of a subset of stones, given that the sum of any subset that contains stone 0 is negated.


DEFINITION
Class:MagicSubset
Method:findBest
Parameters:vector <int>
Returns:int
Method signature:int findBest(vector <int> values)


NOTES
-The value of n is not given explicitly. Instead, you can determine it as the number of elements in value."


CONSTRAINTS
-value will contain between 1 and 50 elements, inclusive.
-Each element of value will be between -100 and 100, inclusive.


EXAMPLES

0)
{1,10,4,-6,3}

Returns: 17

There are five stones.
The magic stone 0 has value 1.
In this case, it is optimal to ignore the magic stone and to choose only the stones labeled 1, 2, and 4.
The sum of their values is 10 + 4 + 3 = 17.


1)
{3,-5,1,-6}

Returns: 8

In this case the optimal choice is to take the stones labeled 0, 1, and 3.
The sum of their values is 3 + (-5) + (-6) = -8.
However, since we included the magic stone 0, we have to multiply this sum by -1, getting the final value (-8) * (-1) = 8.


2)
{0,0,0,0,0,0,0,0,0}

Returns: 0

Stones can also have value 0.


3)
{-100}

Returns: 100


4)
{100}

Returns: 0

In this case, we don't take any stones.


5)
{-3,1,-4,1,5,-9,2,6,-5,3,5}

Returns: 23

*/
// END CUT HERE
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class MagicSubset {
	public:
	int findBest(vector <int> values) {
		int ans = 0, neg = values[0];
		for (int i = 1; i < (int)values.size(); ++i) {
			if (values[i] > 0) {
				ans += values[i];
			} else {
				neg += values[i];
			}
		}
		return max(ans, -neg);
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
			int Arr0[] = {1,10,4,-6,3};
			int Arg1 = 17;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findBest(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,-5,1,-6};
			int Arg1 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findBest(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,0,0,0,0,0,0,0};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findBest(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-100};
			int Arg1 = 100;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findBest(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findBest(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-3,1,-4,1,5,-9,2,6,-5,3,5};
			int Arg1 = 23;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findBest(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicSubset ___test;
	___test.run_test(-1);
}
// END CUT HERE
