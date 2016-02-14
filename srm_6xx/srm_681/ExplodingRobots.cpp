// BEGIN CUT HERE
/*
SRM 681 Div2 Medium (500)

問題
-2台のロボットがいて、それぞれの座標が与えられる
-上下左右からなる一連の移動コマンドを、両方に送る
-両方に同じコマンドを送るが、コマンドのいくつかは無視される可能性がある
-同じ座標になる可能性があるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class ExplodingRobots {
public:
	string canExplode(int x1, int y1, int x2, int y2, string instructions) {
		int dx = abs(x1 - x2), dy = abs(y1 - y2);
		for (char c : instructions) {
			switch (c) {
			case 'U':
			case 'D':
				dy = max(0, dy - 1);
				break;
			case 'R':
			case 'L':
				dx = max(0, dx - 1);
				break;
			}
		}
		return (dx == 0 && dy == 0) ? "Explosion" : "Safe";
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
			int Arg0 = 1;
			int Arg1 = 0;
			int Arg2 = 2;
			int Arg3 = 0;
			string Arg4 = "L";
			string Arg5 = "Explosion";

			verify_case(n, Arg5, canExplode(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 0;
			int Arg2 = 2;
			int Arg3 = 0;
			string Arg4 = "U";
			string Arg5 = "Safe";

			verify_case(n, Arg5, canExplode(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 0;
			int Arg2 = 2;
			int Arg3 = 0;
			string Arg4 = "UL";
			string Arg5 = "Explosion";

			verify_case(n, Arg5, canExplode(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			int Arg2 = 5;
			int Arg3 = 5;
			string Arg4 = "LURLL";
			string Arg5 = "Safe";

			verify_case(n, Arg5, canExplode(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 5;
			int Arg2 = -9;
			int Arg3 = -10;
			string Arg4 = "LULULULLLUULRULULULULULULLULULLULD";
			string Arg5 = "Explosion";

			verify_case(n, Arg5, canExplode(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ExplodingRobots ___test;
	___test.run_test(-1);
}
// END CUT HERE
