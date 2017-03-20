// BEGIN CUT HERE
/*
SRM 699 Div2 Medium (500)

PROBLEM STATEMENT
Limak chose a positive integer X and wrote it on a blackboard.
After that, every day he erased the last digit of the current number.
He stopped when he erased all digits.

After the process was over, Limak computed the sum of all numbers that appeared on the blackboard, including the original number X.

For example, if the original number was 509, the numbers that appeared on the blackboard were the numbers 509, 50, and 5.
Their sum is 564.

You are given a long long S.
Limak wants you to find a number X such that the above process produces the sum S.
It can be shown that for any positive S there is at most one valid X.
If there is a valid X, find and return it.
Otherwise, return -1.


DEFINITION
Class:LastDigit
Method:findX
Parameters:long long
Returns:long long
Method signature:long long findX(long long S)


CONSTRAINTS
-S will be between 1 and 10^18, inclusive.


EXAMPLES

0)
564

Returns: 509

This is the example from the problem statement. The value X = 509 produces the sum 564, as shown above.


1)
565

Returns: -1

There is no X for which the sum would be 565.


2)
3000

Returns: 2701

You can check that 2701 + 270 + 27 + 2 = 3000.


3)
137174210616796

Returns: 123456789555123


4)
837592744927492746

Returns: -1


5)
999999999999999999

Returns: 900000000000000000

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

class LastDigit {
	LL sum(LL n) {
		LL s = 0;
		while (n) {
			s += n;
			n /= 10;
		}
		return s;
	}

public:
	long long findX(long long S) {
		LL low = S / 2, high = S + 1;
		while (high - low > 1) {
			LL mid = (low + high) / 2;
			if (sum(mid) > S) {
				high = mid;
			} else {
				low = mid;
			}
		}
		return sum(low) == S ? low : -1;
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
			long long Arg0 = 564LL;
			long long Arg1 = 509LL;

			verify_case(n, Arg1, findX(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 565LL;
			long long Arg1 = -1LL;

			verify_case(n, Arg1, findX(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 3000LL;
			long long Arg1 = 2701LL;

			verify_case(n, Arg1, findX(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 137174210616796LL;
			long long Arg1 = 123456789555123LL;

			verify_case(n, Arg1, findX(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 837592744927492746LL;
			long long Arg1 = -1LL;

			verify_case(n, Arg1, findX(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 999999999999999999LL;
			long long Arg1 = 900000000000000000LL;

			verify_case(n, Arg1, findX(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			long long Arg0 = 1;
			long long Arg1 = 1;

			verify_case(n, Arg1, findX(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LastDigit ___test;
	___test.run_test(-1);
}
// END CUT HERE
