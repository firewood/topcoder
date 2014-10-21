// BEGIN CUT HERE
/*
SRM 614 Div2 Medium (500)

PROBLEM STATEMENT
There are N points in the plane. You are given their description as two vector <int>s, x and y, with N elements each.
The N points have coordinates (x[0],y[0]), (x[1],y[1]), ..., (x[N-1],y[N-1]).

You want to draw a single square onto the plane. The vertices of the square must have integer coordinates,
and the sides of the square must be parallel to the coordinate axes.
Additionally, at least N-2 of the N given points must lie strictly inside the square (i.e., not on its boundary).

Return the smallest possible area of a square that satisfies these constraints.


DEFINITION
Class:MinimumSquareEasy
Method:minArea
Parameters:vector <int>, vector <int>
Returns:long long
Method signature:long long minArea(vector <int> x, vector <int> y)


CONSTRAINTS
-x will contain between 3 and 50 elements, inclusive.
-y will contain the same number of elements as x.
-All points will be pairwise distinct.
-Each element of x will be between -1,000,000,000 and 1,000,000,000, inclusive.
-Each element of y will be between -1,000,000,000 and 1,000,000,000, inclusive.


EXAMPLES

0)
{0, 1, 2}
{0, 1, 5}

Returns: 4

The square must contain at least one of the three given points. One of the optimal solutions is the square with opposite corners at (-1,-1) and (1,1).


1)
{-1, -1, 0, 2, 0}
{-2, -1, 0, -1, -2}

Returns: 9

This time the square must contain at least three of the five given points. The optimal solution is the square with opposite corners at (-2,-3) and (1,0).


2)
{1000000000, -1000000000, 1000000000, -1000000000}
{1000000000, 1000000000, -1000000000, -1000000000}

Returns: 4000000008000000004

In this case one of the optimal solutions is a square that contains all four points.


3)
{93, 34, 12, -11, -7, -21, 51, -22, 59, 74, -19, 29, -56, -95, -96, 9, 44, -37, -54, -21}
{64, 12, -43, 20, 55, 74, -20, -54, 24, 20, -18, 77, 86, 22, 47, -24, -33, -57, 5, 7}

Returns: 22801

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<LL> LLVec;

class MinimumSquareEasy {
public:
	long long minArea(vector <int> x, vector <int> y) {
		int K = (int)x.size() - 2;
		LL ans = 1LL << 62;
		for (int bottom : y) {
			for (int left : x) {
				LLVec d;
				for (int i = 0; i < (int)x.size(); ++i) {
					if (x[i] >= left && y[i] >= bottom) {
						d.push_back(max(x[i] - left, y[i] - bottom) + 2);
					}
				}
				if (d.size() >= K) {
					sort(d.begin(), d.end());
					ans = min(ans, d[K - 1] * d[K - 1]);
				}
			}
		}
		return ans;
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
			int Arr0[] = {0, 1, 2};
			int Arr1[] = {0, 1, 5};
			long long Arg2 = 4LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minArea(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1, -1, 0, 2, 0};
			int Arr1[] = {-2, -1, 0, -1, -2};
			long long Arg2 = 9LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minArea(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000000000, -1000000000, 1000000000, -1000000000};
			int Arr1[] = {1000000000, 1000000000, -1000000000, -1000000000};
			long long Arg2 = 4000000008000000004LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minArea(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {93, 34, 12, -11, -7, -21, 51, -22, 59, 74, -19, 29, -56, -95, -96, 9, 44, -37, -54, -21};
			int Arr1[] = {64, 12, -43, 20, 55, 74, -20, -54, 24, 20, -18, 77, 86, 22, 47, -24, -33, -57, 5, 7};
			long long Arg2 = 22801LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minArea(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MinimumSquareEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
