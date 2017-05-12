// BEGIN CUT HERE
/*
SRM 714 Div2 Easy (250)

PROBLEM STATEMENT

You are given a vector <int> arr that contains a set of positive integers.
The elements in arr are all distinct and they are given in increasing order.

A range is a finite set of consecutive integers.
Formally, for any two positive integers a ? b the range [a,b] is defined to be the set of all integers that lie between a and b, inclusive.
For example, [3,3] = {3} and [4,7] = {4,5,6,7}.

You want to represent the set given in arr as a union of some ranges.
Return the minimum number of ranges you need.


DEFINITION
Class:RangeEncoding
Method:minRanges
Parameters:vector <int>
Returns:int
Method signature:int minRanges(vector <int> arr)


CONSTRAINTS
-arr will have between 1 and 50 elements, inclusive.
-Each element of arr will be between 1 and 50.
-The elements in arr will be in strictly increasing order.


EXAMPLES

0)
{1,2,3,4,5,6,7,8,9,10}	

Returns: 1

We can represent this set as a single range [1,10]. 


1)
{1,6,10,20,32,49}

Returns: 6

In this case we have to use 6 different ranges, each containing just a single number.


2)
{2,4,5,6,8,9,10,11,12,15}

Returns: 4

This set of integers can be represented as the union of four ranges: [2,2], [4,6], [8,12], and [15,15].


3)
{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47}

Returns: 14


4)
{10,11,12,13,14,15,20,21,22,23,25,27,28,29,30,31,32,33}

Returns: 4


5)
{33}

Returns: 1

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class RangeEncoding {
public:
	int minRanges(vector <int> arr) {
		int ans = 0, next = -1;
		for (int a : arr) {
			if (a != next) {
				++ans;
			}
			next = a + 1;
		}
		return ans;
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
			int Arr0[] = {1,2,3,4,5,6,7,8,9,10}	;
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minRanges(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,6,10,20,32,49};
			int Arg1 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minRanges(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,4,5,6,8,9,10,11,12,15};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minRanges(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
			int Arg1 = 14;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minRanges(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,11,12,13,14,15,20,21,22,23,25,27,28,29,30,31,32,33};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minRanges(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {33};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minRanges(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RangeEncoding ___test;
	___test.run_test(-1);
}
// END CUT HERE
