// BEGIN CUT HERE
/*
SRM 735 Div2 Easy (250)

問題
-マイナス2とプラス3だけが実行できる電卓がある
-この電卓で値aからbにする手数の最小値を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class BinaryCalculator {
public:
	int minimumSteps(int a, int b) {
		int ans = 1 << 30;
		for (int i = 0; i < 1000; ++i) {
			for (int j = 0; j < 1000; ++j) {
				if (a - 2 * i + 3 * j == b) {
					ans = min(ans, i + j);
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
			int Arg0 = 10;
			int Arg1 = 14;
			int Arg2 = 3;

			verify_case(n, Arg2, minimumSteps(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 23;
			int Arg1 = 23;
			int Arg2 = 0;

			verify_case(n, Arg2, minimumSteps(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 18;
			int Arg1 = 12;
			int Arg2 = 3;

			verify_case(n, Arg2, minimumSteps(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 23;
			int Arg1 = 62;
			int Arg2 = 13;

			verify_case(n, Arg2, minimumSteps(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BinaryCalculator ___test;
	___test.run_test(-1);
}
// END CUT HERE
