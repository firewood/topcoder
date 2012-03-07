// BEGIN CUT HERE
/*
// SRM 536 Div1 Easy (250)

// PROBLEM STATEMENT
// Warning: This problem statement contains superscripts and/or subscripts.
It may not display properly outside of the applet.

The candy industry is going through a hard time in Byteland. Some of the
biggest companies in the business have decided to perform a series of mergers
so as to become one company in the end. Surprisingly, empirical studies
conducted by the economists of Byteland have shown that for any m >= 2
the revenue of a company that is created by simultainously merging m companies
with revenues equal to r0, r1, ..., rm - 1 is equal to the average of these
revenues, that is (r0 + r1 + ... + rm - 1) / m.


You are given a vector <int> revenues. The revenue of the i-th of the
companies that want to merge is equal to revenues[i]. Return the maximum
possible revenue of the final company that can be created in any series of
mergers that joins all the companies. In each of the mergers, we may merge
as many of the currently existing companies as we wish.

DEFINITION
Class:MergersDivOne
Method:findMaximum
Parameters:vector <int>
Returns:double
Method signature:double findMaximum(vector <int> revenues)


NOTES
-The returned value must have an absolute or relative error less than 10-9.
-Please note that the revenue of a company may be negative; this means that
 the company is actually losing money.
-It is always possible to merge all companies into a single one: for example,
 by merging all of them in a single step.


CONSTRAINTS
-revenues will contain between 2 and 50 elements, inclusive.
-Each element of revenues will be between -1,000 and 1,000, inclusive.


EXAMPLES


0)
{5, -7, 3}

Returns: 1.5

The optimal way is to first merge companies 1 and 2, obtaining a company with
total revenue -2, and then merge that company with company 0.


1)
{10, -17}

Returns: -3.5


2)
{12, 12, 12, 12, 12}

Returns: 12.0

We can just merge all the companies at once.


3)
{0, 0, 0, 0, 0, 100}

Returns: 50.0

We may first merge companies 0 through 4 and then merge the resulting company with company 5.


4)
{10, -10, 100, -100, 1000, -1000}

Returns: 491.25

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

class MergersDivOne {

public:
	double findMaximum(vector <int> revenues) {
		sort(revenues.begin(), revenues.end());
		double res = revenues[0];
		for (int i = 1; i < (int)revenues.size(); ++i) {
			res = (res + revenues[i]) / 2.0;
		}
		return res;
	}

	
// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, -7, 3};
			double Arg1 = 1.5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findMaximum(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, -17};
			double Arg1 = -3.5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findMaximum(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {12, 12, 12, 12, 12};
			double Arg1 = 12.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findMaximum(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0, 0, 0, 100};
			double Arg1 = 50.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findMaximum(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, -10, 100, -100, 1000, -1000};
			double Arg1 = 491.25;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findMaximum(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MergersDivOne ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
