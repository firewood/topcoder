// BEGIN CUT HERE
/*
// SRM 524 Div2 Medium (500)
// PROBLEM STATEMENT
// You found n Magic Diamonds in the mountain. You are now thinking about transfering them to your home.
The only way you can transfer Magic Diamonds is to use Transfer Magic one or more times.


The Magic Diamonds are very strange.
For any positive integer x you can use Transfer Magic to transfer x Magic Diamonds at once. However, if x is a prime number, the Magic Diamonds will disappear instead of getting transferred. You are not allowed to lose any of the Magic Diamonds, therefore you may never use Transfer Magic on a prime number of Magic Diamonds. Your task is to transfer all Magic Diamonds using Transfer Magic as few times as possible.



You are given a long long n. Return the minimal number of Transfer Magic usages you need to transfer n Magic Diamonds.

DEFINITION
Class:MagicDiamonds
Method:minimalTransfer
Parameters:long long
Returns:long long
Method signature:long long minimalTransfer(long long n)


NOTES
-A positive integer x is a prime number if and only if it has exactly 2 divisors: 1 and x. Note that 1 is not a prime number.
-Your task can always be accomplished. For example, you can use Transfer Magic n times and transfer 1 Magic Diamond each time.


CONSTRAINTS
-n will be between 1 and 1,000,000,000,000 (10^12), inclusive.


EXAMPLES

0)
2

Returns: 2

We have to use Transfer Magic twice, each time we transfer 1 Magic Diamond.

1)
4294967297

Returns: 1

We just need to use Transfer Magic once, because 4294967297 is not a prime. We have 4294967297 = 641 * 6700417.

2)
2147483647

Returns: 2

This time n is a prime, so we have to use Transfer Magic at least twice. We have 2147483647 = 2147400000 + 83647 (83647 = 233 * 359, which is not a prime), thus the answer is 2.

3)
1

Returns: 1



#line 64 "MagicDiamonds.cpp"
*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

class MagicDiamonds {

public:
	long long minimalTransfer(long long n) {
		if (n <= 3) {
			return n;
		}
		if ((n % 2) == 0) {
			return 1;
		}
		LL x;
		for (x = 3; x*x <= n; x += 2) {
			if ((n % x) == 0) {
				return 1;
			}
		}
		return 2;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 2LL; verify_case(0, Arg1, minimalTransfer(Arg0)); }
	void test_case_1() { long long Arg0 = 4294967297LL; long long Arg1 = 1LL; verify_case(1, Arg1, minimalTransfer(Arg0)); }
	void test_case_2() { long long Arg0 = 2147483647LL; long long Arg1 = 2LL; verify_case(2, Arg1, minimalTransfer(Arg0)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 1LL; verify_case(3, Arg1, minimalTransfer(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicDiamonds ___test;
	___test.run_test(0);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
