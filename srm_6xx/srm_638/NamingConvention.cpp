// BEGIN CUT HERE
/*
SRM 638 Div2 Easy (250)

PROBLEM STATEMENT
In most programming languages variable names cannot contain spaces.
If we want a variable name that consists of two or more words, we have to encode the spaces somehow.
In this problem, we will look at two ways of doing so: Snake Case and Camel Case.
When using Snake Case, we just replace each space by an underscore ('_').
When using Camel Case, we capitalize the first letter of each word except for the first one,
and then we remove all spaces.

For example, suppose that we want to declare a variable called "good morning world" (quotes for clarity).
In Snake Case, we would write this variable as "good_morning_world",
while in Camel Case it would be "goodMorningWorld".
You are given a string variableName.
This string contains a valid variable name written in Snake Case.
Return the same variable name in Camel Case.


DEFINITION
Class:NamingConvention
Method:toCamelCase
Parameters:string
Returns:string
Method signature:string toCamelCase(string variableName)


CONSTRAINTS
-variableName will contain between 1 and 50 characters.
-Each character of variableName will be 'a'-'z' or '_'.
-The first and last character of variableName will not be '_'.
-variableName will not contain two consecutive underscores ('_').


EXAMPLES

0)
"sum_of_two_numbers"

Returns: "sumOfTwoNumbers"

We have 4 words: "sum", "of", "two", "numbers". So the answer is "sum" + "Of" + "Two" + "Numbers".


1)
"variable"

Returns: "variable"

Note that if we have only 1 word, then the varaible name will remain same.


2)
"t_o_p_c_o_d_e_r"

Returns: "tOPCODER"


3)
"the_variable_name_can_be_very_long_like_this"

Returns: "theVariableNameCanBeVeryLongLikeThis"

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class NamingConvention {
public:
	string toCamelCase(string variableName) {
		string ans;
		bool u = false;
		for (char c : variableName) {
			if (c == '_') {
				u = true;
			} else if (u) {
				u = false;
				ans += toupper(c);
			} else {
				ans += c;
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "sum_of_two_numbers";
			string Arg1 = "sumOfTwoNumbers";

			verify_case(n, Arg1, toCamelCase(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "variable";
			string Arg1 = "variable";

			verify_case(n, Arg1, toCamelCase(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "t_o_p_c_o_d_e_r";
			string Arg1 = "tOPCODER";

			verify_case(n, Arg1, toCamelCase(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "the_variable_name_can_be_very_long_like_this";
			string Arg1 = "theVariableNameCanBeVeryLongLikeThis";

			verify_case(n, Arg1, toCamelCase(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NamingConvention ___test;
	___test.run_test(-1);
}
// END CUT HERE
