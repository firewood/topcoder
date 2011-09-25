// BEGIN CUT HERE
/*
// SRM 511 Div2 Hard (1000)
// PROBLEM STATEMENT
// Fox Ciel and Toastman are playing a game.


The game uses a memory and N cards. Initially the value of the memory is set to zero.
You are given a vector <int> cards containing exactly N elements.
cards[i] is the number written on the i-th card.


Ciel and Toastman take alternate turns, and Ciel plays first. In each turn,
the player chooses a card and removes the card from the game (this card can't be used later).
If the chosen card contains x and the value of the memory is y, the value of the memory is changed to (x | y).
The '|' symbol stands for bitwise OR (see notes for clarification).
If a player can't make a move (because there are no cards left),
or if after a player's move the memory becomes 511, this player loses.


Determine the winner when both players play optimally. If Fox Ciel wins, return "Fox Ciel" (quotes for clarity).
If Toastman wins, return "Toastman" (quotes for clarity).


DEFINITION
Class:FiveHundredEleven
Method:theWinner
Parameters:vector <int>
Returns:string
Method signature:string theWinner(vector <int> cards)


NOTES
-If a and b are single bits then a | b is defined as max(a, b). For two integers, A and B,
in order to calculate A | B, they need to be represented in binary:
A = (an...a1)2, B = (bn...b1)2 (if the lengths of their representations are different,
the shorter one is prepended with the necessary number of leading zeroes).
Then A | B = C = (cn...c1)2, where ci = ai | bi. For example, 10 | 3 = (1010)2 | (0011)2 = (1011)2 = 11.


CONSTRAINTS
-cards will contain between 1 and 50 elements, inclusive.
-Each element of cards will be between 0 and 511, inclusive.


EXAMPLES

0)
{3, 5, 7, 9, 510}

Returns: "Fox Ciel"

If Fox Ciel chooses 510 in her first turn, the value of the memory after Toastman's turn becomes 511
regardless of his choice.

1)
{0, 0, 0, 0}

Returns: "Toastman"

The value of the memory never becomes 511. After each player chooses 2 cards,
there are no cards left and Fox Ciel loses.

2)
{511}

Returns: "Toastman"

After Fox Ciel chooses the only card in her first turn, the value of the memory becomes 511 and Fox Ciel loses.

3)
{5, 58, 192, 256}

Returns: "Fox Ciel"



#line 65 "FiveHundredEleven.cpp"
*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

typedef unsigned long long ULL;

typedef vector<int> IV;

class FiveHundredEleven {
	bool isWinner(const IV &c, int v, ULL f) {
		if (f == 0) {
			return false;
		}

		ULL b = 1;
		int i;
		for (i = 0; i < (int)c.size(); ++i) {
			if (f & b) {
				int nv = v | c[i];
				if (nv != 511 && !isWinner(c, nv, f ^ b)) {
					return true;
				}
			}
			b <<= 1;
		}

		return false;
	}

public:
	string theWinner(vector <int> cards) {
		ULL f = (1LL << cards.size()) - 1;
		return isWinner(cards, 0, f) ? "Fox Ciel" : "Toastman";
	}
};

// BEGIN CUT HERE
template <typename T> static T __str_to_val(const char *p)
{
	return p;
}
template <> static int __str_to_val(const char *p)
{
	return atoi(p);
}
template <typename T> vector<T> getVector(const char *s)
{
	static const int buffer_size = 1024000;
	static char buffer[buffer_size];
	strcpy(buffer, s);
	vector <T> v;
	char *p = strtok(buffer, " ,");
	while (p) {
		v.push_back(__str_to_val<T>(p));
		p = strtok(NULL, " ,");
	}
	return v;
}

static void Test(const char *seq, const char *expected)
{
	vector <int> v = getVector<int>(seq);
	FiveHundredEleven ___test;
	string result = ___test.theWinner(v);
	printf("result: %s, %s\n", strcmp(result.c_str(), expected) == 0 ? "OK" : "FAILED", result.c_str());
}

int main() {
//	Test("3,5,7,9,510", "Fox Ciel");
//	Test("0,0,0,0", "Toastman");
//	Test("511", "Toastman");
//	Test("5,58,192,256", "Fox Ciel");
	Test("77,389,61,361,289,255,195,13,485,476,239,317,234,310,372,426,478,29,356,30,60,439,349,261,440,117,459,253,289,495,350,167,115,492,338,394,429,243,177,368,11,282,393,227,405,372,364,56,276,160", "FoxCiel");
	return 0;
}
// END CUT HERE
