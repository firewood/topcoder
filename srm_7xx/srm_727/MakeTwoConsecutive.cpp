// BEGIN CUT HERE
/*
SRM 727 Div2 Easy (250)

PROBLEM STATEMENT
Definition: a string is beautiful if it has two consecutive equal characters.
Examples of beautiful strings are "KEEP", "ZZZZZ" and "TTORR", while the following are not beautiful: "A", "GH" and "ABCABCBX".

You are given the string S and you are going to remove exactly one character from S.
Is it possible that the new string will be beautiful?
If yes, return "Possible".
Otherwise, return "Impossible".

Note that the return value is case-sensitive.


DEFINITION
Class:MakeTwoConsecutive
Method:solve
Parameters:string
Returns:string
Method signature:string solve(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-Each character in S will be an uppercase English letter: 'A' - 'Z'.


EXAMPLES

0)
"VIKING"

Returns: "Possible"

You can remove 'K' to obtain the string "VIING".
This string is beautiful because it has two consecutive 'I'.


1)
"BCAB"

Returns: "Impossible"

You can only get one of the following strings: "CAB", "BAB", "BCB" and "BCA".
None of these are beautiful, so the answer is "Impossible".


2)
"XX"

Returns: "Impossible"

After removing one character you will get the string "X" that isn't beautiful.
Please note that you have to remove exactly one character.


3)
"A"

Returns: "Impossible"

After removing one character you will get the empty string "".
It isn't beautiful.


4)
"AABB"

Returns: "Possible"

You can get either "ABB" or "ABB".
Both these strings are beautiful.


5)
"QWERTYY"

Returns: "Possible"

There are a few beautiful strings you can get.
Some of them are "WERTYY" and "QWETYY".


6)
"ITHINKYOUAREAHUMAN"

Returns: "Impossible"


7)
"BOB"

Returns: "Possible"

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

typedef long long LL;

// BEGIN CUT HERE
/*
typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<II> IIVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;
typedef set<II> IISet;
typedef set<string> StrSet;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
#define MOD 1000000007LL
#define MOD 1000000009LL
*/
// END CUT HERE

class MakeTwoConsecutive {
	bool possible(const string &s) {
		for (int i = 0; i < (int)s.length(); ++i) {
			string x = s.substr(0, i) + s.substr(i + 1);
			char prev = 0;
			for (char c : x) {
				if (c == prev) {
					return true;
				}
				prev = c;
			}
		}
		return false;
	}
public:
	string solve(string S) {
		return possible(S) ? "Possible" : "Impossible";
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
			string Arg0 = "VIKING";
			string Arg1 = "Possible";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BCAB";
			string Arg1 = "Impossible";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "XX";
			string Arg1 = "Impossible";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "A";
			string Arg1 = "Impossible";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AABB";
			string Arg1 = "Possible";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "QWERTYY";
			string Arg1 = "Possible";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ITHINKYOUAREAHUMAN";
			string Arg1 = "Impossible";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BOB";
			string Arg1 = "Possible";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MakeTwoConsecutive ___test;
	___test.run_test(-1);
}
// END CUT HERE
