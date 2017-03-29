// BEGIN CUT HERE
/*
SRM 698 Div2 Medium (500)

問題
-文字列が二つの文字列の繰り返しになっているとき、平方文字列と呼ぶ
-文字列sから何文字か削除して平方文字列にするとき、最大の長さを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int lcs(const string &a, const string &b) {
	int dp[52][52] = {};
	for (int i = 0; i != a.length(); ++i) {
		for (int j = 0; j != b.length(); ++j) {
			if (a[i] == b[j]) {
				dp[i + 1][j + 1] = 1 + dp[i][j];
			} else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}
	return dp[a.length()][b.length()];
}

class RepeatStringEasy {
public:
	int maximalLength(string s) {
		int ans = 0;
		int len = (int)s.length();
		for (int i = 1; i < len; ++i) {
			ans = max(ans, lcs(s.substr(0, i), s.substr(i, len - i)));
		}
		return ans * 2;
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
			string Arg0 = "frankfurt";
			int Arg1 = 4;

			verify_case(n, Arg1, maximalLength(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "single";
			int Arg1 = 0;

			verify_case(n, Arg1, maximalLength(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "singing";
			int Arg1 = 6;

			verify_case(n, Arg1, maximalLength(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aababbababbabbbbabbabb";
			int Arg1 = 18;

			verify_case(n, Arg1, maximalLength(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "x";
			int Arg1 = 0;

			verify_case(n, Arg1, maximalLength(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RepeatStringEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
