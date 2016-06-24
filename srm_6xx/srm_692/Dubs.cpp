// BEGIN CUT HERE
/*
SRM 692 Div2 Medium (500)

PROBLEM STATEMENT

A positive integer X is called a double number if its decimal representation (without leading zeroes) has the following properties:

it contains at least two digits
the two least significant digits are identical

For example, 1488 is a double number, but 3 and 221 are not.

You are given two long longs: L and R. Compute how many double numbers lie between L and R, inclusive. Return their count.


DEFINITION
Class:Dubs
Method:count
Parameters:long long, long long
Returns:long long
Method signature:long long count(long long L, long long R)


CONSTRAINTS
-L will be between 10 and 1,000,000,000,000 (10^12), inclusive.
-R will be between L and 1,000,000,000,000 (10^12), inclusive.


EXAMPLES

0)
10
10

Returns: 0

The only number in the range [10,10] is 10. It isn't a double number.


1)
10
20

Returns: 1

The only double number in the range [10,20] is 11.


2)
49
101

Returns: 6

The double numbers are 55, 66, 77, 88, 99 and 100.


3)
1111111
111111111

Returns: 11000001


4)
91750002841
91751522033

Returns: 151920

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

class Dubs {
public:
	long long count(long long L, long long R) {
		long long ans = 0;
		LL a = ((L + 99) / 100) * 100;
		while (L < a && L < R) {
			ans += ((L % 100) % 11) == 0;
			++L;
		}
		a = ((R - 1) / 100) * 100;
		if (a > L) {
			ans += (a - L) / 10;
			L = a;
		}
		while (L <= R) {
			ans += ((L % 100) % 11) == 0;
			++L;
		}
		return ans;
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
			long long Arg0 = 10LL;
			long long Arg1 = 10LL;
			long long Arg2 = 0LL;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 10LL;
			long long Arg1 = 20LL;
			long long Arg2 = 1LL;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 49LL;
			long long Arg1 = 101LL;
			long long Arg2 = 6LL;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1111111LL;
			long long Arg1 = 111111111LL;
			long long Arg2 = 11000001LL;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 91750002841LL;
			long long Arg1 = 91751522033LL;
			long long Arg2 = 151920LL;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Dubs ___test;
	___test.run_test(-1);
}
// END CUT HERE
