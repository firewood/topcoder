// BEGIN CUT HERE
/*
SRM 614 Div1 Easy (250)

PROBLEM STATEMENT
There are N points in the plane. You are given their description as two vector <int>s, x and y, with N elements each. The N points have coordinates (x[0],y[0]), (x[1],y[1]), ..., (x[N-1],y[N-1]).

You want to draw a single square onto the plane. The vertices of the square must have integer coordinates, and the sides of the square must be parallel to the coordinate axes. There is one additional constraint: at least K of the N given points must lie strictly inside the square (i.e., not on its boundary).

You are given x, y, and the int K. Return the smallest possible area of a square that satisfies the constraints above.


DEFINITION
Class:MinimumSquare
Method:minArea
Parameters:vector <int>, vector <int>, int
Returns:long long
Method signature:long long minArea(vector <int> x, vector <int> y, int K)


CONSTRAINTS
-x will contain between 2 and 100 elements, inclusive.
-y will contain the same number of elements as x.
-K will be between 1 and the number of elements in x, inclusive.
-All points will be pairwise distinct.
-Each element of x will be between -1,000,000,000 and 1,000,000,000, inclusive.
-Each element of y will be between -1,000,000,000 and 1,000,000,000, inclusive.


EXAMPLES

0)
{0, 3}
{0, 7}
2

Returns: 81

The square we seek must contain both given points. One optimal solution is the square with opposite corners at (-1,-1) and (8,8).


1)
{-4, 3, 1}
{3 , -1, -2}
2

Returns: 16

2)
{0, 0, 1, 1, 2, 2}
{0, 1, 0, 1, 0, 1}
4

Returns: 9


3)
{1000000000, 1000000000, 1000000000, -1000000000, -1000000000, -1000000000}
{1000000000, 0, -1000000000, 1000000000, 0, -1000000000}
3

Returns: 4000000008000000004

In this case one of the optimal solutions is a square that contains all six points.


4)
{-47881, 28623, 1769, -38328, -16737, 16653, -23181, 37360, 41429, 26282, 254, 728, 8299, -41080, -29498, 17488, -23937, -11, 33319, 25232}
{-46462, 48985, -43820, -19587, -33593, -28337, 13667, -48131, -5568, -2332, -41918, -31370, -3695, 42599, -37788, -40096, 39049, 25045, -2122, 3874}
8

Returns: 1695545329

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;

class MinimumSquare {
public:
	long long minArea(vector <int> x, vector <int> y, int K) {
		LL ans = 1LL << 62;
		IntVec h = x, v = y;
		sort(h.begin(), h.end());
		sort(v.begin(), v.end());
		for (int bottom : v) {
			for (int left : h) {
				IntVec d;
				for (int i = 0; i < (int)x.size(); ++i) {
					if (x[i] >= left && y[i] >= bottom) {
						d.push_back(max(x[i] - left, y[i] - bottom));
					}
				}
				if (d.size() >= K) {
					sort(d.begin(), d.end());
					LL a = d[K - 1] + 2;
					ans = min(ans, a * a);
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
			int Arr0[] = {0, 3};
			int Arr1[] = {0, 7};
			int Arg2 = 2;
			long long Arg3 = 81LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minArea(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-4, 3, 1};
			int Arr1[] = {3 , -1, -2};
			int Arg2 = 2;
			long long Arg3 = 16LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minArea(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 1, 1, 2, 2};
			int Arr1[] = {0, 1, 0, 1, 0, 1};
			int Arg2 = 4;
			long long Arg3 = 9LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minArea(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000000000, 1000000000, 1000000000, -1000000000, -1000000000, -1000000000};
			int Arr1[] = {1000000000, 0, -1000000000, 1000000000, 0, -1000000000};
			int Arg2 = 3;
			long long Arg3 = 4000000008000000004LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minArea(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-47881, 28623, 1769, -38328, -16737, 16653, -23181, 37360, 41429, 26282, 254, 728, 8299, -41080, -29498, 17488, -23937, -11, 33319, 25232};
			int Arr1[] = {-46462, 48985, -43820, -19587, -33593, -28337, 13667, -48131, -5568, -2332, -41918, -31370, -3695, 42599, -37788, -40096, 39049, 25045, -2122, 3874};
			int Arg2 = 8;
			long long Arg3 = 1695545329LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minArea(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MinimumSquare ___test;
	___test.run_test(-1);
}
// END CUT HERE
