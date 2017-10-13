// BEGIN CUT HERE
/*
SRM 722 Div2 Easy (250)

PROBLEM STATEMENT
You are about to go hiking. The trail consists of n segments. Some segments go uphill, others are level, and the remaining ones go downhill.

You are given a vector <int> height with n+1 elements. The elements of height are altitude measurements taken at the beginning of the trail and at the end of each segment.

You are concerned about long uphill climbs. Return the largest number of consecutive trail segments that go uphill.


DEFINITION
Class:HillClimber
Method:longest
Parameters:vector <int>
Returns:int
Method signature:int longest(vector <int> height)


CONSTRAINTS
-height will contain between 2 and 50 elements, inclusive.
-Each element of height will be between 0 and 10000, inclusive.


EXAMPLES

0)
{ 1, 2, 3, 2, 2 }

Returns: 2

At the beginning of this trail there are two consecutive segments of uphill hiking: first we go from altitude 1 to altitude 2, and then we go from altitude 2 to altitude 3.


1)
{ 1, 2, 2, 3 }

Returns: 1

This trail has two uphill segments (1-2 and 2-3) but they are not consecutive.


2)
{ 1, 8, 9, 12 }

Returns: 3

The altitudes that correspond to the answer don't necessarily have to form a proper arithmetic sequence.
As long as they are increasing, it is an uphill hike.


3)
{ 10, 4, 4, 2 }

Returns: 0

We never actually have any uphill segments here.


4)
{ 10, 8, 4, 9, 11, 14, 15, 3, 7, 8, 10, 6 }

Returns: 4

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class HillClimber {
public:
	int longest(vector <int> height) {
		int ans = 0, prev = 1LL << 30, cnt = 0;
		for (int h : height) {
			if (h > prev) {
				++cnt;
				ans = max(ans, cnt);
			} else {
				cnt = 0;
			}
			prev = h;
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
			int Arr0[] = { 1, 2, 3, 2, 2 };
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, longest(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 1, 2, 2, 3 };
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, longest(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 1, 8, 9, 12 };
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, longest(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 10, 4, 4, 2 };
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, longest(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 10, 8, 4, 9, 11, 14, 15, 3, 7, 8, 10, 6 };
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, longest(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	HillClimber ___test;
	___test.run_test(-1);
}
// END CUT HERE
