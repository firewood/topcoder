// BEGIN CUT HERE
/*
SRM 656 Div2 Easy (250)

問題
-同じ文字からなる文字列がある
-K文字が別の文字に変更された
-元の文字列の候補を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class CorruptedMessage {
public:
	string reconstructMessage(string s, int k) {
		int cnt[256] = {};
		for (char c : s) {
			cnt[c] += 1;
		}
		char c;
		for (c = 'a'; c <= 'z'; ++c) {
			if ((cnt[c] + k) == s.length()) {
				break;
			}
		}
		return string(s.length(), c);
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
			string Arg0 = "hello";
			int Arg1 = 3;
			string Arg2 = "lllll";

			verify_case(n, Arg2, reconstructMessage(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abc";
			int Arg1 = 3;
			string Arg2 = "ddd";

			verify_case(n, Arg2, reconstructMessage(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "wwwwwwwwwwwwwwwwww";
			int Arg1 = 0;
			string Arg2 = "wwwwwwwwwwwwwwwwww";

			verify_case(n, Arg2, reconstructMessage(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ababba";
			int Arg1 = 3;
			string Arg2 = "aaaaaa";

			verify_case(n, Arg2, reconstructMessage(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "zoztxtoxytyt";
			int Arg1 = 10;
			string Arg2 = "oooooooooooo";

			verify_case(n, Arg2, reconstructMessage(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "jlmnmiunaxzywed";
			int Arg1 = 13;
			string Arg2 = "mmmmmmmmmmmmmmm";

			verify_case(n, Arg2, reconstructMessage(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CorruptedMessage ___test;
	___test.run_test(-1);
}
// END CUT HERE
