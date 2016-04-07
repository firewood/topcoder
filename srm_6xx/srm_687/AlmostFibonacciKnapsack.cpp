// BEGIN CUT HERE
/*
SRM 687 Div1 Easy (250)

PROBLEM STATEMENT

You are given a sequence of integers.
This sequence is defined as follows:

A[1] = 2
A[2] = 3
for each n >= 3, A[n] = A[n-1] + A[n-2] - 1

You are given a long long x that is at least 2.
Your task is to write x as a sum of distinct elements of the above sequence.
More precisely, you have to find and return any valid vector <int> B with the following properties:

The elements of B are distinct positive integers.
x = A[B[0]] + A[B[1]] + ... + A[B[k-1]], where k is the number of elements in B.

If there are multiple solutions, return any of them.
If there are no solutions, return the vector <int> {-1} instead.


DEFINITION
Class:AlmostFibonacciKnapsack
Method:getIndices
Parameters:long long
Returns:vector <int>
Method signature:vector <int> getIndices(long long x)


CONSTRAINTS
-x will be between 2 and 10^18, inclusive.


EXAMPLES

0)
148

Returns: {6, 10, 8, 5 }

The first few terms of the sequence are 2,3,4,6,9,14,22,35,56,90.
We can see that 14+90+35+9=148, and their respective indices are 6,10,8,5.


1)
2

Returns: {1 }


2)
13

Returns: {2, 3, 4 }


3)
3

Returns: {2 }


4)
86267769395

Returns: {3, 14, 15, 9, 26, 53, 5, 8 }

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

class AlmostFibonacciKnapsack {
public:
	vector <int> getIndices(long long x) {
		LL a[100] = { 2, 2, 3 };
		for (int i = 3; i < 87; ++i) {
			a[i] = a[i - 1] + a[i - 2] - 1;
		}
		vector <int> ans;
		for (int i = 86; i >= 1; --i) {
			if (x >= a[i] && x != a[i] + 1) {
				x -= a[i];
				ans.push_back(i);
			}
		}
		return ans;
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
			long long Arg0 = 148LL;
			int Arr1[] = {6, 10, 8, 5 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getIndices(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 2LL;
			int Arr1[] = {1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getIndices(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 13LL;
			int Arr1[] = {2, 3, 4 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getIndices(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 3LL;
			int Arr1[] = {2 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getIndices(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 86267769395LL;
			int Arr1[] = {3, 14, 15, 9, 26, 53, 5, 8 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getIndices(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AlmostFibonacciKnapsack ___test;
	___test.run_test(-1);
}
// END CUT HERE
