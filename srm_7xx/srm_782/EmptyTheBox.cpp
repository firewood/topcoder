// BEGIN CUT HERE
/*
SRM 782 Div1 Easy (250)

PROBLEM STATEMENT

Empty The Box is a game played with two D-sided dice, one box, and a collection of T penalty tokens.
The values of the penalty tokens are 1, 2, ..., T.
At the beginning of the game all penalty tokens are in the box.

The game consists of one or more turns.
In each turn you roll the two D-sided dice.
The number you rolled (i.e., the sum of the numbers on the two dice) is called your power for the round.
Now you have the option to remove some penalty tokens from the box.
You may remove arbitrarily many tokens, but the total value of the tokens you remove must be exactly equal to your current power.
If you cannot do that, you do not get to remove any tokens and the game ends.
Your penalty at the end of the game is equal to the total value of tokens left in the box.

You are going to play this game.
Your goal is to minimize the expected value of the penalty you'll receive at the end.
Calculate and return that expected value, assuming you play optimally.


DEFINITION
Class:EmptyTheBox
Method:minExpectedPenalty
Parameters:int, int
Returns:double
Method signature:double minExpectedPenalty(int D, int T)


NOTES
-Your return value must have an absolute or relative error at most 1e-9.
-Each D-sided die generates a uniformly random number between 1 and D, inclusive.


CONSTRAINTS
-D will be between 2 and 6, inclusive.
-T will be between 1 and 50, inclusive.


EXAMPLES

0)
2
3

Returns: 1.25

You have two 2-sided dice (i.e., coins with "1" on one side and "2" on the other) and three penalty tokens with values 1, 2, 3.
The only strategic decision in this game is what to take if your first roll is a 3. In this particular situation it's obvious that eliminating the token with value 3 is better than eliminating tokens worth 1+2, as it leaves you more options later, so you do that.
We can now examine all possible results of the first and second roll, concluding that if your first roll is a 2 or a 4, your expected final penalty is 1.5, but if your first roll is the 3, your expected final penalty is only 1.
Hence, your expected final penalty is 0.25 * 1.5 + 0.5 * 1 + 0.25 * 1.5 = 1.25.


1)
6
2

Returns: 2.777777777777778

If you roll a 1+1 (probability 1/36), you get to remove the token with value 2.
If you roll a 1+2 (probability 1/18), you get to empty the box.
Otherwise, you end with penalty 3.


2)
6
10

Returns: 16.64572136166177

Two regular dice and a box with ten tokens. You can usually get the penalty much lower than the initial 55.


3)
4
10

Returns: 33.489906787872314

In the same game played with tetrahedrons instead of traditional dice your expected final penalty is much higher.

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long double LD;

int get_sum(int x) {
	int r = 0;
	for (int i = 0; i < 12; ++i) {
		if ((1 << i) & x) {
			r += i + 1;
		}
	}
	return r;
}

class EmptyTheBox {
	int d;
	int t;
	int bm;
	LD p[16];
	map<int, LD> memo;

	LD dfs(int x) {
		if (memo.find(x) == memo.end()) {
			LD& r = memo[x];
			for (int i = 2; i <= 2 * d; ++i) {
				LD m = get_sum(x);
				for (int k = 1; k <= bm; ++k) {
					if ((x & k) == k && get_sum(k) == i) {
						m = min(m, dfs(x ^ k));
					}
				}
				r += m * p[i];
			}
		}
		return memo[x];
	}

public:
	double minExpectedPenalty(int D, int T) {
		LD ans = 0;
		d = D;
		t = T;
		bm = 0;
		memo.clear();
		for (int i = 0; i < 16; ++i) {
			p[i] = 0;
		}
		for (int i = 1; i <= d; ++i) {
			for (int j = 1; j <= d; ++j) {
				p[i + j] += 1.0 / d / d;
			}
		}
		for (int i = 0; i < T; ++i) {
			if (i < 2 * D) {
				bm |= 1 << i;
			} else {
				ans += i + 1;
			}
		}
		return ans + dfs(bm);
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
			int Arg0 = 2;
			int Arg1 = 3;
			double Arg2 = 1.25;

			verify_case(n, Arg2, minExpectedPenalty(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 2;
			double Arg2 = 2.777777777777778;

			verify_case(n, Arg2, minExpectedPenalty(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 10;
			double Arg2 = 16.64572136166177;

			verify_case(n, Arg2, minExpectedPenalty(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 10;
			double Arg2 = 33.489906787872314;

			verify_case(n, Arg2, minExpectedPenalty(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EmptyTheBox ___test;
	___test.run_test(-1);
}
// END CUT HERE
