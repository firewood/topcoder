// BEGIN CUT HERE
/*
SRM 780 Div1 Easy (250)

PROBLEM STATEMENT

Beat the Star is a TV game show franchise started by the German original Schlag den Raab.
In the game show a candidate attempts to beat a celebrity in a series of games.
There are N games, numbered 1 to N.
Each game has a winner and a loser.
The winner of game X is awarded X points.
The winner of the game show is the player (either the celebrity or the candidate) whose point total at the end is bigger.

In this problem we will make two simplifying assumptions (in comparison to the actual show):

N will be such that the total number of points is odd, so that we do not have to handle ties.
We will assume that all games always get played, even if the final winner is already known by that point.

You are soon going to take part in the game show as the candidate.
The celebrity you'll compete against happens to be your twin.
When trying to find an edge that would help you in the game, you watched many episodes of the show and you realized that the early games matter even less than it seems.
Hence, you could save your strength by giving up some of the early games with the hope that this will help you beat your twin in the later games that are worth more points.

In this problem we want you to analyze how much each of the individual games matters.
More precisely, we ask the following question:
Assume that in each game each player wins with probability 50 percent.
What is the probability that at the end game number G actually matters?
(Given the full results of the show, game G matters if changing the winner of G would change the winner of the show.)


DEFINITION
Class:BeatTheStar
Method:doesItMatter
Parameters:int, int
Returns:double
Method signature:double doesItMatter(int N, int G)


NOTES
-The return value must have an absolute error at most 1e-9.


CONSTRAINTS
-N will be between 1 and 100, inclusive.
-N will be such that the total number of points in the show is odd.
-G will be between 1 and N, inclusive.


EXAMPLES

0)
2
1

Returns: 0.0

There are two games: game 1 awards one point and game 2 awards two. In this setting, game 1 does not matter at all: the winner of game 2 wins the show.


1)
5
5

Returns: 0.625

If there are five games, game 5 matters quite often so winning it is crucial.


2)
5
1

Returns: 0.125

Game 1 matters much less.


3)
5
2

Returns: 0.125

Perhaps quite surprisingly, even though game 2 is worth twice as many points as game 1, in this particular format their importance is exactly the same.


4)
9
7

Returns: 0.328125

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class BeatTheStar {
public:
	double doesItMatter(int N, int G) {
		long double dp[102][5200] = {};
		dp[0][0] = 1.0;
		for (int i = 1; i <= N; ++i) {
			if (i == G) {
				for (int t = 0; t <= 5050; ++t) {
					dp[i][t] += dp[i - 1][t];
				}
			} else {
				for (int t = 0; t <= 5050; ++t) {
					dp[i][t] += dp[i - 1][t] * 0.5;
					dp[i][t + i] += dp[i - 1][t] * 0.5;
				}
			}
		}
		int h = ((N + 1) * N) / 4;
		long double ans = 0;
		for (int i = 0; i <= h; ++i) {
			if (i + G > h) {
				ans += dp[N][i];
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (fabs(Expected - Received)<1e-9) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;
			double Arg2 = 0.0;

			verify_case(n, Arg2, doesItMatter(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 5;
			double Arg2 = 0.625;

			verify_case(n, Arg2, doesItMatter(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 1;
			double Arg2 = 0.125;

			verify_case(n, Arg2, doesItMatter(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 2;
			double Arg2 = 0.125;

			verify_case(n, Arg2, doesItMatter(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arg1 = 7;
			double Arg2 = 0.328125;

			verify_case(n, Arg2, doesItMatter(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 98;
			int Arg1 = 98;
			double Arg2 = 0.139318092382;

			verify_case(n, Arg2, doesItMatter(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1;
			int Arg1 = 1;
			double Arg2 = 1.0;

			verify_case(n, Arg2, doesItMatter(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BeatTheStar ___test;
	___test.run_test(-1);
}
// END CUT HERE
