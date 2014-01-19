// BEGIN CUT HERE
/*
// SRM 523 Div2 Hard (1000)

問題
1x1x1、1x1x2、1x1x3の3種類のブロックがある。
ブロックの上には1x1x1のブロックを積むことができる。
連続する2ブロックの上には1x1x2のブロックを積むことができる。
連続する3ブロック、または、1個あけた2ブロックの上には1x1x3のブロックを積むことができる。
幅と高さが与えられる。ブロックの積み方が何通りあるかをmod 1000000007で求める。

*/
// END CUT HERE
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

#define MAX_W 10
#define WSIZE (1<<MAX_W)
#define MOD 1000000007

typedef long long LL;
typedef map<int, int> IntMap;

class SmallBricks31 {

	IntMap ways[WSIZE];

	void gen_ways(int i, int pre, int post) {
		if (i >= MAX_W) {
			ways[pre][post] += 1;
		} else {
			gen_ways(i + 1, pre, post);
			int mask = 1<<i;
			if (pre & mask) {
				gen_ways(i + 1, pre, post | mask);
			}
			mask = 3 << i;
			if ((pre & mask) == mask) {
				gen_ways(i + 2, pre, post | mask);
			}
			mask = 5 << i;
			if ((pre & mask) == mask) {
				gen_ways(i + 3, pre, post | (7<<i));
			}
		}
	}

public:
	SmallBricks31() {
		int i;
		for (i = 0; i < WSIZE; ++i) {
			gen_ways(0, i, 0);
		}
	}

	int countWays(int w, int h) {
		int W = 1<<w;
		int dp[2][WSIZE] = {};
		int read = 0;
		int write = 1;
		dp[0][W-1] = 1;
		int i, j;
		for (i = 0; i < h; ++i) {
			memset(dp[write], 0, sizeof(dp[write]));
			for (j = 0; j < W; ++j) {
				LL c = dp[read][j];
				if (c) {
					const IntMap &m = ways[j];
					IntMap::const_iterator it;
					for (it = m.begin(); it != m.end(); ++it) {
						LL n = c * (LL)it->second;
						n += dp[write][it->first];
						dp[write][it->first] = (int)(n % MOD);
					}
				}
			}
			read ^= 1;
			write ^= 1;
		}

		int res = 0;
		for (i = 0; i < W; ++i) {
			res = (res + dp[read][i]) % MOD;
		}
		return res;
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
			int Arg1 = 3;
			int Arg2 = 4;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 1;
			int Arg2 = 13;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			int Arg2 = 84;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 9;
			int Arg2 = 132976888;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 5;
			int Arg2 = 11676046;

			verify_case(n, Arg2, countWays(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SmallBricks31 ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
