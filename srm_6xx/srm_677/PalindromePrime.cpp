// BEGIN CUT HERE
/*
SRM 677 Div2 Easy (250)

PROBLEM STATEMENT
A positive integer is called a prime if it has exactly two distinct positive integer divisors: 1 and itself.
The first few primes are 2, 3, 5, 7, 11, 13, ...

A positive integer is called a palindrome if its base-10 representation reads the same forwards and backwards.
Some palindromes: 2, 77, 101, 33333, 12344321.

A positive integer is called a palindromic prime if it is both a palindrome and a prime.

You are given two ints: L and R.
Compute and return the number of palindromic primes between L and R, inclusive.


DEFINITION
Class:PalindromePrime
Method:count
Parameters:int, int
Returns:int
Method signature:int count(int L, int R)


NOTES
-The number 1 is not a prime number.


CONSTRAINTS
-L will be between 1 and 1,000, inclusive.
-R will be between L and 1,000, inclusive.


EXAMPLES

0)
100
150

Returns: 2

This range contains only two palindromic primes: 101 and 131.


1)
1
9

Returns: 4

The palindromic primes in this range are 2, 3, 5, and 7.


2)
929
929

Returns: 1


3)
1
1

Returns: 0


4)
1
1000

Returns: 20

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class PalindromePrime {

	bool isPalindrome(int n) {
		stringstream ss;
		ss << n;
		string a = ss.str();
		string b = a;
		reverse(b.begin(), b.end());
		return a == b;
	}

public:
	int count(int L, int R) {
		int f[1001] = {}, s[1001] = {};
		int pars = 0;
		for (int n = 2; n < 1001; ++n) {
			if (!f[n]) {
				for (int i = n; i < 1001; i += n) {
					f[i] = 1;
				}
				pars += isPalindrome(n);
			}
			s[n] = pars;
		}
		return s[R] - s[L - 1];
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
			int Arg0 = 100;
			int Arg1 = 150;
			int Arg2 = 2;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 9;
			int Arg2 = 4;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 929;
			int Arg1 = 929;
			int Arg2 = 1;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 0;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1000;
			int Arg2 = 20;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PalindromePrime ___test;
	___test.run_test(-1);
}
// END CUT HERE
