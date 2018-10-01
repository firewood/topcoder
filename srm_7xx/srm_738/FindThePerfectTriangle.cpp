// BEGIN CUT HERE
/*
SRM 738 Div1 Easy (250)

PROBLEM STATEMENT

You are given the ints perimeter and area.
Your task is to find a triangle with the following properties:

The coordinates of each vertex are integers between 0 and 3000, inclusive.
The perimeter of the triangle must be exactly perimeter, and its area must be exactly area.

If there are multiple solutions, you may choose any of them.
Return a vector <int> with six elements: {x1, y1, x2, y2, x3, y3}, where (x1, y1), (x2, y2), and (x3, y3) are the coordinates of the vertices of your triangle.
If there is no solution, return an empty vector <int> instead.


DEFINITION
Class:FindThePerfectTriangle
Method:constructTriangle
Parameters:int, int
Returns:vector <int>
Method signature:vector <int> constructTriangle(int area, int perimeter)


CONSTRAINTS
-area will be between 1 and 1,000,000, inclusive.
-perimeter will be between 1 and 1000, inclusive.


EXAMPLES

0)
6
11

Returns: { }

There are no valid triangles with area 6 and perimeter 11.


1)
6
12

Returns: {1, 1, 1, 4, 5, 4 }

The example output describes a right triangle with vertices at (1, 1), (1, 4) and (5, 4).
Its sides have lengths 3, 4, and 5, hence its perimeter is 12.
The area of the triangle is (3*4)/2 = 6.


2)
37128
882

Returns: {137, 137, 273, 410, 1, 410 }


3)
12
18

Returns: {1, 1, 4, 5, 1, 9 }

In this test case our solution constructed an isosceles triangle with vertices at (1, 1), (4, 5) and (1, 9).


4)
18096
928

Returns: {1, 1, 1, 88, 417, 88 }


5)
1000000
1000

Returns: { }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class FindThePerfectTriangle {
public:
	vector <int> constructTriangle(int area, int perimeter) {
		vector<int> xv, yv;
		for (int x = -1000; x <= 1000; ++x) {
			for (int y = -1000; y <= 1000; ++y) {
				int rr = x * x + y * y;
				int r = (int)(sqrt(rr) + 1.0e-10);
				if (rr == r * r) {
					xv.push_back(x);
					yv.push_back(y);
				}
			}
		}
		int sz = (int)xv.size();
		for (int i = 0; i < sz; ++i) {
			int ax = xv[i], ay = yv[i];
			for (int j = 0; j < sz; ++j) {
				int bx = xv[j], by = yv[j];
				if (abs(ax * by - bx * ay) == area * 2) {
					int cx = ax - bx, cy = ay - by;
					double p = sqrt(ax * ax + ay * ay) + sqrt(bx * bx + by * by) + sqrt(cx * cx + cy * cy);
					if (fabs(p - perimeter) <= 1.0e-10) {
						return vector<int>({ 1000, 1000, ax + 1000, ay + 1000, bx + 1000, by + 1000 });
					}
				}
			}
		}
		return vector<int>();
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
			int Arg0 = 6;
			int Arg1 = 11;

			vector <int> Arg2;
			verify_case(n, Arg2, constructTriangle(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 12;
			int Arr2[] = {1, 1, 1, 4, 5, 4 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, constructTriangle(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 37128;
			int Arg1 = 882;
			int Arr2[] = {137, 137, 273, 410, 1, 410 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, constructTriangle(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 12;
			int Arg1 = 18;
			int Arr2[] = {1, 1, 4, 5, 1, 9 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, constructTriangle(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 18096;
			int Arg1 = 928;
			int Arr2[] = {1, 1, 1, 88, 417, 88 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, constructTriangle(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000;
			int Arg1 = 1000;

			vector <int> Arg2;
			verify_case(n, Arg2, constructTriangle(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 420;
			int Arg1 = 150;
			int Arr2[] = { 0,1000,0,1008,21,980 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, constructTriangle(Arg0, Arg1));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FindThePerfectTriangle ___test;
	___test.run_test(-1);
}
// END CUT HERE
