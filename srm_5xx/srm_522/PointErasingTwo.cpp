// BEGIN CUT HERE
/*
// SRM 522 Div2 Easy (250)

問題

y座標の配列が与えられる。
2点間を選んだとき、その内部に含まれる最大の個数を求める。

#line 71 "PointErasingTwo.cpp"
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

class PointErasingTwo {

public:
	int getMaximum(vector <int> y) {
		int result = 0;
		int i, j, k;
		for (i = 0; i < (int)(y.size() - 1); ++i) {
			for (j = i + 1; j < (int)y.size(); ++j) {
				int c = 0;
				int sy = min(y[i], y[j]);
				int ey = max(y[i], y[j]);
				for (k = i + 1; k < j; ++k) {
					c += (sy < y[k] && y[k] < ey);
				}
				result = max(result, c);
			}
		}
		return result;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 2, 1, 1, 0, 4, 3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getMaximum(Arg0)); }
	void test_case_1() { int Arr0[] = { 0, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getMaximum(Arg0)); }
	void test_case_2() { int Arr0[] = { 0, 1, 2, 3, 4 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, getMaximum(Arg0)); }
	void test_case_3() { int Arr0[] = { 10, 19, 10, 19 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, getMaximum(Arg0)); }
	void test_case_4() { int Arr0[] = { 0, 23, 49, 50, 32, 0, 18, 50, 0, 28, 50, 27, 49, 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, getMaximum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PointErasingTwo ___test;
	___test.run_test(0);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
