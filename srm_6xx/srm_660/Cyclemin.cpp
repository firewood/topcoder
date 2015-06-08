// BEGIN CUT HERE
/*
SRM 660 Div2 Easy (250)

問題
-文字列Sが与えられる
-自由にローテーションした上で、k個だけ文字を入れ替えられる
-辞書順最小の文字列を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Cyclemin {
public:
	string bestmod(string s, int k) {
		string ans = s;
		int len = (int)s.length();
		for (int i = 0; i < len; ++i) {
			string a = s.substr(i, len - i) + s.substr(0, i);
			int cnt = 0;
			for (int j = 0; cnt < k && j < len; ++j) {
				if (a[j] != 'a') {
					a[j] = 'a';
					++cnt;
				}
			}
			ans = min(ans, a);
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
			string Arg0 = "aba";
			int Arg1 = 1;
			string Arg2 = "aaa";

			verify_case(n, Arg2, bestmod(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aba";
			int Arg1 = 0;
			string Arg2 = "aab";

			verify_case(n, Arg2, bestmod(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "bbb";
			int Arg1 = 2;
			string Arg2 = "aab";

			verify_case(n, Arg2, bestmod(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "sgsgaw";
			int Arg1 = 1;
			string Arg2 = "aasgsg";

			verify_case(n, Arg2, bestmod(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abacaba";
			int Arg1 = 1;
			string Arg2 = "aaaabac";

			verify_case(n, Arg2, bestmod(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "isgbiao";
			int Arg1 = 2;
			string Arg2 = "aaaisgb";

			verify_case(n, Arg2, bestmod(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Cyclemin ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
