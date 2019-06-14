// BEGIN CUT HERE
/*
SRM 760 Div2 Easy (250)

PROBLEM STATEMENT

In the finals of the NBA 2019 playoffs the (Golden State) Warriors are playing the (Toronto) Raptors.

A transcript of a game is a sequence of integers and a string of characters.
The transcript is obtained as follows: 
Whenever a team's possession of the ball ends in the team scoring some points, we append the number of points scored to the sequence of integers and we append a character representing the team ('W' for the Warriors, 'R' for the Raptors) to the string of characters.

Note that on each possession a team can score at most four points.
(The four-point play occurs when a player scores a field goal and then gets awarded free throw(s) for being fouled while making the shot.)

For example, the sequence {2, 4, 1} and the string "RWW" represent a game in which first the Raptors scored 2 points, then the Warriors scored 4 points, and then the Warriors scored another 1 point.

Teja is rooting for the Warriors.
However, he was busy preparing problems for this SRM and he missed one of the games.
He only has a transcript of the game: the vector <int> scores and the string team.

The transcript of the game is damaged: some values in scores and some (not necessarily the same) characters in team have been erased.
In scores the erased values are represented by zeros and in team the erased characters are represented by question marks.

Help Teja determine whether the Warriors could have won the game at the end of the transcript.
Return 1 if it is possible and 0 if it isn't.


DEFINITION
Class:NBAFinals
Method:dubsAgain
Parameters:vector <int>, string
Returns:int
Method signature:int dubsAgain(vector <int> scores, string team)


NOTES
-For the purpose of this problem, a tie is not a win. You should return 1 only if it is possible that at the end of the transcript the Warriors had strictly more points than the Raptors. See Example #1.
-Remember that in a correct transcript each score must be between 1 and 4, inclusive.


CONSTRAINTS
-scores will contain between 1 and 100 elements, inclusive.
-Each element of scores will be between 0 and 4, inclusive.
-The length of team will be equal to the number of elements in scores.
-Each character in team will be one of 'W', 'R', and '?'.


EXAMPLES

0)
{2, 2, 3, 3, 2, 4, 2}
"RRWWRWR"

Returns: 1

This is a full transcript of a game in which the Warriors scored 3+3+4 = 10 points while the Raptors only scored 2+2+2+2 = 8 points.


1)
{2, 2, 3, 3, 2, 3, 3}
"RRWWRWR"

Returns: 0

This is a transcript of a game that ended in a tie. (Although in NBA the game would continue into overtime in case of a tie, in this problem inputs like this one can still appear. We are asking whether the Warriors could have won at the end of the given transcript. A tie is not a win, so you should return 0.)


2)
{0, 3}
"WR"

Returns: 1

The Warriors scored some unknown number of points and then the Raptors scored a three-pointer. It is still possible that the Warriors won: the erased score could have been a 4.


3)
{3, 0, 0}
"RWR"

Returns: 0

The Warriors cannot have won this game. Remember that each of the erased values must be between 1 and 4, inclusive, so the Raptors have scored at least four points and the Warriors have scored at most four points.


4)
{0, 0, 0, 0}
"????"

Returns: 1


5)
{3, 2, 3, 2}
"?WR?"

Returns: 1


6)
{0, 1, 2, 3, 4}
"R?W?R"

Returns: 1

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class NBAFinals {
public:
	int dubsAgain(vector <int> scores, string team) {
		int tot[2] = {};
		for (int i = 0; i < (int)scores.size(); ++i) {
			int s = scores[i];
			if (!s) {
				s = team[i] != 'R' ? 4 : 1;
			}
			tot[team[i] != 'R'] += s;
		}
		return tot[1] > tot[0];
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
			int Arr0[] = {2, 2, 3, 3, 2, 4, 2};
			string Arg1 = "RRWWRWR";
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, dubsAgain(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 2, 3, 3, 2, 3, 3};
			string Arg1 = "RRWWRWR";
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, dubsAgain(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 3};
			string Arg1 = "WR";
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, dubsAgain(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3, 0, 0};
			string Arg1 = "RWR";
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, dubsAgain(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0, 0};
			string Arg1 = "????";
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, dubsAgain(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3, 2, 3, 2};
			string Arg1 = "?WR?";
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, dubsAgain(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 1, 2, 3, 4};
			string Arg1 = "R?W?R";
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, dubsAgain(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NBAFinals ___test;
	___test.run_test(-1);
}
// END CUT HERE
