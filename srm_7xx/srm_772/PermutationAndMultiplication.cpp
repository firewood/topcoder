// BEGIN CUT HERE
/*
SRM 772 Div2 Medium (500)

PROBLEM STATEMENT

You are given two ints: ones and zeroes. 
You need to do the following:

Let A be the largest integer whose binary representation consists of exactly ones 1s and zeroes 0s.
Let B be the smallest integer whose binary representation consists of exactly ones 1s and zeroes 0s.
Let C = A*B.

Compute and return the number of 1s in the binary representation of C.


DEFINITION
Class:PermutationAndMultiplication
Method:multiplyAndCount
Parameters:int, int
Returns:int
Method signature:int multiplyAndCount(int ones, int zeroes)


NOTES
-The binary representations of A and B are not allowed to have leading zeroes.


CONSTRAINTS
-ones will be between 1 and 200,000, inclusive
-zeroes will be between 0 and 200,000, inclusive


EXAMPLES

0)
2
2

Returns: 4

A = 12 (in decimal) = 1100 (in binary)
B = 9 (in decimal) = 1001 (in binary)
Thus, A*B = 108 (in decimal) = 1101100 (in binary).
The number 1101100 contains four 1s, so the correct answer is 4.


1)
1
2

Returns: 1

Here we have A = B = 4, and thus A*B = 16.
(In binary, A = B = 100 and A*B = 10000.)

2)
2
0

Returns: 2

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class PermutationAndMultiplication {
public:
	int multiplyAndCount(int ones, int zeroes) {
		int ans = 0, carry = 0, one_count = 0;
		for (int i = 0; (i < (ones * 2 + zeroes)) || carry > 0; ++i) {
			if (i < ones - 1) {
				++one_count;
			}
			if (i >= ones && i < ones * 2 - 1) {
				--one_count;
			}
			carry += one_count;
			carry += i >= (ones + zeroes - 1) && i < (ones * 2 + zeroes - 1);
			ans += carry % 2;
			carry /= 2;
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
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 4;

			verify_case(n, Arg2, multiplyAndCount(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 2;
			int Arg2 = 1;

			verify_case(n, Arg2, multiplyAndCount(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 0;
			int Arg2 = 2;

			verify_case(n, Arg2, multiplyAndCount(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PermutationAndMultiplication ___test;
	___test.run_test(-1);
}
// END CUT HERE
