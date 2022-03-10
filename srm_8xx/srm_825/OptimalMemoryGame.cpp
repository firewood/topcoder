// BEGIN CUT HERE
/*
SRM 825 Div1 Easy (250)

PROBLEM STATEMENT

You have a deck of 52 cards. 
Each card has a single uppercase English letter ('A'-'Z').
Each letter is used exactly twice, so the deck contains 26 pairs of cards.

You are going to use the cards to play the memory game with your friends.
You shuffled the deck of cards and placed them onto the table.
The cards are arranged into a single row and they are all face-down (i.e., the letters on them are not visible).

The memory game is played in turns.
In each turn, the active player starts by selecting one of the cards and turning it over.
After seeing the letter on this card, the player then selects and turns over another card.
If the two cards are distinct, they are turned face down again and the turn ends.
If they form a pair, the player scores a point and takes those cards away from the table.
Then, the player gets to repeat the whole process until they either reveal two cards that don't match, or find and remove the last pair of cards.

Some (possibly zero) turns of the game have already been played by other players.
It is now your turn to play the game.
There are 2*N cards still on the table. 

(Note that during the game only pairs of matching cards are removed from the game, and thus it is guaranteed that those 2*N cards contain N pairs of matching cards.)

The string known represents what you currently know about the cards that are still in play.
Each character represents one of the cards.
If the character is a letter, you are certain that the card has that specific letter.
Otherwise, the character is '-' (dash) and it means that you don't know anything about the card. (Maybe you haven't seen it, maybe you just forgot what it was.)

What is the maximum number of pairs you are guaranteed to find this turn, if you play the game optimally (i.e., in a way that maximizes this number)?
Calculate and return this number of pairs.


DEFINITION
Class:OptimalMemoryGame
Method:findPairs
Parameters:string
Returns:int
Method signature:int findPairs(string known)


NOTES
-We want to stress that the two cards selected by the player are not selected at the same time. Instead, they are selected and revealed one at a time. When selecting the second card ("looking for a pair"), the player already knows what letter was on the first card they selected, and this information can influence the choice of the second card.


CONSTRAINTS
-N will be between 1 and 26, inclusive.
-known will contain exactly 2*N characters.
-Each character in known will be an uppercase English letter or a dash.
-Each letter will appear at most twice in known.
-There will be at most N distinct letters in known.


EXAMPLES

0)
"AEIOUIAEUO"

Returns: 5

All ten remaining cards have already been revealed and you know what they are. You can simply collect all pairs, one after another.


1)
"----------"

Returns: 0

The best you can do is flip some pair of cards. You aren't guaranteed that they will match. (In fact, it's likely that they won't.) Thus, you aren't guaranteed to find any pairs here, regardless of what strategy you use.


2)
"--------A----E-----IAO----U---"

Returns: 1

The pair of As is the only pair you can collect here. After you do so, you may get lucky and find another pair, but this isn't guaranteed to happen.


3)
"-X"

Returns: 1

Sometimes we can guarantee to find a pair even if we aren't actually given the positions of both cards in it.
For example, here the only unknown card is clearly the second X, and once we know that, we can guarantee that we can find and collect a matching pair.

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

class OptimalMemoryGame {
public:
	int findPairs(string known) {
		int ans = 0, cnt = 0;
		map<int, int> m;
		for (char c : known) {
			if (c == '-') {
				++cnt;
			} else {
				m[c] += 1;
				if (m[c] == 2) {
					m.erase(c);
					ans += 1;
				}
			}
		}
		if (m.size() == cnt) {
			ans += cnt;
		} else {
			ans += cnt == 2;
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
			string Arg0 = "AEIOUIAEUO";
			int Arg1 = 5;

			verify_case(n, Arg1, findPairs(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "----------";
			int Arg1 = 0;

			verify_case(n, Arg1, findPairs(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "--------A----E-----IAO----U---";
			int Arg1 = 1;

			verify_case(n, Arg1, findPairs(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "-X";
			int Arg1 = 1;

			verify_case(n, Arg1, findPairs(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			string Arg0 = "--";
			int Arg1 = 1;

			verify_case(n, Arg1, findPairs(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			string Arg0 = "A-B-";
			int Arg1 = 2;

			verify_case(n, Arg1, findPairs(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OptimalMemoryGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
