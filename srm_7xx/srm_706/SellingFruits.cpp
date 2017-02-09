// BEGIN CUT HERE
/*
SRM 706 Div2 Medium (500)

問題
-Limakは毎日フルーツを1個食べ、xドル使う
-フルーツがf個、dドル持っていて、pドルでフルーツが買える
-Limakが何日過ごせるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class SellingFruits {
public:
	int maxDays(int x, int f, int d, int p) {
		int dd = min(f, d / x);
		return dd + (d - dd * x) / ((long long)x + p);
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
			int Arg1 = 5;
			int Arg2 = 100;
			int Arg3 = 10;
			int Arg4 = 11;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 17;
			int Arg2 = 20;
			int Arg3 = 1;
			int Arg4 = 10;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 97;
			int Arg2 = 98;
			int Arg3 = 1;
			int Arg4 = 97;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 16;
			int Arg1 = 4;
			int Arg2 = 8;
			int Arg3 = 2;
			int Arg4 = 0;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 17;
			int Arg1 = 1;
			int Arg2 = 2000000000;
			int Arg3 = 4;
			int Arg4 = 95238095;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1996245611;
			int Arg2 = 1999990159;
			int Arg3 = 123;
			int Arg4 = 1996275808;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 15000000;
			int Arg1 = 100;
			int Arg2 = 2000000000;
			int Arg3 = 1;
			int Arg4 = 133;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1000000000;
			int Arg2 = 2000000000;
			int Arg3 = 1000000000;
			int Arg4 = 1000000000;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SellingFruits ___test;
	___test.run_test(-1);
}
// END CUT HERE
