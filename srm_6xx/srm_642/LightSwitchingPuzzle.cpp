// BEGIN CUT HERE
/*
SRM 642 Div2 Medium (500)

問題
-N個のスイッチと電灯がある
-n番のスイッチはnの倍数の電灯の状態をトグルさせる
-各電灯の状態が与えられる
-すべての電灯をオフにするための操作回数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class LightSwitchingPuzzle {
public:
	int minFlips(string state) {
		int ans = 0;
		for (int i = 0; i < (int)state.length(); ++i) {
			if (state[i] == 'Y') {
				++ans;
				for (int j = i; j < (int)state.length(); j += (i + 1)) {
					state[j] = (state[j] == 'Y') ? 'N' : 'Y';
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
			string Arg0 = "YYYYYY";
			int Arg1 = 1;

			verify_case(n, Arg1, minFlips(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "YNYNYNYNY";
			int Arg1 = 2;

			verify_case(n, Arg1, minFlips(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "NNNNNNNNNN";
			int Arg1 = 0;

			verify_case(n, Arg1, minFlips(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "YYYNYYYNYYYNYYNYYYYN";
			int Arg1 = 4;

			verify_case(n, Arg1, minFlips(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "NYNNYNNNYNNNNYNNNNNYNNNNNNYNNNNNNNY";
			int Arg1 = 12;

			verify_case(n, Arg1, minFlips(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LightSwitchingPuzzle ___test;
	___test.run_test(-1);
}
// END CUT HERE
