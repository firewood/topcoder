// BEGIN CUT HERE
/*
SRM 628 Div2 Medium (500)

問題
-3種類の括弧がある
-Xは括弧の文字のいずれかである
-括弧またはXからなる文字列が与えられる
-正しく閉じているかどうか求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class BracketExpressions {

	int xs;
	int x[5];

	void shrink(string &s) {
		while (true) {
			int pos = s.find("()");
			if (pos >= 0) {
				s = s.substr(0, pos) + s.substr(pos + 2);
				continue;
			}
			pos = s.find("[]");
			if (pos >= 0) {
				s = s.substr(0, pos) + s.substr(pos + 2);
				continue;
			}
			pos = s.find("{}");
			if (pos >= 0) {
				s = s.substr(0, pos) + s.substr(pos + 2);
				continue;
			}
			break;
		}
	}

	bool can(string s) {
		shrink(s);
		const char *b = "([{}])";
		shrink(s);
		xs = 0;
		int i;
		for (i = 0; i < s.length(); ++i) {
			if (s[i] == 'X') {
				x[xs++] = i;
			}
		}
		if (xs == 0) {
			return s.length() == 0;
		}

		int xc[5] = {};
		while (true) {
			for (i = 0; i < xs; ++i) {
				s[x[i]] = b[xc[i]];
			}
			string a = s;
			shrink(a);
			if (a.length() == 0) {
				return true;
			}
			for (i = 0; i < xs; ++i) {
				xc[i] += 1;
				if (xc[i] < 6) {
					break;
				}
				xc[i] = 0;
			}
			if (i >= xs) {
				break;
			}
		}
		return false;
	}


public:
	string ifPossible(string expression) {
		return can(expression) ? "possible" : "impossible";
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
			string Arg0 = "([]{})";
			string Arg1 = "possible";

			verify_case(n, Arg1, ifPossible(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "(())[]";
			string Arg1 = "possible";

			verify_case(n, Arg1, ifPossible(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "({])";
			string Arg1 = "impossible";

			verify_case(n, Arg1, ifPossible(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "[]X";
			string Arg1 = "impossible";

			verify_case(n, Arg1, ifPossible(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "([]X()[()]XX}[])X{{}}]";
			string Arg1 = "possible";

			verify_case(n, Arg1, ifPossible(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BracketExpressions ___test;
	___test.run_test(-1);
}
// END CUT HERE
