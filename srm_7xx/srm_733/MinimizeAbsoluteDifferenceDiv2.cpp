// BEGIN CUT HERE
/*
SRM 733 Div2 Easy (250)

PROBLEM STATEMENT

You are given three positive integers: the ints x0, x1, and x2.
You have the following expression: |(?/?) - ?|.
You want to replace the three question marks with your three integers in some order.
In what order should you place the three integers if your goal is to make the result as small as possible?

More formally, you have an expression of the form | (xa / xb) - xc |.
Here, "/" denotes real division (e.g., 7/2  = 3.5), and "||" denotes absolute value.
Your task is to choose three distinct subscripts a, b, c so that the value of the expression is as small as possible.

Return a vector <int> with three elements: the optimal values {a, b, c}.
If there are multiple optimal answers, you may return any of them.


DEFINITION
Class:MinimizeAbsoluteDifferenceDiv2
Method:findTriple
Parameters:int, int, int
Returns:vector <int>
Method signature:vector <int> findTriple(int x0, int x1, int x2)


CONSTRAINTS
-x0 will be between 1 and 10,000, inclusive.
-x1 will be between 1 and 10,000, inclusive.
-x2 will be between 1 and 10,000, inclusive.


EXAMPLES

0)
1
1
1

Returns: {0, 1, 2 }

Regardless of our choice of subscripts, the expression is always evaluated to |(1/1) - 1| = 0.
Any of the six permutations of {0, 1, 2} is a correct answer.


1)
1
2
3

Returns: {1, 2, 0 }

The return value {1, 2, 0} corresponds to the expression |(x1 / x2) - x0| = |2/3 - 1| = 1/3 = 0.333333.
This is the only optimal choice of {a, b, c}, all other choices produce expressions with a larger value.


2)
7
20
5

Returns: {1, 0, 2 }

This set of subscripts produces an expression with the value 15/7.


3)
6
2
3

Returns: {0, 1, 2 }

There are two correct answers: {0, 1, 2} and {0, 2, 1}. You may return either of them.


4)
10
11
111

Returns: {2, 1, 0 }

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class MinimizeAbsoluteDifferenceDiv2 {
public:
	vector <int> findTriple(int x0, int x1, int x2) {
		double mn = 1e20;
		double x[3] = { (double)x0, (double)x1, (double)x2 };
		vector<int> ans;
		vector<int> seq { 0,1,2 };
		do {
			double t = fabs(x[seq[0]] / x[seq[1]] - x[seq[2]]);
			if (t + 1e-10 < mn) {
				mn = t;
				ans = seq;
			}
		} while (next_permutation(seq.begin(), seq.end()));
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
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arr3[] = {0, 1, 2 };

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, findTriple(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 2;
			int Arg2 = 3;
			int Arr3[] = {1, 2, 0 };

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, findTriple(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 20;
			int Arg2 = 5;
			int Arr3[] = {1, 0, 2 };

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, findTriple(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 2;
			int Arg2 = 3;
			int Arr3[] = {0, 1, 2 };

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, findTriple(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 11;
			int Arg2 = 111;
			int Arr3[] = {2, 1, 0 };

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, findTriple(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MinimizeAbsoluteDifferenceDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
