// BEGIN CUT HERE
/*
SRM 623 Div2 Medium (450)

問題
-半径Rの円筒状のチューブがある
-時刻0にて秒速Vratで移動できるネズミを投入する
-時刻tにて秒速Vcatで移動できる猫を投入する
-ネズミが最大限逃げるとき、猫がネズミをつかえまる時間を求める

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

class CatAndRat {
public:
	double getTime(int R, int T, int Vrat, int Vcat) {
		if (Vcat <= Vrat) {
			return -1;
		}
		double x = (double)T * Vrat;
		double r = (double)R * M_PI;
		double pos = min(x, r);
		return pos / (double)(Vcat - Vrat);
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
			int Arg0 = 10;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 1;
			double Arg4 = -1.0;

			verify_case(n, Arg4, getTime(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 2;
			double Arg4 = 1.0;

			verify_case(n, Arg4, getTime(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 1;
			int Arg2 = 2;
			int Arg3 = 1;
			double Arg4 = -1.0;

			verify_case(n, Arg4, getTime(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000;
			int Arg1 = 1000;
			int Arg2 = 1;
			int Arg3 = 1000;
			double Arg4 = 1.001001001001001;

			verify_case(n, Arg4, getTime(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1000;
			int Arg2 = 1;
			int Arg3 = 2;
			double Arg4 = 3.141592653589793;

			verify_case(n, Arg4, getTime(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CatAndRat ___test;
	___test.run_test(-1);
}
// END CUT HERE
