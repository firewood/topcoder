// BEGIN CUT HERE
/*
SRM 765 Div1 Easy (300)

PROBLEM STATEMENT

You are given the vector <int> A with N elements.
Your task is to sort it into the usual non-decreasing order.

The only way in which you can modify A is by reversing some segments of A.
In each step you can specify indices i, j such that 0 <= i < j <= N, and reverse the segment A[i:j] = { A[i], ..., A[j-1] }.

There is one extra restriction: The operations must never change the value of the element at index fixed.

If there is no way to sort A, return {-1}.
Otherwise, find any solution with at most 75 reversals and return a vector <int> of the form { i1, j1, i2, j2, ... } that describes the sequence of reversals you wish to perform.


DEFINITION
Class:FixedPointReversals
Method:sort
Parameters:vector <int>, int
Returns:vector <int>
Method signature:vector <int> sort(vector <int> A, int fixed)


NOTES
-You are not required to minimize the number of reversals.
-For the given constraints, whenever a solution exists, a solution with at most 75 reversals exists.


CONSTRAINTS
-A will have between 1 and 50 elements, inclusive.
-Each element of A will be between 1 and 50, inclusive.
-fixed will be between 0 and length(A)-1, inclusiive.


EXAMPLES

0)
{10, 20, 30, 40, 50}
2

Returns: { }

The array is already sorted.


1)
{10, 20, 40, 30, 50}
2

Returns: {-1 }

There is no way to sort this array and satisfy the requirement that after each operation A[2] must remain 40.


2)
{20, 10, 10, 10, 10, 10}
4

Returns: {0, 6 }

We can reverse the entire array. Note that after that operation A[4] is still equal to 10, so this is allowed.


3)
{1, 50, 40, 30, 20, 10}
0

Returns: {1, 6 }


4)
{20, 10, 30, 50, 40}
2

Returns: {0, 2, 3, 5 }

*/
// END CUT HERE

#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>

using namespace std;

typedef pair<int, int> II;

class FixedPointReversals {
public:
vector <int> sort(vector <int> A, int fixed) {
    vector<int> a, ans;
    a = A;
    std::sort(a.begin(), a.end());
    if (A[fixed] == a[fixed]) {
        int n = a.size();
        vector<II> v;
        vector<int> w(n);
        for (int i = 0; i < n; ++i) {
            v.push_back(II(A[i], i));
        }
        std::sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i) {
            w[v[i].second] = i;
        }
        if (w[fixed] != fixed) {
            int pos = std::find(w.begin(), w.end(), fixed) - w.begin();
            swap(w[pos], w[fixed]);
        }
        int rcnt = 0;
        for (int i = fixed - 1; i >= 0; --i) {
            if (w[i] < fixed) {
                for (int j = 0; j < i; ++j) {
                    if (w[j] > fixed) {
                        ans.push_back(j);
                        ans.push_back(i + 1);
                        std::reverse(w.begin() + j, w.begin() + i + 1);
                        break;
                    }
                }
            }
            if (w[i] > fixed) {
                ++rcnt;
            }
        }
        for (int i = fixed + 1; i < n; ++i) {
            if (w[i] > fixed) {
                for (int j = n - 1; j > i; --j) {
                    if (w[j] < fixed) {
                        ans.push_back(i);
                        ans.push_back(j + 1);
                        std::reverse(w.begin() + i, w.begin() + j + 1);
                        break;
                    }
                }
            }
        }
        if (rcnt) {
            ans.push_back(fixed - rcnt);
            ans.push_back(fixed + rcnt + 1);
            std::reverse(w.begin() + fixed - rcnt, w.begin() + fixed + rcnt + 1);
        }
        for (int i = fixed - 1; i >= 0; --i) {
            int pos = std::find(w.begin(), w.end(), i) - w.begin();
            assert(pos >= 0 && pos < fixed);
            if (i != pos) {
                ans.push_back(pos);
                ans.push_back(i + 1);
                std::reverse(w.begin() + pos, w.begin() + i + 1);
            }
        }
        for (int i = fixed + 1; i < n; ++i) {
            int pos = std::find(w.begin(), w.end(), i) - w.begin();
            assert(pos > fixed && pos < n);
            if (i != pos) {
                ans.push_back(i);
                ans.push_back(pos + 1);
                std::reverse(w.begin() + i, w.begin() + pos + 1);
            }
        }
    } else {
        ans = {-1};
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
			int Arr0[] = {10, 20, 30, 40, 50};
			int Arg1 = 2;
			int Arr2[] = { };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, sort(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 20, 40, 30, 50};
			int Arg1 = 2;
			int Arr2[] = {-1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, sort(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {20, 10, 10, 10, 10, 10};
			int Arg1 = 4;
			int Arr2[] = {0, 6 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, sort(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 50, 40, 30, 20, 10};
			int Arg1 = 0;
			int Arr2[] = {1, 6 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, sort(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {20, 10, 30, 50, 40};
			int Arg1 = 2;
			int Arr2[] = {0, 2, 3, 5 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, sort(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  FixedPointReversals ___test;
  ___test.run_test(-1);
}
// END CUT HERE
