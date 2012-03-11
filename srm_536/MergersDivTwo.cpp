// BEGIN CUT HERE
/*
// SRM 536 Div2 Hard (1000)

問題
いくつかの会社があり、それぞれの利益が配列で与えられる。
会社を合併すると、新会社の利益は、各社の利益の総和÷社数となる。
合併には少なくともk社必要で、最終的には1社になる。
最終的にできる会社の利益の最大値を求める。

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
#include <numeric>

using namespace std;

const double Min = -999999999;

class MergersDivTwo {
#if 1

public:
	double findMaximum(vector <int> revenues, int k) {
		sort(revenues.begin(), revenues.end());
		int n = revenues.size();
		int f[64] = {0};
		double Max[64];
		int i, j;
		f[0] = 1;
		Max[0] = revenues[0];
		for (i = 0; i <= n-k; ++i) {
			if (f[i]) {
				for (j = k; j < 2*k && i+j <= n; ++j) {
					double sum = Max[i];
					sum += accumulate(revenues.begin() + i + 1, revenues.begin() + i + j, 0);
					f[i+j-1] = 1;
					Max[i+j-1] = max(Max[i+j-1], sum/j);
				}
			}
		}
		return Max[n-1];
	}

#else

	int n;
	int k;
	double sum[64];
	double memo[64];

	double rec(int index, double d) {
		if (index == n) {
			return d;
		}
		double res = Min;
		if (d > memo[index]) {
			memo[index] = d;
			int i;
			for (i = index + k-1; i <= n; ++i) {
				res = max(res, rec(i, (d+sum[i]-sum[index])/(i-index+1)));
			}
		}
		return res;
	}

public:
	double findMaximum(vector <int> revenues, int _k) {
		sort(revenues.begin(), revenues.end());
		n = revenues.size();
		k = _k;
		int i;
		int _sum = 0;
		for (i = 0; i < n; ++i) {
			_sum += revenues[i];
			sum[i+1] = _sum;
		}
		for (i = 0; i < 64; ++i) {
			memo[i] = Min;
		}
		double res = Min;
		for (i = k; i <= n; ++i) {
			res = max(res, rec(i, sum[i]/i));
		}
		return res;
	}

#endif

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (fabs(Expected - Received)<1.0e-9) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, -7, 3};
			int Arg1 = 2;
			double Arg2 = 1.5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findMaximum(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, -7, 3};
			int Arg1 = 3;
			double Arg2 = 0.3333333333333333;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findMaximum(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 2, 3, -10, 7};
			int Arg1 = 3;
			double Arg2 = 2.9166666666666665;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findMaximum(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-100, -100, -100, -100, -100, 100};
			int Arg1 = 4;
			double Arg2 = -66.66666666666667;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findMaximum(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {869, 857, -938, -290, 79, -901, 32, -907, 256, -167, 510, -965, -826, 808, 890,
 -233, -881, 255, -709, 506, 334, -184, 726, -406, 204, -912, 325, -445, 440, -368};
			int Arg1 = 7;
			double Arg2 = 706.0369290573373;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findMaximum(Arg0, Arg1));
		}
		n++;


		//@@
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1000, -300, -97, 900, -94, -96, -99, -400, -400, -81, -86, 900, -1000, -600, 300, -89, 700, 1000, -82, -94, -93, -91, -300, -200, -91, 800, -84, 700, 0, -400};
			int Arg1 = 7;
			double Arg2 = 710.8573696145124;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findMaximum(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, -7, 3};
			int Arg1 = 3;
			double Arg2 = 0.3333333333333333;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findMaximum(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-981, -972, -963, -948, -946, -928, -927, -908, -902, -896, -895, -890, -882, -874, -874, -855, -826, -777, -770, -750, -728, -690, -621, -598, -575, -555, -497, -485, -481, -477, -463, -446, -402, -300, -296, -255, -236, -221, -203, -166, -143, -119, -113, -109, -85, -26, -26, -21, -9, 51};
			int Arg1 = 3;
			double Arg2 = -0.010811316695289008;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findMaximum(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MergersDivTwo ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
