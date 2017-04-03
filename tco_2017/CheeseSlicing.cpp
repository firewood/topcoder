// BEGIN CUT HERE
/*
TCO 2017 R1A Medium (500)

PROBLEM STATEMENT
You want to make a lot of sandwiches.
However, you only have a limited amount of cheese.
The only piece of cheese you currently have is a rectangular block with dimensions A, B, and C.

You can cut the block of cheese into smaller pieces.
You are only allowed to cut as follows:

Each cut must divide one block of cheese into two smaller blocks of cheese.
Each cut must be parallel to one of the faces of the piece you are cutting.
Each of the two smaller blocks must have integer dimensions.

When placing a block of cheese onto a piece of bread, the cheese is always rotated so that its shortest side is vertical.
In other words, suppose you have a block of cheese with dimensions (X,Y,Z) such that X ? Y ? Z.
If you place this block onto a piece of bread, its surface area will be X*Y and its thickness will be Z.

A block of cheese is called a good slice if and only if its thickness is greater than or equal to S.
(Recall that the thickness of a block is the length of its shortest side.)

You can cut your block of cheese into arbitrarily many pieces, as long as you follow the rules given above.
Your goal is to cut the block in such a way that maximizes the total surface area of all good slices among the pieces.
Note that your way of cutting may also produce some pieces that are not good slices, but those pieces won't contribute to the surface area.
The number of good slices does not matter, we only care about their surface.
Different good slices may have different dimensions.

You are given the ints A, B, C, and S.
Return the maximum total surface area of good slices you can get.


DEFINITION
Class:CheeseSlicing
Method:totalArea
Parameters:int, int, int, int
Returns:int
Method signature:int totalArea(int A, int B, int C, int S)


CONSTRAINTS
-A, B and C will be between 1 and 100, inclusive.
-S will be between 1 and 10, inclusive.


EXAMPLES

0)
1
3
3
2

Returns: 0

One of the dimensions of this block is 1.
Regardless of how we cut it, each piece will have one dimension equal to 1.
As S=2, this means that producing a good slice is impossible.
Hence, the maximum total surface area of good slices is 0.


1)
5
3
5
3

Returns: 25

The entire block is a good slice with thickness 3 and surface area 5*5 = 25.
An optimal solution is to make no cuts and to simply take this one block.


2)
5
5
5
2

Returns: 58

One possible sequence of cuts:

 5x5x5 -> 2x5x5 + 3x5x5 
 3x5x5 -> 3x2x5 + 3x3x5 
 3x3x5 -> 3x3x2 + 3x3x3 

After these three cuts we have four pieces: 2x5x5, 3x2x5, 3x3x2, and 3x3x3.
Each of these is a good slice.
Their total surface area is 5*5 + 3*5 + 3*3 + 3*3.


3)
49
92
20
3

Returns: 30045

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

class CheeseSlicing {

	int s;
	int memo[101][101][101];
	int g(int a, int b, int c) {
		if (c < b) {
			swap(b, c);
		}
		if (b < a) {
			swap(a, b);
		}
		int &r = memo[a][b][c];
		if (r < 0) {
			r = a >= s ? b * c : 0;
			for (int i = s; (i + s) <= a; ++i) {
				r = max(r, g(i, b, c) + g(a - i, b, c));
			}
			for (int i = s; (i + s) <= b; ++i) {
				r = max(r, g(a, i, c) + g(a, b - i, c));
			}
			for (int i = s; (i + s) <= c; ++i) {
				r = max(r, g(a, b, i) + g(a, b, c - i));
			}
		}
		return r;
	}

public:
	int totalArea(int A, int B, int C, int S) {
		s = S;
		memset(memo, -1, sizeof(memo));
		return g(A, B, C);
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
			int Arg0 = 1;
			int Arg1 = 3;
			int Arg2 = 3;
			int Arg3 = 2;
			int Arg4 = 0;

			verify_case(n, Arg4, totalArea(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 3;
			int Arg2 = 5;
			int Arg3 = 3;
			int Arg4 = 25;

			verify_case(n, Arg4, totalArea(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 5;
			int Arg2 = 5;
			int Arg3 = 2;
			int Arg4 = 58;

			verify_case(n, Arg4, totalArea(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 49;
			int Arg1 = 92;
			int Arg2 = 20;
			int Arg3 = 3;
			int Arg4 = 30045;

			verify_case(n, Arg4, totalArea(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 100;
			int Arg1 = 100;
			int Arg2 = 100;
			int Arg3 = 2;
			int Arg4 = 4*50*50*50;

			verify_case(n, Arg4, totalArea(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 100;
			int Arg1 = 100;
			int Arg2 = 100;
			int Arg3 = 1;
			int Arg4 = 100 * 100 * 100;

			verify_case(n, Arg4, totalArea(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CheeseSlicing ___test;
	___test.run_test(-1);
}
// END CUT HERE
