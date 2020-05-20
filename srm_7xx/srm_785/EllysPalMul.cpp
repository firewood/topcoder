// BEGIN CUT HERE
/*
SRM 785 Div1 Easy (275)

PROBLEM STATEMENT
This problem has a non-standard time limit: 3 seconds.

We call a number a palindrome if it reads the same from left to right as it does from right to left.
For example, some palindromic numbers are 6, 11, 121, 666, 100001, and 123454321.
Note that the number 47740 is not a palindrome (as you are not allowed to have unnecessary leading zeros).

Elly has the integer X. Now she wants to find the lowest integer 1 ? Y ? 1,000,000,000, such that the product X * Y is a palindrome (if there is such a number). 

Let's look at several examples:

If X = 42, then Y is 6 (42 * 6 = 252).
If X = 121, then Y = 1 (121 * 1 = 121).
If X = 1337, then Y = 143 (1337 * 143 = 191191).
If X = 13, then Y = 38 (13 * 38 = 494).
If X = 100, then no Y can make it a palindrome.
If X = 21951, then Y = 9612315612 would make it a palindrome (21951 * 9612315612 = 210999939999012), but this Y isn't in the bounds [1, 10^9].

Given the int X, return the lowest integer Y in the interval [1, 10^9] that makes the product X * Y a palindrome, or -1 if there is no such Y.


DEFINITION
Class:EllysPalMul
Method:getMin
Parameters:int
Returns:int
Method signature:int getMin(int X)


CONSTRAINTS
-X will be between 1 and 100,000, inclusive.


EXAMPLES

0)
42

Returns: 6

42 * 6 = 252


1)
121

Returns: 1

121 is already a palindrome, so we can multiply it by 1.


2)
1337

Returns: 143

1337 * 143 = 191191


3)
13

Returns: 38

13 * 38 = 494


4)
100

Returns: -1

No Y can make it a palindrome, so we return -1.


5)
21951

Returns: -1

Y = 9612315612 would make it a palindrome (21951 * 9612315612 = 210999939999012), but since it isn't in the bounds [1, 10^9], we return -1.

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

class EllysPalMul {
public:
	LL getMin(int X) {
		for (int digits = 1; digits <= 14; ++digits) {
			int hd = digits / 2;
			LL mn = pow(10, hd - 1), mx = pow(10, hd), upper = pow(10, hd + (digits % 2));
			for (LL i = mn; i < mx; ++i) {
				LL x = i * upper;
				for (LL d = mn, r = i; r > 0; d /= 10, r /= 10) {
					x += d * (r % 10);
				}
				for (LL k = 0; k < 10; ++k, x += mx) {
					if (!x) continue;
					LL y = x / X;
					if (y > 1000000000LL) return -1;
					if (y * X == x) return y;
					if ((digits % 2) == 0) break;
				}
			}
		}
		return -1;
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
			int Arg0 = 42;
			int Arg1 = 6;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 121;
			int Arg1 = 1;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1337;
			int Arg1 = 143;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 13;
			int Arg1 = 38;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = -1;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 21951;
			int Arg1 = -1;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1;
			int Arg1 = 1;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysPalMul ___test;
	___test.run_test(-1);

/*
	for (int i = 10000; i < 100000; ++i) {
		if ((i % 10) == 0) continue;
		LL ans = ___test.getMin(i);
		if (ans == -1) {
			cout << "No answer: " << i << endl;
		} else {
			if (ans > 1000000000) {
				cout << "Overflow: " <<  i << endl;
			}
		}
	}
*/
}
// END CUT HERE
