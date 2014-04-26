// BEGIN CUT HERE
/*
SRM 612 Div1 Easy (250)

問題
-顔文字をsmiles個送り付けたい
-入力欄全体をクリップボードへコピー、クリップボードを入力欄へ貼り付け、入力欄から1つ削除の3つの操作が可能
-入力欄にsmiles個入力するための最小手数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

typedef long long LL;

class EmoticonsDiv1 {
public:
	int printSmiles(int smiles) {
		int dp[1024+1] = {};
		memset(dp, 0x3f, sizeof(dp));
		dp[1] = 0;
		for (int i = 0; i < 10; ++i) {
			for (int j = 1; j <= 1024; ++j) {
				// copy & paste
				for (int k = 1; (j + k*j) <= 1024; ++k) {
					dp[j + k*j] = min(dp[j + k*j], dp[j] + 1 + k);
				}
			}
			// delete
			for (int j = 1; j <= 1024; ++j) {
				dp[j] = min(dp[j], dp[j + 1] + 1);
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
			int Arg0 = 4;
			int Arg1 = 4;

			verify_case(n, Arg1, printSmiles(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 5;

			verify_case(n, Arg1, printSmiles(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 18;
			int Arg1 = 8;

			verify_case(n, Arg1, printSmiles(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 11;
			int Arg1 = 8;

			verify_case(n, Arg1, printSmiles(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EmoticonsDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
