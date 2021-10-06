// BEGIN CUT HERE
/*
SRM 814 Div2 Easy (300)

PROBLEM STATEMENT

You are traversing a dangerous section of a video game level.
The section contains some solid terrain blocks (denoted '-') and some blocks with spiky traps (denoted '*').
If you step onto a trap, you die.

You are given the layout of the level in the string level.
You are currently standing on the leftmost block of the level.
This block is represented by the character level[0] and it is guaranteed to be a solid block.

Your task is to reach the block at the opposite end of the level.
This block is also guaranteed to be solid.

You can move in three ways:

Take a step (denoted 'S'): move one block to the right.
Make a hop (denoted 'H'): hop over one block and land two block to the right of your current block.
Make a jump (denoted 'J'): jump over two consecutive blocks and land three blocks to the right of your current position.

For example, if the level is "----", you can traverse it by making three steps (denoted "SSS"), a
hop followed by a step ("SH"), a step followed by a hop ("HS"), or a single jump ("J").

If the level is "-**-", the only way to traverse it is by making a jump - remember that you cannot
step onto the spiky traps.

Find whether it is possible to traverse the level you were given.
If yes, return a string of letters 'S', 'H', and 'J' that describes how to do it.
(If there are multiple valid strings, you may return any one of them.)

If traversing the level isn't possible, return an empty string instead.


DEFINITION
Class:StepHopJumpEasy
Method:solve
Parameters:string
Returns:string
Method signature:string solve(string level)


CONSTRAINTS
-level will contain between 2 and 200 characters, inclusive.
-Each character of level will be either '-' or '*'.
-The first and the last character of level will be '-'.


EXAMPLES

0)
"----"

Returns: "HS"

As explained in the statement, there are four acceptable answers for this test case: "SSS", "SH", "HS", and "J". You may return any one of them.


1)
"-**-"

Returns: "J"

Here, "J" is the only acceptable answer.


2)
"-*--**---***----****-----"

Returns: ""

This level has no solution - there is no sequence of steps, hops and jumps that gets you from the left end all the way to the right end.


3)
"-*-*------"

Returns: "HJJS"

The first move must be a hop. Then, the second move must be a hop or a jump. In all other cases you will step onto a spiky trap and die.


4)
"---"

Returns: "H"

Here, the only solutions are "SS" and "H". Note that the player cannot jump, as the level is not long enough for a jump - they would jump beyond the end of the level.

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

class StepHopJumpEasy {
public:
	string solve(string level) {
		vector<string> dp(level.length() + 1);
		dp[0] = ".";
		for (int i = 1; i < level.length(); ++i) {
			if (level[i] == '-') {
				if (!dp[i - 1].empty()) {
					dp[i] = dp[i - 1] + "S";
				}
				if (i >= 2 && !dp[i - 2].empty()) {
					dp[i] = dp[i - 2] + "H";
				}
				if (i >= 3 && !dp[i - 3].empty()) {
					dp[i] = dp[i - 3] + "J";
				}
			}
		}
		string ans = dp[level.length() - 1];
		if (ans.length()) {
			ans = ans.substr(1);
		}
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
			string Arg0 = "----";
//			string Arg1 = "HS";
			string Arg1 = "J";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "-**-";
			string Arg1 = "J";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "-*--**---***----****-----";
			string Arg1 = "";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "-*-*------";
//			string Arg1 = "HJJS";
			string Arg1 = "HHHJ";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "---";
			string Arg1 = "H";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	StepHopJumpEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
