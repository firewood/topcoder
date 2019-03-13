// BEGIN CUT HERE
/*
SRM 752 Div2 Easy (250)

PROBLEM STATEMENT

Two players are playing poker.
At the beginning of the game, player 1 had X dollars and player 2 had Y dollars.
You know that X and Y were nonnegative integers such that X + Y = 10,000.

The players have already played three rounds of the game.
Each round looked as follows:

Player 1 bet all the money they had.
Player 2 called. (That is, they bet the same amount of money.)
They revealed their hands. Player 1 won and received both bets.

You are given the int T.
Can player 2 have exactly T dollars after the third round of the game?
If they cannot, return -1.
Otherwise, compute and return Y: the amount of dollars player 2 had in the beginning.
(This value is always unique.)


DEFINITION
Class:PokerRound
Method:amount
Parameters:int
Returns:int
Method signature:int amount(int T)


NOTES
-Player 2 cannot bet money they don't have. For example, X=9000 and Y=1000 is not possible because in the first round of the game player 2 does not have enough money to call player 1's bet.


CONSTRAINTS
-T will be between 0 and 10,000, inclusive.


EXAMPLES

0)
2000

Returns: 9000

Here's how the game played out:

In the beginning, player 1 had X = 1000 and player 2 had Y = 9000 dollars.
Player 1 bet 1000, player 2 called, player 1 won. Player 1 got back the 1000 dollars he bet + the 1000 dollars player 2 bet. Thus, after the first round, player 1 has 2000 dollars and player 2 has 8000 dollars.
In the second game player 1 bet 2000, player 2 called, and player 1 won. After round 2 player 1 has 4000 and player 2 has 6000 dollars.
In the third game player 1 bet 4000, player 2 called, and player 1 won again. Thus, at the end of the game player 1 has 8000 and player 2 has T = 2000 dollars.

You are given the value T = 2000 and you are supposed to compute and return the matching value Y = 9000.


1)
10000

Returns: 10000

Player 1 had no money and player 2 had all the money. Then they played three rounds. In each round, player 1 bet 0, player 2 called with 0, and player 1 won 0. Thus, in the end player 2 still has all the money.


2)
1722

Returns: -1

There is no pair (X,Y) such that player 2 ends up with T = 1722 dollars in the end.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class PokerRound {
public:
	int amount(int T) {
		int x = (10000 - T) / 8;
		int y = T + x * 7;
		return x >= 0 && (x + y == 10000) ? y : -1;
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
			int Arg0 = 2000;
			int Arg1 = 9000;

			verify_case(n, Arg1, amount(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10000;
			int Arg1 = 10000;

			verify_case(n, Arg1, amount(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1722;
			int Arg1 = -1;

			verify_case(n, Arg1, amount(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PokerRound ___test;
	___test.run_test(-1);
}
// END CUT HERE
