// BEGIN CUT HERE
/*
TCO19 R3B Easy (250)

PROBLEM STATEMENT

You are playing a platform game.
At the beginning, your x-coordinate is sx and your y-coordinate is 0.
There is an infinite horizontal platform at each positive integer y-coordinate.
There are two infinite vertical ladders.
One starts at the point (lx1,0), the other at the point (lx2,0).

In one second you can walk one step left or right.
If you are at a ladder, you can also climb one floor up in one second.
Once you climb up, there is no way back down.

There are some coins scattered around the level:
for each valid i, there is a coin that can be picked up when you reach the coordinates (X[i], Y[i]).

Calculate and return the minimum time to pick up all coins.


DEFINITION
Class:TwoLadders
Method:minSteps
Parameters:int, int, int, vector <int>, vector <int>
Returns:long long
Method signature:long long minSteps(int sx, int lx1, int lx2, vector <int> X, vector <int> Y)


CONSTRAINTS
-sx, lx1, and lx2 will all be between 0 and 10^9, inclusive.
-lx1 will be smaller than lx2.
-The number of elements in X will be between 1 and 100, inclusive.
-X and Y will have the same number of elements.
-All values in X and Y will be be between 0 and 10^9, inclusive.
-The points (sx, 0), (lx1, 0), (lx2, 0), and the locations of all coins will all be distinct.


EXAMPLES

0)
10
0
100
{47, 42}
{0, 0}

Returns: 37

You start at (10, 0). You simply start walking right. After 32 seconds you'll pick up the coin at (42, 0) and after another 5 seconds the coin at (47, 0).


1)
10
8
11
{10, 12}
{1, 1}

Returns: 5

Go right, up, left, right, right.
Alternately, go right, up, right, left, left.


2)
10
8
42
{10, 12}
{1, 1}

Returns: 7

This time you should go two steps left, then up, then four steps right.


3)
10
8
42
{10, 100, 12}
{1, 0, 1}

Returns: 181

You have to pick up the coin at (100, 0) first. Then, once you are that far right, you might as well take the ladder at x=42 and continue walking left until you pick up both coins.


4)
500000000
1
999999999
{0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000}
{1, 1, 2, 2, 3, 3, 4, 4, 7, 7, 999999947, 999999947, 900000047, 900000047}

Returns: 8499999959

In one variant of the philosophical problem by Jean Buridan, a donkey starves to death when you place it exactly halfway between two identical piles of hay. Don't let that happen to you in this nice symmetric level!

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
typedef pair<int, LL> ILL;

class TwoLadders {
	LL cost(LL sx, LL ex, LL lx, LL rx) {
		LL lc = abs(sx - lx) + rx - lx + abs(ex - rx);
		LL rc = abs(sx - rx) + rx - lx + abs(ex - lx);
		return min(lc, rc);
	}

public:
	long long minSteps(int sx, int lx1, int lx2, vector <int> X, vector <int> Y) {
		vector<ILL> yx, costs;
		for (int i = 0; i < (int)X.size(); ++i) {
			yx.push_back({ Y[i], X[i] });
		}
		sort(yx.begin(), yx.end());
		if (yx[0].first == 0) {
			costs = { { sx, 0 } };
		} else {
			costs = { { lx1, abs(lx1 - sx)}, { lx2, abs(lx2 - sx)} };
		}
		int ei;
		for (int si = 0; si < (int)yx.size(); si = ei) {
			for (ei = si + 1; ei < (int)yx.size(); ++ei) {
				if (yx[ei].first > yx[si].first) {
					break;
				}
			}
			LL lx = yx[si].second, rx = yx[ei - 1].second;
			LL cost1 = 1LL << 60, cost2 = 1LL << 60;
			for (int j = 0; j < (int)costs.size(); ++j) {
				if (yx[si].first < yx.back().first) {
					cost1 = min(cost1, costs[j].second + cost(costs[j].first, lx1, lx, rx));
					cost2 = min(cost2, costs[j].second + cost(costs[j].first, lx2, lx, rx));
				} else {
					for (int i = si; i < ei; ++i) {
						cost1 = min(cost1, costs[j].second + cost(costs[j].first, yx[i].second, lx, rx));
					}
				}
			}
			costs = { { lx1, cost1 }, { lx2, cost2 } };
		}
		return yx.back().first + min(costs[0].second, costs[1].second);
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
			int Arg0 = 10;
			int Arg1 = 0;
			int Arg2 = 100;
			int Arr3[] = {47, 42};
			int Arr4[] = {0, 0};
			long long Arg5 = 37LL;

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg5, minSteps(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 8;
			int Arg2 = 11;
			int Arr3[] = {10, 12};
			int Arr4[] = {1, 1};
			long long Arg5 = 5LL;

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg5, minSteps(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 8;
			int Arg2 = 42;
			int Arr3[] = {10, 12};
			int Arr4[] = {1, 1};
			long long Arg5 = 7LL;

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg5, minSteps(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 8;
			int Arg2 = 42;
			int Arr3[] = {10, 100, 12};
			int Arr4[] = {1, 0, 1};
			long long Arg5 = 181LL;

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg5, minSteps(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 500000000;
			int Arg1 = 1;
			int Arg2 = 999999999;
			int Arr3[] = {0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000};
			int Arr4[] = {1, 1, 2, 2, 3, 3, 4, 4, 7, 7, 999999947, 999999947, 900000047, 900000047};
			long long Arg5 = 8499999959LL;

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg5, minSteps(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TwoLadders ___test;
	___test.run_test(-1);
}
// END CUT HERE
