// BEGIN CUT HERE
/*
SRM 657 Div2 Medium (500)

問題
-SRM用の問題がある
-問題はEasy専用、EasyまたはMedium用、Medium専用、MediumまたはHard専用のいずれかである
-EasyとMediumとHardの一つずつをセットにするとき、最大何セット作れるかを求める

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

typedef long long LL;

class ProblemSetsEasy {

	bool possible(LL E, LL EM, LL M, LL MH, LL H, LL total) {
		LL a = min(E, min(M, H));
		E -= a, M -= a, H -= a, total -= a;
		EM -= max(0LL, total - E);
		if (EM < 0) {
			return false;
		}
		MH -= max(0LL, total - (EM + M));
		if (MH < 0) {
			return false;
		}
		return (MH + H) >= total;
	}

public:
	int maxSets(int E, int EM, int M, int MH, int H) {
		for (LL i = 1; ; ++i) {
			if (!possible(E, EM, M, MH, H, i)) {
				return i - 1;
			}
		}
		return -1;
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
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 1;
			int Arg3 = 2;
			int Arg4 = 2;
			int Arg5 = 3;

			verify_case(n, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 100;
			int Arg2 = 100;
			int Arg3 = 0;
			int Arg4 = 0;
			int Arg5 = 0;

			verify_case(n, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 657;
			int Arg1 = 657;
			int Arg2 = 657;
			int Arg3 = 657;
			int Arg4 = 657;
			int Arg5 = 1095;

			verify_case(n, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 2;
			int Arg2 = 3;
			int Arg3 = 4;
			int Arg4 = 5;
			int Arg5 = 3;

			verify_case(n, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100000;
			int Arg1 = 100000;
			int Arg2 = 100000;
			int Arg3 = 100000;
			int Arg4 = 100000;
			int Arg5 = 166666;

			verify_case(n, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ProblemSetsEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
