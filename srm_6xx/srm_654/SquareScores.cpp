// BEGIN CUT HERE
/*
SRM 654 Div1 Easy (250)

問題
-アルファベットと?からなる文字列Sがある
-?がどの文字になるかの確率が与えられる
-同じ文字だけからなるSの部分文字列の総数をスコアとする
-スコアの期待値を求める

*/
// END CUT HERE
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class SquareScores {
	public:
	double calcexpectation(vector <int> p, string s) {
		long double ans = 0;
		for (LL c = 0; c < p.size(); ++c) {
			long double b[1024];
			long double dp[2][1024];
			for (LL i = 0; i < s.length(); ++i) {
				if (s[i] == '?') {
					b[i] = (long double)p[c] * 0.01;
				} else {
					b[i] = s[i] == ('a' + c);
				}
				dp[1][i] = b[i];
				ans += b[i];
			}
			for (LL n = 2; n <= s.length(); ++n) {
				for (LL i = n - 1; i < s.length(); ++i) {
					long double d = dp[(n - 1) % 2][i - 1] * b[i];
					dp[n % 2][i] = d;
					ans += d;
				}
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (fabs(Expected - Received) < 1.0e-6) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 99};
			string Arg1 = "aaaba";
			double Arg2 = 8.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, calcexpectation(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 20, 70};
			string Arg1 = "aa?bbbb";
			double Arg2 = 15.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, calcexpectation(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 20, 30, 40};
			string Arg1 = "a??c?dc?b";
			double Arg2 = 11.117;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, calcexpectation(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {25, 25, 21, 2, 2, 25};
			string Arg1 = "a??b???????ff??e";
			double Arg2 = 21.68512690712425;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, calcexpectation(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4};
			string Arg1 = "??????????????????????????????";
			double Arg2 = 31.16931963781721;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, calcexpectation(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 3, 4, 3, 8, 2, 4, 3, 4, 4, 3, 2, 4, 4, 3, 4, 2, 4, 7, 6, 4, 4, 3, 4, 4, 3};
			string Arg1 = "makigotapresentfromniko";
			double Arg2 = 23.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, calcexpectation(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SquareScores ___test;
	___test.run_test(-1);
}
// END CUT HERE
