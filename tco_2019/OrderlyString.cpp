// BEGIN CUT HERE
/*
Collegiate Programmers in South America Medium (500)

PROBLEM STATEMENT
You are given string s consisting of characters 'A'-'Z'.

You wish to delete some characters from the string, such that the characters that remain are all in non-decreasing order.

Return the length of the longest possible string that remains.


DEFINITION
Class:OrderlyString
Method:longestLength
Parameters:string
Returns:int
Method signature:int longestLength(string s)


CONSTRAINTS
-s will contain between 1 and 200 characters, inclusive.
-Each character of s will be in the range 'A'-'Z'.


EXAMPLES

0)
"ABCDEFG"

Returns: 7

We don't actually need to remove any characters.


1)
"GFEDCBA"

Returns: 1

The characters initially are all in the wrong order, best we can do is leave only one.


2)
"ACBB"

Returns: 3

ABB is the longest.

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

class OrderlyString {
public:
	int longestLength(string s) {
		int dp[256][256] = {};
		for (int i = 0; i < (int)s.length(); ++i) {
			int c = s[i];
			for (int j = 'A'; j <= 'Z'; ++j) {
				dp[i + 1][j] = dp[i][j];
			}
			for (int j = 'A'; j <= c; ++j) {
				dp[i + 1][c] = max(dp[i + 1][c], dp[i][j] + 1);
			}
		}
		int ans = 0;
		for (int j = 'A'; j <= 'Z'; ++j) {
			ans = max(ans, dp[s.length()][j]);
		}
		return ans;
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
			string Arg0 = "ABCDEFG";
			int Arg1 = 7;

			verify_case(n, Arg1, longestLength(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "GFEDCBA";
			int Arg1 = 1;

			verify_case(n, Arg1, longestLength(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ACBB";
			int Arg1 = 3;

			verify_case(n, Arg1, longestLength(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			string Arg0 = "BACBB";
			int Arg1 = 3;

			verify_case(n, Arg1, longestLength(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OrderlyString ___test;
	___test.run_test(-1);
}
// END CUT HERE
