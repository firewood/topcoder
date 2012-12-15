// BEGIN CUT HERE
/*
// SRM 564 Div1 Medium (500)

// PROBLEM STATEMENT
// Bob is playing with his ball destroyer robot. Initially, Bob had r red balls, g green balls and b blue balls. The robot repeated the following 3-step program until there were no balls left:

If there is at least one red ball available, destroy one red ball.
If there is at least one green ball available, destroy one green ball.
If there is at least one blue ball available, destroy one blue ball.

Bob forgot how many balls of each color he initially had. He only remembers that there were n balls in total and that the k-th (1-based index) ball that was destroyed was red. Return the total number of different initial settings that match that description. Formally, return the number of different tuples (r, g, b) such that r + g + b = n and the k-th ball that was destroyed was red.


DEFINITION
Class:AlternateColors2
Method:countWays
Parameters:int, int
Returns:long long
Method signature:long long countWays(int n, int k)


NOTES
-It follows from the constraints that the return value will always fit into a long long.


CONSTRAINTS
-n will be between 1 and 100000, inclusive.
-k will be between 1 and n, inclusive.


EXAMPLES

0)
1
1

Returns: 1

There was only one ball. This ball was necessarily the first ball destroyed. Therefore, it had to be red.


1)
3
3

Returns: 3

There are three cases in which the third ball to be destroyed is red:
r = 3, b = 0, g = 0.
r = 2, b = 1, g = 0.
r = 2, b = 0, g = 1.


2)
6
4

Returns: 9


3)
6
1

Returns: 21


4)
1000
2

Returns: 1

In order for the second destroyed ball to be red, there would have to be zero balls of the other colors.


5)
100000
100000

Returns: 1666700000

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class AlternateColors2 {

public:
	long long countWays(int N, int K) {
		if (N <= 1) {
			return 1;
		}
		if (N <= 2) {
			return K == 1 ? 3 : 1;
		}

		static int dp[100002][8][3];
		memset(dp, 0, sizeof(dp));

		dp[1][7][0] = 1;
		int i, color, cb, p, pb, p2, pb2;
		for (i = 2; i <= N; ++i) {
			for (color = 0; color <= 2; ++color) {
				if (i == K && color != 0) continue;
				cb = 1<<color;
				dp[i][cb][color] += dp[i-1][cb][color];
				p = (color+2)%3;
				pb = 1<<p;
				p2 = (color+1)%3;
				pb2 = 1<<p2;
				dp[i][cb][color] += dp[i-1][7][color];
				dp[i][cb][color] += dp[i-1][pb|cb][color];
				dp[i][cb][color] += dp[i-1][pb2|cb][color];
				dp[i][pb|cb][color] += dp[i-1][pb|cb][p];
				dp[i][pb2|cb][color] += dp[i-1][pb2|cb][p2];
				dp[i][pb2|cb][color] += dp[i-1][7][p2];
				dp[i][7][color] += dp[i-1][7][p];
			}
		}

		LL ans = 0;
		for (int colors = 1; colors <= 7; ++colors) {
			for (int color = 0; color <= 2; ++color) {
				ans += dp[N][colors][color];
			}
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
			int Arg0 = 1;
			int Arg1 = 1;
			long long Arg2 = 1LL;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			long long Arg2 = 3LL;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 4;
			long long Arg2 = 9LL;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 1;
			long long Arg2 = 21LL;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000;
			int Arg1 = 2;
			long long Arg2 = 1LL;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100000;
			int Arg1 = 100000;
			long long Arg2 = 1666700000LL;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AlternateColors2 ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
