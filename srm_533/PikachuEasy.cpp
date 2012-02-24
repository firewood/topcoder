// BEGIN CUT HERE
/*
// SRM 533 Div2 Easy (250)

// PROBLEM STATEMENT
// Pikachu is a well-known character in the Pokemon anime series.
Pikachu can speak, but only 3 syllables: "pi", "ka", and "chu".
Therefore Pikachu can only pronounce strings that can be created
as a concatenation of one or more syllables he can pronounce.
For example, he can pronounce the words "pikapi" and "pikachu".

You are given a string word.
Your task is to check whether Pikachu can pronounce the string.
If the string can be produced by concatenating copies of the strings
"pi", "ka", and "chu", return "YES" (quotes for clarity). Otherwise,
return "NO".

DEFINITION
Class:PikachuEasy
Method:check
Parameters:string
Returns:string
Method signature:string check(string word)


CONSTRAINTS
-word will contain between 1 and 50 characters, inclusive.
-Each character of word will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"pikapi"

Returns: "YES"

"pikapi" = "pi" + "ka" + "pi", so Pikachu can say it.

1)
"pipikachu"

Returns: "YES"

This time we have "pipikachu" = "pi" + "pi" + "ka" + "chu",
so Pikachu can say it as well.

2)
"pikaqiu"

Returns: "NO"

Pikachu can't say "pikaqiu" since 'q' does not appear in "pi", "ka", or "chu".

3)
"topcoder"

Returns: "NO"



4)
"piika"

Returns: "NO"



5)
"chupikachupipichu"

Returns: "YES"



6)
"pikapipachu"

Returns: "NO"

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class PikachuEasy {

public:
	string check(string word) {
		const char *p = word.c_str();
		while (*p) {
			if (strncmp(p, "pi", 2) == 0 || strncmp(p, "ka", 2) == 0) {
				p += 2;
			} else if (strncmp(p, "chu", 3) == 0) {
				p += 3;
			} else {
				return "NO";
			}
		}
		return "YES";
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
			string Arg0 = "pikapi";
			string Arg1 = "YES";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "pipikachu";
			string Arg1 = "YES";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "pikaqiu";
			string Arg1 = "NO";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "topcoder";
			string Arg1 = "NO";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "piika";
			string Arg1 = "NO";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "chupikachupipichu";
			string Arg1 = "YES";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "pikapipachu";
			string Arg1 = "NO";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PikachuEasy ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
