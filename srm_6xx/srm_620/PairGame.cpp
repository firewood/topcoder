// BEGIN CUT HERE
/*
SRM 620 Div1 Easy (250)

PROBLEM STATEMENT
In this problem we consider ordered pairs of positive integers. Given such a pair, you can now make zero or more steps.
In each step, you can change your pair into a new pair of integers by adding one of them to the other.
That is, if your current pair is (x, y), then your next pair will be either (x+y, y), or (x, x+y).

For example, you can start with (1, 2), change it to (3, 2), change that to (3, 5), and then change that again to (3, 8).

You are given four ints: a, b, c, and d.
We are looking for a pair (x, y) such that:

It is possible to start with (x, y) and end with (a, b).
It is also possible to start with the same (x, y) and end with (c, d).

The number of steps needed to reach (a, b) may be different from the number of steps needed to reach (c, d).

If there is at least one such pair (x, y), return the largest possible value of x+y.
Otherwise, return -1.


DEFINITION
Class:PairGame
Method:maxSum
Parameters:int, int, int, int
Returns:int
Method signature:int maxSum(int a, int b, int c, int d)


CONSTRAINTS
-a will be between 1 and 1,000,000, inclusive.
-b will be between 1 and 1,000,000, inclusive.
-c will be between 1 and 1,000,000, inclusive.
-d will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
1
2
2
1

Returns: 2

We have (1,1) -> (1,2) and (1,1) -> (2,1).


1)
15
4
10
7

Returns: 7

Now we have (3,4) -> (7,4) -> (11,4) -> (15,4) and (3,4) -> (3,7) -> (10,7).


2)
1
1
10
10

Returns: -1


3)
1000
1001
2000
2001

Returns: 1001


4)
10944
17928
7704
21888

Returns: 144


5)
1
1
1
1

Returns: 2

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class PairGame {

public:
	int maxSum(int a, int b, int c, int d) {
		while (a > 0 && b > 0 && c > 0 && d > 0) {
			if (a == c && b == d) {
				return a + b;
			}
			if (a + b >= c + d) {
				if (a > b){
					a -= b;
				} else {
					b -= a;
				}
			} else {
				if (c > d) {
					c -= d;
				} else {
					d -= c;
				}
			}
		}
		return -1;
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
			int Arg1 = 2;
			int Arg2 = 2;
			int Arg3 = 1;
			int Arg4 = 2;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 15;
			int Arg1 = 4;
			int Arg2 = 10;
			int Arg3 = 7;
			int Arg4 = 7;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 10;
			int Arg3 = 10;
			int Arg4 = -1;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000;
			int Arg1 = 1001;
			int Arg2 = 2000;
			int Arg3 = 2001;
			int Arg4 = 1001;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10944;
			int Arg1 = 17928;
			int Arg2 = 7704;
			int Arg3 = 21888;
			int Arg4 = 144;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 1;
			int Arg4 = 2;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1000000;
			int Arg2 = 1;
			int Arg3 = 6;
			int Arg4 = 7;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1000000;
			int Arg2 = 1000000;
			int Arg3 = 1;
			int Arg4 = 2;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 1000000;
			int Arg3 = 999998;
			int Arg4 = -1;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000;
			int Arg1 = 1;
			int Arg2 = 999999;
			int Arg3 = 2;
			int Arg4 = 2;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 999999;
			int Arg2 = 2;
			int Arg3 = 1000000;
			int Arg4 = -1;

			verify_case(n, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PairGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
