// BEGIN CUT HERE
/*
SRM 745 Level 3 (500)

PROBLEM STATEMENT
All problems in this problem set are about "chains": collections of nested ranges of integers. All problems are independent, but use the same definitions. Each problem statement contains the definitions it needs. If a term appears in multiple problems, the definition is always identical.

Definitions follow. The defined term is always in uppercase.

An INTERVAL [x,y) with x <= y is the set of integers that are greater than or equal to x, and strictly less than y.

There is only one EMPTY INTERVAL but it has multiple equivalent notations. For example, [0,0) and [3,3) both denote the empty interval. Note that [3,0) is not a valid interval, because an interval [x,y) must have x <= y.

An interval I1 is called a PROPER SUBSET of an interval I2 if I2 contains all elements of I1 and at least one other element.

A CHAIN is a nonempty sequence of intervals such that each interval (except for the last one) is a proper subset of the next interval.

A CHAIN OF ORDER n is any chain such that the last interval in the chain is either the interval [0,n) or its proper subset.

You are given a sequence of valid intervals.
More precisely, you are given two vector <int>s: x and y.
It is guaranteed that for each valid i, [ x[i], y[i] ) is a valid interval.

If the given sequence of intervals is a chain. return R, where R is the smallest nonnegative integer such that the chain is a chain of order R.

If the given sequence of intervals is not a chain, return (-T), where T is the largest positive integer such that the first T-1 intervals of the input sequence still do form a valid chain.


DEFINITION
Class:Chains2
Method:validate
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int validate(vector <int> x, vector <int> y)


CONSTRAINTS
-n will be between 1 and 30, inclusive.
-Each of x and y will have exactly n elements.
-For each valid i, 0 <= x[i] <= y[i] < 2^30.


EXAMPLES

0)
{0, 0, 0}
{0, 1, 3}

Returns: 3


1)
{1, 4, 4}
{1, 7, 8}

Returns: 8

Note that the first interval in this chain is the empty interval. The empty interval is a proper subset of the interval [4,7) so everything is in order.


2)
{4, 4, 3}
{5, 7, 6}

Returns: -3

[4,5), [4,7) is a valid chain but [4,5), [4,7), [3,6) isn't.


3)
{4, 4}
{7, 7}

Returns: -2

Each interval must be a proper subset of the next one.


4)
{3}
{3}

Returns: 0

This valid chain consists of one interval. That interval happens to be the empty interval. Thus, this is a valid chain of order 0.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Chains2 {
	bool v(vector <int> x, vector <int> y, int z) {
		for (int i = 0; i < z; ++i) {
			if (x[i] == x[z] && y[i] == y[z]) {
				return false;
			}
			if (x[i] < x[z] || y[i] > y[z]) {
				return false;
			}
		}
		return true;
	}

public:
	int validate(vector <int> x, vector <int> y) {
		int cnt = 0;
		int n = (int)x.size();
		if (x[0] == y[0]) {
			if (n >= 2) {
				int p = min(x[1], y[1]);
				x[0] = p;
				y[0] = p;
			} else {
				x[0] = 0;
				y[0] = 0;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (!v(x, y, i)) {
				break;
			}
			cnt = i + 1;
		}
		return cnt == n ? y[n-1] : -(cnt + 1);
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
			int Arr0[] = {0, 0, 0};
			int Arr1[] = {0, 1, 3};
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, validate(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 4, 4};
			int Arr1[] = {1, 7, 8};
			int Arg2 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, validate(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 4, 3};
			int Arr1[] = {5, 7, 6};
			int Arg2 = -3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, validate(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 4};
			int Arr1[] = {7, 7};
			int Arg2 = -2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, validate(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3};
			int Arr1[] = {3};
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, validate(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Chains2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
