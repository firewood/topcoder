// BEGIN CUT HERE
/*
SRM 839 Div2 Hard (1000)

PROBLEM STATEMENT

You are hosting a party.

Each of your friends is willing to bring you some number of candies if you invite them to the party.
These numbers of candies are given in the vector <int> candies.

You can invite an arbitrary subset of these friends to your party.
Once all the invited guests arrive, you are going to collect all the candies they brought and then divide them among everyone at the party (including yourself).
The party is perfect if it's possible to divide the candies evenly, i.e., with no remainder.

Return the number of ways in which you can have a perfect party. (Two ways differ iff the set of participants differs.)


DEFINITION
Class:PerfectParty
Method:invite
Parameters:vector <int>
Returns:long long
Method signature:long long invite(vector <int> candies)


CONSTRAINTS
-candies will have between 1 and 50 elements, inclusive.
-Each element of candies will be between 0 and 2,500, inclusive.


EXAMPLES

0)
{0, 0, 0, 0}

Returns: 16

Nobody is willing to bring any candies. On one hand that means that everyone at the party will be hungry, but on the other hand you can invite any subset of your friends (including none of them or all of them) and the party will be perfect: you can divide 0 candies evenly among any number of participants.


1)
{1, 1, 1, 1, 1, 1, 1, 1}

Returns: 1

Regardless of how many friends you invite, you'll always have one fewer candies than participants and so the party will never be perfect - except for one case. If you don't invite anyone, you will be alone with no candies. That is clearly a perfect party. (In real life opinions may differ, but in our problem a perfect party has an exact definition.)


2)
{0, 0, 0, 0, 125}

Returns: 20

Let's call the last friend (the one willing to bring 125 candies) Peter. There are 2^4 = 16 ways to have a perfect party without Peter. If we do invite Peter, the party will be perfect if and only if the total number of participants is exactly 5. There are four distinct ways to do this: you need to choose one of the four other friends who won't get invited.


3)
{1, 2, 3, 4, 5, 6, 7}

Returns: 31

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

typedef long long LL;

class PerfectParty {
public:
	long long invite(vector <int> candies) {
		LL N = candies.size(), ans = 0;
		for (int num = 1; num <= N + 1; ++num) {
			vector<vector<LL>> dp(num, vector<LL>(num));
			dp[0][0] = 1;
			for (int i = 0; i < N; ++i) {
				vector<vector<LL>> prev = dp;
				for (int j = 0; j <= i && j < num - 1; ++j) {
					for (int k = 0; k < num; ++k) {
						dp[j + 1][(k + candies[i]) % num] += prev[j][k];
					}
				}
			}
			ans += dp[num - 1][0];
		}
		return ans;
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
			int Arr0[] = {0, 0, 0, 0};
			long long Arg1 = 16LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, invite(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1};
			long long Arg1 = 1LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, invite(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0, 0, 125};
			long long Arg1 = 20LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, invite(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4, 5, 6, 7};
			long long Arg1 = 31LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, invite(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840, 840 };
			long long Arg1 = 367245340781671LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, invite(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 2368, 1571, 2082, 2212, 1035, 397, 929, 1371, 895, 1929, 451, 1706, 2476, 1446, 1172, 978, 2274, 1071, 1462, 2181, 2315, 164, 1982, 1278, 2304, 1619, 1065, 2127, 904, 2483, 466, 848, 1555, 1988, 1036, 2472, 2285, 611, 1818, 62, 697, 2240, 339, 305, 1088, 2094, 2239 };
			long long Arg1 = 5864061984249LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, invite(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PerfectParty ___test;
	___test.run_test(-1);
}
// END CUT HERE
