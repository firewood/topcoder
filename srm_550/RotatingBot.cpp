// BEGIN CUT HERE
/*
// SRM 550 Div1 Easy (250)

// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly
if viewed outside of the applet.

We had a rectangular grid that consisted of W x H square cells.
We placed a robot on one of the cells.
The robot then followed the rules given below.

Initially, the robot is facing east.
The robot moves in steps. In each step it moves to the adjacent cell in the
direction it currently faces.
The robot may not leave the grid.
The robot may not visit the same cell twice. (This also means that it may not
reenter the starting cell.)
If a step forward does not cause the robot to break the above rules, the robot
takes the step.
Otherwise, the robot rotates 90 degrees to the left (counter-clockwise) and
checks whether a step forward still breaks the above rules.
If not, the robot takes the step and continues executing this program (still
rotated in the new direction).
If the rotation left did not help, the robot terminates the execution of this program.
We can also terminate the execution of the program manually, at any moment.

For example, the following seven images show a series of moves made by the robot in a 12 x 11 board:

We forgot the dimensions of the grid and the original (x,y) coordinates of the
cell on which the robot was originally placed, but we do remember its movement.
You are given a vector <int> moves. This sequence of positive integers shall
be interpreted as follows:
The robot performed moves[0] steps eastwards, turned left, performed moves[1]
steps northwards, turned left, and so on.
After performing the last sequence of steps, the robot stopped. (Either it
detected that it should terminate, or we stopped it manually.) We are not sure
if the sequence of moves is valid. If the sequence of moves is impossible,
return -1. Else, return the minimum area of a grid in which the sequence of
moves is possible.
(I.e., the return value is the smallest possible value of the product of W and H.).


DEFINITION
Class:RotatingBot
Method:minArea
Parameters:vector <int>
Returns:int
Method signature:int minArea(vector <int> moves)


CONSTRAINTS
-moves will contain between 1 and 50 elements, inclusive.
-Each element of moves will be between 1 and 50, inclusive.


EXAMPLES

0)
{15}

Returns: 16

The smallest valid board is a 16x1 board, with the robot starting on the west end of the board.


1)
{3,10}

Returns: 44

The smallest solution is to place the robot into the southwest corner of a 4 x 11 board.


2)
{1,1,1,1}

Returns: -1

This sequence of moves is not possible because the robot would return to its initial location which is forbidden.


3)
{9,5,11,10,11,4,10}

Returns: 132

These moves match the image from the problem statement.


4)
{12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15}

Returns: 420


5)
{8,6,6,1}

Returns: -1


6)
{8,6,6}

Returns: 63


7)
{5,4,5,3,3}

Returns: 30

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

static const int dx[4] = {1,0,-1,0};
static const int dy[4] = {0,-1,0,1};

class RotatingBot {

public:
	int minArea(vector <int> moves) {
		int x = 64, y = 64;
		int minX = x, maxX = x, minY = y, maxY = y;
		int sz = (int)moves.size();
		int i, j;
		for (i = 0; i < sz; ++i) {
			x += dx[i%4] * moves[i];
			y += dy[i%4] * moves[i];
			minX = min(minX, x);
			maxX = max(maxX, x);
			minY = min(minY, y);
			maxY = max(maxY, y);
		}
		int W = maxX - minX;
		int H = maxY - minY;
		if (W > 50 || H > 50) {
			return -1;
		}
		int f[128][128] = {};
		for (i = 0; i < 128; ++i) {
			f[minY-1][i] = 1;
			f[maxY+1][i] = 1;
			f[i][minX-1] = 1;
			f[i][maxX+1] = 1;
		}
		x = 64, y = 64;
		f[y][x] = 1;
		for (i = 0; i < sz; ++i) {
			for (j = 0; j < moves[i]; ++j) {
				x += dx[i%4];
				y += dy[i%4];
				if (f[y][x]) {
					return -1;
				}
				f[y][x] = 1;
			}
			if (i == (sz-1)) {
				break;
			}
			if (!f[y + dy[i%4]][x + dx[i%4]]) {
				return -1;
			}
		}
		return (W+1)*(H+1);
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
			int Arr0[] = {15};
			int Arg1 = 16;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minArea(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,10};
			int Arg1 = 44;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minArea(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1};
			int Arg1 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minArea(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9,5,11,10,11,4,10};
			int Arg1 = 132;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minArea(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15};
			int Arg1 = 420;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minArea(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8,6,6,1};
			int Arg1 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minArea(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8,6,6};
			int Arg1 = 63;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minArea(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,4,5,3,3};
			int Arg1 = 30;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minArea(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RotatingBot ___test;
	___test.run_test(3);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
