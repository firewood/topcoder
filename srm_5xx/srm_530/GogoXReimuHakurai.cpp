// BEGIN CUT HERE
/*
// SRM 530 Div2 Hard (1000)

問題
小説が0から(N-1)までの全Nステージある
あるステージAから次のステージBへのルートがあるかどうかのフラグが与えられる
前のステージへは戻れない
それまでに通っていないルートを1通りとして何通りのルートがあるか求める

*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>
#include <algorithm>
#include <numeric>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

class GogoXReimuHakurai {

public:
	int solve(vector <string> choices) {
		int len = choices.size();
		IntVec f(len, 0);
		IntVec dp(len, 0);
		f[len -1] = 1;
		int i, j;
		for (i = len - 1; i >= 0; --i) {
			for (j = i; j < len; ++j) {
				if (choices[i][j] == 'Y' && f[j]) {
					f[i] = 1;
				}
			}
		}
		dp[0] = f[0];
		for (i = 0; i < len; ++i) {
			for (j = i+1; j < len; ++j) {
				if (choices[i][j] == 'Y' && f[j]) {
					dp[j] += dp[i];
					dp[i] = dp[i] > 0;
				}
			}
		}
		return dp[len-1];
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
			string Arr0[] = {
"NYY",
"NNY",
"NNN"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"NYNY",
"NNYY",
"NNNY",
"NNNN"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNY"
,"NNY"
,"NNN"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NN"
,"NN"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;


		// system test case 3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYYYY", "NNYYY", "NNNYY", "NNNNY", "NNNNN"};
			int Arg1 = 7;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// system test case x
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYNYYYYNYY", "NNNYYYYNYY", "NNNYNNYYNN", "NNNNYYYNYY", "NNNNNYNNNN", "NNNNNNNNYN", "NNNNNNNNYY", "NNNNNNNNNY", "NNNNNNNNNN", "NNNNNNNNNN"};
			int Arg1 = 7;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GogoXReimuHakurai ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
