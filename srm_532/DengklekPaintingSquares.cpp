// BEGIN CUT HERE
/*
// SRM 532 Div2 Hard (950)

// PROBLEM STATEMENT
// Mr. Dengklek lives in the Kingdom of Ducks, where humans and ducks live
together in peace and harmony.

One day, the queen of the kingdom challenged Mr. Dengklek with a perplexing
puzzle: she gave Mr. Dengklek an N Å~ M board made of wood that consists of
N*M squares. She then asked Mr. Dengklek to paint the squares according to
these rules:

Each square must be either colored or empty.
Each colored square must have an even number of adjacent colored squares.
Two squares are adjacent if they share a side.

For example, here is one valid solution for N=4, M=7:

In the above image, black squares denote empty squares and brown squares
denote colored squares.

Of course, finding one solution to the puzzle is easy: we do not color
anything. Instead, the queen asked Mr. Dengklek a much harder question:
to count all valid solutions of the puzzle. Help Mr. Dengklek count the
solutions and return the result modulo 1,000,000,007. Two solutions are
different if there is a square that is colored in one solution and not
colored in the other solution.


DEFINITION
Class:DengklekPaintingSquares
Method:numSolutions
Parameters:int, int
Returns:int
Method signature:int numSolutions(int N, int M)


CONSTRAINTS
-N will be between 1 and 100, inclusive.
-M will be between 1 and 8, inclusive.


EXAMPLES

0)
1
1

Returns: 2

Either Mr. Dengklek colors the square, or he does not. Both choices produce a valid solution.


1)
2
2

Returns: 8

Here are the 8 valid solutions:


2)
1
3

Returns: 5


3)
47
7

Returns: 944149920

*/
// END CUT HERE
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

#define MOD 1000000007
#define MAX_SZ 3*3*3*3*3*3*3*3

typedef map<int, int> IntMap;

static int pat[MAX_SZ][256];

class DengklekPaintingSquares {

public:
	int numSolutions(int N, int M) {
		int i, j, k, a, b, c, d;
		int W = 1<<M;

		int SZ = 1;
		for (i = 0; i < M; ++i) {
			SZ *= 3;
		}

		int idx2val[MAX_SZ] = {};
		IntMap val2idx;
		for (i = 0; i < SZ; ++i) {
			a = i;
			b = 0;
			for (j = 0; j < M; ++j) {
				b |= (1<<(j*2)) * (a % 3);
				a /= 3;
			}
			idx2val[i] = b;
			val2idx[b] = i;
		}

		int bitmask[256] = {};
		for (i = 0; i < W; ++i) {
			b = 0;
			for (j = 0; j < M; ++j) {
				if (i & (1<<j)) {
					b |= (1<<(j*2));
				}
			}
			bitmask[i] = b;
		}

		memset(pat, -1, sizeof(pat));
		for (i = 0; i < SZ; ++i) {
			a = idx2val[i];
			for (j = 0; j < W; ++j) {
				b = bitmask[j];
				if ((a ^ b) & a & 0x5555) {
					continue;
				}
				if ((a >> 1) & 0x5555 & b) {
					continue;
				}

				c = (a & 0x5555) + ((a >> 1) & 0x5555) + (b >> 2) + ((b << 2) & 0x5555);
				d = (b & c);
				b = ((b ^ d) << 1) | d;
				pat[i][j] = val2idx[b];
			}
		}

		int dp[2][MAX_SZ] = {};
		dp[0][0] = 1;
		int read = 0, write = 1;
		for (i = 0; i < N; ++i) {
			memset(dp[write], 0, sizeof(dp[0]));
			for (j = 0; j < SZ; ++j) {
				a = dp[read][j];
				for (k = 0; k < W; ++k) {
					b = pat[j][k];
					if (b >= 0) {
						dp[write][b] += a;
						dp[write][b] %= MOD;
					}
				}
			}
			read ^= 1, write ^= 1;
		}
		int result = 0;
		for (i = 0; i < SZ; ++i) {
			if ((idx2val[i] & 0x5555) == 0) {
				result += dp[read][i];
				result %= MOD;
			}
		}

		return result;
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
			int Arg1 = 1;
			int Arg2 = 2;

			verify_case(n, Arg2, numSolutions(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 8;

			verify_case(n, Arg2, numSolutions(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 3;
			int Arg2 = 5;

			verify_case(n, Arg2, numSolutions(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 47;
			int Arg1 = 7;
			int Arg2 = 944149920;

			verify_case(n, Arg2, numSolutions(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arg1 = 8;
			int Arg2 = 609190003;

			verify_case(n, Arg2, numSolutions(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DengklekPaintingSquares ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
