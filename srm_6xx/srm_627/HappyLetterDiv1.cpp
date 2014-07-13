// BEGIN CUT HERE
/*
SRM 627 Div1 Easy (250)

問題
-文字列が与えられる
-2つの異なる文字を取り除いていく
-最終的に残る可能性のある全ての文字を結合した文字列を求める

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;

class HappyLetterDiv1 {
public:
	string getHappyLetters(string letters) {
		IntVec chars(26);
		for (char c : letters) {
			chars[c - 'a'] += 1;
		}
		string ans;
		for (int i = 0; i < 26; ++i) {
			IntVec cnt = chars;
			int p = cnt[i];
			cnt[i] = 0;

			while (true) {
				sort(cnt.begin(), cnt.end());
				if (cnt[24] > 0 && cnt[25] > 0) {
					cnt[24]--, cnt[25]--;
				} else {
					break;
				}
			}

			int q = accumulate(cnt.begin(), cnt.end(), 0);
			if (p > q) {
				ans += ('a' + i);
			}
		}
		return ans;
	}

private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aabbacccc";
			string Arg1 = "abc";

			verify_case(n, Arg1, getHappyLetters(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaaaaaccdd";
			string Arg1 = "a";

			verify_case(n, Arg1, getHappyLetters(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ddabccadb";
			string Arg1 = "abcd";

			verify_case(n, Arg1, getHappyLetters(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaabbb";
			string Arg1 = "";

			verify_case(n, Arg1, getHappyLetters(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "rdokcogscosn";
			string Arg1 = "cos";

			verify_case(n, Arg1, getHappyLetters(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "aabbccd";
			string Arg1 = "abcd";

			verify_case(n, Arg1, getHappyLetters(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	HappyLetterDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
