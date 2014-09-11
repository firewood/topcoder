// BEGIN CUT HERE
/*
SRM 623 Div2 Easy (250)

// PROBLEM STATEMENT
// One of the modes in the game "osu!" is called "catch the beat".
In this mode, you control a character that catches falling fruit.

The game is played in the vertical plane.
For simplicity, we will assume that both your character and all pieces of fruit are points in that plane.

You start the game at the coordinates (0, 0).
Your character can only move along the x-axis.
The maximum speed of your character is 1 unit of distance per second.
For example, you need at least 3 seconds to move from (-2, 0) to (1, 0).

You are given vector <int>s x and y that contain initial coordinates of the fruit you should catch:
for each valid i, there is one piece of fruit that starts at (x[i], y[i]).
All pieces of fruit fall down with constant speed of 1 unit of distance per second.
That is, a fruit currently located at (xf, yf) will move to (xf, yf-t) in t seconds.

You will catch a fruit if the character is located at the same point as the fruit at some moment in time.
Can you catch all the fruit in the game?
Return "Able to catch" (quotes for clarity) if you can, and "Not able to catch" otherwise.


DEFINITION
Class:CatchTheBeatEasy
Method:ableToCatchAll
Parameters:vector <int>, vector <int>
Returns:string
Method signature:string ableToCatchAll(vector <int> x, vector <int> y)


CONSTRAINTS
-x will contain between 1 and 50 elements, inclusive.
-x and y will contain the same number of elements.
-The elements in x will be between -1,000 and 1,000, inclusive.
-The elements in y will be between 0 and 1,000, inclusive.


EXAMPLES

0)
{-1, 1, 0}
{1, 3, 4}

Returns: "Able to catch"

In order to catch all three pieces of fruit, you have to follow this schedule (always walking at 1 unit per second):

Walk left for 1 second. When you reach (-1,0), catch the fruit that started at (-1,1).
Walk right for 2 seconds. When you reach (1,0), catch the fruit that started at (1,3).
Walk left for 1 second. When you reach (0,0), catch the fruit that started at (0,4).


1)
{-3}
{2}

Returns: "Not able to catch"

The only piece of fruit cannot be caught.
Even if you start moving left immediately, you will only reach (-2,0) by the time the fruit crosses the y axis.


2)
{-1, 1, 0}
{1, 2, 4}

Returns: "Not able to catch"


3)
{0, -1, 1}
{9, 1, 3}

Returns: "Able to catch"

You can catch the pieces of fruit in any order.
Also note that sometimes you'll want to move slower or wait at some location.
For example, after catching the pieces of fruit that started at (-1,1) and (1,3), you can walk to (0,0) and wait there for the third piece.


4)
{70,-108,52,-70,84,-29,66,-33}
{141,299,402,280,28,363,427,232}

Returns: "Not able to catch"


5)
{-175,-28,-207,-29,-43,-183,-175,-112,-183,-31,-25,-66,-114,-116,-66}
{320,107,379,72,126,445,318,255,445,62,52,184,247,245,185}

Returns: "Able to catch"


6)
{0,0,0,0}
{0,0,0,0}

Returns: "Able to catch"

Different pieces of fruit may share the same position.
You can catch all the pieces at the same time.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> IIVec;

class CatchTheBeatEasy {

	bool can(vector <int> x, vector <int> y) {
		int N = (int)x.size();
		IIVec v;
		for (int i = 0; i < N; ++i) {
			v.push_back(II(y[i], x[i]));
		}
		sort(v.begin(), v.end());
		int cx = 0, cy = 0;
		for (int i = 0; i < N; ++i) {
			int t = v[i].first - cy;
			int d = abs(v[i].second - cx);
			if (d > t) {
				return false;
			}
			cx = v[i].second;
			cy = v[i].first;
		}
		return true;
	}

public:
	string ableToCatchAll(vector <int> x, vector <int> y) {
		return can(x, y) ? "Able to catch" : "Not able to catch";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1, 1, 0};
			int Arr1[] = {1, 3, 4};
			string Arg2 = "Able to catch";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ableToCatchAll(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-3};
			int Arr1[] = {2};
			string Arg2 = "Not able to catch";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ableToCatchAll(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1, 1, 0};
			int Arr1[] = {1, 2, 4};
			string Arg2 = "Not able to catch";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ableToCatchAll(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, -1, 1};
			int Arr1[] = {9, 1, 3};
			string Arg2 = "Able to catch";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ableToCatchAll(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {70,-108,52,-70,84,-29,66,-33};
			int Arr1[] = {141,299,402,280,28,363,427,232};
			string Arg2 = "Not able to catch";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ableToCatchAll(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-175,-28,-207,-29,-43,-183,-175,-112,-183,-31,-25,-66,-114,-116,-66};
			int Arr1[] = {320,107,379,72,126,445,318,255,445,62,52,184,247,245,185};
			string Arg2 = "Able to catch";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ableToCatchAll(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,0,0};
			int Arr1[] = {0,0,0,0};
			string Arg2 = "Able to catch";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ableToCatchAll(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CatchTheBeatEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
