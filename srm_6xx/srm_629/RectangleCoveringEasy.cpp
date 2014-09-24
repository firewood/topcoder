// BEGIN CUT HERE
/*
SRM 629 Div2 Easy (250)

問題
-地面に四角形の穴が開いていて、四角形の板が1枚ある
-板は穴の座標軸に平行に、かつ、板の四隅が穴の外側になるように置くこと
-地面の穴を完全に覆えるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class RectangleCoveringEasy {
public:
	int solve(int holeH, int holeW, int boardH, int boardW) {
		int hh = min(holeH, holeW);
		int hw = max(holeH, holeW);
		int bh = min(boardH, boardW);
		int bw = max(boardH, boardW);
		if ((bh > hh && bw >= hw) || (bh >= hh && bw > hw)) {
			return 1;
		}
		return -1;
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
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 1;
			int Arg4 = -1;

			verify_case(n, Arg4, solve(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 5;
			int Arg2 = 4;
			int Arg3 = 6;
			int Arg4 = 1;

			verify_case(n, Arg4, solve(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 20;
			int Arg2 = 25;
			int Arg3 = 15;
			int Arg4 = 1;

			verify_case(n, Arg4, solve(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 10;
			int Arg2 = 3;
			int Arg3 = 12;
			int Arg4 = 1;

			verify_case(n, Arg4, solve(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RectangleCoveringEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
