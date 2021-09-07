// BEGIN CUT HERE
/*
SRM 812 Div2 Easy (300)

PROBLEM STATEMENT

You are playing Slay the Spire, an excellent deck-builder strategic game.
You are currently taking a turn in a combat.

You have N cards in your hand.
All the cards in your hand are attack cards.
Each of them has a cost (some number of actions you have to spend on using the card) and an effect (the amount of damage it deals to the opponent).

You are given the description of the cards: the vector <int>s actions and damage.
Each of these arrays has exactly N elements.
For each valid index i, you have a card that costs actions[i] actions and deals damage[i] damage.
You can only play each card once.

You can spend up to three actions on playing your cards this turn.

Calculate and return the maximum total amount of damage you can deal.


DEFINITION
Class:SpireAttack
Method:dealMostDamage
Parameters:int, vector <int>, vector <int>
Returns:int
Method signature:int dealMostDamage(int N, vector <int> actions, vector <int> damage)


NOTES
-You may have multiple copies of the same card in your hand. Each of them should be treated just like any other card - i.e., as a separate card that can be played once. (See Example 5.)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-actions will have exactly N elements.
-Each element of actions will be between 1 and 3, inclusive.
-damage will have exactly N elements.
-Each element of damage will be between 1 and 99, inclusive.


EXAMPLES

0)
3
{1, 1, 1}
{2, 4, 6}

Returns: 12

You can play all three cards and deal 2+4+6 damage.


1)
4
{1, 1, 1, 1}
{2, 4, 8, 6}

Returns: 18

Here you only have enough actions to play any three out of these four cards. Clearly, the best solution is to deal 4+6+8 damage.


2)
2
{2, 2}
{5, 6}

Returns: 6

Here we can only play one of these two cards. After we do so, we will be left with one action, but the remaining card requires two actions to play.


3)
3
{2, 2, 1}
{5, 6, 1}

Returns: 7

A similar solution to the previous example but now we also have a card that can be played for one action. An optimal solution is to spend two actions on the card that deals 6 damage and then the remaining action on the card that deals 1 damage.


4)
3
{1, 2, 3}
{1, 4, 9}

Returns: 9

Here we could play the first two cards, but that would only deal 1+4 = 5 damage. A better solution is to play only the third card, which deals 9 damage.


5)
8
{1, 2, 1, 3, 1, 2, 1, 1}
{1, 1, 1, 1, 1, 1, 1, 1}

Returns: 3

We can deal three damage by playing any three of the five cards that cost 1 action each.


6)
2
{1, 3}
{2, 1}

Returns: 2

You do not have to spend all three actions. Here the optimal solution is to spend one action on playing the card that deals 2 damage. (You will be left with two unspent actions + a card you cannot play.)

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

class SpireAttack {
public:
	int dealMostDamage(int N, vector <int> actions, vector <int> damage) {
		int ans = 0;
		for (int i = 0; i < 2; ++i) {
			actions.emplace_back(0);
			damage.emplace_back(0);
		}
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N + 1; ++j) {
				for (int k = j + 1; k < N + 2; ++k) {
					if (actions[i] + actions[j] + actions[k] <= 3) {
						ans = max(ans, damage[i] + damage[j] + damage[k]);
					}
				}
			}
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
			int Arg0 = 3;
			int Arr1[] = {1, 1, 1};
			int Arr2[] = {2, 4, 6};
			int Arg3 = 12;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, dealMostDamage(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {1, 1, 1, 1};
			int Arr2[] = {2, 4, 8, 6};
			int Arg3 = 18;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, dealMostDamage(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {2, 2};
			int Arr2[] = {5, 6};
			int Arg3 = 6;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, dealMostDamage(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {2, 2, 1};
			int Arr2[] = {5, 6, 1};
			int Arg3 = 7;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, dealMostDamage(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {1, 2, 3};
			int Arr2[] = {1, 4, 9};
			int Arg3 = 9;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, dealMostDamage(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arr1[] = {1, 2, 1, 3, 1, 2, 1, 1};
			int Arr2[] = {1, 1, 1, 1, 1, 1, 1, 1};
			int Arg3 = 3;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, dealMostDamage(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {1, 3};
			int Arr2[] = {2, 1};
			int Arg3 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, dealMostDamage(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SpireAttack ___test;
	___test.run_test(-1);
}
// END CUT HERE
