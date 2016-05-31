// BEGIN CUT HERE
/*
SRM 691 Div2 Easy (300)

PROBLEM STATEMENT
Hero plays a game with a deck of cards and a counter.
Initially, the counter is set to zero.
During the game Hero must play each card in the deck exactly once.
He gets to choose the order in which he plays the cards.

You are given the description of the deck in the string s.
Each character of s is either '+' or a digit ('0'-'9').
Each character represents one card, as described below.

Whenever Hero plays a card with a '+', the counter is incremented. (I.e., its value is increased by 1.)

Whenever Hero plays a card with a digit, he gets some (possibly zero) penalty points.
The number of penalty points is calculated as abs(C - D), where C is the current value of the counter and D is the digit on the card.

Hero wants to minimize the sum of penalty points he receives during the game.
Find an order in which he should play the cards, and return that order in a string.
If there are multiple optimal orders of cards, return the lexicographically smallest among them.


DEFINITION
Class:Plusonegame
Method:getorder
Parameters:string
Returns:string
Method signature:string getorder(string s)


NOTES
-Let S and T be two different but equally long strings, and let i be the smallest index such that S[i] and T[i] differ. We say that S is lexicographically smaller than T if the character S[i] has a smaller ASCII value than the character T[i].
-The ASCII value of the '+' character is smaller than the ASCII values of digits.


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character in s will be either '+' or digit('0' - '9').


EXAMPLES

0)
"1++"

Returns: "+1+"

Hero should increment the counter to 1, then play the card '1' for 0 penalty points, and then increment the counter again.


1)
"549"

Returns: "459"

Each of the six possible permutations of these cards leads to the same result: Hero will receive 4+5+9 = 18 penalty points.
The string "459" is the lexicographically smallest of the six possible strings.


2)
"++++++"

Returns: "++++++"


3)
"+++++2+"

Returns: "++2++++"


4)
"++++4++++200++2++1+6++++++"

Returns: "00+1+22++4++6+++++++++++++"


5)
"++11199999"

Returns: "+111+99999"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Plusonegame {
public:
	string getorder(string s) {
		int cnt[256] = {};
		for (char c : s) {
			cnt[(int)c] += 1;
		}
		string ans;
		for (char i = '0'; i <= '9'; ++i) {
			ans += string(cnt[(int)i], i);
			if (cnt['+']) {
				ans += "+";
				cnt['+'] -= 1;
			}
		}
		ans += string(cnt[(int)'+'], '+');
		return ans;
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
			string Arg0 = "1++";
			string Arg1 = "+1+";

			verify_case(n, Arg1, getorder(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "549";
			string Arg1 = "459";

			verify_case(n, Arg1, getorder(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "++++++";
			string Arg1 = "++++++";

			verify_case(n, Arg1, getorder(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "+++++2+";
			string Arg1 = "++2++++";

			verify_case(n, Arg1, getorder(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "++++4++++200++2++1+6++++++";
			string Arg1 = "00+1+22++4++6+++++++++++++";

			verify_case(n, Arg1, getorder(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "++11199999";
			string Arg1 = "+111+99999";

			verify_case(n, Arg1, getorder(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Plusonegame ___test;
	___test.run_test(-1);
}
// END CUT HERE
