// BEGIN CUT HERE
/*
SRM 749 Div2 Easy (250)

PROBLEM STATEMENT

Hero is fighting against a monster.

Hero's basic attack deals attack points of damage.
Hero also has a special skill that gradually increases the amount of damage he deals when attacking the same monster multiple times in a row.
Hero has level skill points in this skill.
The effect of the skill is such that in each of the following attacks the damage is increased by level percent of the damage dealt by the basic attack.
In other words, if Hero already attacked the monster n times, the next attack after that will deal attack + n * (level percent of attack) damage.

Hero is going to attack the monster duration times in a row. Calculate and return the total amount of damage he will deal.


DEFINITION
Class:FightMonsterDiv2
Method:damageDealt
Parameters:long long, long long, long long
Returns:long long
Method signature:long long damageDealt(long long attack, long long level, long long duration)


CONSTRAINTS
-attack will be between 100 and 100,000, inclusive.
-attack will be a multiple of 100.
-level will be between 0 and 100, inclusive.
-duration will be between 1 and 100,000, inclusive.


EXAMPLES

0)
100
10
3

Returns: 330

The first attack will deal 100 damage.
The second attack will deal 100 + 10 = 110 damage.
The third attack will deal 110 + 10 = 120 damage.


1)
100
0
5

Returns: 500

With level = 0, the increment is zero and thus each of the five attacks will deal 100 damage.


2)
100000
100
100000

Returns: 500005000000000

This is the largest possible input. Watch out for integer overflow.

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

class FightMonsterDiv2 {
public:
	long long damageDealt(long long attack, long long level, long long duration) {
		return attack * duration + ((duration - 1) * duration) / 2 * (attack * level / 100);
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 100LL;
			long long Arg1 = 10LL;
			long long Arg2 = 3LL;
			long long Arg3 = 330LL;

			verify_case(n, Arg3, damageDealt(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 100LL;
			long long Arg1 = 0LL;
			long long Arg2 = 5LL;
			long long Arg3 = 500LL;

			verify_case(n, Arg3, damageDealt(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 100000LL;
			long long Arg1 = 100LL;
			long long Arg2 = 100000LL;
			long long Arg3 = 500005000000000LL;

			verify_case(n, Arg3, damageDealt(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FightMonsterDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
