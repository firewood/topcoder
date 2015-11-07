// BEGIN CUT HERE
/*
SRM 670 Div1 Easy (250)

問題
-'('と')'だけからなる文字列がある
-それらのうち閉じ括弧が正しく対応している文字列Sがある
-文字列Tが次の条件を満たすとき、Tの個数を求める
-Sと同じ長さ
-閉じ括弧が正しく対応している
-Sとは異なる
-SとTの部分文字列の共通部分の長さが最大

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Bracket107 {

	bool check(string s) {
		int cnt = 0;
		for (char c : s) {
			if (c == '(') {
				++cnt;
			} else if (--cnt < 0) {
				return false;
			}
		}
		return true;
	}

public:
	int yetanother(string s) {
		set<string> m;
		int len = s.length();
		for (int i = 1; i < len - 1; ++i) {
			string a = s.substr(0, i) + s.substr(i + 1);
			for (int j = 1; j < len - 1; ++j) {
				string b = a.substr(0, j) + s[i] + a.substr(j);
				if (check(b)) {
					m.insert(b);
				}
			}
		}
		return m.size() - 1;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) {
		cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "(())";
			int Arg1 = 1;

			verify_case(n, Arg1, yetanother(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "(())()";
			int Arg1 = 3;

			verify_case(n, Arg1, yetanother(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "()()()";
			int Arg1 = 3;

			verify_case(n, Arg1, yetanother(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "(((())))";
			int Arg1 = 5;

			verify_case(n, Arg1, yetanother(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "((())())";
			int Arg1 = 9;

			verify_case(n, Arg1, yetanother(Arg0));
		}
		n++;
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Bracket107 ___test;
	___test.run_test(-1);
}
// END CUT HERE
