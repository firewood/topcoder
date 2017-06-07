// BEGIN CUT HERE
/*
SRM 714 Div2 Medium (500)

問題
-括弧だけからなる文字列が与えられる
-括弧の対応関係を維持したまま、以下の操作を繰り返す
-左端の1文字を消す
-括弧の対応関係が成り立つように、どれか1文字消す
-何通りの消し方ができるかどうかを求める

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

class RemovingParenthesis {
public:
	int countWays(string s) {
		int ans = 1, cnt = 0;
		for (int i = 0; i != s.length(); ++i) {
			if (s[i] == '(') {
				ans *= ++cnt;
			} else {
				--cnt;
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
			string Arg0 = "()()()()()";
			int Arg1 = 1;

			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "(((())))" ;
			int Arg1 = 24;

			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "((()()()))" ;
			int Arg1 = 54;

			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "(())(())(())" ;
			int Arg1 = 8;

			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "((()))(()(()))((()))";
			int Arg1 = 432;

			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RemovingParenthesis ___test;
	___test.run_test(-1);
}
// END CUT HERE
