// BEGIN CUT HERE
/*
SRM 658 Div2 Medium (500)

PROBLEM STATEMENT
Fox Ciel is writing an AI for the game Starcraft and she needs your help.

In Starcraft, one of the available units is a mutalisk.
Mutalisks are very useful for harassing Terran bases.
Fox Ciel has one mutalisk.
The enemy base contains one or more Space Construction Vehicles (SCVs).
Each SCV has some amount of hit points.

When the mutalisk attacks, it can target up to three different SCVs.

The first targeted SCV will lose 9 hit points.
The second targeted SCV (if any) will lose 3 hit points.
The third targeted SCV (if any) will lose 1 hit point.

If the hit points of a SCV drop to 0 or lower, the SCV is destroyed.
Note that you may not target the same SCV twice in the same attack.

You are given a vector <int> HP containing the current hit points of your enemy's SCVs.
Return the smallest number of attacks in which you can destroy all these SCVs.


DEFINITION
Class:MutaliskEasy
Method:minimalAttacks
Parameters:vector <int>
Returns:int
Method signature:int minimalAttacks(vector <int> x)


CONSTRAINTS
-x will contain between 1 and 3 elements, inclusive.
-Each element in x will be between 1 and 60, inclusive.


EXAMPLES

0)
{12,10,4}

Returns: 2

You can destroy all SCVs in two attacks as follows:

Target the SCVs in the order 0, 2, 1. Their hit points after the attack will be {12-9, 10-1, 4-3} = {3, 9, 1}.
Target the SCVs in the order 1, 0, 2. Their hit points will drop exactly to {0, 0, 0}.


1)
{54,18,6}

Returns: 6

You should attack 6 times, always in the order 0, 1, 2.


2)
{55,60,53}

Returns: 13


3)
{1,1,1}

Returns: 1


4)
{60, 40}

Returns: 9


5)
{60}

Returns: 7

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<int, pair<int, int> > III;
typedef map<III, int> IIIMap;

class MutaliskEasy {

	IIIMap memo;

	int find(vector <int> &x) {
		sort(x.begin(), x.end());
		if (x[2] <= 0) {
			return 0;
		}
		III key(make_pair(x[0], make_pair(x[1], x[2])));
		if (memo.find(key) != memo.end()) {
			return memo[key];
		}
		vector <int> a = { max(0, x[0] - 1), max(0, x[1] - 3), max(0, x[2] - 9) };
		vector <int> b = { max(0, x[0] - 1), max(0, x[2] - 3), max(0, x[1] - 9) };
		vector <int> c = { max(0, x[1] - 1), max(0, x[0] - 3), max(0, x[2] - 9) };
		return memo[key] = min(min(find(a), find(b)), find(c)) + 1;
	}

public:
	int minimalAttacks(vector <int> x) {
		while (x.size() < 3) {
			x.push_back(0);
		}
		return find(x);
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
			int Arr0[] = {12,10,4};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalAttacks(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {54,18,6};
			int Arg1 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalAttacks(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {55,60,53};
			int Arg1 = 13;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalAttacks(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalAttacks(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {60, 40};
			int Arg1 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalAttacks(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {60};
			int Arg1 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalAttacks(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 6, 9, 9 };
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalAttacks(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MutaliskEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
