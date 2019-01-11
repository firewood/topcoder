// BEGIN CUT HERE
/*
SRM 744 Div2 Medium (500)

問題
- A以上B以下の平方数のうち、10進数表記して偶数番目の桁の数字が奇数番目の桁の数字よりも大きいものの個数を求めよ。

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

class MagicNumbersAgain {
public:
	int count(long long A, long long B) {
		int ans = 0;
		LL m = (LL)sqrt(B);
		for (LL i = 1; i <= m; ++i) {
			LL j = i * i;
			if (j >= A) {
				string s = to_string(j);
				int len = (int)s.length();
				int ok = 1;
				if (len % 2) {
					s += "@";
				}
				s += " @";
				for (int k = 0; k < len; k += 2) {
					if (s[k] >= s[k + 1] || s[k + 1] <= s[k + 2]) {
						ok = 0;
					}
				}
				ans += ok;
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
			long long Arg0 = 1LL;
			long long Arg1 = 64LL;
			int Arg2 = 7;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 50LL;
			long long Arg1 = 60LL;
			int Arg2 = 0;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 121LL;
			long long Arg1 = 121LL;
			int Arg2 = 1;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 5679LL;
			long long Arg1 = 1758030LL;
			int Arg2 = 73;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1304164LL;
			long long Arg1 = 2000000LL;
			int Arg2 = 14;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicNumbersAgain ___test;
	___test.run_test(-1);
}
// END CUT HERE
