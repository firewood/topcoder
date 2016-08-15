// BEGIN CUT HERE
/*
SRM 696 Div2 Easy (250)

PROBLEM STATEMENT
Hero has a collection of ropes.
You are given the string s that contains an ASCII art depicting this collection of ropes.
Each character of s is either '-' (dash, ASCII 45) or '.' (period, ASCII 46).
Each dash is a rope segment, each period is an empty space.
Each contiguous segment of dashes represents one rope; the number of dashes is the length of the rope.
For example, s = "..-..----." means that Hero has two ropes: one of length 1 and one of length 4.

Hero has decided to rearrange his collection of ropes, using the following rules:

Each rope that has an even length must be placed to the left of all ropes that have odd lengths.
There must be at least one empty space between any two ropes.
If there are multiple arrangements that satisfy the previous two rules, Hero will choose the one that corresponds to the lexicographically smallest string. (This is explained below.)

Once Hero rearranges his ropes, we can encode their new placement into a new string that looks similar to s.
(The string will have the same length as s and it will contain the same collection of ropes, but possibly in different places.)

Given two strings of the same length, the lexicographically smaller one is the one that has a character with a smaller ASCII value on the first position on which they differ.
For example, the string X = "---.-" is lexicographically smaller than the string Y = "-.---" because X[0] = Y[0] and X[1] &lt Y[1].
(Note that a dash has a smaller ASCII value than a period.)

Construct the arrangement of ropes chosen by Hero and return the string that encodes it.


DEFINITION
Class:Ropestring
Method:makerope
Parameters:string
Returns:string
Method signature:string makerope(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character in s will be either '-' or '.'.


EXAMPLES

0)
"..-..-"

Returns: "-.-..."


1)
"-.-"

Returns: "-.-"


2)
"--..-.---..--"

Returns: "--.--.---.-.."


3)
"--..-.---..--..-----.--."

Returns: "--.--.--.-----.---.-...."


4)
"..."

Returns: "..."

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Ropestring {
public:
	string makerope(string s) {
		int cnt[64] = {};
		int i, j, k;
		for (i = 0; i != s.length(); i += j) {
			for (j = 0; i + j != s.length(); ++j) {
				if (s[i + j] != '-') {
					break;
				}
			}
			cnt[j] += 1;
			if (!j) {
				++j;
			}
		}
		string ans;
		for (k = 0; k < 2; ++k) {
			for (i = (s.length() & ~1) | k; i >= 1; i -= 2) {
				for (j = 0; j != cnt[i]; ++j) {
					if (!ans.empty()) {
						ans += '.';
						--cnt[0];
					}
					ans += string(i, '-');
				}
			}
		}
		ans += string(cnt[0], '.');
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
			string Arg0 = "..-..-";
			string Arg1 = "-.-...";

			verify_case(n, Arg1, makerope(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "-.-";
			string Arg1 = "-.-";

			verify_case(n, Arg1, makerope(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "--..-.---..--";
			string Arg1 = "--.--.---.-..";

			verify_case(n, Arg1, makerope(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "--..-.---..--..-----.--.";
			string Arg1 = "--.--.--.-----.---.-....";

			verify_case(n, Arg1, makerope(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "...";
			string Arg1 = "...";

			verify_case(n, Arg1, makerope(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Ropestring ___test;
	___test.run_test(-1);
}
// END CUT HERE
