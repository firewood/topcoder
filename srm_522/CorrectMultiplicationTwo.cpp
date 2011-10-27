// BEGIN CUT HERE
/*
// SRM 522 Div2 Hard (900)

問題

a * b = cという式があるが、正しくない。
値を加算または減算してA * B = Cに値を変更する。
|A - a| + |B - b| + |C - c|の最小値を求める。

#line 75 "CorrectMultiplicationTwo.cpp"
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

class CorrectMultiplicationTwo {

public:
	int getMinimum(int a, int b, int c) {
		int result = 2000000;
		int p = min(a, b);
		int q = max(a, b);
		int i, j;
		for (i = 1; i <= 1001; ++i) {
			for (j = 1; j <= b + c; ++j) {
				int x = i * j;
				if (x > 1000001) {
					break;
				}
				int r = abs(p-i)+abs(q-j)+abs(c-x);
				result = min(result, r);
			}
		}
		return result;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) {
		if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4();
//		test_case_5();
	}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 19; int Arg1 = 28; int Arg2 = 522; int Arg3 = 2; verify_case(0, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 30; int Arg2 = 500; int Arg3 = 11; verify_case(1, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 111; int Arg1 = 111; int Arg2 = 12321; int Arg3 = 0; verify_case(2, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 100; int Arg2 = 10; int Arg3 = 1089; verify_case(3, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 399; int Arg1 = 522; int Arg2 = 199999; int Arg3 = 24; verify_case(4, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1000000; int Arg1 = 1000000; int Arg2 = 1; int Arg3 = 1999998; verify_case(0, Arg3, getMinimum(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CorrectMultiplicationTwo ___test;
//	___test.run_test(2);
//	___test.run_test(3);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
