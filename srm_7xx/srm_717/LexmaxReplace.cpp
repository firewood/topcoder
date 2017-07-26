// BEGIN CUT HERE
/*
SRM 717 Div2 Medium (500)

問題
-小文字のアルファベットだけからなる文字列sがある
-何枚かのカードがあり、それぞれに小文字のアルファベットが書かれている
-各カードは、sのいずれかの文字に貼りつけることができる
-得られる辞書順最大の文字列を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class LexmaxReplace {
public:
	string get(string s, string t) {
		int pos = 0;
		sort(t.rbegin(), t.rend());
		for (char c : t) {
			while (pos != s.length() && s[pos] >= c) {
				++pos;
			}
			if (pos == s.length()) {
				break;
			}
			s[pos++] = c;
		}
		return s;
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
			string Arg0 = "abb";
			string Arg1 = "c";
			string Arg2 = "cbb";

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "z";
			string Arg1 = "f";
			string Arg2 = "z";

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "fedcba";
			string Arg1 = "ee";
			string Arg2 = "feeeba";

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "top";
			string Arg1 = "coder";
			string Arg2 = "trp";

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "xldyzmsrrwzwaofkcxwehgvtrsximxgdqrhjthkgfucrjdvwlr";
			string Arg1 = "xfpidmmilhdfzypbguentqcojivertdhshstkcysydgcwuwhlk";
			string Arg2 = "zyyyzyxwwwzwvuuttxwtssvtssxrqxppqrontmmllukrkjvwlr";

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LexmaxReplace ___test;
	___test.run_test(-1);
}
// END CUT HERE
