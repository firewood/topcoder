// BEGIN CUT HERE
/*
// SRM 524 Div2 Medium (500)

問題

距離nだけ移動したい。
素数の移動は不可。
1は素数ではない。
2より大きい合成数なら移動可能。
移動回数の最小値を求める。


#line 64 "MagicDiamonds.cpp"
*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

class MagicDiamonds {

public:
	long long minimalTransfer(long long n) {
		if (n <= 3) {
			return n;
		}
		if ((n % 2) == 0) {
			return 1;
		}
		LL x;
		for (x = 3; x*x <= n; x += 2) {
			if ((n % x) == 0) {
				return 1;
			}
		}
		return 2;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 2LL; verify_case(0, Arg1, minimalTransfer(Arg0)); }
	void test_case_1() { long long Arg0 = 4294967297LL; long long Arg1 = 1LL; verify_case(1, Arg1, minimalTransfer(Arg0)); }
	void test_case_2() { long long Arg0 = 2147483647LL; long long Arg1 = 2LL; verify_case(2, Arg1, minimalTransfer(Arg0)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 1LL; verify_case(3, Arg1, minimalTransfer(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicDiamonds ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
