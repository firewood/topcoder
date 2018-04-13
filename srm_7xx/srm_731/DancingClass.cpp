// BEGIN CUT HERE
/*
SRM 731 Div2 Medium (500)

問題
-N人の生徒がいる
-男女一人ずつ、同じペアにならないようにK回選ぶことができるときを良い状態とする
-男女の生起確率が等しいとき、良い状態である確率を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class DancingClass {
	long double check(int n, int k) {
		static const int COMBSZ = 501;
		long double C[COMBSZ][COMBSZ] = { 1 };
		for (int i = 1; i < COMBSZ; ++i) {
			C[i][0] = 1;
			for (int j = 1; j <= i; ++j) {
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			}
		}

		long double tot = 0;
		long double base = pow(2, -n);
		for (int boys = 0; boys <= n; ++boys) {
			int girls = n - boys;
			if (boys * girls >= k) {
				tot += base * C[n][boys];
			}
		}
		return tot;
	}

public:
	string checkOdds(int n, int k) {
		long double res = check(n, k);
		if (fabs(res - 0.5) < 1e-9) {
			return "Equal";
		} else {
			return res < 0.5 ? "Low" : "High";
		}
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
			int Arg0 = 2;
			int Arg1 = 1;
			string Arg2 = "Equal";

			verify_case(n, Arg2, checkOdds(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			string Arg2 = "High";

			verify_case(n, Arg2, checkOdds(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;
			string Arg2 = "Low";

			verify_case(n, Arg2, checkOdds(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 500;
			int Arg1 = 500;
			string Arg2 = "High";

			verify_case(n, Arg2, checkOdds(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 40;
			int Arg1 = 397;
			string Arg2 = "Low";

			verify_case(n, Arg2, checkOdds(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			string Arg2 = "Low";

			verify_case(n, Arg2, checkOdds(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DancingClass ___test;
	___test.run_test(-1);
}
// END CUT HERE
