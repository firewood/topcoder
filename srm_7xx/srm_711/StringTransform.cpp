// BEGIN CUT HERE
/*
SRM 711 Div2 Medium (500)

問題
-同じ長さの文字列sとtがある
-iはjより大きいものとして、s[i]をs[j]に変更することができる
-文字列sを文字列tにすることができるかどうかを求める

*/
// END CUT HERE
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class StringTransform {

	bool possible(string &s, string &t) {
		for (int i = 0; i != s.length(); ++i) {
			int pos = s.find(t[i]);
			if (pos < 0 || pos > i) {
				return false;
			}
		}
		return true;
	}

	public:
	string isPossible(string s, string t) {
		return possible(s, t) ? "Possible" : "Impossible";
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
			string Arg0 = "abc";
			string Arg1 = "aba";
			string Arg2 = "Possible";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abc";
			string Arg1 = "bbc";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "topcoder";
			string Arg1 = "topcoder";
			string Arg2 = "Possible";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "rdmcxnnbbe";
			string Arg1 = "rdrrxrnxbe";
			string Arg2 = "Possible";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "rdmcxnnbbe";
			string Arg1 = "rdqrxrnxbe";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	StringTransform ___test;
	___test.run_test(-1);
}
// END CUT HERE
