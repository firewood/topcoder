// BEGIN CUT HERE
/*
SRM 783 Div1 Easy (250)

PROBLEM STATEMENT

This problem is about a special type of cardboard boxes.
When assembled, these boxes have three dimensions: length, width, and height.
All three dimensions must be positive integers.
Length and width are interchangable: a (length,width,height) box is the same as a (width,length,height) box.

A cardboard box consists of 12 connected pieces of cardboard.
The shape of each piece is a rectangle.

Four of these pieces are simply the sides of the box.
If we only had these four pieces, we would have a box that is missing the top and the bottom.
We will call this shape an open box.

The next four pieces are flaps on the top of the box.
Each flap is connected to one of the four edges of the open box.
Thus, one dimension of each flap is fixed.
All four flaps have the same second dimension, and this dimension is as small as possible given that together the four flaps can completely cover the top of the box.
For example, if your box is 50 cm long and 21 cm wide, each of the top flaps will have dimensions (the length of the edge it is attached to, times 10.5 cm).

The last four pieces are flaps on the bottom. These look the same as the flaps on the top.

Given the total surface area S of the cardboard box, count all possible dimensions it may have.


DEFINITION
Class:CardboardBoxes
Method:count
Parameters:long long
Returns:long long
Method signature:long long count(long long S)


NOTES
-As shown in the statement, only the dimensions of the box itself must be integers. The flaps can have one dimension that is not an integer.


CONSTRAINTS
-S will be between 1 and 10^13, inclusive.


EXAMPLES

0)
47

Returns: 0

It should be quite obvious that the surface area of a valid cardboard box cannot be 47.


1)
470

Returns: 6

The six distinct sets of dimensions (in the order width, length, height) that correspond to surface area 470 are listed below:

1 4 46
1 46 4
2 3 45
2 45 3
3 44 2
4 43 1


2)
4700

Returns: 106

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

class CardboardBoxes {
public:
	long long count(LL S) {
		LL ans = 0;
		if (S % 2 == 0) {
			S /= 2;
			for (LL a = 2; a * a <= S; ++a) {
				if ((S % a) == 0) {
					ans += a / 2;
					LL b = S / a;
					if (a != b) {
						ans += min(a - 1, b / 2);
					}
				}
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 47LL;
			long long Arg1 = 0LL;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 470LL;
			long long Arg1 = 6LL;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 4700LL;
			long long Arg1 = 106LL;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			long long Arg0 = 512LL;
			long long Arg1 = 26LL;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CardboardBoxes ___test;
	___test.run_test(-1);
}
// END CUT HERE
