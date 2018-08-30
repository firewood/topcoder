// BEGIN CUT HERE
/*
TCO18 R4 Easy (250)

問題
-1個,2個,3個,...と各段にピラミッド上に数値を並べる
-下の段の2つの数値の合計が上の段の数値となる
-levels段のピラミッドで、最上部の数値がtopとなるものが何通りあるか求めよ

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
static LL C[1002][1002];
static LL dp[1002][1002];

class SumPyramid {
public:
	int countPyramids(int levels, int top) {
		if (!C[0][0]) {
			for (LL i = 0; i <= 1000; ++i) {
				C[i][0] = 1;
				for (LL j = 1; j <= i; ++j) {
					C[i][j] = min(9999LL, C[i - 1][j - 1] + C[i - 1][j]);
				}
			}
		}
		for (int i = 0; i <= top; ++i) {
			dp[0][i] = 1;
		}
		for (LL i = 1; i < levels; ++i) {
			for (LL j = 0; j <= top; ++j) {
				dp[i][j] = dp[i - 1][j];
				LL k = j - C[levels - 1][i];
				if (k >= 0) {
					dp[i][j] = (dp[i][j] + dp[i][k]) % MOD;
				}
			}
		}
		return dp[levels - 1][top];
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
			int Arg1 = 47;
			int Arg2 = 1;

			verify_case(n, Arg2, countPyramids(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 10;
			int Arg2 = 11;

			verify_case(n, Arg2, countPyramids(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			int Arg2 = 4;

			verify_case(n, Arg2, countPyramids(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 7;
			int Arg2 = 18;

			verify_case(n, Arg2, countPyramids(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1000;
			int Arg1 = 1000;
			int Arg2 = 1005;

			verify_case(n, Arg2, countPyramids(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arg0 = 5;
			int Arg1 = 1000;
			int Arg2 = 448070112;

			verify_case(n, Arg2, countPyramids(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 10;
			int Arg1 = 1000;
			int Arg2 = 659293026;

			verify_case(n, Arg2, countPyramids(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 70;
			int Arg1 = 1000;
			int Arg2 = 42840;

			verify_case(n, Arg2, countPyramids(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SumPyramid ___test;
	___test.run_test(-1);
}
// END CUT HERE
