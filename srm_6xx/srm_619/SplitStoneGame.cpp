// BEGIN CUT HERE
/*
SRM 619 Div1 Easy (250)

PROBLEM STATEMENT

Shiny likes to play games.
Her favorite games are games with pebbles (small stones).
Today, she is playing such a game with her friend Lucy.

Initially, there are N piles of stones.
You are given a vector <int> number with N elements.
Each element of number is the number of stones in one of the piles.

The players take alternating turns.
Shiny plays first.
In each turn, the current player must:

Choose a pile X that has at least two stones.
Split the chosen pile X into two non-empty parts A and B. (The parts can have arbitrary sizes, as long as both are non-empty.)
Choose two piles Y and Z. (Y and Z must be different non-empty piles other than X.)
Add all stones from A to the pile X, and all stones from B to the pile Y.


For example, if the current piles are {1, 2, 50}, the current player could:

Choose the pile with 50 stones as X.
Split it into two parts with 25 stones each.
Choose the other two piles (the ones with 1 and 2 stones) to be Y and Z.
Add all stones from A to the pile X, and all stones from B to the pile Y. At the end of the turn, there are two piles of stones: one with 26 and one with 27 stones.


The player who cannot make a valid move loses the game.
Assume that both players play the game optimally.
Return the string "WIN" (quotes for clarity) if Shiny wins the game, and "LOSE" if she does not.


DEFINITION
Class:SplitStoneGame
Method:winOrLose
Parameters:vector <int>
Returns:string
Method signature:string winOrLose(vector <int> number)


CONSTRAINTS
-number will contain between 1 and 50 elements, inclusive.
-Each element of number will be between 1 and 50, inclusive.


EXAMPLES

0)
{1, 1, 1}

Returns: "LOSE"

Shiny can't choose a pile X that has at least two stones, so she loses.


1)
{2, 2}

Returns: "LOSE"

After Shiny chooses one of the piles as X and splits it into two piles with one stone each, she is
unable to choose Y and Z, because there is only one pile left to choose from at the moment. Thus,
she cannot make a valid move and therefore she loses the game.


2)
{1, 1, 2}

Returns: "WIN"

Shiny can choose the last pile as X, split it into 1+1 stone, and add those stones to the other two
piles. This is a valid move that produces two piles with two stones each, and it is now Lucy's turn. 
As we saw in Example 1, Lucy now has no valid move left, thus she loses the game and Shiny is the
winner.


3)
{1, 2, 3, 4, 3, 2, 2, 4, 3, 1, 4, 4, 1, 2, 4, 4, 1, 4, 3, 1, 4, 2, 1}

Returns: "WIN"


4)
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 3, 1, 9, 1, 3, 1, 1, 1, 1, 1}

Returns: "LOSE"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SplitStoneGame {
public:
	string winOrLose(vector <int> number) {
		sort(number.begin(), number.end());
		int len = (int)number.size();
		if (len <= 2 || number[len - 1] == 1 || (len % 2) == 0) {
			return "LOSE";
		}
		return "WIN";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1};
			string Arg1 = "LOSE";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, winOrLose(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 2};
			string Arg1 = "LOSE";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, winOrLose(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 2};
			string Arg1 = "WIN";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, winOrLose(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4, 3, 2, 2, 4, 3, 1, 4, 4, 1, 2, 4, 4, 1, 4, 3, 1, 4, 2, 1};
			string Arg1 = "WIN";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, winOrLose(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 3, 1, 9, 1, 3, 1, 1, 1, 1, 1};
			string Arg1 = "LOSE";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, winOrLose(Arg0));
		}
		n++;




		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 1 };
			string Arg1 = "LOSE";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, winOrLose(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 1, 1 };
			string Arg1 = "LOSE";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, winOrLose(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 1, 2 };
			string Arg1 = "LOSE";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, winOrLose(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 1, 1, 1, 1 };
			string Arg1 = "LOSE";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, winOrLose(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 1, 1, 2, 2, 2,1 };
			string Arg1 = "LOSE";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, winOrLose(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SplitStoneGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
