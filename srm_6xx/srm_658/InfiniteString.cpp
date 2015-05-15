// BEGIN CUT HERE
/*
SRM 658 Div2 Easy (250)

問題
-文字列sを無限に連結した文字列と、文字列tを無限に連結した文字列が同じかどうかを求める

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

class InfiniteString {
public:
	string equal(string s, string t) {
		string a, b;
		for (int i = 0; i < t.length(); ++i) {
			a += s;
		}
		for (int i = 0; i < s.length(); ++i) {
			b += t;
		}
		return a == b ? "Equal" : "Not equal";
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
			string Arg1 = "abab";
			string Arg2 = "Equal";

			verify_case(n, Arg2, equal(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abc";
			string Arg1 = "bca";
			string Arg2 = "Not equal";

			verify_case(n, Arg2, equal(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abab";
			string Arg1 = "aba";
			string Arg2 = "Not equal";

			verify_case(n, Arg2, equal(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaaa";
			string Arg1 = "aaaaaa";
			string Arg2 = "Equal";

			verify_case(n, Arg2, equal(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ababab";
			string Arg1 = "abab";
			string Arg2 = "Equal";

			verify_case(n, Arg2, equal(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "a";
			string Arg1 = "z";
			string Arg2 = "Not equal";

			verify_case(n, Arg2, equal(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	InfiniteString ___test;
	___test.run_test(-1);
}
// END CUT HERE
