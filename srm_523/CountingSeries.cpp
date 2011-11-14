// BEGIN CUT HERE
/*
// SRM 523 Div2 Medium (500)
// PROBLEM STATEMENT
// You are given long longs a, b, c and d. The numbers a and b define an arithmetic progression that consists of all numbers of the form a + b*x, where x is a nonnegative integer. Likewise, c and d define a geometric progression that consists of all the numbers that are equal to c * d^y, where y is a nonnegative integer. You are also given a long long upperBound. Return the total number of integers between 1 and upperBound, inclusive, that belong to the arithmetic progression, the geometric progression or both.

DEFINITION
Class:CountingSeries
Method:countThem
Parameters:long long, long long, long long, long long, long long
Returns:long long
Method signature:long long countThem(long long a, long long b, long long c, long long d, long long upperBound)


NOTES
-The ^ operator in this statement denotes the exponentiation operation. For example, 3^0 = 1 and 2^4 = 2*2*2*2 = 16.


CONSTRAINTS
-a, b, c and upperBound will each be between 1 and 1000000000000 (10^12), inclusive.
-d will be between 1 and 100000 (10^5), inclusive.


EXAMPLES

0)
1
1
1
2
1000

Returns: 1000

The arithmetic progression is: 1, 2, 3, 4, ... .
The geometric progression is: 1, 2, 4, 8, 16, ... . 
Each positive integer is contained in at least one of the progressions.

1)
3
3
1
2
1000

Returns: 343

This time, the arithmetic progression is: 3, 6, 9, 12, ... .
The geometric progression is still: 1, 2, 4, 8, 16, ....
There are 333 multiples of 3 between 1 and 1000, inclusive, and there are 10 powers of 2, 512 being the highest. As these two progressions do not have any common elements, the total result is 343.

2)
40
77
40
100000
40

Returns: 1



3)
452
24
4
5
600

Returns: 10

The 10 numbers are: 4, 20, 100, 452, 476, 500, 524, 548, 572 and 596.

4)
234
24
377
1
10000

Returns: 408



#line 86 "CountingSeries.cpp"
*/
// END CUT HERE
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
typedef vector<int> IntVec;
typedef vector<string> StrVec;

class CountingSeries {

public:
	long long countThem(long long a, long long b, long long c, long long d, long long upperBound) {
		LL Min = a;
		LL Max = upperBound - ((upperBound - a) % b);
		LL result = (Max - Min) / b + 1;

		LL x = c;
		while (x <= upperBound) {
			LL y = x - a;
			if (y >= 0 && ((y % b) == 0)) {
				;
			} else {
				++result;
			}
			x *= d;
			if (x <= 0 || d <= 1) {
				break;
			}
		}

		return result;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 1LL; long long Arg2 = 1LL; long long Arg3 = 2LL; long long Arg4 = 1000LL; long long Arg5 = 1000LL; verify_case(0, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { long long Arg0 = 3LL; long long Arg1 = 3LL; long long Arg2 = 1LL; long long Arg3 = 2LL; long long Arg4 = 1000LL; long long Arg5 = 343LL; verify_case(1, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { long long Arg0 = 40LL; long long Arg1 = 77LL; long long Arg2 = 40LL; long long Arg3 = 100000LL; long long Arg4 = 40LL; long long Arg5 = 1LL; verify_case(2, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { long long Arg0 = 452LL; long long Arg1 = 24LL; long long Arg2 = 4LL; long long Arg3 = 5LL; long long Arg4 = 600LL; long long Arg5 = 10LL; verify_case(3, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { long long Arg0 = 234LL; long long Arg1 = 24LL; long long Arg2 = 377LL; long long Arg3 = 1LL; long long Arg4 = 10000LL; long long Arg5 = 408LL; verify_case(4, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CountingSeries ___test;
	___test.run_test(0);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
