// BEGIN CUT HERE
/*
SRM 718 Div1 Easy (250)

PROBLEM STATEMENT
Correct parentheses sequences can be defined recursively as follows:

The empty string "" is a correct sequence.
If "X" and "Y" are correct sequences, then "XY" (the concatenation of X and Y) is a correct sequence.
If "X" is a correct sequence, then "(X)" is a correct sequence.
Each correct parentheses sequence can be derived using the above rules.


Examples of correct parentheses sequences include "", "()", "()()()", "(()())", and "(((())))".

You are given two strings s1 and s2.
Each character in these strings is a parenthesis, but the strings themselves are not necessarily correct sequences of parentheses.

You would like to interleave the two sequences so that they will form a correct parentheses sequence.
Note that sometimes two different ways of interleaving the two sequences will produce the same final sequence of characters.
Even if that happens, we count each of the ways separately.
(See Example 0 for a clarification.)

Compute and return the number of different ways to produce a correct parentheses sequence, modulo 10^9 + 7.


DEFINITION
Class:InterleavingParenthesis
Method:countWays
Parameters:string, string
Returns:int
Method signature:int countWays(string s1, string s2)


CONSTRAINTS
-s1,s2 will contain between 1 and 2,500 characters, inclusive.
-Each character of s1,s2 will be '(' or ')'.


EXAMPLES

0)
"(()"
"())"

Returns: 19

The 19 ways are:

Here, the red characters come from the first sequence, and the blue characters come from the second sequence.


1)
")"
"("

Returns: 1


2)
"((((("
")))))"

Returns: 42


3)
"()(()"
"))((())"

Returns: 10


4)
"()()()()()()()()()()()()()()()()()()()()"
"()()()()()()()()()()()()()()()()()"

Returns: 487340184

Don't forget about the mod.


5)
"(())())))"
"(())()"

Returns: 0

*/
// END CUT HERE
#include <algorithm>
#include <cstring>
#include <string>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

static const int MOD = 1000000007;

class InterleavingParenthesis {
	int dp[2501][2501];
	int cnt[2501][2501];

public:
	int countWays(string s1, string s2) {
		memset(dp, 0, sizeof(dp));
		memset(cnt, -1, sizeof(cnt));
		int a = (int)s1.length(), b = (int)s2.length();
		dp[0][0] = 1;
		cnt[0][0] = 0;
		for (int i = 0; i <= a; ++i) {
			for (int j = 0; j < b; ++j) {
				if (s2[j] == '(') {
					if (cnt[i][j] >= 0) {
						dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
						cnt[i][j + 1] = cnt[i][j] + 1;
					}
				} else {
					if (cnt[i][j] >= 1) {
						dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
						cnt[i][j + 1] = cnt[i][j] - 1;
					}
				}
			}
			if (i >= a) {
				break;
			}
			for (int j = 0; j <= b; ++j) {
				if (s1[i] == '(') {
					if (cnt[i][j] >= 0) {
						dp[i + 1][j] = dp[i][j];
						cnt[i + 1][j] = cnt[i][j] + 1;
					}
				} else {
					if (cnt[i][j] >= 1) {
						dp[i + 1][j] = dp[i][j];
						cnt[i + 1][j] = cnt[i][j] - 1;
					}
				}
			}
		}
		return cnt[a][b] == 0 ? dp[a][b] : 0;
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
			string Arg0 = "(()";
			string Arg1 = "())";
			int Arg2 = 19;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = ")";
			string Arg1 = "(";
			int Arg2 = 1;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "(((((";
			string Arg1 = ")))))";
			int Arg2 = 42;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "()(()";
			string Arg1 = "))((())";
			int Arg2 = 10;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "()()()()()()()()()()()()()()()()()()()()";
			string Arg1 = "()()()()()()()()()()()()()()()()()";
			int Arg2 = 487340184;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "(())())))";
			string Arg1 = "(())()";
			int Arg2 = 0;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	InterleavingParenthesis ___test;
	___test.run_test(-1);
}
// END CUT HERE
