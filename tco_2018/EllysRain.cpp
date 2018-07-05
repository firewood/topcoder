// BEGIN CUT HERE
/*
TCC India 2018 Qualification Round Hard (1000)

PROBLEM STATEMENT

Elly has a beautiful flowerpot with roses on her window sill. Whenever it rains outside, Elly remembers that she hasn't watered her roses in a while. However, now that it rains, maybe the rain will water them for her! To make sure the roses get watered properly, Elly watches the whole situation carefully and records where the individual raindrops fall.

For simplicity, we will consider the flowerpot to be a closed line segment of length L. (One endpoint of the segment has coordinate 0, the other has coordinate L, and both endpoints belong to the segment.) 
Each raindrop will fall onto some point of this segment.
The coordinate of each raindrop will be an integer.

The flowerpot is considered properly watered if each possible closed interval of length D or more already received at least one raindrop. Note that this includes intervals that start and end at non-integer coordinates.

You are given the ints L and D.
You are also given four other ints: N, P1, M, and A.
These describe the rainfall.
N drops fell onto our line segment. (The drops fell sequentially, i.e., one at a time.)
The first raindrop landed on coordinate P1.
For each of the following raindrops you can compute the coordinate where it dropped as follows:
Let P_prev be the coordinate of the previous raindrop.
Then the coordinate of the current raindrop is (P_prev * M + A) modulo (L + 1).

Find and return the smallest K such that Elly's flowerpot was properly watered after the first K raindrops.
If the entire rainfall was not enough to water the flowerpot properly, return -1 instead.


DEFINITION
Class:EllysRain
Method:getTime
Parameters:int, int, int, int, int, int
Returns:int
Method signature:int getTime(int L, int D, int N, int P1, int M, int A)


CONSTRAINTS
-L will be between 2 and 1,000,000,000, inclusive.
-D will be between 1 and L-1, inclusive.
-N will be between 1 and 1,000,000, inclusive.
-P1, M, and A will each be between 0 and L, inclusive.


EXAMPLES

0)
23
7
12
14
13
5

Returns: 9

We have a flowerpot of length L = 23, and we are waiting until each closed interval of length D = 7 or more gets hit by a raindrop.

There are N = 12 raindrops. Using the formula from the problem statement we can compute that their coordinates are 14, 19, 12, 17, 10, 15, 8, 13, 6, 11, 4, 9 (in this order).

First eight raindrops are not enough. For example, there is a completely dry interval of length 7.3 that starts at coordinate 0.4 and ends at coordinate 7.7.

On the other hand, the first nine raindrops are already enough. Thus, the correct return value is 9.


1)
10
4
5
5
2
6

Returns: -1

This flowerpot has length 10. There are 5 raindrops, and each of them falls on the same coordinate: at 5. We need to water every interval of length 4 or more, but after the last raindrop the interval [6,10] is still all dry. Thus, the flowerpot is still not watered properly and we should return -1.


2)
10
5
5
5
2
6

Returns: 1

Sometimes a single drop of water is all Elly's cactuses need.


3)
1000000
1337
123456
424242
13
42

Returns: 8484

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

class EllysRain {
	bool possible(int L, int D, int n, int P1, int M, int A) {
		if (n <= 0) {
			return false;
		}

		const LL MOD = L + 1;
		vector<LL> v(1, P1);
		for (int i = 1; i < n; ++i) {
			LL next = (v[i - 1] * M + A) % MOD;
			v.push_back(next);
		}
		sort(v.begin(), v.end());
		v.push_back(L);

		LL prev = 0;
		for (LL a : v) {
			if ((a - prev) > D) {
				return false;
			}
			prev = a;
		}
		return true;
	}

public:
	int getTime(int L, int D, int N, int P1, int M, int A) {
		int left = 0;
		int right = N + 1;
		while ((right - left) > 1) {
			int mid = (left + right) / 2;
			if (possible(L, D, mid, P1, M, A)) {
				right = mid;
			} else {
				left = mid;
			}
		}
		return right > N ? -1 : right;
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
			int Arg0 = 23;
			int Arg1 = 7;
			int Arg2 = 12;
			int Arg3 = 14;
			int Arg4 = 13;
			int Arg5 = 5;
			int Arg6 = 9;

			verify_case(n, Arg6, getTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 4;
			int Arg2 = 5;
			int Arg3 = 5;
			int Arg4 = 2;
			int Arg5 = 6;
			int Arg6 = -1;

			verify_case(n, Arg6, getTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 5;
			int Arg2 = 5;
			int Arg3 = 5;
			int Arg4 = 2;
			int Arg5 = 6;
			int Arg6 = 1;

			verify_case(n, Arg6, getTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000;
			int Arg1 = 1337;
			int Arg2 = 123456;
			int Arg3 = 424242;
			int Arg4 = 13;
			int Arg5 = 42;
			int Arg6 = 8484;

			verify_case(n, Arg6, getTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 10;
			int Arg1 = 1;
			int Arg2 = 10;
			int Arg3 = 1;
			int Arg4 = 1;
			int Arg5 = 1;
			int Arg6 = 9;

			verify_case(n, Arg6, getTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 100000;
			int Arg1 = 100;
			int Arg2 = 1000;
			int Arg3 = 1;
			int Arg4 = 1;
			int Arg5 = 100;
			int Arg6 = 1000;

			verify_case(n, Arg6, getTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysRain ___test;
	___test.run_test(-1);
}
// END CUT HERE
