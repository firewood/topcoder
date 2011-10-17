// BEGIN CUT HERE
/*
// SRM 517 Div2 Easy (250)

問題
  HxW のセルからなるボードがある。初期値は白である。
  白か黒からなるボードの状態が与えられる。
  その状態に塗るための最小の手数を答える。

#line 89 "MonochromaticBoard.cpp"
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

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

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
			// paint all rows
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
	// example 0
	Test("WBWBW BBBBB WBWBW WBWBW", 3);

	// example 1
	Test("BBBB BBBB BBBB", 3);

	// example 2
	Test("BBBBB BBBBB BBBBB BBBBB BBBBB BBBBB BBBBB BBBBB", 5);

	// example 3
	Test("WW WW", 0);

	// example 4
	Test("BBBBBBBB BBBBBBBB BBBBBBBB WBWBBBWB BBBBBBBB", 9);

	return 0;
}
// END CUT HERE
