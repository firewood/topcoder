// BEGIN CUT HERE
/*
SRM 690 Div2 Easy (250)

PROBLEM STATEMENT
A string is called a square if it can be created by concatenating two copies of the same string.
For example, "CANCAN" is a square because it consists of two copies of the string "CAN".
Other squares include "AA", "ZZZZ", and "BERIBERI".
The strings "AAAAA" and "HAHAHA" are not squares.

You are given a string S.
Return "square" (quotes for clarity) if there is a string T such that S = T + T.
Otherwise, return "not square".
Note that the return value is case-sensitive.


DEFINITION
Class:DoubleString
Method:check
Parameters:string
Returns:string
Method signature:string check(string S)


CONSTRAINTS
-The length of S will be between 1 and 50, inclusive.
-Each character in S will be an uppercase letter ('A'-'Z').


EXAMPLES

0)
"MAZAIMAZAI"

Returns: "square"

If T is "MAZAI", T+T will be "MAZAIMAZAI". 


1)
"MAMAZAIZAI"

Returns: "not square"

In this case, there is no string T for which T+T will be S.


2)
"IOI"

Returns: "not square"

The length of S is odd, so it's impossible to make S by concatenating the same string twice.


3)
"AA"

Returns: "square"

T will be "A".


4)
"ABCCBA"

Returns: "not square"


5)
"Y"

Returns: "not square"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class DoubleString {
public:
	string check(string S) {
		int hlen = (int)S.length() / 2;
		return S.substr(0, hlen).compare(S.substr(hlen)) == 0 ? "square" : "not square";
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
			string Arg0 = "MAZAIMAZAI";
			string Arg1 = "square";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "MAMAZAIZAI";
			string Arg1 = "not square";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "IOI";
			string Arg1 = "not square";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AA";
			string Arg1 = "square";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABCCBA";
			string Arg1 = "not square";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Y";
			string Arg1 = "not square";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DoubleString ___test;
	___test.run_test(-1);
}
// END CUT HERE
