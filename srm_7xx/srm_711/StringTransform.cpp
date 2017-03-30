// BEGIN CUT HERE
/*
SRM 711 Div2 Medium (500)

PROBLEM STATEMENT
You are given the strings s and t.
Both strings have the same length.

You are allowed to modify s.
In each step you may choose two valid indices i and j such that i > j, and change s[i] to s[j].
For example, if s = "abc", you may choose i=2 and j=0, which will change s to "aba".

Return "Possible" (quotes for clarity) if you can change s into t by a sequence of zero or more steps.
Otherwise, return "Impossible".

Note that the return values are case-sensitive.


DEFINITION
Class:StringTransform
Method:isPossible
Parameters:string, string
Returns:string
Method signature:string isPossible(string s, string t)


CONSTRAINTS
-s will contain between 1 and 1,000 characters, inclusive. 
-s and t will be of equal length.  
-s will contain only lowercase English letters.  
-t will contain only lowercase English letters.


EXAMPLES

0)
"abc"
"aba"

Returns: "Possible"

This is the example from the problem statement.
We can change s into t by changing s[2] to s[0].


1)
"abc"
"bbc"

Returns: "Impossible"

Note that in each step i must be greater than j.
You are not allowed to choose i=0 and j=1.


2)
"topcoder"
"topcoder"

Returns: "Possible"

The two strings are equal, so we don't have to make any changes.


3)
"rdmcxnnbbe"
"rdrrxrnxbe"

Returns: "Possible"


4)
"rdmcxnnbbe"
"rdqrxrnxbe"

Returns: "Impossible"

*/
// END CUT HERE
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class StringTransform {

	bool possible(string &s, string &t) {
		for (int i = 0; i != s.length(); ++i) {
			int pos = s.find(t[i]);
			if (pos < 0 || pos > i) {
				return false;
			}
		}
		return true;
	}

	public:
	string isPossible(string s, string t) {
		return possible(s, t) ? "Possible" : "Impossible";
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
			string Arg0 = "abc";
			string Arg1 = "aba";
			string Arg2 = "Possible";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abc";
			string Arg1 = "bbc";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "topcoder";
			string Arg1 = "topcoder";
			string Arg2 = "Possible";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "rdmcxnnbbe";
			string Arg1 = "rdrrxrnxbe";
			string Arg2 = "Possible";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "rdmcxnnbbe";
			string Arg1 = "rdqrxrnxbe";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	StringTransform ___test;
	___test.run_test(-1);
}
// END CUT HERE
