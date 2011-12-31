// BEGIN CUT HERE
/*
// SRM 528 Div2 Hard (1000)

問題

位置と速度が異なる蚊がN匹いる。
半径Rで炸裂する爆弾があるとき、殺せる蚊の最大匹数を求める。

*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
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

class Mosquitoes {

public:
	int getMaximum(vector <int> xInit, vector <int> v, int R) {
		const double e = 1.0e-9;
		int result = 1;
		int a, b, c;
		for (a = 0; a < (int)v.size(); ++a) {
			for (b = 0; b < (int)v.size(); ++b) {
				if (a == b) continue;
				double d = xInit[b] - xInit[a] - 2*R;
				double t = d / (v[a] - v[b]);
				if (t < 0) continue;
				double st = xInit[a] + v[a]*t -e;
				double ed = xInit[b] + v[b]*t +e;
				int cnt = 0;
				for (c = 0; c < (int)v.size(); ++c) {
					if (c == a || c == b) {
						++cnt;
					} else {
						double p = xInit[c] + v[c]*t;
						cnt += (st <= p && p <= ed);
					}
				}
				result = max(result, cnt);
			}
		}
		return result;
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
			int Arr0[] = {1, -1};
			int Arr1[] = {1, -1};
			int Arg2 = 10;
			int Arg3 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getMaximum(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100, -100};
			int Arr1[] = {1, -1};
			int Arg2 = 10;
			int Arg3 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getMaximum(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, -1, 10, -11, 99, -99};
			int Arr1[] = {1, -1, -3, 3, 47, -47};
			int Arg2 = 3;
			int Arg3 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getMaximum(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5};
			int Arr1[] = {2};
			int Arg2 = 8;
			int Arg3 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getMaximum(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {12,34,56,78,90};
			int Arr1[] = {-1,2,-3,4,-5};
			int Arg2 = 6;
			int Arg3 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getMaximum(Arg0, Arg1, Arg2));
		}
		n++;

		//@@
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100,97};
			int Arr1[] = {99,-100};
			int Arg2 = 1;
			int Arg3 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getMaximum(Arg0, Arg1, Arg2));
		}
		n++;
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Mosquitoes ___test;
	___test.run_test(5);
//	___test.run_test(-1);
	return 0;
}
// END CUT HERE
