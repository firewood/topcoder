// BEGIN CUT HERE
/*
SRM 754 Div2 Medium (500)

PROBLEM STATEMENT

Alice had some positive integer A with at most 500 digits.
Bob looked at A and computed the number B: the sum of seventh powers of digits of A.

For example, if Alice had the number A = 407, Bob computed the number B = 4^7 + 0^7 + 7^7 = 839927.

You are given the number B.
Find and return a string containing the decimal representation of any valid number A.


DEFINITION
Class:SeventhPowers
Method:reconstructA
Parameters:int
Returns:string
Method signature:string reconstructA(int B)


NOTES
-The answer always exists.
-Any valid answer will be accepted. (Remember that A must have at most 500 digits.)
-The string you return cannot have leading zeros.


CONSTRAINTS
-B will be between 1 and 10,000,000, inclusive.


EXAMPLES

0)
839927

Returns: "407"


1)
130

Returns: "121"


2)
43740

Returns: "33333333333333333333"

20 * 3^7 = 43,740.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class SeventhPowers {
	string find(int d, int r) {
		if (d <= 1) {
			return string(r, '1');
		}
		int x = 1;
		for (int i = 0; i < 7; ++i) {
			x *= d;
		}
		int y = r / x;
		string z;
		for (int i = max(0, y - 2); i <= y; ++i) {
			string t = string(i, '0' + d) + find(d - 1, r - i * x);
			if (z.empty() || t.length() < z.length()) {
				z = t;
			}
		}
		return z;
	}

public:
	string reconstructA(int B) {
		string ans = find(9, B);
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
			int Arg0 = 839927;
			string Arg1 = "407";

			verify_case(n, Arg1, reconstructA(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 130;
			string Arg1 = "121";

			verify_case(n, Arg1, reconstructA(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 43740;
			string Arg1 = "33333333333333333333";

			verify_case(n, Arg1, reconstructA(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SeventhPowers ___test;
	___test.run_test(-1);
}
// END CUT HERE
