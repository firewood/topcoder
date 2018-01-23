// BEGIN CUT HERE
/*
SRM 727 Div1 Easy (250)

問題
-文字列Xから0文字以上の文字を削除して作れる文字列を部分文字列とする
-部分文字列としてSATANを含まない文字列Sが与えられる
-以下の条件を満たす文字列Xを求めよ
  -Xは部分文字列としてSを含む
  -Xは部分文字列としてSANTAを含む
  -Xは部分文字列としてSATANを含まない

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

__inline bool contains(const string &source, const string &target) {
	int pos = 0;
	for (char c : target) {
		if (c == source[pos]) {
			++pos;
			if (pos == source.length()) {
				return true;
			}
		}
	}
	return false;
}

class OnlySanta {
public:
	string solve(string S) {
		size_t n = S.rfind('N');
		if (n == string::npos) {
			return "SANTA" + S;
		}
		string p = S.substr(0, n);
		string q = S.substr(n);
		size_t s = p.find('S');
		if (s == string::npos) {
			return p + "SA" + q + "TA";
		}
		size_t a = p.find('A', s);
		if (a == string::npos) {
			return p + "A" + q + "TA";
		}
		return S + "TA";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) {
		cerr << "Test Case #" << Case << "...";
		if (contains("SANTA", Received) && !contains("SATAN", Received)) {
			cerr << "PASSED" << endl;
		} else {
			cerr << "FAILED" << endl;
			cerr << "\tExpected: \"" << Expected << '\"' << endl;
			cerr << "\tReceived: \"" << Received << '\"' << endl;
		}
	}

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "STANA";
			string Arg1 = "STANTA";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "STN";
			string Arg1 = "SANTNA";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RATSNOOOA";
			string Arg1 = "DEARATSNOOOSANTA";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "SXAYNTA";
			string Arg1 = "OOOOSOXAYNTOOOOAOOO";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "SNTA";
			string Arg1 = "SANTA";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ASNTA";
			string Arg1 = "SASNTAS";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "NIELATA";
			string Arg1 = "SANIELATAJA";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			string Arg0 = "X";
			string Arg1 = "SSAAXNNTTAA";

			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OnlySanta ___test;
	___test.run_test(-1);
}
// END CUT HERE
