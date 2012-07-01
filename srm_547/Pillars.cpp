// BEGIN CUT HERE
/*
// SRM 547 Div1 Easy (250)

// PROBLEM STATEMENT
// On a horizontal line, there are two vertical pillars.
The distance between their bottoms is w.
The height of the first pillar is an integer, chosen uniformly at random
in the range 1 through x, inclusive.
The height of the second pillar is an integer, chosen uniformly at random
in the range 1 through y, inclusive.
The tops of both pillars will be connected by a straight piece of rope.

You are given the ints w, x, and y.
Compute and return the expected length of the rope.


DEFINITION
Class:Pillars
Method:getExpectedLength
Parameters:int, int, int
Returns:double
Method signature:double getExpectedLength(int w, int x, int y)


NOTES
-Your return value must have a relative or an absolute error of less than 1e-9.
-In this task, the expected rope length can be computed as the average rope length over all possible cases.


CONSTRAINTS
-w will be between 1 and 1000, inclusive.
-x will be between 1 and 100,000, inclusive.
-y will be between 1 and 100,000, inclusive.


EXAMPLES

0)
1
1
1

Returns: 1.0

The rope always has a length of 1.


1)
1
5
1

Returns: 2.387132965131785

There are 5 possible (equiprobable) cases in which the length of the rope is
1, sqrt(2), sqrt(5), sqrt(10) and sqrt(17). The correct answer is the
arithmetic average of these 5 numbers.


2)
2
3
15

Returns: 6.737191281760445


3)
10
15
23

Returns: 12.988608956320535

*/
// END CUT HERE
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class Pillars {

	double WW;
	LL c;
	double res;

	void add(int d, int n) {
		double D = d;
		res += sqrt(WW + D*D) * (double)n;
		c += n;
	}

public:
	double getExpectedLength(int w, int x, int y) {
		res = 0;
		WW = (double)w * (double)w;
		c = 0;

		int a = min(x, y);
		int b = max(x, y);

		add(0, a);
		int d;
		for (d = 1; d < b; ++d) {
			int Min = d+1;
			int Max = min(b, d + a);
			int n = Max - Min + 1;
			add(d, n);
		}
		for (d = 1; d < a; ++d) {
			int n = a - d;
			add(d, n);
		}

		return res / (double)c;
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
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 1;
			double Arg3 = 1.0;

			verify_case(n, Arg3, getExpectedLength(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 5;
			int Arg2 = 1;
			double Arg3 = 2.387132965131785;

			verify_case(n, Arg3, getExpectedLength(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 3;
			int Arg2 = 15;
			double Arg3 = 6.737191281760445;

			verify_case(n, Arg3, getExpectedLength(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 15;
			int Arg2 = 23;
			double Arg3 = 12.988608956320535;

			verify_case(n, Arg3, getExpectedLength(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 10000;
			int Arg2 = 10000;
			double Arg3 = 12.988608956320535;

			verify_case(n, Arg3, getExpectedLength(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Pillars ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
