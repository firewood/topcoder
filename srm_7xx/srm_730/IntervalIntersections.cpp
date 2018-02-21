// BEGIN CUT HERE
/*
SRM 730 Div2 Easy (250)

PROBLEM STATEMENT

For any x ? y the interval [x,y] contains all real numbers between x and y, inclusive.
The length of the interval [x,y] is y-x.
Two intervals intersect if they have at least one number in common.

You are given the ints x1, y1, x2, and y2.
These are the endpoints of two intervals: [x1,y1] and [x2,y2].
We are looking for an interval [a,b] that intersects both given intervals.
Return the smallest possible length of the interval [a,b].


DEFINITION
Class:IntervalIntersections
Method:minLength
Parameters:int, int, int, int
Returns:int
Method signature:int minLength(int x1, int y1, int x2, int y2)


CONSTRAINTS
-x1,y1,x2,y2 will be between 1 and 10^6, inclusive.
-x1 will be less than or equal to y1.
-x2 will be less than or equal to y2.


EXAMPLES

0)
3
6
1
2

Returns: 1

The two given intervals are [3,6] and [1,2]. The unique shortest interval that intersects both of them is the interval [2,3]. Its length is 3-2 = 1.


1)
1
2
3
6

Returns: 1

The same two intervals as in Example 0, only in different order. The correct return value is the same.


2)
1
10
2
5

Returns: 0

In this test case the optimal length of the interval [a,b] is 0. Examples of such intervals include [2,2] and [4,4].


3)
4
5
1
4

Returns: 0


4)
1
1
1000000
1000000

Returns: 999999

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class IntervalIntersections {
public:
	int minLength(int x1, int y1, int x2, int y2) {
		if (x1 > x2) {
			swap(x1, x2);
			swap(y1, y2);
		}
		return x2 - min(y1, x2);
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
			int Arg0 = 3;
			int Arg1 = 6;
			int Arg2 = 1;
			int Arg3 = 2;
			int Arg4 = 1;

			verify_case(n, Arg4, minLength(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 2;
			int Arg2 = 3;
			int Arg3 = 6;
			int Arg4 = 1;

			verify_case(n, Arg4, minLength(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 10;
			int Arg2 = 2;
			int Arg3 = 5;
			int Arg4 = 0;

			verify_case(n, Arg4, minLength(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 5;
			int Arg2 = 1;
			int Arg3 = 4;
			int Arg4 = 0;

			verify_case(n, Arg4, minLength(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 1000000;
			int Arg3 = 1000000;
			int Arg4 = 999999;

			verify_case(n, Arg4, minLength(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	IntervalIntersections ___test;
	___test.run_test(-1);
}
// END CUT HERE
