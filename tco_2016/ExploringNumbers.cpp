// BEGIN CUT HERE
/*
TCO 2016 Round 1B Easy (250)

PROBLEM STATEMENT

Vasa likes to construct sequences of numbers. If you tell him a positive integer n,
he will begin a new sequence by writing the integer n as its first element.
He will then repeat the following steps:

If the last number in his sequence is a prime, he terminates the sequence.
If he already wrote n elements without finding a prime, he becomes bored and leaves.
Otherwise, he computes the next element of the sequence as the sum of squares of digits of the last element.
For example, 4001 will be followed by 4^2 + 0^2 + 0^2 + 1^2 = 17, and 17 will be followed by 1^2 + 7^2 = 50.

Find out what happens for the given int n. If Vasa eventually becomes bored and leaves, return -1.
Otherwise, return the length of the generated sequence.


DEFINITION
Class:ExploringNumbers
Method:numberOfSteps
Parameters:int
Returns:int
Method signature:int numberOfSteps(int n)


NOTES
-A prime number is a positive integer with exactly two positive integer divisors: 1 and itself.
 The first few primes are 2, 3, 5, 7, 11. Note that 1 is not a prime.


CONSTRAINTS
-n will be between 1 and 10^9, inclusive.


EXAMPLES

0)
5

Returns: 1

The input itself is a prime.


1)
57

Returns: 4

Vasa will write down 57, 74 (= 5^2 + 7^2), 65 (= 7^2 + 4^2), and 61 (= 6^2 + 5^2). Number 61 is a prime.


2)
1

Returns: -1

Vasa begins by writing down the number 1. As 1 is not a prime, he is not done yet. As he already wrote down 1 element of the sequence without finding a prime, he becomes bored and leaves.


3)
6498501

Returns: 2


4)
989113

Returns: 6


5)
12366

Returns: -1

For n=12366 there are no primes among the first 12366 elements of Vasa's sequence.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class ExploringNumbers {

	vector<int> primes;

	void gen_prime(int N) {
		primes.push_back(2);
		primes.push_back(3);
		int n;
		for (n = 5; n <= N; n += 2) {
			const int *r = &primes[1];
			int p;
			while (((p = *r++) * p) < n && (n % p) != 0) {
				;
			}
			if ((p * p) > n) {
				primes.push_back(n);
			}
		}
	}

	bool is_prime(int n) {
		if (n <= 1) {
			return false;
		}
		for (int p : primes) {
			if (p >= n) {
				break;
			}
			if ((n % p) == 0) {
				return false;
			}
		}
		return true;
	}

public:
	int numberOfSteps(int n) {
		if (primes.size() <= 0) {
			gen_prime(32000);
		}
		set<int> p(primes.begin(), primes.end());
		set<int> m;
		int a = n;
		for (int i = 0; i < n; ++i) {
			if (m.find(a) != m.end()) {
				return -1;
			}
			m.insert(a);
			if (is_prime(a)) {
				return i + 1;
			}
			int b = a;
			a = 0;
			while (b) {
				a += (b % 10) * (b % 10);
				b /= 10;
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
			int Arg0 = 5;
			int Arg1 = 1;

			verify_case(n, Arg1, numberOfSteps(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 57;
			int Arg1 = 4;

			verify_case(n, Arg1, numberOfSteps(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = -1;

			verify_case(n, Arg1, numberOfSteps(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6498501;
			int Arg1 = 2;

			verify_case(n, Arg1, numberOfSteps(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 989113;
			int Arg1 = 6;

			verify_case(n, Arg1, numberOfSteps(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 12366;
			int Arg1 = -1;

			verify_case(n, Arg1, numberOfSteps(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ExploringNumbers ___test;
	___test.run_test(-1);
}
// END CUT HERE
