// BEGIN CUT HERE
/*
SRM 656 Div2 Easy (250)

PROBLEM STATEMENT

Your friend just sent you a message.
The message consisted of one or more copies of the same lowercase letter.
For example, "aaaaa" and "xxxxxxxxx" are valid messages.
Unfortunately, on its way to you the message became corrupted: exactly k letters of the original message were changed to some other letters.
The message you received is s.

Given the string s and the int k, reconstruct the original message.
More precisely, return a string that could have been the original message.
It is guaranteed that at least one such string will always exist.
If there are multiple possible answers, you may return any of them.


DEFINITION
Class:CorruptedMessage
Method:reconstructMessage
Parameters:string, int
Returns:string
Method signature:string reconstructMessage(string s, int k)


CONSTRAINTS
-The number of characters in s will be between 1 and 50, inclusive.
-Each character in s will be a lowercase letter ('a'-'z').
-k will be between 0 and the length of s, inclusive.
-At least one possible original message will be consistent with s and k.


EXAMPLES

0)
"hello"
3

Returns: "lllll"

The three corrupted characters have 0-based indices 0, 1, and 4.


1)
"abc"
3

Returns: "ddd"

The original message can't be "aaa", "bbb", or "ccc", since we need to change exactly 3 characters.

Some other possible answers include "qqq", "xxx", or "ppp".


2)
"wwwwwwwwwwwwwwwwww"
0

Returns: "wwwwwwwwwwwwwwwwww"

No characters were corrupted.


3)
"ababba"
3

Returns: "aaaaaa"

"bbbbbb" will also be accepted.


4)
"zoztxtoxytyt"
10

Returns: "oooooooooooo"


5)
"jlmnmiunaxzywed"
13

Returns: "mmmmmmmmmmmmmmm"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class CorruptedMessage {
public:
	string reconstructMessage(string s, int k) {
		int cnt[256] = {};
		for (char c : s) {
			cnt[c] += 1;
		}
		char c;
		for (c = 'a'; c <= 'z'; ++c) {
			if ((cnt[c] + k) == s.length()) {
				break;
			}
		}
		return string(s.length(), c);
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
			string Arg0 = "hello";
			int Arg1 = 3;
			string Arg2 = "lllll";

			verify_case(n, Arg2, reconstructMessage(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abc";
			int Arg1 = 3;
			string Arg2 = "ddd";

			verify_case(n, Arg2, reconstructMessage(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "wwwwwwwwwwwwwwwwww";
			int Arg1 = 0;
			string Arg2 = "wwwwwwwwwwwwwwwwww";

			verify_case(n, Arg2, reconstructMessage(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ababba";
			int Arg1 = 3;
			string Arg2 = "aaaaaa";

			verify_case(n, Arg2, reconstructMessage(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "zoztxtoxytyt";
			int Arg1 = 10;
			string Arg2 = "oooooooooooo";

			verify_case(n, Arg2, reconstructMessage(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "jlmnmiunaxzywed";
			int Arg1 = 13;
			string Arg2 = "mmmmmmmmmmmmmmm";

			verify_case(n, Arg2, reconstructMessage(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CorruptedMessage ___test;
	___test.run_test(-1);
}
// END CUT HERE
