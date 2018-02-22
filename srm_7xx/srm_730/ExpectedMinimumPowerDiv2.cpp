// BEGIN CUT HERE
/*
SRM 730 Div2 Medium (500)

PROBLEM STATEMENT

You are given two positive ints: n and x.

You are going to choose x distinct integers, each between 1 and n, inclusive.
The choice will be made uniformly at random.
That is, each of the possible x-element subsets of the integers 1 to n is equally likely to be chosen.

Let S be the smallest integer among the x chosen ones.
Compute and return the expected value of 2^S.
In other words, determine the average value of 2 to the power of S, where the average is taken over all possible choices of the x distinct integers.


DEFINITION
Class:ExpectedMinimumPowerDiv2
Method:findExp
Parameters:int, int
Returns:double
Method signature:double findExp(int n, int x)


NOTES
-Your answer will be accepted if the absolute or relative error is at most 1e-9.


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-x will be between 1 and n, inclusive.


EXAMPLES

0)
4
4

Returns: 2.0

The only possible situation is that you will choose (1, 2, 3, 4). In this case, the minimum is 1, and the expected value is 2^1 = 2. 


1)
3
2

Returns: 2.6666666666666665

There are three equally likely scenarios: you will select either {1,2} or {1,3} or {2,3}. The corresponding values of S are 1, 1, and 2, respectively. Thus, the average value of 2^S is (2^1 + 2^1 + 2^2) / 3 = 8 / 3 = 2.6666666


2)
3
1

Returns: 4.666666666666667


3)
10
4

Returns: 8.076190476190476


4)
50
25

Returns: 9.906688596554163


5)
50
1

Returns: 4.503599627370492E13

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class ExpectedMinimumPowerDiv2 {
public:
	double findExp(int n, int x) {
		static const int COMBSZ = 64;
		double C[COMBSZ][COMBSZ] = { 1 };
		for (int i = 1; i < COMBSZ; ++i) {
			C[i][0] = 1;
			for (int j = 1; j <= i; ++j) {
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			}
		}
		double cnt = 0, tot = 0;
		for (int i = 1; i <= n - x + 1; ++i) {
			cnt += C[n - i][x - 1];
			tot += C[n - i][x - 1] * pow(2, i);
		}
		return tot / cnt;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) {
		cerr << "Test Case #" << Case << "...";
		if (fabs(Expected - Received) <= 1e-9) cerr << "PASSED" << endl;
		else { cerr << "FAILED" << endl;
		cerr << "\tExpected: \"" << Expected << '\"' << endl;
		cerr << "\tReceived: \"" << Received << '\"' << endl;
		}
	}

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;
			double Arg2 = 2.0;

			verify_case(n, Arg2, findExp(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			double Arg2 = 2.6666666666666665;

			verify_case(n, Arg2, findExp(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 1;
			double Arg2 = 4.666666666666667;

			verify_case(n, Arg2, findExp(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 4;
			double Arg2 = 8.076190476190476;

			verify_case(n, Arg2, findExp(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			int Arg1 = 25;
			double Arg2 = 9.906688596554163;

			verify_case(n, Arg2, findExp(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			int Arg1 = 1;
			double Arg2 = 4.503599627370492E13;

			verify_case(n, Arg2, findExp(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ExpectedMinimumPowerDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
