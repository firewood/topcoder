// BEGIN CUT HERE
/*
SRM 627 Div1 Easy (250)

PROBLEM STATEMENT
The Happy Letter game is played as follows:
At the beginning, several players enter the field.
Each player has a lowercase English letter on their back.
The game is played in turns.
In each turn, you select two players with different letters, and both selected players leave the field.
The game ends once it is impossible to take another turn.

If there are some players left in the field at the end of the game, they must all have the same letter.
That letter is called the winning letter.
If there are no players left in the field at the end of the game, there is no winning letter.

You are given a string letters.
The characters in letters are the characters carried by the players at the beginning of the game.
Return a string with all possible winning letters.
The letters in the returned string must be sorted in increasing order.


DEFINITION
Class:HappyLetterDiv1
Method:getHappyLetters
Parameters:string
Returns:string
Method signature:string getHappyLetters(string letters)


NOTES
-If there's no happy letter, return the empty string.


CONSTRAINTS
-letters will contain between 1 and 50 elements.
-Each element of letters will be a lowercase English letter ('a'-'z').


EXAMPLES

0)
"aabbacccc"

Returns: "abc"

Each of the three letters can be the winning letter.
Here is one possibility how 'a' can be the winning letter:
Let's number the players 0 through 8 in the order in which they appear in the input.
We can then play the game as follows:

Send away players 1 ('a') and 8 ('c').
Send away players 2 ('b') and 6 ('c').
Send away players 7 ('c') and 0 ('a').
Send away players 5 ('c') and 3 ('b').
The only player left is player 4 ('a'), hence 'a' is the winning letter.


1)
"aaaaaaaccdd"

Returns: "a"

Only letter 'a' can win.


2)
"ddabccadb"

Returns: "abcd"


3)
"aaabbb"

Returns: ""

No letter can win.


4)
"rdokcogscosn"

Returns: "cos"

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;

class HappyLetterDiv1 {
public:
	string getHappyLetters(string letters) {
		IntVec chars(26);
		for (char c : letters) {
			chars[c - 'a'] += 1;
		}
		string ans;
		for (int i = 0; i < 26; ++i) {
			IntVec cnt = chars;
			int p = cnt[i];
			cnt[i] = 0;

			while (true) {
				sort(cnt.begin(), cnt.end());
				if (cnt[24] > 0 && cnt[25] > 0) {
					cnt[24]--, cnt[25]--;
				} else {
					break;
				}
			}

			int q = accumulate(cnt.begin(), cnt.end(), 0);
			if (p > q) {
				ans += ('a' + i);
			}
		}
		return ans;
	}

private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aabbacccc";
			string Arg1 = "abc";

			verify_case(n, Arg1, getHappyLetters(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaaaaaccdd";
			string Arg1 = "a";

			verify_case(n, Arg1, getHappyLetters(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ddabccadb";
			string Arg1 = "abcd";

			verify_case(n, Arg1, getHappyLetters(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaabbb";
			string Arg1 = "";

			verify_case(n, Arg1, getHappyLetters(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "rdokcogscosn";
			string Arg1 = "cos";

			verify_case(n, Arg1, getHappyLetters(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "aabbccd";
			string Arg1 = "abcd";

			verify_case(n, Arg1, getHappyLetters(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	HappyLetterDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
