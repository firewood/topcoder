// BEGIN CUT HERE
/*
SRM 701 Div2 Easy (250)

PROBLEM STATEMENT

We say that a string S is a square if it has the form TT, where T is some non-empty string.
In other words, a square is a string that is a concatenation of two copies of the same non-empty string.
For example, the strings "aa", "bbbb", and "beriberi" are squares.

A string is called square-free if none of its substrings is a square.
For example, the string "abca" is square-free.
(The substrings of this string are the strings "a", "b", "c", "a", "ab", "bc", "ca", "abc", "bca", and "abca". None of these strings is a square.)

You are given a string s.
Return "square-free" if s is square-free.
Otherwise, return "not square-free".
Note that the return value is case-sensitive.


DEFINITION
Class:SquareFreeString
Method:isSquareFree
Parameters:string
Returns:string
Method signature:string isSquareFree(string s)


CONSTRAINTS
-s will consist only of lowercase English letters ('a'-'z').  
-The length of s will be between 1 and 50, inclusive.


EXAMPLES

0)
"bobo"

Returns: "not square-free"

"bobo" = T + T, where T = "bo", so it is not square-free.  


1)
"apple"

Returns: "not square-free"

Substring "pp" is a square.  


2)
"pen"

Returns: "square-free"

"pen" does not contain any substrings that are squares.  


3)
"aydyamrbnauhftmphyrooyq"

Returns: "not square-free"


4)
"qwertyuiopasdfghjklzxcvbnm"

Returns: "square-free"

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

class SquareFreeString {
public:
	string isSquareFree(string s) {
		for (int i = 0; i != s.length(); ++i) {
			for (int j = 1; (i + j * 2) <= (int)s.length(); ++j) {
				if (s.substr(i, j).compare(s.substr(i + j, j)) == 0) {
					return "not square-free";
				}
			}
		}
		return "square-free";
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
			string Arg0 = "bobo";
			string Arg1 = "not square-free";

			verify_case(n, Arg1, isSquareFree(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "apple";
			string Arg1 = "not square-free";

			verify_case(n, Arg1, isSquareFree(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "pen";
			string Arg1 = "square-free";

			verify_case(n, Arg1, isSquareFree(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aydyamrbnauhftmphyrooyq";
			string Arg1 = "not square-free";

			verify_case(n, Arg1, isSquareFree(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "qwertyuiopasdfghjklzxcvbnm";
			string Arg1 = "square-free";

			verify_case(n, Arg1, isSquareFree(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SquareFreeString ___test;
	___test.run_test(-1);
}
// END CUT HERE
