// BEGIN CUT HERE
/*
TCO20 R1B Hard (900)

PROBLEM STATEMENT

Elly calls a positive integer a different prime if it's a prime number and all its digits are distinct.
For example, 13, 5419, and 102345697 are different primes but 1234 and 131 aren't.
(The number 1234 is not a prime number and the number 131 has a repeated digit.)

Given a positive int N, return the different prime that is closest to N.
If there are two different primes tied for being the closest one to N, return the smaller of the two.


DEFINITION
Class:EllysDifferentPrimes
Method:getClosest
Parameters:int
Returns:int
Method signature:int getClosest(int N)


NOTES
-A prime number (or a prime) is a natural number greater than 1 that has no positive divisors other than 1 and itself. Thus, the first few primes are 2, 3, 5, 7, 11, 13, 17, ...


CONSTRAINTS
-N will be between 1 and 50,000,000, inclusive.


EXAMPLES

0)
100

Returns: 97

The closest prime number to 100 is 101, but this is not a valid answer because the digit 1 occurs twice in 101. The next two closest primes to 100 are 97 and 103. Both of them are different primes and both of them have the difference 3 from N. In this situation we should return the smaller of the two numbers, so the correct return value is 97.


1)
123457

Returns: 123457

The number 123457 itself is a different prime.


2)
6661337

Returns: 6701459

Sometimes the answer is a number larger than N.


3)
42424242

Returns: 42398701

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

class EllysDifferentPrimes {

	vector<int> primes;

	vector<int> gen_primes(int m) {
		vector<int> primes;
		primes.push_back(2);
		for (int i = 3; i <= m; i += 2) {
			for (int prime : primes) {
				if (i < prime * prime) {
					primes.push_back(i);
					break;
				}
				if ((i % prime) == 0) {
					break;
				}
			}
		}
		return primes;
	}

	bool is_prime(int n) {
		if (n <= 1) {
			return false;
		}

		for (int p : primes) {
			if (p >= n) {
				return true;
			}
			if ((n % p) == 0) {
				return false;
			}
		}
		return true;
	}

public:
	int getClosest(int N) {
		if (primes.empty()) {
			primes = gen_primes(40000);
		}

		for (int i = 0; ; ++i) {
			for (int j = -1; j <= 1; j += 2) {
				int k = N + i * j;
				if (is_prime(k)) {
					if ([](int n) {
						char cnt[10] = {};
						while (n > 0) {
							if (++cnt[n % 10] >= 2) {
								return false;
							}
							n /= 10;
						}
						return true;
					}(k)) {
						return k;
					}
				}
			}
		}
		return N;
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
			int Arg1 = 97;

			verify_case(n, Arg1, getClosest(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 123457;
			int Arg1 = 123457;

			verify_case(n, Arg1, getClosest(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6661337;
			int Arg1 = 6701459;

			verify_case(n, Arg1, getClosest(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 42424242;
			int Arg1 = 42398701;

			verify_case(n, Arg1, getClosest(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 50000000;
			int Arg1 = 50123467;

			verify_case(n, Arg1, getClosest(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysDifferentPrimes ___test;
	___test.run_test(-1);
}
// END CUT HERE
