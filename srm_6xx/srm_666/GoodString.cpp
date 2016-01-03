// BEGIN CUT HERE
/*
SRM 666 Div2 Medium (444)

PROBLEM STATEMENT
Chandan loves to play with strings.
He just learned a new operation: inserting one string X into another string Y.

When inserting X into Y, it is also allowed to place X at the beginning or at the end of Y.
For example, there are exactly five ways how to insert the string "ab" into the string "????":
you can produce one of the strings "ab????", "?ab???", "??ab??", "???ab?", and "????ab".

According to Chandan, a good string is a string that can be constructed in the following way:
Initially, he takes the empty string "".
Then, he performs a sequence of zero or more steps.
In each step he inserts the string "ab" anywhere into the current string.

According to the above definition, the strings "ab", "aabb", and "aababb" are good while the strings "aab", "ba", and "abbb" are not good.

Chandan's friend Ravi came up with a string s.
Ravi asked Chandan whether it is a good string.
Return "Good" (quotes for clarity) if the string is good, or "Bad" if the string is not good.


DEFINITION
Class:GoodString
Method:isGood
Parameters:string
Returns:string
Method signature:string isGood(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each element of s will be either 'a' or 'b'.


EXAMPLES

0)
"ab"

Returns: "Good"

Chandan can start with an empty string and insert "ab".

1)
"aab"

Returns: "Bad"



2)
"aabb"

Returns: "Good"

Chandan can construct this string as follows: "" -> "ab" -> "aabb".

3)
"ababab"

Returns: "Good"

One way to construct this string is to append "ab" to the current string three times.

4)
"abaababababbaabbaaaabaababaabbabaaabbbbbbbb"

Returns: "Bad"



5)
"aaaaaaaabbbaaabaaabbabababababaabbbbaabbabbbbbbabb"

Returns: "Good"



*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <cstring>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class GoodString {
	public:
	string isGood(string s) {
		int pos;
		while ((pos = s.find("ab")) >= 0) {
			s = s.substr(0, pos) + s.substr(pos + 2);
		}
		return s.empty() ? "Good" : "Bad";
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
			string Arg0 = "ab";
			string Arg1 = "Good";

			verify_case(n, Arg1, isGood(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aab";
			string Arg1 = "Bad";

			verify_case(n, Arg1, isGood(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aabb";
			string Arg1 = "Good";

			verify_case(n, Arg1, isGood(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ababab";
			string Arg1 = "Good";

			verify_case(n, Arg1, isGood(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abaababababbaabbaaaabaababaabbabaaabbbbbbbb";
			string Arg1 = "Bad";

			verify_case(n, Arg1, isGood(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaaaaaabbbaaabaaabbabababababaabbbbaabbabbbbbbabb";
			string Arg1 = "Good";

			verify_case(n, Arg1, isGood(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GoodString ___test;
	___test.run_test(-1);
}
// END CUT HERE
