// BEGIN CUT HERE
/*
SRM 706 Div2 Easy (250)

問題
-3つの箱にキャンディーがそれぞれa,b,c個入っている
-1回の操作でどれかのキャンディーを1つ食べることができる
-a<b<cとするための最小操作回数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class ThreeIncreasing {
public:
	int minEaten(int a, int b, int c) {
		if (b < 2 || c < 3) {
			return -1;
		}
		int ans = max(0, b - c + 1);
		b -= ans;
		ans += max(0, a - b + 1);
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
			int Arg0 = 15;
			int Arg1 = 40;
			int Arg2 = 22;
			int Arg3 = 19;

			verify_case(n, Arg3, minEaten(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 6;
			int Arg2 = 6;
			int Arg3 = 2;

			verify_case(n, Arg3, minEaten(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 1;
			int Arg2 = 3000;
			int Arg3 = -1;

			verify_case(n, Arg3, minEaten(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 4;
			int Arg2 = 2;
			int Arg3 = -1;

			verify_case(n, Arg3, minEaten(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 2;
			int Arg2 = 6;
			int Arg3 = 3;

			verify_case(n, Arg3, minEaten(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1234;
			int Arg2 = 3000;
			int Arg3 = 0;

			verify_case(n, Arg3, minEaten(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2789;
			int Arg1 = 2400;
			int Arg2 = 1693;
			int Arg3 = 1806;

			verify_case(n, Arg3, minEaten(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ThreeIncreasing ___test;
	___test.run_test(-1);
}
// END CUT HERE
