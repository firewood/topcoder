// BEGIN CUT HERE
/*
SRM 671 Div1 Easy (300)

問題
-1個以上の泣きの顔文字;_;をネットワーク上に送信する
-アンダースコアは1つ以上なら何個でもよい
-複数の顔文字が混ざって1つの文字列として送信される
-1つの顔文字内の文字の順番は入れ替わらない
-最終的に送信されるmessageが何通りに復元できるかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

#define MOD 1000000007

struct modll {
	long long x;
	modll() { }
	modll(long long _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(const modll &r) { return (x + r.x) % MOD; }
	modll operator+=(const modll &r) { return x = (x + r.x) % MOD; }
	modll operator-(const modll &r) { return (x + MOD - r.x) % MOD; }
	modll operator-=(const modll &r) { return x = (x + MOD - r.x) % MOD; }
	modll operator*(const modll &r) { return (x * r.x) % MOD; }
	modll operator*(int r) { return (x * r) % MOD; }
	modll operator*=(const modll &r) { return x = (x * r.x) % MOD; }
};

class BearCries {

	modll dp[202][202][202];

public:
	int count(string message) {
		int len = (int)message.length();
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;
		for (int i = 0; i < len; ++i) {
			if (message[i] == ';') {
				for (int j = 0; j <= i; ++j) {
					for (int k = 0; k <= i; ++k) {
						dp[i + 1][j + 1][k] += dp[i][j][k];
						if (k > 0) {
							dp[i + 1][j][k - 1] += dp[i][j][k] * k;
						}
					}
				}
			} else {
				for (int j = 0; j <= i; ++j) {
					for (int k = 0; k <= i; ++k) {
						dp[i + 1][j][k] += dp[i][j][k] * k;
						if (j > 0) {
							dp[i + 1][j - 1][k + 1] += dp[i][j][k] * j;
						}
					}
				}
			}
		}
		return dp[len][0][0];
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
			string Arg0 = ";_;;_____;";
			int Arg1 = 2;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = ";;;___;;;";
			int Arg1 = 36;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "_;__;";
			int Arg1 = 0;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = ";_____________________________________;";
			int Arg1 = 1;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = ";__;____;";
			int Arg1 = 0;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = ";_;;__;_;;";
			int Arg1 = 52;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;____________________________________________________________;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;";
			int Arg1 = 343258070;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearCries ___test;
	___test.run_test(-1);
}
// END CUT HERE
