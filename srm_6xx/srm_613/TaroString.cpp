// BEGIN CUT HERE
/*
SRM 613 Div2 Easy (250)


PROBLEM STATEMENT

Cat Taro has a string S.
He wants to obtain the string "CAT" from the string S.
In a single turn he can choose any character and erase all occurrences of this character in S.
He can do as many turns as he wants (possibly zero).

You are given the string S.
Return "Possible" (quotes for clarity) if it is possible to obtain the string "CAT" and "Impossible" otherwise.


DEFINITION
Class:TaroString
Method:getAnswer
Parameters:string
Returns:string
Method signature:string getAnswer(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-S will contain only uppercase English letters ('A'-'Z').


EXAMPLES

0)
"XCYAZTX"

Returns: "Possible"

It is possible to obtain string "CAT" in three turns, as follows:
Erase all characters 'X' (and obtain the string "CYAZT")
Erase all characters 'Y' (and obtain the string "CAZT")
Erase all characters 'Z' (and obtain the string "CAT")


1)
"CTA"

Returns: "Impossible"


2)
"ACBBAT"

Returns: "Impossible"

Note that whenever you are erasing a character, you must erase all its occurrences. In this case, it is not possible to erase the first 'A' and keep the second one.


3)
"SGHDJHFIOPUFUHCHIOJBHAUINUIT"

Returns: "Possible"


4)
"CCCATT"

Returns: "Impossible"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TaroString {
public:
	string getAnswer(string S) {
		string s;
		for (char c : S) {
			switch (c) {
			case 'C':
			case 'A':
			case 'T':
				s += c;
				break;
			}
		}
		return s == "CAT" ? "Possible" : "Impossible";
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
			string Arg0 = "XCYAZTX";
			string Arg1 = "Possible";

			verify_case(n, Arg1, getAnswer(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "CTA";
			string Arg1 = "Impossible";

			verify_case(n, Arg1, getAnswer(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ACBBAT";
			string Arg1 = "Impossible";

			verify_case(n, Arg1, getAnswer(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "SGHDJHFIOPUFUHCHIOJBHAUINUIT";
			string Arg1 = "Possible";

			verify_case(n, Arg1, getAnswer(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "CCCATT";
			string Arg1 = "Impossible";

			verify_case(n, Arg1, getAnswer(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TaroString ___test;
	___test.run_test(-1);
}
// END CUT HERE
