// BEGIN CUT HERE
/*
TCO 2016 Round 2B Easy (300)

PROBLEM STATEMENT
An ordered triple (a, b, c) is called a triangle triple if a, b, c are positive integers such that there is a triangle with side lengths a, b, c and a positive area.

For example, (4, 5, 6) and (5, 4, 6) are two different triangle triples.
On the other hand, (1, 2, 3) and (47, 5, 5) are not triangle triples.

You are given the ints A, B, and C.
Let X be the number of triangle triples (a, b, c) such that 1 <= a <= A, 1 <= b <= B, and 1 <= c <= C.
Compute and return the value (X modulo 1,000,000,007).

DEFINITION
Class:TriangleTriples
Method:count
Parameters:int, int, int
Returns:int
Method signature:int count(int A, int B, int C)


CONSTRAINTS
-A will be between 1 and 1,000,000,000, inclusive.
-B will be between 1 and 1,000,000,000, inclusive.
-C will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
1
10
20

Returns: 10

We have 10 such triples: (1,1,1), (1,2,2), (1,3,3), ..., (1,10,10).


1)
2
2
1000000000

Returns: 6

This time we have: (1,1,1), (1,2,2), (2,1,2), (2,2,1), (2,2,2) and (2,2,3).


2)
10
10
10

Returns: 505


3)
1
1
1

Returns: 1


4)
123456789
987654321
555555555

Returns: 64296241

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
#include <cstring>

using namespace std;

typedef long long LL;

#define MOD 1000000007LL

struct modll {
	long long x;
	modll() { }
	modll(long long _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(const modll &r) { return (x + r.x) % MOD; }
	modll operator+=(const modll &r) { return x = (x + r.x) % MOD; }
	modll operator-(const modll &r) { return (x + MOD - r.x) % MOD; }
	modll operator-=(const modll &r) { return x = (x + MOD - r.x) % MOD; }
	modll operator*(const modll &r) { return (x * r.x) % MOD; }
	modll operator*(int r) { return (x * r) % MOD; }
	modll operator*=(const modll &r) { return x = (x * r.x) % MOD; }
	static modll modinv(int a) { return modpow(a, MOD - 2); }
	static modll modpow(int a, int b) {
		modll x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

modll pyramid(int A) {
	modll r = A - 1;
	r *= A;
	r *= (A + 1);
	r *= modll::modinv(6);
	return r;
}

modll calc(int A, int B, int C) {
	modll r = pyramid(C);
	r -= pyramid(max(0, C - A));
	r -= pyramid(max(0, C - B));
	r += pyramid(max(0, C - A - B));
	return r;
}

class TriangleTriples {
public:
	int count(int A, int B, int C) {
		modll ans = A;
		ans *= B;
		ans *= C;
		ans -= calc(A, B, C);
		ans -= calc(B, C, A);
		ans -= calc(C, A, B);
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
			int Arg2 = 20;
			int Arg3 = 10;

			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 1000000000;
			int Arg3 = 6;

			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 10;
			int Arg2 = 10;
			int Arg3 = 505;

			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 1;

			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 123456789;
			int Arg1 = 987654321;
			int Arg2 = 555555555;
			int Arg3 = 64296241;

			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TriangleTriples ___test;
	___test.run_test(-1);
}
// END CUT HERE
