// BEGIN CUT HERE
/*
SRM 726 Div2 Easy (250)

問題
-同じ文字が2回だけ出現する文字列がある
-それぞれの文字を1つ削除し、半分の長さにする
-辞書順最小の文字列を作るときの先頭の文字を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class StringHalving {
public:
	string lexsmallest(string s) {
		int rindex = -1;
		for (char c : s) {
			rindex = max(rindex, (int)(find(s.rbegin(), s.rend(), c) - s.rbegin()));
		}
		char ans = 'z';
		for (char c : s.substr(0, s.length() - 1 - rindex)) {
			ans = min(ans, c);
		}
		return string(1, ans);
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
			string Arg0 = "baba";
			string Arg1 = "a";

			verify_case(n, Arg1, lexsmallest(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "bbaa";
			string Arg1 = "b";

			verify_case(n, Arg1, lexsmallest(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "zyiggiyssz";
			string Arg1 = "g";

			verify_case(n, Arg1, lexsmallest(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "topcodertpcder";
			string Arg1 = "c";

			verify_case(n, Arg1, lexsmallest(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "rvofqorvfq";
			string Arg1 = "f";

			verify_case(n, Arg1, lexsmallest(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	StringHalving ___test;
	___test.run_test(-1);
}
// END CUT HERE
