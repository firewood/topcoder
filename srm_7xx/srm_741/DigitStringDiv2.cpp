// BEGIN CUT HERE
/*
SRM 741 Div2 Easy (250)

PROBLEM STATEMENT

You are given a digit string S and a positive integer integer X.
We want to select a non-empty contiguous substring of S such that:

The substring does not begin with the digit '0'.
When you convert it to a number, its value is strictly greater than X.

Two ways of selecting a substring are different if they begin or end at a different index. 

Compute and return the number of ways in which we can select a substring with the above properties.


DEFINITION
Class:DigitStringDiv2
Method:count
Parameters:string, int
Returns:int
Method signature:int count(string S, int X)


CONSTRAINTS
-S will contain between 1 and 9 characters, inclusive.
-Each character of S will be a digit ('0'-'9').
-X will be between 0 and 777,444,111, inclusive.


EXAMPLES

0)
"0"
1

Returns: 0


1)
"10"
9

Returns: 1


2)
"471"
47

Returns: 2

We can select either the substring "471" or the substring "71".


3)
"2222"
97

Returns: 3

We can select the entire string S ("2222"). We also have two different ways to select the string "222": either we choose the first three or the last three characters of S

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class DigitStringDiv2 {
public:
	int count(string S, int X) {
		int len = (int)S.length();
		int ans = 0;
		for (int i = 0; i < len; ++i) {
			if (S[i] != '0') {
				int k = 0;
				for (int j = i; j < len; ++j) {
					k = k * 10 + S[j] - '0';
					ans += k > X;
				}
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
			string Arg0 = "0";
			int Arg1 = 1;
			int Arg2 = 0;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "10";
			int Arg1 = 9;
			int Arg2 = 1;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "471";
			int Arg1 = 47;
			int Arg2 = 2;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "2222";
			int Arg1 = 97;
			int Arg2 = 3;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DigitStringDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
