// BEGIN CUT HERE
/*
SRM 630 Div2 Easy (250)

PROBLEM STATEMENT
You are given a string S.
You can modify this string by repeating the following process:

Find the leftmost occurrence of two consecutive letters in S that are the same.
If you found a pair of identical letters in the first step, delete those two letters from S.

For example, if S="aabccb", you can proceed as follows:

Find and erase "aa", producing the string "bccb".
Find and erase "cc", producing the string "bb".
Find and erase "bb", producing the empty string.

For S="axxyybac" you can do at most two steps, erasing "xx" first and "yy" next. Once you obtain the string "abac", you are done. Note that you cannot erase the two "a"s because they are not consecutive.

You want to change S into an empty string by repeating the operation described above.
Return "Possible" if you can do that, and "Impossible" otherwise.

DEFINITION
Class:DoubleLetter
Method:ableToSolve
Parameters:string
Returns:string
Method signature:string ableToSolve(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters.
-Each character in S will be a lowercase English letter ('a'-'z').


EXAMPLES

0)
"aabccb"

Returns: "Possible"


1)
"aabccbb"

Returns: "Impossible"

The process will terminate with a single 'b'.


2)
"abcddcba"

Returns: "Possible"

"abcddcba" -> "abccba" -> "abba" -> "aa" -> "".


3)
"abab"

Returns: "Impossible"

No two successive letters are the same, so we can't do any operation.


4)
"aaaaaaaaaa"

Returns: "Possible"


5)
"aababbabbaba"

Returns: "Impossible"


6)
"zzxzxxzxxzzx"

Returns: "Possible"

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class DoubleLetter {
public:
	string ableToSolve(string S) {
		while (true) {
			int len = (int)S.length();
			int i;
			for (i = 0; i < len - 1; ++i) {
				if (S[i] == S[i + 1]) {
					break;
				}
			}
			if (i >= len - 1) {
				break;
			}
			S = S.substr(0, i) + S.substr(i + 2);
		}
		return S.length() == 0 ? "Possible" : "Impossible";
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
			string Arg0 = "aabccb";
			string Arg1 = "Possible";

			verify_case(n, Arg1, ableToSolve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aabccbb";
			string Arg1 = "Impossible";

			verify_case(n, Arg1, ableToSolve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcddcba";
			string Arg1 = "Possible";

			verify_case(n, Arg1, ableToSolve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abab";
			string Arg1 = "Impossible";

			verify_case(n, Arg1, ableToSolve(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaaaaaaaa";
			string Arg1 = "Possible";

			verify_case(n, Arg1, ableToSolve(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aababbabbaba";
			string Arg1 = "Impossible";

			verify_case(n, Arg1, ableToSolve(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "zzxzxxzxxzzx";
			string Arg1 = "Possible";

			verify_case(n, Arg1, ableToSolve(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DoubleLetter ___test;
	___test.run_test(-1);
}
// END CUT HERE
