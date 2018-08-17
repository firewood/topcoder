// BEGIN CUT HERE
/*
TCO18 Fun Round Beijing Medium (500)

PROBLEM STATEMENT

In this problem, 
a word is a string with the following properties:

Each of its characters is a lowercase English letter ('a'-'z'), a digit ('0'-'9'), or an underscore ('_').
The string is non-empty and it does not begin with a digit.

For instance, "ax3d", "com", "_3x_9", and "_" are all words, but "x.f", "", and "3xf" are not words.

A phrase is a string that can be obtained by concatenating a non-empty sequence of words while placing a single period ('.') between each pair of words.
Formally:

A word is a phrase.
If P is a phrase and W is a word, P + '.' + W is also a phrase.
No other strings are phrases.

For instance, "ax3d.com._x3x_9" is a phrase that was produced by concatenating three words: "ax3d", "com", and "_x3x_9".
The strings "abc" and "_._" are also phrases.
However, "", ".", "com..com", "com.3def", "..com", and "3xdf" are not phrases.

You are given a word w.
We are looking for all possible phrases with the following property: if you replace every period in the phrase by an underscore, you will obtain the given word w.
Compute and return the number of such phrases, modulo 10^9 + 7.


DEFINITION
Class:WordAndPhraseDiv1
Method:findNumberOfPhrases
Parameters:string
Returns:int
Method signature:int findNumberOfPhrases(string w)


CONSTRAINTS
-w will contain between 1 and 1,000 characters, inclusive.
-Each character in w will be a lowercase English letter, a digit, or an underscore.
-The first character of w will not be a digit.


EXAMPLES

0)
"tco_topcoder_com"

Returns: 4

There are four phrases that turn into "tco_topcoder_com" when we replace each period by an underscore:

tco_topcoder_com
tco_topcoder.com
tco.topcoder_com
tco.topcoder.com


1)
"tcotopcodercom"

Returns: 1

The only matching phrase is the word itself.


2)
"_tco18_admin_id_is_secret"

Returns: 16

A phrase cannot begin with a period.


3)
"____"

Returns: 3

This w consists of four consecutive underscores. The three matching patterns are "____", "_.__", and "__._".


4)
"a0_a1_a2_a3_a4_a5_a6_a7_a8_a9_a0_a1_a2_a3_a4_a5_a6_a7_a8_a9_a0_a1_a2_a3_a4_a5_a6_a7_a8_a9_a0"

Returns: 73741817

Remember to use the modular arithmetics in your calculations. The exact number of matching phrases in this test case is obviously 2^30.


5)
"d0_0b"

Returns: 1

This is a word, but changing the underscore to a period does not make it a valid phrase - remember that a word cannot start with a digit.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

const LL MOD = 1000000007LL;

class WordAndPhraseDiv1 {
public:
	int findNumberOfPhrases(string w) {
		static LL dp[1024][1024];
		memset(dp, 0, sizeof(dp));
		int len = (int)w.length();
		dp[0][1] = 1;
		for (int i = 0; i < len; ++i) {
			char c = w[i];
			if (isdigit(c)) {
				dp[i + 1][0] = dp[i][0];
			} else if (isalpha(c)) {
				dp[i + 1][0] = (dp[i][0] + dp[i][1]) % MOD;
			} else if (c == '.') {
				dp[i + 1][0] = dp[i][0];
			} else if (c == '_') {
				dp[i + 1][0] = (dp[i][0] + dp[i][1]) % MOD;
				dp[i + 1][1] = dp[i][0];
			}
		}
		return dp[len][0];
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
			string Arg0 = "tco_topcoder_com";
			int Arg1 = 4;

			verify_case(n, Arg1, findNumberOfPhrases(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "tcotopcodercom";
			int Arg1 = 1;

			verify_case(n, Arg1, findNumberOfPhrases(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "_tco18_admin_id_is_secret";
			int Arg1 = 16;

			verify_case(n, Arg1, findNumberOfPhrases(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "____";
			int Arg1 = 3;

			verify_case(n, Arg1, findNumberOfPhrases(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "a0_a1_a2_a3_a4_a5_a6_a7_a8_a9_a0_a1_a2_a3_a4_a5_a6_a7_a8_a9_a0_a1_a2_a3_a4_a5_a6_a7_a8_a9_a0";
			int Arg1 = 73741817;

			verify_case(n, Arg1, findNumberOfPhrases(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "d0_0b";
			int Arg1 = 1;

			verify_case(n, Arg1, findNumberOfPhrases(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WordAndPhraseDiv1 ___test;
	___test.run_test(0);
}
// END CUT HERE
