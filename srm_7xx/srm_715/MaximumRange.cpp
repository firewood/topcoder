// BEGIN CUT HERE
/*
SRM 715 Div1 Easy (250)

PROBLEM STATEMENT

Cat Noku was given a calculator for his birthday.
The calculator is very simple.
It can only store a single variable.
The variable is called X and its initial value is 0.
The calculator has only two buttons: + and -.
Pressing + increments X by 1 and pressing - decrements X by 1.
For example, if X is 4 and Noku presses +, X is incremented to 5.

A string of '+' and '-' characters can be seen as a sequence of instructions to press the corresponding buttons.
The range of such a sequence of instructions is the difference between the largest and the smallest value stored in X while executing that sequence of instructions, in order.

For example, the range of "+++++++" is 7: the largest value of X is 7 (at the end) and the smallest value is 0 (in the beginning).
The range of "---" is 3: maximum is 0, minimum is (-3), their difference is 0 - (-3) = 3.
The range of "+-+-+-" is 1.
The range of an empty sequence of instructions is 0.

Noku's calculator came with a piece of paper that contained a string s.
Each character of s was either '+' or '-'.
Noku will choose and execute any (not necessarily contiguous) subsequence of these characters.
Help him do so in a way that maximizes the range of the executed sequence.

Compute and return the maximal range of a subsequence of the string s.


DEFINITION
Class:MaximumRange
Method:findMax
Parameters:string
Returns:int
Method signature:int findMax(string s)


CONSTRAINTS
-s will contain between 1 and 2,500 characters, inclusive.
-Each element of s will be '+' or '-'.


EXAMPLES

0)
"+++++++"

Returns: 7

Cat Noku should choose the entire string s.
As we saw in the problem statement, the range of "+++++++" is 7, and clearly this is the most we can get.


1)
"+--+--+"

Returns: 4

One optimal solution is to skip the fourth instruction (the '+' in the middle of s).
Thus, the sequence of button presses will be "+----+".
The value of X will change as follows: 0,1,0,-1,-2,-3,-2.
The maximum number we see is 1 while the minimum number is -3, so the range is 1 - (-3) = 4.


2)
"++++--------"

Returns: 8


3)
"-+-+-+-+-+-+"

Returns: 6


4)
"+"

Returns: 1

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

class MaximumRange {
public:
	int findMax(string s) {
		int c = count(s.begin(), s.end(), '+');
		return max(c, (int)s.length() - c);
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
			string Arg0 = "+++++++";
			int Arg1 = 7;

			verify_case(n, Arg1, findMax(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "+--+--+";
			int Arg1 = 4;

			verify_case(n, Arg1, findMax(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "++++--------";
			int Arg1 = 8;

			verify_case(n, Arg1, findMax(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "-+-+-+-+-+-+";
			int Arg1 = 6;

			verify_case(n, Arg1, findMax(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "+";
			int Arg1 = 1;

			verify_case(n, Arg1, findMax(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MaximumRange ___test;
	___test.run_test(-1);
}
// END CUT HERE
