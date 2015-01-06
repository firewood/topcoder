// BEGIN CUT HERE
/*
SRM 639 Div1 Medium (500)

Problem Statement
Little Petya likes puzzles a lot. Recently he has received one as a gift from his mother.
The puzzle has the form of a rectangular sheet of paper that is divided into N rows by M columns of unit square cells.
Rows are numbered 0 through N-1 from top to bottom, and columns 0 through M-1 from left to right.
Each cell is colored either black or white.
You are given a description of the paper, the exact format is specified at the end of this problem statement. 

The goal of the puzzle is to fold the paper. This has to be done in a sequence of turns.
In each turn, Petya has to fold the paper according to the rules below.
He can end the process after any number of turns (including zero), even if there are still valid ways to fold the paper. 

In each turn, Petya must follow these steps:
  To start folding, he must choose a line that is parallel to one of the sides of the paper and passes between two rows/columns of cells.
  He can then take the smaller part of the paper and fold it on top of the larger part.
  (If the line divides the current paper in half, he can fold either half on top of the other.)
There is one additional restriction:
  Petya may only perform the fold if all cells of the part that is being folded land on equally-colored cells of the part that remains in place. 

For example, consider the following paper (with 0 and 1 representing white and black):
10010101
11110100
00000000
01101110

Here, Petya could choose the vertical line that goes between the two leftmost columns and the rest of the paper.
Note that this is a valid choice: as he makes the fold, the cells from the leftmost two columns will all match their counterparts in the right part of the paper. This is how the paper looks like after the fold (with periods representing empty spaces):
..010101
..110100
..000000
..101110

Clearly, even after multiple folds the paper will always look like a subrectangle of the original paper.
Two states of the game are considered the same if that rectangle has the same dimensions and the same offset with respect to the original top left corner of the paper.
(Note that folding order does not matter. Two different sequences of folding may produce the same final state.) 

You are given the ints N and M.
You are also given a description of the original state of the paper in a compressed form, as a String[] compressedPaper.
Compute and return the number of possible final states of the game. 

The String[] compressedPaper will contain N elements with ceil(M/6) characters each.
Each character (except possibly the last one) encodes six cells of the paper.
The actual paper can be obtained from compressedPaper using the following pseudocode: 

for i in 0..N-1:
    for j in 0..M-1:
        paper[i][j] = (tonumber(compressedPaper[i][j / 6]) >> (j modulo 6)) modulo 2

In the above pseudocode, "/" represents integer division (rounding down), ">>" is a bit shift to the right, and tonumber(x) maps the character x to a number between 0 and 63 as follows:
the characters '0'-'9' map to integers 0-9, 'a'-'z' map to 10-35, 'A'-'Z' map to 36-61, '#' maps to 62, and '@' maps to 63. 

If paper[i][j] = 0, then the cell (i,j) is white, otherwise it is black.


Definition

Class:	BoardFolding
Method:	howMany
Parameters:	int, int, String[]
Returns:	int
Method signature:	int howMany(int N, int M, String[] compressedPaper)
(be sure your method is public)


Constraints
-	N and M will be between 1 and 250, inclusive.
-	compressedPaper will contain N elements.
-	Each element of compressedPaper will contain ceil(M / 6) elements.
-	compressedPaper will contain only characters '0'-'9', 'a'-'z', 'A'-'Z', '#' and '@'.
*/
// END CUT HERE

#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class BoardFolding {
	int H;
	int W;
	int b[256][256];
	int same[256][256];
	int l_foldable[256][256];
	int r_foldable[256][256];
	int vis[256][256];
	int ways;

	unsigned int tonumber(char c) {
		if (c >= '0' && c <= '9') {
			return c - '0';
		}
		if (c >= 'a' && c <= 'z') {
			return c - 'a' + 10;
		}
		if (c >= 'A' && c <= 'Z') {
			return c - 'A' + 36;
		}
		if (c == '#') {
			return 62;
		}
		return 63;
	}

	void dfs(int s, int e) {
		if (vis[s][e]) {
			return;
		}
		++ways;
		vis[s][e] = 1;
		int w = (e - s) / 2;
		for (int i = 1; i <= w; ++i) {
			if (r_foldable[s][i]) {
				dfs(s + i, e);
			}
		}
		for (int i = 1; i <= w; ++i) {
			if (l_foldable[e][i]) {
				dfs(s, e - i);
			}
		}
	}

	void setup(int height, int width) {
		H = height, W = width;
		memset(l_foldable, 0, sizeof(l_foldable));
		memset(r_foldable, 0, sizeof(r_foldable));
		memset(vis, 0, sizeof(vis));
		ways = 0;
		for (int i = 0; i < W; ++i) {
			same[i][i] = 0;
			for (int j = i+1; j < W; ++j) {
				int k;
				for (k = 0; k < H; ++k) {
					if (b[k][i] != b[k][j]) {
						break;
					}
				}
				same[i][j] = same[j][i] = k >= H;
			}
		}
		for (int i = 1; i < W; ++i) {
			for (int j = 1; j <= i && i+j <= W; ++j) {
				if (!same[i-j][i+j-1]) {
					break;
				}
				l_foldable[i+j][j] = 1;
				r_foldable[i-j][j] = 1;
			}
		}
	}

public:
	int howMany(int N, int M, vector <string> compressedPaper) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				b[i][j] = (tonumber(compressedPaper[i][j/6]) >> (j % 6)) & 1;
			}
		}
		setup(N, M);
		dfs(0, M);
		int ans = ways;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				b[j][i] = (tonumber(compressedPaper[i][j/6]) >> (j % 6)) & 1;
			}
		}
		setup(M, N);
		dfs(0, N);
		ans *= ways;
		return ans;
	}

// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; string Arr2[] = {"1", "3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 7; string Arr2[] = {"@@", "@@"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 84; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; string Arr2[] = {"6", "9", "9", "6"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 9; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 1; string Arr2[] = {"0", "2", "6", "@", "4", "A"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"0", "2", "0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(4, Arg3, howMany(Arg0, Arg1, Arg2)); }
// END CUT HERE
};

// BEGIN CUT HERE
int main() {
	BoardFolding ___test;
	___test.run_test(-1);
}
// END CUT HERE
