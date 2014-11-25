// BEGIN CUT HERE
/*
SRM 599 Div2 Medium (500)

PROBLEM STATEMENT
You are given four ints A, B, C and D.
Return "divisible" (quotes for clarity) if A^B is divisible by C^D. Return "not divisible" otherwise.


DEFINITION
Class:BigFatInteger2
Method:isDivisible
Parameters:int, int, int, int
Returns:string
Method signature:string isDivisible(int A, int B, int C, int D)


NOTES
-The return value is case-sensitive.
-Positive integer y divides a positive integer x if and only if there is a positive integer z such that y*z=x. In particular, for each positive integer x, both 1 and x divide x.


CONSTRAINTS
-A, B, C and D will each be between 1 and 1,000,000,000 (109), inclusive.


EXAMPLES

0)
6
1
2
1

Returns: "divisible"

Here, AB = 61 = 6 and CD = 21 = 2. 6 is divisible by 2.


1)
2
1
6
1

Returns: "not divisible"

2 is not divisible by 6.


2)
1000000000
1000000000
1000000000
200000000

Returns: "divisible"

Now the numbers are huge, but we can see that AB is divisible by CD from the fact that A=C and B>D.


3)
8
100
4
200

Returns: "not divisible"

We can rewrite 8100 as (23)100 = 2300.
Similarly, 4200 = (22)200 = 2400.
Thus, 8100 is not divisible by 4200.


4)
999999937
1000000000
999999929
1

Returns: "not divisible"

Here A and C are distinct prime numbers, which means AB cannot have C as its divisor.


5)
2
2
4
1

Returns: "divisible"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class BigFatInteger2 {

	bool check(LL A, LL B, LL C, LL D) {
		for (LL i = 2; i < 32000; ++i) {
			LL x = 0, y = 0;
			while ((A % i) == 0) {
				++x;
				A /= i;
			}
			while ((C % i) == 0) {
				++y;
				C /= i;
			}
			if (y > 0 && x*B < y*D) {
				return false;
			}
		}
		if (C > 1) {
			return A == C && B >= D;
		}
		return true;
	}

public:
	string isDivisible(int A, int B, int C, int D) {
		return check(A, B, C, D) ? "divisible" : "not divisible";
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
			int Arg0 = 6;
			int Arg1 = 1;
			int Arg2 = 2;
			int Arg3 = 1;
			string Arg4 = "divisible";

			verify_case(n, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;
			int Arg2 = 6;
			int Arg3 = 1;
			string Arg4 = "not divisible";

			verify_case(n, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000000;
			int Arg1 = 1000000000;
			int Arg2 = 1000000000;
			int Arg3 = 200000000;
			string Arg4 = "divisible";

			verify_case(n, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arg1 = 100;
			int Arg2 = 4;
			int Arg3 = 200;
			string Arg4 = "not divisible";

			verify_case(n, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 999999937;
			int Arg1 = 1000000000;
			int Arg2 = 999999929;
			int Arg3 = 1;
			string Arg4 = "not divisible";

			verify_case(n, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 4;
			int Arg3 = 1;
			string Arg4 = "divisible";

			verify_case(n, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000000;
			int Arg1 = 1000000000;
			int Arg2 = 536870912;
			int Arg3 = 310344827;
			string Arg4 = "divisible";

			verify_case(n, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000000;
			int Arg1 = 1000000000;
			int Arg2 = 536870912;
			int Arg3 = 1000000000;
			string Arg4 = "not divisible";

			verify_case(n, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 999999986;
			int Arg1 = 1000000000;
			int Arg2 = 499999993;
			int Arg3 = 1000000000;
			string Arg4 = "divisible";

			verify_case(n, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BigFatInteger2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
