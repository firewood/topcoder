// BEGIN CUT HERE
/*
SRM 669 Div1 Easy (250)

PROBLEM STATEMENT

The idols Ami and Mami like playing games.
Today they bought a new game.
At the beginning of the game a single slime appears on the screen.
You are given an int S: the size of the slime.

The game consists of K turns.
In each turn of the game the player must choose a single slime and cut it into two smaller parts.
More precisely, suppose that the player chose a slime of size z.
When cutting this slime, the player must choose two positive integers x and y such that x+y = z.
The player will then cut the slime into two smaller slimes.
The sizes of those smaller slimes will be x and y, respectively.
Note that the player must always choose a slime of size 2 or more, as it is not possible to cut a slime of size 1.

The player gets a reward for making each cut:
whenever you cut a slime of size x+y into slimes of sizes x and y, the player is awarded x*y mascots.

Ami and Mami have just started a new game.
You are given two ints S and M.
Calculate and return the smallest possible K (the number of turns in the game) such that Ami and Mami can get at least M mascots in the game.
If there exists no such K, return -1 instead.


DEFINITION
Class:SubdividedSlimes
Method:needCut
Parameters:int, int
Returns:int
Method signature:int needCut(int S, int M)


CONSTRAINTS
-S will be between 2 and 1000, inclusive.
-M will be between 1 and 10^9, inclusive.


EXAMPLES

0)
3
2

Returns: 1

There is a single slime of size 3, and the players have to get at least two mascots.
In this case, K = 1 is sufficient.
In the only step, cut the only slime into two slimes with sizes 1 and 2.
(This gives them 1*2 = 2 mascots.)


1)
3
3

Returns: 2

There is a single slime of size 3, and the players have to get at least three mascots.
They can get three mascots in two steps:
In the first step, cut the only slime into two slimes with sizes 1 and 2.
(This gives them 1*2 = 2 mascots.)
In the second step, choose the slime of size 2 and cut it into two slimes of size 1 each.
(This gives them 1*1 = 1 mascot.)
The total number of mascots they obtained is 2 + 1 = 3.


2)
3
4

Returns: -1

There is a single slime of size 3.
The players cannot get 4 mascots in any way.


3)
765
271828

Returns: 14

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SubdividedSlimes {
public:
	int needCut(int S, int M) {
		for (int d = 2; d <= S; ++d) {
			int sum = 0, t = 0;
			int r = S % d;
			for (int i = 0; i < d; ++i) {
				int a = (S / d) + (i < r);
				sum += t * a;
				t += a;
			}
			if (sum >= M) {
				return d - 1;
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
			int Arg0 = 3;
			int Arg1 = 2;
			int Arg2 = 1;

			verify_case(n, Arg2, needCut(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			int Arg2 = 2;

			verify_case(n, Arg2, needCut(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 4;
			int Arg2 = -1;

			verify_case(n, Arg2, needCut(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 765;
			int Arg1 = 271828;
			int Arg2 = 14;

			verify_case(n, Arg2, needCut(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SubdividedSlimes ___test;
	___test.run_test(-1);
}
// END CUT HERE
