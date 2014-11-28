// BEGIN CUT HERE
/*
SRM 639 Div1 Easy (250)

PROBLEM STATEMENT

Alice and Kirito just played a game.
The game consisted of a finite (possibly empty) sequence of turns.
You do not know the exact number of turns.
The turns were numbered starting from 1.
In each turn, exactly one of our two players won.
The winner of turn i scored 2*i-1 points.

You are given two long longs x and y.
Find out whether it is possible that at the end of the game Alice had exactly x points and Kirito had exactly y points.
If it is possible, return the smallest number of turns Alice could have won.
If the given final result is not possible, return -1 instead.


DEFINITION
Class:AliceGame
Method:findMinimumValue
Parameters:long long, long long
Returns:long long
Method signature:long long findMinimumValue(long long x, long long y)


CONSTRAINTS
-x and y are between 0 and 1,000,000,000,000, inclusive.


EXAMPLES

0)
8
17

Returns: 2

This final result is possible.
Alice must have won at least two turns.
One possibility is that Alice won turns 2 and 3 (for 3+5 = 8 points) and Kirito won turns 1, 4, and 5 (for 1+7+9 = 17 points).


1)
17
8

Returns: 3


2)
0
0

Returns: 0


3)
9
9

Returns: -1


4)
500000
500000

Returns: 294

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

typedef long long LL;

class AliceGame {
public:

	long long findMinimumValue(long long x, long long y) {
		LL sum = x + y;
		LL r = (LL)sqrt(sum);
		if (r*r != sum || x == 2 || y == 2) {
			return -1;
		}
		if (x == 0) {
			return 0;
		}
		LL ans = 0;
		LL t = 0;
		for (LL i = r; i >= 1; --i) {
			++ans;
			t += i * 2 - 1;
			if (t >= x && (t % 2) == (x % 2)) {
				return ans;
			}
		}
		return -1;
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
			long long Arg0 = 8LL;
			long long Arg1 = 17LL;
			long long Arg2 = 2LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 17LL;
			long long Arg1 = 8LL;
			long long Arg2 = 3LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 0LL;
			long long Arg1 = 0LL;
			long long Arg2 = 0LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 9LL;
			long long Arg1 = 9LL;
			long long Arg2 = -1LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 500000LL;
			long long Arg1 = 500000LL;
			long long Arg2 = 294LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 999999999999;
			long long Arg2 = 1LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			long long Arg0 = 500000000000;
			long long Arg1 = 500000000000;
			long long Arg2 = 292894LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			long long Arg0 = 21LL;
			long long Arg1 = 4LL;
			long long Arg2 = 3LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			long long Arg0 = 27LL;
			long long Arg1 = 9LL;
			long long Arg2 = 3LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			long long Arg0 = 7LL;
			long long Arg1 = 2LL;
			long long Arg2 = -1LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1000000000000LL;
			long long Arg1 = 0LL;
			long long Arg2 = 1000000LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AliceGame ___test;
	___test.run_test(10);
	___test.run_test(-1);
}
// END CUT HERE
