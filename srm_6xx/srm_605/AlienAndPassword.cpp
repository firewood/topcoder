// BEGIN CUT HERE
/*
SRM 605 Div2 Easy (250)

PROBLEM STATEMENT

Alien Fred wants to destroy the Earth, but he forgot the password that activates the planet destroyer.
You are given a string S.
Fred remembers that the correct password can be obtained from S by erasing exactly one character.
Return the number of different passwords Fred needs to try.


DEFINITION
Class:AlienAndPassword
Method:getNumber
Parameters:string
Returns:int
Method signature:int getNumber(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-Each character in S will be an uppercase English letter ('A'-'Z').


EXAMPLES

0)
"A"

Returns: 1

In this case, the only password Fred needs to try is an empty string.


1)
"ABA"

Returns: 3

The following three passwords are possible in this case: "BA", "AA", "AB".


2)
"AABACCCCABAA"

Returns: 7


3)
"AGAAGAHHHHFTQLLAPUURQQRRRUFJJSBSZVJZZZ"

Returns: 26


4)
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ"

Returns: 1

Regardless of which character we erase, we will always obtain the same string. Thus there is only one possible password: the string that consists of 49 'Z's.

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef set<string> StrSet;

class AlienAndPassword {
public:
	int getNumber(string S) {
		StrSet s;
		for (auto i = 0; i < S.length(); ++i) {
			s.insert(S.substr(0, i) + S.substr(i + 1));
		}
		return s.size();
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
			string Arg0 = "A";
			int Arg1 = 1;

			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABA";
			int Arg1 = 3;

			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AABACCCCABAA";
			int Arg1 = 7;

			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AGAAGAHHHHFTQLLAPUURQQRRRUFJJSBSZVJZZZ";
			int Arg1 = 26;

			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
			int Arg1 = 1;

			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AlienAndPassword ___test;
	___test.run_test(-1);
}
// END CUT HERE
