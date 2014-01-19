// BEGIN CUT HERE
/*
// SRM 563 Div2 Easy (250)

問題
-文字列の途中に同じ文字列を挿入する操作を拡張とする
-与えられた文字列が拡張操作によるものかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class FoxAndHandleEasy {

public:
	string isPossible(string S, string T) {
		if (S.length()*2 == T.length()) {
			for (int i = 0; i <= (int)S.length(); ++i) {
				if (S.compare(T.substr(i, S.length())) == 0) {
					string s = T.substr(0, i);
					s += T.substr(i + S.length(), S.length() - i);
					if (S.compare(s) == 0) {
						return "Yes";
					}
				}
			}
		}
		return "No";
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
			string Arg0 = "Ciel";
			string Arg1 = "CieCiell";
			string Arg2 = "Yes";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Ciel";
			string Arg1 = "FoxCiel";
			string Arg2 = "No";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "FoxCiel";
			string Arg1 = "FoxFoxCielCiel";
			string Arg2 = "Yes";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "FoxCiel";
			string Arg1 = "FoxCielCielFox";
			string Arg2 = "No";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Ha";
			string Arg1 = "HaHaHaHa";
			string Arg2 = "No";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "TheHandleCanBeVeryLong";
			string Arg1 = "TheHandleCanBeVeryLong";
			string Arg2 = "No";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "Long";
			string Arg1 = "LongLong";
			string Arg2 = "Yes";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arg0 = "eTpbJbUCvmNwYkRzmRNn";
			string Arg1 = "eTpbJeTpbJbUCvmNwYkRzmRNnbUCvmNwYkRzmRNn";
			string Arg2 = "Yes";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arg0 = "bNhQYQeGbDxVlDt";
			string Arg1 = "bNhQYQeGbDxVbNhQYQeGbDxVlDtlDt";
			string Arg2 = "Yes";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arg0 = "ycBdMJBjEKCgMNj";
			string Arg1 = "ycycBdMJBjEKCgMNjBdMJBjEKCgMNj";
			string Arg2 = "Yes";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arg0 = "RaPsuHyHGooAAUxkgy";
			string Arg1 = "RaPsuRaPsuHyHGooAAUxkgyHyHGooAAUxkgy";
			string Arg2 = "Yes";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndHandleEasy ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
