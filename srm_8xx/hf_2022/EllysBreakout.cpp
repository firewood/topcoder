// BEGIN CUT HERE
/*
2022 Humbefool Cup - Preliminary Hard (1000)

PROBLEM STATEMENT
Elly was kidnapped! Luckily she has found the plan of the mansion she is held hostage at. Unfortunately she does not know where exactly in the building she is located (she was blind-folded when taken there).

We can consider the mansion to be a matrix of N rows and M columns. Each cell can either be empty (a corridor) or blocked (a wall). Initially Elly is located in one of the empty cells, but we don't know which one exactly. She can move to each of the (up to) four adjacent cells. Moving to adjacent empty cell takes no time at all - after all it's just making several steps. Moving through a blocked cell takes a bit more time - the girl has to break the wall first. We assume that this takes her one hour. The girl can escape through each of the cells on the border of the mansion by just stepping out (like there is a corridor outside the matrix).

Elly believes she is located in an empty cell that would take her the most time to break free, if choosing the optimal path out. Help her by finding out how many possibile such cells there are.

You are given the plan of the mansion in the vector <string> plan. It has N elements (the rows of the matrix), and each element is M characters long (the columns of the matrix). Each character is either a '.' or '#'. The symbol '.' represents an empty cell and the symbol '#' represents a blocked cell. Write a method that returns the number of cells that the girl can be initially located in - that is the number of cells, that have maximal time to reach the outside of the mansion if choosing the optimal path.

DEFINITION
Class:EllysBreakout
Method:getCount
Parameters:vector <string>
Returns:int
Method signature:int getCount(vector <string> plan)


CONSTRAINTS
-plan will contain between 1 and 100 elements, inclusive.
-Each element of plan will contain between 1 and 100 characters, inclusive.
-All elements of plan will contain the same number of characters.
-Each character in plan will be either '.' or '#'.
-It is guaranteed, that there will be at least one '.' character.


EXAMPLES

0)
{".#............",
 ".#####........",
 ".#.#..#.......",
 ".##.#.#.......",
 ".#.#..#..####.",
 ".#...##..#.##.",
 "..####...###.."}

Returns: 1

There are three "rooms", one of them nested inside another one. This means the girl should be located inside the inner room (she needs to break two walls to escape).


1)
{"..#",
 "...",
 ".#."}

Returns: 7

Sometimes Elly may be able to escape without breaking any walls.


2)
{"#.#.#.#.#.#.#.#.#.",
 ".#.#.#.#.#.#.#.#.#",
 "#.#.#.#.#.#.#.#.#.",
 ".#.#.#.#.#.#.#.#.#",
 "#.#.#.#.#.#.#.#.#.",
 ".#.#.#.#.#.#.#.#.#",
 "#.#.#.#.#.#.#.#.#.",
 ".#.#.#.#.#.#.#.#.#",
 "#.#.#.#.#.#.#.#.#.",
 ".#.#.#.#.#.#.#.#.#",
 "#.#.#.#.#.#.#.#.#.",
 ".#.#.#.#.#.#.#.#.#"}

Returns: 8

Please note that the girl can only move horizontally and vertically (but not diagonally).


3)
{"#########",
 "#########",
 "#########",
 "#########",
 "####.####",
 "####.####",
 "####.####",
 "#########",
 "#########",
 "#########",
 "#########"}

Returns: 3

Very well guarded room with three cells.


4)
{"#...##.......#..#..#..#.#..#..###............##...",
 "....#.....#....#...###..#....#......#.#.......#.#.",
 "......#....#..#.....#.#..#...#.#..##.......#.....#",
 "................#..#......##........#..#....##...#",
 "###..#..#.#....##...#...........#.##..###..##.....",
 ".##..#......#...........#.##...##..#.....#.....#..",
 "....#..##...#..#.#........##.#....................",
 ".#.#.#.##.....#.........#......#.......#..#.##.#..",
 "..#....#......#........#...#.#...#.#....#........#",
 "#.#....#..#.#.#.#....#.....................#.#....",
 ".#....#..#.......#.........#....#.#............##.",
 "..##......#....###..#...#.#..#.....##........#..#.",
 "........#.#..........#......#........##.#.#.#....#",
 "....#.#..####...#..#.....#.###..##....#.#.......#.",
 "....#....#...#................###.#......##.......",
 ".#.....#..#.....##....#......................##.#.",
 "#.................#.......#...#...........#....#..",
 "............#........#.....#.#.....#.#.....#..##..",
"#......#.#..#.#.##..#.........#..#.#.....#.....#..",
 "....#..###.#........#.#.....................##....",
 "......##...###..#...#.##..#..#.##....#.........##.",
 ".......#...............#....#...#......##....#..#.",
 ".#...#.##....#...#........###..##.#....#...##.....",
 "....#........#..............#..###.#.#..#.....#.##",
 ".#...#..#.....#.#...#...........#....##.....#.#...",
 "...#..#.#.#..##....#............#.....#........###",
 ".##......#.#..##.......###...##...................",
 "..........#.............#.#...#.....###...##..##..",
 ".......##...#.#...#.........#.#.....#.#..#.#...#..",
 "####.........#.#.....#....#.#......#.#.....#..#...",
 ".#.#...#..###...#.#.#.....###.#....##.....#...#..#",
 ".#..#.##.#.###....#.###..#..........#...#.........",
 "##..#.#....#..##...#.....##..#..##..............##",
 "#.##.##..........##.#....##......#...#.....##...#.",
 ".....#........#..............#.....####.######....",
 "..##............#..###.##...#.#...#.....#.#...#..#",
 "...##..#.#...#......#.#..........#..#..##..#.#..#.",
 "..##.####......#....#....#.....#......#....##.....",
 "#.......####.#......##.#.....#..#........#...##.#.",
 "..#.....#..###....#......#..#........#....####....",
 "......#.....#..................#.........#.##...#.",
 "...#....#....##......#.#.....#.....#....#......#..",
 "....#.##...#.#....#..#.#...#.......##.......#.#...",
 "...#..#.#.##.#.....###....#.###.....##.#......#...",
 ".#.#......#.....#.....#...........##...#.....#.##.",
 "..........#.....#...#.##....#..........#.....###..",
 "........##..#.....#...#....##..#......##.......#..",
 ".....#....##....#.....#....#.#.#.........#........",
 "..#...##......#.#............#....#.##...#....#...",
 "..##...#.#...#......#....##.#.#..#......#..######."}

Returns: 13

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

typedef pair<int, int> II;

static const int dx[4] = { -1,1,0,0 };
static const int dy[4] = { 0,0,-1,1 };

class EllysBreakout {
public:
	int getCount(vector <string> plan) {
		int H = plan.size(), W = plan[0].length(), ans = 0;
		vector<II> q, nq;
		set<II> used;
		auto push = [&](int y, int x) {
			II key(y, x);
			if (used.find(key) == used.end()) {
				used.insert(key);
				if (plan[y][x] == '.') {
					q.emplace_back(key);
				} else {
					nq.emplace_back(key);
				}
			}
		};
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				if (i == 0 || j == 0 || i == H - 1 || j == W - 1) {
					push(i, j);
				}
			}
		}
		// 01-BFS
		while (!q.empty() || !nq.empty()) {
			int cnt = 0;
			for (int qi = 0; qi < q.size(); ++qi) {
				int y = q[qi].first, x = q[qi].second;
				cnt += plan[y][x] == '.';
				for (int dir = 0; dir < 4; ++dir) {
					int ny = y + dy[dir], nx = x + dx[dir];
					if (ny >= 0 && ny < H && nx >= 0 && nx < W) {
						push(ny, nx);
					}
				}
			}
			q = nq;
			nq.clear();
			if (cnt > 0) {
				ans = cnt;
			}
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
			string Arr0[] = { ".#............",
 ".#####........",
 ".#.#..#.......",
 ".##.#.#.......",
 ".#.#..#..####.",
 ".#...##..#.##.",
 "..####...###.." };
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getCount(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)) {
			string Arr0[] = { "..#",
 "...",
 ".#." };
			int Arg1 = 7;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getCount(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)) {
			string Arr0[] = { "#.#.#.#.#.#.#.#.#.",
 ".#.#.#.#.#.#.#.#.#",
 "#.#.#.#.#.#.#.#.#.",
 ".#.#.#.#.#.#.#.#.#",
 "#.#.#.#.#.#.#.#.#.",
 ".#.#.#.#.#.#.#.#.#",
 "#.#.#.#.#.#.#.#.#.",
 ".#.#.#.#.#.#.#.#.#",
 "#.#.#.#.#.#.#.#.#.",
 ".#.#.#.#.#.#.#.#.#",
 "#.#.#.#.#.#.#.#.#.",
 ".#.#.#.#.#.#.#.#.#" };
			int Arg1 = 8;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getCount(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)) {
			string Arr0[] = { "#########",
 "#########",
 "#########",
 "#########",
 "####.####",
 "####.####",
 "####.####",
 "#########",
 "#########",
 "#########",
 "#########" };
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getCount(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)) {
			string Arr0[] = { "#...##.......#..#..#..#.#..#..###............##...",
 "....#.....#....#...###..#....#......#.#.......#.#.",
 "......#....#..#.....#.#..#...#.#..##.......#.....#",
 "................#..#......##........#..#....##...#",
 "###..#..#.#....##...#...........#.##..###..##.....",
 ".##..#......#...........#.##...##..#.....#.....#..",
 "....#..##...#..#.#........##.#....................",
 ".#.#.#.##.....#.........#......#.......#..#.##.#..",
 "..#....#......#........#...#.#...#.#....#........#",
 "#.#....#..#.#.#.#....#.....................#.#....",
 ".#....#..#.......#.........#....#.#............##.",
 "..##......#....###..#...#.#..#.....##........#..#.",
 "........#.#..........#......#........##.#.#.#....#",
 "....#.#..####...#..#.....#.###..##....#.#.......#.",
 "....#....#...#................###.#......##.......",
 ".#.....#..#.....##....#......................##.#.",
 "#.................#.......#...#...........#....#..",
 "............#........#.....#.#.....#.#.....#..##..",
"#......#.#..#.#.##..#.........#..#.#.....#.....#..",
 "....#..###.#........#.#.....................##....",
 "......##...###..#...#.##..#..#.##....#.........##.",
 ".......#...............#....#...#......##....#..#.",
 ".#...#.##....#...#........###..##.#....#...##.....",
 "....#........#..............#..###.#.#..#.....#.##",
 ".#...#..#.....#.#...#...........#....##.....#.#...",
 "...#..#.#.#..##....#............#.....#........###",
 ".##......#.#..##.......###...##...................",
 "..........#.............#.#...#.....###...##..##..",
 ".......##...#.#...#.........#.#.....#.#..#.#...#..",
 "####.........#.#.....#....#.#......#.#.....#..#...",
 ".#.#...#..###...#.#.#.....###.#....##.....#...#..#",
 ".#..#.##.#.###....#.###..#..........#...#.........",
 "##..#.#....#..##...#.....##..#..##..............##",
 "#.##.##..........##.#....##......#...#.....##...#.",
 ".....#........#..............#.....####.######....",
 "..##............#..###.##...#.#...#.....#.#...#..#",
 "...##..#.#...#......#.#..........#..#..##..#.#..#.",
 "..##.####......#....#....#.....#......#....##.....",
 "#.......####.#......##.#.....#..#........#...##.#.",
 "..#.....#..###....#......#..#........#....####....",
 "......#.....#..................#.........#.##...#.",
 "...#....#....##......#.#.....#.....#....#......#..",
 "....#.##...#.#....#..#.#...#.......##.......#.#...",
 "...#..#.#.##.#.....###....#.###.....##.#......#...",
 ".#.#......#.....#.....#...........##...#.....#.##.",
 "..........#.....#...#.##....#..........#.....###..",
 "........##..#.....#...#....##..#......##.......#..",
 ".....#....##....#.....#....#.#.#.........#........",
 "..#...##......#.#............#....#.##...#....#...",
 "..##...#.#...#......#....##.#.#..#......#..######." };
			int Arg1 = 13;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getCount(Arg0));
		}
		n++;

	}

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysBreakout ___test;
	___test.run_test(-1);
}
// END CUT HERE
