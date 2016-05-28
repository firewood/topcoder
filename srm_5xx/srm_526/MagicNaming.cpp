// BEGIN CUT HERE
/*
// SRM 526.5 Div2 Hard (1000)

問題

住人が発明した呪文がある。
呪文は住人の名前を結合したもののうち、辞書順で最小のものである。
最大で何人の住人が含まれるか求める。

*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>
#include <algorithm>
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

class MagicNaming {

	static int compare(const char *a, const char *b, int len_a, int len_b) {
		int c = 0;
		const char *as = a;
		const char *bs = b;
		const char *ae = a + len_a;
		const char *be = b + len_b;
		int len = len_a + len_b;
		while (len-- > 0) {
			c = *a++ - *b++;
			if (c != 0) {
				break;
			}
			if (a == ae) {
				a = bs;
			}
			if (b == be) {
				b = as;
			}
		}
		return c;
	}

public:
	int maxReindeers(string magicName) {
		int dp[60][60] = {0};
		int i, j, k, m;
		const char *s = magicName.c_str();
		int len = magicName.length();
		for (i = len - 1; i >= 0; --i) {
			dp[i][len - i] = 1;
			for (j = (len - i); j >= 1; --j) {
				m = 0;
				for (k = len - i - j; k > 0; --k) {
					if (dp[i+j][k] > 0 && compare(s + i, s + i + j, j, k) <= 0) {
						m = max(m, 1 + dp[i+j][k]);
					}
				}
				dp[i][j] = max(dp[i][j], m);
			}
		}
		int result = 0;
		for (i = 1; i <= len; ++i) {
			result = max(result, dp[0][i]);
		}
		return result;
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
			string Arg0 = "aba";
			int Arg1 = 2;

			verify_case(n, Arg1, maxReindeers(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "babbaba";
			int Arg1 = 2;

			verify_case(n, Arg1, maxReindeers(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "philosophersstone";
			int Arg1 = 5;

			verify_case(n, Arg1, maxReindeers(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "knuthmorrispratt";
			int Arg1 = 7;

			verify_case(n, Arg1, maxReindeers(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "acrushpetrtourist";
			int Arg1 = 7;

			verify_case(n, Arg1, maxReindeers(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "zzzzz";
			int Arg1 = 5;

			verify_case(n, Arg1, maxReindeers(Arg0));
		}
		n++;

		// system test case 11
		if ((Case == -1) || (Case == n)){
			string Arg0 = "bbbaaaabbaabaabbbabaaaaaaabb";
			int Arg1 = 4;

			verify_case(n, Arg1, maxReindeers(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicNaming ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
