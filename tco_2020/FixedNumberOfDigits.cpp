// BEGIN CUT HERE
/*
TCO20 R2B Easy (250)

PROBLEM STATEMENT

You are writing down numbers in increasing order, starting with start and increasing by step.
You stop after writing down numberOfDigits digits total.
You stop immediately, even if it's in the middle of a number.

Calculate and return the last number you wrote.


DEFINITION
Class:FixedNumberOfDigits
Method:sum
Parameters:int, int, long long
Returns:long long
Method signature:long long sum(int start, int step, long long numberOfDigits)


CONSTRAINTS
-start will be between 0 and 10^9, inclusive.
-step will be between 1 and 10, inclusive.
-numberOfDigits will be between 1 and 10^16, inclusive.


EXAMPLES

0)
47
10
7

Returns: 7

You will write down "47, 57, 67, 7" and stop. The last number you wrote down was 7.


1)
98
1
10

Returns: 101

You will write down "98, 99, 100, 101". The last number written down is 101.


2)
0
1
7

Returns: 6


3)
123456789
10
5

Returns: 12345


4)
123456789
10
17

Returns: 12345679

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long LL;

class FixedNumberOfDigits {
public:
	long long sum(int start, int step, long long numberOfDigits) {
		LL r = numberOfDigits;
		LL x = start;
		while (true) {
			LL digits = to_string(x).length();
			LL ed = pow(10, digits);
			LL steps = min((ed - x) / step, (r - 1) / digits);
			x += step * steps;
			r -= digits * steps;

			digits = to_string(x).length();
			if (r <= digits) {
				break;
			}
			x += step;
			r -= digits;
		}
		return stoll(to_string(x).substr(0, r));
	}

	// BEGIN CUT HERE
	long long sum2(int start, int step, long long numberOfDigits) {
		for (LL i = start; i <= 10000; i += step) {
			string s = to_string(i);
			if (s.length() <= numberOfDigits) {
				return stoll(s.substr(0, numberOfDigits));
			}
			numberOfDigits -= s.length();
		}
		return -1;
	}

private:
	template <typename T> string print_array(const vector<T>& V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long& Expected, const long long& Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) {
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 47;
			int Arg1 = 10;
			long long Arg2 = 7LL;
			long long Arg3 = 7LL;

			verify_case(n, Arg3, sum(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 98;
			int Arg1 = 1;
			long long Arg2 = 10LL;
			long long Arg3 = 101LL;

			verify_case(n, Arg3, sum(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 0;
			int Arg1 = 1;
			long long Arg2 = 7LL;
			long long Arg3 = 6LL;

			verify_case(n, Arg3, sum(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 123456789;
			int Arg1 = 10;
			long long Arg2 = 5LL;
			long long Arg3 = 12345LL;

			verify_case(n, Arg3, sum(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 123456789;
			int Arg1 = 10;
			long long Arg2 = 17LL;
			long long Arg3 = 12345679LL;

			verify_case(n, Arg3, sum(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1;
			int Arg1 = 1;
			long long Arg2 = 1;
			long long Arg3 = 1;

			verify_case(n, Arg3, sum(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1;
			int Arg1 = 1;
			long long Arg2 = 1002;
			long long Arg3 = 370;

			verify_case(n, Arg3, sum(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1;
			int Arg1 = 10;
			long long Arg2 = 100000000000;
			long long Arg3 = 9191919191;

			verify_case(n, Arg3, sum(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1;
			int Arg1 = 10;
			long long Arg2 = 10000000000000000LL;
			long long Arg3 = 6319444;

			verify_case(n, Arg3, sum(Arg0, Arg1, Arg2));
		}
		n++;

	}

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FixedNumberOfDigits ___test;
	___test.run_test(-1);

	for (int st = 0; st <= 50; ++st) {
		for (int step = 1; step <= 10; ++step) {
			for (int t = 0; t < 100; ++t) {
				int d = 1 + (rand() % 10000);
				LL a = ___test.sum(st, step, d);
				LL b = ___test.sum(st, step, d);
				if (a != b) {
					cout << "FAILED" << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
// END CUT HERE
