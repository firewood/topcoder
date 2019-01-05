// BEGIN CUT HERE
/*
SRM 744 Div2 Easy (250)

PROBLEM STATEMENT

Ternary search is one of many algorithms in which we need to split a range of integers into three equal (or almost equal) parts.
That will be your task in this problem.

A half-open interval [x,y) is the set of integers that are greater than or equal to x and strictly less than y.
Hence, [x,y) = { x, x+1, x+2, ..., y-2, y-1 }.
For example, [3,7) = { 3, 4, 5, 6 }.

You are given two ints a and d. These define the half-open interval [a,d). This interval contains n = d-a numbers. Your task is to split this interval into three parts: [a,b), [b,c), and [c,d).
Each of these intervals must contain at least (n div 3) elements.

Return {b, c}. That is, return a vector <int> with two elements, the first of which is b and the second is c. If there are multiple valid solutions, you may return any one of them.


DEFINITION
Class:ThreePartSplit
Method:split
Parameters:int, int
Returns:vector <int>
Method signature:vector <int> split(int a, int d)


NOTES
-The formula "n div 3" means "n divided by 3, rounded down". For example, 14 div 3 = 4.


CONSTRAINTS
-a will be between 0 and 10^8, inclusive.
-d will be between a+3 and 10^8, inclusive.


EXAMPLES

0)
0
6

Returns: {2, 4 }

We are given the range [0,6) = {0,1,2,3,4,5}.
We need to split it into three parts, each containing at least (6 div 3) = 2 elements.
Clearly, the only valid solution is to split it into {0,1}, {2,3}, and {4,5}, that is, intervals [0,2), [2,4), and [4,6).
Thus, we must have b=2 and c=4, and we must return {2,4}.


1)
10
14

Returns: {11, 12 }

When splitting the interval [10,14) into three roughly equal parts, we have multiple valid options:

Split it into [10,11), [11,12), and [12,14).
Split it into [10,11), [11,13), and [13,14).
Split it into [10,12), [12,13), and [13,14).

Hence, there are three valid return values: {11, 12}, {11, 13}, and {12, 13}. Your solution may return any one of these three.


2)
127
345

Returns: {199, 271 }


3)
0
100000000

Returns: {33333333, 66666666 }


4)
100
105

Returns: {101, 104 }

As the original interval contains d-a = 5 elements, the requirement is that each of the three new intervals must contain at least one element. The return value of our solution corresponds to splitting the original interval into intervals of length 1, 3, and 1.

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

class ThreePartSplit {
public:
	vector <int> split(int a, int d) {
		int x = d - a, b = a + x / 3, c = b + x / 3;
		return { b, c };
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 6;
			int Arr2[] = {2, 4 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, split(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 14;
			int Arr2[] = {11, 12 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, split(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 127;
			int Arg1 = 345;
			int Arr2[] = {199, 271 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, split(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 100000000;
			int Arr2[] = {33333333, 66666666 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, split(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 105;
			int Arr2[] = {101, 104 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, split(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ThreePartSplit ___test;
	___test.run_test(-1);
}
// END CUT HERE
