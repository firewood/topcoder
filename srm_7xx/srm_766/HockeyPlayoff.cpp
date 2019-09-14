// BEGIN CUT HERE
/*
SRM 766 Div1 Easy (250)

PROBLEM STATEMENT

An ice hockey playoff final is played as a sequence of matches.
The winner is the first team that wins winsNeeded of those matches.

Teams A and B are facing off in such a final.
The home ice alternates every two matches.
That is, A plays the first two matches on their home ice, B plays matches 3 and 4 on their home ice, A plays matches 5 and 6 at home, and so on.

It is known that home and away games are completely different. In this matchup, we know the following about a single independent game between A and B:

If A plays at home ice, they win with probability AwinHome percent.
If B plays at home ice, they win with probability BwinHome percent.

There is a reason why we emphasized the words "single independent game" in the previous paragraph.
In a playoff series there is one more factor that influences the win probability of each team: momentum.
The team that keeps winning has a morale boost that makes it more likely that they will win the next match.
In this problem, momentum works as follows:
if a team has a streak of W won matches in a row, their win probability for the next match is increased by 5*W percent (up to a maximum of 100 percent, of course).

For example, if A won the first game of the series and B won the next three, in game five B has a 5*3 = 15 percent boost due to momentum.

You are given winsNeeded, AwinHome and BwinHome.
Let P be the probability that team A will win the whole series.
Let M = 2*winsNeeded-1 be the maximum number of matches in the series.
It can be shown that X = P * 100^M is an integer.
Compute and return the value (X modulo (10^9 + 7)).


DEFINITION
Class:HockeyPlayoff
Method:winProbability
Parameters:int, int, int
Returns:int
Method signature:int winProbability(int winsNeeded, int AwinHome, int BwinHome)


CONSTRAINTS
-winsNeeded will be between 1 and 600, inclusive.
-AwinHome will be between 0 and 100, inclusive.
-BwinHome will be between 0 and 100, inclusive.


EXAMPLES

0)
3
0
100

Returns: 0

The first one to three wins will win the series. Team A is completely hopeless and always loses, so B will win this series 3:0.


1)
4
100
0

Returns: 999300007

The diametrally opposite situation to Example 0. The answer is 100^7 modulo (10^9 + 7).


2)
600
50
50

Returns: 594375906

A perfectly symmetric situation. The answer is (0.5 * 100^1199) modulo (10^9 + 7).


3)
4
53
57

Returns: 942200194


4)
7
93
87

Returns: 545426737

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;
static const LL MOD = 1000000007LL;

struct modll {
	long long x;
	modll() { }
	modll(long long _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(const modll& r) { return (x + r.x) % MOD; }
	modll operator+=(const modll& r) { return x = (x + r.x) % MOD; }
	modll operator-(const modll& r) { return (x + MOD - r.x) % MOD; }
	modll operator-=(const modll& r) { return x = (x + MOD - r.x) % MOD; }
	modll operator*(const modll& r) { return (x * r.x) % MOD; }
	modll operator*(int r) { return (x * r) % MOD; }
	modll operator*=(const modll& r) { return x = (x * r.x) % MOD; }
	static modll modinv(int a) { return modpow(a, MOD - 2); }
	static modll modpow(int a, int b) {
		modll x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

class HockeyPlayoff {
	modll dp[2][2][602][22];

public:
	int winProbability(int winsNeeded, int AwinHome, int BwinHome) {
		memset(dp, 0, sizeof(dp));
		LL wr[4] = { AwinHome, AwinHome, 100 - BwinHome, 100 - BwinHome };
		dp[0][0][1][1] = wr[0];
		dp[0][1][0][1] = 100 - wr[0];
		for (int t = 1; t < winsNeeded * 2 - 1; ++t) {
			int curr = t & 1, prev = curr ^ 1;
			memset(dp[curr], 0, sizeof(dp[0]));
			for (int i = 0; i <= winsNeeded; ++i) {
				LL awr = wr[t & 3];
				LL bwr = 100 - awr;
				for (int j = 1; j <= 20; ++j) {
					awr = min(100LL, awr + 5);
					bwr = min(100LL, bwr + 5);
					dp[curr][0][min(winsNeeded, i + 1)][min(20, j + 1)] += awr * dp[prev][0][i][j];
					dp[curr][1][i][1] += (100 - awr) * dp[prev][0][i][j];
					dp[curr][1][i][min(20, j + 1)] += bwr * dp[prev][1][i][j];
					dp[curr][0][min(winsNeeded, i + 1)][1] += (100 - bwr) * dp[prev][1][i][j];
				}
			}
		}
		modll ans = 0;
		for (int j = 1; j <= 20; ++j) {
			ans += dp[0][0][winsNeeded][j];
			ans += dp[0][1][winsNeeded][j];
		}
		return ans;
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
			int Arg0 = 3;
			int Arg1 = 0;
			int Arg2 = 100;
			int Arg3 = 0;

			verify_case(n, Arg3, winProbability(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 100;
			int Arg2 = 0;
			int Arg3 = 999300007;

			verify_case(n, Arg3, winProbability(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 600;
			int Arg1 = 50;
			int Arg2 = 50;
			int Arg3 = 594375906;

			verify_case(n, Arg3, winProbability(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 53;
			int Arg2 = 57;
			int Arg3 = 942200194;

			verify_case(n, Arg3, winProbability(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 93;
			int Arg2 = 87;
			int Arg3 = 545426737;

			verify_case(n, Arg3, winProbability(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 2;
			int Arg1 = 1;
			int Arg2 = 99;
			int Arg3 = 600;

			verify_case(n, Arg3, winProbability(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	HockeyPlayoff ___test;
	___test.run_test(-1);
}
// END CUT HERE
