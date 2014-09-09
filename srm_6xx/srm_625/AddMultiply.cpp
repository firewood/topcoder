// BEGIN CUT HERE
/*
SRM 625 Div2 Easy (250)

PROBLEM STATEMENT
You are given an int y.
We are looking for any vector <int> x that satisfies the following constraints:

x has exactly three elements
( x[0] * x[1] ) + x[2] = y
Each x[i] must be between -1000 and 1000, inclusive.
No x[i] can be equal to 0 or 1.

Find and return one such x.

If there are multiple valid solutions, you may return any of them.
You may assume that for our constraints on y (specified below) at least one valid x always exists.

DEFINITION
Class:AddMultiply
Method:makeExpression
Parameters:int
Returns:vector <int>
Method signature:vector <int> makeExpression(int y)


CONSTRAINTS
-y will be between 0 and 500, inclusive.


EXAMPLES

0)
6

Returns: {2, 2, 2 }

2*2 + 2 = 6

Note that this is one of many possible solutions. Another solution is:

3*3 + (-3) = 6


1)
11

Returns: {2, 3, 5 }


2)
0

Returns: {7, 10, -70 }

Note that 0 and 1 are not allowed, thus a result like 0 * 0 + 0 would be incorrect.


3)
500

Returns: {-400, -3, -700 }

Some or all of the returned numbers may be negative.


4)
2

Returns: {2, 2, -2 }


5)
5

Returns: {5, 2, -5 }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class AddMultiply {
public:
	vector <int> makeExpression(int y) {
		vector <int> ans(3);
		for (int i = -40000; i <= 40000; ++i) {
			int a = i / 200, b = abs(i % 200) - 100;
			if (abs(a*b - y) <= 1000) {
				ans[0] = a;
				ans[1] = b;
				ans[2] = y - a*b;
				break;
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) {
		cerr << "Test Case #" << Case << "...";
		if ((Expected[0] * Expected[1] + Expected[2]) == (Received[0] * Received[1] + Received[2]))
			cerr << "PASSED" << endl;
		else { cerr << "FAILED" << endl;
			cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl;
		}
	}

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arr1[] = {2, 2, 2 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, makeExpression(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 11;
			int Arr1[] = {2, 3, 5 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, makeExpression(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arr1[] = {7, 10, -70 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, makeExpression(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 500;
			int Arr1[] = {-400, -3, -700 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, makeExpression(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {2, 2, -2 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, makeExpression(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {5, 2, -5 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, makeExpression(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AddMultiply ___test;
	___test.run_test(-1);
}
// END CUT HERE
