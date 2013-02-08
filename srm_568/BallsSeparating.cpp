// BEGIN CUT HERE
/*
SRM 567 Div1 Easy (250)

PROBLEM STATEMENT
There are N boxes numbered from 0 to N-1, inclusive.
For each i, box i contains red[i] red balls, green[i] green balls, and blue[i] blue balls.

Fox Ciel wants to separate the balls by colors.
In each operation, she can pick a single ball from some box and put it into another box.
She considers the balls to be separated if no box contains balls of more than one color.

Return the minimal number of operations required to separate the balls. If this is impossible, return -1.


DEFINITION
Class:BallsSeparating
Method:minOperations
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int minOperations(vector <int> red, vector <int> green, vector <int> blue)


CONSTRAINTS
-red, green and blue will each contain between 1 and 50 elements, inclusive.
-red, green and blue will contain the same number of elements.
-Each element of red, green and blue will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
{1, 1, 1}
{1, 1, 1}
{1, 1, 1}

Returns: 6

One way to separate the balls in six operations is as follows:

Move a red ball from box 1 to box 0.
Move a red ball from box 2 to box 0.
Move a green ball from box 0 to box 1.
Move a green ball from box 2 to box 1.
Move a blue ball from box 0 to box 2.
Move a blue ball from box 1 to box 2.

The pictures on the left and on the right show the initial and the final states of the balls, respectively.


1)
{5}
{6}
{8}

Returns: -1

It is impossible to separate the balls.


2)
{4, 6, 5, 7}
{7, 4, 6, 3}
{6, 5, 3, 8}

Returns: 37


3)
{7, 12, 9, 9, 7}
{7, 10, 8, 8, 9}
{8, 9, 5, 6, 13}

Returns: 77


4)
{842398, 491273, 958925, 849859, 771363, 67803, 184892, 391907, 256150, 75799}
{268944, 342402, 894352, 228640, 903885, 908656, 414271, 292588, 852057, 889141}
{662939, 340220, 600081, 390298, 376707, 372199, 435097, 40266, 145590, 505103}

Returns: 7230607

*/
// END CUT HERE
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class BallsSeparating {
public:
	int minOperations(vector <int> red, vector <int> green, vector <int> blue) {
		int sz = (int)red.size();
		if (sz < 3) {
			return -1;
		}

		int m = accumulate(red.begin(), red.end(), 0);
		m += accumulate(green.begin(), green.end(), 0);
		m += accumulate(blue.begin(), blue.end(), 0);

		int ans = m;
		int i, j, k, l, n, o;
		for (i = 0; i < sz; ++i) {
			for (j = 0; j < sz; ++j) {
				for (k = 0; k < sz; ++k) {
					if (i == j || j == k || k == i) continue;
					n = m;
					for (l = 0; l < sz; ++l) {
						o = max(red[l], max(green[l], blue[l]));
						if (i==l) o = red[l];
						if (j==l) o = green[l];
						if (k==l) o = blue[l];
						n -= o;
					}
					ans = min(ans, n);
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
			int Arr0[] = {1, 1, 1};
			int Arr1[] = {1, 1, 1};
			int Arr2[] = {1, 1, 1};
			int Arg3 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minOperations(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5};
			int Arr1[] = {6};
			int Arr2[] = {8};
			int Arg3 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minOperations(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 6, 5, 7};
			int Arr1[] = {7, 4, 6, 3};
			int Arr2[] = {6, 5, 3, 8};
			int Arg3 = 37;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minOperations(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7, 12, 9, 9, 7};
			int Arr1[] = {7, 10, 8, 8, 9};
			int Arr2[] = {8, 9, 5, 6, 13};
			int Arg3 = 77;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minOperations(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {842398, 491273, 958925, 849859, 771363, 67803, 184892, 391907, 256150, 75799};
			int Arr1[] = {268944, 342402, 894352, 228640, 903885, 908656, 414271, 292588, 852057, 889141};
			int Arr2[] = {662939, 340220, 600081, 390298, 376707, 372199, 435097, 40266, 145590, 505103};
			int Arg3 = 7230607;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minOperations(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int Arr1[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int Arr2[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int Arg3 = 100;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minOperations(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1, 1};
			int Arr1[] = {1, 1, 1, 1};
			int Arr2[] = {5, 5, 5, 5};
			int Arg3 = 16;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minOperations(Arg0, Arg1, Arg2));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BallsSeparating ___test;
	___test.run_test(-1);
}
// END CUT HERE
