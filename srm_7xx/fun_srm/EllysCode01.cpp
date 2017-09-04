// BEGIN CUT HERE
/*
2017 TCO Algorithm Warsaw Regional Round
Fun SRM Medium (500)

PROBLEM STATEMENT
Elly came up with an infinite sequence of zeroes and ones.
The sequence can be incrementally constructed as follows:
Begin by writing down a zero.
Then, repeat the following process forever:

Copy the entire sequence, but change each zero into a one and vice versa.
Append the copy to the current sequence.

The first few iterations of this process look as follows:
0 Å® 01 Å® 0110 Å® 01101001 Å® 0110100110010110 Å® 01101001100101101001011001101001 Å® Åc
The positions in the sequence are numbered sequentially, starting from zero.

To impress Elly you want to write a program which can quickly answer any question of the following type:
"How many ones are in Elly's sequence at positions from L to R, inclusive?"

You are given the long longs L and R.
Return the total number of ones whose positions lie in the interval [L, R].


DEFINITION
Class:EllysCode01
Method:getOnes
Parameters:long long, long long
Returns:long long
Method signature:long long getOnes(long long L, long long R)


CONSTRAINTS
-L and R will be between 0 and 10^18, inclusive.
-L will be less than or equal to R.


EXAMPLES

0)
5
15

Returns: 5

The interval [5, 15] covers the digits 01101[00110010110]1001011001101001. This subsequence contains 5 ones, so the correct answer is 5.


1)
101
185

Returns: 42

The answer is 42.


2)
0
0

Returns: 0

The digit at index zero is 0.


3)
1
1

Returns: 1

The digit at index one is 1.


4)
1337
1337

Returns: 0

The digit at 1337-th position is 0.


5)
12345
67890

Returns: 27772


6)
5192834871235435
954971273487212547

Returns: 474889219307988557

*/
// END CUT HERE
#include <algorithm>
#include <cassert>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class EllysCode01 {
public:
	long long calc(long long x) {
		if (x <= 1) {
			return 0;
		}
		long long b = 1, r = 0;
		while (b <= x) {
			b *= 2;
		}
		b /= 2;
		r += b / 2;
		r += (x - b) / 2;
		if (x % 2) {
			bool f = false;
			--x;
			while (x > 0) {
				if (x >= b) {
					f = !f;
					x -= b;
				}
				b /= 2;
			}
			r += f;
		}
		return r;
	}
public:
	long long getOnes(long long L, long long R) {
		return calc(R + 1) - calc(L);
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
			long long Arg0 = 5LL;
			long long Arg1 = 15LL;
			long long Arg2 = 5LL;

			verify_case(n, Arg2, getOnes(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 101LL;
			long long Arg1 = 185LL;
			long long Arg2 = 42LL;

			verify_case(n, Arg2, getOnes(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 0LL;
			long long Arg1 = 0LL;
			long long Arg2 = 0LL;

			verify_case(n, Arg2, getOnes(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 1LL;
			long long Arg2 = 1LL;

			verify_case(n, Arg2, getOnes(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1337LL;
			long long Arg1 = 1337LL;
			long long Arg2 = 0LL;

			verify_case(n, Arg2, getOnes(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 12345LL;
			long long Arg1 = 67890LL;
			long long Arg2 = 27772LL;

			verify_case(n, Arg2, getOnes(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 5192834871235435LL;
			long long Arg1 = 954971273487212547LL;
			long long Arg2 = 474889219307988557LL;

			verify_case(n, Arg2, getOnes(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			long long Arg0 = 0LL;
			long long Arg1 = 2LL;
			long long Arg2 = 2LL;

			verify_case(n, Arg2, getOnes(Arg0, Arg1));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysCode01 ___test;
	___test.run_test(-1);
}
// END CUT HERE
