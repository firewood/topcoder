// BEGIN CUT HERE
/*
SRM 599 Div1 Easy (250)

PROBLEM STATEMENT
This problem statement contains superscipts that may not display properly outside the applet.

Lun the dog loves very large integers. Her favorite is AB (A to the power of B).

She has an integer variable X. Initially, the value of X is set to 1. She can perform the following two kinds of operations in any order, any number of times.

Operation 1: choose a prime number p, then multiply X by p.
Operation 2: choose a positive divisor d of the value of X at that point, then multiply X by d.

You are given two ints A and B. Return the minimum number of operations Lun needs to perform
in order to obtain X = AB from the initial state X = 1.


DEFINITION
Class:BigFatInteger
Method:minOperations
Parameters:int, int
Returns:int
Method signature:int minOperations(int A, int B)


CONSTRAINTS
-A will be between 2 and 1,000,000 (106), inclusive.
-B will be between 1 and 1,000,000 (106), inclusive.


EXAMPLES

0)
6
1

Returns: 2

Here, AB = 61 = 6. Here is one of the optimal sequences of operations:

Perform operation 1 by choosing p=2. X is now 1*2 = 2.
Perform operation 1 by choosing p=3. X is now 2*3 = 6.


1)
162
1

Returns: 4

One of the optimal sequences of operations:

Perform operation 1 by choosing p=3. X is now 1*3 = 3.
Perform operation 1 by choosing p=3. X is now 3*3 = 9.
Perform operation 2 by choosing d=9. X is now 9*9 = 81.
Perform operation 1 by choosing p=2. X is now 81*2 = 162.


2)
999983
9

Returns: 5

Here, A is prime. One of the optimal sequences of operations:

Perform operation 1 by choosing p=A. X is now A.
Perform operation 1 by choosing p=A. X is now A2.
Perform operation 1 by choosing p=A. X is now A3.
Perform operation 2 by choosing d=A3. X is now A6.
Perform operation 2 by choosing d=A3. X is now A9.


3)
360
8

Returns: 8

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class BigFatInteger {
public:
	int minOperations(int A, int B) {
		LL mul = 0;
		int primes = 0;
		for (int n = 2; n < 1000; ++n) {
			if ((A % n) == 0) {
				++primes;
				LL c = 0;
				while ((A % n) == 0) {
					++c;
					A /= n;
				}
				mul = max(mul, c);
			}
		}
		if (A > 1) {
			++primes;
			mul = max(mul, 1LL);
		}
		mul *= B;
		int ans = primes;
		LL n = 1;
		while (mul > n) {
			n *= 2;
			++ans;
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
			int Arg0 = 6;
			int Arg1 = 1;
			int Arg2 = 2;

			verify_case(n, Arg2, minOperations(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 162;
			int Arg1 = 1;
			int Arg2 = 4;

			verify_case(n, Arg2, minOperations(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 999983;
			int Arg1 = 9;
			int Arg2 = 5;

			verify_case(n, Arg2, minOperations(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 360;
			int Arg1 = 8;
			int Arg2 = 8;

			verify_case(n, Arg2, minOperations(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arg0 = 36;
			int Arg1 = 2;
			int Arg2 = 4;

			verify_case(n, Arg2, minOperations(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arg0 = 216;
			int Arg1 = 5;
			int Arg2 = 6;

			verify_case(n, Arg2, minOperations(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arg1 = 5;
			int Arg2 = 5;

			verify_case(n, Arg2, minOperations(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;
			int Arg2 = 1;

			verify_case(n, Arg2, minOperations(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BigFatInteger ___test;
//	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
