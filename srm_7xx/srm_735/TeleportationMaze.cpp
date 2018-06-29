// BEGIN CUT HERE
/*
SRM 735 Div2 Medium (600)

PROBLEM STATEMENT
There is a rectangular maze built on a two-dimensional grid. Each cell of the grid is either an empty corridor or a wall. A corridor is denoted by a period ('.'), a wall is denoted by a hashmark ('#'). You are given the vector <string> a that contains the map of the maze.
Rows and columns of the maze are numbered starting from 0. The character a[r][c] represents the cell in row r, column c.

You are also given the ints r1, c1, r2, and c2. You start in the cell (r1, c1) and your goal is to reach the cell (r2, c2).

You have to move in steps. In each step you can take one of the following actions:

Walk to any of the four adjacent cells provided that the target cell is empty. This move takes 1 second.
Teleport to the nearest empty cell in any of the four cardinal directions. This move takes 2 seconds.

You are not allowed to make a move that would take you outside the maze.

If reaching the destination is impossible, return -1. Otherwise, return the smallest T such that it is possible to go from (r1, c1) to (r2, c2) in T seconds.


DEFINITION
Class:TeleportationMaze
Method:pathLength
Parameters:vector <string>, int, int, int, int
Returns:int
Method signature:int pathLength(vector <string> a, int r1, int c1, int r2, int c2)


CONSTRAINTS
-a will contain between 1 and 50 elements, inclusive.
-Each element of a will contain between 1 and 50 characters, inclusive.
-All elements of a will have the same length.
-Each character in each element of a will be either '.' or '#'.
-Both r1 and r2 will be between 0 and |a|-1, inclusive.
-Both c1 and c2 will be between 0 and |a[0]|-1, inclusive.
-The origin and the destination will be distinct.
-The origin and the destination will both be empty.


EXAMPLES

0)
{".##.",
 ".###",
 ".###",
 "...."}
0
0
3
3

Returns: 4

0##2
.###
.###
...4

You begin in the cell labeled 0. The optimal solution is to teleport eastwards (to the cell labeled 2) and from there to teleport southwards (to the cell labeled 4).

The above solution takes 4 seconds. For comparison, walking southwards three times and then eastwards three times takes 6 seconds total.


1)
{"#.",
 ".#"}
0
1
1
0

Returns: -1

In this situation you have no valid moves. All cells adjacent to the source cell are blocked, so you cannot walk anywhere. There are no other empty cells in your row or column, so you cannot teleport anywhere either. Thus, there is no way to reach the given destination.


2)
{"......",
 "#####.",
 "#.###.",
 "#####.",
 "#.###.",
 "#####.",
 "#....."}
0
0
6
1

Returns: 5

012...
#####.
#.###.
#####.
#.###.
#####.
#54...

The digits in the map above show an optimal solution.
Each digit corresponds to the number of seconds between the beginning and the moment when you reach that cell.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class TeleportationMaze {
	vector <string> b;
	int gy;
	int gx;
	unsigned int cost[50][50];
	unsigned int dfs(int y, int x, int c) {
		unsigned int r = -1;
		cost[y][x] = c;
		if (y == gy && x == gx) {
			return c;
		}
		const int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };
		for (int d = 0; d < 4; ++d) {
			for (int i = 1; i < 50; ++i) {
				int ny = y + dy[d] * i, nx = x + dx[d] * i;
				if (ny >= 0 && ny < b.size() && nx >= 0 && nx < (int)b[0].length() && b[ny][nx] != '#') {
					unsigned int nc = c + (i == 1 ? 1 : 2);
					if (nc < cost[ny][nx]) {
						r = min(r, dfs(ny, nx, nc));
					}
					break;
				}
			}
		}
		return r;
	}

public:
	int pathLength(vector <string> a, int r1, int c1, int r2, int c2) {
		memset(cost, -1, sizeof(cost));
		b = a, gy = r2, gx = c2;
		return dfs(r1, c1, 0);
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
			string Arr0[] = {".##.",
 ".###",
 ".###",
 "...."};
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 3;
			int Arg4 = 3;
			int Arg5 = 4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg5, pathLength(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#.",
 ".#"};
			int Arg1 = 0;
			int Arg2 = 1;
			int Arg3 = 1;
			int Arg4 = 0;
			int Arg5 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg5, pathLength(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"......",
 "#####.",
 "#.###.",
 "#####.",
 "#.###.",
 "#####.",
 "#....."};
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 6;
			int Arg4 = 1;
			int Arg5 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg5, pathLength(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TeleportationMaze ___test;
	___test.run_test(-1);
}
// END CUT HERE
