// BEGIN CUT HERE
/*
SRM 628 Div1 Easy (250)

PROBLEM STATEMENT
Halina is a young mathematician.
Recently she has been studying an interesting function h that operates on positive integers.

Let d(n) be the number of distinct positive divisors of n.
The function h is then defined as follows: for each n we have h(n) = n^d(n).
In words, h(n) is defined as n to the power of d(n).

For example, d(6)=4 because 6 is divisible by 1, 2, 3, and 6.
Then, h(6) = 6^4 = 1296.

Halina already knows how to compute her function h.
Now she would like to compute the inverse function.
Help her!

You are given a long long n.
Return the smallest x such that h(x) = n.
If there is no such x, return -1 instead.

DEFINITION
Class:DivisorsPower
Method:findArgument
Parameters:long long
Returns:long long
Method signature:long long findArgument(long long n)


CONSTRAINTS
-n will be between 2 and 10^18, inclusive.


EXAMPLES

0)
4

Returns: 2

d(2) = 2, h(2) = 4


1)
10

Returns: -1

There is no x satisfying h(x) = 10.


2)
64

Returns: 4

d(4) = 3, h(4) = 64


3)
10000

Returns: 10

d(10) = 4, h(10) = 10000


4)
2498388559757689

Returns: 49983883

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

int divisors(LL n) {
	int cnt = 1;
	LL x;
	for (x = 2; x*x < n; ++x) {
		cnt += (n % x) == 0;
	}
	return 2 * cnt + (x*x == n);
}

class DivisorsPower {

public:
	long long findArgument(long long n) {
		for (LL x = 2; x <= 1000000; ++x) {
			LL a = x;
			for (int y = 2; ; ++y) {
				LL prev = a;
				a *= x;
				if (a == n && a/x == prev && divisors(x) == y) {
					return x;
				}
				if (a > n || prev > a) {
					break;
				}
			}
		}
		LL a = (LL)sqrt((long double)n);
		if (a*a == n && divisors(a) == 2) {
			return a;
		}
		return -1;
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
			long long Arg0 = 4LL;
			long long Arg1 = 2LL;

			verify_case(n, Arg1, findArgument(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 10LL;
			long long Arg1 = -1LL;

			verify_case(n, Arg1, findArgument(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 64LL;
			long long Arg1 = 4LL;

			verify_case(n, Arg1, findArgument(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 10000LL;
			long long Arg1 = 10LL;

			verify_case(n, Arg1, findArgument(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 2498388559757689LL;
			long long Arg1 = 49983883LL;

			verify_case(n, Arg1, findArgument(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			long long Arg0 = 6756327210616080LL;
			long long Arg1 = -1;

			verify_case(n, Arg1, findArgument(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DivisorsPower ___test;
	___test.run_test(-1);
}
// END CUT HERE
