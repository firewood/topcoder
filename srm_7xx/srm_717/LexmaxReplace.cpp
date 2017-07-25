// BEGIN CUT HERE
/*
SRM 717 Div2 Medium (500)

PROBLEM STATEMENT

Alice has a string s of lowercase letters.
The string is written on a wall.

Alice also has a set of cards.
Each card contains a single letter.
Alice can take any card and glue it on top of one of the letters of s.
She may use any subset of cards in this way, possibly none or all of them.
She is not allowed to glue new letters in front of s or after s, she can only replace the existing letters.

Alice wants to produce the lexicographically largest possible string.

You are given the string s.
You are also given a string t.
Each character of t is a letter written on one of the cards.
Compute and return the lexicographically largest string Alice can produce on the wall while following the rules described above.


DEFINITION
Class:LexmaxReplace
Method:get
Parameters:string, string
Returns:string
Method signature:string get(string s, string t)


NOTES
-Given two distinct strings X and Y of the same length, the lexicographically larger one is the one that has a larger character on the first position on which they differ.


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-t will contain between 1 and 50 characters, inclusive.
-s will contain only lowercase English letters ('a' - 'z').
-t will contain only lowercase English letters ('a' - 'z').


EXAMPLES

0)
"abb"
"c"

Returns: "cbb"

Alice has a single card.
This card contains the letter 'c'.
The optimal solution is to glue it on top of s[0], producing the string "cbb".


1)
"z"
"f"

Returns: "z"

Here the optimal solution is to do nothing. The card with the letter 'f' will remain unused.


2)
"fedcba"
"ee"

Returns: "feeeba"


3)
"top"
"coder"

Returns: "trp"


4)
"xldyzmsrrwzwaofkcxwehgvtrsximxgdqrhjthkgfucrjdvwlr"
"xfpidmmilhdfzypbguentqcojivertdhshstkcysydgcwuwhlk"

Returns: "zyyyzyxwwwzwvuuttxwtssvtssxrqxppqrontmmllukrkjvwlr"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class LexmaxReplace {
public:
	string get(string s, string t) {
		int pos = 0;
		sort(t.rbegin(), t.rend());
		for (char c : t) {
			while (pos != s.length() && s[pos] >= c) {
				++pos;
			}
			if (pos == s.length()) {
				break;
			}
			s[pos++] = c;
		}
		return s;
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
			string Arg0 = "abb";
			string Arg1 = "c";
			string Arg2 = "cbb";

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "z";
			string Arg1 = "f";
			string Arg2 = "z";

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "fedcba";
			string Arg1 = "ee";
			string Arg2 = "feeeba";

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "top";
			string Arg1 = "coder";
			string Arg2 = "trp";

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "xldyzmsrrwzwaofkcxwehgvtrsximxgdqrhjthkgfucrjdvwlr";
			string Arg1 = "xfpidmmilhdfzypbguentqcojivertdhshstkcysydgcwuwhlk";
			string Arg2 = "zyyyzyxwwwzwvuuttxwtssvtssxrqxppqrontmmllukrkjvwlr";

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LexmaxReplace ___test;
	___test.run_test(-1);
}
// END CUT HERE
