// BEGIN CUT HERE
/*
TCO 2015 Round 2C Easy (250)

PROBLEM STATEMENT
Petr and Snuke are playing a cooperative card game.
The game is played with special cards: each card is labeled with some positive integer.
The integers on cards are not necessarily distinct.

At the beginning of the game Petr is holding some cards in his hand and Snuke is holding all the other cards in his hand.
You are given vector <int>s petr and snuke that describe the state at the beginning of the game:
the elements of petr are the numbers on Petr's cards and the elements of snuke are the numbers on Snuke's cards.

During the game the players will place some of their cards onto a pile.
Initially, the pile is empty.
The players take alternating turns, Petr goes first.
In each turn, if the current player has no cards in his hand, the game ends.
Otherwise, the player must make exactly one valid move.
There are three types of valid moves:

If the pile is empty, the player may choose any card and place it onto the pile.
If the pile is not empty, the player may choose any card and place it on top of the pile. However, this move is only valid if the number on the new card is strictly greater than the number on the card that was previously on the top of the pile.
The player may always choose one of his cards and eat it.

Petr and Snuke have a common goal: they want to create a pile with as many cards as possible.
Return the size of the pile at the end of the game, assuming that they cooperate and play the game optimally.


DEFINITION
Class:YetAnotherCardGame
Method:maxCards
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int maxCards(vector <int> petr, vector <int> snuke)


CONSTRAINTS
-petr and snuke will contain between 1 and 50 elements, inclusive.
-petr and snuke will contain the same number of elements.
-Each element in petr and snuke will be between 1 and 100, inclusive.


EXAMPLES

0)
{2, 5}
{3, 1}

Returns: 3

One optimal way is as follows.

Petr puts 2 onto the pile.
Snuke puts 3 onto the pile.
Petr puts 5 onto the pile.
Snuke eats 1.
The game ends because Petr has no cards in his hand.


1)
{1, 1, 1, 1, 1}
{1, 1, 1, 1, 1}

Returns: 1

The integers on cards are not necessarily distinct.


2)
{1, 4, 6, 7, 3}
{1, 7, 1, 5, 7}

Returns: 6


3)
{19, 99, 86, 30, 98, 68, 73, 92, 37, 69, 93, 28, 58, 36, 86, 32, 46, 34, 71, 29}
{28, 29, 22, 75, 78, 75, 39, 41, 5, 14, 100, 28, 51, 42, 9, 25, 12, 59, 98, 83}

Returns: 28

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef vector<int> IntVec;

typedef long long LL;

// BEGIN CUT HERE
/*
typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<II> IIVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;
typedef set<II> IISet;
typedef set<string> StrSet;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
*/
// END CUT HERE

class YetAnotherCardGame {
public:
	int maxCards(vector <int> petr, vector <int> snuke) {
		int dp[101][101];
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		int N = (int)petr.size();
		for (int i = 0; i < N * 2; ++i) {
			IntVec &v = (i & 1) ? snuke : petr;
			for (int j = 0; j <= 100; ++j) {
				if (dp[i][j] >= 0) {
					dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
					for (int k = 0; k < N; ++k) {
						if (v[k] > j) {
							dp[i + 1][v[k]] = max(dp[i][j] + 1, dp[i + 1][v[k]]);
						}
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i <= 100; ++i) {
			ans = max(ans, dp[N * 2][i]);
		}
		return ans;
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
			int Arr0[] = {2, 5};
			int Arr1[] = {3, 1};
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCards(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1, 1, 1};
			int Arr1[] = {1, 1, 1, 1, 1};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCards(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 4, 6, 7, 3};
			int Arr1[] = {1, 7, 1, 5, 7};
			int Arg2 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCards(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {19, 99, 86, 30, 98, 68, 73, 92, 37, 69, 93, 28, 58, 36, 86, 32, 46, 34, 71, 29};
			int Arr1[] = {28, 29, 22, 75, 78, 75, 39, 41, 5, 14, 100, 28, 51, 42, 9, 25, 12, 59, 98, 83};
			int Arg2 = 28;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCards(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	YetAnotherCardGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
