// BEGIN CUT HERE
/*
// SRM 556 Div1 Medium (500)

// PROBLEM STATEMENT
// You are playing a solitaire game called Left-Right Digits Game.
This game uses a deck of N cards. Each card has a single digit written on it.
These digits are given as characters in the string digits. More precisely,
the i-th character of digits is the digit written on the i-th card
from the top of the deck (both indices are 0-based).

The game is played as follows. First, you place the topmost card
(whose digit is the 0-th character of digits) on the table. Then,
you pick the cards one-by-one from the top of the deck. For each card,
you have to place it either to the left or to the right of all cards
that are already on the table.

After all of the cards have been placed on the table, they now form an N-digit number.
You are given a string lowerBound that represents an N-digit number.
The primary goal of the game is to arrange the cards in such a way that
the number X shown on the cards will be greater than or equal to lowerBound.
If there are multiple ways to satisfy the primary goal, you want to make
the number X as small as possible.

Return the smallest possible value of X you can achieve, as a string
containing N digits. If it is impossible to achieve a number which is
greater than or equal to lowerBound, return an empty string instead.


DEFINITION
Class:LeftRightDigitsGame2
Method:minNumber
Parameters:string, string
Returns:string
Method signature:string minNumber(string digits, string lowerBound)


NOTES
-lowerBound has no leading zeros. This means that any valid number X should
 also have no leading zeros (since otherwise it will be smaller than lowerBound).


CONSTRAINTS
-digits will contain between 1 and 50 characters, inclusive.
-Each character of digits will be between '0' and '9', inclusive.
-lowerBound will contain the same number of characters as digits.
-Each character of lowerBound will be between '0' and '9', inclusive.
-The first character of lowerBound will not be '0'.


EXAMPLES

0)
"565"
"556"

Returns: "556"

You can achieve exactly 556. The solution is as follows:

Place the first card on the table.
Place the second card to the right of all cards on the table.
Place the last card to the left of all cards on the table.


1)
"565"
"566"

Returns: "655"


2)
"565"
"656"

Returns: ""

The largest number you can achieve is 655, but it is still less than 656.


3)
"9876543210"
"5565565565"

Returns: "5678943210"


4)
"8016352"
"1000000"

Returns: "1086352"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<string> StrVec;

class LeftRightDigitsGame2 {

	string Min(string a, string b) {
		if (a.empty()) {
			return b;
		}
		if (b.empty()) {
			return a;
		}
		return min(a, b);
	}

public:
	string minNumber(string digits, string lowerBound) {
		string ans;
		int sz = (int)digits.length();
		int i, eqlen, pos;
		for (eqlen = 0; eqlen <= sz; ++eqlen) {
			StrVec dp(sz);
			for (pos = 0; pos < sz; ++pos) {
				if (pos < eqlen && digits[0] == lowerBound[pos] ||
						pos == eqlen && digits[0] > lowerBound[pos] ||
						pos > eqlen) {
					dp[pos] = string(1, digits[0]);
				}
			}
			for (i = 1; i < sz; ++i) {
				StrVec prev = dp;
				dp = StrVec(sz);
				for (pos = 0; pos < (sz-i); ++pos) {
					if (!prev[pos+1].empty()) {
						if (pos < eqlen && digits[i] == lowerBound[pos] ||
								pos == eqlen && digits[i] > lowerBound[pos] ||
								pos > eqlen) {
							dp[pos] = Min(dp[pos], digits[i] + prev[pos+1]);
						}
					}
					if (!prev[pos].empty()) {
						if ((pos+i) < eqlen && digits[i] == lowerBound[pos+i] ||
								(pos+i) == eqlen && digits[i] > lowerBound[pos+i] ||
								(pos+i) > eqlen) {
							dp[pos] = Min(dp[pos], prev[pos] + digits[i]);
						}
					}
				}
			}
			ans = Min(ans, dp[0]);
		}
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
			string Arg0 = "565";
			string Arg1 = "556";
			string Arg2 = "556";

			verify_case(n, Arg2, minNumber(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "565";
			string Arg1 = "566";
			string Arg2 = "655";

			verify_case(n, Arg2, minNumber(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "565";
			string Arg1 = "656";
			string Arg2 = "";

			verify_case(n, Arg2, minNumber(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "9876543210";
			string Arg1 = "5565565565";
			string Arg2 = "5678943210";

			verify_case(n, Arg2, minNumber(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "8016352";
			string Arg1 = "1000000";
			string Arg2 = "1086352";

			verify_case(n, Arg2, minNumber(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "36403829258";
			string Arg1 = "83994503502";
			string Arg2 = "84360329258";

			verify_case(n, Arg2, minNumber(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arg0 = "5";
			string Arg1 = "5";
			string Arg2 = "5";

			verify_case(n, Arg2, minNumber(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arg0 = "54880697764616510142";
			string Arg1 = "56781948547726329061";
			string Arg2 = "56784580697461610142";

			verify_case(n, Arg2, minNumber(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arg0 = "522042136022636254641";
			string Arg1 = "559737750935742501186";
			string Arg2 = "560022542136223624641";

			verify_case(n, Arg2, minNumber(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LeftRightDigitsGame2 ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
