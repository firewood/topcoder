// BEGIN CUT HERE
/*
SRM 596 Div2 Hard (1000)

問題
-F(n) = (n - 0^2) * (n - 1^2) * (n - 2^2) * (n - 3^2) * ... * (n - k^2) とする
-素数の除数Pが与えられる
-lo以上hi以下のnについて、Pで割り切れるF(n)の個数を求める

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

class SparseFactorialDiv2 {
	LL calc(LL n, LL divisor) {
		LL cnt = 0;
		int f[1000] = {};
		for (LL x = 0; ; ++x) {
			LL sq = x*x;
			LL z = n - sq;
			if (z <= 0) {
				break;
			}
			LL r = sq % divisor;
			if (f[r]) {
				continue;
			}
			f[r] = 1;
			cnt += z / divisor;
		}
		return cnt;
	}

public:
	long long getCount(long long lo, long long hi, long long divisor) {
		return calc(hi, divisor) - calc(lo-1, divisor);
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
			long long Arg0 = 4LL;
			long long Arg1 = 8LL;
			long long Arg2 = 3LL;
			long long Arg3 = 3LL;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 9LL;
			long long Arg1 = 11LL;
			long long Arg2 = 7LL;
			long long Arg3 = 1LL;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 1000000000000LL;
			long long Arg2 = 2LL;
			long long Arg3 = 999999999999LL;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 16LL;
			long long Arg1 = 26LL;
			long long Arg2 = 11LL;
			long long Arg3 = 4LL;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 10000LL;
			long long Arg1 = 20000LL;
			long long Arg2 = 997LL;
			long long Arg3 = 1211LL;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 123456789LL;
			long long Arg1 = 987654321LL;
			long long Arg2 = 71LL;
			long long Arg3 = 438184668LL;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 2LL;
			long long Arg2 = 2LL;
			long long Arg3 = 1LL;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 2LL;
			long long Arg2 = 3LL;
			long long Arg3 = 0LL;

			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SparseFactorialDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
