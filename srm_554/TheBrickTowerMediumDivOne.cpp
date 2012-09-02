// BEGIN CUT HERE
/*
// SRM 554 Div1 Medium (500)

// PROBLEM STATEMENT
// 
John and Brus just built some towers using toy bricks.
They now have n towers numbered 0 through n-1.
For each i, the height of the i-th tower (0-based index) is given in heights[i].

John and Brus want to arrange their towers into a line.
That is, the bottoms of the towers will all stand on the same line.
John and Brus don't like it when a tower falls down and knocks over another tower while falling.
To avoid this, they have to put their towers sufficiently far apart.
More precisely, the distance between any two neighboring towers must be at least equal to the maximum of their heights.
John and Brus would like to minimize the distance between the first and the last tower in the line.

You are given the vector <int> heights.
Return a vector <int> containing exactly n elements: the order in which the towers should be placed on the line.
For each i, the i-th element of the return value should be the number of the tower that will be placed i-th on the line.
If there is a tie (multiple solutions give the same minimal distance), return the lexicographically smallest order.


DEFINITION
Class:TheBrickTowerMediumDivOne
Method:find
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> find(vector <int> heights)


NOTES
-A vector <int> A is lexicographically smaller than a vector <int> B
 if it contains a smaller element at the first position where these vector <int>s differ.


CONSTRAINTS
-heights will contain between 1 and 47 elements, inclusive.
-Each element of heights will be between 1 and 47 inclusive.


EXAMPLES

0)
{4, 7, 5}

Returns: {0, 2, 1 }

There are six possible orderings, but only four of them have optimal distance 12 between the first and the last towers:

{0, 2, 1}
{1, 0, 2}
{1, 2, 0}
{2, 0, 1}

Among these ordirings {0, 2, 1} is the lexicographically smallest one.


1)
{4, 4, 4, 4, 4, 4, 4}

Returns: {0, 1, 2, 3, 4, 5, 6 }

Towers may have equal heights.


2)
{2, 3, 3, 2}

Returns: {0, 3, 1, 2 }

Towers of height 2 have to be neighboring in the optimal ordering.


3)
{13, 32, 38, 25, 43, 47, 6}

Returns: {0, 6, 3, 1, 2, 4, 5 }

*/
// END CUT HERE
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

typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef vector<II> IIVec;

class TheBrickTowerMediumDivOne {

public:
	vector <int> find(vector <int> heights) {
		int sz = (int)heights.size();
		IIVec x, y;
		int i, j;
		for (i = 0; i < sz; ++i) {
			x.push_back(II(heights[i], i));
		}
		y.push_back(x[0]);
		x.erase(x.begin());
		while (!x.empty()) {
			i = 0;
			int mincost = max(y.back().first, x[i].first);
			for (j = 1; j < (int)x.size(); ++j) {
				int cost = max(y.back().first, x[j].first);
				if (cost < mincost) {
					i = j;
					mincost = cost;
				}
			}
			y.push_back(x[i]);
			x.erase(x.begin() + i);
		}
		IntVec res(sz);
		for (i = 0; i < sz; ++i) {
			res[i] = y[i].second;
		}
		return res;
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
			int Arr0[] = {4, 7, 5};
			int Arr1[] = {0, 2, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 4, 4, 4, 4, 4, 4};
			int Arr1[] = {0, 1, 2, 3, 4, 5, 6 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 3, 3, 2};
			int Arr1[] = {0, 3, 1, 2 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {13, 32, 38, 25, 43, 47, 6};
			int Arr1[] = {0, 6, 3, 1, 2, 4, 5 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			int Arr1[] = {0};

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,3,4,7,1,2,6};
			int Arr1[] = {0,1,4,5,2,6,3};

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheBrickTowerMediumDivOne ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
