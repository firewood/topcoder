// BEGIN CUT HERE
/*
SRM 587 Div2 Easy (250)

PROBLEM STATEMENT

You are given two strings: init and goal.
Both init and goal contain lowercase letters only.
Additionally, init does not contain the character 'z'.

Your goal is to transform init into goal.
The only operation you are allowed to do is to insert the character 'z' anywhere into init.
You can repeat the operation as many times as you want, and each time you can choose any position where to insert the 'z'.

For example, if init="fox", you can transform it to "fzox" in one operation.
Alternately, you can transform "fox" into "zzzfoxzzz" in six operations.
It is not possible to transform "fox" into any of the strings "fx", "foz", "fxo", "foxy".

Return "Yes" (quotes for clarity) if it is possible to transform init into goal.
Otherwise, return "No".


DEFINITION
Class:InsertZ
Method:canTransform
Parameters:string, string
Returns:string
Method signature:string canTransform(string init, string goal)


NOTES
-Note that the return value is case sensitive.


CONSTRAINTS
-init and goal will each contain between 1 and 50 characters, inclusive.
-Each character of init and goal will be a lowercase letter ('a'-'z').
-init will not contain the letter 'z'.


EXAMPLES

0)
"fox"
"fozx"

Returns: "Yes"

By inserting 'z' to the position bettween 'o' and 'x' in "fox", we obtain "fozx".


1)
"fox"
"zfzoxzz"

Returns: "Yes"

You may perform the operation multiple times.


2)
"foon"
"foon"

Returns: "Yes"

In this case init and goal are equal. You do not have to perform the operation.


3)
"topcoder"
"zopzoder"

Returns: "No"


4)
"aaaaaaaaaa"
"a"

Returns: "No"


5)
"mvixrdnrpxowkasufnvxaq"
"mvizzxzzzrdzznzrpxozzwzzkazzzszzuzzfnvxzzzazzq"

Returns: "Yes"


6)
"opdlfmvuicjsierjowdvnx"
"zzopzdlfmvzuicjzzsizzeijzowvznxzz"

Returns: "No"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class InsertZ {
public:
	string canTransform(string init, string goal) {
		string s;
		for (char c : goal) {
			if (c != 'z') {
				s += c;
			}
		}
		return init.compare(s) == 0 ? "Yes" : "No";
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
			string Arg0 = "fox";
			string Arg1 = "fozx";
			string Arg2 = "Yes";

			verify_case(n, Arg2, canTransform(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "fox";
			string Arg1 = "zfzoxzz";
			string Arg2 = "Yes";

			verify_case(n, Arg2, canTransform(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "foon";
			string Arg1 = "foon";
			string Arg2 = "Yes";

			verify_case(n, Arg2, canTransform(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "topcoder";
			string Arg1 = "zopzoder";
			string Arg2 = "No";

			verify_case(n, Arg2, canTransform(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaaaaaaaa";
			string Arg1 = "a";
			string Arg2 = "No";

			verify_case(n, Arg2, canTransform(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "mvixrdnrpxowkasufnvxaq";
			string Arg1 = "mvizzxzzzrdzznzrpxozzwzzkazzzszzuzzfnvxzzzazzq";
			string Arg2 = "Yes";

			verify_case(n, Arg2, canTransform(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "opdlfmvuicjsierjowdvnx";
			string Arg1 = "zzopzdlfmvzuicjzzsizzeijzowvznxzz";
			string Arg2 = "No";

			verify_case(n, Arg2, canTransform(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	InsertZ ___test;
	___test.run_test(-1);
}
// END CUT HERE
