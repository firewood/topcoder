// BEGIN CUT HERE
/*
SRM 667 Div2 Easy (250)

PROBLEM STATEMENT

You are given two distinct points A and B in the two-dimensional plane.
Your task is to find any point C with the following properties:

C is different from A and B.
Each coordinate of C is an integer between -100 and 100, inclusive.
The distance between A and C is strictly greater than the distance between B and C.

You are given four ints: x1, y1, x2, and y2.
Point A has coordinates (x1,y1) and point B has coordinates (x2,y2).
Find the coordinates (x3,y3) of one possible point C with the above properties.
Return these coordinates as a vector <int> with two elements: element 0 is x3 and element 1 is y3.
In other words, return the vector <int> {x3,y3}.

For the constraints given below it is guaranteed that a valid point C always exists.
If there are multiple solutions, return any of them.


DEFINITION
Class:PointDistance
Method:findPoint
Parameters:int, int, int, int
Returns:vector <int>
Method signature:vector <int> findPoint(int x1, int y1, int x2, int y2)


NOTES
-In this problem we consider the standard Euclidean distance. Formally, the distance between points (xi,yi) and (xj,yj) is defined as sqrt( (xi-xj)^2 + (yi-yj)^2 ).


CONSTRAINTS
-x1,y1,x2,y2 will be between -50 and 50, inclusive.
-(x1,y1) will be different from (x2,y2).


EXAMPLES

0)
-1
0
1
0

Returns: {8, 48 }

In this example, point A is at (-1,0) and point B is at (1,0).
Almost any point with a positive x-coordinate will be a valid answer.
For example, your program can also return {100,100}, {2,0}, or {9,-100}.
Note that you cannot return {1,0} because point C must not be the same as point B.


1)
1
1
-1
-1

Returns: {25, -63 }

(x1,y1) is (1,1) and (x2,y2) is (-1,-1).


2)
0
1
2
3

Returns: {41, 65 }


3)
5
-4
-2
5

Returns: {68, 70 }


4)
-50
-50
50
-50

Returns: {67, 4 }


5)
-50
50
-49
49

Returns: {73, -25 }

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

class PointDistance {
public:
	vector <int> findPoint(int x1, int y1, int x2, int y2) {
		vector <int> ans(2);
		for (int y = -100; y <= 100; ++y) {
			if (y == y1 || y == y2) {
				continue;
			}
			for (int x = -100; x <= 100; ++x) {
				if (x == x1 || x == x2) {
					continue;
				}
				int r1 = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
				int r2 = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y);
				if (r1 > r2) {
					ans[0] = x;
					ans[1] = y;
					return ans;
				}
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = -1;
			int Arg1 = 0;
			int Arg2 = 1;
			int Arg3 = 0;
			int Arr4[] = {8, 48 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, findPoint(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = -1;
			int Arg3 = -1;
			int Arr4[] = {25, -63 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, findPoint(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 1;
			int Arg2 = 2;
			int Arg3 = 3;
			int Arr4[] = {41, 65 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, findPoint(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = -4;
			int Arg2 = -2;
			int Arg3 = 5;
			int Arr4[] = {68, 70 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, findPoint(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = -50;
			int Arg1 = -50;
			int Arg2 = 50;
			int Arg3 = -50;
			int Arr4[] = {67, 4 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, findPoint(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = -50;
			int Arg1 = 50;
			int Arg2 = -49;
			int Arg3 = 49;
			int Arr4[] = {73, -25 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, findPoint(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PointDistance ___test;
	___test.run_test(-1);
}
// END CUT HERE
