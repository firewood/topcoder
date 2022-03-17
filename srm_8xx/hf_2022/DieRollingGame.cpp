// BEGIN CUT HERE
/*
2022 Humbefool Cup - Preliminary Medium (600)

PROBLEM STATEMENT
You are playing a game in which you roll a single die, with faces numbered 1..n. With each roll, you score points equal to the value shown on the die. You keep rolling until you either reach total, and win, or else exceed total, and lose the game.

Assuming you are using a fair die that has an equal chance of landing on any side, what is the probability that you win the game?


DEFINITION
Class:DieRollingGame
Method:winChance
Parameters:int, int
Returns:double
Method signature:double winChance(int n, int total)


CONSTRAINTS
-n will be between 2 and 20.
-total will be between 1 and 100.


EXAMPLES

0)
6
1

Returns: 0.16666666666666666

You're only going to make a single roll here, and you have a 1/6 chance of getting the 1.


1)
4
2

Returns: 0.3125

Here, it's a little more interesting.

You have a 1/4 chance of winning on the first roll, with a 2,
as well as a 1/4 * 1/4 chance of winning with two rolls of 1.


2)
2
3

Returns: 0.625

Since we're basically flipping a coin, we have an equal chance of rolling a 1 or a 2, leaving 1 or 2 more points that we need to win. We have a 1/2 chance to get 1 point, or a 3/4 chance to successfully score 2 points.
1/2 * 1/2 + 1/2 * 3/4 = 5/8


3)
20
20

Returns: 0.12634750976878192

We could win this in a single roll of 20, 20 consecutive rolls of 1, or a whole lot of other possibilities in between.

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

typedef long double LD;

class DieRollingGame {
public:
	double winChance(int n, int total) {
		LD ans = 0;
		vector<LD> dp(total, 0);
		dp[0] = 1.0;
		for (int i = 0; i <= total; ++i) {
			vector<LD> next(total, 0);
			for (int j = 0; j < total; ++j) {
				for (int k = 1; k <= n; ++k) {
					int t = j + k;
					if (t == total) {
						ans += dp[j] / n;
					} else if (t < total) {
						next[t] += dp[j] / n;
					}
				}
			}
			dp = next;
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 1;
			double Arg2 = 0.16666666666666666;

			verify_case(n, Arg2, winChance(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 2;
			double Arg2 = 0.3125;

			verify_case(n, Arg2, winChance(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 3;
			double Arg2 = 0.625;

			verify_case(n, Arg2, winChance(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arg1 = 20;
			double Arg2 = 0.12634750976878192;

			verify_case(n, Arg2, winChance(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DieRollingGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
