// BEGIN CUT HERE
/*
// SRM 541 Div2 Easy (250)

// PROBLEM STATEMENT
// 
Consider the following function:
f(X) = Waai + X + Akari + X + Daisuki
Here, X is a string and + denotes string concatenation.
Waai, Akari and Daisuki are constant non-empty strings.

You are given a string S.
Compute and return the number of different tuples (Waai,Akari,Daisuki,X) such that f(X) equals S.


DEFINITION
Class:AkariDaisukiDiv2
Method:countTuples
Parameters:string
Returns:int
Method signature:int countTuples(string S)


NOTES
-Two tuples (A,B,C,D) and (E,F,G,H) are considered equal if and only if A=E, B=F, C=G, and D=H.


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-Each character of S will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"topcoderdivtwo"

Returns: 2

The possible tuples of (Waai, Akari, Daisuki, X) are the following ones:

("t", "pc", "derdivtwo", "o")
("topco", "er", "ivtwo", "d")

("topc", "derdivtw", "", "o") is not allowed since Daisuki is empty.


1)
"foxciel"

Returns: 0

The answer can be zero.


2)
"magicalgirl"

Returns: 4


3)
"waaiusushioakariusushiodaisuki"

Returns: 75


4)
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"

Returns: 8924

*/
// END CUT HERE
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class AkariDaisukiDiv2 {

public:
	int countTuples(string S) {
		int result = 0;
		int i, j, k;
		int N = S.length();
		const char *s = S.c_str();
		for (i = 1; i <= (N-4); ++i) {
			for (j = 1; j <= (N-i-3); ++j) {
				for (k = i+j+1; k <= (N-j-1); ++k) {
					if (memcmp(s+i, s+k, j) == 0) {
						++result;
					}
				}
			}
		}
		return result;
	}

// BEGIN CUT HERE
private:
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "topcoderdivtwo";
			int Arg1 = 2;

			verify_case(n, Arg1, countTuples(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "foxciel";
			int Arg1 = 0;

			verify_case(n, Arg1, countTuples(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "magicalgirl";
			int Arg1 = 4;

			verify_case(n, Arg1, countTuples(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "waaiusushioakariusushiodaisuki";
			int Arg1 = 75;

			verify_case(n, Arg1, countTuples(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
			int Arg1 = 8924;

			verify_case(n, Arg1, countTuples(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AkariDaisukiDiv2 ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
