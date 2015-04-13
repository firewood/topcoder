// BEGIN CUT HERE
/*
TCO 2015 Round 1A Easy (250)

PROBLEM STATEMENT
Given two positive integers x and y, their similarity S(x, y) is defined as follows:
To compute S(x, y) we count all d between 0 and 9, inclusive, such that both x and y contain the digit d when written in base 10 (without any leading zeros).
For example, S(1123, 220181) = 2 since both numbers contain the digit 1 and both contain the digit 2.

You are given two ints L and R that define a range.
Find two distinct integers in this range that have the largest similarity.
Formally, return the maximum of S(a, b) over all a, b such that L <= a < b <= R.


DEFINITION
Class:Similars
Method:maxsim
Parameters:int, int
Returns:int
Method signature:int maxsim(int L, int R)


CONSTRAINTS
-R will be between 2 and 100,000, inclusive.
-L will be between 1 and R - 1, inclusive.


EXAMPLES

0)
1
10

Returns: 1

We have S(1, 10) = 1 since both numbers contain the digit 1. All other pairs of numbers within this range have similarity 0.


1)
1
99

Returns: 2

There are many pairs with similarity 2, for example pairs (23,32) and (38,83).


2)
99
100

Returns: 0

Here we have only one pair (99, 100) and its similarity is 0.


3)
1000
1010

Returns: 2


4)
444
454

Returns: 2

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

typedef set<int> IntSet;

static inline int popcount(unsigned int b)
{
#ifdef __GNUC__
	return __builtin_popcount(b);
#elif _MSC_VER >= 1400
	return __popcnt(b);
#else
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	b += b >> 16;
	return b & 0x3F;
#endif
}

class Similars {
public:
	int maxsim(int L, int R) {
		int cnt[1024] = {};
		for (int n = L; n <= R; ++n) {
			char d[64];
			sprintf(d, "%d", n);
			int len = strlen(d);
			int b = 0;
			for (int i = 0; i < len; ++i) {
				b |= (1 << (d[i] - '0'));
			}
			cnt[b] += 1;
		}
		int ans = 0;
		for (int i = 1; i < 1024; ++i) {
			if (cnt[i] <= 0) {
				continue;
			}
			if (cnt[i] >= 2) {
				ans = max(ans, popcount(i));
			}
			for (int j = i + 1; j < 1024; ++j) {
				if (cnt[j] > 0 && (i & j)) {
					ans = max(ans, popcount(i&j));
				}
			}
		}
		return ans;
	}


// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 10;
			int Arg2 = 1;

			verify_case(n, Arg2, maxsim(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 99;
			int Arg2 = 2;

			verify_case(n, Arg2, maxsim(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 99;
			int Arg1 = 100;
			int Arg2 = 0;

			verify_case(n, Arg2, maxsim(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000;
			int Arg1 = 1010;
			int Arg2 = 2;

			verify_case(n, Arg2, maxsim(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 444;
			int Arg1 = 454;
			int Arg2 = 2;

			verify_case(n, Arg2, maxsim(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 100000;
			int Arg2 = 5;

			verify_case(n, Arg2, maxsim(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Similars ___test;
	___test.run_test(-1);
}
// END CUT HERE
