// BEGIN CUT HERE
/*
SRM 683 Div2 Easy (250)

問題
-文字列sが与えられる
-重ならない2つの部分文字列のうち、同じものの個数を求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class EqualSubstrings2 {
public:
	int get(string s) {
		int ans = 0, N = (int)s.length();
		for (int i = 0; i != N; ++i) {
			for (int j = 1; j <= (N - i) / 2; ++j) {
				for (int k = i + j; k + j <= N; ++k) {
					ans += memcmp(s.c_str() + i, s.c_str() + k, j) == 0;
				}
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
			string Arg0 = "aa";
			int Arg1 = 1;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcd";
			int Arg1 = 0;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aba";
			int Arg1 = 1;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abab";
			int Arg1 = 3;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaab";
			int Arg1 = 7;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "onetwothreeonetwothree";
			int Arg1 = 86;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EqualSubstrings2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
