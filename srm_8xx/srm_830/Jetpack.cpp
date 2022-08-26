// BEGIN CUT HERE
/*
SRM 830 Div1 Easy (250)

PROBLEM STATEMENT

You want to travel from 'A' to 'B' in a maze.
You have a jetpack to help you cross some pits along the way.

The maze consists of a grid of unit square cells.

Some cells are walls ('#'). You cannot enter those.
Some cells are floors ('.'). You can walk on those.
The characters 'A' and 'B' are the start and the desired end of your journey. Both are unique. Both count as floors.
Some cells are pits ('_'). You can hover over those if your jetpack is active.
Some cells are charging stations ('C'). They count as floors.

You can move in a sequence of steps. Each step takes 1 second. Each step will take you to a cell that is horizontally or vertically adjacent to your current cell. 
You cannot enter a wall, you cannot leave the maze (as if there were additional walls all around it), and you cannot enter a cell with a pit if your jetpack has no charges left.

Initially, your jetpack has no charges.
Spending T consecutive seconds at a charging station adds one charge to the jetpack.
You can do this arbitrarily many times during your travels, possibly at different charging stations.
A jetpack can contain an arbitrary large number of charges simultaneously.

Each step onto a cell with a pit consumes one jetpack charge.
(Stepping from a cell with a pit onto another cell with a pit still consumes only one charge. Stepping from a cell with a pit onto a floor does not consume any charges.)

Calculate and return the fastest time in which it is possible to reach 'B' from 'A'.
If it's impossible to reach 'B', return -1 instead.


DEFINITION
Class:Jetpack
Method:travel
Parameters:vector <string>, int
Returns:int
Method signature:int travel(vector <string> maze, int T)


CONSTRAINTS
-maze will contain between 1 and 50 elements, inclusive.
-Each element of maze will contain between 1 and 50 characters, inclusive.
-Each element of maze will contain the same number of characters.
-Each character in maze will be one of 'A', 'B', 'C', '#', '.', '_'.
-There will be exactly one 'A'.
-There will be exactly one 'B'.
-T will be between 1 and 10^5, inclusive.


EXAMPLES

0)
{"A###B",
 "....."}
47

Returns: 6

We need six ordinary steps. Each takes a second.


1)
{"A#.#B",
 "..#.."}
47

Returns: -1

As we cannot make diagonal steps, this maze has no solution.


2)
{"A#.#B",
 ".._C."}
1

Returns: -1

This maze has no solution either. With an empty jetpack we cannot enter the cell with the pit, and thus we cannot get to the charging station.


3)
{"B_C_C_CA"}
10

Returns: 37

One optimal solution:

1 second: Take a step left.
10 seconds: Charge jetpack. (One charge added.)
1 second: Take a step left. (We stepped onto a pit. One jetpack charge is consumed.)
1 second: Take a step left.
10 seconds: Charge jetpack. (One charge added.)
1 second: Take a step left. (We stepped onto a pit. One jetpack charge is consumed.)
1 second: Take a step left.
10 seconds: Charge jetpack. (One charge added.)
1 second: Take a step left. (We stepped onto a pit. One jetpack charge is consumed.)
1 second: Take a step left.


4)
{"___B__.",
 "C#####.",
 "AC....."}
1

Returns: 8

Charging is quick. We should go up, add three charges to the jetpack and fly over the longer sequence of pits.


5)
{"___B__.",
 "C#####.",
 "AC....."}
10

Returns: 31

The same maze but now charging is slower. We should take the longer route that requires less time spent on charging.

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
typedef pair<LL, LL> II;
typedef pair<II, II> IIII;

const LL INF = 1LL << 60;
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

class Jetpack {
public:
	int travel(vector <string> maze, int T) {
        LL H = maze.size(), W = maze[0].length();
        vector<vector<vector<LL>>> cost(H, vector<vector<LL>>(W, vector<LL>(2, INF)));
        int sy, sx, ey, ex;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (maze[i][j] == 'A') {
                    sy = i;
                    sx = j;
                }
                if (maze[i][j] == 'B') {
                    ey = i;
                    ex = j;
                }
            }
        }
        vector<IIII> q;
        q.emplace_back(IIII(II(0, 0), II(sy, sx)));
        while (!q.empty()) {
            vector<IIII> nq;
            auto enqueue = [&](LL y, LL x, LL f, LL next_cost) {
                if (next_cost < cost[y][x][f]) {
                    cost[y][x][f] = next_cost;
                    nq.emplace_back(IIII(II(next_cost, f), II(y, x)));
                }
            };
            for (auto kv : q) {
                LL c = kv.first.first, f = kv.first.second, y = kv.second.first, x = kv.second.second;
                if (c > cost[y][x][f]) {
                    continue;
                }
                for (int dir = 0; dir < 4; ++dir) {
                    LL ny = y + dy[dir], nx = x + dx[dir];
                    if (ny >= 0 && ny < H && nx >= 0 && nx < W) {
                        switch (maze[ny][nx]) {
                        case 'C':
                            enqueue(ny, nx, f, c + 1);
                            enqueue(ny, nx, 1, c + 1);
                            break;
                        case '_':
                            if (f) {
                                enqueue(ny, nx, f, c + 1 + T);
                            }
                            break;
                        case 'A':
                        case 'B':
                        case '.':
                            enqueue(ny, nx, f, c + 1);
	                        break;
                        }
                    }
                }
            }
            q = nq;
        }
        LL ans = min(cost[ey][ex][0], cost[ey][ex][1]);
        return ans < INF ? int(ans) : -1;
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
			string Arr0[] = {"A###B",
 "....."};
			int Arg1 = 47;
			int Arg2 = 6;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, travel(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"A#.#B",
 "..#.."};
			int Arg1 = 47;
			int Arg2 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, travel(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"A#.#B",
 ".._C."};
			int Arg1 = 1;
			int Arg2 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, travel(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"B_C_C_CA"};
			int Arg1 = 10;
			int Arg2 = 37;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, travel(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"___B__.",
 "C#####.",
 "AC....."};
			int Arg1 = 1;
			int Arg2 = 8;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, travel(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"___B__.",
 "C#####.",
 "AC....."};
			int Arg1 = 10;
			int Arg2 = 31;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, travel(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Jetpack ___test;
	___test.run_test(-1);
}
// END CUT HERE
