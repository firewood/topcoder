// BEGIN CUT HERE
/*
SRM 641 Div1 Easy (250)

PROBLEM STATEMENT
We have chosen a finite set of points in the plane.
You are given their coordinates in the vector <int>s x and y:
for each valid i, there is a point with coordinates (x[i],y[i]).

We are interested in triangles with the following properties:

Each vertex of the triangle is one of our chosen points.
The point (0,0) lies inside the triangle.

Return the number of such triangles.

Note that the constraints guarantee that there are no degenerate triangles and that the point (0,0) never lies on the boundary of a triangle.


DEFINITION
Class:TrianglesContainOrigin
Method:count
Parameters:vector <int>, vector <int>
Returns:long long
Method signature:long long count(vector <int> x, vector <int> y)


CONSTRAINTS
-x and y will contain between 3 and 2500 elements, inclusive.
-x and y will contain the same number of elements.
-Each element of x and y will be between -10,000 and 10,000, inclusive.
-No two points will be the same.
-No three points will be collinear.
-No point will be on the origin.
-There will be no two points P and Q such that P, Q, and the origin are collinear.


EXAMPLES

0)
{-1,-1,1}
{1,-1,0}

Returns: 1

There is exactly one possible triangle. It does contain the origin.


1)
{-1,-1,1,2}
{1,-1,2,-1}

Returns: 2

There are four possible triangles. Two of them contain the origin. One is the triangle with vertices in (-1,1), (-1,-1), and (2,-1). The other is the triangle with vertices in (-1,-1), (1,2), and (2,-1).


2)
{-1,-2,3,3,2,1}
{-2,-1,1,2,3,3}

Returns: 8


3)
{1,5,10,5,-5,7,-9,-6,-3,0,8,8,1,-4,7,-3,10,9,-6}
{5,-6,-3,4,-2,-8,-7,2,7,4,2,0,-4,-8,7,5,-5,-2,-9}

Returns: 256

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

typedef long long LL;

class TrianglesContainOrigin {

public:
	long long count(vector <int> x, vector <int> y) {
		int N = (int)x.size();
		double rad[10000] = {};
		for (int i = 0; i < N; ++i) {
			rad[i] = atan2(x[i], y[i]);
			if (rad[i] < 0) {
				rad[i] += 2.0 * M_PI;
			}
		}
		sort(rad, rad + N);
		for (int i = 0; i < N; ++i) {
			rad[N + i] = rad[i] + 2.0 * M_PI;
		}
		LL ans = 0;
		for (int i = 0; i < N; ++i) {
			size_t a = lower_bound(rad + i, rad + i + N, rad[i] + M_PI) - rad;
			for (int j = i + 1; j < N; ++j) {
				if (rad[j] - rad[i] < M_PI) {
					size_t b = lower_bound(rad + j, rad + i + N, rad[j] + M_PI) - rad;
					if (b > a) {
						ans += b - a;
					}
				}
			}
		}
		return ans / 2;
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
			int Arr0[] = {-1,-1,1};
			int Arr1[] = {1,-1,0};
			long long Arg2 = 1LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1,-1,1,2};
			int Arr1[] = {1,-1,2,-1};
			long long Arg2 = 2LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1,-2,3,3,2,1};
			int Arr1[] = {-2,-1,1,2,3,3};
			long long Arg2 = 8LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,5,10,5,-5,7,-9,-6,-3,0,8,8,1,-4,7,-3,10,9,-6};
			int Arr1[] = {5,-6,-3,4,-2,-8,-7,2,7,4,2,0,-4,-8,7,5,-5,-2,-9};
			long long Arg2 = 256LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TrianglesContainOrigin ___test;
	___test.run_test(-1);
}
// END CUT HERE
