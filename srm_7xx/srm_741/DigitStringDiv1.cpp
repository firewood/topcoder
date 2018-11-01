// BEGIN CUT HERE
/*
SRM 741 Div1 Easy (250)

PROBLEM STATEMENT

You are given a digit string S and a positive integer X.
We are going to erase some (possibly none, but not all) characters of S.
While doing so, we have the following goals:

The string formed by the remaining characters (in their original order) cannot begin with the digit '0'.
When that string is converted to a number, its value must be strictly greater than the given X.

Two ways of erasing characters are different if there is an index i such that S[i] got erased in exactly one of the two ways.

Compute and return the number of ways in which we can erase some characters and achieve the goals stated above.


DEFINITION
Class:DigitStringDiv1
Method:count
Parameters:string, int
Returns:long long
Method signature:long long count(string S, int X)


CONSTRAINTS
-S will contain between 1 and 47 characters, inclusive.
-Each character of S will be a digit ('0'-'9').
-X will be between 0 and 777,444,111, inclusive.


EXAMPLES

0)
"0"
1

Returns: 0


1)
"101"
9

Returns: 3

We can produce one of the strings "10", "11", and "101".


2)
"471"
47

Returns: 2


3)
"2222"
97

Returns: 5

We have one way to produce the string "2222" and four ways to produce the string "222".

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

class DigitStringDiv1 {
public:
	long long count(string S, int X) {
		int slen = (int)S.length();
		char w[64];
		sprintf(w, "%d", X);
		int xlen = (int)strlen(w);

		LL edp[64][64] = {};
		LL gdp[64][64] = {};
		for (int i = 0; i < slen; ++i) {
			edp[i + 1][1] = edp[i][1] + (S[i] == w[0]);
			gdp[i + 1][1] = gdp[i][1] + (S[i] > w[0]);
			for (int j = 1; j <= i && j < xlen; ++j) {
				edp[i + 1][j + 1] = edp[i][j + 1];
				gdp[i + 1][j + 1] = gdp[i][j] + gdp[i][j + 1];
				if (S[i] == w[j]) {
					edp[i + 1][j + 1] += edp[i][j];
				} else if (S[i] > w[j]) {
					gdp[i + 1][j + 1] += edp[i][j];
				}
			}
		}
		LL ans = gdp[slen][xlen];

		LL dp[64][64] = {};
		for (int i = 0; i < slen; ++i) {
			dp[i + 1][1] = dp[i][1] + (S[i] > '0');
			for (int j = 1; j <= i; ++j) {
				dp[i + 1][j + 1] = dp[i][j] + dp[i][j + 1];
			}
		}
		for (int i = xlen + 1; i <= slen; ++i) {
			ans += dp[slen][i];
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "0";
			int Arg1 = 1;
			long long Arg2 = 0LL;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "101";
			int Arg1 = 9;
			long long Arg2 = 3LL;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "471";
			int Arg1 = 47;
			long long Arg2 = 2LL;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "2222";
			int Arg1 = 97;
			long long Arg2 = 5LL;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			string Arg0 = "75000908030900000040005000004010000400099099610";
			int Arg1 = 412711;
			long long Arg2 = 108473978310664LL;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DigitStringDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
