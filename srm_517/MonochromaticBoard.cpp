// BEGIN CUT HERE
/*
// SRM 517 Div2 Easy (250)
// PROBLEM STATEMENT
// There is a HxW rectangular board divided into 1x1 cells. Initially each cell is colored White.
Fox Ciel wants to change the color of certain cells on the board.
You are given a vector <string> board consisting of characters 'B' and 'W'.
If the j-th character of the i-th element of board is 'B', she must change the color of cell (i, j) to Black,
otherwise this cell must remain White.


Fox Ciel can perform the following operation:


1. Choose one row or one column.

2. Paint the row or the column she chose in step 1 with Black.
The color of all cells in the row or the column becomes Black.


Return the minimal number of operations required to change the color to board.
The constraints will guarantee that it's always possible.

DEFINITION
Class:MonochromaticBoard
Method:theMin
Parameters:vector <string>
Returns:int
Method signature:int theMin(vector <string> board)


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will contain the same number of characters.
-Each element of board will contain between 1 and 50 characters, inclusive.
-Each character in board will be 'W' or 'B'.
-board can be obtained by performing the operation described in the statement 0 or more times.


EXAMPLES

0)
{"WBWBW",
 "BBBBB",
 "WBWBW",
 "WBWBW"}

Returns: 3

Paint?row?1?(0-indexed),?column?1?and?column?3.

1)
{"BBBB",
 "BBBB",
 "BBBB"}

Returns: 3

Paint?all?rows.

2)
{"BBBBB",
 "BBBBB",
 "BBBBB",
 "BBBBB",
 "BBBBB",
 "BBBBB",
 "BBBBB",
 "BBBBB"}

Returns: 5

Paint?all?columns.

3)
{"WW",
 "WW"}

Returns: 0



4)
{"BBBBBBBB",
 "BBBBBBBB",
 "BBBBBBBB",
 "WBWBBBWB",
 "BBBBBBBB"}

Returns: 9



#line 89 "MonochromaticBoard.cpp"
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

class MonochromaticBoard {
	public:
	int theMin(vector <string> board) {
		if (board.size() < 1) {
			return 0;
		}

		int Width = board[0].length();
		int Height = board.size();

		bool rows[64] = {0};
		bool columns[64] = {0};
		char b[64][64] = {0};
		int x, y;
		for (y = 0; y < Height; ++y) {
			strcpy(b[y], board[y].c_str());
			for (x = 0; x < Width; ++x) {
				if (b[y][x] == 'B') {
					rows[y] = true;
					columns[x] = true;
				}
			}
		}
		bool has_white = false;
		for (y = 0; y < Height; ++y) {
			for (x = 0; x < Width; ++x) {
				if (b[y][x] == 'W') {
					has_white = true;
					rows[y] = false;
					columns[x] = false;
				}
			}
		}

		if (!has_white) {
			return min(Width, Height);
		}

		int p = 0;
		for (x = 0; x < Width; ++x) {
			p += columns[x];
		}
		for (y = 0; y < Height; ++y) {
			p += rows[y];
		}
		return p;
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
	vector <string> v = getVector<string>(seq);
	MonochromaticBoard ___test;
	int result = ___test.theMin(v);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	Test("WBWBW BBBBB WBWBW WBWBW", 3);
	Test("BBBB BBBB BBBB", 3);
	Test("BBBBB BBBBB BBBBB BBBBB BBBBB BBBBB BBBBB BBBBB", 5);
	Test("WW WW", 0);
	Test("BBBBBBBB BBBBBBBB BBBBBBBB WBWBBBWB BBBBBBBB", 9);
	return 0;
}
// END CUT HERE
