// BEGIN CUT HERE
/*
SRM 809 Div1 Easy (250)

PROBLEM STATEMENT

N kids are waiting in the line for lunch. The kids are numbered from 0 to N-1 in the order in which they are currently standing, with kid 0 being the one who would get lunch first.

The lunch lady hasn't started giving out lunch yet, and the kids are restless.
However, each time someone misbehaves, Mrs. Trunchbull (the teacher in charge of the dining hall today) sends them to the very end of the line as a punishment.

You are given N and a sequence of M events. 
Events are numbered from 0 to M-1 in chronological order.
In event i kid number K[i] is sent to the end of the line.

Compute the sequence F[0], ..., F[N-1] of numbers the kids in the queue have at the end.
Return the value sum( i*F[i] ).

In order to keep the input size small, the sequence K of kids sent back is pseudorandom.
Please use the following code to generate it:

if M > 0: K[0] = A
if M > 1: K[1] = B
for i = 2 to M-1: K[i] = (C*K[i-1] + D*K[i-2] + E) mod N


DEFINITION
Class:LunchLine
Method:simulate
Parameters:int, int, int, int, int, int, int
Returns:long long
Method signature:long long simulate(int N, int M, int A, int B, int C, int D, int E)


NOTES
-Watch out for integer overflows when generating K: 64-bit integers are needed for the intermediate values.


CONSTRAINTS
-N will be between 1 and 250,000, inclusive.
-M will be between 0 and 100,000, inclusive.
-A, B, C, D, E will be between 0 and N-1, inclusive.


EXAMPLES

0)
250000
0
0
0
0
0
0

Returns: 5208302083375000

Nobody gets sent back, so the kids are still in the order 0, 1, 2, ... and the return value is sum(i^2) where i goes from 0 to N-1, inclusive.


1)
10
5
2
3
1
0
1

Returns: 225

The sequence of kids sent back is {2, 3, 4, 5, 6}. Thus, in the end the line looks as follows: {0, 1, 7, 8, 9, 2, 3, 4, 5, 6}.


2)
10
5
2
4
1
0
2

Returns: 210

Kids sent back: {2, 4, 6, 8, 0}. Final line: {1, 3, 5, 7, 9, 2, 4, 6, 8, 0}.


3)
10
100000
4
7
0
0
3

Returns: 249

Kids sent back: {4, 7, 3, 3, 3, ...}. Final line: {0, 1, 2, 5, 6, 8, 9, 4, 7, 3}.


4)
11
30
4
7
1
2
3

Returns: 229

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

class LunchLine {
public:

	long long simulate(int N, int M, int A, int B, int C, int D, int E) {
		vector<LL> K;
		K.emplace_back(A);
		K.emplace_back(B);
		for (int i = 2; i < M; ++i) {
			K.emplace_back((C * K[i - 1] + D * K[i - 2] + E) % N);
		}
		vector<LL> pos(N);
		iota(pos.begin(), pos.end(), 0);
		vector<LL> order = pos;
		for (int i = 0; i < M; ++i) {
			pos[K[i]] = order.size();
			order.emplace_back(K[i]);
		}
		LL ans = 0, count = 0;
		for (int i = 0; i < order.size(); ++i) {
			if (pos[order[i]] == i) {
				ans += count++ * order[i];
			}
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
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 250000;
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 0;
			int Arg4 = 0;
			int Arg5 = 0;
			int Arg6 = 0;
			long long Arg7 = 5208302083375000LL;

			verify_case(n, Arg7, simulate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 10;
			int Arg1 = 5;
			int Arg2 = 2;
			int Arg3 = 3;
			int Arg4 = 1;
			int Arg5 = 0;
			int Arg6 = 1;
			long long Arg7 = 225LL;

			verify_case(n, Arg7, simulate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 10;
			int Arg1 = 5;
			int Arg2 = 2;
			int Arg3 = 4;
			int Arg4 = 1;
			int Arg5 = 0;
			int Arg6 = 2;
			long long Arg7 = 210LL;

			verify_case(n, Arg7, simulate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 10;
			int Arg1 = 100000;
			int Arg2 = 4;
			int Arg3 = 7;
			int Arg4 = 0;
			int Arg5 = 0;
			int Arg6 = 3;
			long long Arg7 = 249LL;

			verify_case(n, Arg7, simulate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 11;
			int Arg1 = 30;
			int Arg2 = 4;
			int Arg3 = 7;
			int Arg4 = 1;
			int Arg5 = 2;
			int Arg6 = 3;
			long long Arg7 = 229LL;

			verify_case(n, Arg7, simulate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6));
		}
		n++;
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LunchLine ___test;
	___test.run_test(-1);
}
// END CUT HERE
