// BEGIN CUT HERE
/*
SRM 772 Div2 Easy (250)

PROBLEM STATEMENT

Given count plus signs ('+'), arrange them in a way that maximizes the number of closed figures. 
Assume that horizontally or vertically adjacent plus signs touch each other.

For example, the following arrangement of 8 plus signs contains three closed figures (squares, each formed by parts of four + signs):

++++
++++

The following arrangement contains 10 plus signs but only one closed figure (a 2x3 rectangle with some short line segments on the inside):

++++
+  +
++++

And the following arrangement of 6 plus signs contains no closed figures at all:

+ + +
 + ++

Compute and return the largest number of closed figures that can be produced using exactly count plus signs.


DEFINITION
Class:PlusCastle
Method:maximiseClosedFigures
Parameters:int
Returns:int
Method signature:int maximiseClosedFigures(int k)


CONSTRAINTS
-count will be between 1 and 1,000,000,000, inclusive


EXAMPLES

0)
9

Returns: 4

The following arrangement maximises the number of closed figures:
+++
+++
+++


1)
6

Returns: 2

The following arrangement maximises the number of closed figures:
+++
+++


2)
898680485

Returns: 898620529

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

class PlusCastle {
public:
	int maximiseClosedFigures(int k) {
		int w = sqrt(k), h = k / w, r = k - w * h;
		return (w - 1) * (h - 1) + max(0, r - 1);
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
			int Arg0 = 9;
			int Arg1 = 4;

			verify_case(n, Arg1, maximiseClosedFigures(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 2;

			verify_case(n, Arg1, maximiseClosedFigures(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 898680485;
			int Arg1 = 898620529;

			verify_case(n, Arg1, maximiseClosedFigures(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PlusCastle ___test;
	___test.run_test(-1);
}
// END CUT HERE
