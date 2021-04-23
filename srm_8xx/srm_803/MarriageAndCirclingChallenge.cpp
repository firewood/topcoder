// BEGIN CUT HERE
/*
SRM 803 Div1 Easy (250)

PROBLEM STATEMENT

One of the challenges  before  marriage (yes, this problem is a bit different from the others in that regard!) is circling.
By circling, we mean love circles.
The ideal situation in love is when A loves B and B loves A back, as then A and B can get married and be happy together.
However, in real life you can get much more complicated situations such as "A loves B, B loves C, C loves D, ..., and X loves A".
We will take a closer look at those situations.

Imagine a society in which no ideal love circles exist, for a very simple reason:
for any two people A, B in the society either A loves B, or B loves A, but never both.

We are examining one such society.
We are currently interested in situations that are in some sense closest to the ideal one: love circles that involve exactly four people.
That is, we are interested in four-tuples (A, B, C, D) of distinct people such that A loves B, B loves C, C loves D, and finally D loves A.
The cyclic order does not matter, so (B, C, D, A) is the same four-tuple as (A, B, C, D).

You are given N, threshold and state.
The society we are examining consists of N people, numbered from 0 to N-1.
Use the following simple pseudocode to generate the relationships between them.

def rnd():
	state = (state * 1103515245 + 12345) modulo 2^31
	return state modulo 100

for i = 0 to N-1:
	for j = i+1 to N-1:
		if rnd() < threshold:
			i loves j
		else:
			j loves i


DEFINITION
Class:MarriageAndCirclingChallenge
Method:solve
Parameters:int, int, int
Returns:long long
Method signature:long long solve(int N, int threshold, int state)


CONSTRAINTS
-N will be between 4 and 600, inclusive.
-threshold will be between 0 and 100, inclusive.
-state will be between 0 and 2^31 - 1, inclusive.


EXAMPLES

0)
10
0
12345

Returns: 0

In this society the test rnd() < threshold never returns true and therefore the person with the higher number always loves the person with the smaller number. In such a society there clearly are no love circles at all, regardless of their length.


1)
5
50
47

Returns: 4


The values returned by rnd() when generating this society are:
8
(0 loves 1),
5
(0 loves 2),
98
(3 loves 0),
91
(4 loves 0),
48
(1 loves 2),
33
(1 loves 3),
50
(4 loves 1),
27
(2 loves 3),
76
(4 loves 2),
37
(3 loves 4).

The four love circles of length four in this society are (0, 1, 2, 3), (0, 1, 3, 4), (1, 2, 3, 4), and (3, 4, 0, 2).


2)
9
20
1234567

Returns: 29

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>
#include <bitset>

using namespace std;

class MarriageAndCirclingChallenge {
	unsigned long long _state;
	int rnd() {
		_state = (_state * 1103515245 + 12345) % (1LL << 31);
		return _state % 100;
	}

public:
	long long solve(int N, int threshold, int state) {
		_state = state;
		vector<bitset<600>> in(600), out(600);
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				if (rnd() < threshold) {
					in[j][i] = 1;
					out[i][j] = 1;
				} else {
					in[i][j] = 1;
					out[j][i] = 1;
				}
			}
		}
		vector<vector<int>> dp(600, vector<int>(600, 0));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (i == j) continue;
				dp[i][j] = (out[j] & in[i]).count();
			}
		}
		long long ans = 0;
		for (int i = 0; i < N; ++i) {
			vector<long long> left, right;
			for (int j = 0; j < N; ++j) {
				if (i == j) continue;
				if (out[i][j]) {
					right.push_back(j);
				} else {
					left.push_back(j);
				}
			}
			for (auto x : left) {
				for (auto y : right) {
					ans += dp[x][y];
				}
			}
		}
		return ans / 4;
	}

	// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T>& V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long& Expected, const long long& Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) {
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 10;
			int Arg1 = 0;
			int Arg2 = 12345;
			long long Arg3 = 0LL;

			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 5;
			int Arg1 = 50;
			int Arg2 = 47;
			long long Arg3 = 4LL;

			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 9;
			int Arg1 = 20;
			int Arg2 = 1234567;
			long long Arg3 = 29LL;

			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 600;
			int Arg1 = 50;
			int Arg2 = 1;
			long long Arg3 = 2005187214LL;

			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;


	}

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MarriageAndCirclingChallenge ___test;
	___test.run_test(-1);
}
// END CUT HERE
