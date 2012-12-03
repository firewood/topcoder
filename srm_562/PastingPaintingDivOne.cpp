// BEGIN CUT HERE
/*
// SRM 562 Div1 Easy (250)

// PROBLEM STATEMENT
// Cucumber Boy likes drawing pictures.  Today, he plans to draw a picture using a very simple graphics editor.

The editor has the following functions:

The canvas is an infinite two-dimensional grid of pixels.
There are only four colors: red, green, blue, and transparent. These are denoted 'R', 'G', 'B', and '.' (a period), respectively.
The editor has a clipboard that contains a rectangular picture.
The editor can take the picture in the clipboard and paste it onto any corresponding rectangle of the canvas. The user just has to select the pixel of the canvas where the upper left corner of the clipboard will be pasted.
When pasting the picture, the red, green, and blue pixels of the picture in the clipboard will overwrite their corresponding pixels on the canvas. The pixels that are transparent in the clipboard picture do not change the canvas.

At this moment, all pixels on the infinite canvas are transparent.  Cucumber Boy has already stored a picture in the clipboard.  You are given this picture as a vector <string> clipboard.

Cucumber Boy now wants to paste the clipboard picture onto the canvas exactly T times in a row.  For each i, when pasting the clipboard for the i-th time, he will choose the pixel (i,i) as the upper left corner of the pasted picture.

You are given the vector <string> clipboard and the int T.  Return a vector<long long> containing exactly three elements: the number of red, green, and blue pixels on the canvas after all the pasting is finished.


DEFINITION
Class:PastingPaintingDivOne
Method:countColors
Parameters:vector <string>, int
Returns:vector<long long>
Method signature:vector<long long> countColors(vector <string> clipboard, int T)


CONSTRAINTS
-clipboard will contain between 1 and 50 elements, inclusive.
-Each element of clipboard will contain between 1 and 50 characters, inclusive.
-Each element of clipboard will contain the same number of characters.
-Each character of each element of clipboard will be one of 'R', 'G', 'B', and '.'.
-T will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{
"..G",
"R..",
"BG."
}
3

Returns: {3, 4, 3 }


1)
{
"R...",
"....",
"....",
"...R"
}
2

Returns: {4, 0, 0 }


2)
{"RGB"}
100000

Returns: {100000, 100000, 100000 }


3)
{"."}
1000000000

Returns: {0, 0, 0 }


4)
{
"RB.",
".G."
}

100

Returns: {100, 1, 100 }


5)
{
"..........G..........",
".........G.G.........",
"........G...G........",
".......G.....G.......",
"......G..B.B..G......",
".....G...B.B...G.....",
"....G...........G....",
"...G...R.....R...G...",
"..G.....RRRRRR....G..",
".G..........RR.....G.",
"GGGGGGGGGGGGGGGGGGGGG"
}
1000000000

Returns: {2000000018, 17000000048, 2000000005 }

Note that the answers may overflow a 32-bit integer variable.


This is the image of clipboard in this example.

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
typedef vector<LL> LLVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;

class PastingPaintingDivOne {

public:
	vector<long long> countColors(vector <string> clipboard, int T) {
		LLVec res(3);

		int tbl[128];
		tbl['.'] = -1;
		tbl['R'] = 0;
		tbl['G'] = 1;
		tbl['B'] = 2;

		int i, j, k, color;
		for (i = 0; i < (int)clipboard.size(); ++i) {
			for (j = 0; j < (int)clipboard[0].length(); ++j) {
				color = tbl[clipboard[i][j]];
				if (color >= 0) {
					int cnt = T;
					for (k = 1; k <= T; ++k) {
						if (k > i || k > j) {
							break;
						}
						if (tbl[clipboard[i-k][j-k]] >= 0) {
							cnt = k;
							break;
						}
					}
					res[color] += cnt;
				}
			}
		}

		return res;
	}


// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"..G",
"R..",
"BG."
};
			int Arg1 = 3;
			long Arr2[] = {3, 4, 3 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, countColors(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"R...",
"....",
"....",
"...R"
};
			int Arg1 = 2;
			long Arr2[] = {4, 0, 0 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, countColors(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"RGB"};
			int Arg1 = 100000;
			long Arr2[] = {100000, 100000, 100000 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, countColors(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"."};
			int Arg1 = 1000000000;
			long Arr2[] = {0, 0, 0 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, countColors(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"RB.",
".G."
}
;
			int Arg1 = 100;
			long Arr2[] = {100, 1, 100 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, countColors(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"..........G..........",
".........G.G.........",
"........G...G........",
".......G.....G.......",
"......G..B.B..G......",
".....G...B.B...G.....",
"....G...........G....",
"...G...R.....R...G...",
"..G.....RRRRRR....G..",
".G..........RR.....G.",
"GGGGGGGGGGGGGGGGGGGGG"
};
			int Arg1 = 1000000000;
			LL Arr2[] = {2000000018LL, 17000000048LL, 2000000005LL };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, countColors(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PastingPaintingDivOne ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
