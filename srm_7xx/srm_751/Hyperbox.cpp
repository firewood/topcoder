// BEGIN CUT HERE
/*
SRM 751 Div1 Easy (250)

PROBLEM STATEMENT

The boundary of a two-dimensional rectangle is one-dimensional (a collection of line segments), and we can measure its length.
The boundary of a three-dimensional box is two-dimensional (a collection of rectangles), and we can measure its area.
In the same sense, the boundary of a four-dimensional hyperbox is three-dimensional, and we can measure its volume.

You are given the int volume (in cubic meters).
Return the number of distinct hyperboxes with positive integer sides (in meters) and this exact surface volume.

Two hyperboxes are distinct if they are not congruent.
(In other words, they are distinct if we cannot rearrange the dimensions of one to get the dimensions of the other.)


DEFINITION
Class:Hyperbox
Method:count
Parameters:int
Returns:int
Method signature:int count(int volume)


CONSTRAINTS
-volume will be between 1 and 200,000,000, inclusive.


EXAMPLES

0)
8

Returns: 1

The smallest possible hyperbox (i.e., the 1 x 1 x 1 x 1 hyperbox) is the only one with surface volume 8.


1)
1234567

Returns: 0

There are no hyperboxes with integer sides and this exact surface volume.


2)
120

Returns: 3

One of the three distinct hyperboxes with this surface volume has side lengths 1, 2, 2, and 7.


3)
123456

Returns: 52

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Hyperbox {
public:
	int count(int volume) {
		int ans = 0;
		if ((volume % 2) == 0) {	
			volume /= 2;
			for (int a = 1; a * a * a <= volume; ++a) {
				for (int b = a; a * b * b <= volume; ++b) {
					for (int c = b; b * c * c <= volume; ++c) {
						int x = a * b + b * c + c * a;
						int r = volume - a * b * c;
						int d = r / x;
						ans += d >= c && r == x * d;
					}
				}
			}
		}
		return ans;
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
			int Arg0 = 8;
			int Arg1 = 1;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1234567;
			int Arg1 = 0;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 120;
			int Arg1 = 3;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 123456;
			int Arg1 = 52;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 200000000;
			int Arg1 = 1414;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Hyperbox ___test;
	___test.run_test(-1);
}
// END CUT HERE
