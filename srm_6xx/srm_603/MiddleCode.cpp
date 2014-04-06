// BEGIN CUT HERE
/*
SRM 603 Div2 Easy (250)

PROBLEM STATEMENT
Hero is learning a new algorithm to encode a string.
You are given a string s that consists of lowercase letters only.
Your task is to simulate the algorithm described below on this string, so that Hero can see how it works.

The algorithm starts with a given input string s and an empty output string t.
The execution of the algorithm consists of multiple steps.
In each step, s and t are modified as follows:

If the length of s is odd, the middle character of s is added to the end of t, and then deleted from s.
If the length of s is even, the two characters in the middle of s are compared. The smaller one of them (either one in case of a tie) is added to the end of t, and then deleted from s.

If after some step the string s is empty, the algorithm terminates.
The output of the algorithm is the final string t.

Return the string t that will be produced by the above algorithm for the given string s.

DEFINITION
Class:MiddleCode
Method:encode
Parameters:string
Returns:string
Method signature:string encode(string s)


NOTES
-When comparing letters, the smaller one is the one earlier in the alphabet - i.e., the character with the smaller ASCII code.


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character in s will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"word"

Returns: "ordw"


In the first step, 'o' is smaller than 'r', thus 'o' is selected.
After the first step: s="wrd", t="o".
After the second step: s="wd", t="or".
In the third step, 'w' is greater than 'd', thus 'd' is selected.
After the third step: s="w", t="ord".
After the fourth step: s="", t="ordw", and the algorithm terminates.


1)
"aaaaa"

Returns: "aaaaa"


2)
"abacaba"

Returns: "caabbaa"


3)
"shjegr"

Returns: "ejghrs"


4)
"adafaaaadafawafwfasdaa"

Returns: "afawadafawafaafsadadaa"

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class MiddleCode {
public:
	string encode(string s) {
		string t;
		while (!s.empty()) {
			int len = (int)s.length();
			char a = s[(len-1)/2], b = s[len/2];
			if (a < b) {
				t += a;
				s = s.substr(0, len/2-1) + s.substr(len/2);
			} else {
				t += b;
				s = s.substr(0, len/2) + s.substr(len/2+1);
			}
		}
		return t;
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
			string Arg0 = "word";
			string Arg1 = "ordw";

			verify_case(n, Arg1, encode(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaaa";
			string Arg1 = "aaaaa";

			verify_case(n, Arg1, encode(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abacaba";
			string Arg1 = "caabbaa";

			verify_case(n, Arg1, encode(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "shjegr";
			string Arg1 = "ejghrs";

			verify_case(n, Arg1, encode(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "adafaaaadafawafwfasdaa";
			string Arg1 = "afawadafawafaafsadadaa";

			verify_case(n, Arg1, encode(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MiddleCode ___test;
	___test.run_test(-1);
}
// END CUT HERE
