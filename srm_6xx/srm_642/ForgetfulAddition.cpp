// BEGIN CUT HERE
/*
SRM 642 Div2 Easy (250)

PROBLEM STATEMENT

Alice had two positive integers, a and b.
She typed the expression "a+b" into her computer, but the '+' key malfunctioned.
For example, instead of "128+9" the computer's screen now shows "1289".

Later, Bob saw the string on the screen.
He knows that the '+' sign is missing but he does not know where it belongs.
He now wonders what is the smallest possible result of Alice's original expression.

For example, if Bob sees the string "1289", Alice's expression is either "128+9" or "12+89" or "1+289".
These expressions evaluate to 137, 101, and 290.
The smallest of those three results is 101.

You are given a string expression that contains the expression on Alice's screen.
Compute and return the smallest possible result after inserting the missing plus sign


DEFINITION
Class:ForgetfulAddition
Method:minNumber
Parameters:string
Returns:int
Method signature:int minNumber(string expression)


CONSTRAINTS
-expression will contain between 2 and 8 characters, inclusive.
-Each character of expression will be between '1' and '9'.


EXAMPLES

0)
"22"

Returns: 4

The only possible expression Alice could have typed is "2+2". Thus, Bob knows this evaluates to 4.


1)
"123"

Returns: 15

The expression Alice has typed could have been "1+23" or "12+3". Of these two, the second is smaller, thus Bob will get the answer 15. 


2)
"1289"

Returns: 101

This is the example from the problem statement.


3)
"31415926"

Returns: 9067


4)
"98765"

Returns: 863

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class ForgetfulAddition {
public:
	int minNumber(string expression) {
		int ans = 1 << 30;
		for (int i = 1; i < (int)expression.length(); ++i) {
			int a = atoi(expression.substr(0, i).c_str());
			int b = atoi(expression.substr(i).c_str());
			ans = min(ans, a + b);
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
			string Arg0 = "22";
			int Arg1 = 4;

			verify_case(n, Arg1, minNumber(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "123";
			int Arg1 = 15;

			verify_case(n, Arg1, minNumber(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "1289";
			int Arg1 = 101;

			verify_case(n, Arg1, minNumber(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "31415926";
			int Arg1 = 9067;

			verify_case(n, Arg1, minNumber(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "98765";
			int Arg1 = 863;

			verify_case(n, Arg1, minNumber(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ForgetfulAddition ___test;
	___test.run_test(-1);
}
// END CUT HERE
