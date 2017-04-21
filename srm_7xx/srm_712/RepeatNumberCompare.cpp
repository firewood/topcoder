// BEGIN CUT HERE
/*
SRM 712 Div2 Easy (250)

PROBLEM STATEMENT
For any two positive integers x and k we can make a new number denoted repeat(x, k) by concatenating k copies of x written in decimal.
For example, repeat(1234,3) = 123412341234 and repeat(70,4) = 70707070.

You are given the ints x1, k1, x2, and k2.
Let v1 = repeat(x1, k1) and v2 = repeat(x2, k2).
Please compare the numbers v1 and v2 and return a string that describes the result of the comparison.
In particular:

Return "Less" if v1 is less than v2.
Return "Greater" if v1 is greater than v2.
Return "Equal" if v1 and v2 are equal.


DEFINITION
Class:RepeatNumberCompare
Method:compare
Parameters:int, int, int, int
Returns:string
Method signature:string compare(int x1, int k1, int x2, int k2)


NOTES
-The return value is case-sensitive.


CONSTRAINTS
-x1 will be between 1 and 1,000,000,000, inclusive.
-k1 will be between 1 and 50, inclusive.
-x2 will be between 1 and 1,000,000,000, inclusive.
-k2 will be between 1 and 50, inclusive.


EXAMPLES

0)
1234
3
70
4

Returns: "Greater"

v1 = 123412341234 and v2 = 70707070, so we have v1 > v2.


1)
1010
3
101010
2

Returns: "Equal"

This time we have v1 = v2 = 101010101010.


2)
1234
10
456
20

Returns: "Less"

v1 has 40 digits and v2 has 60 digits, so v1 < v2.


3)
5
9
555555555
1

Returns: "Equal"


4)
5
9
555555554
1

Returns: "Greater"


5)
5
9
555555556
1

Returns: "Less"


6)
1000000000
50
1000000000
50

Returns: "Equal"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class RepeatNumberCompare {
public:
	string compare(int x1, int k1, int x2, int k2) {
		string a, b;
		stringstream sa, sb;
		for (int i = 0; i < k1; ++i) {
			sa << x1;
		}
		sa >> a;
		for (int i = 0; i < k2; ++i) {
			sb << x2;
		}
		sb >> b;
		string ans;
		if (a == b) {
			ans = "Equal";
		} else if (a.length() < b.length()) {
			ans = "Less";
		} else if (a.length() > b.length()) {
			ans = "Greater";
		} else {
			ans = a < b ? "Less" : "Greater";
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
			int Arg0 = 1234;
			int Arg1 = 3;
			int Arg2 = 70;
			int Arg3 = 4;
			string Arg4 = "Greater";

			verify_case(n, Arg4, compare(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1010;
			int Arg1 = 3;
			int Arg2 = 101010;
			int Arg3 = 2;
			string Arg4 = "Equal";

			verify_case(n, Arg4, compare(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1234;
			int Arg1 = 10;
			int Arg2 = 456;
			int Arg3 = 20;
			string Arg4 = "Less";

			verify_case(n, Arg4, compare(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 9;
			int Arg2 = 555555555;
			int Arg3 = 1;
			string Arg4 = "Equal";

			verify_case(n, Arg4, compare(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 9;
			int Arg2 = 555555554;
			int Arg3 = 1;
			string Arg4 = "Greater";

			verify_case(n, Arg4, compare(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 9;
			int Arg2 = 555555556;
			int Arg3 = 1;
			string Arg4 = "Less";

			verify_case(n, Arg4, compare(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000000;
			int Arg1 = 50;
			int Arg2 = 1000000000;
			int Arg3 = 50;
			string Arg4 = "Equal";

			verify_case(n, Arg4, compare(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RepeatNumberCompare ___test;
	___test.run_test(-1);
}
// END CUT HERE
