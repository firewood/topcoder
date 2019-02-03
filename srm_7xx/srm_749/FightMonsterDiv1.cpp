// BEGIN CUT HERE
/*
SRM 749 Div1 Easy (250)

PROBLEM STATEMENT

Hero is fighting against a monster.
The monster has hp hit points.
This means that the monster will die when Hero deals it a total of hp damage or more.

Hero's basic attack deals attack points of damage.
He has two things that can help him defeat the monster: a special passive skill and a magic scroll.

Hero has level skill points in the skill.
The skill gradually increases the amount of damage he deals when attacking the monster multiple times.
More precisely, each attack after the first one will deal M more points of damage than the previous one, where M = (level percent of attack).

The magic scroll can only be used once.
The scroll activates a spell that will affect the next duration attacks.
During each of these attacks Hero deals not just regular damage (calculated as explained above) but also magical damage.
The amount of magical damage is always exactly four times the amount of regular damage.

One attack takes one second.
Activating the scroll also takes one second (and during that second Hero cannot attack).
Return the smallest number of seconds needed to kill the monster.


DEFINITION
Class:FightMonsterDiv1
Method:fightTime
Parameters:long long, long long, int, long long
Returns:long long
Method signature:long long fightTime(long long hp, long long attack, int level, long long duration)


CONSTRAINTS
-hp will be between 1 and 1012, inclusive.
-attack will be between 100 and 1012, inclusive.
-attack will be a multiple of 100.
-level will be between 0 and 100, inclusive.
-duration will be between 1 and 1012, inclusive.


EXAMPLES

0)
201
100
10
10

Returns: 2


Hero can just attack. The first attack will deal 100 damage, the second one will deal 110 damage, and the monster will be defeated.

Alternately, Hero can read the scroll and then deal 100 regular + 400 magical = 500 damage in a single attack.


1)
74900
100
0
2

Returns: 742

Here is one optimal solution:

Attack the monster 9 times, each time dealing 100 damage. (Total: 9 seconds, 900 damage.)
Read the scroll. (Total: 10 seconds, 900 damage.)
Attack the monster twice with the bonus from the spell, each time dealing 500 damage. (Total: 12 seconds, 1900 damage.)
Attack the monster another 730 times, each time only dealing 100 damage again. (Total: 742 seconds, 74900 damage.)


2)
1000000000000
1000000000000
100
1000000000000

Returns: 1


3)
1338
100
1
2

Returns: 6

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

#ifdef __GNUC__
#define int128_t __int128
#else
#include <boost/multiprecision/cpp_int.hpp>
typedef boost::multiprecision::int128_t int128_t;
#endif

typedef long long LL;

class FightMonsterDiv1 {
	bool possible(int128_t hp, int128_t attack, int128_t level, int128_t duration, int128_t t) {
		if (t <= 1) {
			return t * attack >= hp;
		}
		int128_t a = ((t - 1) * t) / 2;
		int128_t m = (attack * level) / 100;
		if (hp <= (t * attack + a * m)) {
			return true;
		}
		--t;
		int128_t d = min(duration, t);
		a = ((t - 1) * t) / 2;
		int128_t b = ((t - 1 - d) * (t - d)) / 2;
		return hp <= ((t + d * 4) * attack + (a + (a - b) * 4) * m);
	}

public:
	long long fightTime(long long hp, long long attack, int level, long long duration) {
		LL left = 0, right = hp / attack + 1;
		while (right - left > 1) {
			LL mid = (left + right) / 2;
			if (possible(hp, attack, level, duration, mid)) {
				right = mid;
			} else {
				left = mid;
			}
		}
		return left + 1;
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
			long long Arg0 = 201LL;
			long long Arg1 = 100LL;
			int Arg2 = 10;
			long long Arg3 = 10LL;
			long long Arg4 = 2LL;

			verify_case(n, Arg4, fightTime(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 74900LL;
			long long Arg1 = 100LL;
			int Arg2 = 0;
			long long Arg3 = 2LL;
			long long Arg4 = 742LL;

			verify_case(n, Arg4, fightTime(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1000000000000LL;
			long long Arg1 = 1000000000000LL;
			int Arg2 = 100;
			long long Arg3 = 1000000000000LL;
			long long Arg4 = 1LL;

			verify_case(n, Arg4, fightTime(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1338LL;
			long long Arg1 = 100LL;
			int Arg2 = 1;
			long long Arg3 = 2LL;
			long long Arg4 = 6LL;

			verify_case(n, Arg4, fightTime(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			long long Arg0 = 999999917775;
			long long Arg1 = 400LL;
			int Arg2 = 41;
			long long Arg3 = 1000000000000LL;
			long long Arg4 = 49386LL;

			verify_case(n, Arg4, fightTime(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FightMonsterDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
