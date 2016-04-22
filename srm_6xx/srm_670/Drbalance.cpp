// BEGIN CUT HERE
/*
SRM 670 Div2 Medium (450)

問題
-プラスとマイナスだけでできた文字列が与えられる
-プラスの個数からマイナスの個数を引いた値を評価値とする
-文字列Sの先頭からはじまる部分文字列を接尾辞とする
-全ての接尾辞のうち、評価値が負になる個数が最大でもk個となるようにする
-書き換える文字数の最小値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Drbalance {

	int check(string s) {
		int cnt[2] = {};
		int neg = 0;
		for (int i = 0; i != s.length(); ++i) {
			cnt[s[i] == '+'] += 1;
			neg += cnt[0] > cnt[1];
		}
		return neg;
	}

public:
	int lesscng(string s, int k) {
		int ans = 0;
		for (int i = 0; check(s) > k && i != s.length(); ++i) {
			if (s[i] == '-') {
				++ans;
				s[i] = '+';
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
			string Arg0 = "---";
			int Arg1 = 1;
			int Arg2 = 1;

			verify_case(n, Arg2, lesscng(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "+-+-";
			int Arg1 = 0;
			int Arg2 = 0;

			verify_case(n, Arg2, lesscng(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "-+-+---";
			int Arg1 = 2;
			int Arg2 = 1;

			verify_case(n, Arg2, lesscng(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "-------++";
			int Arg1 = 3;
			int Arg2 = 3;

			verify_case(n, Arg2, lesscng(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "-+--+--+--++++----+";
			int Arg1 = 3;
			int Arg2 = 2;

			verify_case(n, Arg2, lesscng(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE
};

// BEGIN CUT HERE
int main() {
	Drbalance ___test;
	___test.run_test(-1);
}
// END CUT HERE
