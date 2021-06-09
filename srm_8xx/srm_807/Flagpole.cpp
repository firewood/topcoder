// BEGIN CUT HERE
/*
SRM 807 1000

PROBLEM STATEMENT
Time limit is 4 seconds.

The leader of the neighboring country has just unveiled a giant flagpole with their national flag.
Our national pride is hurt.
We need a bigger flagpole.
(True story.)

Their flagpole measures LO nanometers.
The maximum safe height of a flagpole is HI nanometers.

A flagpole is built by placing one or more segments on top of each other.
The final height of the flagpole is the sum of heights of segments used.

Our government must purchase all flagpole segments from its only official flagpole segment provider.
The lengths of the segments the provider has in their warehouse are given in the vector <int> segments.
(All segments are distinct: even if they have the same length, they have different colors.)

Count all ways in which we can purchase a subset of the available segments if we want a safe flagpole that is bigger than what our neighbors have.


DEFINITION
Class:Flagpole
Method:build
Parameters:vector <int>, long long, long long
Returns:long long
Method signature:long long build(vector <int> segments, long long LO, long long HI)


NOTES
-Note that we want you to return the exact number of ways in which a subset of segments can be selected, and not the number modulo something (as is sometimes the case in similar problems).


CONSTRAINTS
-segments will have between 1 and 40 elements, inclusive.
-Each element of segments will be between 1 and 2*10^9, inclusive.
-LO will be between 1 and 10^11, inclusive.
-HI will be between LO+1 and 10^11, inclusive.


EXAMPLES

0)
{10, 10, 10, 10, 10}
9
49

Returns: 30

Out of the 2^5 = 32 possible purchases only two are invalid: 

If we don't purchase any segments, our flagpole will have height 0 and our neighbors will laugh at us.
If we purchase all five segments, the flagpole will exceed the maximum safe height.


1)
{10, 10, 10, 10, 10}
30
39

Returns: 0

There is no solution: either we make a flagpole that is at most as long as our neighbor's, or we make one that is too tall to be safe.


2)
{1, 2, 4, 8, 16, 32, 64, 128}
47
100

Returns: 53

For each of the heights 48-100 there is exactly one way to purchase some segments that sum to the chosen flagpole height.


3)
{50, 10, 40, 30, 20}
45
63

Returns: 6

We can build a flagpole of height 50 as 50, 10+40, or 20+30. We can build a flagpole of height 60 as 10+50, 20+40, or 10+20+30.

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

class Flagpole {
public:
	long long build(vector <int> segments, long long LO, long long HI) {
		vector<LL> a, b;
		a.emplace_back(0);
		b.emplace_back(0);
		for (auto x : segments) {
			vector<LL> prev = a;
			for (auto y : prev) {
				a.emplace_back(x + y);
			}
			swap(a, b);
		}
		sort(b.begin(), b.end());
		LL ans = 0;
		for (auto x : a) {
			ans += lower_bound(b.begin(), b.end(), HI - x + 1) - lower_bound(b.begin(), b.end(), LO - x + 1);
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
			int Arr0[] = {10, 10, 10, 10, 10};
			long long Arg1 = 9LL;
			long long Arg2 = 49LL;
			long long Arg3 = 30LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, build(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 10, 10, 10, 10};
			long long Arg1 = 30LL;
			long long Arg2 = 39LL;
			long long Arg3 = 0LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, build(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 4, 8, 16, 32, 64, 128};
			long long Arg1 = 47LL;
			long long Arg2 = 100LL;
			long long Arg3 = 53LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, build(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {50, 10, 40, 30, 20};
			long long Arg1 = 45LL;
			long long Arg2 = 63LL;
			long long Arg3 = 6LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, build(Arg0, Arg1, Arg2));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Flagpole ___test;
	___test.run_test(-1);
}
// END CUT HERE
