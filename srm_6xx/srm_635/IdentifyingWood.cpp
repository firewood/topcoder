// BEGIN CUT HERE
/*
SRM 635 Div2 Easy (250)

問題
-文字列sから何文字か削除して文字列tに一致するかどうを求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class IdentifyingWood {
public:
	string check(string s, string t) {
		int pos = 0;
		for (int i = 0; i < (int)s.length(); ++i) {
			if (s[i] == t[pos]) {
				++pos;
				if (pos >= (int)t.length()) {
					return "Yep, it's wood.";
				}
			}
		}
		return "Nope.";
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
			string Arg0 = "absdefgh";
			string Arg1 = "asdf";
			string Arg2 = "Yep, it's wood.";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "oxoxoxox";
			string Arg1 = "ooxxoo";
			string Arg2 = "Nope.";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "oxoxoxox";
			string Arg1 = "xxx";
			string Arg2 = "Yep, it's wood.";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "qwerty";
			string Arg1 = "qwerty";
			string Arg2 = "Yep, it's wood.";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "string";
			string Arg1 = "longstring";
			string Arg2 = "Nope.";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	IdentifyingWood ___test;
	___test.run_test(-1);
}
// END CUT HERE
