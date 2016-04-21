// BEGIN CUT HERE
/*
SRM 666 Div2 Medium (444)

問題
-空文字列に文字列"ab"を加えていき、文字列sが作れるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <cstring>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class GoodString {
	public:
	string isGood(string s) {
		int pos;
		while ((pos = s.find("ab")) >= 0) {
			s = s.substr(0, pos) + s.substr(pos + 2);
		}
		return s.empty() ? "Good" : "Bad";
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
			string Arg0 = "ab";
			string Arg1 = "Good";

			verify_case(n, Arg1, isGood(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aab";
			string Arg1 = "Bad";

			verify_case(n, Arg1, isGood(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aabb";
			string Arg1 = "Good";

			verify_case(n, Arg1, isGood(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ababab";
			string Arg1 = "Good";

			verify_case(n, Arg1, isGood(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abaababababbaabbaaaabaababaabbabaaabbbbbbbb";
			string Arg1 = "Bad";

			verify_case(n, Arg1, isGood(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaaaaaabbbaaabaaabbabababababaabbbbaabbabbbbbbabb";
			string Arg1 = "Good";

			verify_case(n, Arg1, isGood(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GoodString ___test;
	___test.run_test(-1);
}
// END CUT HERE
