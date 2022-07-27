// BEGIN CUT HERE
/*
SRM 834 Div1 Easy (300)

PROBLEM STATEMENT

This problem is about the popular word-guessing game Wordle. Knowledge of this game is not necessary to solve the problem.

There are two strings: the secret string hidden and the puzzle solver's attempt guess.
Each string consists of five uppercase English letters ('A'-'Z').

When the solver makes a guess, the game announces how good the guess was.
This is done using colors.
The letters of the guess that are in correct places are highlighted in green and the letters that are in the secret word but at some other index are highlighted in yellow.

Formally, the coloring works as follows:

A pair of indices (i, j) is called valid if guess[i] = hidden[j].
When coloring the letters of guess we will look for valid pairs of indices.
Among these pairs each index can only be used at most once:
there cannot be two pairs (i, j1) and (i, j2) with j1 != j2, and there cannot be two pairs (i1, j) and (i2, j) with i1 != i2.

We will create these pairs in two passes. 

In the first pass we create all valid pairs of the form (i, i).
These correspond to the green letters.

In the second pass we go through all possible i from 0 to 4, in this order.
For each i, if there is a j such that (i, j) is a valid pair disjoint from all the ones we already have, we take the smallest such j and we add the pair (i, j) to our collection.
For each pair (i, j) added in this step the letter at position i in guess will be yellow.

Return a string of length 5 with the colors assigned to the letters of the given guess. 
Use 'g' for green, 'y' for yellow, and '-' for letters that did not get any color.


DEFINITION
Class:WordleColors
Method:color
Parameters:string, string
Returns:string
Method signature:string color(string hidden, string guess)


CONSTRAINTS
-hidden will have exactly 5 characters.
-Each character in hidden will be an uppercase English letter ('A'-'Z').
-guess will have exactly 5 characters.
-Each character in guess will be an uppercase English letter ('A'-'Z').


EXAMPLES

0)
"BLOCK"
"BRICK"

Returns: "g--gg"

The letters 'B', 'C', 'K' all appear in their correct positions and so they are green. The letters 'R' and 'I' of the guess don't appear in the hidden word and so they don't get a color.


1)
"BLOCK"
"BLOBS"

Returns: "ggg--"

The letter guess[3] = 'B' does not get any color. When coloring the letters green for exact matches we already created the pair (0, 0), i.e., we paired guess[0] = 'B' with the corresponding hidden[0] = 'B'. There is no other 'B' in hidden to pair with guess[3].


2)
"BLURB"
"BOBBY"

Returns: "g-y--"

We first find the pair (0, 0) of 'B's in the right position that makes guess[0] green. Then we find the pair (2, 4) of 'B's that are present but not in the same position. The third 'B' in "BOBBY" has no pair, as "BLURB" only contains two 'B's.


3)
"ABBOT"
"BOBBY"

Returns: "yyg--"


4)
"CANAL"
"AAAAA"

Returns: "-g-g-"


5)
"GREEN"
"BLACK"

Returns: "-----"


6)
"RATES"
"STARE"

Returns: "yyyyy"

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

class WordleColors {
public:
	string color(string hidden, string guess) {
		string ans = "-----", used = "-----";
		for (int i = 0; i < 5; ++i) {
			if (hidden[i] == guess[i]) {
				ans[i] = 'g';
				used[i] = 'g';
			}
		}
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (ans[i] == '-' && used[j] == '-' && guess[i] == hidden[j]) {
					ans[i] = 'y';
					used[j] = 'y';
					break;
				}
			}
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
			string Arg0 = "BLOCK";
			string Arg1 = "BRICK";
			string Arg2 = "g--gg";

			verify_case(n, Arg2, color(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BLOCK";
			string Arg1 = "BLOBS";
			string Arg2 = "ggg--";

			verify_case(n, Arg2, color(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BLURB";
			string Arg1 = "BOBBY";
			string Arg2 = "g-y--";

			verify_case(n, Arg2, color(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABBOT";
			string Arg1 = "BOBBY";
			string Arg2 = "yyg--";

			verify_case(n, Arg2, color(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "CANAL";
			string Arg1 = "AAAAA";
			string Arg2 = "-g-g-";

			verify_case(n, Arg2, color(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "GREEN";
			string Arg1 = "BLACK";
			string Arg2 = "-----";

			verify_case(n, Arg2, color(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RATES";
			string Arg1 = "STARE";
			string Arg2 = "yyyyy";

			verify_case(n, Arg2, color(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			string Arg0 = "ABCDA";
			string Arg1 = "EAAAE";
			string Arg2 = "-yy--";

			verify_case(n, Arg2, color(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WordleColors ___test;
	___test.run_test(-1);
}
// END CUT HERE
