// BEGIN CUT HERE
/*
// SRM 524 Div2 Easy (250)

問題

N個の立方体をa x b x cの形で隙間なく詰めたい。
a+b+cの最小値を求める。


#line 61 "ShippingCubes.cpp"
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
typedef map<int, int> IntMap;

class ShippingCubes {
public:
	int minimalCost(int N) {
		int result = N + 2;		// 1x1xN
		int i, j, k;
		for (i = 0; i <= N; ++i) {
			for (j = 0; j <= N; ++j) {
				for (k = 0; k <= N; ++k) {
					int x = i*j*k;
					if (x > N) {
						break;
					}
					if (x == N) {
						result = min(result, i+j+k);
					}
				}
			}
		}
		return result;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 3; verify_case(0, Arg1, minimalCost(Arg0)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 6; verify_case(1, Arg1, minimalCost(Arg0)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 9; verify_case(2, Arg1, minimalCost(Arg0)); }
	void test_case_3() { int Arg0 = 200; int Arg1 = 18; verify_case(3, Arg1, minimalCost(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ShippingCubes ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
