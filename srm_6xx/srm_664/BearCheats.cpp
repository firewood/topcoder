// BEGIN CUT HERE
/*
SRM 664 Div2 Easy (250)

問題
-数字が与えられる
-1桁以内の変更で、数Aと数Bを同じにできるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class BearCheats {
	public:
	string eyesight(int A, int B) {
		char a[16], b[16];
		sprintf(a, "%d", A);
		sprintf(b, "%d", B);
		int len = strlen(a);
		if (len == strlen(b)) {
			int c = 0;
			for (int i = 0; i < len; ++i) {
				c += a[i] == b[i];
			}
			if (c >= len - 1) {
				return "happy";
			}
		}
		return "glasses";
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
			int Arg0 = 8072;
			int Arg1 = 3072;
			string Arg2 = "happy";

			verify_case(n, Arg2, eyesight(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 508;
			int Arg1 = 540;
			string Arg2 = "glasses";

			verify_case(n, Arg2, eyesight(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 854000;
			int Arg1 = 854000;
			string Arg2 = "happy";

			verify_case(n, Arg2, eyesight(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 6;
			string Arg2 = "happy";

			verify_case(n, Arg2, eyesight(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 385900;
			int Arg1 = 123000;
			string Arg2 = "glasses";

			verify_case(n, Arg2, eyesight(Arg0, Arg1));
		}
		n++;
	}
// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearCheats ___test;
	___test.run_test(-1);
}
// END CUT HERE
