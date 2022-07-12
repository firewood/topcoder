// BEGIN CUT HERE
/*
SRM 833 Div1 Easy (300)

PROBLEM STATEMENT

As usual in many counting problems, you are standing on the point (0, 0) and you want to reach the point (X, Y) - that is, the point X steps east and Y steps north from your current location.

You move by taking steps. Each step must lead either east or north.

There is one extra rule tonight: along your way, you are not allowed to take exactly three steps in a row in the same direction. Fewer is good, more is also good, only exactly three is bad.

Count all valid ways of reaching the goal. Return that count modulo 10^9 + 7.


DEFINITION
Class:Never3Steps
Method:count
Parameters:int, int
Returns:int
Method signature:int count(int X, int Y)


CONSTRAINTS
-X will be between 0 and 1000, inclusive.
-Y will be between 0 and 1000, inclusive.


EXAMPLES

0)
2
2

Returns: 6

All six paths from (0, 0) to (2, 2) are valid.


1)
3
3

Returns: 14

Using 'N' for a step north and 'E' for a step east, the valid paths include "NENENE" and "EENENN" while the invalid paths include "NNNEEE" and "ENNNEE".


2)
0
7

Returns: 1

The only valid path consists of seven consecutive steps north. Seven is not three, so this is a valid path.


3)
10
2

Returns: 45


As we'll only take a total of two steps north, we don't have to worry about making three consecutive steps north. We just need to make sure we'll never make exactly three consecutive steps east.

Each valid path can be described as follows: "x steps east, step north, y steps east, step north, z steps east", where x+y+z = 10 and none of them equals 3. We can easily count that there are 45 such paths.


4)
0
0

Returns: 1

There's exactly one valid way to get from (0, 0) to (0, 0): take no steps.

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
static const size_t TABLE_SIZE = 1000000;

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
		for (; b > 0; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

modint combination_fast(int n, int r) {
	if (r > n) return 0;
	static modint fact[TABLE_SIZE + 1], inv[TABLE_SIZE + 1];
	if (!fact[0]) {
		fact[0] = 1;
		for (int i = 1; i <= TABLE_SIZE; ++i) {
			fact[i] = fact[i - 1] * i;
		}
		inv[TABLE_SIZE] = modint::modinv(fact[TABLE_SIZE]);
		for (int i = TABLE_SIZE; i >= 1; --i) {
			inv[i - 1] = inv[i] * i;
		}
	}
	return (fact[n] * inv[r]) * inv[n - r];
}

modint combination_slow(int n, int r) {
	if (r > n) return 0;
	r = min(r, n - r);
	if (r == 0) return 1;
	if (r == 1) return n;
	if (r == 2) return (((int64_t)n * (n - 1)) / 2) % MOD;
	modint a = 1, b = 1;
	for (int i = 0; i < r; ++i) {
		a *= n - i;
		b *= i + 1;
	}
	return a * modint::modinv(b);
}

inline modint combination(int n, int r) {
	return combination_fast(n, r);
}

modint nHr(int n, int r) {
	return combination(n + r - 1, r);
}

class Never3Steps {
public:
	int count(int X, int Y) {
		vector<vector<modint>> from_left(Y + 1, vector<modint>(X + 1, 0));
		vector<vector<modint>> from_down(Y + 1, vector<modint>(X + 1, 0));
		vector<modint> left_sum(X + 2, 0);
		from_left[0][0] = 1;
		from_down[0][0] = 1;
		for (int y = 0; y <= Y; ++y) {
			modint down_sum = 0;
			for (int x = 0; x <= X; ++x) {
				from_left[y][x] += down_sum;
				from_down[y][x] += left_sum[x];
				if (y + 3 <= Y) {
					from_down[y + 3][x] -= from_left[y][x];
				}
				if (x + 3 <= X) {
					from_left[y][x + 3] -= from_down[y][x];
				}
				down_sum += from_down[y][x];
				left_sum[x] += from_left[y][x];
			}
		}
		from_left[0][0] -= 1;
		return from_left[Y][X] + from_down[Y][X];
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
			int Arg1 = 2;
			int Arg2 = 6;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			int Arg2 = 14;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 7;
			int Arg2 = 1;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 2;
			int Arg2 = 45;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 0;
			int Arg2 = 1;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 0;
			int Arg1 = 3;
			int Arg2 = 0;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 3;
			int Arg1 = 0;
			int Arg2 = 0;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 6;
			int Arg1 = 7;
			int Arg2 = 601;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Never3Steps ___test;
	___test.run_test(-1);
}
// END CUT HERE
