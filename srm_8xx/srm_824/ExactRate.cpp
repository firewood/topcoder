// BEGIN CUT HERE
/*
SRM 824 Div1 Easy (250)

PROBLEM STATEMENT

A high jumper is practicing for the upcoming competition.
She makes a sequence of N jumps.
We will number the jumps from 0 to N-1.
The height of jump i is H[i].
Jump i is a success if H[i] > threshold, and it is a failure otherwise.

You are given ints S and F.
Find the longest contiguous segment of her practice such that within the segment the ratio of successes to failures is exactly S:F.

Find and return {lo, hi} such that H[lo:hi] is the optimal segment. (See Notes if you aren't familiar with the H[lo:hi] notation.)

If there are multiple optimal segments, minimize lo.

In order to keep the input size small, the sequence H is pseudorandom. Follow the pseudocode given below to generate it.

H[0] = (seed * 1103515245 + 12345) modulo 2^31
for i = 1 to N-1:
    H[i] = (H[i-1] * 1103515245 + 12345) modulo 2^31


DEFINITION
Class:ExactRate
Method:getLongest
Parameters:int, int, int, int, int
Returns:vector <int>
Method signature:vector <int> getLongest(int N, int seed, int threshold, int S, int F)


NOTES
-You should return a vector <int> with two elements: element 0 is lo, element 1 is hi. These values must satisfy 0 <= lo <= hi <= N.
-Jump i belongs into the segment H[lo:hi] if and only if lo <= i < hi. Note that jump number hi does not belong into this segment.
-The reference solution does not depend on the input being pseudorandom.


CONSTRAINTS
-N will be between 1 and 500,000, inclusive.
-seed will be between 0 and 2^31 - 1, inclusive.
-threshold will be between 0 and 2^31 - 1, inclusive.
-S will be between 1 and N, inclusive.
-F will be between 1 and N, inclusive.


EXAMPLES

0)
12
47
1012345678
1
2

Returns: {0, 6 }


Sequence of jump heights: H = { 325621308, 263614405, 1041878298, 160854091, 1346820648, 663962433, 1031250150, 1993983527, 507736276, 118477437, 1569514866, 722640323 }.

Jumps 2, 4, 6, 7 and 10 are successes. The other seven jumps are failures.

The longest segment in which there are twice as many failures as successes consists of the first six jumps (0,1,2,3,4,5).


1)
12
47
1012345678
2
1

Returns: {2, 8 }

Same sequence of jumps. Here the longest good segment contains jumps 2,3,4,5,6,7. Out of those, four are successes and two are failures.


2)
12
47
1012345678
7
11

Returns: {0, 0 }

Whenever there is no non-empty segment with the desired ratio, return {0, 0}. This is a description of an empty segment, and among all such descriptions it has the smallest possible value lo.

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

int64_t gcd(int64_t a, int64_t b) { return b ? gcd(b, a % b) : a; }

class ExactRate {
public:
	vector <int> getLongest(int N, int seed, int threshold, int S, int F) {
		int64_t sum = 0, prev = seed, g = gcd(S, F);
		S /= g;
		F /= g;
		vector<map<int64_t, int64_t>> m(S + F);
		m[0][0] = 0;
		vector <int> ans(2);
		for (int i = 0; i < N; ++i) {
			int64_t h = (prev * 1103515245 + 12345) % (1LL << 31);
			prev = h;
			if (h > threshold) {
				sum += F;
			} else {
				sum -= S;
			}
			map<int64_t, int64_t>& values = m[(i + 1) % (S + F)];
			auto it = values.find(sum);
			if (it == values.end()) {
				values[sum] = i + 1;
			} else {
				if ((i + 1 - it->second) > (ans[1] - ans[0])) {
					ans[0] = it->second;
					ans[1] = i + 1;
				}
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 12;
			int Arg1 = 47;
			int Arg2 = 1012345678;
			int Arg3 = 1;
			int Arg4 = 2;
			int Arr5[] = {0, 6 };

			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			verify_case(n, Arg5, getLongest(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 12;
			int Arg1 = 47;
			int Arg2 = 1012345678;
			int Arg3 = 2;
			int Arg4 = 1;
			int Arr5[] = {2, 8 };

			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			verify_case(n, Arg5, getLongest(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 12;
			int Arg1 = 47;
			int Arg2 = 1012345678;
			int Arg3 = 7;
			int Arg4 = 11;
			int Arr5[] = {0, 0 };

			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			verify_case(n, Arg5, getLongest(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arg0 = 493509;
			int Arg1 = 1232685585;
			int Arg2 = 2055120873;
			int Arg3 = 4205;
			int Arg4 = 93670;
			int Arr5[] = { 3098, 474248 };

			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			verify_case(n, Arg5, getLongest(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ExactRate ___test;
	___test.run_test(-1);
}
// END CUT HERE
