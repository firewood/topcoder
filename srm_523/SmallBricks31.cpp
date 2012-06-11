// BEGIN CUT HERE
/*
// SRM 523 Div2 Hard (1000)

// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.

We have three kinds of construction bricks. Those of dimensions 1x1x1,
1x1x2 and 1x1x3. We also have a special brick of dimensions 1x1xw which
we will call the base.

We would like to use the bricks and the base to build structures. For the
bricks to connect to each other and to the base, they all have to be
aligned properly. Placing a brick at a non-integer position is not allowed.
Also, to ensure stability, the longer bricks (1x1x2 and 1x1x3) must be
placed in a way that their extremes both rest on top of another brick or
bricks, including the base. There may be an empty space directly below the
middle part of a 1x1x3 brick. The following image shows a valid structure
and the other image shows a structure that is invalid for three reasons.

The height of a structure is the number of layers of bricks it contains.
The base is not counted into the height of the structure.

Two structures are different if there is a position where they differ in
any way. (There are two ways in which two given structures may differ:
First, there may be a position where one structure has a brick and the
other does not. Second, there may be a position where both structures
have bricks, but the bricks are of different types.)

Given are two ints w and h. Count the total number of different structures
that can be created using any number of 1x1x1, 1x1x2 and 1x1x3 bricks and
a base of width w such that the height of the structure is at most h units.
Since the result can be large, return the count modulo 1000000007.
For example, the following image shows the 84 different structures for w=3, h=2:


DEFINITION
Class:SmallBricks31
Method:countWays
Parameters:int, int
Returns:int
Method signature:int countWays(int w, int h)


CONSTRAINTS
-w will be between 1 and 10, inclusive.
-h will be between 1 and 10, inclusive.


EXAMPLES

0)
1
3

Returns: 4


1)
3
1

Returns: 13

The leftmost column in the picture above shows the 13 different structures of width 3 and at most 1 unit of height.


2)
3
2

Returns: 84

The picture above shows the 84 different structures of width 3 and at most 2 unit of height.


3)
4
9

Returns: 132976888


4)
5
5

Returns: 11676046

*/
// END CUT HERE
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

#define MAX_W 10
#define WSIZE (1<<MAX_W)
#define MOD 1000000007

typedef long long LL;
typedef map<int, int> IntMap;

class SmallBricks31 {

	IntMap ways[WSIZE];

	void gen_ways(int i, int pre, int post) {
		if (i >= MAX_W) {
			ways[pre][post] += 1;
		} else {
			gen_ways(i + 1, pre, post);
			int mask = 1<<i;
			if (pre & mask) {
				gen_ways(i + 1, pre, post | mask);
			}
			mask = 3 << i;
			if ((pre & mask) == mask) {
				gen_ways(i + 2, pre, post | mask);
			}
			mask = 5 << i;
			if ((pre & mask) == mask) {
				gen_ways(i + 3, pre, post | (7<<i));
			}
		}
	}

public:
	SmallBricks31() {
		int i;
		for (i = 0; i < WSIZE; ++i) {
			gen_ways(0, i, 0);
		}
	}

	int countWays(int w, int h) {
		int W = 1<<w;
		int dp[2][WSIZE] = {};
		int read = 0;
		int write = 1;
		dp[0][W-1] = 1;
		int i, j;
		for (i = 0; i < h; ++i) {
			memset(dp[write], 0, sizeof(dp[write]));
			for (j = 0; j < W; ++j) {
				LL c = dp[read][j];
				if (c) {
					const IntMap &m = ways[j];
					IntMap::const_iterator it;
					for (it = m.begin(); it != m.end(); ++it) {
						LL n = c * (LL)it->second;
						n += dp[write][it->first];
						dp[write][it->first] = (int)(n % MOD);
					}
				}
			}
			read ^= 1;
			write ^= 1;
		}

		int res = 0;
		for (i = 0; i < W; ++i) {
			res = (res + dp[read][i]) % MOD;
		}
		return res;
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
			int Arg0 = 1;
			int Arg1 = 3;
			int Arg2 = 4;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 1;
			int Arg2 = 13;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			int Arg2 = 84;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 9;
			int Arg2 = 132976888;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 5;
			int Arg2 = 11676046;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SmallBricks31 ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
