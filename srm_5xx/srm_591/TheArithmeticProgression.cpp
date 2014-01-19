// BEGIN CUT HERE
/*
SRM 591 Div2 Easy (250)

問題
-y-x=z-yが成り立つタプル(x,y,z)を等差数列と呼ぶ
-タプルが与えられたとき、等差数列にするために加減算する最小値を求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class TheArithmeticProgression {
public:
	double minimumChange(int a, int b, int c) {
		return fabs((double)(a+c-2*b)*0.5);
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 1;
			int Arg2 = 2;
			double Arg3 = 0.0;

			verify_case(n, Arg3, minimumChange(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 2;
			int Arg2 = 1;
			double Arg3 = 1.5;

			verify_case(n, Arg3, minimumChange(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			int Arg2 = 1;
			double Arg3 = 0.0;

			verify_case(n, Arg3, minimumChange(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;
			int Arg2 = 8;
			double Arg3 = 2.0;

			verify_case(n, Arg3, minimumChange(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheArithmeticProgression ___test;
	___test.run_test(-1);
}
// END CUT HERE
