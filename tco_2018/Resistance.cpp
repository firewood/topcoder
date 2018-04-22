// BEGIN CUT HERE
/*
TCO18 R1A Medium (500)

PROBLEM STATEMENT

The Resistance is a multiplayer board game.
During the game each player belongs into one of two groups: some are resistance members, others are spies.
In this problem there are P players, and exactly S of them are spies.
The players are numbered 0 through P-1.

The game is played in rounds.
In each round of the game a subset of all players goes on a mission.
Each player who goes on the mission casts a secret vote on whether they want it to succeed or to fail.
Resistance members always vote for the mission to succeed, and spies may cast either vote.
(Sometimes a spy will vote for a mission to succeed in order to gain trust of the other players.)
If at least one player on a mission voted for it to fail, the mission fails.
If everybody voted for the mission to succeed, it succeeds.

You are given the ints P and S.
You are also given the vector <string> missions: data on all the missions that already took place.
Each mission is described by a string.
The first character of that string is 'F' for a failed mission or 'S' for a successful one.
The next P characters describe which players went on the mission: for each valid i, character (i+1) is '1' if player i went on the misson and '0' otherwise.

Verify whether the mission history is valid.
If there is no assignment of roles (spies / resistance members) to players that would be consistent with the given mission history, return an empty vector <double>.

If the mission history is valid, assume that each of the matching assignments of roles to players is equally likely.
Return a vector <double> containing P elements.
For each i, the i-th element of the return value should be the probability that player i is a spy, given the above assumption.


DEFINITION
Class:Resistance
Method:spyProbability
Parameters:int, int, vector <string>
Returns:vector <double>
Method signature:vector <double> spyProbability(int P, int S, vector <string> missions)


NOTES
-Each element of your return value must have an absolute or a relative error smaller than 1e-9.


CONSTRAINTS
-P will be between 3 and 10, inclusive.
-S will be between 1 and P, inclusive.
-missions will contain between 1 and 50 elements, inclusive.
-Each element of missions will contain exactly P+1 characters.
-For each element of missions, its first character will be 'S' or 'F', and the rest of the characters will be '0' or '1'.
-Each element of missions will contain at least one '1' character.


EXAMPLES

0)
4
1
{"S0110",
 "F1100",
 "S0011"}

Returns: {0.5, 0.5, 0.0, 0.0 }

There is only one spy. Players 2 and 3 cannot be the spy because neither of them went on the failed mission. Players 0 and 1 can be spies. As both scenarios are valid, each of these two players is a spy with probability 50%.


1)
4
2
{"F0100",
 "S0101",
 "F1010",
 "S1011"}

Returns: {0.5, 1.0, 0.5, 0.0 }

Now we have two spies. Only one player went to the first failed mission, so we can be certain that player 1 is a spy. Based on the second failed mission, one of players 0 and 2 must be a spy. Both possibilities match the rest of the input, so we assign each of them probability 50% of being a spy.

Note that player 1 (a known spy) once voted for a success of a mission.


2)
3
1
{"F110",
 "F101",
 "F011"}

Returns: { }

There is supposed to be only one spy, but no player went on all three failed missions, so the mission history is invalid.


3)
5
2
{"F11000",
 "S00011",
 "F10100",
 "S01111"}

Returns: {0.8, 0.4, 0.4, 0.2, 0.2 }

One possibility is that the spies are players 1 and 2. Another possibility is that one of the spies is player 0 and the other spy can be any of the other four players.


4)
9
3
{"S100001100",
 "F011110000",
 "F001000010",
 "F100010101",
 "S010010001",
 "F100001010",
 "F000100100"}

Returns: {0.3, 0.1, 0.4, 0.5, 0.2, 0.1, 0.6, 0.7, 0.1 }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

static inline int popcount(unsigned int b)
{
#ifdef __GNUC__
	return __builtin_popcount(b);
#elif _MSC_VER >= 1400
	return __popcnt(b);
#else
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	b += b >> 16;
	return b & 0x3F;
#endif
}

class Resistance {
public:
	vector <double> spyProbability(int P, int S, vector <string> missions) {
		int m = (int)missions.size();
		int bm = 1 << P;
		int vc = 0;
		int scnt[10] = {};
		for (int b = 0; b < bm; ++b) {
			if (popcount(b) == S) {
				bool valid = true;
				for (int i = 0; i < m; ++i) {
					if (missions[i][0] == 'F') {
						bool ok = false;
						for (int j = 0; j < P; ++j) {
							if (missions[i][j+1] == '1' && (((1 << j) & b) != 0)) {
								ok = true;
								break;
							}
						}
						if (!ok) {
							valid = false;
							break;
						}
					}
				}
				if (valid) {
					++vc;
					for (int j = 0; j < P; ++j) {
						for (int i = 0; i < m; ++i) {
							if ((((1 << j) & b) != 0)) {
								scnt[j]++;
								break;
							}
						}
					}
				}
			}
		}
		vector <double> ans;
		if (vc) {
			for (int j = 0; j < P; ++j) {
				ans.push_back((1.0 * scnt[j]) / vc);
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 1;
			string Arr2[] = {"S0110",
 "F1100",
 "S0011"};
			double Arr3[] = {0.5, 0.5, 0.0, 0.0 };

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, spyProbability(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 2;
			string Arr2[] = {"F0100",
 "S0101",
 "F1010",
 "S1011"};
			double Arr3[] = {0.5, 1.0, 0.5, 0.0 };

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, spyProbability(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 1;
			string Arr2[] = {"F110",
 "F101",
 "F011"};
//			double Arr3[] = { };

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <double> Arg3;
			verify_case(n, Arg3, spyProbability(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 2;
			string Arr2[] = {"F11000",
 "S00011",
 "F10100",
 "S01111"};
			double Arr3[] = {0.8, 0.4, 0.4, 0.2, 0.2 };

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, spyProbability(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arg1 = 3;
			string Arr2[] = {"S100001100",
 "F011110000",
 "F001000010",
 "F100010101",
 "S010010001",
 "F100001010",
 "F000100100"};
			double Arr3[] = {0.3, 0.1, 0.4, 0.5, 0.2, 0.1, 0.6, 0.7, 0.1 };

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, spyProbability(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 5;
			int Arg1 = 2;
			string Arr2[] = { "S100001100" };
			double Arr3[] = { 0.4, 0.4, 0.4, 0.4, 0.4 };

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, spyProbability(Arg0, Arg1, Arg2));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Resistance ___test;
	___test.run_test(-1);
}
// END CUT HERE
