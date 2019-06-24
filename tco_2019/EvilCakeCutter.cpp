// BEGIN CUT HERE
/*
Collegiate Programmers in South America Easy (250)

PROBLEM STATEMENT

You and another baker are working on cutting a w x h sheet cake into pieces.
Each piece must be a w1 x h1 rectangle with sides parallel to the sides of the cake.
Note that the pieces cannot be rotated: the width of the piece must run in parallel to the width of the cake.

Your coworker does not like to work in any orderly fashion.
He has decided to cut out the first piece completely at random.
More precisely, he will choose the location of the top left corner of the cut uniformly at random from all possible locations such that the entire cut lies within the cake.
(Note that the coordinates may be arbitrary real numbers, not just integers.)

Calculate the probability that after his cut you will still be able to cut out at least one more piece of the same size.


DEFINITION
Class:EvilCakeCutter
Method:successProbability
Parameters:int, int, int, int
Returns:double
Method signature:double successProbability(int w, int h, int w1, int h1)


CONSTRAINTS
-w1 will be between 1 and w, inclusive.
-h1 will be between 1 and h, inclusive.
-w will be between w1 and 1,000,000, inclusive.
-h will be between h1 and 1,000,000, inclusive.


EXAMPLES

0)
3
2
1
1

Returns: 1.0

It's always possible to get a second piece.


1)
2
2
1
1

Returns: 0.0

The only way a second piece can be cut, is if the first piece comes perfectly from a corner. Since the evil cut is chosen continuously, the probability of this is infinitesimally small.


2)
8
5
3
2

Returns: 0.9333333333333333

Only if the first cut is right near the middle, leaving too small a width or height anywhere around it, can a second piece not be cut. In most cases getting a second piece is possible.

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
#include <cassert>

using namespace std;

class EvilCakeCutter {
	double calc(int w, int w1) {
		if (w >= w1 * 3) {
			return 0;
		}
		if (w <= w1 * 2) {
			return 1.0;
		}
		double a = w - w1;
		return (2 * w1 - a) / a;
	}
public:
	double successProbability(int w, int h, int w1, int h1) {
		return 1.0 - calc(w, w1) * calc(h, h1);
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			int Arg2 = 1;
			int Arg3 = 1;
			double Arg4 = 1.0;

			verify_case(n, Arg4, successProbability(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 1;
			int Arg3 = 1;
			double Arg4 = 0.0;

			verify_case(n, Arg4, successProbability(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arg1 = 5;
			int Arg2 = 3;
			int Arg3 = 2;
			double Arg4 = 0.9333333333333333;

			verify_case(n, Arg4, successProbability(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 8;
			int Arg1 = 5;
			int Arg2 = 5;
			int Arg3 = 2;
			double Arg4 = 0;

			verify_case(n, Arg4, successProbability(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 5;
			int Arg1 = 8;
			int Arg2 = 2;
			int Arg3 = 5;
			double Arg4 = 0;

			verify_case(n, Arg4, successProbability(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 9;
			int Arg1 = 5;
			int Arg2 = 3;
			int Arg3 = 4;
			double Arg4 = 1;

			verify_case(n, Arg4, successProbability(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EvilCakeCutter ___test;
	___test.run_test(-1);
}
// END CUT HERE
