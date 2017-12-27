// BEGIN CUT HERE
/*
SRM 726 Div2 Easy (250)

PROBLEM STATEMENT
Hero has a string of lowercase English letters.
Each letter that appears in the string appears exactly twice.

Hero now wants to remove one half of his string.
More precisely, he wants to remove one of the two copies of each letter in his string.
The order of the letters he does not remove will remain unchanged.

If there are multiple ways to remove the letters, Hero prefers the ones where the resulting string begins with a smaller letter (i.e., a letter that is earlier in the alphabet).

You are given the string s containing Hero's string.
Find the smallest letter that can appear at the beginning of the string after Hero removes half of the letters.
Return a string with a single character: that letter.


DEFINITION
Class:StringHalving
Method:lexsmallest
Parameters:string
Returns:string
Method signature:string lexsmallest(string s)


CONSTRAINTS
-s will contain between 2 and 50 characters, inclusive.
-Each character in s will be between 'a' and 'z', inclusive.
-Each letter from 'a' to 'z' will have either zero or two occurrences in s.


EXAMPLES

0)
"baba"

Returns: "a"

Hero can remove the first 'b' and the second 'a' to obtain the string "ab".


1)
"bbaa"

Returns: "b"

Regardless of which 'a' and which 'b' Hero removes, the resulting string will always be "ba".


2)
"zyiggiyssz"

Returns: "g"


3)
"topcodertpcder"

Returns: "c"


4)
"rvofqorvfq"

Returns: "f"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class StringHalving {
public:
	string lexsmallest(string s) {
		int rindex = -1;
		for (char c : s) {
			rindex = max(rindex, (int)(find(s.rbegin(), s.rend(), c) - s.rbegin()));
		}
		char ans = 'z';
		for (char c : s.substr(0, s.length() - 1 - rindex)) {
			ans = min(ans, c);
		}
		return string(1, ans);
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
			string Arg0 = "baba";
			string Arg1 = "a";

			verify_case(n, Arg1, lexsmallest(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "bbaa";
			string Arg1 = "b";

			verify_case(n, Arg1, lexsmallest(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "zyiggiyssz";
			string Arg1 = "g";

			verify_case(n, Arg1, lexsmallest(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "topcodertpcder";
			string Arg1 = "c";

			verify_case(n, Arg1, lexsmallest(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "rvofqorvfq";
			string Arg1 = "f";

			verify_case(n, Arg1, lexsmallest(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	StringHalving ___test;
	___test.run_test(-1);
}
// END CUT HERE
