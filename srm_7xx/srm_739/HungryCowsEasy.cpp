// BEGIN CUT HERE
/*
SRM 739 Div2 Easy (250)

PROBLEM STATEMENT
There are several hungry cows and several barns, all located on the same straight line. All barns are located at distinct postitions.
You are given the coordinates of the cows in the vector <int> cowPositions and the coordinates of barns in the vector <int> barnPositions. In particular, the i-th element of cowPositions is the coordinate of the i-th cow, and the i-th element of barnPositions is the coordinate of the i-th barn. (Both cows and barns are numbered starting from zero.)
Each cow will go to the nearest barn to have dinner. If two barns have the same smallest distance from a cow, the cow will choose the barn with the smaller coordinate. Multiple cows can have dinner in the same barn.
Which barn will each cow go to? Return a vector <int> with as many elements as there are cows. For each i, the i-th element of the return value should be the number of the barn where the i-th cow will go.


DEFINITION
Class:HungryCowsEasy
Method:findFood
Parameters:vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> findFood(vector <int> cowPositions, vector <int> barnPositions)


CONSTRAINTS
-cowPositions will contain between 1 and 50 elements, inclusive.
-Each element of cowPositions will be between -1,000,000,000 and 1,000,000,000, inclusive.
-barnPositions will contain between 1 and 50 elements, inclusive.
-Each element of barnPositions will be between -1,000,000,000 and 1,000,000,000, inclusive.
-All elements of barnPositions will be distinct.


EXAMPLES

0)
{0}
{-5, 5}

Returns: {0 }

There is a single cow located at coordinate 0 and two barns at coordinates -5 and 5, respectively. They are both at the same distance from the cow, so the cow will choose the one with the smaller coordinate, which is -5. Thus, cow 0 will have its dinner in barn 0.


1)
{7, 7}
{7, 10000}

Returns: {0, 0 }

There are two barns: barn 0 at coordinate 7 and barn 1 at coordinate 10000. Both cows are currently at the location of barn 0, and therefore both of them will have their dinner there. (Recall that multiple cows can share the same barn at dinnertime.)


2)
{2, 6, 0, 4, 8}
{3, -1, 5, 1, 7}

Returns: {3, 2, 1, 0, 4 }

Note that the coordinates of cows and barns are not necessarily sorted.

The correct return value describes the following outcome:

Cow 0 (coordinate=2) will eat its dinner in barn 3 (coordinate=1).
Cow 1 (coordinate=6) will eat its dinner in barn 2 (coordinate=5).
Cow 2 (coordinate=0) will eat its dinner in barn 1 (coordinate=-1).
Cow 3 (coordinate=4) will eat its dinner in barn 0 (coordinate=3).
Cow 4 (coordinate=8) will eat its dinner in barn 4 (coordinate=7).

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class HungryCowsEasy {
public:
	vector <int> findFood(vector <int> cowPositions, vector <int> barnPositions) {
		int n = (int)cowPositions.size();
		vector <int> ans(n);
		for (int i = 0; i < n; ++i) {
			int m = 1 << 30;
			for (int j = 0; j < (int)barnPositions.size(); ++j) {
				int d = abs(cowPositions[i] - barnPositions[j]);
				if (d < m || (d == m && barnPositions[j] < barnPositions[ans[i]])) {
					ans[i] = j;
					m = d;
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
			int Arr0[] = {0};
			int Arr1[] = {-5, 5};
			int Arr2[] = {0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findFood(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7, 7};
			int Arr1[] = {7, 10000};
			int Arr2[] = {0, 0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findFood(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 6, 0, 4, 8};
			int Arr1[] = {3, -1, 5, 1, 7};
			int Arr2[] = {3, 2, 1, 0, 4 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findFood(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	HungryCowsEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
