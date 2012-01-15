// BEGIN CUT HERE
/*
// SRM 526.5 Div2 Hard (1000)
// PROBLEM STATEMENT
// Today is the Christmas Eve. People around the world celebrate this 
holiday. The following story takes place in the land of reindeer, where Santa Claus resides.

The reindeer have invented a new magic spell. To pick a name for the spell,
they decided to concatenate their own names.

Of course, this can be done in multiple ways. For example, if there are two reindeer
called "bob" and "bobby", they could call the spell either "bobbobby" or "bobbybob".
To resolve this ambiguity, the reindeer picked the lexicographically smallest possibility.
(In this case, that would be "bobbobby".)

You are given a string magicName. This is the name of the spell. You do not know
how many reindeer invented the spell and what their names were. Your method must compute
and return the largest possible number of reindeer that could have invented the spell.

DEFINITION
Class:MagicNaming
Method:maxReindeers
Parameters:string
Returns:int
Method signature:int maxReindeers(string magicName)


NOTES
-Given two distinct strings of equal length, the lexicographically smaller one is the one
with a smaller character in the first position where they differ
-The name of each reindeer is a nonempty string of lowercase letters.
-It is always possible that the spell was created by a single reindeer, so the return value is always defined.
-Note that multiple reindeer may share the same name. See Example #5 for clarification.


CONSTRAINTS
-The length of magicName will be between 1 and 50, inclusive.
-Each character in magicName will be between 'a' and 'z', inclusive.


EXAMPLES

0)
"aba"

Returns: 2

The magic spell called "aba" could have been invented by two reindeer called "a" and "ba".

Note that this spell could not have been invented by three reindeer. Their names would have to be "a", "b", and "a". However, reindeer with these names would choose the name "aab" for their spell.

1)
"babbaba"

Returns: 2

In this case there might have been two reindeer called "ba" and "bbaba". More than two reindeer would never pick this name for their spell.

2)
"philosophersstone"

Returns: 5



3)
"knuthmorrispratt"

Returns: 7



4)
"acrushpetrtourist"

Returns: 7



5)
"zzzzz"

Returns: 5

Note that multiple reindeer may share the same name.

#line 87 "MagicNaming.cpp"
*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

class MagicNaming {
	static int compare(const char *a, const char *b, int len_a, int len_b) {
		int c = strncmp(a, b, min(len_a, len_b));
		if (c == 0 && len_a != len_b) {
			c = len_a > len_b ? 1 : -1;
		}
		return c;
	}

public:
	int maxReindeers(string magicName) {
		int result = 0;
		int i, j, k, l;
		int len = magicName.length();
		const char *s = magicName.c_str();

		int dp[60][60] = {0};
		for (i = len - 1; i >= 0; --i) {
			dp[i][len - i] = 1;
			for (j = (len - i); j >= 1; --j) {
				int m = 0;
				for (k = len - i - j; k > 0; --k) {
					if (dp[i+j][k] > 0 && compare(s + i, s + i + j, j, k) <= 0) {
						m = max(m, 1 + dp[i+j][k]);
					}
				}
				dp[i][j] = max(dp[i][j], m);
			}
		}

		for (i = 1; i <= len; ++i) {
			result = max(result, dp[0][i]);
		}
		return result;
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
			string Arg0 = "aba";
			int Arg1 = 2;

			verify_case(n, Arg1, maxReindeers(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "babbaba";
			int Arg1 = 2;

			verify_case(n, Arg1, maxReindeers(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "philosophersstone";
			int Arg1 = 5;

			verify_case(n, Arg1, maxReindeers(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "knuthmorrispratt";
			int Arg1 = 7;

			verify_case(n, Arg1, maxReindeers(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "acrushpetrtourist";
			int Arg1 = 7;

			verify_case(n, Arg1, maxReindeers(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "zzzzz";
			int Arg1 = 5;

			verify_case(n, Arg1, maxReindeers(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicNaming ___test;
//	___test.run_test(0);
//	___test.run_test(1);
	___test.run_test(3);
//	___test.run_test(-1);
	return 0;
}
// END CUT HERE
