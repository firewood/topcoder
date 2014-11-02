// BEGIN CUT HERE
/*
SRM 608 Div2 Easy (250)

問題
-一次元平面上をロボットが移動する
-ロボットは座標(-A,0)から(B,0)までの範囲を取る
-コマンドが与えられる
-ロボットの最終座標を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class OneDimensionalRobotEasy {
public:
	int finalPosition(string commands, int A, int B) {
		int pos = 0;
		for (char c : commands) {
			if (c == 'L') {
				pos = max(-A, pos - 1);
			} else {
				pos = min(B, pos + 1);
			}
		}
		return pos;
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
			string Arg0 = "RRLRRLLR";
			int Arg1 = 10;
			int Arg2 = 10;
			int Arg3 = 2;

			verify_case(n, Arg3, finalPosition(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RRRRR";
			int Arg1 = 3;
			int Arg2 = 4;
			int Arg3 = 4;

			verify_case(n, Arg3, finalPosition(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "LLLLLLLLLLR";
			int Arg1 = 2;
			int Arg2 = 6;
			int Arg3 = -1;

			verify_case(n, Arg3, finalPosition(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RRRRRRRLRRLRRRRRRRRRRRRLRLRRRRRRRRLRRRRRLRRRRRRRRR";
			int Arg1 = 5;
			int Arg2 = 20;
			int Arg3 = 20;

			verify_case(n, Arg3, finalPosition(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RLRLLLLLLLRLLLRLLLLLLLLRLLLLLRLLLRRLLLLLRLLLLLRLLL";
			int Arg1 = 34;
			int Arg2 = 15;
			int Arg3 = -30;

			verify_case(n, Arg3, finalPosition(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OneDimensionalRobotEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
