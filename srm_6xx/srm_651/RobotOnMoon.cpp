// BEGIN CUT HERE
/*
SRM 651 Div1 Easy (250)

PROBLEM STATEMENT
There is a robot on the moon.
You are given a vector <string> board containing the map of a rectangular area.
The robot is currently located somewhere in that area.
In the map, the character '.' (period) represents an empty square, 'S' represents an empty square that currently contains the robot, and '#' represents an obstacle.

We are going to send a sequence of commands to the robot.
Each command must be one of 'U', 'D', 'L', and 'R', representing a step up, down, left, and right, respectively.

Whenever the robot receives a command, one of three things will happen:

If the requested move leads to an empty square, the robot performs the move.
If the requested move leads to a square with an obstacle, the robot ignores the command and remains in place.
If the requested move leads out of the mapped area, the robot leaves the mapped area and dies immediately.

A sequence of commands is called safe if the robot is still alive after executing the entire sequence.

When sending commands to the moon, some of them may get lost along the way.
This may sometimes change a safe sequence of commands into an unsafe one.
We want to avoid that.


A sequence of commands is called perfectly safe if it is safe, and each of its subsequences is safe as well.
(Note that this includes subsequences that are not contiguous.)


Find and return the largest X such that there is a perfectly safe sequence of X commands.
If there are arbitrarily long perfectly safe sequences, return -1 instead.


DEFINITION
Class:RobotOnMoon
Method:longestSafeCommand
Parameters:vector <string>
Returns:int
Method signature:int longestSafeCommand(vector <string> board)


NOTES
-The direction 'U' corresponds to moving from board[i][j] to board[i-1][j]. The direction 'L' corresponds to moving from board[i][j] to board[i][j-1].


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will contain between 1 and 50 characters.
-Each element of board will contain same number of characters.
-The characters in board will be '.', '#' or 'S'.
-There will be exactly one 'S' in board.


EXAMPLES

0)
{"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#####"}

Returns: -1

There are obstacles all around the map. This means that all possible sequences of commands are perfectly safe.


1)
{"S......"}

Returns: 6

The longest perfectly safe string is "RRRRRR"


2)
{"#.######",
 "#.#..S.#",
 "#.#.##.#",
 "#......#",
 "########"}

Returns: -1

Even though it is possible to leave this map, there are still arbitrarily long perfectly safe sequences of commands. For example, any sequence that does not contain any 'U' is perfectly safe.


3)
{"S"}

Returns: 0

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class RobotOnMoon {
public:
	int longestSafeCommand(vector <string> board) {
		int W = (int)board[0].length();
		int H = (int)board.size();
		for (int i = 0; i < H; ++i) {
			int x = (int)board[i].find('S');
			if (x >= 0) {
				if (board[i].find('#') != string::npos) {
					return -1;
				}
				for (int j = 0; j < H; ++j) {
					if (board[j][x] == '#') {
						return -1;
					}
				}
			}
		}
		return W + H - 2;
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
			string Arr0[] = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#####"};
			int Arg1 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, longestSafeCommand(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"S......"};
			int Arg1 = 6;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, longestSafeCommand(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#.######",
 "#.#..S.#",
 "#.#.##.#",
 "#......#",
 "########"};
			int Arg1 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, longestSafeCommand(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"S"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, longestSafeCommand(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
				"........S......" };
			int Arg1 = 14;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, longestSafeCommand(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RobotOnMoon ___test;
	___test.run_test(-1);
}
// END CUT HERE
