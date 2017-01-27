// BEGIN CUT HERE
/*
SRM 703 Div2 Easy (250)

問題
-隣り合う2文字が全て異なる文字列を交互文字列とする
-0と1からなる文字列sが与えられる
-sの部分文字列のうち交互文字列であるものの最大の長さを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class AlternatingString {
public:
	int maxLength(string s) {
		int ans = 0;
		for (int i = 0; i != 2; ++i) {
			for (int j = 0; j != s.length(); ++j) {
				int k;
				for (k = j; k != s.length(); ++k) {
					if ((s[k] - '0') != ((k & 1) ^ i)) {
						break;
					}
				}
				ans = max(ans, k - j);
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
			string Arg0 = "111101111";
			int Arg1 = 3;

			verify_case(n, Arg1, maxLength(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "1010101";
			int Arg1 = 7;

			verify_case(n, Arg1, maxLength(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "000011110000";
			int Arg1 = 2;

			verify_case(n, Arg1, maxLength(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "1011011110101010010101";
			int Arg1 = 8;

			verify_case(n, Arg1, maxLength(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "0";
			int Arg1 = 1;

			verify_case(n, Arg1, maxLength(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AlternatingString ___test;
	___test.run_test(-1);
}
// END CUT HERE
