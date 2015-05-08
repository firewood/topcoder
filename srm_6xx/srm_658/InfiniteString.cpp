// BEGIN CUT HERE
/*
SRM 658 Div2 Easy (250)

PROBLEM STATEMENT
Given a string s, let f(s) denote the infinite string obtained by concatenating infinitely many copies of s.
For example, if s = "abc" then f(s) = "abcabcabcabc...".

Note that the string f(s) still has a beginning.
Hence, f("abc") and f("bca") are two different infinite strings: the first one starts with an 'a' while the other starts with a 'b'.

Sometimes, two different finite strings can produce the same infinite string.
For example, f("abc") is the same as f("abcabc").

You are given strings s and t.
Check whether f(s) equals f(t).
If the two infinite strings are equal, return "Equal".
Otherwise, return "Not equal".


DEFINITION
Class:InfiniteString
Method:equal
Parameters:string, string
Returns:string
Method signature:string equal(string s, string t)


CONSTRAINTS
-s will contain between 1 and 50 elements, inclusive.
-t will contain between 1 and 50 elements, inclusive.
-Each character in s will be a lowercase English letter ('a'-'z').
-Each character in t will be a lowercase English letter ('a'-'z').


EXAMPLES

0)
"ab"
"abab"

Returns: "Equal"

Both string will generate "ababababab...".


1)
"abc"
"bca"

Returns: "Not equal"


2)
"abab"
"aba"

Returns: "Not equal"

The first one will generate "abababab...", but the second one will generate "abaaba...".


3)
"aaaaa"
"aaaaaa"

Returns: "Equal"


4)
"ababab"
"abab"

Returns: "Equal"


5)
"a"
"z"

Returns: "Not equal"

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class InfiniteString {
public:
	string equal(string s, string t) {
		string a, b;
		for (int i = 0; i < t.length(); ++i) {
			a += s;
		}
		for (int i = 0; i < s.length(); ++i) {
			b += t;
		}
		return a == b ? "Equal" : "Not equal";
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
			string Arg1 = "abab";
			string Arg2 = "Equal";

			verify_case(n, Arg2, equal(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abc";
			string Arg1 = "bca";
			string Arg2 = "Not equal";

			verify_case(n, Arg2, equal(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abab";
			string Arg1 = "aba";
			string Arg2 = "Not equal";

			verify_case(n, Arg2, equal(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaaa";
			string Arg1 = "aaaaaa";
			string Arg2 = "Equal";

			verify_case(n, Arg2, equal(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ababab";
			string Arg1 = "abab";
			string Arg2 = "Equal";

			verify_case(n, Arg2, equal(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "a";
			string Arg1 = "z";
			string Arg2 = "Not equal";

			verify_case(n, Arg2, equal(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	InfiniteString ___test;
	___test.run_test(-1);
}
// END CUT HERE
