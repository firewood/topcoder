// BEGIN CUT HERE
/*
SRM 814 Div2 Medium (500)

PROBLEM STATEMENT

You are traversing a dangerous section of a video game level.
The section contains some solid terrain blocks (denoted '-') and some blocks with spiky traps (denoted '*').
If you step onto a trap, you die.

You are given the layout of the level in the string level.
You are currently standing on the leftmost block of the level.
This block is represented by the character level[0] and it is guaranteed to be a solid block.

Your task is to reach the block at the opposite end of the level.
This block is also guaranteed to be solid.

You can move in three ways:

Take a step (denoted 'S'): move one block to the right.
Make a hop (denoted 'H'): hop over one block and land two block to the right of your current block.
Make a jump (denoted 'J'): jump over two consecutive blocks and land three blocks to the right of your current position.

For example, if the level is "----", you can traverse it by making three steps (denoted "SSS"), a
hop followed by a step ("SH"), a step followed by a hop ("HS"), or a single jump ("J").

If the level is "-**-", the only way to traverse it is by making a jump - remember that you cannot
step onto the spiky traps.

In the above way, we can describe any way of traversing the level as a string in which each character is 'S', 'H', or 'J'.
Two ways of traversing a level are considered different if they are described by different strings.
For example, there are four ways to traverse the level "----", one way to traverse the level
"-**-**-", and no ways at all to traverse the level "-*-****-*-".

Let W be the number of different ways in which we can traverse the level described by the string level.
Calculate and return the value (W modulo 1,000,000,007).


DEFINITION
Class:StepHopJumpMedium
Method:countWays
Parameters:string
Returns:int
Method signature:int countWays(string level)


CONSTRAINTS
-level will contain between 2 and 200 characters, inclusive.
-Each character of level will be either '-' or '*'.
-The first and the last character of level will be '-'.


EXAMPLES

0)
"----"

Returns: 4

The first example from the problem statement.


1)
"-**-"

Returns: 1

The second example from the problem statement.


2)
"-*-****-*-"

Returns: 0

The third example from the problem statement: there are no solutions.


3)
"------------------------------------"

Returns: 132436845

This level consists of 36 dashes. It can be traversed in many different ways. One of them is taking 35 steps, another is taking 11 jumps and then a hop. There are exactly 1,132,436,852 different ways in total. Remember that you should return this value modulo 10^9 + 7.

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

const int64_t MOD = 1000000007;

struct modint {
	int64_t x;
	modint() { }
	modint(int _x) : x(_x) { }
	operator int() const { return (int)x; }
	modint operator+(int y) { return (x + y + MOD) % MOD; }
	modint operator+=(int y) { x = (x + y + MOD) % MOD; return *this; }
	modint operator-(int y) { return (x - y + MOD) % MOD; }
	modint operator-=(int y) { x = (x - y + MOD) % MOD; return *this; }
	modint operator*(int y) { return (x * y) % MOD; }
	modint operator*=(int y) { x = (x * y) % MOD; return *this; }
	modint operator/(int y) { return (x * modpow(y, MOD - 2)) % MOD; }
	modint operator/=(int y) { x = (x * modpow(y, MOD - 2)) % MOD; return *this; }
	static modint modinv(int a) { return modpow(a, MOD - 2); }
	static modint modpow(int a, int b) {
		modint x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

class StepHopJumpMedium {
public:
	int countWays(string level) {
		vector<modint> dp(level.length() + 1, 0);
		dp[0] = 1;
		for (int i = 1; i < level.length(); ++i) {
			if (level[i] == '-') {
				dp[i] += dp[i - 1];
				if (i >= 2) {
					dp[i] += dp[i - 2];
				}
				if (i >= 3) {
					dp[i] += dp[i - 3];
				}
			}
		}
		return dp[level.length() - 1];
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
			string Arg0 = "----";
			int Arg1 = 4;

			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "-**-";
			int Arg1 = 1;

			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "-*-****-*-";
			int Arg1 = 0;

			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "------------------------------------";
			int Arg1 = 132436845;

			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	StepHopJumpMedium ___test;
	___test.run_test(-1);
}
// END CUT HERE
