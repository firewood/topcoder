// BEGIN CUT HERE
/*
TCO18 Fun Round Beijing Medium (500)

問題
-数字で始まらない1文字以上の文字列を単語とする
-単語と単語、または単語とフレーズをピリオドで結合したものをフレーズとする
-英数字とアンダースコアからなる文字列Wが与えられる
-Wの任意のアンダースコアをピリオドに置き換えることができる
-有効なフレーズの総数を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

const LL MOD = 1000000007LL;

class WordAndPhraseDiv1 {
public:
	int findNumberOfPhrases(string w) {
		static LL dp[1024][1024];
		memset(dp, 0, sizeof(dp));
		int len = (int)w.length();
		dp[0][1] = 1;
		for (int i = 0; i < len; ++i) {
			char c = w[i];
			if (isdigit(c)) {
				dp[i + 1][0] = dp[i][0];
			} else if (isalpha(c)) {
				dp[i + 1][0] = (dp[i][0] + dp[i][1]) % MOD;
			} else if (c == '.') {
				dp[i + 1][0] = dp[i][0];
			} else if (c == '_') {
				dp[i + 1][0] = (dp[i][0] + dp[i][1]) % MOD;
				dp[i + 1][1] = dp[i][0];
			}
		}
		return dp[len][0];
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
			string Arg0 = "tco_topcoder_com";
			int Arg1 = 4;

			verify_case(n, Arg1, findNumberOfPhrases(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "tcotopcodercom";
			int Arg1 = 1;

			verify_case(n, Arg1, findNumberOfPhrases(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "_tco18_admin_id_is_secret";
			int Arg1 = 16;

			verify_case(n, Arg1, findNumberOfPhrases(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "____";
			int Arg1 = 3;

			verify_case(n, Arg1, findNumberOfPhrases(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "a0_a1_a2_a3_a4_a5_a6_a7_a8_a9_a0_a1_a2_a3_a4_a5_a6_a7_a8_a9_a0_a1_a2_a3_a4_a5_a6_a7_a8_a9_a0";
			int Arg1 = 73741817;

			verify_case(n, Arg1, findNumberOfPhrases(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "d0_0b";
			int Arg1 = 1;

			verify_case(n, Arg1, findNumberOfPhrases(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WordAndPhraseDiv1 ___test;
	___test.run_test(0);
}
// END CUT HERE
