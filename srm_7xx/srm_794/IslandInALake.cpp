// BEGIN CUT HERE
/*
SRM 794 Div1 Easy (250)

PROBLEM STATEMENT

You are given the vector <string> country that contains a rectangular map of a region.
The map is divided into cells, and each cell is either water ('.') or land ('#').
All cells on the border of the map are water cells.

Boats can travel between water cells by moving in the four cardinal directions ("up, down, left, right").
Two water cells belong to the same body of water if a boat can reach one of those cells from the other (without going onto land).
The body of water that contains the border of the map is the sea, all other bodies of water are lakes.

Rabbits can travel between land cells by moving in eight directions (not just horizontally and vertically, but also diagonally).
Two land cells belong to the same island if a rabbit can reach one of those cells from the other (without going into water).

You have just inherited an unlimited amount of soil.
You want to use it to build your own island somewhere in this region.
You really dislike saltwater, so you want to build your island on one of the lakes (and not in the sea).
Obviously, your island must be a single island (as defined above) and it must not touch any of the existing islands.

Compute and return the largest possible number of cells that can form your new island-in-a-lake.
Return 0 if it's not possible to build a new island in a lake.


DEFINITION
Class:IslandInALake
Method:build
Parameters:vector <string>
Returns:int
Method signature:int build(vector <string> country)


CONSTRAINTS
-country will contain between 1 and 50 elements, inclusive.
-Each element of country will contain between 1 and 50 characters.
-All elements of country will contain the same number of characters.
-Each character in country will be either '.' or '#'.
-Each character on the boundary of country (i.e., first+last row+column) will be '.'.


EXAMPLES

0)
{"......",
 "......",
 "......",
 "......",
 "......"}

Returns: 0

Only the sea. No islands, no lakes, nowhere to build our new island-in-a-lake.


1)
{".......",
 "..##...",
 ".##..#.",
 "..#.#..",
 "......."}

Returns: 0

Two islands in the sea. One has five cells, the other one has two. No lakes anywhere.


2)
{".......",
 ".####..",
 ".#...#.",
 ".#####.",
 "......."}

Returns: 0

One island with a lake that consists of three cells. The lake is too narrow, we cannot build any new island inside the lake.


3)
{"..........",
 ".####.....",
 ".#...#....",
 ".#...#....",
 ".#...#....",
 ".#####....",
 ".........."}

Returns: 1

This time we can build a single-cell island inside the lake. The new map would then look as follows (with the new island denoted by an asterisk):

..........
.####.....
.#...#....
.#.*.#....
.#...#....
.#####....
..........


4)
{"............",
 ".####.#####.",
 ".#...#....#.",
 ".#........#.",
 ".#...#....#.",
 ".#########..",
 "............"}

Returns: 2

A bigger island, still with a single lake. There are now multiple ways to build a new island on this lake, including one way of building an island that consists of two adjacent cells.

............
.####.#####.
.#...#....#.
.#.....**.#.
.#...#....#.
.#########..
............


5)
{"...........",
 "..#####....",
 "..#....##..",
 "..#.....#..",
 "...#.....#.",
 "..#.#....#.",
 ".#...#...#.",
 "..###.###..",
 "..........."}

Returns: 3

This map contains a single island and there are two lakes on this island. One is too small to build on, the other can contain a new island of size 3 as shown below.

...........
..#####....
..#....##..
..#..*..#..
...#..*..#.
..#.#..*.#.
.#...#...#.
..###.###..
...........


6)
{"...........",
 ".#########.",
 ".#.......#.",
 ".#.#####.#.",
 ".#.#...#.#.",
 ".#.#...#.#.",
 ".#.#...#.#.",
 ".#.#####.#.",
 ".#.......#.",
 ".#########.",
 "..........."}

Returns: 1

We can build a 1-cell island in the center of this map. The lake that contains it is actually a lake on an island that is on a lake on an island, but we do not care about that. Any lake (i.e., any body of water other than the sea) can be used for building.


7)
{"...........",
 ".#########.",
 ".#.......#.",
 ".#.#####.#.",
 ".#.#...#...",
 ".#.#...#.#.",
 ".#.#...#.#.",
 ".#.###.#.#.",
 ".#.......#.",
 ".#########.",
 "..........."}

Returns: 0

This map looks similar to the previous one, but this one actually contains two separate islands, and all water is sea so we cannot build our island anywhere.


8)
{"...........",
 ".#########.",
 ".#.......#.",
 ".#.......#.",
 ".#.......#.",
 ".#.......#.",
 ".#.......#.",
 ".#.......#.",
 ".#...#...#.",
 ".#.......#.",
 ".#.......#.",
 ".#.......#.",
 ".#########.",
 "..........."}

Returns: 31

The optimal new island is shown below. Notice how it goes around the existing tiny island.

...........
.#########.
.#.......#.
.#.*****.#.
.#.*****.#.
.#.*****.#.
.#.*****.#.
.#.*...*.#.
.#.*.#.*.#.
.#.*...*.#.
.#.*****.#.
.#.......#.
.#########.
...........


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
#include <functional>

using namespace std;

class IslandInALake {

public:
	int build(vector <string> country) {
		int H = country.size(), W = country[0].length();
		vector<vector<int>> vis(H, vector<int>(W));
		int color = 0;

		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				function<void(int, int)> dfs = [&](int y, int x) {
					if (country[y][x] == '#' || vis[y][x] > 0) return;
					vis[y][x] = color;
					const int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
					for (int d = 0; d < 4; ++d) {
						int ny = y + dy[d], nx = x + dx[d];
						if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
							dfs(ny, nx);
						}
					}
				};
				++color;
				dfs(i, j);
			}
		}

		for (int i = 3; i <= H - 3; ++i) {
			for (int j = 3; j <= W - 3; ++j) {
				int cnt = 0;
				for (int y = i - 1; y <= i + 1; ++y) {
					for (int x = j - 1; x <= j + 1; ++x) {
						cnt += vis[y][x] > 1;
					}
				}
				if (cnt >= 9) {
					country[i][j] = '*';
				}
			}
		}

		int ans = 0;
		for (int i = 3; i <= H - 3; ++i) {
			for (int j = 3; j <= W - 3; ++j) {
				function<int(int, int)> dfs = [&](int y, int x) -> int {
					if (country[y][x] != '*') return 0;
					country[y][x] = '.';
					int r = 1;
					for (int ny = y - 1; ny <= y + 1; ++ny) {
						for (int nx = x - 1; nx <= x + 1; ++nx) {
							if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
							if (nx == x && ny == y) continue;
							r += dfs(ny, nx);
						}
					}
					return r;
				};
				ans = max(ans, dfs(i, j));
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
			string Arr0[] = {"......",
 "......",
 "......",
 "......",
 "......"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, build(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".......",
 "..##...",
 ".##..#.",
 "..#.#..",
 "......."};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, build(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".......",
 ".####..",
 ".#...#.",
 ".#####.",
 "......."};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, build(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..........",
 ".####.....",
 ".#...#....",
 ".#...#....",
 ".#...#....",
 ".#####....",
 ".........."};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, build(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"............",
 ".####.#####.",
 ".#...#....#.",
 ".#........#.",
 ".#...#....#.",
 ".#########..",
 "............"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, build(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...........",
 "..#####....",
 "..#....##..",
 "..#.....#..",
 "...#.....#.",
 "..#.#....#.",
 ".#...#...#.",
 "..###.###..",
 "..........."};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, build(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...........",
 ".#########.",
 ".#.......#.",
 ".#.#####.#.",
 ".#.#...#.#.",
 ".#.#...#.#.",
 ".#.#...#.#.",
 ".#.#####.#.",
 ".#.......#.",
 ".#########.",
 "..........."};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, build(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...........",
 ".#########.",
 ".#.......#.",
 ".#.#####.#.",
 ".#.#...#...",
 ".#.#...#.#.",
 ".#.#...#.#.",
 ".#.###.#.#.",
 ".#.......#.",
 ".#########.",
 "..........."};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, build(Arg0));
		}
		n++;

		// test_case_8
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...........",
 ".#########.",
 ".#.......#.",
 ".#.......#.",
 ".#.......#.",
 ".#.......#.",
 ".#.......#.",
 ".#.......#.",
 ".#...#...#.",
 ".#.......#.",
 ".#.......#.",
 ".#.......#.",
 ".#########.",
 "..........."};
			int Arg1 = 31;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, build(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	IslandInALake ___test;
	___test.run_test(-1);
}
// END CUT HERE
