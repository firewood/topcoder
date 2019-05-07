// BEGIN CUT HERE
/*
TCO19 R1B Medium (500)

PROBLEM STATEMENT

Elly plays a platform game on her computer.
There are N platforms with distinct heights, placed on top of each other.
You can generate the heights of the platforms as follows:

Platform number 1 is has height[1] = H1.
For each i between 2 and N, inclusive, height[i] = (height[i-1] * A + B) % M.

The girl has a "hero" whom she can move from platform to platform.
At the beginning of the game there is a coin on each platform.
The hero collects the coin the first time she visits the platform.
(Once a coin is collected, it is gone. Visiting the same platform again does not give Elly a second coin.)

In the beginning of the game Elly can place her hero on any of the N platforms.
Once she does that, the hero will pick up the coin from that platform and then the game starts.

During the game Elly only has one way to move her hero: by using a device that teleports the hero vertically.
The device is deterministic and it behaves as follows:
if the hero's current platform is at height X, the hero gets teleported to the height Y = (X * P + Q) % M.
After the teleport, one of three different things will happen:

If there is a platform at height Y, the hero will stand on that platform and collect the coin from that platform (if it is still there).
If there is no platform at height Y but there are some lower platforms, the hero falls down until she hits the closest platform. She will always lands safely, regardless of the height of the fall. Then, she will collect the coin from that platform (if it is still there).
If there are no platforms at or below the hero's new height, the game ends.

Elly can use the device arbitrarily many times, one after another.
Note that the device can only be used while the hero is standing on a platform (i.e., not while she is falling).

You are given all the ints mentioned in the problem statement.
Compute and return the largest number of coins Elly's hero can collect during a single game.


DEFINITION
Class:EllysTeleport
Method:getMax
Parameters:int, int, int, int, int, int, int
Returns:int
Method signature:int getMax(int N, int H1, int A, int B, int P, int Q, int M)


CONSTRAINTS
-N will be between 1 and 10,000, inclusive.
-M will be between 1 and 1,000,000,007, inclusive.
-H1, A, B, P and Q will be between 0 and M-1, inclusive.
-All platform heights will be distinct.


EXAMPLES

0)
11
9
17
9
7
13
23

Returns: 6

The generated heights are {9, 1, 3, 14, 17, 22, 15, 11, 12, 6, 19}. The optimal choice would be to start from the platform with height 15. The heights Elly's hero will visit are: 15 -> 3 -> 11 -> [21] -> 19 -> [8] -> 6 -> 9 -> [7] -> 6... With [Y] we have denoted a height where the hero is teleported to, but there is no platform so she starts falling down.


1)
8
17
23
19
15
28
43

Returns: 4

The generated numbers are {17, 23, 32, 24, 12, 37, 10, 34}. There are two possible choices for a starting platform, which yields the maximal number of coins: 32 or 12 (the paths being, respectively, 32 -> [35] -> 34 -> [22] -> 17 -> [25] -> 24 -> [1] -> game ends, and 12 -> [36] -> 34 -> [22] -> 17 -> [25] -> 24 -> [1] -> game ends).


2)
15
42
114
52
76
1
131

Returns: 5

The generated numbers are {42, 124, 40, 27, 117, 28, 100, 55, 34, 129, 86, 31, 49, 5, 98}.


3)
10
71
54
85
96
52
100

Returns: 10

Here the heights are {71, 19, 11, 79, 51, 39, 91, 99, 31, 59}. Starting from the platform with height 99 Elly's hero can collect all of the coins: 99 -> [56] -> 51 -> [49] -> 39 -> [96] -> 91 -> [88] -> 79 -> [36] -> 31 -> [28] -> 19 -> [76] -> 71 -> [68] -> 59 -> [16] -> 11 -> [8] -> game ends


4)
1000
1337
706135
1085680
1153206
345473
1234567

Returns: 42

Watch out for overflows when generating the heights!

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

class EllysTeleport {

public:
	int getMax(int N, int H1, int A, int B, int P, int Q, int M) {
		vector<LL> h({ H1 });
		for (int i = 1; i < N; ++i) {
			h.push_back((h[i - 1] * A + B) % M);
		}
		sort(h.begin(), h.end());

		vector<int> e(N, -1);
		for (int i = 0; i < N; ++i) {
			LL next = (int)((h[i] * P + Q) % M);
			e[i] = (int)(upper_bound(h.begin(), h.end(), next) - h.begin() - 1);
		}

		int ans = 0;
		for (int i = 0; i < N; ++i) {
			vector<int> vis(N);
			int cnt = 0;
			for (int node = i; node >= 0 && !vis[node]; node = e[node]) {
				++cnt;
				vis[node] = true;
			}
			ans = max(ans, cnt);
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T>& V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int& Expected, const int& Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) {
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 11;
			int Arg1 = 9;
			int Arg2 = 17;
			int Arg3 = 9;
			int Arg4 = 7;
			int Arg5 = 13;
			int Arg6 = 23;
			int Arg7 = 6;

			verify_case(n, Arg7, getMax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 8;
			int Arg1 = 17;
			int Arg2 = 23;
			int Arg3 = 19;
			int Arg4 = 15;
			int Arg5 = 28;
			int Arg6 = 43;
			int Arg7 = 4;

			verify_case(n, Arg7, getMax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 15;
			int Arg1 = 42;
			int Arg2 = 114;
			int Arg3 = 52;
			int Arg4 = 76;
			int Arg5 = 1;
			int Arg6 = 131;
			int Arg7 = 5;

			verify_case(n, Arg7, getMax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 10;
			int Arg1 = 71;
			int Arg2 = 54;
			int Arg3 = 85;
			int Arg4 = 96;
			int Arg5 = 52;
			int Arg6 = 100;
			int Arg7 = 10;

			verify_case(n, Arg7, getMax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1000;
			int Arg1 = 1337;
			int Arg2 = 706135;
			int Arg3 = 1085680;
			int Arg4 = 1153206;
			int Arg5 = 345473;
			int Arg6 = 1234567;
			int Arg7 = 42;

			verify_case(n, Arg7, getMax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 10000;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 1;
			int Arg4 = 1;
			int Arg5 = 1;
			int Arg6 = 20000;		// M
			int Arg7 = 10000;

			verify_case(n, Arg7, getMax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysTeleport ___test;
	___test.run_test(-1);
}
// END CUT HERE
