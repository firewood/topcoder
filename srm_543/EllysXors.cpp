// BEGIN CUT HERE
/*
// SRM 543 Div1 Easy (250)

// PROBLEM STATEMENT
// XOR problems became very popular in TopCoder recently. (If you do not know
the bitwise operation XOR, see the Notes section for an explanation.) That's
why Elly decided to invent one of her own. Fortunately for you, the one she
came up with is quite simple. You are given two long longs L and R. She wants
you to find the XOR of all numbers between L and R, inclusive.

DEFINITION
Class:EllysXors
Method:getXor
Parameters:long long, long long
Returns:long long
Method signature:long long getXor(long long L, long long R)


NOTES
-XOR (exclusive or) is a binary operation, performed on two numbers in binary
 notation. First, the shorter number is prepended with leading zeroes until
 both numbers have the same number of digits (in binary). Then, the result is
 calculated as follows: for each bit where the numbers differ the result has 1
 in its binary representation. It has 0 in all other positions.
-For example 42 XOR 7 is performed as follows. First, the numbers are
 converted to binary: 42 is 101010 and 7 is 111. Then the shorter number is
 prepended with leading zeros until both numbers have the same number of digits.
 This means 7 becomes 000111. Then 101010 XOR 000111 = 101101 (the result has
 ones only in the positions where the two numbers differ). Then the result can
 be converted back to decimal notation. In this case 101101 = 45, so 42 XOR 7 = 45.
-One of the ways to calculate the XOR of more than two numbers A1, A2, ..., An
 is "A1 XOR (A2 XOR (... XOR An))..))". Since the function is commutative and
 associative, you can also express it as "A1 XOR A2 XOR ... XOR An" and group
 the operands in any way you like.
-It can be proved that the answer is always less than 2*R for the given constraints.


CONSTRAINTS
-L and R will be between 1 and 4,000,000,000, inclusive.
-L will be less than or equal to R.


EXAMPLES

0)
3
10

Returns: 8


((((((3 XOR 4) XOR 5) XOR 6) XOR 7) XOR 8) XOR 9) XOR 10 =
        (((((7 XOR 5) XOR 6) XOR 7) XOR 8) XOR 9) XOR 10 = 
                ((((2 XOR 6) XOR 7) XOR 8) XOR 9) XOR 10 = 
                        (((4 XOR 7) XOR 8) XOR 9) XOR 10 = 
                                ((3 XOR 8) XOR 9) XOR 10 =
                                       (11 XOR 9) XOR 10 =
                                                2 XOR 10 = 8.


1)
5
5

Returns: 5

The XOR of a single number is the number itself.


2)
13
42

Returns: 39

A bit larger example.


3)
666
1337

Returns: 0

The answer can be zero.


4)
1234567
89101112

Returns: 89998783

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class EllysXors {

	static LL f(LL x) {
		switch (x & 3) {
		case 0:
			return x;
		case 1:
			return 1;
		case 2:
			return x | 1;
		default:
			return 0;
		}
	}

public:
	long long getXor(long long L, long long R) {
#if 1
		LL res = f(L-1) ^ f(R);
#else
		LL res = 0;
		LL x;
		for (x = L; x <= R; ++x) {
			res ^= x;
			if ((R-x) >= 4 && (x&1) == 1) {
				x += (R-x) & ~3;
			}
		}
#endif
		return res;
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
			long long Arg0 = 3LL;
			long long Arg1 = 10LL;
			long long Arg2 = 8LL;

			verify_case(n, Arg2, getXor(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 5LL;
			long long Arg1 = 5LL;
			long long Arg2 = 5LL;

			verify_case(n, Arg2, getXor(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 13LL;
			long long Arg1 = 42LL;
			long long Arg2 = 39LL;

			verify_case(n, Arg2, getXor(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 666LL;
			long long Arg1 = 1337LL;
			long long Arg2 = 0LL;

			verify_case(n, Arg2, getXor(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1234567LL;
			long long Arg1 = 89101112LL;
			long long Arg2 = 89998783LL;

			verify_case(n, Arg2, getXor(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			long long Arg0 = 0LL;
			long long Arg1 = 0LL;
			long long Arg2 = 0LL;

			verify_case(n, Arg2, getXor(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysXors ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
