// BEGIN CUT HERE
/*
SRM 663 Div2 Medium (500)

PROBLEM STATEMENT
One day, Jamie noticed that many English words only use the letters A and B.
Examples of such words include "AB" (short for abdominal), "BAA" (the noise a sheep makes), "AA" (a type of lava), and "ABBA" (a Swedish pop sensation).

Inspired by this observation, Jamie created a simple game.
You are given two strings: initial and target.
The goal of the game is to find a sequence of valid moves that will change initial into target.
There are two types of valid moves:

Add the letter A to the end of the string.
Reverse the string and then add the letter B to the end of the string.

Return "Possible" (quotes for clarity) if there is a sequence of valid moves that will change initial into target.
Otherwise, return "Impossible".


DEFINITION
Class:ABBA
Method:canObtain
Parameters:string, string
Returns:string
Method signature:string canObtain(string initial, string target)


CONSTRAINTS
-The length of initial will be between 1 and 999, inclusive.
-The length of target will be between 2 and 1000, inclusive.
-target will be longer than initial.
-Each character in initial and each character in target will be either 'A' or 'B'.


EXAMPLES

0)
"B"
"ABBA"

Returns: "Possible"

Jamie can perform the following moves:

Initially, the string is "B".
Jamie adds an 'A' to the end of the string. Now the string is "BA".
Jamie reverses the string and then adds a 'B' to the end of the string. Now the string is "ABB".
Jamie adds an 'A' to the end of the string. Now the string is "ABBA".

Since there is a sequence of moves which starts with "B" and creates the string "ABBA", the answer is "Possible".


1)
"AB"
"ABB"

Returns: "Impossible"

The only strings of length 3 Jamie can create are "ABA" and "BAB".


2)
"BBAB"
"ABABABABB"

Returns: "Impossible"


3)
"BBBBABABBBBBBA"
"BBBBABABBABBBBBBABABBBBBBBBABAABBBAA"

Returns: "Possible"


4)
"A"
"BB"

Returns: "Impossible"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class ABBA {
	string init;
	string t;
	int init_len;
	int target_len;

	bool dfs(int dir, int st, int ed) {
		int len = ed - st;
		if (len == init_len) {
			string s = t.substr(st, init_len);
			if (dir) {
				reverse(s.begin(), s.end());
			}
			return init == s;
		}
		bool result = false;
		if (len > init_len) {
			if (!dir) {
				if (t[ed - 1] == 'A') {
					result |= dfs(0, st, ed - 1);
				} else {
					result |= dfs(1, st, ed - 1);
				}
			} else {
				if (t[st] == 'A') {
					result |= dfs(1, st + 1, ed);
				} else {
					result |= dfs(0, st + 1, ed);
				}
			}
		}
		return result;
	}

public:
	string canObtain(string initial, string target) {
		init = initial;
		t = target;
		init_len = initial.length();
		target_len = target.length();
		return dfs(0, 0, target_len) ? "Possible" : "Impossible";
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
			string Arg0 = "B";
			string Arg1 = "ABBA";
			string Arg2 = "Possible";

			verify_case(n, Arg2, canObtain(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AB";
			string Arg1 = "ABB";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, canObtain(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BBAB";
			string Arg1 = "ABABABABB";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, canObtain(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BBBBABABBBBBBA";
			string Arg1 = "BBBBABABBABBBBBBABABBBBBBBBABAABBBAA";
			string Arg2 = "Possible";

			verify_case(n, Arg2, canObtain(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "A";
			string Arg1 = "BB";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, canObtain(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ABBA ___test;
	___test.run_test(-1);
}
// END CUT HERE
