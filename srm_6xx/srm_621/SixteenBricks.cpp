// BEGIN CUT HERE
/*
SRM 621 Div1 Easy (250)

PROBLEM STATEMENT
You have 16 bricks. Each brick has the shape of a rectangular box. You are given a vector <int> height. For each i, one of your bricks has dimensions 1 x 1 x height[i].

You also have an opaque table. You are going to place your 16 bricks onto the table in a specific way. You are not allowed to rotate the bricks while placing them: the dimension given in height must always be vertical. On the table, there is a 4 x 4 grid of squares. You have to place exactly one of your bricks onto each of the squares.

After you place all the bricks, we will look at the solid formed by them. We are interested in the visible surface area of the solid. Note that the bottom sides of your bricks are not a part of the visible surface, as they stand on the table. Also, adjacent bricks always touch each other and the parts where they touch are not visible.

Different arrangements of bricks may lead to different visible surfaces. Return the largest possible visible surface area.


DEFINITION
Class:SixteenBricks
Method:maximumSurface
Parameters:vector <int>
Returns:int
Method signature:int maximumSurface(vector <int> height)


CONSTRAINTS
-height will contain exactly 16 elements.
-Each element of height will be between 1 and 100, inclusive.


EXAMPLES

0)
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

Returns: 32

All your bricks look the same.
The only solid you can construct is a 1 x 4 x 4 box.
The bottom side of the box is not visible, the other five sides are.
The total visible surface area is 4*4 + 4*(1*4) = 32.


1)
{1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2}

Returns: 64

In order to maximize the visible surface area, you should produce a configuration in which no two bricks with height 2 share a common face.


2)
{77, 78, 58, 34, 30, 20, 8, 71, 37, 74, 21, 45, 39, 16, 4, 59}

Returns: 1798

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SixteenBricks {
public:
	int maximumSurface(vector <int> height) {
		sort(height.begin(), height.end());
		int h[6][6] = {};
		h[1][1] = height[15];
		h[1][3] = height[14];
		h[2][2] = height[13];
		h[2][4] = height[12];
		h[3][1] = height[11];
		h[3][3] = height[10];
		h[4][2] = height[9];
		h[4][4] = height[8];
		int seq[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
		int ans = 0;
		do {
			h[1][2] = height[seq[0]];
			h[1][4] = height[seq[1]];
			h[2][1] = height[seq[2]];
			h[2][3] = height[seq[3]];
			h[3][2] = height[seq[4]];
			h[3][4] = height[seq[5]];
			h[4][1] = height[seq[6]];
			h[4][3] = height[seq[7]];
			int cnt = 16;
			for (int i = 1; i <= 4; ++i) {
				for (int j = 1; j <= 4; ++j) {
					cnt += max(0, h[i][j] - h[i - 1][j]);
					cnt += max(0, h[i][j] - h[i][j - 1]);
					cnt += max(0, h[i][j] - h[i][j + 1]);
					cnt += max(0, h[i][j] - h[i + 1][j]);
				}
			}
			ans = max(ans, cnt);
		} while (next_permutation(seq, seq + 8));
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
			int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			int Arg1 = 32;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumSurface(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2};
			int Arg1 = 64;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumSurface(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {77, 78, 58, 34, 30, 20, 8, 71, 37, 74, 21, 45, 39, 16, 4, 59};
			int Arg1 = 1798;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumSurface(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SixteenBricks ___test;
	___test.run_test(-1);
}
// END CUT HERE
