// BEGIN CUT HERE
/*
SRM 729 Div1 Medium (450)

PROBLEM STATEMENT
We have an n by n board.
Both rows and columns are numbered 0 through n-1.

There is a frog on the board.
Initially, the frog is located in the cell (sx, sy).
Its goal is to reach the cell (tx, ty).

The frog can move by making a sequence of zero or more jumps.
Each jump must have length at least d.
More precisely, the frog can jump from (r1,c1) to (r2,c2) if and only if the Euclidean distance between the centers of those two cells is at least d.
Formally, sqrt( (r1-r2)^2 + (c1-c2)^2 ) must be greater than or equal to d.

The frog is not allowed to jump outside the board.

You are given the ints n, d, sx, sy, tx, and ty.
Compute and return the minimum number of jumps the frog needs to make to reach its goal.
If the goal cannot be reached, return -1 instead.


DEFINITION
Class:FrogSquare
Method:minimalJumps
Parameters:int, int, int, int, int, int
Returns:int
Method signature:int minimalJumps(int n, int d, int sx, int sy, int tx, int ty)


CONSTRAINTS
-n will be between 1 and 1,000, inclusive.
-d will be between 1 and 2,000, inclusive.
-sx will be between 0 and n-1, inclusive.
-sy will be between 0 and n-1, inclusive.
-tx will be between 0 and n-1, inclusive.
-ty will be between 0 and n-1, inclusive.


EXAMPLES

0)
100
10
0
0
3
4

Returns: 2

The distance between (0, 0) and (3, 4) is 5, which is less than 10, so we can't jump there direcly. However we can get there in 2 jumps, for example: from (0, 0) to (10, 0), then to (3, 4).


1)
100
5
0
0
3
4

Returns: 1

This time we can jump to (3, 4) directly.


2)
100
200
0
0
3
4

Returns: -1

You can't jump to anywhere on the board from (0, 0). Thus you can't get to (3, 4).


3)
10
7
4
4
5
5

Returns: 3


4)
1
1
0
0
0
0

Returns: 0

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class FrogSquare {
	int vis[1024][1024];
	int sz;
	int md;
	int gx;
	int gy;
	int dfs(int x, int y, int d) {
		vis[x][y] = d;
		if (x == gx && y == gy) {
			return 0;
		}
		if (((gx - x)*(gx - x) + (gy - y)*(gy - y)) >= md) {
			return 1;
		}
		int r = 1 << 30;
		int nxs[] = { 0, x / 2, sz - x / 2 - 1, sz - 1, -1 };
		int nys[] = { 0, y / 2, sz - y / 2 - 1, sz - 1, -1 };
		for (int i = 0; nxs[i]>= 0; ++i) {
			for (int j = 0; nys[j]>=0; ++j) {
				int nx = nxs[i], ny = nys[j];
				if (d < vis[nx][ny] && ((nx - x)*(nx - x) + (ny - y)*(ny - y)) >= md) {
					r = min(r, 1 + dfs(nx, ny, d + 1));
				}
			}
		}
		return r;
	}

public:
	int minimalJumps(int n, int d, int sx, int sy, int tx, int ty) {
		memset(vis, 0x3f, sizeof(vis));
		sz = n, md = d * d, gx = tx, gy = ty;
		int ans = dfs(sx, sy, 0);
		return ans < (1 << 30) ? ans : -1;
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
			int Arg0 = 100;
			int Arg1 = 10;
			int Arg2 = 0;
			int Arg3 = 0;
			int Arg4 = 3;
			int Arg5 = 4;
			int Arg6 = 2;

			verify_case(n, Arg6, minimalJumps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 5;
			int Arg2 = 0;
			int Arg3 = 0;
			int Arg4 = 3;
			int Arg5 = 4;
			int Arg6 = 1;

			verify_case(n, Arg6, minimalJumps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 200;
			int Arg2 = 0;
			int Arg3 = 0;
			int Arg4 = 3;
			int Arg5 = 4;
			int Arg6 = -1;

			verify_case(n, Arg6, minimalJumps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 7;
			int Arg2 = 4;
			int Arg3 = 4;
			int Arg4 = 5;
			int Arg5 = 5;
			int Arg6 = 3;

			verify_case(n, Arg6, minimalJumps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 0;
			int Arg3 = 0;
			int Arg4 = 0;
			int Arg5 = 0;
			int Arg6 = 0;

			verify_case(n, Arg6, minimalJumps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 13;
			int Arg1 = 13;
			int Arg2 = 0;
			int Arg3 = 8;
			int Arg4 = 11;
			int Arg5 = 12;
			int Arg6 = 3;

			verify_case(n, Arg6, minimalJumps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 26;
			int Arg1 = 26;
			int Arg2 = 19;
			int Arg3 = 21;
			int Arg4 = 6;
			int Arg5 = 23;
			int Arg6 = 4;

			verify_case(n, Arg6, minimalJumps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 238;
			int Arg1 = 264;
			int Arg2 = 23;
			int Arg3 = 23;
			int Arg4 = 220;
			int Arg5 = 29;
			int Arg6 = 4;

			verify_case(n, Arg6, minimalJumps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 436;
			int Arg1 = 479;
			int Arg2 = 396;
			int Arg3 = 118;
			int Arg4 = 356;
			int Arg5 = 395;
			int Arg6 = 4;

			verify_case(n, Arg6, minimalJumps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FrogSquare ___test;
	___test.run_test(-1);
}
// END CUT HERE
