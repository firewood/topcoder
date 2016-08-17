// BEGIN CUT HERE
/*
SRM 696 Div2 Easy (250)

問題
-ロープが文字列で与えられる
-連続するダッシュが一本のロープで、ピリオドが区切り
-ロープの位置を並べ替える
-偶数の長さのものを奇数のものより前に
-ダッシュのほうがピリオドより辞書順が前
-条件を満たす辞書順最小の文字列を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Ropestring {
public:
	string makerope(string s) {
		int cnt[64] = {};
		int i, j, k;
		for (i = 0; i != s.length(); i += j) {
			for (j = 0; i + j != s.length(); ++j) {
				if (s[i + j] != '-') {
					break;
				}
			}
			cnt[j] += 1;
			if (!j) {
				++j;
			}
		}
		string ans;
		for (k = 0; k < 2; ++k) {
			for (i = (s.length() & ~1) | k; i >= 1; i -= 2) {
				for (j = 0; j != cnt[i]; ++j) {
					if (!ans.empty()) {
						ans += '.';
						--cnt[0];
					}
					ans += string(i, '-');
				}
			}
		}
		ans += string(cnt[0], '.');
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
			string Arg0 = "..-..-";
			string Arg1 = "-.-...";

			verify_case(n, Arg1, makerope(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "-.-";
			string Arg1 = "-.-";

			verify_case(n, Arg1, makerope(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "--..-.---..--";
			string Arg1 = "--.--.---.-..";

			verify_case(n, Arg1, makerope(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "--..-.---..--..-----.--.";
			string Arg1 = "--.--.--.-----.---.-....";

			verify_case(n, Arg1, makerope(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "...";
			string Arg1 = "...";

			verify_case(n, Arg1, makerope(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Ropestring ___test;
	___test.run_test(-1);
}
// END CUT HERE
