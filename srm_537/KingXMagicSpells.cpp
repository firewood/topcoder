// BEGIN CUT HERE
/*
// SRM 537 Div1 Medium (500)

// PROBLEM STATEMENT
// Warning: This problem statement contains superscripts and/or subscripts.
It may not display properly outside of the applet.

King Dengklek is the perfect king of Kingdom of Ducks, where slimes and ducks
live together in peace and harmony.

The palace has N rooms, conveniently numbered 0 through N-1. The rooms are
occupied by the ducks King Dengklek loves the most. There are ducks[i] ducks
in room i.

Today, King Dengklek realized that two magic spells are affecting the palace.
Being a perfect king, he quickly learned that on each day, exactly one of the
two magic spells will take place with the same probability (i.e., 50%).
The effects of the two magic spells are as follows:

Spell 1: For each i, let D be the number of ducks in room i right before the
         spell's effect takes place. The number of ducks in room i will become
		 D XOR spellOne[i] (see the Notes section for the definition of XOR).
Spell 2: For each i, all ducks in room i will move to room spellTwo[i]. All
         these movements will happen simultaneously. This will permute the
		 ducks (i.e., no two elements of spellTwo will be equal).

King Dengklek is worried about these odd magic spells. He is especially
worried about room 0, because he has promised that he will grant all ducks
in this room to his successor.
You are given the vector <int>s ducks, spellOne, spellTwo, and the int K.
Return the expected number of ducks in room 0 after the magic spells have
affected the palace for K days.

DEFINITION
Class:KingXMagicSpells
Method:expectedNumber
Parameters:vector <int>, vector <int>, vector <int>, int
Returns:double
Method signature:double expectedNumber(vector <int> ducks, vector <int> spellOne, vector <int> spellTwo, int K)


NOTES
-The returned value must have an absolute or relative error less than 10-9.
-If a and b are single bits then a XOR b is defined as (a + b) modulo 2.
For two integers, A and B, in order to calculate A XOR B, they need to be
represented in binary: A = (an...a1)2, B = (bn...b1)2 (if the lengths of their
representations are different, the shorter one is prepended with the necessary
number of leading zeroes). Then A XOR B = C = (cn...c1)2, where ci = ai XOR bi.
For example, 10 XOR 3 = (1010)2 XOR (0011)2 = (1001)2 = 9.


CONSTRAINTS
-ducks, spellOne, and spellTwo will contain the same number of elements, between 1 and 50, inclusive.
-Each element of ducks will be between 0 and 1,000,000,000, inclusive.
-Each element of spellOne will be between 0 and 1,000,000,000, inclusive.
-Each element of spellTwo will be between 0 and N-1, inclusive, where N is the number of elements in ducks.
-All elements of spellTwo will be distinct.
-K will be between 1 and 50, inclusive.


EXAMPLES

0)
{5, 3, 7}
{1, 7, 4}
{1, 0, 2}
1

Returns: 3.5

We want to know the expected number of ducks in room 0 after K=1 day. Exactly one spell will take place. Depending on which spell takes place, there are two possible outcomes:

Spell 1: The numbers of ducks in the rooms become {5 XOR 1, 3 XOR 7, 7 XOR 4} = {4, 4, 3}.
Spell 2: The numbers of ducks in the rooms become {3, 5, 7}.

Therefore, the expected number of ducks in room 0 is (4 + 3)/2 = 3.5.


1)
{5, 8}
{53, 7}
{1, 0}
2

Returns: 21.5

There are four possible outcomes, depending on which two spells take place:

Spell 1 and then spell 1: {48, 15} and then {5, 8}.
Spell 1 and then spell 2: {48, 15} and then {15, 48}.
Spell 2 and then spell 1: {8, 5} and then {61, 2}.
Spell 2 and then spell 2: {8, 5} and then {5, 8}.

Therefore, the expected number of ducks in room 0 is (5 + 15 + 61 + 5)/4 = 21.5.


2)
{123, 456, 789, 1234, 56789}
{0, 0, 0, 0, 0}
{0, 1, 2, 3, 4}
50

Returns: 123.0

In this case, the number of ducks in each room will never change.


3)
{83291232, 3124231, 192412, 3813249, 629231, 9998989}
{58, 37, 44, 66, 72, 19}
{2, 0, 1, 5, 4, 3}
11

Returns: 2.888186784716797E7

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

typedef vector<int> IntVec;
typedef vector<double> DoubleVec;
typedef vector<DoubleVec> DVV;

class KingXMagicSpells {

public:
	double expectedNumber(vector <int> ducks, vector <int> spellOne, vector <int> spellTwo, int K) {
		int c = ducks.size();
		DVV v(c);
		int i, j;
		for (i = 0; i < c; ++i) {
			v[i].resize(30);
		}
		for (i = 0; i < c; ++i) {
			for (j = 0; j < 30; ++j) {
				if (ducks[i] & (1 << j)) {
					v[i][j] = 1.0;
				}
			}
		}

		int day;
		for (day = 0; day < K; ++day) {
			DVV next(c);

			for (i = 0; i < c; ++i) {
				const DoubleVec &src = v[i];
				next[spellTwo[i]] = src;
			}

			for (i = 0; i < c; ++i) {
				const DoubleVec &x = v[i];
				DoubleVec &y = next[i];
				int one = spellOne[i];
				for (j = 0; j < 30; ++j) {
					double n = x[j];
					if (one & (1 << j)) {
						n = 1.0 - n;
					}
					y[j] = 0.5 * (y[j] + n);
				}
			}

			v = next;
		}

		double res = 0;
		for (j = 0; j < 30; ++j) {
			double d = 1 << j;
			res += d * v[0][j];
		}
		return res;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 3, 7};
			int Arr1[] = {1, 7, 4};
			int Arr2[] = {1, 0, 2};
			int Arg3 = 1;
			double Arg4 = 3.5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, expectedNumber(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 8};
			int Arr1[] = {53, 7};
			int Arr2[] = {1, 0};
			int Arg3 = 2;
			double Arg4 = 21.5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, expectedNumber(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {123, 456, 789, 1234, 56789};
			int Arr1[] = {0, 0, 0, 0, 0};
			int Arr2[] = {0, 1, 2, 3, 4};
			int Arg3 = 50;
			double Arg4 = 123.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, expectedNumber(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {83291232, 3124231, 192412, 3813249, 629231, 9998989};
			int Arr1[] = {58, 37, 44, 66, 72, 19};
			int Arr2[] = {2, 0, 1, 5, 4, 3};
			int Arg3 = 11;
			double Arg4 = 2.888186784716797E7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, expectedNumber(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	KingXMagicSpells ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
