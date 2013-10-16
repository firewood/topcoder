// BEGIN CUT HERE
/*
SRM 587 Div1 Easy (250)

問題
-階段の最下段にいる
-全部でn回ジャンプできる
-i回目のジャンプの距離はiである
-特定の段が壊れている
-到達できる最高位置を求める

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class JumpFurther {
public:
	int furthest(int N, int badStep) {
		int ans = 0;
		for (int i = 1; i <= N; ++i) {
			ans += i;
			if (ans == badStep) {
				--ans;
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
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 3;

			verify_case(n, Arg2, furthest(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;
			int Arg2 = 2;

			verify_case(n, Arg2, furthest(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			int Arg2 = 5;

			verify_case(n, Arg2, furthest(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1313;
			int Arg1 = 5858;
			int Arg2 = 862641;

			verify_case(n, Arg2, furthest(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 757065;
			int Arg2 = 1;

			verify_case(n, Arg2, furthest(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	JumpFurther ___test;
	___test.run_test(-1);
}
// END CUT HERE
