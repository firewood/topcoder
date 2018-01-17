// BEGIN CUT HERE
/*
SRM 727 Div2 Medium (500)

PROBLEM STATEMENT
Bearland can be represented as a horizontal plane with N distinct points, denoting positions of N cities.
The i-th city has coordinates (x[i], y[i]).

Limak is planning to build two infinitely long roads in Bearland.
One should go northwest, and the other should go northeast (both these directions are tilted exactly 45 degrees from the vertical direction).
It implies that the two roads are perpendicular to each other, and that they have an intersection point (this point can be a city but not necessarily).

Roads increase the trade significantly.
A city will be happy if it lies on at least one of the two roads.
Help Limak and find the maximum possible number of happy cities.


DEFINITION
Class:TwoDiagonals
Method:maxPoints
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int maxPoints(vector <int> x, vector <int> y)


CONSTRAINTS
-N will be between 1 and 1000, inclusive.
-x will contain exactly N elements.
-y will contain exactly N elements.
-Each number in x and in y will be between 0 and 999, inclusive.
-Every two cities will be in different points. (No two cities will coincide.)


EXAMPLES

0)
{1, 4, 4, 5}
{3, 0, 2, 3}

Returns: 4

There are four cities: (1,3), (4,0), (4,2), (5,3).
It's possible to draw two lines in such a way that all cities will be happy:


1)
{0, 1, 2, 3, 4, 5}
{2, 2, 2, 2, 2, 2}

Returns: 2

The new roads can go through at most two cities in this case.
One of many optimal placements is:


2)
{2, 2, 3, 3}
{2, 3, 2, 3}

Returns: 4


3)
{10, 0, 15, 9}
{10, 0, 15, 11}

Returns: 4

The two roads should intersect in the point (10, 10).


4)
{273, 100, 999, 789, 105}
{838, 200, 999, 0, 560}

Returns: 2


5)
{0, 2, 0, 2, 1}

{0, 0, 2, 2, 1}

Returns: 5


6)
{500, 503, 501}
{200, 197, 199}

Returns: 3

The positions of cities are collinear and the line going through them is tilted exactly 45 degrees from the vertical direction, so Limak can build a road going through all three cities.
The placement of the other road doesn't matter.


7)
{0, 2, 4}
{0, 3, 6}

Returns: 2

The positions of cities are again collinear, but Limak can't make all of them happy.
This time the line going through the three points isn't tilted exactly 45 degrees from the vertical direction.

The best Limak can do is to build one road going through one of cities, and build the other road to go through one of the remaining two cities.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class TwoDiagonals {
public:
	int maxPoints(vector <int> x, vector <int> y) {
		vector<vector<int> > ao, bo;
		for (int i = -2000; i <= 2000; ++i) {
			vector<int> as, bs;
			for (int j = 0; j < (int)x.size(); ++j) {
				if (y[j] == x[j] + i) {
					as.push_back(j);
				}
				if (y[j] == -x[j] + i) {
					bs.push_back(j);
				}
			}
			if (as.size() > 0) {
				ao.push_back(as);
			}
			if (bs.size() > 0) {
				bo.push_back(bs);
			}
		}
		int ans = 0;
		for (int i = 0; i < (int)ao.size(); ++i) {
			for (int j = 0; j < (int)bo.size(); ++j) {
				vector<int> s = ao[i];
				s.insert(s.end(), bo[j].begin(), bo[j].end());
				sort(s.begin(), s.end());
				ans = max(ans, (int)(unique(s.begin(), s.end()) - s.begin()));
			}
		}
		return ans;
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
			int Arr0[] = {1, 4, 4, 5};
			int Arr1[] = {3, 0, 2, 3};
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxPoints(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 1, 2, 3, 4, 5};
			int Arr1[] = {2, 2, 2, 2, 2, 2};
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxPoints(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 2, 3, 3};
			int Arr1[] = {2, 3, 2, 3};
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxPoints(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 0, 15, 9};
			int Arr1[] = {10, 0, 15, 11};
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxPoints(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {273, 100, 999, 789, 105};
			int Arr1[] = {838, 200, 999, 0, 560};
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxPoints(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 2, 0, 2, 1}
;
			int Arr1[] = {0, 0, 2, 2, 1};
			int Arg2 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxPoints(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {500, 503, 501};
			int Arr1[] = {200, 197, 199};
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxPoints(Arg0, Arg1));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 2, 4};
			int Arr1[] = {0, 3, 6};
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxPoints(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 0 };
			int Arr1[] = { 0 };
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxPoints(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TwoDiagonals ___test;
	___test.run_test(-1);
}
// END CUT HERE
