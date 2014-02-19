// BEGIN CUT HERE
/*
SRM 596 Div2 Hard (1000)

PROBLEM STATEMENT
For an integer n, let F(n) = (n - 0^2) * (n - 1^2) * (n - 2^2) * (n - 3^2) * ... * (n - k^2), where k is the largest integer such that n - k^2 > 0.
You are given three long longs lo, hi and divisor.
It is guaranteed that divisor will be a prime number.
Compute and return the number of integers n between lo and hi, inclusive, such that F(n) is divisible by divisor.

DEFINITION
Class:SparseFactorialDiv2
Method:getCount
Parameters:long long, long long, long long
Returns:long long
Method signature:long long getCount(long long lo, long long hi, long long divisor)


CONSTRAINTS
-lo will be between 1 and 1,000,000,000,000, inclusive.
-hi will be between lo and 1,000,000,000,000, inclusive.
-divisor will be between 2 and 997, inclusive.
-divisor will be a prime number.


EXAMPLES

0)
4
8
3

Returns: 3

The value of F(n) for each n = 4, 5, ..., 8 is as follows. 

F(4) = 4*3   = 12
F(5) = 5*4*1 = 20
F(6) = 6*5*2 = 60
F(7) = 7*6*3 = 126
F(8) = 8*7*4 = 224

Thus, F(4), F(6), F(7) are divisible by 3 but F(5) and F(8) are not.


1)
9
11
7

Returns: 1


F(9)  = 9*8*5     = 360
F(10) = 10*9*6*1  = 540
F(11) = 11*10*7*2 = 1540

Only F(11) is divisible by 7.


2)
1
1000000000000
2

Returns: 999999999999

Watch out for the overflow. 


3)
16
26
11

Returns: 4


4)
10000
20000
997

Returns: 1211


5)
123456789
987654321
71

Returns: 438184668

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class SparseFactorialDiv2 {
	LL calc(LL n, LL divisor) {
		LL cnt = 0;
		int f[1000] = {};
		for (LL x = 0; ; ++x) {
			LL sq = x*x;
			LL z = n - sq;
			if (z <= 0) {
				break;
			}
			LL r = sq % divisor;
			if (f[r]) {
				continue;
			}
			f[r] = 1;
			cnt += z / divisor;
		}
		return cnt;
	}

public:
	long long getCount(long long lo, long long hi, long long divisor) {
		return calc(hi, divisor) - calc(lo-1, divisor);
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
			long long Arg1 = 8LL;
			long long Arg2 = 3LL;
			long long Arg3 = 3LL;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 9LL;
			long long Arg1 = 11LL;
			long long Arg2 = 7LL;
			long long Arg3 = 1LL;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 1000000000000LL;
			long long Arg2 = 2LL;
			long long Arg3 = 999999999999LL;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 16LL;
			long long Arg1 = 26LL;
			long long Arg2 = 11LL;
			long long Arg3 = 4LL;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 10000LL;
			long long Arg1 = 20000LL;
			long long Arg2 = 997LL;
			long long Arg3 = 1211LL;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 123456789LL;
			long long Arg1 = 987654321LL;
			long long Arg2 = 71LL;
			long long Arg3 = 438184668LL;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 2LL;
			long long Arg2 = 2LL;
			long long Arg3 = 1LL;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 2LL;
			long long Arg2 = 3LL;
			long long Arg3 = 0LL;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SparseFactorialDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
