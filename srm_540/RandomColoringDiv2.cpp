// BEGIN CUT HERE
/*
// SRM 540 Div2 Easy (250)

// PROBLEM STATEMENT
// Little Arthur has a new frisbee and he would like to color it.
A frisbee has the shape of a disc. Arthur will color the disc using two colors:
one for the top side, one for the bottom side.

Each color is defined by three integer components: R, G, and B (meaning red,
green, and blue, respectively), where 0 <= R < maxR, 0 <= G < maxG, and 0 <= B < maxB.
It is known that Arthur can use any of the maxR*maxG*maxB possible colors.

Arthur is going to perform the coloring in the following way:

In the first step, he will color the top side of the frisbee using the color
(startR, startG, startB).
In the second step, he will color the bottom side of the frisbee using a color
that makes a good transition from the first color. (This is explained below.)


A transition from color (R, G, B) to color (R', G', B') is called good if all
components differ by at most d2 units (formally, |R - R'| <= d2, |G - G'| <= d2,
|B - B'| <= d2) and at least one component differs by at least d1 units (formally,
at least one of the conditions |R - R'| >= d1, |G - G'| >= d1, |B - B'| >= d1 holds).
Intuitively, a transition between two colors is called good if they are neither
too similar, nor too different.

After coloring the top side Arthur is wondering how many different options
there are now for the color of the bottom side of the frisbee.

Given ints maxR, maxG, maxB, startR, startG, startB, d1, and d2, return the
number of valid colors that make a good transition from the color (startR, startG, startB).

DEFINITION
Class:RandomColoringDiv2
Method:getCount
Parameters:int, int, int, int, int, int, int, int
Returns:int
Method signature:int getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2)


CONSTRAINTS
-maxR, maxG and maxB will each be between 1 and 100, inclusive.
-startR will be between 0 and maxR-1, inclusive.
-startG will be between 0 and maxG-1, inclusive.
-startB will be between 0 and maxB-1, inclusive.
-d1 and d2 will each be between 0 and 100, inclusive.
-d1 will be less than or equal to d2.


EXAMPLES

0)
5
1
1
2
0
0
0
1

Returns: 3

Only the R component can change here. It has to change by at least 0 and at most 1.
Thus the colors that make a good transition from color (2, 0, 0) here are (1, 0, 0), (2, 0, 0), and (3, 0, 0).


1)
4
2
2
0
0
0
3
3

Returns: 4

Colors that make a good transition from color (0, 0, 0) here are (3, 0, 0), (3, 0, 1), (3, 1, 0), and (3, 1, 1).


2)
4
2
2
0
0
0
5
5

Returns: 0

At least one component has to change by 5. There exists no color that makes
a good transition from color (0, 0, 0) within the respective maxR, maxG, maxB constraints.


3)
6
9
10
1
2
3
0
10

Returns: 540

All valid colors make a good transition from color (1, 2, 3).


4)
6
9
10
1
2
3
4
10

Returns: 330


5)
49
59
53
12
23
13
11
22

Returns: 47439

*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

class RandomColoringDiv2 {

public:
	int getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) {

		int result;
		{
			int rs = max(0, startR - d2);
			int re = min(maxR - 1, startR + d2);
			int gs = max(0, startG - d2);
			int ge = min(maxG - 1, startG + d2);
			int bs = max(0, startB - d2);
			int be = min(maxB - 1, startB + d2);
			result = (re - rs + 1) * (ge - gs + 1) * (be - bs + 1);
		}
		if (d1 > 0) {
			--d1;
			int rs = max(0, startR - d1);
			int re = min(maxR - 1, startR + d1);
			int gs = max(0, startG - d1);
			int ge = min(maxG - 1, startG + d1);
			int bs = max(0, startB - d1);
			int be = min(maxB - 1, startB + d1);
			result -= (re - rs + 1) * (ge - gs + 1) * (be - bs + 1);
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
			int Arg0 = 5;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 2;
			int Arg4 = 0;
			int Arg5 = 0;
			int Arg6 = 0;
			int Arg7 = 1;
			int Arg8 = 3;

			verify_case(n, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 2;
			int Arg2 = 2;
			int Arg3 = 0;
			int Arg4 = 0;
			int Arg5 = 0;
			int Arg6 = 3;
			int Arg7 = 3;
			int Arg8 = 4;

			verify_case(n, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 2;
			int Arg2 = 2;
			int Arg3 = 0;
			int Arg4 = 0;
			int Arg5 = 0;
			int Arg6 = 5;
			int Arg7 = 5;
			int Arg8 = 0;

			verify_case(n, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 9;
			int Arg2 = 10;
			int Arg3 = 1;
			int Arg4 = 2;
			int Arg5 = 3;
			int Arg6 = 0;
			int Arg7 = 10;
			int Arg8 = 540;

			verify_case(n, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 9;
			int Arg2 = 10;
			int Arg3 = 1;
			int Arg4 = 2;
			int Arg5 = 3;
			int Arg6 = 4;
			int Arg7 = 10;
			int Arg8 = 330;

			verify_case(n, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 49;
			int Arg1 = 59;
			int Arg2 = 53;
			int Arg3 = 12;
			int Arg4 = 23;
			int Arg5 = 13;
			int Arg6 = 11;
			int Arg7 = 22;
			int Arg8 = 47439;

			verify_case(n, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 100;
			int Arg2 = 100;
			int Arg3 = 99;
			int Arg4 = 0;
			int Arg5 = 0;
			int Arg6 = 1;
			int Arg7 = 100;
			int Arg8 = 999999;

			verify_case(n, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RandomColoringDiv2 ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
