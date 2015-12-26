// BEGIN CUT HERE
/*
SRM 677 Div1 Easy (250)

PROBLEM STATEMENT
You have two positive integers: the first one is a, the second one is b.

You also have a red button and a blue button.
Whenever you push the red button, both your numbers are incremented by 1.
Whenever you push the blue button, both your numbers are multiplied by 2.

Your goal is to change the pair (a, b) into the pair (newA, newB).

You are given the ints a, b, newA, and newB.
If there is a sequence of zero or more button pushes that accomplishes your goal, return the length of the shortest such sequence.
Otherwise, return -1.

DEFINITION
Class:DoubleOrOneEasy
Method:minimalSteps
Parameters:int, int, int, int
Returns:int
Method signature:int minimalSteps(int a, int b, int newA, int newB)


NOTES
-The operations can produce arbitrarily large integers. For example, if you just push the blue button 1000 times in a row, you will get the numbers a*2^1000 and b*2^1000.


CONSTRAINTS
-a will be between 1 and 1,000,000,000, inclusive.
-b will be between 1 and 1,000,000,000, inclusive.
-newA will be between 1 and 1,000,000,000, inclusive.
-newB will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
100
1000
101
1001

Returns: 1

Just push the red button once.


1)
100
1000
202
2002

Returns: 2

The best solution is to push the red button followed by the blue button.
This performs the operation +1 followed by the operation *2.

Another valid solution is to push the blue button once and then the red button twice to perform the operations *2, +1, and +1.
This solution is not optimal because the previous solution contains fewer operations.


2)
2
2
1
1

Returns: -1

We are unable to decrease a and b.


3)
1
111111111
8
888888888

Returns: 3


4)
1
111111111
9
999999999

Returns: -1

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class DoubleOrOneEasy {
public:
	int minimalSteps(int a, int b, int newA, int newB) {
		if (a > b) {
			swap(a, b);
			swap(newA, newB);
		}
		int x = b - a, y = newB - newA;
		int r = 1;
		while (x > 0 && y > 0 && x * r < y) {
			r *= 2;
		}
		if (x * r != y) {
			return -1;
		}
		int ans = 0;
		while (a < newA) {
			int p = newA / r, q = newB / r, d = p - a;
			a += d, b += d, ans += d;
			if (r > 1) {
				a *= 2, b *= 2, r /= 2, ++ans;
			}
		}
		return a == newA && b == newB ? ans : -1;
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
			int Arg0 = 100;
			int Arg1 = 1000;
			int Arg2 = 101;
			int Arg3 = 1001;
			int Arg4 = 1;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 1000;
			int Arg2 = 202;
			int Arg3 = 2002;	
			int Arg4 = 2;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 1;
			int Arg3 = 1;
			int Arg4 = -1;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 111111111;
			int Arg2 = 8;
			int Arg3 = 888888888;
			int Arg4 = 3;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 111111111;
			int Arg2 = 9;
			int Arg3 = 999999999;
			int Arg4 = -1;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;




		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 2;
			int Arg2 = 4;
			int Arg3 = 3;
			int Arg4 = -1;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;
			int Arg2 = 3;
			int Arg3 = 4;
			int Arg4 = -1;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;




		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 999999999;
			int Arg3 = 999999999;
			int Arg4 = 999999998;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 17;
			int Arg2 = 999934463;
			int Arg3 = 999999999;
			int Arg4 = 244145;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 2;
			int Arg3 = 4;
			int Arg4 = -1;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DoubleOrOneEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
