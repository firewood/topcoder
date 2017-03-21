// BEGIN CUT HERE
/*
SRM 698 Div2 Medium (500)

PROBLEM STATEMENT
A string S is called a square if there is some string T such that S = T + T.
For example, the strings "", aabaab" and "xxxx" are squares, but "a", "aabb" and "aabbaa" are not.

You are given a string s.
Find the longest square string that can be obtained from s by erasing some (possibly none, possibly all) of its characters.
In other words, we are looking for the longest square that occurs in s as a subsequence.
Return the length of that square.

Note that the answer is well-defined, as the square "" (the empty string) will always occur in s as a subsequence.


DEFINITION
Class:RepeatStringEasy
Method:maximalLength
Parameters:string
Returns:int
Method signature:int maximalLength(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character in s will be a lowercase English letter ('a'-'z').


EXAMPLES

0)
"frankfurt"

Returns: 4

The longest square that occurs in "frankfurt" is "frfr". Its length is 4.


1)
"single"

Returns: 0

The letters in the string "single" are all distinct. Hence, the only square that occurs in this string is "". The length of this square is zero.


2)
"singing"

Returns: 6


3)
"aababbababbabbbbabbabb"

Returns: 18


4)
"x"

Returns: 0

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int lcs(const string &a, const string &b) {
	int dp[52][52] = {};
	for (int i = 0; i != a.length(); ++i) {
		for (int j = 0; j != b.length(); ++j) {
			if (a[i] == b[j]) {
				dp[i + 1][j + 1] = 1 + dp[i][j];
			} else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}
	return dp[a.length()][b.length()];
}

class RepeatStringEasy {
public:
	int maximalLength(string s) {
		int ans = 0;
		int len = (int)s.length();
		for (int i = 1; i < len; ++i) {
			ans = max(ans, lcs(s.substr(0, i), s.substr(i, len - i)));
		}
		return ans * 2;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "frankfurt";
			int Arg1 = 4;

			verify_case(n, Arg1, maximalLength(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "single";
			int Arg1 = 0;

			verify_case(n, Arg1, maximalLength(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "singing";
			int Arg1 = 6;

			verify_case(n, Arg1, maximalLength(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aababbababbabbbbabbabb";
			int Arg1 = 18;

			verify_case(n, Arg1, maximalLength(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "x";
			int Arg1 = 0;

			verify_case(n, Arg1, maximalLength(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RepeatStringEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
