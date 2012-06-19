// BEGIN CUT HERE
/*
// SRM 526 Div2 Hard (1000)

// PROBLEM STATEMENT
// Mr. Dengklek once told you that 4 and 7 are lucky numbers. He also defined
the luckiness of a positive integer as the absolute difference between the
number of 7s in its decimal representation and the number of 4s in its decimal
representation. For example, for each of the numbers 23, 47 and 47714 the
luckiness is 0, and for each of the numbers 4474 and 7070 the luckiness is 2.

You are given two ints A and B. Return the sum of luckiness of all integers
between A and B, inclusive.


DEFINITION
Class:SumOfLuckiness
Method:theSum
Parameters:int, int
Returns:long long
Method signature:long long theSum(int A, int B)


CONSTRAINTS
-A will be between 1 and 2,000,000,000, inclusive.
-B will be between A and 2,000,000,000, inclusive.


EXAMPLES

0)
1
10

Returns: 2

The luckiness of 4 is 1. The luckiness of 7 is 1. The luckiness of the other numbers is 0. So, the sum of luckiness is 2.


1)
40
47

Returns: 8

The luckiness of 40, 41, 42, 43, 45, and 46 is 1. The luckiness of 44 is 2. The luckiness of 47 is 0.


2)
58
526

Returns: 231


3)
4444
7777

Returns: 2338


4)
585858585
858585858

Returns: 287481025

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

#define DIVISOR 100

class SumOfLuckiness {

public:
	long long theSum(int A, int B) {
		long long result = 0;

		int upper = ((A+DIVISOR-1)/DIVISOR) * DIVISOR;
		int i, j;
		for (i = A; i < upper && i <= B; ++i) {
			int c[10] = {};
			for (j = i; j > 0; j /= 10) {
				c[j % 10] += 1;
			}
			result += abs(c[4] - c[7]);
		}
		upper = (B/DIVISOR) * DIVISOR;
		for (; i < upper; i += DIVISOR) {
			int c[10] = {};
			for (j = i; j > 0; j /= 10) {
				c[j % 10] += 1;
			}
			int f = c[4];
			int s = c[7];
#if DIVISOR == 100
			// 04 14 24 34 40 41 42 43 45 46 48 49 54 64 84 94
			result += abs(f + 1 - s) * 16;
			// 44
			result += abs(f + 2 - s);
			// 07 17 27 37 57 67 70 71 72 73 75 76 78 79 87 97
			result += abs(s + 1 - f) * 16;
			// 77
			result += abs(s + 2 - f);
			// others
			result += abs(f - s) * 66;
#endif
#if DIVISOR == 1000
			result += abs(f + 1 - s) * 195;
			result += abs(f + 2 - s) * 24;
			result += abs(f + 3 - s);
			result += abs(s + 1 - f) * 195;
			result += abs(s + 2 - f) * 24;
			result += abs(s + 3 - f);
			result += abs(f - s) * 560;
#endif
		}
		for (; i <= B; ++i) {
			int c[10] = {};
			for (j = i; j > 0; j /= 10) {
				c[j % 10] += 1;
			}
			result += abs(c[4] - c[7]);
		}

		return result;
	}

	
// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 10;
			long long Arg2 = 2LL;

			verify_case(n, Arg2, theSum(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 40;
			int Arg1 = 47;
			long long Arg2 = 8LL;

			verify_case(n, Arg2, theSum(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 58;
			int Arg1 = 526;
			long long Arg2 = 231LL;

			verify_case(n, Arg2, theSum(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4444;
			int Arg1 = 7777;
			long long Arg2 = 2338LL;

			verify_case(n, Arg2, theSum(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 585858585;
			int Arg1 = 858585858;
			long long Arg2 = 287481025LL;

			verify_case(n, Arg2, theSum(Arg0, Arg1));
		}
		n++;



/*
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 101;
			long long Arg2 = 36LL;

			verify_case(n, Arg2, theSum(Arg0, Arg1));
		}
		n++;
*/

		if ((Case == -1) || (Case == n)){
			int Arg0 = 58;
			int Arg1 = 201;
			long long Arg2 = 52LL;

			verify_case(n, Arg2, theSum(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SumOfLuckiness ___test;
//	___test.run_test(2);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
