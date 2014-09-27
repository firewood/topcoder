// BEGIN CUT HERE
/*
SRM 618 Div1 Medium (500)

PROBLEM STATEMENT
Fox Ciel likes all the words that have the following properties:

Each letter of the word is an uppercase English letter.
Equal letters are never consecutive.
There is no subsequence of the form xyxy, where x and y are (not necessarily distinct) letters. Note that a subsequence doesn't have to be contiguous.

Examples:

Ciel does not like "ABBA" because there are two consecutive 'B's.
Ciel does not like "THETOPCODER" because it contains the subsequence "TETE".
Ciel does not like "ABACADA" because it contains the subsequence "AAAA". (Note that here x=y='A'.)
Ciel likes "A", "ABA", and also "ABCBA".

Given a string word, return "Likes" (quotes for clarity) if Ciel likes word and "Dislikes" if she does not.


DEFINITION
Class:LongWordsDiv2
Method:find
Parameters:string
Returns:string
Method signature:string find(string word)


CONSTRAINTS
-word will contain between 1 and 100 characters, inclusive.
-Each character of word will be an uppercase English letter ('A'-'Z').


EXAMPLES

0)
"AAA"

Returns: "Dislikes"


1)
"ABCBA"

Returns: "Likes"


2)
"ABCBAC"

Returns: "Dislikes"


3)
"TOPCODER"

Returns: "Likes"


4)
"VAMOSGIMNASIA"

Returns: "Dislikes"


5)
"SINGLEROUNDMATCH"

Returns: "Likes"


6)
"DALELOBO"

Returns: "Likes"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class LongWordsDiv2 {
public:

	bool check(string s) {
		for (int i = 1; i < (int)s.length(); ++i) {
			if (s[i - 1] == s[i]) {
				return false;
			}
		}
		for (int a = 'A'; a <= 'Z'; ++a) {
			for (int b = 'A'; b <= 'Z'; ++b) {
				int pos = s.find(a, 0);
				if (pos >= 0) {
					pos = s.find(b, pos + 1);
					if (pos >= 0) {
						pos = s.find(a, pos + 1);
						if (pos >= 0) {
							pos = s.find(b, pos + 1);
							if (pos >= 0) {
								return false;
							}
						}
					}
				}
			}
		}
		return true;
	}

	string find(string word) {
		return check(word) ? "Likes" : "Dislikes";
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
			string Arg0 = "AAA";
			string Arg1 = "Dislikes";

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABCBA";
			string Arg1 = "Likes";

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABCBAC";
			string Arg1 = "Dislikes";

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "TOPCODER";
			string Arg1 = "Likes";

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "VAMOSGIMNASIA";
			string Arg1 = "Dislikes";

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "SINGLEROUNDMATCH";
			string Arg1 = "Likes";

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "DALELOBO";
			string Arg1 = "Likes";

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LongWordsDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
