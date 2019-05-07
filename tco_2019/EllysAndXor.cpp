// BEGIN CUT HERE
/*
TCO19 R1A Easy (250)

PROBLEM STATEMENT
Elly has a sequence of small positive integers. You are given this sequence in the vector <int> numbers. The girl wants to place a bitwise AND operator ('&') or a bitwise XOR operator ('^') between each pair of neighboring numbers. Now she wonders what is the maximal result that can be achieved if using optimal placement of operations between the integers?
For this task we will assume that the operations AND and XOR have equal priority (precedence), thus the expression is evaluated left to right. For example, 42 ^ 26 & 38 will be evaluated as (42 ^ 27) & 38 = 49 & 38 = 32. Note, however, that the maximal answer for the numbers (42, 27, 38) is achieved by using the expression 42 & 27 ^ 38 = (42 & 27) ^ 38 = 10 ^ 38 = 44.


DEFINITION
Class:EllysAndXor
Method:getMax
Parameters:vector <int>
Returns:int
Method signature:int getMax(vector <int> numbers)


NOTES
-The result of the bitwise operation AND (denoted as '&') applied on two integers is a new integer, having 1-bits on each position where both integers had a 1 in their binary representation, and 0 on all others. For example, 42(10) & 27(10) = 101010(2) & 011011(2) = 001010(2) = 10(10).
-The result of the bitwise operation XOR (denoted as '^') applied on two integers is a new integer, having 1-bits on each position where exactly one of the integers had a 1 in their binary representation, and 0 on all others. For example, 42(10) ^ 27(10) = 101010(2) ^ 011011(2) = 110001(2) = 49(10).


CONSTRAINTS
-numbers will contain between 1 and 10 elements, inclusive.
-Each element of numbers will be between 1 and 1000, inclusive.


EXAMPLES

0)
{42, 27, 38}

Returns: 44

The example from the problem statement.


1)
{666, 133, 438, 123, 893, 674, 462, 209}

Returns: 976


2)
{42}

Returns: 42

The result of an expression with a single number equals the number.


3)
{123, 456, 789, 987, 654, 321}

Returns: 975


4)
{42, 13, 17, 666, 811, 314, 1, 5, 2, 1000}

Returns: 1007

Please note that the answer can go over 1000.

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

class EllysAndXor {
public:
	int getMax(vector <int> numbers) {
		int dp[16][1024];
		memset(dp, 0, sizeof(dp));
		dp[0][numbers[0]] = 1;
		int n = (int)numbers.size();
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < 1024; ++j) {
				if (dp[i - 1][j]) {
					dp[i][j & numbers[i]] = 1;
					dp[i][j ^ numbers[i]] = 1;
				}
			}
		}
		int ans = 0;
		for (int j = 0; j < 1024; ++j) {
			if (dp[n - 1][j]) {
				ans = j;
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
			int Arr0[] = {42, 27, 38};
			int Arg1 = 44;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMax(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {666, 133, 438, 123, 893, 674, 462, 209};
			int Arg1 = 976;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMax(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {42};
			int Arg1 = 42;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMax(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {123, 456, 789, 987, 654, 321};
			int Arg1 = 975;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMax(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {42, 13, 17, 666, 811, 314, 1, 5, 2, 1000};
			int Arg1 = 1007;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMax(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysAndXor ___test;
	___test.run_test(-1);
}
// END CUT HERE
