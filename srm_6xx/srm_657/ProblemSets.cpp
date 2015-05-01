// BEGIN CUT HERE
/*
SRM 657 Div1 Easy (250)

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

class ProblemSets {

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
	long long maxSets(long long E, long long EM, long long M, long long MH, long long H) {
		LL low = -1, high = 1LL << 62;
		while ((high - low) > 1) {
			LL mid = (low + high) / 2;
			if (!possible(E, EM, M, MH, H, mid)) {
				high = mid;
			} else {
				low = mid;
			}
		}
		return low;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 2LL;
			long long Arg1 = 2LL;
			long long Arg2 = 1LL;
			long long Arg3 = 2LL;
			long long Arg4 = 2LL;
			long long Arg5 = 3LL;

			verify_case(n, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 100LL;
			long long Arg1 = 100LL;
			long long Arg2 = 100LL;
			long long Arg3 = 0LL;
			long long Arg4 = 0LL;
			long long Arg5 = 0LL;

			verify_case(n, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 657LL;
			long long Arg1 = 657LL;
			long long Arg2 = 657LL;
			long long Arg3 = 657LL;
			long long Arg4 = 657LL;
			long long Arg5 = 1095LL;

			verify_case(n, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 2LL;
			long long Arg2 = 3LL;
			long long Arg3 = 4LL;
			long long Arg4 = 5LL;
			long long Arg5 = 3LL;

			verify_case(n, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1000000000000000000LL;
			long long Arg1 = 1000000000000000000LL;
			long long Arg2 = 1000000000000000000LL;
			long long Arg3 = 1000000000000000000LL;
			long long Arg4 = 1000000000000000000LL;
			long long Arg5 = 1666666666666666666LL;

			verify_case(n, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ProblemSets ___test;
	___test.run_test(-1);
}
// END CUT HERE
