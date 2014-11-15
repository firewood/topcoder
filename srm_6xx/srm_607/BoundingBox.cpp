// BEGIN CUT HERE
/*
SRM 607 Div2 Easy (250)

PROBLEM STATEMENT
Andrew drew a bunch of points on a sheet of graph paper.
You are given the coordinates of these points in two vector <int>s: X and Y.
That is, for each valid i, there is a point at the coordinates (X[i], Y[i]).

Now Andrew wants to draw a rectangle.
The sides of the rectangle must be parallel to the coordinate axes.
(In other words, each side of the rectangle must be either horizontal or vertical.)
Additionally, each of Andrew's points must be inside the rectangle or on its boundary.

Return the area of the smallest possible rectangle Andrew can draw.


DEFINITION
Class:BoundingBox
Method:smallestArea
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int smallestArea(vector <int> X, vector <int> Y)


CONSTRAINTS
-X will have between 2 and 50 elements, inclusive.
-X and Y will have the same number of elements.
-Each element of X and Y will be between -100 and 100, inclusive.
-The points described by X and Y will not be in a straight line horizontally or vertically. That is, the smallest rectangle will have a positive area.


EXAMPLES

0)
{0,1}
{1,0}

Returns: 1


1)
{0,-2,-1}
{-1,-1,-2}

Returns: 2


2)
{0,0,1,0,-1,2}
{0,1,2,-2,0,-1}

Returns: 12


3)
{9,-88,-40,98,-55,41,-38}
{-65,56,-67,7,-58,33,68}

Returns: 25110

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class BoundingBox {
public:
	int smallestArea(vector <int> X, vector <int> Y) {
		int width = *max_element(X.begin(), X.end()) - *min_element(X.begin(), X.end());
		int height = *max_element(Y.begin(), Y.end()) - *min_element(Y.begin(), Y.end());
		return width * height;
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
			int Arr0[] = {0,1};
			int Arr1[] = {1,0};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, smallestArea(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,-2,-1};
			int Arr1[] = {-1,-1,-2};
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, smallestArea(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,1,0,-1,2};
			int Arr1[] = {0,1,2,-2,0,-1};
			int Arg2 = 12;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, smallestArea(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9,-88,-40,98,-55,41,-38};
			int Arr1[] = {-65,56,-67,7,-58,33,68};
			int Arg2 = 25110;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, smallestArea(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BoundingBox ___test;
	___test.run_test(-1);
}
// END CUT HERE
