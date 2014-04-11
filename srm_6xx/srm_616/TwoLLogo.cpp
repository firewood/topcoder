// BEGIN CUT HERE
/*
SRM 616 Div2 Hard (1000)

PROBLEM STATEMENT
Please note that this problem has a non-standard time limit: 3 seconds.

A yet unknown "LL Company" wants to design a logo. After a long discussion, company designers decided that the logo should consist of two letters L drawn in some way.

To start with something, designers drew N rows of M points each, one under another, so that these points form a rectangular grid. They also painted each point either white or black. Here is an example of what they could get for N = 4 and M = 5:

Designers agreed to draw each letter L as a union of a horizontal and a vertical line segment intersecting at their left and bottom ends, respectively. The segments must have positive lengths, and their endpoints must be white grid points. All grid points that lie on the segments must be white as well. For example, here are two valid placements of a letter:

Note that neither the letters nor the grid can be rotated.

The final requirement is that the two letters should be disjoint. That is, no white point should lie on two segments belonging to different letters.

You are given the grid with N rows and M columns, encoded as a vector <string> grid with N elements, each containing M characters. Each character is either '.' or '#', meaning that the corresponding point is either white or black, respectively.

Return the number of different possible logos with two L's drawn on them according to the requirements. Two logos are considered different if there is a pair of points that is connected by a line segment in exactly one of the logos.


DEFINITION
Class:TwoLLogo
Method:countWays
Parameters:vector <string>
Returns:long long
Method signature:long long countWays(vector <string> grid)


CONSTRAINTS
-grid will contain between 2 and 30 elements, inclusive.
-All elements of grid will contain the same number of characters.
-Each element of grid will contain between 2 and 30 characters, inclusive.
-Each character of grid will be either '.' or '#'.


EXAMPLES

0)
{"....",
 "...."}

Returns: 1


1)
{".##..",
 "...#.",
 ".#.#.",
 "#...#"}

Returns: 3

This is the example from the problem statement. The three possible logos look as follows:


2)
{"..#.",
 "#.#.",
 "....",
 "..#."}

Returns: 4


3)
{"..",
 ".."}

Returns: 0

Too small for a logo.


4)
{".#.#",
 "....",
 ".#.#",
 "...."}

Returns: 34


5)
{"##############",
 "##############",
 "#.############",
 "#.############",
 "#.############",
 "#.############",
 "#.############",
 "#.############",
 "#.#####.######",
 "#.#####.######",
 "#.#####.######",
 "#....##.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######......#",
 "##############"}

Returns: 1350

Corners of L's are identified uniquely in this case, but line segment lengths can vary.


6)
{"#......",
 ".#....#",
 ".#.#...",
 "#....#.",
 ".##..#.",
 ".#.....",
 ".....#.",
 ".#.#...",
 ".#...#.",
 "..##..."}

Returns: 2386


7)
{"...#..........................",
 "..............................",
 "..............................",
 "..................#...#.......",
 "..................#...........",
 "..............................",
 "...........#..................",
 "..............................",
 ".....#..#.....................",
 ".......................#......",
 "..................#.....#.....",
 "..............................",
 "..............................",
 "..............................",
 "..............................",
 "..#...........................",
 "..............................",
 "..............................",
 "..............................",
 "#............................#",
 "..............................",
 ".....#.........#............#.",
 "..............................",
 ".........................#....",
 ".#............................",
 ".............#................",
 "..............................",
 "..............................",
 ".......................#......",
 ".............#................"}

Returns: 5020791386

*/
// END CUT HERE

#include <string> 
#include <vector> 
#include <iostream> 
#include <sstream> 
#include <string.h> 

using namespace std; 

typedef long long LL;
typedef pair<int, int> II; 
typedef vector<II> IIVec; 

class TwoLLogo {

	int H;
	int W;
	int v[32][32];
	int h[32][32];

	int count(int x, int y, int hl, int vl) {
		int c = 0;
		int i, j;
		i = y;
		for (j = x + hl; j < W - 1; ++j) {
			c += h[i][j] * v[i][j];
		}
		for (--i; i > 0; --i) {
			if (i <= y-vl) {
				for (j = 0; j < W-1; ++j) {
					c += h[i][j] * v[i][j];
				}
			} else {
				for (j = 0; j <= x-2; ++j) {
					c += min(h[i][j], x-j-1) * v[i][j];
				}
				for (j = x+1; j < W-1; ++j) {
					c += h[i][j] * v[i][j];
				}
			}
		}
		return c;
	}

	public:
	long long countWays(vector <string> grid) {
		H = (int)grid.size();
		W = (int)grid[0].length();
		memset(v, 0, sizeof(v));
		memset(h, 0, sizeof(h));
		for (int i = 1; i < H; ++i) {
			const string &s = grid[i];
			for (int j = 0; j < W - 1; ++j) {
				if (s[j] == '.' && grid[i-1][j] == '.' && s[j+1] == '.') {
					for (int k = i-1; k >= 0; --k) {
						if (grid[k][j] != '.') {
							break;
						}
						v[i][j] += 1;
					}
					for (int k = j+1; k < W; ++k) {
						if (s[k] != '.') {
							break;
						}
						h[i][j] += 1;
					}
				}
			}
		}

		LL ans = 0;
		for (int i = H - 1; i >= 0; --i) {
			for (int j = 0; j < W - 1; ++j) {
				if (v[i][j] > 0) {
					for (int vl = 1; vl <= v[i][j]; ++vl) {
						for (int hl = 1; hl <= h[i][j]; ++hl) {
							ans += count(j, i, hl+1, vl+1);
						}
					}
				}
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
			string Arr0[] = {
 "....",
 "...."};
			long long Arg1 = 1LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
 ".##..",
 "...#.",
 ".#.#.",
 "#...#"};
			long long Arg1 = 3LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
 "..#.",
 "#.#.",
 "....",
 "..#."};
			long long Arg1 = 4LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
 "..",
 ".."};
			long long Arg1 = 0LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
 ".#.#",
 "....",
 ".#.#",
 "...."};
			long long Arg1 = 34LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
 "##############",
 "##############",
 "#.############",
 "#.############",
 "#.############",
 "#.############",
 "#.############",
 "#.############",
 "#.#####.######",
 "#.#####.######",
 "#.#####.######",
 "#....##.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######......#",
 "##############"};
			long long Arg1 = 1350LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
 "#......",
 ".#....#",
 ".#.#...",
 "#....#.",
 ".##..#.",
 ".#.....",
 ".....#.",
 ".#.#...",
 ".#...#.",
 "..##..."};
			long long Arg1 = 2386LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
 "...#..........................",
 "..............................",
 "..............................",
 "..................#...#.......",
 "..................#...........",
 "..............................",
 "...........#..................",
 "..............................",
 ".....#..#.....................",
 ".......................#......",
 "..................#.....#.....",
 "..............................",
 "..............................",
 "..............................",
 "..............................",
 "..#...........................",
 "..............................",
 "..............................",
 "..............................",
 "#............................#",
 "..............................",
 ".....#.........#............#.",
 "..............................",
 ".........................#....",
 ".#............................",
 ".............#................",
 "..............................",
 "..............................",
 ".......................#......",
 ".............#................"};
			long long Arg1 = 5020791386LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

	}

// END CUT HERE


};
// BEGIN CUT HERE 
int main() {
	TwoLLogo ___test;
	___test.run_test(-1);

}
// END CUT HERE

