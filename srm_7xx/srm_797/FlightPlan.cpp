// BEGIN CUT HERE
/*
SRM 797 Div1 Easy (250)

PROBLEM STATEMENT

There is a horizontal rectangular board with R rows and C columns of unit squares.

A three-dimensional world is built on top of this board: on each square of the board there is a stack of zero or more unit cubes.
The number of cubes on the square (r, c) is H[r*C + c].

We have a helicopter. The helicopter is negligibly tiny in comparison to the unit cubes that form the world, so we'll pretend it's a point. The helicopter is currently standing in the middle of the top face of the stack of cubes on square (0, 0). 

We want to get the helicopter to land in the opposite corner of the board: in the middle of the top face of the stack of cubes at coordinates (R-1, C-1).

The helicopter can move in three ways: it can fly up, down, or sideways. Each time it moves, it must move by exactly 1 unit of distance. Flying an unit of distance upwards costs cup, flying the same distance downwards costs cdn,
and flying an unit of distance sideways costs clr. When flying sideways, the direction of travel must be one of the four cardinal directions, so after each move the helicopter will be hovering over the center of one of the unit squares.

Obviously, the helicopter cannot leave the board and it cannot fly into a stack of cubes. It can fly while touching the top surface of a stack of cubes, so for example the helicopter's first move can be sideways as long as it goes into a square that doesn't have a higher stack of cubes. 

Calculate and return the minimum total cost of reaching the helicopter's destination.


DEFINITION
Class:FlightPlan
Method:fly
Parameters:int, int, vector <int>, int, int, int
Returns:long long
Method signature:long long fly(int R, int C, vector <int> H, int cup, int cdn, int clr)


CONSTRAINTS
-R will be between 1 and 50, inclusive.
-C will be between 1 and 50, inclusive.
-H will contain exactly R * C elements.
-Each element of H will be between 0 and 10^6, inclusive.
-cup, cdn and clr will each be between 1 and 10^6, inclusive.


EXAMPLES

0)
1
5
{10, 8, 6, 8, 10}
40
10
20

Returns: 80

This world has just a single row. The helicopter both starts and wants to end in height 10, and as there are no obstacles in its way, the cheapest solution is to simply fly horizontally (i.e., to the next column) four times.

1)
6
1
{10, 8, 16, 18, 8, 12}
40
10
20

Returns: 480

One optimal solution looks as follows:

Start in row 0, column 0, with starting altitude 10.
Fly to the next row. (This costs 20 and results in a helicopter hovering 2 units of distance above the surface at this point.)
Fly 6 units upwards. (Cost 240, now the helicopter's altitude is 16.)
Fly to the next row. (Cost 20. We are now in the middle row and we are touching its surface.)
Fly another 2 units upwards. (Cost 80, now the helicopter's altitude is 18.)
Fly two units to the right. (Cost 40.)
Fly 6 units down. (Cost 60. We are now in row 0, column 4 and our altitude is 12.
Fly one unit to the right (cost 20), and as we have exactly the correct altitude, terminate. 


The total cost is 480.


2)
5
5
{  100, 1000,  100,  100,  100,
    97, 9999, 9999, 9999,  100,
    93, 9999,    0, 9999,  100,
    99, 9999,   83,   65,  100,
    98,   93,   90, 9999,   95}
1000
1000
1

Returns: 5010

Flying up and down is very expensive. It's better to take a longer route, starting by moving from row 0 to row 1.

3)
5
5
{  100, 1000,  100,  100,  100,
    97, 9999, 9999, 9999,  100,
    93, 9999,    0, 9999,  100,
    99, 9999,   83,   65,  100,
    98,   93,   90, 9999,   95}
1
1
1000

Returns: 9805

The same map but now horizontal movement is expensive. Here it's better to travel through the square (0, 4).

4)
1
1
{47}
123
234
345

Returns: 0

The obligatory example illustrating that travel starting and finishing at the same spot has cost 0.

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
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;

const LL INF = 1LL << 60;
const int dy[4] = { 0, -1, 0, 1 };
const int dx[4] = { -1, 0, 1, 0 };

class FlightPlan {
public:
	long long fly(int R, int C, vector <int> H, int cup, int cdn, int clr) {
		LL ans = R * C <= 1 ? 0 : INF;
		LL sh = H.front(), eh = H.back();
		for (int i = 0; i < R * C; ++i) {
			LL h = H[i];
			if (h < sh || h < eh) continue;
			vector<II> q({ {0,0} });
			vector<vector<int>> vis(R, vector<int>(C));
			for (LL t = 0; !q.empty(); ++t) {
				vector<II> nq;
				for (auto kv : q) {
					int y = kv.first, x = kv.second;
					if (y == R - 1 && x == C - 1) {
						ans = min(ans, cup * (h - sh) + cdn * (h - eh) + clr * t);
						nq.clear();
						break;
					}
					for (int dir = 0; dir < 4; ++dir) {
						int ny = y + dy[dir], nx = x + dx[dir];
						if (ny >= 0 && ny < R && nx >= 0 && nx < C && !vis[ny][nx] && h >= H[C * ny + nx]) {
							vis[ny][nx] = 1;
							nq.emplace_back(II(ny, nx));
						}
					}
				}
				q = nq;
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 5;
			int Arr2[] = {10, 8, 6, 8, 10};
			int Arg3 = 40;
			int Arg4 = 10;
			int Arg5 = 20;
			long long Arg6 = 80LL;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg6, fly(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 1;
			int Arr2[] = {10, 8, 16, 18, 8, 12};
			int Arg3 = 40;
			int Arg4 = 10;
			int Arg5 = 20;
			long long Arg6 = 480LL;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg6, fly(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 5;
			int Arr2[] = {  100, 1000,  100,  100,  100,
    97, 9999, 9999, 9999,  100,
    93, 9999,    0, 9999,  100,
    99, 9999,   83,   65,  100,
    98,   93,   90, 9999,   95};
			int Arg3 = 1000;
			int Arg4 = 1000;
			int Arg5 = 1;
			long long Arg6 = 5010LL;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg6, fly(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 5;
			int Arr2[] = {  100, 1000,  100,  100,  100,
    97, 9999, 9999, 9999,  100,
    93, 9999,    0, 9999,  100,
    99, 9999,   83,   65,  100,
    98,   93,   90, 9999,   95};
			int Arg3 = 1;
			int Arg4 = 1;
			int Arg5 = 1000;
			long long Arg6 = 9805LL;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg6, fly(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arr2[] = {47};
			int Arg3 = 123;
			int Arg4 = 234;
			int Arg5 = 345;
			long long Arg6 = 0LL;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg6, fly(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FlightPlan ___test;
	___test.run_test(-1);
}
// END CUT HERE
