// BEGIN CUT HERE
/*
SRM 614 Div2 Easy (250)

問題
-数値AとDが与えられる
-数値Aを文字列化して連結し、AからDを引いていく
-Aが負になるまで続ける
-結果の文字列を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class MicroStrings {
public:
	string makeMicroString(int A, int D) {
		string ans;
		while (A >= 0) {
			char buf[256];
			sprintf(buf, "%d", A);
			ans += buf;
			A -= D;
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
			int Arg0 = 12;
			int Arg1 = 5;
			string Arg2 = "1272";

			verify_case(n, Arg2, makeMicroString(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			string Arg2 = "31";

			verify_case(n, Arg2, makeMicroString(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 31;
			int Arg1 = 40;
			string Arg2 = "31";

			verify_case(n, Arg2, makeMicroString(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 30;
			int Arg1 = 6;
			string Arg2 = "3024181260";

			verify_case(n, Arg2, makeMicroString(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MicroStrings ___test;
	___test.run_test(-1);
}
// END CUT HERE
