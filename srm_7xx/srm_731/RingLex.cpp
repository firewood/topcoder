// BEGIN CUT HERE
/*
SRM 731 Div2 Easy (250)

問題
-長さNの文字列Sを無限に繰り返した文字列Tがある
-N未満の素数Pをひとつ選び、文字列Tの位置Xから、X+P、X+2Pというように、Pずつ増やした位置でN個の文字を選ぶ
-この操作でできる辞書順最小の文字列を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class RingLex {
public:
	string getmin(string s) {
		int is_prime[1000];
		fill(is_prime, is_prime + 1000, 1);
		for (int i = 2; i < 1000; ++i) {
			if (is_prime[i]) {
				for (int j = 2 * i; j < 1000; j += i) {
					is_prime[j] = 0;
				}
			}
		}
		string ans = string(s.length(), 'z');
		for (int i = 2; i < (int)s.length(); ++i) {
			if (is_prime[i]) {
				for (int j = 0; j < (int)s.length(); ++j) {
					string x;
					for (int k = 0; k < (int)s.length(); ++k) {
						x += s[(j + i * k) % s.length()];
					}
					if (x < ans) {
						ans = x;
					}
				}
			}
		}
		return ans;
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
			string Arg0 = "cba";
			string Arg1 = "abc";

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "acb";
			string Arg1 = "abc";

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abacaba";
			string Arg1 = "aaaabcb";

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaabb";
			string Arg1 = "aabab";

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "azzzabbb";
			string Arg1 = "abazabaz";

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abbaac";
			string Arg1 = "aaaaaa";

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "fsdifyhsoe";
			string Arg1 = "dehifsfsoy";

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RingLex ___test;
	___test.run_test(-1);
}
// END CUT HERE
