// BEGIN CUT HERE
/*
SRM 564 Div2 Easy (250)

問題
-連続する文字を1文字に置き換えた結果、左右対称ならFAUXとする
-文字列が左右対称なのか、FAUXなのか、そうでないのかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class FauxPalindromes {
public:
	string classifyIt(string word) {
		string s = word;
		reverse(s.begin(), s.end());
		if (word == s) {
			return "PALINDROME";
		}
		string a;
		int i;
		for (i = 0; i < (int)word.length(); ++i) {
			if (i == 0 || word[i-1] != word[i]) {
				a += word[i];
			}
		}
		string b = a;
		reverse(b.begin(), b.end());
		if (a == b) {
			return "FAUX";
		}
		return "NOT EVEN FAUX";
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
			string Arg0 = "ANA";
			string Arg1 = "PALINDROME";

			verify_case(n, Arg1, classifyIt(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AAAAANNAA";
			string Arg1 = "FAUX";

			verify_case(n, Arg1, classifyIt(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "LEGENDARY";
			string Arg1 = "NOT EVEN FAUX";

			verify_case(n, Arg1, classifyIt(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "XXXYTYYTTYX";
			string Arg1 = "FAUX";

			verify_case(n, Arg1, classifyIt(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "TOPCOODEREDOOCPOT";
			string Arg1 = "PALINDROME";

			verify_case(n, Arg1, classifyIt(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "TOPCODEREDOOCPOT";
			string Arg1 = "FAUX";

			verify_case(n, Arg1, classifyIt(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "XXXXYYYYYZZXXYYY";
			string Arg1 = "NOT EVEN FAUX";

			verify_case(n, Arg1, classifyIt(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FauxPalindromes ___test;
	___test.run_test(-1);
}
// END CUT HERE
