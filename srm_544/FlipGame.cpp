// BEGIN CUT HERE
/*
// SRM 544 Div1 Medium (500)

// PROBLEM STATEMENT
// Eel Takahashikun is playing a simple game on a rectangular board.

The rectangular board is divided into H x W unit squares. Each unit square
contains a 0 or a 1. In each operation, Takahashikun chooses a shortest path
along edges of unit squares from the upper-left corner to the lower-right
corner, and flips the numbers in all unit squares that are below the chosen
path (i.e., changes all 0s into 1s and vice versa).

For example, the following picture shows a valid operation. The squares below
the chosen path are highlighted in green.

The operation in the following picture is invalid because the path is not shortest.

You are given the initial state of the board in vector <string> board. The
j-th character of the i-th element is the number written in the unit square
at row i, column j. Rows are numbered from top to bottom, and columns are
numbered from left to right. Return the minimal number of iterations required
to change all numbers to 0s.


DEFINITION
Class:FlipGame
Method:minOperations
Parameters:vector <string>
Returns:int
Method signature:int minOperations(vector <string> board)


NOTES
-It is always possible to change all numbers to 0s by a finite number of operations.


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will contain between 1 and 50 characters, inclusive.
-Each element of board will contain the same number of characters.
-Each character in board will be '0' or '1'.


EXAMPLES

0)
{"1000",
 "1110",
 "1111"}

Returns: 1

Takahashikun can flip all 1s in one operation.


1)
{"1111",
 "1111",
 "1111"}

Returns: 1


2)
{"00",
 "00",
 "00"}

Returns: 0


3)
{"00000000",
 "00100000",
 "01000000",
 "00001000",
 "00000000"}

Returns: 4


4)
{"000000000000001100000000000000",
 "000000000000011110000000000000",
 "000000000000111111000000000000",
 "000000000001111111100000000000",
 "000000000011111111110000000000",
 "000000000111111111111000000000",
 "000000001100111111001100000000",
 "000000011000011110000110000000",
 "000000111100111111001111000000",
 "000001111111111111111111100000",
 "000011111111111111111111110000",
 "000111111111000000111111111000",
 "001111111111100001111111111100",
 "011111111111110011111111111110",
 "111111111111111111111111111111"}

Returns: 29

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
#if _MSC_VER >= 1400
#include <intrin.h>
#endif

using namespace std;

typedef long long LL;
typedef vector<LL> LLVec;

class FlipGame {

	static int find_first_set_bit_64(LL b) {
#if defined(__GNUC__) && defined(__x86_64__)
		return __builtin_ctzl(b);	// undefined for zero
#elif _MSC_VER >= 1400 && defined(_WIN64)
		unsigned long r; _BitScanForward64(&r, b); return r;
#else
		unsigned int i = 0; while (!((1LL<<i) & b)) ++i; return i;
#endif
	}

public:
	int minOperations(vector <string> board) {
		int h = (int)board.size();
		int w = (int)board[0].length();
		LLVec v(h);
		int i, j;
		for (i = 0; i < h; ++i) {
			for (j = 0; j < w; ++j) {
				v[i] <<= 1;
				v[i] |= board[i][j] - '0';
			}
		}

		int res = 0;
		while (true) {
			int left = w;
			for (i = 0; i < h; ++i) {
				int pos = left;
				if (v[i]) {
					pos = find_first_set_bit_64(v[i]);
					pos = min(pos, left);
				}
				LL mask = ~((1LL << pos) - 1) & ((1LL << w) - 1);
				v[i] ^= mask;
				left = pos;
			}
			if (left >= w) {
				break;
			}
			++res;
		}
		return res;
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
			string Arr0[] = {"1000",
 "1110",
 "1111"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minOperations(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"1111",
 "1111",
 "1111"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minOperations(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"00",
 "00",
 "00"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minOperations(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"00000000",
 "00100000",
 "01000000",
 "00001000",
 "00000000"};
			int Arg1 = 4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minOperations(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"000000000000001100000000000000",
 "000000000000011110000000000000",
 "000000000000111111000000000000",
 "000000000001111111100000000000",
 "000000000011111111110000000000",
 "000000000111111111111000000000",
 "000000001100111111001100000000",
 "000000011000011110000110000000",
 "000000111100111111001111000000",
 "000001111111111111111111100000",
 "000011111111111111111111110000",
 "000111111111000000111111111000",
 "001111111111100001111111111100",
 "011111111111110011111111111110",
 "111111111111111111111111111111"};
			int Arg1 = 29;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minOperations(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FlipGame ___test;
	___test.run_test(0);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
