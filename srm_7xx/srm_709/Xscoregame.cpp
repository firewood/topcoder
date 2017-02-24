// BEGIN CUT HERE
/*
SRM 709 Div1 Easy (250)

PROBLEM STATEMENT
You have an array of integers: the vector <int> A.

When you give the array to Hero, he will execute the following steps:

At the beginning, he will set the variable X to zero.
For each element Y of A, in the given order, he will set X to (X + (X xor Y)).
He will announce the final value of the variable X.


Before you give the array A to Hero, you are allowed to permute its elements arbitrarily.
Compute and return the largest possible value that can be announced by Hero.

DEFINITION
Class:Xscoregame
Method:getscore
Parameters:vector <int>
Returns:int
Method signature:int getscore(vector <int> A)


CONSTRAINTS
-A will contain between 1 and 15 elements, inclusive.
-Each element in A will be between 0 and 50, inclusive.


EXAMPLES

0)
{1,2,3}

Returns: 12

An optimal solution is to rearrange A into the order {3, 1, 2}.
Given this array, Hero will perform the following steps:

He will set X to zero.
Then, he will set X to (0 + (0 xor 3)) = 3.
Then, he will set X to (3 + (3 xor 1)) = 5.
Finally, he will set X to (5 + (5 xor 2)) = 12, and he will announce the value 12.


1)
{10,0,0,0}

Returns: 80

Here an optimal solution is to leave the array in the original order.
The variable X will have the values 0, 10, 20, 40, and finally 80.

2)
{1,1,1,1,1,1}

Returns: 1



3)
{1,0,1,0,1,0,1,0}

Returns: 170



4)
{50,0,1,0,1,0,1,0,1,0,1,0,1,0,1}

Returns: 830122

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

class Xscoregame {
public:
	int getscore(vector <int> A) {
		int ans = 0, N = (int)A.size(), bm = 1 << N, dp[32768][64];
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for (int i = 0; i < bm; ++i) {
			for (int j = 0; j < 64; ++j) {
				if (dp[i][j] >= 0) {
					for (int k = 0; k < N; ++k) {
						if (!(i & (1 << k))) {
							int x = dp[i][j] + (dp[i][j] ^ A[k]);
							int &next = dp[i | (1 << k)][x & 63];
							next = max(next, x);
							ans = max(ans, next);
						}
					}
				}
			}
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
			int Arr0[] = {1,2,3};
			int Arg1 = 12;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getscore(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,0,0,0};
			int Arg1 = 80;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getscore(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1,1};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getscore(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,0,1,0,1,0,1,0};
			int Arg1 = 170;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getscore(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {50,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
			int Arg1 = 830122;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getscore(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 27,23,47,12,36,40,11,36,5,17 };
			int Arg1 = 32233;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getscore(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 12,14,5 };
			int Arg1 = 48;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getscore(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 2,5,8,41 };
			int Arg1 = 357;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getscore(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Xscoregame ___test;
	___test.run_test(-1);
}
// END CUT HERE
