// BEGIN CUT HERE
/*
SRM 728 Div2 Medium (500)

PROBLEM STATEMENT

You are given two vector <int>s L and R, each of length n.

Find the number of strictly increasing sequences of integers A[0] < A[1] < ... < A[n-1] such that L[i] ? A[i] ? R[i] for every i. Return this number modulo 998244353.


DEFINITION
Class:IncreasingSequencesEasy
Method:count
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int count(vector <int> L, vector <int> R)


NOTES
-The number 998244353 is a prime number.


CONSTRAINTS
-n will be between 1 and 300, inclusive.
-L will contain exactly n elements.
-R will contain exactly n elements.
-L[i] will be between 1 and 104, inclusive.
-R[i] will be between L[i] and 104, inclusive.


EXAMPLES

0)
{1, 3, 1, 4}
{6, 5, 4, 6}

Returns: 4

There are 4 strictly increasing sequences satisfying the conditions: {1, 3, 4, 5}, {1, 3, 4, 6}, {2, 3, 4, 5} and {2, 3, 4, 6}.


1)
{10, 20}
{20, 30}

Returns: 120


2)
{20, 10}
{30, 20}

Returns: 0


3)
{4, 46, 46, 35, 20, 77, 20}
{41, 65, 84, 90, 49, 86, 88}

Returns: 2470


4)
{1, 1, 1}
{10000, 10000, 10000}

Returns: 908107402

Don't forget about the modulo.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

static const int MOD = 998244353;

class IncreasingSequencesEasy {
public:
	int count(vector <int> L, vector <int> R) {
		int dp[2][10001];
		for (int i = 0; i <= 10000; ++i) {
			dp[0][i] = 1;
		}
		for (int i = 0; i < (int)L.size(); ++i) {
			int prev = i % 2, next = !prev;
			memset(dp + next, 0, sizeof(dp[0]));
			int sum = 0;
			for (int j = 0; j <= 10000; ++j) {
				if (j >= L[i] && j <= R[i]) {
					sum = (sum + dp[prev][j - 1]) % MOD;
				}
				dp[next][j] = sum;
			}
		}
		return dp[L.size() % 2][R.back()];
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
			int Arr0[] = {1, 3, 1, 4};
			int Arr1[] = {6, 5, 4, 6};
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 20};
			int Arr1[] = {20, 30};
			int Arg2 = 120;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {20, 10};
			int Arr1[] = {30, 20};
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 46, 46, 35, 20, 77, 20};
			int Arr1[] = {41, 65, 84, 90, 49, 86, 88};
			int Arg2 = 2470;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1};
			int Arr1[] = {10000, 10000, 10000};
			int Arg2 = 908107402;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	IncreasingSequencesEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
