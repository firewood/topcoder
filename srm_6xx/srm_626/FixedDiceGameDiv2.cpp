// BEGIN CUT HERE
/*
SRM 626 Div2 Medium (500)

問題
-Aliceがa面のダイス、Bobがb面のダイスを振る
-Aliceが勝つときの出目の期待値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class FixedDiceGameDiv2 {
public:
	double getExpectation(int a, int b) {
		double cnt = 0, sum = 0;
		for (int i = 2; i <= a; ++i) {
			for (int j = 1; j < i && j <= b; ++j) {
				cnt += 1;
				sum += i;
			}
		}
		return sum / cnt;
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
			int Arg0 = 2;
			int Arg1 = 2;
			double Arg2 = 2.0;

			verify_case(n, Arg2, getExpectation(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 2;
			double Arg2 = 3.2;

			verify_case(n, Arg2, getExpectation(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			double Arg2 = 2.6666666666666665;

			verify_case(n, Arg2, getExpectation(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 11;
			int Arg1 = 13;
			double Arg2 = 7.999999999999999;

			verify_case(n, Arg2, getExpectation(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FixedDiceGameDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
