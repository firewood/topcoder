// BEGIN CUT HERE
/*
SRM 576 Div1 Easy (256)

 PROBLEM STATEMENT
You might remember the old computer arcade games. Here is one about Manao.

The game level is an NxM grid of equal cells. The bottom of some cells has a platform at which Manao can stand.
All the cells in the bottommost row contain a platform, thus covering the whole ground of the level.
The rows of the grid are numbered from 1 to N starting from the top and the columns are numbered from 1 to M starting from the left.
Exactly one cell contains a coin and Manao needs to obtain it.

Initially, Manao is standing on the ground, i.e., in the bottommost row.
He can move between two horizontally adjacent cells if both contain a platform. Also, Manao has a ladder which he can use to climb.
He can use the ladder to climb both up and down. If the ladder is L units long, Manao can climb between two cells (i1, j) and (i2, j) if both contain a platform and |i1-i2| <= L.
Note that Manao carries the ladder along, so he can use it multiple times.
You need to determine the minimum ladder length L which is sufficient to acquire the coin.

Take a look at the following picture. On this level, Manao will manage to get the coin with a ladder of length 2.

You are given a vector <int> level containing N elements.
The j-th character in the i-th row of level is 'X' if cell (i+1, j+1) contains a platform and '.' otherwise.
You are also given ints coinRow and coinColumn.
The coin which Manao seeks is located in cell (coinRow, coinColumn) and it is guaranteed that this cell contains a platform.

Return the minimum L such that ladder of length L is enough to get the coin. If Manao can perform the task without using the ladder, return 0.


DEFINITION
Class:ArcadeManao
Method:shortestLadder
Parameters:vector <string>, int, int
Returns:int
Method signature:int shortestLadder(vector <string> level, int coinRow, int coinColumn)


NOTES
-Manao is not allowed to fall. The only way in which he may change his vertical coordinate is by using the ladder.


CONSTRAINTS
-level will contain N elements, where N is between 1 and 50, inclusive.
-Each element of level will be M characters long, where M is between 1 and 50, inclusive.
-Each element of level will consist of '.' and 'X' characters only.
-The last element of level will be entirely filled with 'X'.
-coinRow will be between 1 and N, inclusive.
-coinColumn will be between 1 and M, inclusive.
-level[coinRow - 1][coinColumn - 1] will be 'X'.


EXAMPLES

0)
{"XXXX....",
 "...X.XXX",
 "XXX..X..",
 "......X.",
 "XXXXXXXX"}
2
4

Returns: 2

The example from the problem statement.


1)
{"XXXX",
 "...X",
 "XXXX"}
1
1

Returns: 1

Manao can use the ladder to climb from the ground to cell (2, 4), then to cell (1, 4) and then he can walk right to the coin.


2)
{"..X..",
 ".X.X.",
 "X...X",
 ".X.X.",
 "..X..",
 "XXXXX"}
1
3

Returns: 4

With a ladder of length 4, Manao can first climb to cell (5, 3) and then right to (1, 3).


3)
{"X"}
1
1

Returns: 0

Manao begins in the same cell as the coin.


4)
{"XXXXXXXXXX",
 "...X......",
 "XXX.......",
 "X.....XXXX",
 "..XXXXX..X",
 ".........X",
 ".........X",
 "XXXXXXXXXX"}
1
1

Returns: 2

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<string> StrVec;

class ArcadeManao {

	int _r;
	int _c;
	int _w;
	int _h;
	StrVec _lev;
	int f[51][51];

	bool dfs(int x, int y, int len) {
		f[y][x] = 1;
		if (x == _c && y == _r) {
			return true;
		}
		int i, j;
		for (i = -1; i <= 1; i += 2) {
			j = x + i;
			if (j >= 0 && j < _w && !f[y][j] && _lev[y][j] == 'X') {
				if (dfs(j, y, len)) {
					return true;
				}
			}
		}
		for (i = -len; i <= len; ++i) {
			j = y + i;
			if (j >= 0 && j < _h && !f[j][x] && _lev[j][x] == 'X') {
				if (dfs(x, j, len)) {
					return true;
				}
			}
		}
		return false;
	}

public:
	int shortestLadder(vector <string> level, int coinRow, int coinColumn) {
		_r = coinRow - 1;
		_c = coinColumn - 1;
		_w = (int)level[0].length();
		_h = (int)level.size();
		_lev = level;
		int len;
		for (len = 0; len <= 50; ++len) {
			memset(f, 0, sizeof(f));
			if (dfs(0, _h - 1, len)) {
				break;
			}
		}
		return len;
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
			string Arr0[] = {"XXXX....",
 "...X.XXX",
 "XXX..X..",
 "......X.",
 "XXXXXXXX"};
			int Arg1 = 2;
			int Arg2 = 4;
			int Arg3 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, shortestLadder(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"XXXX",
 "...X",
 "XXXX"};
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, shortestLadder(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..X..",
 ".X.X.",
 "X...X",
 ".X.X.",
 "..X..",
 "XXXXX"};
			int Arg1 = 1;
			int Arg2 = 3;
			int Arg3 = 4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, shortestLadder(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"X"};
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, shortestLadder(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"XXXXXXXXXX",
 "...X......",
 "XXX.......",
 "X.....XXXX",
 "..XXXXX..X",
 ".........X",
 ".........X",
 "XXXXXXXXXX"};
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, shortestLadder(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ArcadeManao ___test;
	___test.run_test(-1);
}
// END CUT HERE
