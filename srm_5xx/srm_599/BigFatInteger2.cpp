// BEGIN CUT HERE
/*
SRM 599 Div2 Medium (500)

問題
-整数A,B,C,Dが与えられる
-A^BがC^Dで割り切れるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class BigFatInteger2 {

	bool check(LL A, LL B, LL C, LL D) {
		for (LL i = 2; i < 32000; ++i) {
			LL x = 0, y = 0;
			while ((A % i) == 0) {
				++x;
				A /= i;
			}
			while ((C % i) == 0) {
				++y;
				C /= i;
			}
			if (y > 0 && x*B < y*D) {
				return false;
			}
		}
		if (C > 1) {
			return A == C && B >= D;
		}
		return true;
	}

public:
	string isDivisible(int A, int B, int C, int D) {
		return check(A, B, C, D) ? "divisible" : "not divisible";
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
			int Arg0 = 6;
			int Arg1 = 1;
			int Arg2 = 2;
			int Arg3 = 1;
			string Arg4 = "divisible";

			verify_case(n, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;
			int Arg2 = 6;
			int Arg3 = 1;
			string Arg4 = "not divisible";

			verify_case(n, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000000;
			int Arg1 = 1000000000;
			int Arg2 = 1000000000;
			int Arg3 = 200000000;
			string Arg4 = "divisible";

			verify_case(n, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arg1 = 100;
			int Arg2 = 4;
			int Arg3 = 200;
			string Arg4 = "not divisible";

			verify_case(n, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 999999937;
			int Arg1 = 1000000000;
			int Arg2 = 999999929;
			int Arg3 = 1;
			string Arg4 = "not divisible";

			verify_case(n, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 4;
			int Arg3 = 1;
			string Arg4 = "divisible";

			verify_case(n, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000000;
			int Arg1 = 1000000000;
			int Arg2 = 536870912;
			int Arg3 = 310344827;
			string Arg4 = "divisible";

			verify_case(n, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000000;
			int Arg1 = 1000000000;
			int Arg2 = 536870912;
			int Arg3 = 1000000000;
			string Arg4 = "not divisible";

			verify_case(n, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 999999986;
			int Arg1 = 1000000000;
			int Arg2 = 499999993;
			int Arg3 = 1000000000;
			string Arg4 = "divisible";

			verify_case(n, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BigFatInteger2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
