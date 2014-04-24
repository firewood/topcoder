// BEGIN CUT HERE
/*
SRM 612 Div1 Easy (250)


PROBLEM STATEMENT
You are very happy because you advanced to the next round of a very important programming contest.
You want your best friend to know how happy you are.
Therefore, you are going to send him a lot of smile emoticons.
You are given an int smiles: the exact number of emoticons you want to send.

You have already typed one emoticon into the chat.
Then, you realized that typing is slow.
Instead, you will produce the remaining emoticons using copy, paste, and possibly some deleting.

You can only do three different operations:

Copy all the emoticons you currently have into the clipboard.
Paste all emoticons from the clipboard.
Delete one emoticon from the message.

Each operation takes precisely one second.
Copying replaces the old content of the clipboard.
Pasting does not empty the clipboard.
You are not allowed to copy just a part of the emoticons you already have.
You are not allowed to delete an emoticon from the clipboard.

Return the smallest number of seconds in which you can turn the one initial emoticon into smiles emoticons.

DEFINITION
Class:EmoticonsDiv1
Method:printSmiles
Parameters:int
Returns:int
Method signature:int printSmiles(int smiles)


CONSTRAINTS
-smiles will be between 2 and 1000, inclusive.


EXAMPLES

0)
2

Returns: 2

First use copy, then use paste. The first operation copies one emoticon into the clipboard, the second operation pastes it into the message, so now you have two emoticons and you are done.


1)
4

Returns: 4

One optimal solution is to copy the initial emoticon and then to paste it three times. Another optimal solution is to copy the one emoticon, paste it, copy the two emoticons you currently have, and paste two more.


2)
6

Returns: 5


Copy. This puts one emoticon into the clipboard.
Paste. You now have 2 emoticons in the message.
Copy. The clipboard now contains 2 emoticons.
Paste. You now have 4 emoticons in the message.
Paste. You now have 6 emoticons in the message and you are done.


3)
18

Returns: 8


4)
11

Returns: 8

Sometimes we actually do delete an emoticon in the optimal solution.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

typedef long long LL;

class EmoticonsDiv1 {
public:
	int printSmiles(int smiles) {
		int dp[1024+1] = {};
		memset(dp, 0x3f, sizeof(dp));
		dp[1] = 0;
		for (int i = 0; i < 10; ++i) {
			for (int j = 1; j <= 1024; ++j) {
				// copy & paste
				for (int k = 1; (j + k*j) <= 1024; ++k) {
					dp[j + k*j] = min(dp[j + k*j], dp[j] + 1 + k);
				}
			}
			// delete
			for (int j = 1; j <= 1024; ++j) {
				dp[j] = min(dp[j], dp[j + 1] + 1);
			}
		}
		return dp[smiles];
	}


// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;

			verify_case(n, Arg1, printSmiles(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;

			verify_case(n, Arg1, printSmiles(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 5;

			verify_case(n, Arg1, printSmiles(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 18;
			int Arg1 = 8;

			verify_case(n, Arg1, printSmiles(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 11;
			int Arg1 = 8;

			verify_case(n, Arg1, printSmiles(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EmoticonsDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
