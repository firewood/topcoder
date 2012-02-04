// BEGIN CUT HERE
/*
// SRM 530 Div2 Hard (1000)

// PROBLEM STATEMENT
// Like all other software engineers, Gogo likes to "read" virtual novels.
In particular, he's currently "reading" a novel titled Touhou, with Reimu Hakurai
as its main protagonist. There are N stages in Touhou, numbered 0 through N-1.
A playthrough of the novel always starts at the stage 0. The playthrough
then may visit some other stages, based on the player's choices. The sequence
of visited stages is always strictly ascending. A playthrough is successful
if it terminates by reaching the stage N-1.

In each stage, Gogo can either finish the playthrough or choose one of the
available options that advance Reimu to other stages. You are given
a vector <string> choices. If there is a choice that advances Reimu
from stage i to stage j, choices[i][j] will be 'Y', otherwise it will be 'N'.
For each pair of stages i, j such that i < j the game contains at most one such choice.

Gogo wants to make as many successful playthroughs as possible, one after another.
However, there is an additional constraint: Each playthrough must contain
at least one choice Gogo never made in any of the previous playthroughs.

Return the maximum number of successful playthroughs that Gogo can play.
If there are no such playthrough, return 0.

DEFINITION
Class:GogoXReimuHakurai
Method:solve
Parameters:vector <string>
Returns:int
Method signature:int solve(vector <string> choices)


CONSTRAINTS
-choices will contain between 2 and 50 elements, inclusive.
-Each element of choices will contain N characters, where N is the number of elements in choices.
-Each character in choices will be either 'Y', or 'N'.
-If i >= j then choices[i][j] will be 'N'.


EXAMPLES

0)
{
"NYY",
"NNY",
"NNN"}

Returns: 2

The two possible successful playthroughs:
0 -> 1 -> 2
0 -> 2
Gogo may play them both, in any order.

1)
{
"NYNY",
"NNYY",
"NNNY",
"NNNN"}

Returns: 3



2)
{"NNY"
,"NNY"
,"NNN"}

Returns: 1



3)
{"NN"
,"NN"}

Returns: 0

*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>
#include <algorithm>
#include <numeric>
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
typedef vector<string> StrVec;

class GogoXReimuHakurai {

public:
	int solve(vector <string> choices) {
		int len = choices.size();
		IntVec f(len, 0);
		IntVec dp(len, 0);
		f[len -1] = 1;
		int i, j;
		for (i = len - 1; i >= 0; --i) {
			for (j = i; j < len; ++j) {
				if (choices[i][j] == 'Y' && f[j]) {
					f[i] = 1;
				}
			}
		}
		dp[0] = f[0];
		for (i = 0; i < len; ++i) {
			for (j = i+1; j < len; ++j) {
				if (choices[i][j] == 'Y' && f[j]) {
					dp[j] += dp[i];
					dp[i] = dp[i] > 0;
				}
			}
		}
		return dp[len-1];
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
			string Arr0[] = {
"NYY",
"NNY",
"NNN"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"NYNY",
"NNYY",
"NNNY",
"NNNN"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNY"
,"NNY"
,"NNN"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NN"
,"NN"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;


		// system test case 3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYYYY", "NNYYY", "NNNYY", "NNNNY", "NNNNN"};
			int Arg1 = 7;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// system test case x
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYNYYYYNYY", "NNNYYYYNYY", "NNNYNNYYNN", "NNNNYYYNYY", "NNNNNYNNNN", "NNNNNNNNYN", "NNNNNNNNYY", "NNNNNNNNNY", "NNNNNNNNNN", "NNNNNNNNNN"};
			int Arg1 = 7;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GogoXReimuHakurai ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
