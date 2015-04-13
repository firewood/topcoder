// BEGIN CUT HERE
/*
SRM 654 Div2 Easy (250)

問題
-文字列Sの同じ文字だけからなる部分文字列の数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SquareScoresDiv2 {
	public:
	int getscore(string s) {
		int ans = 0;
		int len = s.length();
		for (int i = 0; i < len; ++i) {
			for (int j = 0; i + j < len; ++j) {
				if (s[i] != s[i + j]) {
					break;
				}
				++ans;
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
			string Arg0 = "aaaba";
			int Arg1 = 8;

			verify_case(n, Arg1, getscore(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "zzzxxzz";
			int Arg1 = 12;

			verify_case(n, Arg1, getscore(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcdefghijklmnopqrstuvwxyz";
			int Arg1 = 26;

			verify_case(n, Arg1, getscore(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "p";
			int Arg1 = 1;

			verify_case(n, Arg1, getscore(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
			int Arg1 = 5050;

			verify_case(n, Arg1, getscore(Arg0));
		}
		n++;

	}
// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SquareScoresDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
