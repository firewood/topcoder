// BEGIN CUT HERE
/*
// SRM 554 Div1 Easy (250)

問題
二種類のブロックを交互に積む。
各ブロックの高さと個数が与えられる。
何通りの高さが作れるか求める。

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TheBrickTowerEasyDivOne {

public:
	int find(int redCount, int redHeight, int blueCount, int blueHeight) {
		int res = 0;
		int a = min(redCount, blueCount);
		int b = max(redCount, blueCount);
		if (redHeight == blueHeight) {
			res = (a * 2) + (b > a);
		} else {
			res = (a * 3) + (b > a);
		}
		return res;
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
			int Arg1 = 2;
			int Arg2 = 3;
			int Arg3 = 4;
			int Arg4 = 4;

			verify_case(n, Arg4, find(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;
			int Arg2 = 4;
			int Arg3 = 7;
			int Arg4 = 12;

			verify_case(n, Arg4, find(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 7;
			int Arg2 = 4;
			int Arg3 = 4;
			int Arg4 = 13;

			verify_case(n, Arg4, find(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 47;
			int Arg1 = 47;
			int Arg2 = 47;
			int Arg3 = 47;
			int Arg4 = 94;

			verify_case(n, Arg4, find(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheBrickTowerEasyDivOne ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
