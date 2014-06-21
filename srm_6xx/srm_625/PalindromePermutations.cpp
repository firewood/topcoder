// BEGIN CUT HERE
/*
// SRM 625 Div1 Easy (250)

問題
-文字列が与えられる
-文字列をランダムに並べ替えて、左右対称になる確率を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class PalindromePermutations {

public:
	double palindromeProbability(string word) {
		int f[64] = {};
		int cnt[256] = {};
		int len = (int)word.length();
		for (int i = 0; i < len; ++i) {
			cnt[word[i]] += 1;
		}
		for (int i = len / 2 + 1; i <= len; ++i) {
			f[i] -= 1;
		}
		int odds = 0;
		for (int i = 0; i < 256; ++i) {
			odds += (cnt[i] % 2);
			if (odds > 1) {
				return 0.0;
			}
			for (int j = cnt[i] / 2 + 1; j <= cnt[i]; ++j) {
				f[j] += 1;
			}
		}
		long double ans = 1.0;
		for (int i = 1; i <= len; ++i) {
			for (int j = 0; j < f[i]; ++j) {
				ans *= i;
			}
			for (int j = 0; j > f[i]; --j) {
				ans /= i;
			}
		}
		return (double)ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (fabs(Expected - Received) < 1e-9) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "haha";
			double Arg1 = 0.3333333333333333;

			verify_case(n, Arg1, palindromeProbability(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "xxxxy";
			double Arg1 = 0.2;

			verify_case(n, Arg1, palindromeProbability(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "xxxx";
			double Arg1 = 1.0;

			verify_case(n, Arg1, palindromeProbability(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcde";
			double Arg1 = 0.0;

			verify_case(n, Arg1, palindromeProbability(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff";
			double Arg1 = 0.025641025641025637;

			verify_case(n, Arg1, palindromeProbability(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "bbbbbbaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa";
			double Arg1 = 2.3562121533422868E-5;

			verify_case(n, Arg1, palindromeProbability(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arg0 = "bbbbbbccaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa";
			double Arg1 = 5.746858910590944E-7;

			verify_case(n, Arg1, palindromeProbability(Arg0));
		}
		n++;
	}
// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PalindromePermutations ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
