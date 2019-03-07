// BEGIN CUT HERE
/*
SRM 752 Div1 Easy (250)

PROBLEM STATEMENT

You are given the string comparisons with n characters.
Each character in comparisons is one of '<', '>', '=', and '!'.
These represent the relations "is less than", "is greater than", "equals", and "does not equal", respectively.

A positive integer X with n+1 digits (and with no leading zeros) is said to match the given comparisons if all the relations are true for pairs of consecutive digits of X, in order.
For example, suppose comparisons is "<<=!".
One integer that matches these comparisons is 14770.
This is because 1<4, 4<7, 7=7, and 7!=0.

If no (n+1)-digit integer matches all the given comparisons, return an empty string.
Otherwise return a string with the digits of the smallest such number.


DEFINITION
Class:ReconstructNumber
Method:smallest
Parameters:string
Returns:string
Method signature:string smallest(string comparisons)


CONSTRAINTS
-comparisons will have between 0 and 2000 characters, inclusive.
-Each character in comparisons will be one of "<>=!".


EXAMPLES

0)
">=!<"

Returns: "10012"

We have 1 > 0, 0 = 0, 0 != 1, and 1 < 2. There are other numbers that match these comparisons, but this one is the smallest of them all. 


1)
"====!===="

Returns: "1111100000"


2)
""

Returns: "1"


3)
">>>>>>>>>>>>>>>>>>>>>>>>>>>>>"

Returns: ""


4)
"><<>><=<=>=>"

Returns: "1012101122110"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class ReconstructNumber {
public:
	string smallest(string comparisons) {
		int len = (int)comparisons.length();
		string dp[2004][10];
		for (int i = 0; i < 10; ++i) {
			dp[len][i] = string(1, '0' + i);
		}
		for (int i = len - 1; i >= 0; --i) {
			for (int j = 0; j <= 9; ++j) {
				for (int k = 0; k <= 9; ++k) {
					if (comparisons[i] == '<' && j < k && !dp[i + 1][k].empty()) {
						dp[i][j] = string(1, '0' + j) + dp[i + 1][k];
						break;
					}
					if (comparisons[i] == '>' && j > k && !dp[i + 1][k].empty()) {
						dp[i][j] = string(1, '0' + j) + dp[i + 1][k];
						break;
					}
					if (comparisons[i] == '=' && j == k && !dp[i + 1][k].empty()) {
						dp[i][j] = string(1, '0' + j) + dp[i + 1][k];
						break;
					}
					if (comparisons[i] == '!' && j != k && !dp[i + 1][k].empty()) {
						dp[i][j] = string(1, '0' + j) + dp[i + 1][k];
						break;
					}
				}
			}
		}
		string ans;
		for (int i = 1; i <= 9; ++i) {
			if (!dp[0][i].empty()) {
				ans = dp[0][i];
				break;
			}
		}
		return ans;
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
			string Arg0 = ">=!<";
			string Arg1 = "10012";

			verify_case(n, Arg1, smallest(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "====!====";
			string Arg1 = "1111100000";

			verify_case(n, Arg1, smallest(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "";
			string Arg1 = "1";

			verify_case(n, Arg1, smallest(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
			string Arg1 = "";

			verify_case(n, Arg1, smallest(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "><<>><=<=>=>";
			string Arg1 = "1012101122110";

			verify_case(n, Arg1, smallest(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			string Arg0 = ">";
			string Arg1 = "10";

			verify_case(n, Arg1, smallest(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			string Arg0 = ">>>>>>>>>";
			string Arg1 = "9876543210";

			verify_case(n, Arg1, smallest(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			string Arg0 = "<<<<<<<<";
			string Arg1 = "123456789";

			verify_case(n, Arg1, smallest(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			string Arg0 = string(2000, '=');
			string Arg1 = string(2001, '1');
			verify_case(n, Arg1, smallest(Arg0));
		}
		n++;
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ReconstructNumber ___test;
	___test.run_test(-1);
}
// END CUT HERE
