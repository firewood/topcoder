// BEGIN CUT HERE
/*
// SRM 532 Div2 Hard (950)

問題
N×Mのタイルがある。
あるタイルに隣接するタイルの数が偶数になるように置く。
置き方の総数を求める。

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
