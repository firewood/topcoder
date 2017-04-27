// BEGIN CUT HERE
/*
SRM 713 Div2 Easy (250)

PROBLEM STATEMENT
Fox Ciel has a rectangular board divided into n rows by m columns of unit square cells.
Rows are numbered 0 through n-1 from top to bottom and columns are numbered 0 through m-1 from left to right.
Each cell is either white or black.
You are given a vector <string> board containing the description of the board.
The character board[i][j] represents the cell in row i, column j.
The character '#' represents a black cell and '.' represents a white cell.

The board is called horizontally symmetric if it remains the same when flipped around a horizontal line that goes through the center of the board.
If n is odd, this line goes through the middle of row (n-1)/2.
If n is even, the line goes between rows (n/2)-1 and (n/2).

Similarly, the board is called vertically symmetric if it remains the same when flipped around a vertical line that goes through the center of the board.

Please help Ciel determine the types of symmetry of her board.
Return one of the following four strings:

"Both" if Ciel's board is both horizontally and vertically symmetric.
"Horizontally symmetric" if Ciel's board is horizontally symmetric but not vertically symmetric.
"Vertically symmetric" if Ciel's board is vertically symmetric but not horizontally symmetric.
"Neither" otherwise.

Note that the quotes are for clarity only. Also note that the return value is case-sensitive.


DEFINITION
Class:SymmetryDetection
Method:detect
Parameters:vector <string>
Returns:string
Method signature:string detect(vector <string> board)


NOTES
-The values n and m are not given explicitly. Instead, you can determine n as the number of elements in board and m as the length of any element in board.


CONSTRAINTS
-n, m will be between 1 and 50, inclusive.
-board will contain exactly n elements.
-Each element in board will have exactly m characters.
-Each character in board will be '#' or '.'.


EXAMPLES

0)
{"#####",
 ".###.",
 "..#.."}

Returns: "Vertically symmetric"

If we flip this board according to the vertical line that goes through the middle of column 2, we will get exactly the same board.
On the other hand, if we flip it according to the horizontal line that goes through the middle of row 1, we will get the following shape:


..#..
.###.
#####


This is not the same board, which means that this board isn't horizontally symmetric.


1)
{"#####",
 "#...#",
 "#####"}

Returns: "Both"

This time it is both horizontally and vertically symmetric.


2)
{"#..",
 "#..",
 "#.."}

Returns: "Horizontally symmetric"


3)
{"#.",
 ".#"}

Returns: "Neither"


4)
{"#######",
 "#..#..#",
 "#######",
 "...#...",
 "#######"}

Returns: "Vertically symmetric"


5)
{"#.....#",
 "#.....#",
 "#######",
 "#...#.#",
 "#.....#"}

Returns: "Neither"


6)
{"#######.#.....#",
 "...#....#.....#",
 ".#####..#######",
 "...#....#.....#",
 "#######.#.....#"}

Returns: "Horizontally symmetric"


7)
{"."}

Returns: "Both"


*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

// BEGIN CUT HERE
/*
typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<II> IIVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;
typedef set<II> IISet;
typedef set<string> StrSet;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
#define MOD 1000000007LL
#define MOD 1000000009LL
*/
// END CUT HERE

class SymmetryDetection {
public:
	string detect(vector <string> board) {
		int h = (int)board.size(), w = (int)board[0].length();
		bool hs = true, vs = true;
		for (int i = 0; i <= h / 2; ++i) {
			for (int j = 0; j < w; ++j) {
				if (board[i][j] != board[h - i - 1][j]) {
					hs = false;
				}
			}
		}
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j <= w / 2; ++j) {
				if (board[i][j] != board[i][w-j-1]) {
					vs = false;
				}

			}
		}
		if (hs) {
			return vs ? "Both" : "Horizontally symmetric";
		}
		return vs ? "Vertically symmetric" : "Neither";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#####",
 ".###.",
 "..#.."};
			string Arg1 = "Vertically symmetric";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, detect(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#####",
 "#...#",
 "#####"};
			string Arg1 = "Both";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, detect(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#..",
 "#..",
 "#.."};
			string Arg1 = "Horizontally symmetric";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, detect(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#.",
 ".#"};
			string Arg1 = "Neither";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, detect(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#######",
 "#..#..#",
 "#######",
 "...#...",
 "#######"};
			string Arg1 = "Vertically symmetric";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, detect(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#.....#",
 "#.....#",
 "#######",
 "#...#.#",
 "#.....#"};
			string Arg1 = "Neither";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, detect(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#######.#.....#",
 "...#....#.....#",
 ".#####..#######",
 "...#....#.....#",
 "#######.#.....#"};
			string Arg1 = "Horizontally symmetric";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, detect(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"."};
			string Arg1 = "Both";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, detect(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SymmetryDetection ___test;
	___test.run_test(-1);
}
// END CUT HERE
