// BEGIN CUT HERE
/*
SRM 582 Div1 Easy (250)

PROBLEM STATEMENT
Magical Girls are girls who have magical powers.
They fight against evil to protect the Earth.
Cosmic enemies have just attacked the Earth, and the Magical Girls are going to fight them.

You are given a vector <int> magicalGirlStrength that describes the Magical Girls:
for each i, magicalGirlStrength[i] is the strength of one of the girls.
You are also given a vector <int> enemyStrength and a vector<long long> enemyCount that describe their enemies:
for each i, there are enemyCount[i] enemies that each have strength enemyStrength[i].

Each Magical Girl will always fight one enemy at a time.
A Magical Girl will defeat her enemy if her strength is greater than or equal to the strength of that enemy.

At the beginning of the fight the fatigue of each Magical Girl is 0.
Each time a Magical Girl defeats an enemy, her fatigue increases by 1.

The Magical Girls want to defeat all the enemies.
That is, each of the enemies must be defeated by one of the Magical Girls.
Additionally, the Magical Girls want to minimize the maximum fatigue among them.

If it is impossible to defeat all of the enemies, return -1.
Otherwise, return the smallest F with the following property:
the Magical Girls can defeat all enemies in such a way that at the end the fatigue of each girl is at most F.

DEFINITION
Class:SpaceWarDiv1
Method:minimalFatigue
Parameters:vector <int>, vector <int>, vector<long long>
Returns:long long
Method signature:long long minimalFatigue(vector <int> magicalGirlStrength, vector <int> enemyStrength, vector<long long> enemyCount)


NOTES
-The elements of enemyStrength are not necessarily pairwise distinct.


CONSTRAINTS
-magicalGirlStrength will contain between 1 and 50 elements, inclusive.
-Each element of magicalGirlStrength will be between 1 and 10,000, inclusive.
-enemyStrength and enemyCount will each contain between 1 and 50 elements, inclusive.
-enemyStrength and enemyCount will contain the same number of elements.
-Each element of enemyStrength will be between 1 and 10,000, inclusive.
-Each element of enemyCount will be between 1 and 100,000,000,000,000 (10^14), inclusive.


EXAMPLES

0)
{2, 3, 5}
{1, 3, 4}
{2, 9, 4}

Returns: 7

There are 3 Magical Girls, their strength are 2, 3, and 5.
There are 3 kinds of enemies: 2 enemies with strength 1 each, 9 enemies with strength 3 each, and 4 enemies with strength 4 each.
This is one of the ways how to minimize the maximal fatigue:

Magical girl 0 defeats 2 enemies with strength 1.
Magical girl 1 defeats 7 enemies with strength 3.
Magical girl 2 defeats 2 enemies with strength 3 and 4 enemies with strength 4.


1)
{2, 3, 5}
{1, 1, 2}
{2, 9, 4}

Returns: 5

Each of the Magical Girls can defeat any of the enemies. The optimal strategy is that each girl should defeat 5 of the enemies.


2)
{14, 6, 22}
{8, 33}
{9, 1}

Returns: -1

None of the magical girls can defeat the enemy with strength 33.


3)
{869, 249, 599, 144, 929, 748, 665, 37, 313, 99, 33, 437, 308, 137, 665, 834, 955, 958, 613, 417}
{789, 57, 684, 741, 128, 794, 542, 367, 937, 739, 568, 872, 127, 261, 103, 763, 864, 360, 618, 307}
{20626770196420, 45538527263992, 52807114957507, 17931716090785, 65032910980630, 88711853198687, 26353250637092,
 61272534748707, 89294362230771, 52058590967576, 60568594469453, 23772707032338, 43019142889727, 39566072849912,
 78870845257173, 68135668032761, 36844201017584, 10133804676521, 6275847412927, 37492167783296}

Returns: 75030497287405

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef map<int, LL> ILLMap;

class SpaceWarDiv1 {

	IntVec g;
	ILLMap e;

	bool can(LL n) {
		int i = 0;
		LLVec t(g.size());
		ILLMap::const_iterator it;
		for (it = e.begin(); it != e.end(); ++it) {
			LL r = it->second;
			while (r > 0) {
				LL c = min(r, n - t[i]);
				if (g[i] < it->first || c <= 0) {
					++i;
					if (i >= (int)g.size()) {
						return false;
					}
					continue;
				}
				r -= c;
				t[i] += c;
			}
		}
		return true;
	}

public:
	long long minimalFatigue(vector <int> magicalGirlStrength, vector <int> enemyStrength, vector<long long> enemyCount) {
		g = magicalGirlStrength;
		sort(g.begin(), g.end());
		e.clear();
		for (int i = 0; i < (int)enemyStrength.size(); ++i) {
			e[enemyStrength[i]] += enemyCount[i];
		}
		LL low = -1, high = 1LL<<62;
		while (low < high) {
			LL mid = (low + high) / 2;
			if (can(mid)) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		return low < (1LL<<62) ? low : -1;
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
			int Arr0[] = {2, 3, 5};
			int Arr1[] = {1, 3, 4};
			long Arr2[] = {2, 9, 4};
			long long Arg3 = 7LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minimalFatigue(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 3, 5};
			int Arr1[] = {1, 1, 2};
			long Arr2[] = {2, 9, 4};
			long long Arg3 = 5LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minimalFatigue(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {14, 6, 22};
			int Arr1[] = {8, 33};
			long Arr2[] = {9, 1};
			long long Arg3 = -1LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minimalFatigue(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {869, 249, 599, 144, 929, 748, 665, 37, 313, 99, 33, 437, 308, 137, 665, 834, 955, 958, 613, 417};
			int Arr1[] = {789, 57, 684, 741, 128, 794, 542, 367, 937, 739, 568, 872, 127, 261, 103, 763, 864, 360, 618, 307};
			LL Arr2[] = {20626770196420, 45538527263992, 52807114957507, 17931716090785, 65032910980630, 88711853198687, 26353250637092,
 61272534748707, 89294362230771, 52058590967576, 60568594469453, 23772707032338, 43019142889727, 39566072849912,
 78870845257173, 68135668032761, 36844201017584, 10133804676521, 6275847412927, 37492167783296};
			long long Arg3 = 75030497287405LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minimalFatigue(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SpaceWarDiv1 ___test;
	___test.run_test(0);
	___test.run_test(-1);
}
// END CUT HERE
