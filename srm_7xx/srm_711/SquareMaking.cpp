// BEGIN CUT HERE
/*
SRM 711 Div2 Easy (250)

PROBLEM STATEMENT
You have four sticks.
Their lengths are a, b, c, and d.
There is also a stick altering store.
For one coin they can change (i.e., either increase or decrease) the length of any stick by 1.
You can use the store as many times as you want.

You would like to build a square out of your four sticks.
Therefore, you need four sticks that each have the same length.
Note that the length must be positive.

You are given the ints a, b, c, and d.
Compute and return the smallest number of coins you need to spend at the store.


DEFINITION
Class:SquareMaking
Method:getMinimalPrice
Parameters:int, int, int, int
Returns:int
Method signature:int getMinimalPrice(int a, int b, int c, int d)


CONSTRAINTS
-a will be between 1 and 1,000,000, inclusive.  
-b will be between 1 and 1,000,000, inclusive.  
-c will be between 1 and 1,000,000, inclusive.  
-d will be between 1 and 1,000,000, inclusive.  


EXAMPLES

0)
5
6
5
5

Returns: 1

Here the optimal solution is to pay 1 coin to decrease b by 1.
After the change you will have four equally long sticks.


1)
4
1
5
4

Returns: 4

Here the optimal side length is 4.
Hence, you need to pay the store to increase b three times and to decrease c once.
The total amount spent at the store will therefore be 4 coins.


2)
2017
2017
2017
2017

Returns: 0

Here you do not need to change sticks at all.


3)
705451
751563
608515
994713

Returns: 432310

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SquareMaking {
	public:
	int getMinimalPrice(int a, int b, int c, int d) {
		int m = max(max(a, b), max(c, d));
		int ans = 1 << 30;
		for (int i = 1; i <= m; ++i) {
			int cost = abs(a - i) + abs(b - i) + abs(c - i) + abs(d - i);
			ans = min(ans, cost);
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
			int Arg0 = 5;
			int Arg1 = 6;
			int Arg2 = 5;
			int Arg3 = 5;
			int Arg4 = 1;

			verify_case(n, Arg4, getMinimalPrice(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 1;
			int Arg2 = 5;
			int Arg3 = 4;
			int Arg4 = 4;

			verify_case(n, Arg4, getMinimalPrice(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2017;
			int Arg1 = 2017;
			int Arg2 = 2017;
			int Arg3 = 2017;
			int Arg4 = 0;

			verify_case(n, Arg4, getMinimalPrice(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 705451;
			int Arg1 = 751563;
			int Arg2 = 608515;
			int Arg3 = 994713;
			int Arg4 = 432310;

			verify_case(n, Arg4, getMinimalPrice(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SquareMaking ___test;
	___test.run_test(-1);
}
// END CUT HERE
