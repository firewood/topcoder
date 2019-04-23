// BEGIN CUT HERE
/*
TCO19 R1A Medium (500)

PROBLEM STATEMENT
Programmers often use hexadecimal integers - that is, numbers written in base 16. In this problem, a hexadecimal literal always begins with the characters "0x" (zero followed by a lowercase x). A hexadecimal literal must have at least one valid digit (0-9, A-F). Hence, the string "0x" itself is not a valid hexadecimal literal.
The strings DEADBEEF and BABACECA ("Grandma Ceca", in Bulgarian) are famous for consisting only of the first 6 letters of the English alphabet, thus being valid hexadecimal integers. Thus, 0xDEADBEEF = 3735928559 and 0xBABACECA = 3132804810 are valid hexadecimal literals. Because of that, these patterns are sometimes used as code constants.
Elly has noticed that the standard suffixes for type hinting in C++ (L, LL, U, UL, ULL, LU, LLU) can be added to the end of hexadecimal literals as well. More precisely, a hexadecimal literal either has no type hinting suffix at all, or it ends in exactly one of the seven suffixes we just mentioned. This way, for example, 0xFLU and 0xFULL are valid hexadecimal literals (with the value of 15), as is 0xFALL (which equals 250).
Additionally, the girl can use 0 as a 'O', 1 as 'I', 2 as 'Z', 5 as 'S', and 7 as 'T'. With these additions, for example the word TASTEFUL can be expressed as 0x7A57EFUL, OFFICIAL would be 0x0FF1C1AL, and OOZE would be 0x002E.
Now the girl wants to check whether some strings can be converted to such hexadecimal literals. Help her by writing a method, which, given a string candidate returns a string representing it as a hexadecimal literal (potentially ending in one of the suffixes). If the given string cannot be converted, return an empty string instead.


DEFINITION
Class:EllysCodeConstants
Method:getLiteral
Parameters:string
Returns:string
Method signature:string getLiteral(string candidate)


CONSTRAINTS
-candidate will consist of between 1 and 8 characters, inclusive.
-candidate will consist only of uppercase letters from the English alphabet.


EXAMPLES

0)
"DEADBEEF"

Returns: "0xDEADBEEF"

One of the examples from the problem statement.


1)
"BABACECA"

Returns: "0xBABACECA"

Another example from the problem statement.


2)
"TOPCODER"

Returns: ""

TopCoder unfortunately cannot be expressed as a hexadecimal literal, as the letters 'P' and 'R' are neither one of the first 6 letters of the alphabet, nor can be represented with digits. 'R' is also not one of the valid suffixes.


3)
"FLU"

Returns: "0xFLU"

Note that the standard allows the suffix 'L' (or "LL") to be before 'U'.


4)
"FULL"

Returns: "0xFULL"


5)
"FALL"

Returns: "0xFALL"


6)
"TASTEFUL"

Returns: "0x7A57EFUL"


7)
"OFFICIAL"

Returns: "0x0FF1C1AL"


8)
"OOZE"

Returns: "0x002E"

Leading zeroes are okay for such literals.


9)
"ESPRIT"

Returns: ""

espr1t cannot be expressed in hex either, again because of 'P' and 'R' (as was the case in TopCoder).


10)
"COOL"

Returns: "0xC00L"


11)
"DISEASE"

Returns: "0xD15EA5E"


12)
"SOLVED"

Returns: ""

Let's hope this problem will be ^^ by you!

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class EllysCodeConstants {
public:
	string getLiteral(string candidate) {
		string ans = "0x";
		int spos = -1;
		for (int i = 0; i < (int)candidate.length(); ++i) {
			char c = candidate[i];
			switch (c) {
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
				break;
			case 'L':
			case 'U':
				if (spos < 0) {
					spos = 2 + i;
				}
				break;
			case 'O': c = '0'; break;
			case 'I': c = '1'; break;
			case 'Z': c = '2'; break;
			case 'S': c = '5'; break;
			case 'T': c = '7'; break;
			default: return "";
			}
			ans += c;
		}
		if (spos >= 0) {
			if (spos == 2) {
				return "";
			}
			string b = ans.substr(spos);
			if (b == "L" || b == "LL" || b == "U" || b == "UL" || b == "ULL" || b == "LU" || b == "LLU") {

			} else {
				return "";
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
			string Arg0 = "DEADBEEF";
			string Arg1 = "0xDEADBEEF";

			verify_case(n, Arg1, getLiteral(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BABACECA";
			string Arg1 = "0xBABACECA";

			verify_case(n, Arg1, getLiteral(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "TOPCODER";
			string Arg1 = "";

			verify_case(n, Arg1, getLiteral(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "FLU";
			string Arg1 = "0xFLU";

			verify_case(n, Arg1, getLiteral(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "FULL";
			string Arg1 = "0xFULL";

			verify_case(n, Arg1, getLiteral(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "FALL";
			string Arg1 = "0xFALL";

			verify_case(n, Arg1, getLiteral(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "TASTEFUL";
			string Arg1 = "0x7A57EFUL";

			verify_case(n, Arg1, getLiteral(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			string Arg0 = "OFFICIAL";
			string Arg1 = "0x0FF1C1AL";

			verify_case(n, Arg1, getLiteral(Arg0));
		}
		n++;

		// test_case_8
		if ((Case == -1) || (Case == n)){
			string Arg0 = "OOZE";
			string Arg1 = "0x002E";

			verify_case(n, Arg1, getLiteral(Arg0));
		}
		n++;

		// test_case_9
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ESPRIT";
			string Arg1 = "";

			verify_case(n, Arg1, getLiteral(Arg0));
		}
		n++;

		// test_case_10
		if ((Case == -1) || (Case == n)){
			string Arg0 = "COOL";
			string Arg1 = "0xC00L";

			verify_case(n, Arg1, getLiteral(Arg0));
		}
		n++;

		// test_case_11
		if ((Case == -1) || (Case == n)){
			string Arg0 = "DISEASE";
			string Arg1 = "0xD15EA5E";

			verify_case(n, Arg1, getLiteral(Arg0));
		}
		n++;

		// test_case_12
		if ((Case == -1) || (Case == n)){
			string Arg0 = "SOLVED";
			string Arg1 = "";

			verify_case(n, Arg1, getLiteral(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			string Arg0 = "OULL";
			string Arg1 = "0x0ULL";

			verify_case(n, Arg1, getLiteral(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			string Arg0 = "OULLU";
			string Arg1 = "";

			verify_case(n, Arg1, getLiteral(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			string Arg0 = "L";
			string Arg1 = "";

			verify_case(n, Arg1, getLiteral(Arg0));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysCodeConstants ___test;
	___test.run_test(-1);
}
// END CUT HERE
