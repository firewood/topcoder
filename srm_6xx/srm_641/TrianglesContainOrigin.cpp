// BEGIN CUT HERE
/*
SRM 641 Div1 Easy (250)

問題
-点の集合が与えられる
-一直線上に3点が並ぶことはない
-原点を内側に含む三角形が何個できるか求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

typedef long long LL;

class TrianglesContainOrigin {

public:
	long long count(vector <int> x, vector <int> y) {
		int N = (int)x.size();
		double rad[10000] = {};
		for (int i = 0; i < N; ++i) {
			rad[i] = atan2(x[i], y[i]);
			rad[i + N] = rad[i] + 2.0 * M_PI;
		}
		sort(rad, rad + N * 2);
		LL ans = 0;
		for (int i = 0; i < N; ++i) {
			size_t a = lower_bound(rad + i, rad + i + N, rad[i] + M_PI) - rad;
			for (int j = i + 1; j < N; ++j) {
				if (rad[j] - rad[i] < M_PI) {
					size_t b = lower_bound(rad + j, rad + i + N, rad[j] + M_PI) - rad;
					if (b > a) {
						ans += b - a;
					}
				}
			}
		}
		return ans / 2;
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
			int Arr0[] = {-1,-1,1};
			int Arr1[] = {1,-1,0};
			long long Arg2 = 1LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1,-1,1,2};
			int Arr1[] = {1,-1,2,-1};
			long long Arg2 = 2LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1,-2,3,3,2,1};
			int Arr1[] = {-2,-1,1,2,3,3};
			long long Arg2 = 8LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,5,10,5,-5,7,-9,-6,-3,0,8,8,1,-4,7,-3,10,9,-6};
			int Arr1[] = {5,-6,-3,4,-2,-8,-7,2,7,4,2,0,-4,-8,7,5,-5,-2,-9};
			long long Arg2 = 256LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TrianglesContainOrigin ___test;
	___test.run_test(-1);
}
// END CUT HERE
