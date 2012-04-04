// BEGIN CUT HERE
/*
// TCO12 Round 1A Easy (250)

// PROBLEM STATEMENT
// Elly's memories of last night's sleepover with her friends are rather blurry.
She recalls that they played a game involving drinking orange and apple juice.
In the beginning there were two identical bottles. One contained a gallon of
orange juice, the other a gallon of apple juice. The game was played in turns,
starting with turn zero. In even-numbered turns (turn 0, 2, 4, ...) the current
player drank half of the remaining orange juice. In odd-numbered turns
(turn 1, 3, 5, ...) the current player drank half of the remaining apple juice.
The winner of the game is the player who drank the greatest total amount of
liquid during the game. If multiple players are tied for the greatest amount,
there is no winner.

For example, consider a game consisting of five turns. Suppose that the players
to drink were, in order, Elly, Kriss, Stancho, Elly, and Stancho. (That is,
Elly and Stancho both drank twice: Elly in turns 0 and 3, Stancho in turns 2 and 4.)
In this game, Elly drank 0.75 gallons of liquid (0.5 gallons of orange juice and
0.25 of apple juice), Kriss drank 0.5 gallons of apple juice, and Stancho drank
0.375 gallons of orange juice (0.25 gallons in turn 2 and another 0.125 gallons
in turn 4). In this game Elly would be the winner.

Elly knows all the people who played the game yesterday, and for each of them
the number of times they drank. However, she remembers nothing about the order
in which the players drank.

You are given a vector <string> players, containing the names of all players.
If a player's name is contained X times in players that means that he or she
drank exactly X times during the game. Determine all people who could have
possibly won the game (for some particular order of turns). Return their names
as a lexicographically sorted vector <string>. The return value should only
contain each of the names once.

DEFINITION
Class:EllysJuice
Method:getWinners
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> getWinners(vector <string> players)


NOTES
-A sequence of distinct strings is sorted if each element is lexicographically
 smaller than all the ones following it.
-string A is lexicographically smaller than string B if A contains smaller
 character at the first index where they differ. If there is no index where
 they differ, the shorter one is lexicographically smaller. For example
 "ariadne" is smaller than "elly", "abc" is smaller than "abd", "aaa" is
 smaller than "aaaaa", and "czzzzzzz" is smaller than "kaaaaaaa".


CONSTRAINTS
-players will contain between 1 and 8 elements, inclusive.
-Each element of players will contain between 1 and 20 characters, inclusive.
-Each element of players will consist only of lowercase English letters ('a'-'z').


EXAMPLES

0)
{ "elly", "kriss", "stancho", "elly", "stancho" }

Returns: {"elly", "stancho" }

Elly would win for the order given in the problem statement. If Stancho and
Elly swapped all their turns, Stancho would win the game. Kriss cannot win.


1)
{"torb", "elly", "stancho", "kriss"}

Returns: { }

In any valid game two of the four players would be tied for the lead (with half a gallon each).


2)
{"elly", "elly", "elly", "elly", "elly"}

Returns: {"elly" }

Since she was the only player, apparently she won.


3)
{ "ariadne", "elly", "ariadne", "stancho", "stancho", "kriss", "stancho", "elly" }

Returns: {"ariadne", "elly", "stancho" }

Although Stancho has drunk three times, there are orderings in which someone else wins.

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;
typedef set<string> StrSet;
typedef map<string, int> StrIntMap;

class EllysJuice {

public:
	vector <string> getWinners(vector <string> players) {
		vector <string> res;
		int n = players.size();
		StrIntMap m;
#if 1
		int i;
		for (i = 0; i < n; ++i) {
			m[players[i]] += 1;
		}
		if (m.size() == 1) {
			m.begin()->second += 1;
		}
		StrIntMap::const_iterator it;
		for (it = m.begin(); it != m.end(); ++it) {
			if (it->second >= 2) {
				res.push_back(it->first);
			}
		}
#else
		int i, j, k;
		for (i = 0; i < n; ++i) {
			m[players[i]] += 1;
		}

		i = 0, k = 0;
		int seq[8] = {};
		StrIntMap::const_iterator it;
		for (it = m.begin(); it != m.end(); ++it) {
			for (j = 0; j < it->second; ++j) {
				seq[i++] = k;
			}
			++k;
		}

		int w[8] = {};
		do {
			int d[9] = {};
			int b[2] = {256,256};
			for (i = 0; i < n; ++i) {
				d[seq[i]] += b[i%2];
				b[i%2] /= 2;
			}
			if (d[seq[0]] > d[seq[1]] || seq[0] == seq[1]) {
				++w[seq[0]];
			}
		} while (next_permutation(seq, seq + n));

		if (m.size() == 1) {
			w[0] = 1;
		}

		k = 0;
		for (it = m.begin(); it != m.end(); ++it) {
			if (w[k]) {
				res.push_back(it->first);
			}
			++k;
		}
#endif
		return res;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "elly", "kriss", "stancho", "elly", "stancho" };
			string Arr1[] = {"elly", "stancho" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getWinners(Arg0));
		}
		n++;


		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"torb", "elly", "stancho", "kriss"};

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1;
			verify_case(n, Arg1, getWinners(Arg0));
		}
		n++;


		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"elly", "elly", "elly", "elly", "elly"};
			string Arr1[] = {"elly" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getWinners(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "ariadne", "elly", "ariadne", "stancho", "stancho", "kriss", "stancho", "elly" };
			string Arr1[] = {"ariadne", "elly", "stancho" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getWinners(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "ariadne", "ariadne", "ariadne", "ariadne", "ariadne", "ariadne", "elly", "elly" };
			string Arr1[] = {"ariadne", "elly" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getWinners(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysJuice ___test;
//	___test.run_test(4);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
