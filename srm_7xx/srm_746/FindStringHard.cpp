// BEGIN CUT HERE
/*
SRM 746 Div1 Medium (500)

PROBLEM STATEMENT
An antipalindrome is a string which differs from its own reverse at all positions. For instance, "ab", "aabb", "abab", and "abbaab" are antipalindromes, whereas "aaab", "abba", "aababa", "baa", and "a" are not.

A substring is a nonempty contiguous part of a given string. For instance, "aba" is a substring of "aaba" but "aaa" isn't.

Two substrings are considered different if they are located at different positions in the string. For instance, there are two distinct substrings "aba" in the string "ababa".

You are given an int n. Find and return any string with the following properties:

Its length is at most 100.
Each character is either 'a' or 'b'.
The string has exactly n antipalindromic substrings.


DEFINITION
Class:FindStringHard
Method:withAntipalindromicSubstrings
Parameters:int
Returns:string
Method signature:string withAntipalindromicSubstrings(int n)


NOTES
-It can be shown that the answer always exists. If there are multiple solutions, you may print any of them.
-It is not necessary to minimize the length of the returned string.


CONSTRAINTS
-The integer n will be between 0 and 1000, inclusive.


EXAMPLES

0)
3

Returns: "bbaab"

The three antipalindromic substrings of "bbaab" are "bbaa", "ba", and "ab".


1)
8

Returns: "ababbaab"

The eight antipalindromic substrings of "ababbaab" are three copies of "ab", two copies of "ba", and one copy each of "abab", "bbaa", and "abbaab".


2)
139

Returns: "ababaabbaabbaaabbbaaabbbaaaabbbbaaaabbbbaaaaabbbbbaaaaabbbbbaaaaaabbbbbbaaaaaabbbbbb"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int count(const string &s) {
	int cnt = 0;
	int len = (int)s.length();
	for (int i = 0; i < len; ++i) {
		for (int j = 2; i + j <= len; j += 2) {
			int ok = 1;
			for (int k = 0; k < j / 2; ++k) {
				if (s[i + k] == s[i + j - k - 1]) {
					ok = 0;
					break;
				}
			}
			cnt += ok;
		}
	}
	return cnt;
}

class FindStringHard {
public:
	string withAntipalindromicSubstrings(int n) {
		string s = "a";
		while (count(s) != n) {
			int X = rand() % 35;
			int Y = rand() % 30;
			s.resize(2 * X + Y);
			for (int i = 0; i < X; ++i) { s[2 * i] = 'a'; s[2 * i + 1] = 'b'; }
			for (int i = 0; i < Y; ++i) { s[2 * X + i] = "ab"[rand() % 2]; }
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
			int Arg0 = 3;
			string Arg1 = "bbaab";

			verify_case(n, Arg1, withAntipalindromicSubstrings(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			string Arg1 = "ababbaab";

			verify_case(n, Arg1, withAntipalindromicSubstrings(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 139;
			string Arg1 = "ababaabbaabbaaabbbaaabbbaaaabbbbaaaabbbbaaaaabbbbbaaaaabbbbbaaaaaabbbbbbaaaaaabbbbbb";

			verify_case(n, Arg1, withAntipalindromicSubstrings(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FindStringHard ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
