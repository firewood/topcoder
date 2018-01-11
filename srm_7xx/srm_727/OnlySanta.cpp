// BEGIN CUT HERE
/*
SRM 727 Div1 Easy (250)

PROBLEM STATEMENT
Definition: for two strings X and Y, we say that a string X has a subsequence Y if and only if it's possible to remove 0 or more characters in X so that the remaining characters form the string Y.
For example, "ABCDEFFF" has subsequences "B", "ABFF" and "ABCDEFFF", but doesn't have subsequences "XSFJ", "BA" and "CCDD".

Kids often want to write a letter to Santa but they make a typo and send them to Satan instead.
We say that the address written on an envelope is good if and only if it has the subsequence "SANTA" but it doesn't have the subsequence "SATAN" - otherwise the letter can be sent to the wrong place!

Limak already wrote a string S as the address.
It's guaranteed that S doesn't have the subsequence "SATAN", but possibly it doesn't have the subsequence "SANTA" either.
Your task is to add some (0 or more) characters anywhere into S, including its beginning and end, so that it is a good address, as defined above.

You are given the string S of length up to 1000 consisting of uppercase English letters, representing the currently written address.
Formally, return any string X that satisifes the following conditions:

X has a subsequence S.
X has the subsequence "SANTA".
X doesn't have the subsequence "SATAN".
X has at most 1050 characters.
Each character in X must be an uppercase English letter 'A' - 'Z'.


DEFINITION
Class:OnlySanta
Method:solve
Parameters:string
Returns:string
Method signature:string solve(string S)


NOTES
-It can be proved that a valid answer exists for any valid input.


CONSTRAINTS
-S will contain between 1 and 1000 characters, inclusive.
-Each character in S will be an uppercase English letter: 'A' - 'Z'.
-S will not have the subsequence "SATAN".


EXAMPLES

0)
"STANA"

Returns: "STANTA"

Limak already wrote "STANA".
He can add a single character 'T' to obtain "STANTA".
This string has the subsequence "SANTA" and doesn't have the subsequence "SATAN".


1)
"STN"

Returns: "SANTNA"

Here, one correct solution is to add "AN" between 'S' and 'T' and also add 'A' at the end of the string.
The returned string is: "S(A)(N)TN(A)", where brackets represent added characters.


2)
"RATSNOOOA"

Returns: "DEARATSNOOOSANTA"


3)
"SXAYNTA"

Returns: "OOOOSOXAYNTOOOOAOOO"

One correct answer is simply "SXAYNTA" because this given string already has the subsequence "SANTA".
You don't have to minimize the number of added characters though.


4)
"SNTA"

Returns: "SANTA"


5)
"ASNTA"

Returns: "SASNTAS"


6)
"NIELATA"

Returns: "SANIELATAJA"


7)
"X"

Returns: "SSAAXNNTTAA"


*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

__inline bool contains(const string &source, const string &target) {
	int pos = 0;
	for (char c : target) {
		if (c == source[pos]) {
			++pos;
			if (pos == source.length()) {
				return true;
			}
		}
	}
	return false;
}

class OnlySanta {
public:
	string solve(string S) {
		size_t n = S.rfind('N');
		if (n == string::npos) {
			return "SANTA" + S;
		}
		string p = S.substr(0, n);
		string q = S.substr(n);
		size_t s = p.find('S');
		if (s == string::npos) {
			return p + "SA" + q + "TA";
		}
		size_t a = p.find('A', s);
		if (a == string::npos) {
			return p + "A" + q + "TA";
		}
		return S + "TA";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) {
		cerr << "Test Case #" << Case << "...";
		if (contains("SANTA", Received) && !contains("SATAN", Received)) {
			cerr << "PASSED" << endl;
		} else {
			cerr << "FAILED" << endl;
			cerr << "\tExpected: \"" << Expected << '\"' << endl;
			cerr << "\tReceived: \"" << Received << '\"' << endl;
		}
	}

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "STANA";
			string Arg1 = "STANTA";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "STN";
			string Arg1 = "SANTNA";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RATSNOOOA";
			string Arg1 = "DEARATSNOOOSANTA";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "SXAYNTA";
			string Arg1 = "OOOOSOXAYNTOOOOAOOO";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "SNTA";
			string Arg1 = "SANTA";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ASNTA";
			string Arg1 = "SASNTAS";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "NIELATA";
			string Arg1 = "SANIELATAJA";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			string Arg0 = "X";
			string Arg1 = "SSAAXNNTTAA";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OnlySanta ___test;
	___test.run_test(-1);
}
// END CUT HERE
