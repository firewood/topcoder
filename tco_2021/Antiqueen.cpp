// BEGIN CUT HERE
/*
TCO21 R1B Hard (700)

PROBLEM STATEMENT

An antiqueen is a chess piece that is the opposite of a chess queen - that is, it can move from one cell to another if and only if that move is not a valid queen move.
Note that the antiqueen does have to move: staying on the current square is not a valid antiqueen move.

You have a rectangular board with R rows and C columns.
You have to start by placing the antiqueen onto any square of the board.
Then you have to make a sequence of N valid moves with the antiqueen (always continuing from the square where the previous move ended).

In how many different ways can the above sequence of actions be performed?
Two ways are different if the antiqueen visits a different sequence of N+1 squares.
Return the number of ways modulo 10^9 + 7.


DEFINITION
Class:Antiqueen
Method:countPaths
Parameters:int, int, int
Returns:int
Method signature:int countPaths(int R, int C, int N)


NOTES
-A chess queen can move from one cell to another if and only if the cells lie in the same row, in the same column, or on the same diagonal. This includes all shorter diagonals in both directions.


CONSTRAINTS
-R will be between 1 and 200, inclusive.
-C will be between 1 and 200, inclusive.
-N will be between 1 and 200, inclusive.


EXAMPLES

0)
3
3
1

Returns: 16

You have a 3x3 board. You are asked to place the antiqueen somewhere and then to make one valid move.

You cannot start in the center as then you won't have a valid move. If you start anywhere else, you will have two valid moves to choose from.

Three of the 16 valid solutions are shown below: 0 is where the antiqueen starts and 1 is where it jumps.

   ..0   0..   ...
   ...   ..1   0..
   .1.   ...   ..1


1)
2
3
100

Returns: 4

You must hop back and forth between two opposite corners of this rectangle. Thus, there are four possible sequences of actions (one starting in each corner).


2)
2
4
100

Returns: 9613417

Here the antiqueen has a bit more freedom. The exact number of ways in which you can perform 100 consecutive moves on this board is 6002082144827584333108. Remember that the correct return value is this number modulo 10^9 + 7.


3)
7
8
2

Returns: 64904

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

const LL MOD = 1000000007;

struct modint {
	long long x;
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

class Antiqueen {
public:
	int countPaths(int R, int C, int N) {
		vector<vector<modint>> dp(R, vector<modint>(C, 1));
		modint sum = R * C;
		for (int t = 0; t < N; ++t) {
			modint prev_sum = sum;
			sum = 0;
			vector<modint> h(R, 0), v(C, 0), d(400, 0), rd(400, 0);
			for (int i = 0; i < R; ++i) {
				for (int j = 0; j < C; ++j) {
					h[i] += dp[i][j];
					v[j] += dp[i][j];
					d[i + j] += dp[i][j];
					rd[200 + i - j] += dp[i][j];
				}
			}
			for (int i = 0; i < R; ++i) {
				for (int j = 0; j < C; ++j) {
					modint& x = dp[i][j];
					x *= 3;
					x += prev_sum;
					x -= h[i];
					x -= v[j];
					x -= d[i + j];
					x -= rd[200 + i - j];
					sum += x;
				}
			}
		}
		return sum;
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
			int Arg0 = 3;
			int Arg1 = 3;
			int Arg2 = 1;
			int Arg3 = 16;

			verify_case(n, Arg3, countPaths(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 3;
			int Arg2 = 100;
			int Arg3 = 4;

			verify_case(n, Arg3, countPaths(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 4;
			int Arg2 = 100;
			int Arg3 = 9613417;

			verify_case(n, Arg3, countPaths(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 8;
			int Arg2 = 2;
			int Arg3 = 64904;

			verify_case(n, Arg3, countPaths(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Antiqueen ___test;
	___test.run_test(-1);
}
// END CUT HERE
