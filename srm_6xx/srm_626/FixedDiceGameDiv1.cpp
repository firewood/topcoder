// BEGIN CUT HERE
/*
SRM 626 Div1 Easy (250)

問題
-Aliceはa個のb面ダイスを振る
-Bobはc個のd面ダイスを振る
-n面ダイスは1からnの値を持つ
-出目の合計の多いほうが勝ち
-Aliceが勝つときの期待値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class FixedDiceGameDiv1 {
public:
	void gen(int a, int b, double(&r)[2600]) {
		double tbl[2][2600] = {};
		tbl[0][0] = 1;
		for (int i = 1; i <= a; ++i) {
			for (int j = 0; j <= i*b; ++j) {
				double sum = 0;
				for (int k = 1; k <= b && k <= j; ++k) {
					sum += tbl[(i + 1) % 2][j - k];
				}
				tbl[i % 2][j] = sum / b;
			}
		}
		for (int i = 0; i <= a*b; ++i) {
			r[i] = tbl[a % 2][i];
		}
	}

	double getExpectation(int a, int b, int c, int d) {
		double tbl[2][2600] = {};
		gen(a, b, tbl[0]);
		gen(c, d, tbl[1]);
		double sum[2501] = {};
		for (int i = 1; i <= 2500; ++i) {
			sum[i] = sum[i - 1] + tbl[1][i];
		}

		double pa = 0, pb = 0;
		for (int i = 2; i <= a*b; ++i) {
			double p = tbl[0][i] * sum[i - 1];
			pa += i * p;
			pb += p;
		}
		return pb > 0 ? pa / pb : -1;
	}

#if 0
	void gen(int a, int b, double(&r)[2600]) {
		double tbl[2][2600] = {};
		tbl[0][0] = 1;
		for (int i = 1; i <= a; ++i) {
			for (int j = 0; j < 2600; ++j) {
				tbl[i % 2][j] = 0;
			}
			for (int j = 1; j <= b; ++j) {
				for (int k = 0; k <= a*b; ++k) {
					tbl[i % 2][k + j] += tbl[(i + 1) % 2][k] / b;
				}
			}
		}
		for (int i = 0; i <= a*b; ++i) {
			r[i] = tbl[a % 2][i];
		}
	}

	double getExpectation(int a, int b, int c, int d) {
		double tbl[2][2600] = {};
		gen(a, b, tbl[0]);
		gen(c, d, tbl[1]);
		double pa = 0, pb = 0;
		for (int i = 2; i <= a*b; ++i) {
			double win = tbl[0][i];
			if (win > 0) {
				double sum = 0;
				for (int j = 1; j < i; ++j) {
					sum += tbl[1][j];
				}
				if (sum > 0) {
					pa += (double)i * win * sum;
					pb += win * sum;
				}
			}
		}
		return pb > 0 ? pa / pb : -1;
	}
#endif

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (fabs(Expected - Received) < 1.0e-9) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 2;
			int Arg2 = 1;
			int Arg3 = 5;
			double Arg4 = 2.0;

			verify_case(n, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 3;
			double Arg4 = 3.0;

			verify_case(n, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 5;
			int Arg2 = 1;
			int Arg3 = 1;
			double Arg4 = 3.4999999999999996;

			verify_case(n, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 6;
			int Arg2 = 50;
			int Arg3 = 30;
			double Arg4 = -1.0;

			verify_case(n, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			int Arg1 = 11;
			int Arg2 = 50;
			int Arg3 = 50;
			double Arg4 = 369.8865999182022;

			verify_case(n, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FixedDiceGameDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
