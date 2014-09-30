// BEGIN CUT HERE
/*
SRM 470 Div1 Easy (250)

PROBLEM STATEMENT
John and Gogo are playing Doors Game. This game is played in a building containing a single row of N+1 rooms, numbered 0 through N from left to right. One of the rooms is called the trophy room. There's a door between each pair of adjacent rooms. Each door has a color, and there are 16 possible colors (represented by uppercase letters 'A' through 'P'). All doors are initially closed.

Initially, John is in room 0 and Gogo is in room N. The two players alternate turns, and John gets the first turn. On each turn, the current player chooses a color which hasn't yet been chosen from among the 16 possible colors. All doors, if any, with the chosen color are then opened. At this point, if one of the players can reach the trophy room by walking through only open doors, that player wins and the game ends. If both players can reach the trophy room, the game ends in a draw. If neither player can reach the trophy room, the game continues.

Each player will play according to the following strategy:
Each time a player needs to choose a color, he will make make his choice as follows:

If it's possible for him to choose a color in such a way that he will be able to win no matter what his opponent does, he will choose such a color. If there are several such colors, he will choose the one among them for which the game will end with the fewest total number of colors chosen, assuming that the opponent aims to maximize the number of colors chosen in the game.
Otherwise, if it's possible for him to choose a color in such a way that he will be able to end the game in a draw no matter what his opponent does, he will choose any such color.
Otherwise, he will choose a color for which the game will end with the largest total number of colors chosen, assuming that his opponent aims to win while minimizing the total number of colors chosen.

You are given the colors of the doors in the string doors. The i-th character in doors is the color of the door connecting rooms i and i+1. You are also given an int trophy, which denotes the number of the trophy room. If the game ends in a draw, return 0. Otherwise, let X be the number of colors chosen in the game. If John wins, return X. If Gogo wins, return -X.


DEFINITION
Class:DoorsGame
Method:determineOutcome
Parameters:string, int
Returns:int
Method signature:int determineOutcome(string doors, int trophy)


CONSTRAINTS
-doors will contain between 2 and 50 characters, inclusive.
-Each character in doors will be an uppercase letter 'A'-'P'.
-trophy will be between 1 and N-1, inclusive, where N is the number of characters in doors.


EXAMPLES

0)
"ABCD"
2

Returns: 3

There are five rooms, with the trophy room in the middle. John will win after he chooses color A and B.


1)
"ABCC"
2

Returns: -2

In this case, Gogo will win by just choosing color C.


2)
"ABABAB"
3

Returns: 0

When colors A and B have been chosen, both players will be able to reach the trophy room.


3)
"ABAPDCAA"
5

Returns: -4


4)
"MOCFDCE"
3

Returns: 5


5)
"ABCCDE"
3

Returns: 0


6)
"ABCCD"
3

Returns: 0

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

static inline int popcount(unsigned int b)
{
#ifdef __GNUC__
	return __builtin_popcount(b);
#elif _MSC_VER >= 1400
	return __popcnt(b);
#else
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	b += b >> 16;
	return b & 0x3F;
#endif
}

class DoorsGame {
public:
	int determineOutcome(string doors, int trophy) {
		int a = 0, b = 0;
		for (int i = 0; i < trophy; ++i) {
			a |= (1 << (doors[i] - 'A'));
		}
		for (int i = trophy; i < (int)doors.size(); ++i) {
			b |= (1 << (doors[i] - 'A'));
		}
		int c = popcount(a), d = popcount(b), e = popcount(a&b);
		if (c + e > d && d + e >= c) {
			return 0;
		}
		if (d < c) {
			return -2 * d;
		}
		return 2 * c - 1;
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
			string Arg0 = "ABCD";
			int Arg1 = 2;
			int Arg2 = 3;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABCC";
			int Arg1 = 2;
			int Arg2 = -2;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABABAB";
			int Arg1 = 3;
			int Arg2 = 0;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABAPDCAA";
			int Arg1 = 5;
			int Arg2 = -4;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "MOCFDCE";
			int Arg1 = 3;
			int Arg2 = 5;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABCCDE";
			int Arg1 = 3;
			int Arg2 = 0;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABCCD";
			int Arg1 = 3;
			int Arg2 = 0;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABCB";
			int Arg1 = 2;
			int Arg2 = 0;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arg0 = "BCABA";  //c-b-a
			int Arg1 = 3;
			int Arg2 = 0;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABCBA";  //c-b-a
			int Arg1 = 3;
			int Arg2 = 0;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "EBFDCAE";
			int Arg1 = 4;
			int Arg2 = 0;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DoorsGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
