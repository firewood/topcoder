// BEGIN CUT HERE
/*
SRM 604 Div2 Medium (500)

問題
-4方向の移動を受け付けるロボットがいる
-ターンkに距離3^k移動できる
-与えられた座標に移動可能かどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class PowerOfThreeEasy {

	bool check(int x, int y) {
		while (x != 0 || y != 0) {
			int a = x % 3, b = y % 3;
			if ((a != 0 && b == 0) || (a == 0 && b != 0)) {
				x = (x + a) / 3;
				y = (y + b) / 3;
			} else {
				return false;
			}
		}
		return true;
	}

public:
	string ableToGet(int x, int y) {
		return check(x, y) ? "Possible" : "Impossible";
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
			int Arg1 = 3;
			string Arg2 = "Possible";

			verify_case(n, Arg2, ableToGet(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			string Arg2 = "Impossible";

			verify_case(n, Arg2, ableToGet(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 0;
			string Arg2 = "Impossible";

			verify_case(n, Arg2, ableToGet(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 9;
			string Arg2 = "Impossible";

			verify_case(n, Arg2, ableToGet(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 10;
			string Arg2 = "Possible";

			verify_case(n, Arg2, ableToGet(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1093;
			int Arg1 = 2187;
			string Arg2 = "Possible";

			verify_case(n, Arg2, ableToGet(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 0;
			string Arg2 = "Possible";

			verify_case(n, Arg2, ableToGet(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PowerOfThreeEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
