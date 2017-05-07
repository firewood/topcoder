// BEGIN CUT HERE
/*
SRM 714 Div1 Easy (250)

PROBLEM STATEMENT

Correct parentheses sequences can be defined recursively as follows:

The empty string "" is a correct sequence.
If "X" and "Y" are correct sequences, then "XY" (the concatenation of X and Y) is a correct sequence.
If "X" is a correct sequence, then "(X)" is a correct sequence.
Each correct parentheses sequence can be derived using the above rules.

Examples of correct parentheses sequences include "", "()", "()()()", "(()())", and "(((())))".

You are given a string s that is guaranteed to be a correct parentheses sequence.
A removal is an action that consists of two steps:

Remove the first opening parenthesis in s.
Remove one closing parenthesis in s. After you do so, s must again be a correct parentheses sequence.

Compute and return the number of distinct ways in which s can be reduced to an empty string by performing consecutive removals, modulo 10^9+7.
Two ways are considered distinct if there is a step in which you remove a different closing parenthesis.
(See Example 1 for clarification.)


DEFINITION
Class:ParenthesisRemoval
Method:countWays
Parameters:string
Returns:int
Method signature:int countWays(string s)


CONSTRAINTS
-s will have between 2 and 2,500 characters, inclusive.
-s will be a correct parentheses sequence.


EXAMPLES

0)
"()()()()()"

Returns: 1

In each removal we have to choose the leftmost closing parenthesis.


1)
"(((())))"

Returns: 24

In each removal we can choose any closing parenthesis we want.
Note that these count as distint choices, even though all choices lead to the same string.
Thus, there are 4*3*2*1 = 24 different sequences of removals that change s into an empty string.


2)
"((()()()))"

Returns: 54

Below is one of the 54 possible sequences of removals.
Remember that in each step we also remove the first opening parenthesis.

 Remove the fourth closing parenthesis: "(()()())"
 Remove the second closing parenthesis: "()(())"
 Remove the first closing parenthesis: "(())"
 Remove the second closing parenthesis: "()"
 Remove the first closing parenthesis: ""


3)
"(())(())(())"

Returns: 8


4)
"((((())((((((((((()((((((()))))())))))()))))))))))"

Returns: 948334170

Don't forget about the mod.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;
static const LL MOD = 1000000007LL;

class ParenthesisRemoval {
public:
	int countWays(string s) {
		LL ans = 1, cnt = 0;
		for (int i = 0; i != s.length(); ++i) {
			if (s[i] == '(') {
				ans = (ans * ++cnt) % MOD;
			} else {
				--cnt;
			}
		}
		return (int)ans;
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
			string Arg0 = "()()()()()";
			int Arg1 = 1;

			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "(((())))";
			int Arg1 = 24;

			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "((()()()))";
			int Arg1 = 54;

			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "(())(())(())";
			int Arg1 = 8;

			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "((((())((((((((((()((((((()))))())))))()))))))))))";
			int Arg1 = 948334170;

			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ParenthesisRemoval ___test;
	___test.run_test(-1);
}
// END CUT HERE
