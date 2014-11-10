// BEGIN CUT HERE
/*
SRM 612 Div2 Medium (500)

問題
-顔文字をsmiles個送り付けたい
-入力欄全体をクリップボードへコピー、または、クリップボードを入力欄へ貼り付けのどちらかの操作が可能
-入力欄にsmiles個入力するための最小手数を求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class EmoticonsDiv2 {
public:
	int printSmiles(int smiles) {
		int dp[1024 + 1] = {};
		memset(dp, 0x3f, sizeof(dp));
		dp[1] = 0;
		for (int i = 0; i < 10; ++i) {
			for (int j = 1; j <= 1024; ++j) {
				// copy & paste
				for (int k = 1; (j + k*j) <= 1024; ++k) {
					dp[j + k*j] = min(dp[j + k*j], dp[j] + 1 + k);
				}
			}
		}
		return dp[smiles];
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

			verify_case(n, Arg1, printSmiles(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 5;

			verify_case(n, Arg1, printSmiles(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 11;
			int Arg1 = 11;

			verify_case(n, Arg1, printSmiles(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 16;
			int Arg1 = 8;

			verify_case(n, Arg1, printSmiles(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000;
			int Arg1 = 21;

			verify_case(n, Arg1, printSmiles(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EmoticonsDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
