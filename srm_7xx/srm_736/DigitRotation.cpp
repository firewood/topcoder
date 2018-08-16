// BEGIN CUT HERE
/*
SRM 736 Div1 Easy (250)

PROBLEM STATEMENT

You are given a string X that contains the digits of a large positive integer, with X[0] being the most significant digit of the number.

A 3-rotation is performed as follows:

Select any three numbers a < b < c that are all valid indices into X.
Form a new number by rotating the digits at those three indices: the digit from index a goes to index b, the one from b goes to c, and the one from c goes to a.

For example, if X = "25749", one possible 3-rotation looks as follows:

We select the indices a=0, b=3, and c=4.
We rotate the three digits, producing the new number "95724".

Two 3-rotations are considered distinct if they use different triples of indices.
Note that distinct 3-rotations may sometimes produce the same result.
A 3-rotation is considered valid if the resulting number doesn't have any leading zeros.

Consider all valid 3-rotations of the given number X. Report the sum of all their results, modulo 998244353. 


DEFINITION
Class:DigitRotation
Method:sumRotations
Parameters:string
Returns:int
Method signature:int sumRotations(string X)


CONSTRAINTS
-X will contain between 1 and 500 characters, inclusive.
-Each character of X will be a digit ('0'-'9').
-X[0] will not be '0'.


EXAMPLES

0)
"123"

Returns: 312

There is only one valid 3-rotation. It produces the number 312.


1)
"3570"

Returns: 10407

There are four possible 3-rotations, but only two of them are valid. The other two produce a number with a leading zero. For example, selecting the indices (0,1,3) is not a valid 3-rotation, as it produces the result "0375".

The two valid 3-rotations produce the numbers 7350 and 3057, respectively. The answer is their sum.


2)
"5545"

Returns: 21208

In this case there are four 3-rotations, and all four of them are valid. Note that two of them yield the same result: the number 5554. 
The other two produce the results 4555 and 5545.
Therefore, the answer is 4555 + 5545 + 5554 + 5554.

Also note that the rotation with indices 0,1,3 is valid, even though it leaves the number unchanged. 


3)
"1283749218734901238749213847902"

Returns: 867286291

Do not forget to take the answer modulo 998244353.


4)
"4"

Returns: 0

The sum of an empty set is zero.

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

const int MOD = 998244353;

struct modll {
	long long v;
	modll() : v(0) { }
	modll(long long _v) : v(_v) { }
	long long operator+(const modll &r) const { return (v + r.v) % MOD; }
	long long operator-(const modll &r) const { return (v + MOD - r.v) % MOD; }
	long long operator*(const modll &r) const { return (v * r.v) % MOD; }
	modll operator+=(const modll &r) { v = (v + r.v) % MOD; return *this; }
	modll operator-=(const modll &r) { v = (v + MOD - r.v) % MOD; return *this; }
	modll operator*=(const modll &r) { v = (v * r.v) % MOD; return *this; }
//	friend modll operator+(int l, const modll &r) { return (l + r.v) % MOD; }
//	friend modll operator-(int l, const modll &r) { return (l + MOD - r.v) % MOD; }
//	friend modll operator*(int l, const modll &r) { return (l * r.v) % MOD; }
	static long long modinv(int a) { return modpow(a, MOD - 2); }
	static long long modpow(int a, int b) {
		modll x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r.v;
	}
};

class DigitRotation {
public:
	int sumRotations(string X) {
		int n = (int)X.length();
		modll a = 1, sum = 0, tbl[512] = {}, ans = 0;
		int d[512];
		for (int i = n - 1; i >= 0; --i, a *= 10) {
			d[i] = X[i] - '0';
			sum += a * d[i];
			tbl[i] = a;
		}
		for (int i = 0; i < n; ++i) {
			modll x = sum + tbl[i] * -d[i];
			for (int j = i + 1; j < n; ++j) {
				modll y = x + tbl[j] * (d[i] - d[j]);
				for (int k = j + 1; k < n; ++k) {
					if (i > 0 || d[k]) {
						ans += y;
						ans += tbl[k] * (d[j] - d[k]);
						ans += tbl[i] * d[k];
					}
				}
			}
		}
		return (int)ans.v;
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
			string Arg0 = "123";
			int Arg1 = 312;

			verify_case(n, Arg1, sumRotations(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "3570";
			int Arg1 = 10407;

			verify_case(n, Arg1, sumRotations(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "5545";
			int Arg1 = 21208;

			verify_case(n, Arg1, sumRotations(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "1283749218734901238749213847902";
			int Arg1 = 867286291;

			verify_case(n, Arg1, sumRotations(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "4";
			int Arg1 = 0;

			verify_case(n, Arg1, sumRotations(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			string Arg0 = "123456789123456789123456789123456";
			int Arg1 = 938843585;

			verify_case(n, Arg1, sumRotations(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DigitRotation ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
