// BEGIN CUT HERE
/*
TCO18 R1B Hard (1000)

問題
-同じ文字が3つ続く部分をブロックとする
-S種類の文字からなる長さLの文字列のうち、ブロックを一つだけ含むものがいくつあるかを求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

static const int MOD = 1000000007;

class ThreeSameLetters {
public:
	int countStrings(int L, int S) {
		int dp[26][2][26][26] = {};
		for (int i = 0; i < S; ++i) {
			for (int j = 0; j < S; ++j) {
				dp[1][0][i][j] = 1;
			}
		}
		for (int t = 2; t < L; ++t) {
			for (int i = 0; i < S; ++i) {
				for (int j = 0; j < S; ++j) {
					for (int k = 0; k < S; ++k) {
						if (i == j && j == k) {
							(dp[t][1][j][k] += dp[t - 1][0][i][j]) %= MOD;
						} else {
							(dp[t][0][j][k] += dp[t - 1][0][i][j]) %= MOD;
							(dp[t][1][j][k] += dp[t - 1][1][i][j]) %= MOD;
						}
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < S; ++i) {
			for (int j = 0; j < S; ++j) {
				(ans += dp[L - 1][1][i][j]) %= MOD;
			}
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
			int Arg0 = 3;
			int Arg1 = 7;
			int Arg2 = 7;

			verify_case(n, Arg2, countStrings(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 2;
			int Arg2 = 4;

			verify_case(n, Arg2, countStrings(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 17;
			int Arg2 = 0;

			verify_case(n, Arg2, countStrings(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 11;
			int Arg2 = 410199993;

			verify_case(n, Arg2, countStrings(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ThreeSameLetters ___test;
	___test.run_test(-1);
}
// END CUT HERE
