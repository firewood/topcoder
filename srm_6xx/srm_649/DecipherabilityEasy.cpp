// BEGIN CUT HERE
/*
SRM 649 Div2 Easy (250)

PROBLEM STATEMENT
You had a non-empty string s but you lost it.
Cat Snuke found the string and removed one character from the string.
Later, Snuke gave you the string t.
Can this be the string created from your string s?

You are given the strings s and t.
Return "Possible" (quotes for clarity) if t can be obtained from s by erasing exactly one character.
Otherwise, return "Impossible".
Note that the return value is case-sensitive.


DEFINITION
Class:DecipherabilityEasy
Method:check
Parameters:string, string
Returns:string
Method signature:string check(string s, string t)


CONSTRAINTS
-The number of characters in s will be between 1 and 50, inclusive.
-Every character in s will be a lowercase letter ('a'-'z').
-The number of characters in t will be between 1 and 50, inclusive.
-Every character in t will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"sunuke"
"snuke"

Returns: "Possible"

If Cat Snuke erase the first 'u' from s, it will equal to t.


1)
"snuke"
"skue"

Returns: "Impossible"

Swapping characters is not allowed.


2)
"snuke"
"snuke"

Returns: "Impossible"

Erasing nothing is not allowed.


3)
"snukent"
"snuke"

Returns: "Impossible"

Cat Snuke can erase exactly one character.

4)
"aaaaa"
"aaaa"

Returns: "Possible"


5)
"aaaaa"
"aaa"

Returns: "Impossible"


6)
"topcoder"
"tpcoder"

Returns: "Possible"


7)
"singleroundmatch"
"singeroundmatc"

Returns: "Impossible"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class DecipherabilityEasy {
public:
	string check(string s, string t) {
		for (int i = 0; i < (int)s.length(); ++i) {
			if ((s.substr(0, i) + s.substr(i + 1)) == t) {
				return "Possible";
			}
		}
		return "Impossible";
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
			string Arg0 = "sunuke";
			string Arg1 = "snuke";
			string Arg2 = "Possible";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "snuke";
			string Arg1 = "skue";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "snuke";
			string Arg1 = "snuke";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "snukent";
			string Arg1 = "snuke";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaaa";
			string Arg1 = "aaaa";
			string Arg2 = "Possible";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaaa";
			string Arg1 = "aaa";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "topcoder";
			string Arg1 = "tpcoder";
			string Arg2 = "Possible";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			string Arg0 = "singleroundmatch";
			string Arg1 = "singeroundmatc";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DecipherabilityEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
