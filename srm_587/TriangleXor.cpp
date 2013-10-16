// BEGIN CUT HERE
/*
SRM 587 Div1 Medium (550)

PROBLEM STATEMENT

You are given an int W.
There is a rectangle in the XY-plane with corners at (0, 0), (0, 1), (W, 0), and (W, 1).
Let T[x] be the triangle with vertices at (0, 1), (W, 1) and (x, 0).
(All points that lie inside the triangle are a part of T[x] as well.)

The objective in this problem is to calculate the area of the region (T[0] xor T[1] xor ... xor T[W]).
(See Notes for a formal definition.)
The figures below show the region (T[0] xor T[1] xor ... xor T[W]) for W=1,2,3,4,5,6.

Return the integer part of the area of the region.


DEFINITION
Class:TriangleXor
Method:theArea
Parameters:int
Returns:int
Method signature:int theArea(int W)


NOTES
-For sets of points A and B in the XY-plane, the set (A xor B) is defined as the set of all points that lie in exactly one of the sets A and B (i.e., points that belong to the union of A and B but don't belong to their intersection).
-If the exact area is A, the correct return value is floor(A), not round(A). In words: you should return the largest integer that is less than or equal to the exact area.
-The format of the return value was chosen to help you in case of small precision errors. The constraints guarantee that computing the correct area with absolute error less than 0.01 is sufficient to determine the correct return value. The author's solution is significantly more precise than that.


CONSTRAINTS
-W will be between 1 and 70,000, inclusive.
-The difference between the exact area of the region and the nearest integer will be greater than 0.01.


EXAMPLES

0)
1

Returns: 0

The exact area is 0.5.


1)
2

Returns: 1

The area is approximately 1.33333.


2)
3

Returns: 1

The exact area is 1.35.


3)
4

Returns: 2

The area is approximately 2.62857. Note that the correct answer is 2, not 3.


4)
5

Returns: 2

The area is approximately 2.13294.


5)
12345

Returns: 4629

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TriangleXor {
public:
	int theArea(int W) {
		double w = W;
		double sum = w * (w+1) * 0.5;
		double sign = -1.0;
		for (int i = 1; i <= W; ++i) {
			double h = 1.0 - i / (w + i);
			sum += w * h * 0.5 * (w - i + 1) * 2.0 * sign;
			sign = -sign;
		}
		return (int)sum;
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
			int Arg0 = 1;
			int Arg1 = 0;

			verify_case(n, Arg1, theArea(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;

			verify_case(n, Arg1, theArea(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 1;

			verify_case(n, Arg1, theArea(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 2;

			verify_case(n, Arg1, theArea(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 2;

			verify_case(n, Arg1, theArea(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 12345;
			int Arg1 = 4629;

			verify_case(n, Arg1, theArea(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 62678;
			int Arg1 = 39173;

			verify_case(n, Arg1, theArea(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TriangleXor ___test;
	___test.run_test(-1);
}
// END CUT HERE
