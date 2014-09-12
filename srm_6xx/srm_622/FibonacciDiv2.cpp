// BEGIN CUT HERE
/*
SRM 622 Div2 Easy (250)

PROBLEM STATEMENT
The Fibonacci sequence is defined as follows:

F[0] = 0
F[1] = 1
for each i >= 2: F[i] = F[i-1] + F[i-2]

Thus, the Fibonacci sequence starts as follows: 0, 1, 1, 2, 3, 5, 8, 13, ...
The elements of the Fibonacci sequence are called Fibonacci numbers.

You're given an int N.
You want to change N into a Fibonacci number.
This change will consist of zero or more steps.
In each step, you can either increment or decrement the number you currently have.
That is, in each step you can change your current number X either to X+1 or to X-1.

Return the smallest number of steps needed to change N into a Fibonacci number.

DEFINITION
Class:FibonacciDiv2
Method:find
Parameters:int
Returns:int
Method signature:int find(int N)


CONSTRAINTS
-N will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
1

Returns: 0

The number 1 is already a Fibonacci number. No changes are necessary.


1)
13

Returns: 0

The number 13 is also a Fibonacci number.


2)
15

Returns: 2

The best way to change 15 into a Fibonacci number is to decrement it twice in a row (15 -> 14 -> 13).


3)
19

Returns: 2

You can increase it by 2 to get 21.


4)
1000000

Returns: 167960

This is the biggest possible number that you can get as input.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class FibonacciDiv2 {
public:
	int find(int N) {
		int fib[10000] = { 0, 1 };
		int ans = 1 << 30;
		for (int i = 2; i < 46; ++i) {
			fib[i] = fib[i - 1] + fib[i - 2];
			ans = min(ans, abs(fib[i] - N));
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
			int Arg0 = 1;
			int Arg1 = 0;

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 13;
			int Arg1 = 0;

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 15;
			int Arg1 = 2;

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 19;
			int Arg1 = 2;

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000;
			int Arg1 = 167960;

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FibonacciDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
