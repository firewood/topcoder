// BEGIN CUT HERE
/*
SRM 642 Div2 Easy (250)

問題
-数値が与えられる
-数値のどこかの間にプラス記号をはさむ
-ありうる最小の計算結果を求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class ForgetfulAddition {
public:
	int minNumber(string expression) {
		int ans = 1 << 30;
		for (int i = 1; i < (int)expression.length(); ++i) {
			int a = atoi(expression.substr(0, i).c_str());
			int b = atoi(expression.substr(i).c_str());
			ans = min(ans, a + b);
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
			string Arg0 = "22";
			int Arg1 = 4;

			verify_case(n, Arg1, minNumber(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "123";
			int Arg1 = 15;

			verify_case(n, Arg1, minNumber(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "1289";
			int Arg1 = 101;

			verify_case(n, Arg1, minNumber(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "31415926";
			int Arg1 = 9067;

			verify_case(n, Arg1, minNumber(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "98765";
			int Arg1 = 863;

			verify_case(n, Arg1, minNumber(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ForgetfulAddition ___test;
	___test.run_test(-1);
}
// END CUT HERE
