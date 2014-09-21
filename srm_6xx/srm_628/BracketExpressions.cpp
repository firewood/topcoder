// BEGIN CUT HERE
/*
SRM 628 Div2 Medium (500)

PROBLEM STATEMENT
We have three types of brackets: "()", "[]", and "{}".
We are now interested in some special strings.
A string is special if all the following conditions hold:

Each character of the string is one of the six bracket characters mentioned above.
The characters of the string can be divided into disjoint pairs such that in each pair we have an opening bracket and a closing bracket of the same type.
For each pair, the opening bracket must occur to the left of the corresponding closing bracket.
For each pair, the substring strictly between the opening and the closing bracket must be a special string (again, according to this definition).

For example, the empty string is a special string: there are 0 pairs of brackets.
The string "[]" is also a special string: there is one pair of matching brackets, they are in the proper order, and the string between them (which is the empty string) is a special string.

The character 'X' (uppercase x) occurs in expression at most five times; all other characters in expression are brackets of the types mentioned above.
We want to change expression into a special string by changing each 'X' into one of the brackets.
(Different occurrences of 'X' may be changed into different brackets.)
Return "possible" (quotes for clarity) if we can do that, and "impossible" otherwise.


DEFINITION
Class:BracketExpressions
Method:ifPossible
Parameters:string
Returns:string
Method signature:string ifPossible(string expression)


CONSTRAINTS
-expression will have between 1 and 50 characters, inclusive.
-Each character in expression will be '(', ')', '[', ']', '{', '}' or 'X'.
-There will be at most 5 occurences of 'X' in expression.


EXAMPLES

0)
"([]{})"

Returns: "possible"

This is already a special string. As there are no 'X's, we do not get to change anything.


1)
"(())[]"

Returns: "possible"


2)
"({])"

Returns: "impossible"


3)
"[]X"

Returns: "impossible"

Regardless of bracket type you put instead of 'X', you cannot create a special string.


4)
"([]X()[()]XX}[])X{{}}]"

Returns: "possible"

You can replace 'X's respectively with '{', '(', ')' and '['.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class BracketExpressions {

	int xs;
	int x[5];

	void shrink(string &s) {
		while (true) {
			int pos = s.find("()");
			if (pos >= 0) {
				s = s.substr(0, pos) + s.substr(pos + 2);
				continue;
			}
			pos = s.find("[]");
			if (pos >= 0) {
				s = s.substr(0, pos) + s.substr(pos + 2);
				continue;
			}
			pos = s.find("{}");
			if (pos >= 0) {
				s = s.substr(0, pos) + s.substr(pos + 2);
				continue;
			}
			break;
		}
	}

	bool can(string s) {
		shrink(s);
		const char *b = "([{}])";
		shrink(s);
		xs = 0;
		int i;
		for (i = 0; i < s.length(); ++i) {
			if (s[i] == 'X') {
				x[xs++] = i;
			}
		}
		if (xs == 0) {
			return s.length() == 0;
		}

		int xc[5] = {};
		while (true) {
			for (i = 0; i < xs; ++i) {
				s[x[i]] = b[xc[i]];
			}
			string a = s;
			shrink(a);
			if (a.length() == 0) {
				return true;
			}
			for (i = 0; i < xs; ++i) {
				xc[i] += 1;
				if (xc[i] < 6) {
					break;
				}
				xc[i] = 0;
			}
			if (i >= xs) {
				break;
			}
		}
		return false;
	}


public:
	string ifPossible(string expression) {
		return can(expression) ? "possible" : "impossible";
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
			string Arg0 = "([]{})";
			string Arg1 = "possible";

			verify_case(n, Arg1, ifPossible(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "(())[]";
			string Arg1 = "possible";

			verify_case(n, Arg1, ifPossible(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "({])";
			string Arg1 = "impossible";

			verify_case(n, Arg1, ifPossible(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "[]X";
			string Arg1 = "impossible";

			verify_case(n, Arg1, ifPossible(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "([]X()[()]XX}[])X{{}}]";
			string Arg1 = "possible";

			verify_case(n, Arg1, ifPossible(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BracketExpressions ___test;
	___test.run_test(-1);
}
// END CUT HERE
