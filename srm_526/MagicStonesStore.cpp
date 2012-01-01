// BEGIN CUT HERE
/*
// SRM 526.5 Div2 Easy (250)
// PROBLEM STATEMENT
// Today is the Christmas Eve. People around the world celebrate this 
holiday. The following story takes place in the land of reindeer, where Santa Claus resides.

The currency in the land of reindeer are magic stones. Santa's reindeer have 2n magic stones
(i.e., an even number of them). They want to divide the stones into two piggy banks.
Santa's reindeer are very fond of primes, therefore they want each piggy bank
to contain a prime number of magic stones.

You are given an int n. If it is possible to divide 2n magic stones into two piggy banks,
each containing a prime number of stones, return "YES", otherwise return "NO" (quotes for clarity).

DEFINITION
Class:MagicStonesStore
Method:ableToDivide
Parameters:int
Returns:string
Method signature:string ableToDivide(int n)


NOTES
-A positive integer is prime if and only if it has exactly two positive integer divisors.
 The first few prime numbers are 2, 3, 5, 7, 11, ...
-The number zero is not a prime number, hence you are not allowed to leave any piggy bank empty.


CONSTRAINTS
-n will be between 1 and 1,000, inclusive.


EXAMPLES

0)
1

Returns: "NO"

As n=1, we are dividing 2 magic stones into two piggy banks.
In this case is impossible to have a prime number of stones in each piggy bank.

1)
2

Returns: "YES"

The only valid way of dividing the stones in this case is to put 2 magic stones
into each of the piggy banks.

2)
3

Returns: "YES"

Now the only way is to put 3 magic stones into each of the piggy banks.

3)
5

Returns: "YES"

For 2n=10 stones we have two valid ways of dividing them: either as 5 + 5 or as 7 + 3.

#line 64 "MagicStonesStore.cpp"
*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef set<int> IntSet;

class MagicStonesStore {
	IntSet prime;

	void gen_prime(int n) {
		prime.insert(2);
		int i, j;
		for (i = 3; i <= n; i += 2) {
			for (j = 3; (i % j) && j*j <= i; j += 2) {
				;
			}
			if (j*j > i) {
				prime.insert(i);
			}
		}
	}

public:
	MagicStonesStore(void) {
		gen_prime(2001);
	}

	string ableToDivide(int n) {
		n *= 2;
		IntSet::const_iterator it;
		for (it = prime.begin(); it != prime.end(); ++it) {
			int x = n - *it;
			if (x < 2) {
				break;
			}
			if (prime.find(x) != prime.end()) {
				return "YES";
			}
		}
		return "NO";
	}
	
// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			string Arg1 = "NO";

			verify_case(n, Arg1, ableToDivide(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			string Arg1 = "YES";

			verify_case(n, Arg1, ableToDivide(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			string Arg1 = "YES";

			verify_case(n, Arg1, ableToDivide(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			string Arg1 = "YES";

			verify_case(n, Arg1, ableToDivide(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicStonesStore ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
