// BEGIN CUT HERE
/*
TCO 2015 Round 2B Easy (250)

PROBLEM STATEMENT
In this problem we are dealing with a string of N bits, numbered from 0 to N-1.
Julia likes the string that consists of N zeros.
If you give her any N-bit string, she will convert it into a string of N zeros using the smallest possible number of actions.
An action consists of selecting an integer k (1 <= k <= N) and flipping either the first k bits or the last k bits of the string.
Formally, Julia can flip either all bits with number i such that i < k or all bits with number i such that i >= N - k.

You are going to generate a random string of N bits.
You are given a vector <int> p with N elements.
For each i, bit number i has a p[i] percent chance of being a 1 and a (100 - p[i]) percent chance of being a 0.
The values of the bits are chosen independently from each other.

After you generate the string, you are going to give it to Julia.
Please find and return the expected number of actions Julia will take.

DEFINITION
Class:Bitwisdom
Method:expectedActions
Parameters:vector <int>
Returns:double
Method signature:double expectedActions(vector <int> p)


NOTES
-When a bit is flipped, its value changes. If the bit is originally 1, it will become 0. If it is originally 0, it will become 1.
-Your answer must have an absoute or relative error not exceeding 10^(-9).


CONSTRAINTS
-N will be between 1 and 300, inclusive.
-p will contain exactly N elements.
-Each element of p will be between 0 and 100, inclusive.


EXAMPLES

0)
{100, 100, 100}

Returns: 1.0

All of the bits are guaranteed to be 1, and Julia can set them all to 0 in a single action.


1)
{50, 50}

Returns: 0.75

There is a 25% chance that all of the bits are 0, in which case Julia will do nothing. All other configurations allow Julia to clear the field in 1 action, so the answer is 0.75 * 1 = 0.75.


2)
{0, 40, 50, 60}

Returns: 1.4


3)
{37, 63, 23, 94, 12}

Returns: 2.6820475464

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Bitwisdom {

public:
	double expectedActions(vector <int> p) {
		double dp[2][2][304];
		int N = (int)p.size();

		double ans = 1.0;
		for (int i = 0; i < N; ++i) {
			int prev = i & 1;
			int next = prev ^ 1;
			double a = (100 - p[i]) * 0.01;
			double b = p[i] * 0.01;
			ans *= b;		// all 1
			if (i == 0) {
				// setup initial state
				for (int j = 0; j <= N; ++j) {
					dp[next][0][j] = 0;
					dp[next][1][j] = 0;
				}
				dp[next][0][0] = a;
				dp[next][1][0] = b;
			} else {
				for (int j = 0; j <= N; ++j) {
					dp[next][0][j] = dp[prev][0][j] * a + (j > 0 ? dp[prev][1][j - 1] * a : 0);
					dp[next][1][j] = dp[prev][1][j] * b + (j > 0 ? dp[prev][0][j - 1] * b : 0);
				}
			}
		}

		int c = N & 1;
		for (int i = 0; i <= N; ++i) {
			ans += (dp[c][0][i] + dp[c][1][i]) * i;
		}
		return ans;
	}


// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (fabs(Expected - Received) < 1.0e-9) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100, 100, 100};
			double Arg1 = 1.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedActions(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {50, 50};
			double Arg1 = 0.75;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedActions(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 40, 50, 60};
			double Arg1 = 1.4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedActions(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {37, 63, 23, 94, 12};
			double Arg1 = 2.6820475464;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedActions(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 100 };
			double Arg1 = 1.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedActions(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 0 };
			double Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedActions(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 1 };
			double Arg1 = 0.01;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedActions(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10
			};
			double Arg1 = 30.852;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedActions(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Bitwisdom ___test;
	___test.run_test(-1);
}
// END CUT HERE
