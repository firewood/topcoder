// BEGIN CUT HERE
/*
SRM 733 Div1 Easy (250)

PROBLEM STATEMENT

You are given a vector <int> x that contains exactly five positive integers.
You want to put four of them instead of the question marks into the following expression: | (?/?) - (?/?) |.
Which numbers should you put there and in what order, if your goal is to make the value of the expression as small as possible?

More formally, you have the following expression: | (xa / xb) - (xc / xd) |.
Here, "/" denotes real division (e.g., 7/2 = 3.5) and "||" denotes absolute value.
You want to find the four distinct subscripts a, b, c, d for which the value of the expression is minimized.

Return a vector <int> with four elements: the optimal subscripts {a, b, c, d}.
If there are multiple optimal answers, return the lexicographically smallest one among them.


DEFINITION
Class:MinimizeAbsoluteDifferenceDiv1
Method:findTuple
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> findTuple(vector <int> x)


NOTES
-Given two distinct arrays A and B with the same number of elements, we say that A is lexicographically smaller than B if A has a smaller value at the first index at which they differ.


CONSTRAINTS
-x will contain exactly five elements.
-Each element of x will be between 1 and 10,000, inclusive.


EXAMPLES

0)
{1,1,1,1,1}

Returns: {0, 1, 2, 3 }

Regardless of our choice of subscripts, the expression always evaluates to | (1/1) - (1/1) | = |1-1| = 0. The lexicographically smallest optimal solution is {0, 1, 2, 3}.


1)
{2,3,5,7,11}

Returns: {0, 3, 1, 4 }

Both {0, 3, 1, 4} ans {1, 4, 0, 3} would minimize the given expression, but {0, 3, 1, 4} comes lexicographically first, so that is the only correct answer.
The corresponding expression is |(2/7) - (3/11)| = 0.012987


2)
{8, 2, 4, 2, 6}

Returns: {1, 0, 3, 4 }

There are four sets of subscripts that minimize the given expression: {1, 0, 3, 4}, {1, 4, 3, 0}, {3, 0, 1, 4}, and {3, 4, 1, 0}.


3)
{124, 182, 9, 33, 70}

Returns: {2, 4, 3, 1 }


4)
{9947, 3, 7, 11, 13}

Returns: {1, 4, 3, 0 }


5)
{10000, 4, 10, 4, 10}

Returns: {1, 2, 3, 4 }

The smallest possible value of our expression is |(4/10) - (4/10)| = 0.

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

typedef long long LL;

class MinimizeAbsoluteDifferenceDiv1 {
public:
	vector <int> findTuple(vector <int> x) {
		vector<int> ans(4);
		vector<int> seq({ 0,1,2,3,4 });
		LL mv = -1, md = -1;
		double mn = 1e20;
		do {
#if 1
			LL tv = abs(x[seq[0]] * x[seq[3]] - x[seq[2]] * x[seq[1]]);
			LL td = x[seq[1]] * x[seq[3]];
			if (mv < 0 || tv * md < mv * td) {
				mv = tv, md = td;
				ans = seq;
			}
#else
			double t = fabs((double)x[seq[0]] / x[seq[1]] - (double)x[seq[2]] / x[seq[3]]);
			if ((t + 1e-10) < mn) {
				mn = t;
				ans = seq;
			}
#endif
		} while (next_permutation(seq.begin(), seq.end()));
		ans.resize(4);
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
			int Arr0[] = {1,1,1,1,1};
			int Arr1[] = {0, 1, 2, 3 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findTuple(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,3,5,7,11};
			int Arr1[] = {0, 3, 1, 4 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findTuple(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8, 2, 4, 2, 6};
			int Arr1[] = {1, 0, 3, 4 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findTuple(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {124, 182, 9, 33, 70};
			int Arr1[] = {2, 4, 3, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findTuple(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9947, 3, 7, 11, 13};
			int Arr1[] = {1, 4, 3, 0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findTuple(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10000, 4, 10, 4, 10};
			int Arr1[] = {1, 2, 3, 4 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findTuple(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 6702,4438,1209,9183,8680 };
			int Arr1[] = { 0,3,1,4 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findTuple(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MinimizeAbsoluteDifferenceDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
