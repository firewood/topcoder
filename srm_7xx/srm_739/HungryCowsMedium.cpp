// BEGIN CUT HERE
/*
SRM 739 Div1 Medium (500)

PROBLEM STATEMENT

There is a herd of hungry cows.
You are given the vector <int> cowAppetites.
Each element of cowAppetites is the number of units of food one of the cows needs.

There is also a long straight road with a coordinate system.
All the cows are currently standing at coordinate 0.
There are some barns along the road.
All barns are at distinct positive integer coordinates.
You are given the positions of all barns in the vector <int> barnPositions.
Each barn contains an unlimited supply of food.
There is no other food anywhere else.

During each unit of time, each cow can choose one of three actions:

Do nothing.
Move by one unit of distance in either direction.
Eat one unit of food, if able.

A cow can only eat when it is at the same coordinate as one of the barns.
Additionally, during each unit of time each barn can only serve one cow, so if there are multiple cows at a barn at the same time, only one of them can choose to eat during the next unit of time.
Each cow can combine movement and eating arbitrarily.
For example, a cow can move to a barn, eat 2 units of food, move to another barn, and eat 3 units of food there.

If all cows carefully make a plan, what is the earliest time in which all of them will finish eating?


DEFINITION
Class:HungryCowsMedium
Method:getWellFedTime
Parameters:vector <int>, vector <int>
Returns:long long
Method signature:long long getWellFedTime(vector <int> cowAppetites, vector <int> barnPositions)


CONSTRAINTS
-cowAppetites will contain between 1 and 300 elements, inclusive.
-Each element of cowAppetites will be between 1 and 1,000,000,000, inclusive.
-barnPositions will contain between 1 and 300 elements, inclusive.
-Each element of barnPositions will be between 1 and 1,000,000,000, inclusive.
-All elements of barnPositions will be distinct.


EXAMPLES

0)
{3}
{5}

Returns: 8

A cow that needs 3 units of food and a barn at coordinate 5. The cow will need 5 units of time to reach the barn and then another 3 units of time to eat as much as it needs.


1)
{1,1,1,1,1}
{2,3}

Returns: 5


2)
{4,4,4}
{4,2}

Returns: 9

The inputs are not necessarily sorted.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

class HungryCowsMedium {
	bool possible(vector <LL> &cows, vector <LL> &b, LL t) {
		int bs = (int)b.size();
		vector<LL> f(bs + 1);
		for (int i = 0; i < bs; ++i) {
			f[i] = max(0LL, t - b[i]);
		}
		for (LL c : cows) {
			LL r = c;
			for (int i = 0; r > 0 && i < bs; ++i) {
				if (b[i] + c <= t) {
					LL x = min(r, f[i]);
					r -= x;
					f[i] -= x;
				}
			}
			if (r) {
				return false;
			}
		}
		return true;
	}

public:
	long long getWellFedTime(vector <int> cowAppetites, vector <int> barnPositions) {
		sort(cowAppetites.begin(), cowAppetites.end());
		sort(barnPositions.rbegin(), barnPositions.rend());
		vector <LL> cc(cowAppetites.begin(), cowAppetites.end());
		vector <LL> bb(barnPositions.begin(), barnPositions.end());
		LL left = 0, right = 1LL << 61;
		while ((right - left) > 1) {
			LL mid = (left + right) / 2;
			if (possible(cc, bb, mid)) {
				right = mid;
			} else {
				left = mid + 1;
			}
		}
		for (LL ans = left; ans <= left + 2; ++ans) {
			if (possible(cc, bb, ans)) {
				return ans;
			}
		}
		return left + 1;
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
			int Arr0[] = {3};
			int Arr1[] = {5};
			long long Arg2 = 8LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getWellFedTime(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1};
			int Arr1[] = {2,3};
			long long Arg2 = 5LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getWellFedTime(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,4,4};
			int Arr1[] = {4,2};
			long long Arg2 = 9LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getWellFedTime(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = {
				1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,
				1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000
			};
			int Arr1[] = { 1000000000,1000000000 };
			long long Arg2 = 11000000000LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getWellFedTime(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 8,1 };
			int Arr1[] = { 1,3 };
			long long Arg2 = 9LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getWellFedTime(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	HungryCowsMedium ___test;
	___test.run_test(-1);
}
// END CUT HERE
