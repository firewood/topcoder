// BEGIN CUT HERE
/*
SRM 652 Div2 Easy (250)

問題
-文字列が与えられる
-aからzの文字の基礎点がそれぞれ1から26である
-ある文字xのスコアは、基礎点×x以下の基礎点の文字数である
-スコアの合計を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class ValueOfString {
public:
	int findValue(string s) {
		int cnt[26] = {};
		for (char c : s) {
			cnt[c - 'a'] += 1;
		}
		int ans = 0;
		int t = 0;
		for (int i = 0; i < 26; ++i) {
			if (cnt[i]) {
				t += cnt[i];
				ans += cnt[i] * t * (i + 1);
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
			string Arg0 = "babca";
			int Arg1 = 35;

			verify_case(n, Arg1, findValue(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "zz";
			int Arg1 = 104;

			verify_case(n, Arg1, findValue(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "y";
			int Arg1 = 25;

			verify_case(n, Arg1, findValue(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaabbc";
			int Arg1 = 47;

			verify_case(n, Arg1, findValue(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "topcoder";
			int Arg1 = 558;

			verify_case(n, Arg1, findValue(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "thequickbrownfoxjumpsoverthelazydog";
			int Arg1 = 11187;

			verify_case(n, Arg1, findValue(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "zyxwvutsrqponmlkjihgfedcba";
			int Arg1 = 6201;

			verify_case(n, Arg1, findValue(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ValueOfString ___test;
	___test.run_test(-1);
}
// END CUT HERE
