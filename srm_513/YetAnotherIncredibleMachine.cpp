// BEGIN CUT HERE
/*
// SRM 513 Div2 Medium (500)

問題

「The Incredible Machine」という、ボールが落ちてくるゲームがある。
水平にN本の土台が取り付けられている。
それぞれの長さは platformLength[i] で座標は (platformMount[i], i + 1) である。
土台は、取り付けられた位置から、長さのぶんだけ水平に動かすことができる。
左端の最大位置は (platformMount[i] - platformLength[i], i + 1) であり
右端の最大位置は (platformMount[i] + platformLength[i], i + 1) である。
土台の移動はボールを落とす前だけ可能である。
いくつかのボールを同時に垂直に落とす。
ボールの座標は配列 balls[i] である。ボールは非常に小さいので点で扱ってよい。
全てのボールが落ちる配置が何通りあるか(mod 1000000009)を求める。


#line 82 "YetAnotherIncredibleMachine.cpp"
*/
// END CUT HERE
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
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

class YetAnotherIncredibleMachine {

public:
	int countWays(vector <int> platformMount, vector <int> platformLength, vector <int> balls) {
		LL result = 1;
		int i, j, k;
		for (i = 0; i < (int)platformMount.size(); ++i) {
			int s = platformMount[i];
			int len = platformLength[i];
			LL c = 0;
			for (j = 0; j <= len; ++j, --s) {
				int v = 1;
				int e = s + len;
				for (k = 0; k < (int)balls.size(); ++k) {
					int b = balls[k];
					if (b >= s && b <= e) {
						v = 0;
						break;
					}
				}
				c += v;
			}
			result = (result * c) % 1000000009;
			if (c == 0) {
				break;
			}
		}
		return (int)result;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,9,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 27; verify_case(2, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(3, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {100, -4215, 251}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {400, 10000, 2121}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5000, 2270, 8512, 6122}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 250379170; verify_case(4, Arg3, countWays(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	YetAnotherIncredibleMachine ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
