// BEGIN CUT HERE
/*
// SRM 521 Div2 Hard (1000)

問題

XY平面上に点集合Pがある。
整数nが与えられる。
大きさnの正方形に収まるPの空でない部分集合がいくつあるかを答える。

#line 75 "SquaredSubsets.cpp"
*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;
typedef set<LL> LLSet;
typedef set<int> IntSet;

#define SizeOfArray(a) (sizeof(a)/sizeof(a[0]))

class SquaredSubsets {

#if 1
public:
	long long countSubsets(int n, vector <int> x, vector <int> y) {
		n *= 2;
		int i, j, k;
		const int offsets[] = {-n-1,-n,-1,0,1};
		for (i = 0; i < (int)x.size(); ++i) {
			x[i] *= 2;
			y[i] *= 2;
		}
		IntSet _x(x.begin(), x.end());
		IntSet _y(y.begin(), y.end());
		LLSet memo;
		IntSet::const_iterator h, v;
		for (h = _x.begin(); h != _x.end(); ++h) {
			for (i = 0; i < SizeOfArray(offsets); ++i) {
				int a = *h + offsets[i];
				for (v = _y.begin(); v != _y.end(); ++v) {
					for (j = 0; j < SizeOfArray(offsets); ++j) {
						int b = *v + offsets[j];
						LL l = 0;
						for (k = 0; k < (int)x.size(); ++k) {
							if (a <= x[k] && x[k] <= (a + n) && b <= y[k] && y[k] <= (b + n)) {
								l |= (1LL << k);
							}
						}
						if (l) {
							memo.insert(l);
						}
					}
				}
			}
		}

		return memo.size();
	}
#endif

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {-5,0,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5LL; verify_case(0, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {-5,0,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5LL; verify_case(1, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 100000000; int Arr1[] = {-1,-1,-1,0,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-1,0,1,1,-1,0,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 21LL; verify_case(2, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arr1[] = {5,3,6,2,1,6,4,4,7,-1,-4,-7,2,-2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,-1,8,-5,2,5,-8,8,-6,4,3,2,7,3,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 66LL; verify_case(3, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arr1[] = {-1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 3LL; verify_case(4, Arg3, countSubsets(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SquaredSubsets ___test;
//	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(3);
//	___test.run_test(4);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
