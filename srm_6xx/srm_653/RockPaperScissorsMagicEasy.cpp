// BEGIN CUT HERE
/*
SRM 653 Div2 Medium (500)

PROBLEM STATEMENT

Alice and Bob are going to play a variant of the traditional rock-paper-scissors game.
Their game is played using cards.
Each card shows one of the three pictures: a rock, a paper, or scissors.
There is a sufficient supply of cards of each type.
Bob has already chosen a sequence of cards and he has arranged them into a row, face down.
It is now Alice's turn to do the same.
Once she does that, they will use the two sequences of cards to play the game:
For each i, Alice's i-th card and Bob's i-th card will be revealed and compared using the standard rules of rock-paper-scissors.
Whenever Alice's card wins, Alice gets a point.
Alice gets no points for a loss or a tie.

Alice has marked Bob's cards, so now she can tell which card has which symbol on it.
You are given this information as a vector <int> card.
Each element of card is between 0 and 2, inclusive: 0 is a rock, 1 is a paper, and 2 are scissors.

You are also given an int score.
Alice has just announced that she will get a total of score points.

Let X be the number of sequences in which Alice can play her cards if she wants to achieve exactly score points.
Return the value (X modulo 1,000,000,007).


DEFINITION
Class:RockPaperScissorsMagicEasy
Method:count
Parameters:vector <int>, int
Returns:int
Method signature:int count(vector <int> card, int score)


CONSTRAINTS
-The number of elements in card will be between 1 and 2,000, inclusive.
-All elements of card will be between 0 and 2, inclusive.
-score will be between 0 and 2,000, inclusive.


EXAMPLES

0)
{0,1,2}
2

Returns: 6

Bob has played his cards in the order rock-paper-scissors.
Alice wants to score 2 points.
Hence, she must win twice, and lose to Bob or tie him once.

One possible way in which she can play her cards is paper-scissors-scissors:
her paper beats Bob's rock (1 point), scissors beat paper (1 point), and scissors tie with scissors (0 points).

There are five other ways how Alice can score 2 points: paper-scissors-paper, paper-paper-rock, paper-rock-rock, rock-scissors-rock, and scissors-scissors-rock.


1)
{1,2}
0

Returns: 4


2)
{2,2,1,0,0}
10

Returns: 0


3)
{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
7

Returns: 286226628


4)
{0,1,2,0,1,2,2,1,0}
8

Returns: 18

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

#define COMBSZ 2048
#define MOD 1000000007LL

class RockPaperScissorsMagicEasy {
public:
	int count(vector <int> card, int score) {
		LL N = card.size();
		if (score > N) {
			return 0;
		}
		static LL C[COMBSZ][COMBSZ];
		for (LL i = 0; i < COMBSZ; ++i) {
			C[i][0] = 1;
			for (LL j = 1; j <= i; ++j) {
				C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
			}
		}
		LL ans = C[N][score];
		LL R = N - score;
		for (LL i = 0; i < R; ++i) {
			ans = (ans * 2) % MOD;
		}
		return (int)ans;
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
			int Arr0[] = {0,1,2};
			int Arg1 = 2;
			int Arg2 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2};
			int Arg1 = 0;
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,1,0,0};
			int Arg1 = 10;
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
			int Arg1 = 7;
			int Arg2 = 286226628;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,2,0,1,2,2,1,0};
			int Arg1 = 8;
			int Arg2 = 18;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RockPaperScissorsMagicEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
