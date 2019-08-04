// BEGIN CUT HERE
/*
TCO 2019 Round 4 Easy (250)

PROBLEM STATEMENT

Each of the digits 0 through 9 has a value that is in {0, 1, 2}.
At least one of the digits has value 0.
These values are given: the value of digit x is base[x].

For any bigger positive integer n, the value of n is one greater than the value of p(n), where p is the product of digits of n.

You are given the number goal.
Return the smallest nonnegative integer with value goal.
You may assume that for any valid input the output value exists and does not exceed 10^18.


DEFINITION
Class:ReProduct
Method:minimize
Parameters:vector <int>, int
Returns:long long
Method signature:long long minimize(vector <int> base, int goal)


CONSTRAINTS
-base will contain exactly 10 elements.
-Each element in base will be between 0 and 2, inclusive.
-The smallest element in base will be 0.
-k will be between 0 and 11, inclusive.


EXAMPLES

0)
{0,1,1,1,1,1,1,1,1,1}
2

Returns: 11


As given, the number 0 has value 0.
As given, each of the numbers 1-9 has value 1.
The number 10 has value 1 (because the number 1*0 = 0 has value 0).
The number 11 has value 2 (because the number 1*1 = 1 has value 1). Thus, 11 is the smallest number with value 2.


1)
{0,0,0,0,0,0,0,0,0,0}
3

Returns: 39

We have value(39) = 1 + value(27) = 2 + value(14) = 3 + value(4) = 3, and no smaller number has value 3.


2)
{2,0,0,0,0,0,0,0,0,0}
2

Returns: 0


3)
{2,2,2,2,2,2,2,2,0,2}
1

Returns: 18


4)
{2,1,2,2,1,1,1,0,1,0}
6

Returns: 268

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

LL calc(const vector <int>& base, LL x) {
	if (x <= 9) {
		return base[x];
	}
	LL r;
	for (r = 1; x > 0; x /= 10) {
		r *= x % 10;
	}
	return 1 + calc(base, r);
}

class ReProduct {

public:
	long long minimize(vector <int> base, int goal) {
		for (LL x = 0; x < 1000000; ++x) {
			if (calc(base, x) == goal) {
				return x;
			}
		}

		// http://oeis.org/A003001
		const vector<LL> pre = { 0, 10, 25, 39, 77, 679, 6788, 68889, 2677889, 26888999, 3778888999LL, 277777788888899LL };
		for (LL x : pre) {
			if (calc(base, x) == goal) {
				return x;
			}
		}

		return -1;
	}

	// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T>& V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long& Expected, const long long& Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) {
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 0,1,1,1,1,1,1,1,1,1 };
			int Arg1 = 2;
			long long Arg2 = 11LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minimize(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 0,0,0,0,0,0,0,0,0,0 };
			int Arg1 = 3;
			long long Arg2 = 39LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minimize(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 2,0,0,0,0,0,0,0,0,0 };
			int Arg1 = 2;
			long long Arg2 = 0LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minimize(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 2,2,2,2,2,2,2,2,0,2 };
			int Arg1 = 1;
			long long Arg2 = 18LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minimize(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 2,1,2,2,1,1,1,0,1,0 };
			int Arg1 = 6;
			long long Arg2 = 268LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minimize(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 0,1,0,0,1,0,0,1,1,0 };
			int Arg1 = 9;
			long long Arg2 = 26888999LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minimize(Arg0, Arg1));
		}
		n++;

	}

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ReProduct ___test;
	___test.run_test(-1);
}
// END CUT HERE
