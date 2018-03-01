// BEGIN CUT HERE
/*
SRM 730 Div2 Medium (500)

問題
-正の整数nとxが与えられる
-1からnまでのx個の異なる数を選ぶ
-x個の数の中の最小値をSとする
-2^Sの期待値を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class ExpectedMinimumPowerDiv2 {
public:
	double findExp(int n, int x) {
		static const int COMBSZ = 64;
		double C[COMBSZ][COMBSZ] = { 1 };
		for (int i = 1; i < COMBSZ; ++i) {
			C[i][0] = 1;
			for (int j = 1; j <= i; ++j) {
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			}
		}
		double cnt = 0, tot = 0;
		for (int i = 1; i <= n - x + 1; ++i) {
			cnt += C[n - i][x - 1];
			tot += C[n - i][x - 1] * pow(2, i);
		}
		return tot / cnt;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) {
		cerr << "Test Case #" << Case << "...";
		if (fabs(Expected - Received) <= 1e-9) cerr << "PASSED" << endl;
		else { cerr << "FAILED" << endl;
		cerr << "\tExpected: \"" << Expected << '\"' << endl;
		cerr << "\tReceived: \"" << Received << '\"' << endl;
		}
	}

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;
			double Arg2 = 2.0;

			verify_case(n, Arg2, findExp(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			double Arg2 = 2.6666666666666665;

			verify_case(n, Arg2, findExp(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 1;
			double Arg2 = 4.666666666666667;

			verify_case(n, Arg2, findExp(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 4;
			double Arg2 = 8.076190476190476;

			verify_case(n, Arg2, findExp(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			int Arg1 = 25;
			double Arg2 = 9.906688596554163;

			verify_case(n, Arg2, findExp(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			int Arg1 = 1;
			double Arg2 = 4.503599627370492E13;

			verify_case(n, Arg2, findExp(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ExpectedMinimumPowerDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
