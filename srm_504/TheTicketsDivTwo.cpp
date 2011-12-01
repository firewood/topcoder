// BEGIN CUT HERE
/*
// SRM 504.5 Div2 Hard (1000)

// PROBLEM STATEMENT
// John has two tickets for the basketball game - one for himself and one for a friend.
However, he has n friends who want to go with him. He decides to use the following strategy
to choose one of them. First, he tells his friends to form a straight single file line.
Then, he repeats the following step until he has made a choice. If there is only one friend
in line, John chooses him. Otherwise, he throws a standard six-sided die.
If the number 4 is on top, he chooses the friend who is currently first in line.
Otherwise, if the number is odd, the first friend in line must move to the end of the line,
and if the number is even, the first friend in line must leave the line and go home. 

While the initial John's intention is to throw a die until some friend is chosen,
in practice he gets tired quickly. If after k throws of a die he still hasn't chosen a friend,
he prefers to stop the process and to choose the friend who is currently first in line.

You are given an int m, the 1-based index of a friend in the initial line.
The index of the first friend is 1, and the index of the last friend is n.
Return the probability that the m-th friend in the initial line is ultimately chosen by John.


DEFINITION
Class:TheTicketsDivTwo
Method:find
Parameters:int, int, int
Returns:double
Method signature:double find(int n, int m, int k)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-n will be between 1 and 10, inclusive.
-m will be between 1 and n, inclusive.
-k will be between 1 and 10, inclusive.


EXAMPLES

0)
2
1
1

Returns: 0.16666666666666666

There is 1/6 probability that John will choose the first friend after the first throw of a die.

1)
2
1
2

Returns: 0.5833333333333334

The first friend will go to the game if John chooses him after the first throw, or if he goes to the end of the line after the first throw and Jonh doesn't choose the second friend after the second throw. The overall probability is 1/6 + 1/2 * 5/6.

2)
7
7
4

Returns: 0.0

There's no chance for the last friend in the line to be chosen.

3)
4
2
10

Returns: 0.25264033564814814

*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class TheTicketsDivTwo {

	double rec(int n, int m, int k) {
		if (n <= 1) {
			// only one person remains
			return 1.0;
		}
		if (k <= 0) {
			// exceeds maximum tries
			// first of the queue is chosen
			return m <= 0 ? 1.0 : 0.0;
		}

		// 4
		// chosen if on the first
		double res = m <= 0 ? 1.0 : 0;

		// odd (1,3,5)
		// rotation
		res += rec(n, (n + m - 1) % n, k - 1) * 3.0;

		// even (2,6)
		// remove
		if (m > 0) {
			res += rec(n - 1, m - 1, k - 1) * 2.0;
		}

		return res / 6.0;
	}

public:
	double find(int n, int m, int k) {
		return rec(n, m - 1, k);
	}
};

// BEGIN CUT HERE
static void Test(int n, int m, int k, double expected)
{
	TheTicketsDivTwo ___test;
	double result = ___test.find(n, m, k);
	printf("result: %s, returned %f, expected %f\n", fabs(result-expected)<=0.00000001 ? "OK" : "FAILED", result, expected);
}

int main() {
	// example 0
	Test(2, 1, 1, 0.16666666666666666);

	// example 1
	Test(2, 1, 2, 0.5833333333333334);

	// example 2
	Test(7, 7, 4, 0.0);

	// example 3
	Test(4, 2, 10, 0.25264033564814814);

	return 0;
}
// END CUT HERE
