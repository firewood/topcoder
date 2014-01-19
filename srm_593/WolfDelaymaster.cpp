// BEGIN CUT HERE
/*
SRM 593 Div2 Medium (500)

PROBLEM STATEMENT
Wolf Sothe is playing the game Delaymaster.
In this game, he can create new words according to the following rules:

For each positive integer n, the string which consists of n copies of 'w', then n copies of 'o', then n copies of 'l', and finally n copies of 'f' is a valid word.
The concatenation of two valid words is a valid word.
Only the words that can be obtained by rules 1 and 2 are valid. There are no other valid words.


Thus, for example:

By rule 1, "wolf", "wwoollff", and "wwwooolllfff" are valid words.
Then, by rule 2, "wolfwwoollff" is a valid word.
By applying rule 2 twice, "wolfwwoollffwolf" is a valid word.
The string "wfol" is not a valid word (order matters).
The string "wwolfolf" is not a valid word (we can only concatenate, not insert one word into another).
The string "wwwoolllfff" is not a valid word (only two 'o's instead of three).


You are given a string str.
Return "VALID" if str is a valid word and "INVALID" otherwise.
Note that the return value is case-sensitive: you must return the strings "VALID" and "INVALID" in all-uppercase.

DEFINITION
Class:WolfDelaymaster
Method:check
Parameters:string
Returns:string
Method signature:string check(string str)


CONSTRAINTS
-str will contain between 1 and 50 characters, inclusive.
-Each character in str will be 'w', 'o', 'l' or 'f'.


EXAMPLES

0)
"wolf"

Returns: "VALID"

The first valid word from the examples in the problem statement.


1)
"wwolfolf"

Returns: "INVALID"

The second invalid word from the examples in the problem statement.


2)
"wolfwwoollffwwwooolllfffwwwwoooollllffff"

Returns: "VALID"


3)
"flowolf"

Returns: "INVALID"

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class WolfDelaymaster {
public:
	string check(string str) {
		bool result = true;
		const char *s = str.c_str();
		string wolf = "wolf";
		while (*s) {
			int count[4] = {};
			for (int i = 0; i < 4; ++i) {
				while (*s && *s == wolf[i]) {
					++s;
					++count[i];
				}
				if (count[0] != count[i]) {
					result = false;
				}
			}
		}
		return result ? "VALID" : "INVALID";
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
			string Arg0 = "wolf";
			string Arg1 = "VALID";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "wwolfolf";
			string Arg1 = "INVALID";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "wolfwwoollffwwwooolllfffwwwwoooollllffff";
			string Arg1 = "VALID";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "flowolf";
			string Arg1 = "INVALID";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "wwwooolllff";
			string Arg1 = "INVALID";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WolfDelaymaster ___test;
	___test.run_test(-1);
}
// END CUT HERE
