// BEGIN CUT HERE
/*
TCO18 Round 3B Easy (250)

PROBLEM STATEMENT

There once was an infinite plane called Xanadu. The plane was divided into a grid of unit square cells.
The entire plane was white, with one exception: a black square.
More precisely, for some unknown positive integer N there was an N times N square that consisted of N^2 black cells.

Your friend recently showed you a rectangle. She claims that she cut it out of the Xanadu plane,
and that she was cutting along grid lines while doing so. Verify her story.

You are given the vector <string> cutout that represents a rectangular bitmap.
The character '.' represents a white cell and the character '#' represents a black cell.

If the bitmap can represent a part of the Xanadu plane, return the smallest N that is consistent with cutout.
Otherwise, return zero.


DEFINITION
Class:SquareCutout
Method:verify
Parameters:vector <string>
Returns:int
Method signature:int verify(vector <string> cutout)


CONSTRAINTS
-cutout will contain between 1 and 50 elements, inclusive.
-Each element of cutout will contain between 1 and 50 characters, inclusive.
-Each element of cutout will contain the same number of elements.
-Each character of each element of cutout will be either '.' or '#'.


EXAMPLES

0)
{".....",
 "..##.",
 "..##.",
 ".....",
 "....."}

Returns: 2

This is very clearly a cutout that contains the entire square. The length of its side is 2.

1)
{"...",
 "..."}

Returns: 1

It is possible that this is a cutout made from Xanadu. The square was simply somewhere else. The smallest size it can have is 1.

2)
{".....",
 ".###.",
 ".#.#.",
 ".###.",
 "....."}

Returns: 0

This cutout is definitely not from Xanadu. The square must be filled completely.

3)
{"..####",
 "..####",
 "......"}

Returns: 4

We may see the bottom left corner of a square. The square is at least 4x4. It may be even bigger, but 4 is the smallest size that matches what we see.

4)
{"..#..",
 ".###.",
 "#####",
 ".###.",
 "..#.."}

Returns: 0

This is not a square. This is also not a part of any larger square.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class SquareCutout {
public:
	int verify(vector <string> cutout) {
		int H = (int)cutout.size(), W = (int)cutout[0].length();
		int sx = 0, sy = 0, ex = 1, ey = 1;
		bool done = false;
		for (int y = 0; y < H; ++y) {
			for (int x = 0; x < W; ++x) {
				if (cutout[y][x] == '#') {
					if (done) {
						return 0;
					}
					sx = ex = x;
					sy = ey = y;
					done = true;
					while (ey < H && cutout[ey][x] == '#') {
						++ey;
					}
					while (ex < W && cutout[y][ex] == '#') {
						++ex;
					}
					for (int yy = sy; yy < ey; ++yy) {
						for (int xx = sx; xx < ex; ++xx) {
							if (cutout[yy][xx] != '#') {
								return 0;
							}
							cutout[yy][xx] = '-';
						}
					}
				}
			}
		}
		int width = ex - sx, height = ey - sy;
		if ((!sx || ex >= W) && width < height) {
			width = height;
		}
		if ((!sy || ey >= H) && height < width) {
			height = width;
		}
		return width == height ? width : 0;
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
			string Arr0[] = {".....",
 "..##.",
 "..##.",
 ".....",
 "....."};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, verify(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...",
 "..."};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, verify(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".....",
 ".###.",
 ".#.#.",
 ".###.",
 "....."};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, verify(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..####",
 "..####",
 "......"};
			int Arg1 = 4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, verify(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..#..",
 ".###.",
 "#####",
 ".###.",
 "..#.."};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, verify(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SquareCutout ___test;
	___test.run_test(-1);
}
// END CUT HERE
