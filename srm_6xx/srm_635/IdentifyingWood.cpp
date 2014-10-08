// BEGIN CUT HERE
/*
SRM 635 Div2 Easy (250)

PROBLEM STATEMENT

We call a pair of strings (s, t) "wood" if t is contained in s as a subsequence. (See Notes for a formal definition.)

Given strings s and t, return the string "Yep, it's wood." (quotes for clarity) if the pair (s, t) is wood and "Nope." otherwise.


DEFINITION
Class:IdentifyingWood
Method:check
Parameters:string, string
Returns:string
Method signature:string check(string s, string t)


NOTES
-String t is contained in string s as a subsequence if we can obtain t by removing zero or more (not necessarily consecutive) characters from s.


CONSTRAINTS
-s and t will consist only of lowercase English letters.
-s and t will each be between 1 and 10 characters long, inclusive.


EXAMPLES

0)
"absdefgh"
"asdf"

Returns: "Yep, it's wood."


1)
"oxoxoxox"
"ooxxoo"

Returns: "Nope."


2)
"oxoxoxox"
"xxx"

Returns: "Yep, it's wood."


3)
"qwerty"
"qwerty"

Returns: "Yep, it's wood."


4)
"string"
"longstring"

Returns: "Nope."

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class IdentifyingWood {
public:
	string check(string s, string t) {
		int pos = 0;
		for (int i = 0; i < (int)s.length(); ++i) {
			if (s[i] == t[pos]) {
				++pos;
				if (pos >= (int)t.length()) {
					return "Yep, it's wood.";
				}
			}
		}
		return "Nope.";
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
			string Arg0 = "absdefgh";
			string Arg1 = "asdf";
			string Arg2 = "Yep, it's wood.";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "oxoxoxox";
			string Arg1 = "ooxxoo";
			string Arg2 = "Nope.";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "oxoxoxox";
			string Arg1 = "xxx";
			string Arg2 = "Yep, it's wood.";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "qwerty";
			string Arg1 = "qwerty";
			string Arg2 = "Yep, it's wood.";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "string";
			string Arg1 = "longstring";
			string Arg2 = "Nope.";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	IdentifyingWood ___test;
	___test.run_test(-1);
}
// END CUT HERE
