// BEGIN CUT HERE
/*
SRM 639 Div2 Medium (500)

PROBLEM STATEMENT

Alice and Kirito just played a game.
The game consisted of a finite (possibly empty) sequence of turns.
You do not know the exact number of turns.
The turns were numbered starting from 1.
In each turn, exactly one of our two players won.
The winner of turn i scored i points.

You are given two long longs x and y.
Find out whether it is possible that at the end of the game Alice had exactly x points and Kirito had exactly y points.
If it is possible, return the smallest number of turns Alice could have won.
If the given final result is not possible, return -1 instead.


DEFINITION
Class:AliceGameEasy
Method:findMinimumValue
Parameters:long long, long long
Returns:long long
Method signature:long long findMinimumValue(long long x, long long y)


CONSTRAINTS
-x and y will be between 0 and 1,000,000,000,000(10^12), inclusive.


EXAMPLES

0)
7
14

Returns: 2

This final result is possible.
One possibility is that Alice won turns 1, 2, and 4 (for 1+2+4 = 7 points) and Kirito won turns 3, 5, and 6 (for 3+5+6 = 14 points).
However, there are also some other possibilities in which Alice only won two of the six turns, so the correct answer is 2.


1)
10
0

Returns: 4

There must have been four turns and Alice must have won all four of them.


2)
932599670050
67400241741

Returns: 1047062

Watch out for integer overflow.


3)
7
13

Returns: -1


4)
0
0

Returns: 0


5)
100000
400500

Returns: 106

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class AliceGameEasy {
public:
	long long findMinimumValue(long long x, long long y) {
		LL r = (LL)sqrt(2.0 * (x + y));
		if (r * (r + 1) / 2 != (x + y)) {
			return -1;
		}
		if (x <= 1) {
			return x;
		}
		LL ans = 0;
		LL a = x;
		for (LL i = r; i >= 1; --i) {
			if (a >= i) {
				++ans;
				a -= i;
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
			long long Arg0 = 7LL;
			long long Arg1 = 14LL;
			long long Arg2 = 2LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 10LL;
			long long Arg1 = 0LL;
			long long Arg2 = 4LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 932599670050LL;
			long long Arg1 = 67400241741LL;
			long long Arg2 = 1047062LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 7LL;
			long long Arg1 = 13LL;
			long long Arg2 = -1LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 0LL;
			long long Arg1 = 0LL;
			long long Arg2 = 0LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 100000LL;
			long long Arg1 = 400500LL;
			long long Arg2 = 106LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AliceGameEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
