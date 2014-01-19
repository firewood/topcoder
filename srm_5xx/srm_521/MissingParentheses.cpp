// BEGIN CUT HERE
/*
// SRM 521 Div2 Medium (500)

問題

( か ) からなる文字列がある。
括弧が正しく閉じていない個数を求める。

#line 67 "MissingParentheses.cpp"
*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

class MissingParentheses {

public:
	int countCorrections(string par) {
		int result = 0;
		int o = 0;
		int length = par.length();
		int i;
		for (i = 0; i < length; ++i) {
			if (par[i] == '(') {
				++o;
			}
			if (par[i] == ')') {
				if (o) {
					--o;
				} else {
					++result;
				}
			}
		}
		result += o;

		return result;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "(()(()"; int Arg1 = 2; verify_case(0, Arg1, countCorrections(Arg0)); }
	void test_case_1() { string Arg0 = "()()(()"; int Arg1 = 1; verify_case(1, Arg1, countCorrections(Arg0)); }
	void test_case_2() { string Arg0 = "(())(()())"; int Arg1 = 0; verify_case(2, Arg1, countCorrections(Arg0)); }
	void test_case_3() { string Arg0 = "())(())((()))))()((())))()())())())()()()"; int Arg1 = 7; verify_case(3, Arg1, countCorrections(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MissingParentheses ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
