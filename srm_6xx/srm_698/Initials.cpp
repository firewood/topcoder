// BEGIN CUT HERE
/*
SRM 698 Div2 Easy (250)

PROBLEM STATEMENT
When dealing with long names and phrases, we sometimes use the initial letters of words to form its acronym.
For example, we use "JFK" instead of "John Fitzgerald Kennedy", "lgtm" instead of "looks good to me", and so on.

You are given a string name.
This string contains a phrase: one or more words separated by single spaces.
Please compute and return the acronym of this phrase.
(As above, the acronym should consist of the first letter of each word, in order.)


DEFINITION
Class:Initials
Method:getInitials
Parameters:string
Returns:string
Method signature:string getInitials(string name)


CONSTRAINTS
-name will contain between 1 and 50 characters, inclusive.
-Each character in s will be a space or a lowercase English letter ('a' - 'z').
-The first and last character in s will not be a space.
-No two continuous spaces can appear in s.


EXAMPLES

0)
"john fitzgerald kennedy"

Returns: "jfk"

There are three words: "john", "fitzgerald" and "kennedy".
Their first letters are 'j', 'f' and 'k'.
The correct return value is their concatenation: the string "jfk".
Note that all letters in our problem are in lowercase.


1)
"single"

Returns: "s"

There is only one word: "single". Its acronym has a single letter.


2)
"looks good to me"

Returns: "lgtm"


3)
"single round match"

Returns: "srm"


4)
"a aa aaa aa a bbb bb b bb bbb"

Returns: "aaaaabbbbb"

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Initials {
public:
	string getInitials(string name) {
		string ans;
		char prev = ' ';
		for (char c : name) {
			if (prev == ' ') {
				ans += c;
			}
			prev = c;
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
			string Arg0 = "john fitzgerald kennedy";
			string Arg1 = "jfk";

			verify_case(n, Arg1, getInitials(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "single";
			string Arg1 = "s";

			verify_case(n, Arg1, getInitials(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "looks good to me";
			string Arg1 = "lgtm";

			verify_case(n, Arg1, getInitials(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "single round match";
			string Arg1 = "srm";

			verify_case(n, Arg1, getInitials(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "a aa aaa aa a bbb bb b bb bbb";
			string Arg1 = "aaaaabbbbb";

			verify_case(n, Arg1, getInitials(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Initials ___test;
	___test.run_test(-1);
}
// END CUT HERE
