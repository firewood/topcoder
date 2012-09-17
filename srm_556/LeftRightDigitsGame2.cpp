// BEGIN CUT HERE
/*
// SRM 556 Div1 Medium (500)

問題
N枚のカードが積まれている。
上から1枚ずつ取り、左か右に並べてN桁の数を作る。
生成可能な数のうち、lowerBound以上で最小の数値を求める。

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<string> StrVec;

class LeftRightDigitsGame2 {

	string Min(string a, string b) {
		if (a.empty()) {
			return b;
		}
		if (b.empty()) {
			return a;
		}
		return min(a, b);
	}

public:
	string minNumber(string digits, string lowerBound) {
		string ans;
		int sz = (int)digits.length();
		int i, eqlen, pos;
		for (eqlen = 0; eqlen <= sz; ++eqlen) {
			StrVec dp(sz+1);
			for (i = 0; i < sz; ++i) {
				StrVec prev = dp;
				dp = StrVec(sz);
				for (pos = 0; pos < (sz-i); ++pos) {
					if (!i || !prev[pos+1].empty()) {
						if (pos < eqlen && digits[i] == lowerBound[pos] ||
								pos == eqlen && digits[i] > lowerBound[pos] ||
								pos > eqlen) {
							dp[pos] = Min(dp[pos], digits[i] + prev[pos+1]);
						}
					}
					if (!prev[pos].empty()) {
						if ((pos+i) < eqlen && digits[i] == lowerBound[pos+i] ||
								(pos+i) == eqlen && digits[i] > lowerBound[pos+i] ||
								(pos+i) > eqlen) {
							dp[pos] = Min(dp[pos], prev[pos] + digits[i]);
						}
					}
				}
			}
			ans = Min(ans, dp[0]);
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "565";
			string Arg1 = "556";
			string Arg2 = "556";

			verify_case(n, Arg2, minNumber(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "565";
			string Arg1 = "566";
			string Arg2 = "655";

			verify_case(n, Arg2, minNumber(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "565";
			string Arg1 = "656";
			string Arg2 = "";

			verify_case(n, Arg2, minNumber(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "9876543210";
			string Arg1 = "5565565565";
			string Arg2 = "5678943210";

			verify_case(n, Arg2, minNumber(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "8016352";
			string Arg1 = "1000000";
			string Arg2 = "1086352";

			verify_case(n, Arg2, minNumber(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "36403829258";
			string Arg1 = "83994503502";
			string Arg2 = "84360329258";

			verify_case(n, Arg2, minNumber(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arg0 = "5";
			string Arg1 = "5";
			string Arg2 = "5";

			verify_case(n, Arg2, minNumber(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arg0 = "54880697764616510142";
			string Arg1 = "56781948547726329061";
			string Arg2 = "56784580697461610142";

			verify_case(n, Arg2, minNumber(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arg0 = "522042136022636254641";
			string Arg1 = "559737750935742501186";
			string Arg2 = "560022542136223624641";

			verify_case(n, Arg2, minNumber(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LeftRightDigitsGame2 ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
