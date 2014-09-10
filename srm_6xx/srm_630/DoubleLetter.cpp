// BEGIN CUT HERE
/*
SRM 630 Div2 Easy (250)

問題
-文字列Sが与えられる
-2文字以上連続する文字のうち、最も左のものを削除していく
-最終的に空文字列になるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class DoubleLetter {
public:
	string ableToSolve(string S) {
		while (true) {
			int len = (int)S.length();
			int i;
			for (i = 0; i < len - 1; ++i) {
				if (S[i] == S[i + 1]) {
					break;
				}
			}
			if (i >= len - 1) {
				break;
			}
			S = S.substr(0, i) + S.substr(i + 2);
		}
		return S.length() == 0 ? "Possible" : "Impossible";
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
			string Arg0 = "aabccb";
			string Arg1 = "Possible";

			verify_case(n, Arg1, ableToSolve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aabccbb";
			string Arg1 = "Impossible";

			verify_case(n, Arg1, ableToSolve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcddcba";
			string Arg1 = "Possible";

			verify_case(n, Arg1, ableToSolve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abab";
			string Arg1 = "Impossible";

			verify_case(n, Arg1, ableToSolve(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaaaaaaaa";
			string Arg1 = "Possible";

			verify_case(n, Arg1, ableToSolve(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aababbabbaba";
			string Arg1 = "Impossible";

			verify_case(n, Arg1, ableToSolve(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "zzxzxxzxxzzx";
			string Arg1 = "Possible";

			verify_case(n, Arg1, ableToSolve(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DoubleLetter ___test;
	___test.run_test(-1);
}
// END CUT HERE
