// BEGIN CUT HERE
/*
SRM 828 Div1 Medium (450)

PROBLEM STATEMENT

You have a sequence A[0..N-1] of integers, each between 0 and MOD-1, inclusive.

You have to make exactly E edits. In each edit, you have to pick one index into A and replace that value by a new one. The new value must differ from the old one.

(Values have no memory. Thus, it is allowed to change A[2] from 42 to 47 and then in the next edit change A[2] from 47 back to 42. The only requirement is that each edit must change exactly one element of the array.)

You want to perform the E edits in such a way that the final array will contain a contiguous segment of equal values that is as long as possible. 
Return the length of that segment.

In order to keep the input size small, the array A is generated pseudorandomly. Please use the pseudocode below to generate it.

L = length(Aprefix)
for i = 0 to L-1: A[i] = Aprefix[i]

state = seed
for i = L to N-1:
    state = (state * 1103515245 + 12345) modulo 2^31
    A[i] = (state div 16) modulo MOD


DEFINITION
Class:ContiguousConstantSegment
Method:produce
Parameters:int, int, vector <int>, int, int
Returns:int
Method signature:int produce(int N, int MOD, vector <int> Aprefix, int seed, int E)


NOTES
-The reference solution does not depend on the input sequence being (pseudo)random.
-In each edit, the new value may be an arbitrary integer. In particular, the new values may lie outside of the range [0, MOD). See Example 3.


CONSTRAINTS
-N will be between 1 and 250,000, inclusive.
-MOD will be between 1 and 250,000, inclusive.
-Aprefix will have between 1 and min(100,N) elements, inclusive.
-Each element of Aprefix will be between 0 and MOD-1, inclusive.
-seed will be between 0 and 2^31 - 1, inclusive.
-E will be between 0 and 250,000, inclusive.


EXAMPLES

0)
9
10
{1, 2, 3, 2, 4, 5, 2, 2, 6}
47
0

Returns: 2

As N = length(Aprefix), we are already given the full sequence: A = {1, 2, 3, 2, 4, 5, 2, 2, 6}.

We cannot make any edits. The longest contiguous segment of equal values are the two consecutive 2s at 0-based indices 6 and 7.

1)
9
10
{1, 2, 3, 2, 4, 5, 2, 2, 6}
34424
1

Returns: 3

The same sequence as before but now we have to make exactly one edit. There are three optimal ways to do so: we can change any one of the values A[2], A[5] and A[8] to 2. In each of those cases we will obtain three consecutive 2s, so the correct return value is 3.


2)
9
10
{1, 2, 3, 2, 4, 5, 2, 2, 6}
366122
2

Returns: 5

For the same sequence, if we are allowed two edits, the best solution is now unique (up to the order in which we make the edits): we should change A[4] and A[5] to 2. This produces a contiguous segment of 5 equal values.


3)
4700
1
{0}
123
16

Returns: 4700

We start with a sequence of 4700 zeros. One optimal way of making the 16 edits is to alternately change A[1234] to 5678 and then back to 0. We will end with a sequence of 4700 zeros again.


4)
20
100
{0, 42, 47}
123
6

Returns: 8

Your array A should look as follows: A = { 0, 42, 47, 53, 39, 61, 9, 28, 54, 78, 71, 7, 70, 14, 84, 53, 30, 71, 34, 96 }.
Six edits are just enough to create a contiguous segment of eight equal elements with value 71.

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

class ContiguousConstantSegment {
public:
	int produce(int N, int MOD, vector <int> Aprefix, int seed, int E) {
		int64_t state = seed;
		vector<int> A = Aprefix;
		for (int i = Aprefix.size(); i < N; ++i) {
			state = (state * 1103515245 + 12345) % (1LL << 31);
			A.emplace_back((state / 16) % MOD);
		}

		map<int, vector<int>> m;
		for (int i = 0; i < N; ++i) {
			m[A[i]].emplace_back(i);
		}
		if (m.size() == 1) {
			return max(1, N - (E == 1));
		}

		int ans = min(N, E + 1);
		for (auto kv : m) {
			const vector<int>& v = kv.second;
			int sz = (int)v.size();
			int left = 0;
			for (int i = 1; i < sz; ++i) {
				while (left < i) {
					int c = i - left + 1;
					int diff = v[i] - v[left] + 1;
					if (diff - c <= E) {
						ans = max(ans, min(N, c + E));
						break;
					}
					++left;
				}
			}
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
			int Arg0 = 9;
			int Arg1 = 10;
			int Arr2[] = {1, 2, 3, 2, 4, 5, 2, 2, 6};
			int Arg3 = 47;
			int Arg4 = 0;
			int Arg5 = 2;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg5, produce(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arg1 = 10;
			int Arr2[] = {1, 2, 3, 2, 4, 5, 2, 2, 6};
			int Arg3 = 34424;
			int Arg4 = 1;
			int Arg5 = 3;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg5, produce(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arg1 = 10;
			int Arr2[] = {1, 2, 3, 2, 4, 5, 2, 2, 6};
			int Arg3 = 366122;
			int Arg4 = 2;
			int Arg5 = 5;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg5, produce(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4700;
			int Arg1 = 1;
			int Arr2[] = {0};
			int Arg3 = 123;
			int Arg4 = 16;
			int Arg5 = 4700;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg5, produce(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arg1 = 100;
			int Arr2[] = {0, 42, 47};
			int Arg3 = 123;
			int Arg4 = 6;
			int Arg5 = 8;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg5, produce(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;




		if ((Case == -1) || (Case == n)) {
			int Arg0 = 5;
			int Arg1 = 10;
			int Arr2[] = { 2, 2, 2, 2, 2 };
			int Arg3 = 999;
			int Arg4 = 1;
			int Arg5 = 4;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg5, produce(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 5;
			int Arg1 = 10;
			int Arr2[] = { 2, 1, 2, 1, 2 };
			int Arg3 = 999;
			int Arg4 = 2;
			int Arg5 = 5;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg5, produce(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 5;
			int Arg1 = 10;
			int Arr2[] = { 1, 1, 1, 2, 2 };
			int Arg3 = 999;
			int Arg4 = 4;
			int Arg5 = 5;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg5, produce(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 9;
			int Arg1 = 10;
			int Arr2[] = { 1,2,3,2,4,5,2,2,6 };
			int Arg3 = 47;
			int Arg4 = 250000;
			int Arg5 = 9;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg5, produce(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ContiguousConstantSegment ___test;
	___test.run_test(-1);
}
// END CUT HERE
