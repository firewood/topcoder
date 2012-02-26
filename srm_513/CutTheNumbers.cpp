// BEGIN CUT HERE
/*
// SRM 513 Div2 Hard (1000)

// PROBLEM STATEMENT
// Manao has a board filled with digits represented as vector <string> board.
The j-th character of the i-th element of board represents the digit
written in cell in row i, column j of the board. The rows are numbered from
top to bottom and the columns are numbered from left to right.

Manao is going to cut it into several non-overlapping fragments. Each of the
fragments will be a horizontal or vertical strip containing 1 or more elements.
A strip of length N can be interpreted as an N-digit number in base 10 by
concatenating the digits on the strip in order. The horizontal strips are read
from left to right and the vertical strips are read from top to bottom.
The picture below shows a possible cutting of a 4x4 board:

4937
2591
3846
9150

The sum of the numbers on the fragments in this picture is
493 + 7160 + 23 + 58 + 9 + 45 + 91 = 7879.

Manao wants to cut the board in such a way that the sum of the numbers on the
resulting fragments is the maximum possible. Compute and return this sum.

DEFINITION
Class:CutTheNumbers
Method:maximumSum
Parameters:vector <string>
Returns:int
Method signature:int maximumSum(vector <string> board)


NOTES
-The numbers on the cut strips are allowed to have leading zeros. See example #2 for details.


CONSTRAINTS
-board will contain between 1 and 4 elements, inclusive.
-board[0] will be between 1 and 4 characters long, inclusive.
-Each element of board will be of the same length as board[0].
-Each character in board will be a decimal digit ('0'-'9').


EXAMPLES

0)
{"123",
 "312"}

Returns: 435

Manao can cut out both rows in whole, obtaining 123 + 312 = 435. He also could
cut the columns one by one for a total of 66, or cut the first column and
the residual rows one by one, obtaining 13 + 23 + 12 = 48, or even cut out
single elements, but would not get a better sum.


1)
{"99",
 "11"}

Returns: 182

It's better to cut out the whole columns.


2)
{"001",
 "010",
 "111",
 "100"}

Returns: 1131

The numbers on the strips may have leading zeros. Cutting the columns in whole,
Manao obtains 0011 + 0110 + 1010 = 1131.


3)
{"8"}

Returns: 8

*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

typedef vector<string> StrVec;

class CutTheNumbers {
	int w;
	int h;
	int n[4][4];
	int memo[65536];

	int _rec(int x, int y, int b) {
		int res = 0;
		int filled = b;
		int m = 1 << (y*4+x);
		int sum = 0;
		int i;
		for (i = x; i < w; ++i) {
			if (b & m) {
				break;
			}
			sum = sum * 10 + n[y][i];
			filled |= m;
			m <<= 1;
			res = max(res, sum + rec(filled));
		}
		filled = b;
		m = 1 << (y*4+x);
		sum = 0;
		for (i = y; i < h; ++i) {
			if (b & m) {
				break;
			}
			sum = sum * 10 + n[i][x];
			filled |= m;
			m <<= 4;
			res = max(res, sum + rec(filled));
		}
		return res;
	}

	int rec(int b) {
		int &res = memo[b];
		if (res < 0) {
			res = 0;
			int x, y;
			for (y = 0; y < h; ++y) {
				for (x = 0; x < w; ++x) {
					int m = 1 << (y*4+x);
					if ((b & m) == 0) {
						return res = _rec(x, y, b);
					}
				}
			}
		}
		return res;
	}

public:
	int maximumSum(vector <string> board) {
		memset(n, 0, sizeof(n));
		memset(memo, -1, sizeof(memo));
		w = board[0].length();
		h = board.size();
		int i, j;
		for (i = 0; i < h; ++i) {
			for (j = 0; j < w; ++j) {
				n[i][j] = board[i][j] - '0';
			}
		}
		return rec(0);
	}
};

// BEGIN CUT HERE
template <typename T> static T __str_to_val(const char *p)
{
	return p;
}
template <> static int __str_to_val(const char *p)
{
	return atoi(p);
}
template <typename T> vector<T> getVector(const char *s)
{
	static const int buffer_size = 1024000;
	static char buffer[buffer_size];
	strcpy(buffer, s);
	vector <T> v;
	char *p = strtok(buffer, " ,");
	while (p) {
		v.push_back(__str_to_val<T>(p));
		p = strtok(NULL, " ,");
	}
	return v;
}

static void Test(const char *seq, int expected)
{
	StrVec v = getVector<string>(seq);
	CutTheNumbers ___test;
	int result = ___test.maximumSum(v);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	Test("123 312", 435);
	Test("99 11", 182);
	Test("001 010 111 100", 1131);
	Test("8", 8);

	Test("4937 2591 3846 9150", 24925);

	return 0;
}
// END CUT HERE
