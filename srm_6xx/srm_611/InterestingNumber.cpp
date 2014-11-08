// BEGIN CUT HERE
/*
SRM 611 Div2 Easy (250)

PROBLEM STATEMENT
Fox Ciel thinks that the number 41312432 is interesting.
This is because of the following property:
There is exactly 1 digit between the two 1s, there are exactly 2 digits between the two 2s, and so on.

Formally, Ciel thinks that a number X is interesting if the following property is satisfied:
For each D between 0 and 9, inclusive, X either does not contain the digit D at all, or it contains exactly two digits D, and there are precisely D other digits between them.

You are given a string x that contains the digits of a positive integer.
Return "Interesting" if that integer is interesting, otherwise return "Not interesting".


DEFINITION
Class:InterestingNumber
Method:isInteresting
Parameters:string
Returns:string
Method signature:string isInteresting(string x)


CONSTRAINTS
-x will correspond to an integer between 1 and 1,000,000,000, inclusive.
-x will not start with a '0'.


EXAMPLES

0)
"2002"

Returns: "Interesting"

There are 0 digits between the two 0s, and 2 digits between the two 2s, so this is an interesting number.


1)
"1001"

Returns: "Not interesting"

There should be 1 digit between the two 1s, but there are 2 digits between them. Hence, this number is not interesting.


2)
"41312432"

Returns: "Interesting"

This is the number in the statement.


3)
"611"

Returns: "Not interesting"

There is only one digit 6 in this number, so it's not interesting.


4)
"64200246"

Returns: "Interesting"


5)
"631413164"

Returns: "Not interesting"

This number contains the digit 1 three times.

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class InterestingNumber {
public:

	bool check(string x) {
		for (int i = 0; i <= 9; ++i) {
			char c = i + '0';
			int a = x.find(c);
			int b = x.rfind(c);
			if (a < 0) {
				continue;
			}
			if (b - a != i + 1) {
				return false;
			}
			for (int j = a + 1; j < b; ++j) {
				if (x[j] == c) {
					return false;
				}
			}
		}
		return true;
	}

	string isInteresting(string x) {
		return check(x) ? "Interesting" : "Not interesting";
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
			string Arg0 = "2002";
			string Arg1 = "Interesting";

			verify_case(n, Arg1, isInteresting(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "1001";
			string Arg1 = "Not interesting";

			verify_case(n, Arg1, isInteresting(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "41312432";
			string Arg1 = "Interesting";

			verify_case(n, Arg1, isInteresting(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "611";
			string Arg1 = "Not interesting";

			verify_case(n, Arg1, isInteresting(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "64200246";
			string Arg1 = "Interesting";

			verify_case(n, Arg1, isInteresting(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "631413164";
			string Arg1 = "Not interesting";

			verify_case(n, Arg1, isInteresting(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	InterestingNumber ___test;
	___test.run_test(-1);
}
// END CUT HERE
