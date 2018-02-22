// BEGIN CUT HERE
/*
SRM 730 Div2 Easy (250)

問題
- 閉区間[x,y]はxとyの間の全ての実数を含む。
- 閉区間の長さはy-xである。
- 二つの閉区間について、一つでも共通の数が含まれれば、交差しているものとする。
- 二つの閉区間[x1,y1]と[x2,y2]が与えられる。
- 二つの閉区間の両方に交差する閉区間[a,b]の長さを求めよ。

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class IntervalIntersections {
public:
	int minLength(int x1, int y1, int x2, int y2) {
		if (x1 > x2) {
			swap(x1, x2);
			swap(y1, y2);
		}
		return x2 - min(y1, x2);
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
			int Arg0 = 3;
			int Arg1 = 6;
			int Arg2 = 1;
			int Arg3 = 2;
			int Arg4 = 1;

			verify_case(n, Arg4, minLength(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 2;
			int Arg2 = 3;
			int Arg3 = 6;
			int Arg4 = 1;

			verify_case(n, Arg4, minLength(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 10;
			int Arg2 = 2;
			int Arg3 = 5;
			int Arg4 = 0;

			verify_case(n, Arg4, minLength(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 5;
			int Arg2 = 1;
			int Arg3 = 4;
			int Arg4 = 0;

			verify_case(n, Arg4, minLength(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 1000000;
			int Arg3 = 1000000;
			int Arg4 = 999999;

			verify_case(n, Arg4, minLength(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	IntervalIntersections ___test;
	___test.run_test(-1);
}
// END CUT HERE
