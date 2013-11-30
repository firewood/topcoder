// BEGIN CUT HERE
/*
SRM 591 Div2 Easy (250)

PROBLEM STATEMENT
A triple (x, y, z) is called an arithmetic progression if the equality y - x = z - y holds.

You are given three ints a, b and c. Your goal is to change the triple (a, b, c) into an arithmetic progression.
You are only allowed to change one of the three numbers.
The change must proceed as follows:
First, you choose a non-negative real (not necessarily integer) number r.
Then, you either add r to one of the three given numbers, or you subtract r from one of them. Return the minimum value of r which allows you to create an arithmetic progression.

DEFINITION
Class:TheArithmeticProgression
Method:minimumChange
Parameters:int, int, int
Returns:double
Method signature:double minimumChange(int a, int b, int c)


CONSTRAINTS
-a will be between 0 and 1000, inclusive.
-b will be between 0 and 1000, inclusive.
-c will be between 0 and 1000, inclusive.


EXAMPLES

0)
0
1
2

Returns: 0.0

The triple (0, 1, 2) is an arithmetic progression. Thus, you can choose r = 0.0 and add or subtract it from any of the given numbers without changing the triple.


1)
0
2
1

Returns: 1.5

Note that while (0, 1, 2) is an arithmetic progression, you cannot rearrange the numbers within the triple. You can choose r = 1.5 and subtract it from b, obtaining the triple (0, 0.5, 1).


2)
3
2
1

Returns: 0.0


3)
4
4
8

Returns: 2.0

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class TheArithmeticProgression {
public:
	double minimumChange(int a, int b, int c) {
		return fabs((double)(a+c-2*b)*0.5);
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
			int Arg0 = 0;
			int Arg1 = 1;
			int Arg2 = 2;
			double Arg3 = 0.0;

			verify_case(n, Arg3, minimumChange(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 2;
			int Arg2 = 1;
			double Arg3 = 1.5;

			verify_case(n, Arg3, minimumChange(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			int Arg2 = 1;
			double Arg3 = 0.0;

			verify_case(n, Arg3, minimumChange(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;
			int Arg2 = 8;
			double Arg3 = 2.0;

			verify_case(n, Arg3, minimumChange(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheArithmeticProgression ___test;
	___test.run_test(-1);
}
// END CUT HERE
