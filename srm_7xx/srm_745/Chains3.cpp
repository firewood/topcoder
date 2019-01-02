// BEGIN CUT HERE
/*
SRM 745 Level 4 (600)

PROBLEM STATEMENT
All problems in this problem set are about "chains": collections of nested ranges of integers. All problems are independent, but use the same definitions. Each problem statement contains the definitions it needs. If a term appears in multiple problems, the definition is always identical.

Definitions follow. The defined term is always in uppercase.

An INTERVAL [x,y) with x <= y is the set of integers that are greater than or equal to x, and strictly less than y.

There is only one EMPTY INTERVAL but it has multiple equivalent notations. For example, [0,0) and [3,3) both denote the empty interval. Note that [3,0) is not a valid interval, because an interval [x,y) must have x <= y.

An interval I1 is called a PROPER SUBSET of an interval I2 if I2 contains all elements of I1 and at least one other element.

A CHAIN is a nonempty sequence of intervals such that each interval (except for the last one) is a proper subset of the next interval.

A CHAIN OF ORDER n is any chain such that the last interval in the chain is either the interval [0,n) or its proper subset.

The LENGTH OF A CHAIN is the number of intervals that form it. (I.e., a chain is a sequence of objects, and when we talk about its length, we mean the length of that sequence.)

A MAXIMAL CHAIN OF ORDER n is any chain such that no other chain of order n has a greater length.

Given a chain { I0, I1, ..., Im }, its  CHARACTERISTIC SEQUENCE is any sequence of integers c0, ..., cm-1 such that for all i, ci belongs into Ii+1 but not into Ii.


You are given a nonempty vector <int> c.
Do the following:

If c is a valid characteristic sequence of some maximal chain of order C, return "maximal C".
Note that the correct C is always unique.
If c is a valid characteristic sequence of some chain but not of any maximal chain, return "valid B".
Here, B should be the smallest integer such that after examining the first B elements of c
we can be certain that it isn't the characteristic sequence of any maximal chain.
If c is not a valid characteristic sequence of any chain, return "invalid A", where A is the
smallest integer such that after examining the first A elements of c we can be certain that
it's not a valid characteristic sequence at all.


DEFINITION
Class:Chains3
Method:validate
Parameters:vector <int>
Returns:string
Method signature:string validate(vector <int> c)


CONSTRAINTS
-c will contain between 1 and 50 elements, inclusive.
-Each element of c will be between 0 and 2^30 - 1, inclusive.


EXAMPLES

0)
{1, 0}

Returns: "maximal 2"


1)
{4, 5, 6, 2, 1, 9, 0}

Returns: "valid 4"

The given c is, for example, the characteristic sequence of the following chain: [3,4), [3,5), [3,6), [3,7), [2,7), [1,9), [1,16), [0,24).

Already after seeing {4, 5, 6, 2} we can be sure that there is no maximal chain such that c is its characteristic sequence.


2)
{4, 5, 6, 2, 1, 3, 0}

Returns: "invalid 6"


3)
{4, 5, 4, 2, 1, 3, 0}

Returns: "invalid 3"

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Chains3 {
public:
	string validate(vector <int> c) {
		int n = (int)c.size(), m = c[0] < n ? n : 0;
		int left = c[0], right = c[0];
		for (int i = 1; i < n; ++i) {
			if (c[i] >= left && c[i] <= right) {
				return string("invalid ") + to_string(i + 1);
			}
			if (c[i] < left) {
				if (c[i] < left - 1) {
					m = min(m, i);
				}
				left = c[i];
			} else {
				if (c[i] > min(n - 1, right + 1)) {
					m = min(m, i);
				}
				right = c[i];
			}
		}
		if (m == n && right == n - 1) {
			return string("maximal ") + to_string(n);
		} else {
			return string("valid ") + to_string(min(m + 1, n));
		}
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 0};
			string Arg1 = "maximal 2";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, validate(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 5, 6, 2, 1, 9, 0};
			string Arg1 = "valid 4";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, validate(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 5, 6, 2, 1, 3, 0};
			string Arg1 = "invalid 6";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, validate(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 5, 4, 2, 1, 3, 0};
			string Arg1 = "invalid 3";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, validate(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 7 };
			string Arg1 = "valid 1";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, validate(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 0,2 };
				string Arg1 = "valid 2";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, validate(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 1,2 };
			string Arg1 = "valid 2";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, validate(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 2,0 };
			string Arg1 = "valid 1";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, validate(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Chains3 ___test;
	___test.run_test(-1);
}
// END CUT HERE
