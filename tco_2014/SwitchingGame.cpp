// BEGIN CUT HERE
/*
TCO 2014 Round 2B Easy (350)

PROBLEM STATEMENT
You're playing a game with lamps.
There are M lamps in a row.
The lamps are numbered 0 through M-1.
Initially, all lamps are turned off.

The game consists of N levels.
The levels are numbered 0 through N-1.
Each level is described by a string of M characters.
For each i, character i of that string gives the required state of lamp i.
Each of these characters will be either '+', '-', or '?'.
Here, '+' means that the lamp must be on, '-' means that the lamp must be off, and '?' means that the lamp may be in either state.

The game is played in turns.
Each turn takes one second.
In each turn, you may do one of three things:

You may choose any subset of lamps that are all turned off, and turn all of them on.
You may choose any subset of lamps that are all turned on, and turn all of them off.
You may press the big red button that says "Check!".

Whenever you press the button, the current states of all lamps are checked against the requirements of the current level.
If all lamps satisfy the requirements, you solved the current level.
You win the game by solving all N levels.
You must solve the levels in the given order, starting with level 0.
Note that the lamps do not reset between levels: you continue playing the next level from the state you had when you solved the previous level.

Return the smallest number of seconds it takes to win the game if you play optimally.


DEFINITION
Class:SwitchingGame
Method:timeToWin
Parameters:vector <string>
Returns:int
Method signature:int timeToWin(vector <string> states)


CONSTRAINTS
-states will contain exactly N elements.
-N will be between 1 and 50, inclusive.
-Each element of states will contain exactly M characters.
-M will be between 1 and 50, inclusive.
-Each character of states will be '+', '-' or '?'.


EXAMPLES

0)
{"++--",
 "--++"}

Returns: 5

The following sequence of actions wins the game in five seconds:

Turn lamps 0 and 1 on.
Press the button to win level 0.
Turn lamps 0 and 1 off.
Turn lamps 2 and 3 on.
Press the button to win level 1 and thus win the game.


1)
{"+-++",
 "+-++"}

Returns: 3

Each time you press the button you can only win a single level.
Even though levels 0 and 1 are identical, you have to press the button twice in a row to win both of them.


2)
{"++",
 "+?",
 "?+",
 "++"}

Returns: 5

Here we can simply turn both lamps on, and then use that configuration to win all four levels.


3)
{"+", 
 "?",
 "?",
 "?",
 "-"}

Returns: 7

At some point between winning level 0 and winning level 4 we have to turn the lamp off.


4)
{"+??+++",
 "++??+-",
 "?++??+",
 "?-+-??",
 "??+?++",
 "++-?+?",
 "?++?-+",
 "?--+++",
 "-??-?+"}

Returns: 20

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SwitchingGame {
public:
	int timeToWin(vector <string> states) {
		int N = (int)states.size();
		int M = (int)states[0].length();
		int ans = N;
		char st[64] = "---------------------------------------------------------------";
		for (int i = 0; i < N; ++i) {
			bool on = false, off = false;
			for (int j = 0; j < M; ++j) {
				if (states[i][j] == '+' && st[j] == '-') {
					on = true;
				}
				if (states[i][j] == '-' && st[j] == '+') {
					off = true;
				}
			}
			for (int j = 0; j < M; ++j) {
				if (states[i][j] == '?') {
					if ((on && st[j] == '-') || (off && st[j] == '+')) {
						st[j] = '?';
					}
				} else {
					st[j] = states[i][j];
				}
			}
			ans += on + off;
		}
		return ans;
	}

// BEGIN CUT HERE
	int timeToWin2(vector <string> states) {
		int N = (int)states.size();
		int M = (int)states[0].length();
		int ans = N;
		int st[64] = {};
		int off[64] = {};
		int on[64] = {};
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (states[i][j] == '-' && st[j] != 0) {
					int x = 1;
					for (int k = i - 1; k >= 0; --k) {
						if (states[k][j] != '?') {
							break;
						}
						if (off[k]) {
							x = 0;
						}
					}
					off[i] |= x;
				}
				if (states[i][j] == '+' && st[j] == 0) {
					int x = 1;
					for (int k = i - 1; k >= 0; --k) {
						if (states[k][j] != '?') {
							break;
						}
						if (on[k]) {
							x = 0;
						}
					}
					on[i] |= x;
				}
			}
			ans += off[i] + on[i];
			for (int j = 0; j < M; ++j) {
				if (states[i][j] == '-') {
					st[j] = 0;
				}
				if (states[i][j] == '+') {
					st[j] = 1;
				}
			}
		}

		return ans;
	}

private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"++--",
 "--++"};
			int Arg1 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, timeToWin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"+-++",
 "+-++"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, timeToWin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"++",
 "+?",
 "?+",
 "++"};
			int Arg1 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, timeToWin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"+", 
 "?",
 "?",
 "?",
 "-"};
			int Arg1 = 7;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, timeToWin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"+??+++",
 "++??+-",
 "?++??+",
 "?-+-??",
 "??+?++",
 "++-?+?",
 "?++?-+",
 "?--+++",
 "-??-?+"}
;
			int Arg1 = 20;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, timeToWin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SwitchingGame ___test;
	___test.run_test(-1);

	vector<string> v(3);
	v[0] = "???";
	v[1] = "???";
	v[2] = "???";

	for (int a = 0; a < 19683; ++a) {
		const char ch[] = "?-+";
		int r = a;
		for (int b = 0; b < 9; ++b) {
			v[b / 3][b % 3] = ch[r % 3];
			r /= 3;
		}
		int p = ___test.timeToWin2(v);
		int q = ___test.timeToWin(v);
		if (p != q) {
			cout << "mine:" << p << ",target:" << q << endl;
			for (int i = 0; i < 3; ++i) {
				printf("%s\n", v[i].c_str());
			}
			break;
		}
	}
}
// END CUT HERE
