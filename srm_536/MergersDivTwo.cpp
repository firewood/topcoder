// BEGIN CUT HERE
/*
// SRM 536 Div2 Hard (1000)

// PROBLEM STATEMENT
// Warning: This problem statement contains superscripts and/or subscripts.
It may not display properly outside of the applet.

The candy industry is going through a hard time in Byteland. Some of the
biggest companies in the business have decided to perform a series of mergers
so as to become one company in the end. Due to the depression, each merger
should join at least k companies at once. Surprisingly, empirical studies
conducted by the economists of Byteland have shown that the revenue of
a company that is created by simultainously merging m (m >= k) companies
with revenues equal to r0, r1, ..., rm - 1 is equal to the average of these
revenues, that is (r0 + r1 + ... + rm - 1) / m.

You are given a vector <int> revenues. The revenue of the i-th of the companies
that want to merge is equal to revenues[i]. Return the maximum possible revenue
of the final company that can be created in any series of mergers that joins
all the companies.

DEFINITION
Class:MergersDivTwo
Method:findMaximum
Parameters:vector <int>, int
Returns:double
Method signature:double findMaximum(vector <int> revenues, int k)


NOTES
-The returned value must have an absolute or relative error less than 10-9.
-Please note that the revenue of a company may be negative; this means that
 the company is actually losing money.
-It is always possible to merge all companies into a single one: for example,
 by merging all of them in a single step.


CONSTRAINTS
-revenues will contain between 2 and 50 elements, inclusive.
-Each element of revenues will be between -1,000 and 1,000, inclusive.
-k will be between 2 and the number of elements in revenues, inclusive.


EXAMPLES

0)
{5, -7, 3}
2

Returns: 1.5

The optimal way is to first merge companies 1 and 2, obtaining a company
with total revenue -2, and then merge that company with company 0.


1)
{5, -7, 3}
3

Returns: 0.3333333333333333

The respective revenues are the same as in the previous example, but because
k = 3, we have to merge all companies at once.


2)
{1, 2, 2, 3, -10, 7}
3

Returns: 2.9166666666666665

The solution is to first merge companies 0, 1, 2 and 4, and then merge the
resulting company with companies 3 and 5.


3)
{-100, -100, -100, -100, -100, 100}
4

Returns: -66.66666666666667

Note that we can't merge less than six companies in the first step, because
otherwise we would be left with only two or three companies and we would be
unable to finish the merging process.


4)
{869, 857, -938, -290, 79, -901, 32, -907, 256, -167, 510, -965, -826, 808, 890,
 -233, -881, 255, -709, 506, 334, -184, 726, -406, 204, -912, 325, -445, 440, -368}
7

Returns: 706.0369290573373

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
