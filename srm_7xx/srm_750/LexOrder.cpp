// BEGIN CUT HERE
/*
SRM 750 Div2 Easy (250)

PROBLEM STATEMENT

In this problem, all strings are strings of lowercase English letters ('a'-'z').

You are given the strings A and B such that A < B.
If there is a string C such that A < C < B, return any such string.
(The returned string C must have at most 50 characters, and each character of C must be a lowercase English letter.)
If there is no such string C, return the string "IMPOSSIBLE" instead.

Below, we define how to compare two strings.
This definition is the standard one and we include it just to have a complete, self-contained problem statement.
If you already know how string comparison works, you do not have to read it.

Suppose S and T are two distinct strings.
We say that S is smaller than T in lexicographic order (denoted S < T) if:

either S is a proper prefix of T,
or there is some i >= 0 such that:
    
    the first i characters of S are the same as the first i characters of T
    the next character of S is smaller than the next character of T

For example:

"car" < "careful" because "car" is a proper prefix of "careful"
"dog" < "donut" because the first two characters of both strings are the same ("do") and 'g' is smaller than 'n'.


DEFINITION
Class:LexOrder
Method:between
Parameters:string, string
Returns:string
Method signature:string between(string A, string B)


NOTES
-The statements "character x is smaller than character y", "character x is earlier in the alphabet than character y", and "character x has a smaller ASCII code than character y" are equivalent.
-The return value is case-sensitive. The string IMPOSSIBLE must be in all-uppercase.


CONSTRAINTS
-A will have between 1 and 10 characters, inclusive.
-B will have between 1 and 10 characters, inclusive.
-Each character of A and B will be a lowercase English letter ('a'-'z').
-A will be lexicographically smaller than B.


EXAMPLES

0)
"car"
"dog"

Returns: "careful"

Other valid return values include "ceiling", "catastrophiccancellation", "darling", "do", and "dododododo".


1)
"car"
"cat"

Returns: "cash"


2)
"abcdefghij"
"abcdefghik"

Returns: "abcdefghijklmnopqrst"

Note that the input strings always have at most 10 characters but the string you return may be longer (up to 50 characters).


3)
"man"
"mana"

Returns: "IMPOSSIBLE"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class LexOrder {
public:
	string between(string A, string B) {
		A += 'a';
		return A < B ? A : "IMPOSSIBLE";
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
			string Arg0 = "car";
			string Arg1 = "dog";
			string Arg2 = "careful";

			verify_case(n, Arg2, between(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "car";
			string Arg1 = "cat";
			string Arg2 = "cash";

			verify_case(n, Arg2, between(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcdefghij";
			string Arg1 = "abcdefghik";
			string Arg2 = "abcdefghijklmnopqrst";

			verify_case(n, Arg2, between(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "man";
			string Arg1 = "mana";
			string Arg2 = "IMPOSSIBLE";

			verify_case(n, Arg2, between(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LexOrder ___test;
	___test.run_test(-1);
}
// END CUT HERE
