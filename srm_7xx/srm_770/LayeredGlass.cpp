// BEGIN CUT HERE
/*
SRM 770 Div2 Medium (500)

PROBLEM STATEMENT
You are working in a glass factory, that assembles layered glass, where two pieces of square glass are layered together to create a single, stronger pane of glass.

Unfortunately, the glass sometimes has defects... and a defect in either layer results in a defect to the finished product. However, as the pieces are square, they can be flipped and rotated in whatever way is optimal to minimize the number of defects in the finished product when the layers are put together.

The two pieces are glass are defined in vector <string>s a and b. Each character of each string will be '.' to indicate a good area, or 'X' to indicate a defective area.

Return the minimum number of defective areas in the final layered product, assuming the two layers are rotated and flipped optimally.

DEFINITION
Class:LayeredGlass
Method:minDefects
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int minDefects(vector <string> a, vector <string> b)


NOTES
-Both pieces of glass are square, that is, the number of strings in each array will be the same as the number of characters in each string.


CONSTRAINTS
-a will have between 1 and 50 elements, inclusive.
-a and b will contain the same number of elements.
-a and b will both define a square.
-Each character of each element of a and b will be '.' or 'X'.


EXAMPLES

0)
{"X.",
 ".."}
{"..",
 ".X"}

Returns: 1

Each layer has a defect, but if we rotate them properly, they line up, leaving only a single defect in the finished product.


1)
{"...",
 "..X",
 "..."}
{"X..",
 "...",
 "..."}

Returns: 2

No matter what we do, both defects will appear separately in the finished product.


2)
{"...",
 "...",
 "..."}
{"...",
 ".XX",
 "..."}

Returns: 2

One layer of glass is perfect, but the other layer has two defects, regardless.


3)
{".XX",
 "...",
 "..."}
{"X..",
 "...",
 "X.."}

Returns: 3


4)
{"XX..",
 "X...",
 "XX..",
 "X..."}
{"XXXX",
 "X.X.",
 "....",
 "...."}

Returns: 6

Note that you can also flip the panes, not just rotate them.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

vector <string> rotate(const vector <string>& a) {
	if (a.empty()) {
		return a;
	}
	int h = a.size(), w = a[0].length();
	vector <string> b(w, string(h, ' '));
	for (int r = 0; r < w; ++r) {
		for (int c = 0; c < h; ++c) {
			b[r][c] = a[c][w - r - 1];
		}
	}
	return b;
}

vector <string> flip(const vector <string>& a) {
	int h = a.size();
	vector <string> b(h);
	for (int r = 0; r < h; ++r) {
		b[r] = a[r];
		reverse(b[r].begin(), b[r].end());
	}
	return b;
}

int count_defects(const vector <string>& a, const vector <string>& b) {
	int cnt = 0;
	int h = a.size(), w = a[0].length();
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cnt += a[i][j] != '.' || b[i][j] != '.';
		}
	}
	return cnt;
}

class LayeredGlass {
	int sz;

public:
	int minDefects(vector <string> a, vector <string> b) {
		sz = (int)a.size();
		int ans = 1 << 30;
		for (int i = 0; i < 4; ++i) {
			ans = min({ ans, count_defects(a, b), count_defects(flip(a), b) });
			a = rotate(a);
		}
		return ans;
	}

	// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T>& V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int& Expected, const int& Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) {
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)) {
			string Arr0[] = { "X.",
 ".." };
			string Arr1[] = { "..",
 ".X" };
			int Arg2 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minDefects(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)) {
			string Arr0[] = { "...",
 "..X",
 "..." };
			string Arr1[] = { "X..",
 "...",
 "..." };
			int Arg2 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minDefects(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)) {
			string Arr0[] = { "...",
 "...",
 "..." };
			string Arr1[] = { "...",
 ".XX",
 "..." };
			int Arg2 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minDefects(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)) {
			string Arr0[] = { ".XX",
 "...",
 "..." };
			string Arr1[] = { "X..",
 "...",
 "X.." };
			int Arg2 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minDefects(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)) {
			string Arr0[] = { "XX..",
 "X...",
 "XX..",
 "X..." };
			string Arr1[] = { "XXXX",
 "X.X.",
 "....",
 "...." };
			int Arg2 = 6;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minDefects(Arg0, Arg1));
		}
		n++;

	}

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LayeredGlass ___test;
	___test.run_test(-1);
}
// END CUT HERE
