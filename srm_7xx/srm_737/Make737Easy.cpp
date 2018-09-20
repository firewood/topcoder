// BEGIN CUT HERE
/*
SRM 737 Div2 Easy (250)

PROBLEM STATEMENT

This problem has a non-standard time limit: 8 seconds.

You are given a string S.
Each character of S is either '3' or '7'.
Compute and return the number of 737-triples in this string.

An ordered triple (i,j,k) is called a 737-triple if and only if:

i, j, k are valid indices into S
i < j < k
S[i] = '7', S[j] = '3', and S[k] = '7'.


DEFINITION
Class:Make737Easy
Method:count
Parameters:string
Returns:int
Method signature:int count(string S)


CONSTRAINTS
-S will contain between 1 and 373 characters, inclusive.
-Each character of S will be either '3' or '7'.


EXAMPLES

0)
"737"

Returns: 1

The only 737-triple in this string corresponds to the zero-based indices (0,1,2).


1)
"777333"

Returns: 0

As we must have i < j < k, this string does not contain any 737-triples.


2)
"773377"

Returns: 8


3)
"73737"

Returns: 4

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

class Make737Easy {
public:
	int count(string S) {
		int ans = 0;
		int dp[2] = {};
		for (char c : S) {
			if (c == '3') {
				dp[1] += dp[0];
			} else {
				dp[0] += 1;
				ans += dp[1];
			}
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
			string Arg0 = "737";
			int Arg1 = 1;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "777333";
			int Arg1 = 0;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "773377";
			int Arg1 = 8;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "73737";
			int Arg1 = 4;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Make737Easy ___test;
	___test.run_test(-1);
}
// END CUT HERE
