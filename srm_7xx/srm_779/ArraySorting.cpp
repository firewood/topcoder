// BEGIN CUT HERE
/*
SRM 779 Div1 Easy (250)

PROBLEM STATEMENT

You are given the vector <int> A.
All elements of A are positive integers not exceeding 1000.

You can perform several operations on this array.
In each operation you can take any element of A and replace it by any new value from the range [1,1000].

Using as few such operations as possible, convert A into an array that is sorted in non-decreasing order.
Return the sorted array you produced.
If there are multiple correct answers, return the lexicographically smallest one among them.


DEFINITION
Class:ArraySorting
Method:arraySort
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> arraySort(vector <int> A)


NOTES
-Given two distinct arrays with the same number of elements, the lexicographically smaller one is the one that has a smaller value at the first index at which they differ.


CONSTRAINTS
-A will contain between 1 and 2000 elements,
-Each element of A will be between 1 and 2000, inclusive.


EXAMPLES

0)
{ 10, 8 }

Returns: {1, 8 }

The sequence is not sorted, so we need to make at least one change. There are multiple ways how to make it sorted in exactly one change. For example, we could produce {3, 8}, {10, 10}, or {10, 470}. The lexicographically smallest sorted sequence that can be produced in one step is obtained by changing the 10 to a 1.


1)
{ 6, 9 }

Returns: {6, 9 }

This sequence is already sorted, so no changes are needed.


2)
{ 9, 8, 10, 4 }

Returns: {1, 8, 10, 10 }

The minimum number of changes is two. The optimal way to perform the two changes is to replace the 9 by a 1 and to replace the 4 by a 10.


3)
{ 3, 7, 7, 7, 6 }

Returns: {3, 7, 7, 7, 7 }

In this case, the input sequence can be turned into a non-decreasing sequence in a single operation: by changing the last element to a 7 (or something bigger).

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

using namespace std;

class ArraySorting {
public:
	vector <int> arraySort(vector <int> A) {
		const int INF = 1 << 30;
		int n = (int)A.size();
		vector<vector<int>> dp(n + 1, vector<int>(2001, INF));
		dp[n][2000] = 0;
		for (int i = n - 1; i >= 0; --i) {
			int m = INF;
			for (int j = 2000; j >= 1; --j) {
				m = min(m, dp[i + 1][j]);
				dp[i][j] = m + (j != A[i]);
			}
		}
		vector<int> ans = A;
		int prev = 1;
		for (int i = 0; i < n; ++i) {
			ans[i] = (int)(min_element(dp[i].begin() + prev, dp[i].end()) - dp[i].begin());
			prev = ans[i];
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
			int Arr0[] = { 10, 8 };
			int Arr1[] = {1, 8 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, arraySort(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 6, 9 };
			int Arr1[] = {6, 9 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, arraySort(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 9, 8, 10, 4 };
			int Arr1[] = {1, 8, 10, 10 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, arraySort(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 3, 7, 7, 7, 6 };
			int Arr1[] = {3, 7, 7, 7, 7 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, arraySort(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 5, 4, 3, 2, 1 };
			int Arr1[] = { 1, 1, 1, 1, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, arraySort(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 5, 4, 3, 4, 5 };
			int Arr1[] = { 1, 1, 3, 4, 5 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, arraySort(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ArraySorting ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
