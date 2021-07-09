// BEGIN CUT HERE
/*
TCO21 R3 Easy (250)

PROBLEM STATEMENT

Many websites force their users to select passwords that satisfy various annoying constraints.
This is not only annoying but also dumb, as it often makes the passwords less secure: users who cannot remember their password are prone to storing it in an insecure way.

The authors of these annoying systems often claim that they do it to increase the space of possible passwords.
In this problem we will look at this claim and count some annoying passwords.

An annoying password has the following properties:

It contains exactly U uppercase letters ('A'-'Z').
It contains exactly L lowercase letters ('a'-'z').
It contains exactly D digits ('0'-'9').
It does not contain any other characters.
No two characters of the same type (uppercase, lowercase, digits) are adjacent.
All characters in the password are distinct.

Given U, L and D, count all annoying passwords and return their count modulo 10^9 + 7.


DEFINITION
Class:AnnoyingPasswords
Method:count
Parameters:int, int, int
Returns:int
Method signature:int count(int U, int L, int D)


NOTES
-There are 26 different letters (both in uppercase and in lowercase), and there are 10 different digits.


CONSTRAINTS
-U will be between 0 and 26, inclusive.
-L will be between 0 and 26, inclusive.
-D will be between 0 and 10, inclusive.


EXAMPLES

0)
4
1
1

Returns: 0


The password should contain 4 uppercase letters, 1 lowercase letter and 1 digit.

There are no such annoying passwords: regardless of what order of characters we'll choose, there will always be two consecutive uppercase letters somewhere in the password, and that's not allowed.


1)
5
0
4

Returns: 783743727

The uppercase letters and digits must alternate. For example, "A1B2C3D4Z" is a valid annoying password. There are exactly 39,783,744,000 annoying passwords, the return value is the remainder this number gives when divided by 10^9 + 7.


2)
1
1
1

Returns: 40560

Here, the answer is the exact number of annoying passwords (as it is smaller than 10^9 + 7).


3)
2
2
3

Returns: 559599923

Some annoying passwords of this type include "a1b2C3D" and "7gG4Pp2".


4)
0
0
0

Returns: 1

There is exactly one empty password. By definition, it is annoying.

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

const int64_t MOD = 1000000007;

struct modint {
	int64_t x;
	modint() { }
	modint(int _x) : x(_x) { }
	operator int() const { return (int)x; }
	modint operator+(int y) { return (x + y + MOD) % MOD; }
	modint operator+=(int y) { x = (x + y + MOD) % MOD; return *this; }
	modint operator-(int y) { return (x - y + MOD) % MOD; }
	modint operator-=(int y) { x = (x - y + MOD) % MOD; return *this; }
	modint operator*(int y) { return (x * y) % MOD; }
	modint operator*=(int y) { x = (x * y) % MOD; return *this; }
	modint operator/(int y) { return (x * modpow(y, MOD - 2)) % MOD; }
	modint operator/=(int y) { x = (x * modpow(y, MOD - 2)) % MOD; return *this; }
	static modint modinv(int a) { return modpow(a, MOD - 2); }
	static modint modpow(int a, int b) {
		modint x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

class AnnoyingPasswords {
public:
	int count(int U, int L, int D) {
		vector<vector<vector<vector<modint>>>> dp(U + 1, vector<vector<vector<modint>>>(L + 1, vector<vector<modint>>(D + 1, vector<modint>(3, 0))));
		dp[0][0][0][0] = 1;
		for (int t = 0; t < U + L + D; ++t) {
			vector<vector<vector<vector<modint>>>> next(U + 1, vector<vector<vector<modint>>>(L + 1, vector<vector<modint>>(D + 1, vector<modint>(3, 0))));
			for (int a = 0; a <= U; ++a) {
				for (int b = 0; b <= L; ++b) {
					for (int c = 0; c <= D; ++c) {
						if (a < U) {
							next[a + 1][b][c][0] += dp[a][b][c][1] * (26 - a);
							next[a + 1][b][c][0] += dp[a][b][c][2] * (26 - a);
						}
						if (b < L) {
							next[a][b + 1][c][1] += dp[a][b][c][0] * (26 - b);
							next[a][b + 1][c][1] += dp[a][b][c][2] * (26 - b);
						}
						if (c < D) {
							next[a][b][c + 1][2] += dp[a][b][c][0] * (10 - c);
							next[a][b][c + 1][2] += dp[a][b][c][1] * (10 - c);
						}
					}
				}
			}
			if (t == 0 && U > 0) {
				next[1][0][0][0] += 26;
			}
			dp = next;
		}
		return dp[U][L][D][0] + dp[U][L][D][1] + dp[U][L][D][2];
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
			int Arg0 = 4;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 0;

			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 0;
			int Arg2 = 4;
			int Arg3 = 783743727;

			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 40560;

			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 3;
			int Arg3 = 559599923;

			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 1;

			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AnnoyingPasswords ___test;
	___test.run_test(-1);
}
// END CUT HERE
