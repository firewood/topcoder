// BEGIN CUT HERE
/*
SRM 684 Div2 Easy (250)

問題
-文字列のスコアを計算する
-文字種毎にカウントする
-カウントの二乗の総和がスコア
-K文字消せるとき、スコアの最小値を求める

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Istr {
public:
	int count(string s, int k) {
		int cnt[256] = {};
		for (char c : s) {
			cnt[c] += 1;
		}
		for (int i = 0; i < k; ++i) {
			sort(cnt, cnt + 256);
			cnt[255] = max(0, cnt[255] - 1);
		}
		int ans = 0;
		for (int i = 0; i < 256; ++i) {
			ans += cnt[i] * cnt[i];
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
			string Arg0 = "aba";
			int Arg1 = 1;
			int Arg2 = 2;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abacaba";
			int Arg1 = 0;
			int Arg2 = 21;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abacaba";
			int Arg1 = 1;
			int Arg2 = 14;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abacaba";
			int Arg1 = 3;
			int Arg2 = 6;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abc";
			int Arg1 = 3;
			int Arg2 = 0;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "wersrsresesrsesrawsdsw";
			int Arg1 = 11;
			int Arg2 = 23;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Istr ___test;
	___test.run_test(-1);
}
// END CUT HERE
