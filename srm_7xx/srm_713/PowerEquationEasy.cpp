// BEGIN CUT HERE
/*
SRM 713 Div2 Medium (500)

PROBLEM STATEMENT
Fox Ciel is learning about exponentiation.
While doing so, she has noticed some cute identities such as 9^3 = 27^2 and 2^10 = 32^2.

You are given an int n.
Fox Ciel is going to write down all identities of the form a^b = c^d where 1 <= a,b,c,d <= n.

Let X be the number of such identities.
Compute and return the value (X modulo (10^9 + 7)).


DEFINITION
Class:PowerEquationEasy
Method:count
Parameters:int
Returns:int
Method signature:int count(int n)


CONSTRAINTS
-n will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
2

Returns: 6

We have these solutions:

1^1=1^1
1^1=1^2
1^2=1^1
1^2=1^2
2^1=2^1
2^2=2^2


1)
3

Returns: 15

Now we have:

1^1=1^1
1^1=1^2
1^1=1^3
1^2=1^1
1^2=1^2
1^2=1^3
1^3=1^1
1^3=1^2
1^3=1^3
2^1=2^1
2^2=2^2
2^3=2^3
3^1=3^1
3^2=3^2
3^3=3^3


2)
100

Returns: 21620


3)
22306

Returns: 68467

The answer is 1000068474 mod 10^9+7.


4)
1

Returns: 1

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

typedef long long LL;

static const LL MOD = 1000000007LL;

static LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

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

class PowerEquationEasy {
public:
	int count(int n) {
		modll ans = n;
		ans *= (n * 2 - 1);
		for (LL u = 2; u <= 29; ++u) {
			LL imax = pow(n + 0.1, 1.0 / u);
			if (imax <= 1) {
				break;
			}
			modll y = 0;
			for (LL v = 1; v < u; ++v) {
				if (gcd(u, v) == 1) {
					y += n / u;
				}
			}
			y *= (imax - 1);
			ans += y * 2;
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
			int Arg0 = 2;
			int Arg1 = 6;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 15;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 21620;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 22306;
			int Arg1 = 68467;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PowerEquationEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
