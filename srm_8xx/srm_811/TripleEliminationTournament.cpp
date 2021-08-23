// BEGIN CUT HERE
/*
SRM 811 Div2 Easy (250)

PROBLEM STATEMENT

There are various types of tournaments: round-robin in which each pair of players plays each other, single-elimination in which once you lose, you are out, and many others.

This problem is about a triple-elimination tournament. In such a tournament a player is only eliminated if they lose three games.

The tournament is played in rounds.
In each rounds the players who are still in the tournament are paired up and each pair plays a game (in which one player wins and the other loses).

More precisely, each round looks as follows:

The players are divided into four groups: group 0, 1, 2, and 3. The group number represents the number of losses the player already has in the tournament. (E.g., in the first round everyone is in group 0. In the second round approximately half of the players are still in group 0 and half are in group 1.)
Everyone who is in group 3 (has three losses) is eliminated from the tournament.
If exactly one player remains, that player is declared the winner and the tournament is over.?
Players in group 0 are divided into pairs.
If group 0 has an odd number of players, the last remaining player is paired with a player from the next non-empty group (if there are still some unpaired players left).
Steps 4 and 5 are repeated for the unpaired players in group 1. Then, the same steps are repeated for unpaired players in group 2.
If one player remained unpaired, that player has a bye - they won't play in this round.
Each pair of players plays a game. In the game one player wins and the other loses.

You are given the number N of players at the beginning of the tournament.
You are also given the group G which contained the player who won the tournament at the moment the tournament ended.

Determine and return the total number of games that were played in the tournament.


DEFINITION
Class:TripleEliminationTournament
Method:countGames
Parameters:int, int
Returns:int
Method signature:int countGames(int N, int G)


NOTES
-The answer you should return can always be uniquely determined from the data you were given.
-The answer will always fit into a 32-bit signed int.
-Please note that you are asked to return the total number of games played and not the total number of rounds in the tournament.


CONSTRAINTS
-N will be between 2 and 10^6, inclusive.
-G will be between 0 and 2, inclusive.


EXAMPLES

0)
2
0

Returns: 3

There were two players: Lee Chong Wei and Lin Dan. The tournament had three rounds. In each round the two players were paired together and in each round Lee Chong Wei won. After three losses, Lin Dan got eliminated and Lee Chong Wei won the tournament.


1)
3
1

Returns: 7


Suppose there are three players: A, B, C.

In the first round all of them are in group 0. Two will get paired and the third one will get a bye. For example, assume A plays B and C gets a bye. A wins.

In the second round A and C are still in group 0 (no losses) while B is in group 1. A and C play each other, B gets a bye. Suppose C wins the game.

In the third round, C is the only player in group 0 while both A and B are now in group 1. As described in step 5, C gets paired to somebody from the next group - for example, C may get paired with B. When we then go to process group 1, only A is still unpaired. As we don't have any other players, A remains unpaired and gets a bye. Suppose B wins the game.

In the fourth round all three players are in group 1. From this point the tournament will continue for several more rounds until eventually two of the three players are eliminated.


2)
8
0

Returns: 21


Sometimes it is possible that the input corresponds to multiple very different tournaments. In this case we can uniquely determine the number of players in each group at the beginning of each round. These numbers are shown below:

round | group sizes at its start | number of games played
------+--------------------------+-----------------------
	1 | 8 0 0 0                  | 4
	2 | 4 4 0 0                  | 4
	3 | 2 4 2 0                  | 4
	4 | 1 3 3 1                  | 3 (one player got eliminated, one got a bye)
	5 | 1 1 4 1                  | 3 (one eliminated)
	6 | 1 0 3 2                  | 2 (two eliminated)
	7 | 1 0 1 2                  | 1 (two eliminated)
	8 | 1 0 0 1                  | tournament over


The total number of games was 4+4+4+3+3+2+1 = 21.


Note that in round 6 the only player in group 0 got paired with one of the three players in group 2.


3)
436475
2

Returns: 1309424

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

class TripleEliminationTournament {
public:
	int countGames(int N, int G) {
#if 1
		int ans = (N - 1) * 3 + G;
#else
		int ans = 0;
		vector<int> g(4);
		g[0] = N;
		while (g[0] + g[1] + g[2] > 1) {
			vector<int> next(4);
			int cg = -1;
			for (int i = 0; i <= 2; ++i) {
				if (cg >= 0) {
					if (g[i] == 0) {
						continue;
					}
					if (cg == G) {
						next[cg] += 1;
						next[i + 1] += 1;
					} else {
						next[cg + 1] += 1;
						next[i] += 1;
					}
					g[i]--;
					cg = -1;
					++ans;
				}
				int w = g[i] / 2;
				next[i] += w;
				next[i + 1] += w;
				ans += w;
				if (g[i] % 2) {
					cg = i;
				}
			}
			if (cg >= 0) {
				next[cg] += 1;
			}
			g = next;
		}
#endif
		return ans;
	}

	// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T>& V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int& Expected, const int& Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) {
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 2;
			int Arg1 = 0;
			int Arg2 = 3;

			verify_case(n, Arg2, countGames(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 3;
			int Arg1 = 1;
			int Arg2 = 7;

			verify_case(n, Arg2, countGames(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 8;
			int Arg1 = 0;
			int Arg2 = 21;

			verify_case(n, Arg2, countGames(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 436475;
			int Arg1 = 2;
			int Arg2 = 1309424;

			verify_case(n, Arg2, countGames(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1000000;
			int Arg1 = 0;
			int Arg2 = 2999997;

			verify_case(n, Arg2, countGames(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1000000;
			int Arg1 = 1;
			int Arg2 = 2999998;

			verify_case(n, Arg2, countGames(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1000000;
			int Arg1 = 2;
			int Arg2 = 2999999;

			verify_case(n, Arg2, countGames(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arg0 = 2;
			int Arg1 = 0;
			int Arg2 = 3;

			verify_case(n, Arg2, countGames(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 5;

			verify_case(n, Arg2, countGames(Arg0, Arg1));
		}
		n++;


	}

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TripleEliminationTournament ___test;
	___test.run_test(-1);
}
// END CUT HERE
