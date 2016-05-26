// BEGIN CUT HERE
/*
SRM 688 Div2 Easy (250)

–â‘è
-Š‡ŒÊ‚¾‚¯‚Ì•¶š—ñ‚ª—^‚¦‚ç‚ê‚é
-‹ó•¶š—ñ‚Ì[‚³‚ğ0‚Æ‚·‚é
-"()"‚Ì[‚³‚ğ1‚Æ‚·‚é
-"(X)"‚Ì[‚³‚ğX‚Ì[‚³+1‚Æ‚·‚é
-"XY"‚Ì[‚³‚ğX‚ÆY‚Ì[‚³‚ÌÅ‘å’l‚Æ‚·‚é
-•¶š—ñs‚Ì[‚³‚ğ‹‚ß‚é

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

class ParenthesesDiv2Easy {
public:
	int getDepth(string s) {
		int ans = 0, cnt = 0;
		for (int i = 0; i != s.length(); ++i) {
			if (s[i] == '(') {
				++cnt;
				ans = max(ans, cnt);
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
			string Arg0 = "(())";
			int Arg1 = 2;

			verify_case(n, Arg1, getDepth(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "()()()";
			int Arg1 = 1;

			verify_case(n, Arg1, getDepth(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "(())()";
			int Arg1 = 2;

			verify_case(n, Arg1, getDepth(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "((())())(((())(()))())";
			int Arg1 = 4;

			verify_case(n, Arg1, getDepth(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "()";
			int Arg1 = 1;

			verify_case(n, Arg1, getDepth(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ParenthesesDiv2Easy ___test;
	___test.run_test(-1);
}
// END CUT HERE
