// BEGIN CUT HERE
/*
SRM 729 Div1 Easy (250)

PROBLEM STATEMENT
You are given an integer (provided as string s as it may be up to 50 digits in length).
Return the number of subsequences of digits in the number that themselves compose an integer that is divisible by 3.
Since this count could be very large, return the number mod 1000000007.


DEFINITION
Class:MagicNumberThree
Method:countSubsequences
Parameters:string
Returns:int
Method signature:int countSubsequences(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character of s will be between '0' and '9', inclusive.


EXAMPLES

0)
"132"

Returns: 3

There are 7 total subsequences of the given digits, but only some of them work:
3, 12, and 132 are divisible by 3.
1, 2, 13, and 32 are not.


1)
"9"

Returns: 1

There's only one subsequence to consider here, and it is divisible by 3.


2)
"333"

Returns: 7

There are three ways to make a "3" as a subsequence, and we could all of them individually.
There are also three ways to make a subsequence of "33", which we also count.
And, of course, "333" also works.


3)
"123456"

Returns: 23


4)
"00"

Returns: 3

Remember that 0 is divisible by three. The sequence 00 of course also has the value 0.

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

static const LL MOD = 1000000007LL;

struct modll {
	long long x;
	modll() : x(0) { }
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

class MagicNumberThree {
public:
	int countSubsequences(string s) {
		modll dp[64][3] = { 1 };
		int n = (int)s.length();
		for (int i = 0; i < n; ++i) {
			int c = s[i] - '0';
			for (int j = 0; j < 3; ++j) {
				dp[i + 1][j] = dp[i][j] + dp[i][(j - c + 9) % 3];
			}
		}
		dp[n][0] -= 1;
		return dp[n][0];
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
			string Arg0 = "132";
			int Arg1 = 3;

			verify_case(n, Arg1, countSubsequences(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "9";
			int Arg1 = 1;

			verify_case(n, Arg1, countSubsequences(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "333";
			int Arg1 = 7;

			verify_case(n, Arg1, countSubsequences(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "123456";
			int Arg1 = 23;

			verify_case(n, Arg1, countSubsequences(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "00";
			int Arg1 = 3;

			verify_case(n, Arg1, countSubsequences(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			string Arg0 = "5";
			int Arg1 = 0;

			verify_case(n, Arg1, countSubsequences(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicNumberThree ___test;
	___test.run_test(-1);
}
// END CUT HERE
