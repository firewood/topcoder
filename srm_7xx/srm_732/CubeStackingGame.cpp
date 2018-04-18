// BEGIN CUT HERE
/*
SRM 732 Div2 Medium (500)

PROBLEM STATEMENT

You recently designed the Cube Stacking Game.
This is a single-player puzzle.
All you need to play the game is a collection of cubes, as described below.

You have n cubes.
The cubes are numbered from 0 to n-1.
Each face of each cube has a single color.
There are n+1 colors.
One of the colors is white and has number 0.
The remaining colors have numbers 1 to n.

Each cube has exactly two white faces, and these are always two opposite faces.
Let's number the remaining faces on each cube 1, 2, 3, 4 in adjacent order.
(That is, face 1 is adjacent to 2, 2 to 3, 3 to 4, and 4 to 1.)
For each cube, you are given the colors of these four faces:
on cube i these faces have colors c1[i], c2[i], c3[i] and c4[i], in order.
Remember that these faces are never white.

You want to build a single stack of cubes with cube 0 on the bottom, cube 1 on top of cube 0, and so on.
(I.e., you have to use the cubes in the given order, starting with 0, and you are not allowed to skip any cube.)

The cubes have to be aligned to form a single stack with four vertical sides.
You may rotate the cubes arbitrarily but you must place them onto the stack in such a way that the top and bottom face of each cube will be white.
On each of the four sides of the stack each color can only appear at most once.

Calculate and return the maximum height of a valid stack that can be built out of the given cubes.


DEFINITION
Class:CubeStackingGame
Method:MaximumValue
Parameters:int, vector <int>, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int MaximumValue(int n, vector <int> c1, vector <int> c2, vector <int> c3, vector <int> c4)


CONSTRAINTS
-n will be between 2 and 8, inclusive.
-Each of c1, c2, c3, c4 will contain exactly n elements.
-Each element of c1 will be between 1 and n, inclusive.
-Each element of c2 will be between 1 and n, inclusive.
-Each element of c3 will be between 1 and n, inclusive.
-Each element of c4 will be between 1 and n, inclusive.


EXAMPLES

0)
2
{1,1}
{2,1}
{1,2}
{2,2}

Returns: 1

You can place cube 0 arbitrarily but won't be able to place cube 1 on top of it.
Regarless of how you rotate cube 1, there will always be a side of the stack where both cubes have color 1.
Thus, the tallest valid stack consists of just a single cube.


1)
2
{1,2}
{1,2}
{1,2}
{1,2}

Returns: 2

Here you can place cube 1 onto cube 0 in any way you like, the result will always look the same: a stack of height 2 where on each side you can see a square of color 1 and a square of color 2.


2)
2
{1,1}
{1,2}
{1,2}
{1,2}

Returns: 1


3)
2
{1,1}
{2,2}
{1,1}
{2,2}

Returns: 2


4)
2
{1,1}
{1,2}
{2,2}
{2,1}

Returns: 2

Theoretically one could use cubes 0, 2, and 3 to form a stack of height 3. However, such a stack is not valid because we are not allowed to skip cubes. And as there is no valid way of placing cube 1 onto cube 0, the tallest valid stack only has height 1.


5)
4
{1,1,3,4}
{1,2,3,4}
{1,3,3,4}
{1,4,3,4}

Returns: 1

We can stack up three cubes (cube 1, 3, and 4) with no duplicate colors on the sides, but we cannot skip cube 2.


6)
4
{1,1,1,1}
{2,2,2,4}
{3,3,3,3}
{4,4,4,2}

Returns: 4

Here we can build a valid stack that will contain all four cubes. Note that in order to do so we need to flip cube 3 "upside down".

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class CubeStackingGame {
	int n;
	int c[8][4];

	int getColor(int row, int column, int shift) {
		return c[row][(column * (shift < 4 ? 1 : -1) + shift + 4) % 4];
	}

	int dfs(vector<int> v) {
		int sz = (int)v.size();
		int r = sz;
		if (sz < n) {
			for (int i = 0; i < 8; ++i) {
				bool ok = true;
				for (int j = 0; ok && j < sz; ++j) {
					for (int k = 0; k < 4; ++k) {
						if (getColor(j, k, v[j]) == getColor(sz, k, i)) {
							ok = false;
						}
					}
				}
				if (ok) {
					vector<int> t = v;
					t.push_back(i);
					r = max(r, dfs(t));
				}
			}
		}
		return r;
	}

public:
	int MaximumValue(int n, vector <int> c1, vector <int> c2, vector <int> c3, vector <int> c4) {
		this->n = n;
		for (int i = 0; i < n; ++i) {
			c[i][0] = c1[i], c[i][1] = c2[i], c[i][2] = c3[i], c[i][3] = c4[i];
		}
		return dfs({ 0 });
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
			int Arg0 = 2;
			int Arr1[] = {1,1};
			int Arr2[] = {2,1};
			int Arr3[] = {1,2};
			int Arr4[] = {2,2};
			int Arg5 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg5, MaximumValue(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {1,2};
			int Arr2[] = {1,2};
			int Arr3[] = {1,2};
			int Arr4[] = {1,2};
			int Arg5 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg5, MaximumValue(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {1,1};
			int Arr2[] = {1,2};
			int Arr3[] = {1,2};
			int Arr4[] = {1,2};
			int Arg5 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg5, MaximumValue(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {1,1};
			int Arr2[] = {2,2};
			int Arr3[] = {1,1};
			int Arr4[] = {2,2};
			int Arg5 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg5, MaximumValue(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {1,1};
			int Arr2[] = {1,2};
			int Arr3[] = {2,2};
			int Arr4[] = {2,1};
			int Arg5 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg5, MaximumValue(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {1,1,3,4};
			int Arr2[] = {1,2,3,4};
			int Arr3[] = {1,3,3,4};
			int Arr4[] = {1,4,3,4};
			int Arg5 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg5, MaximumValue(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {1,1,1,1};
			int Arr2[] = {2,2,2,4};
			int Arr3[] = {3,3,3,3};
			int Arr4[] = {4,4,4,2};
			int Arg5 = 4;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg5, MaximumValue(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 5;
			int Arr1[] = { 5, 2, 3, 4, 5 };
			int Arr2[] = { 4, 2, 3, 4, 2 };
			int Arr3[] = { 2, 1, 1, 5, 2 };
			int Arr4[] = { 1, 1, 4, 2, 1 };
			int Arg5 = 3;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg5, MaximumValue(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CubeStackingGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
