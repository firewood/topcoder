// BEGIN CUT HERE
/*
SRM 597 Div2 Easy (250)

PROBLEM STATEMENT

Little Elephant from the Zoo of Lviv likes integers.

You are given an vector <int> A. On a single turn, Little Elephant can double (i.e., multiply by 2) any element of A. He may double the same element more than once, if he wants to. He wants to obtain an array in which all elements are equal. Return "YES" (quotes for clarity) if it is possible to do that and "NO" otherwise.

DEFINITION
Class:LittleElephantAndDouble
Method:getAnswer
Parameters:vector <int>
Returns:string
Method signature:string getAnswer(vector <int> A)


NOTES
-The return value is case-sensitive. Make sure that you return the exact strings "YES" and "NO".


CONSTRAINTS
-A will contain between 1 and 50 elements, inclusive.
-Each element of A will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{1, 2}

Returns: "YES"

One possible way of making all elements equal is to double the element at index 0.


1)
{1, 2, 3}

Returns: "NO"

It's impossible to make all three elements equal in this case.


2)
{4, 8, 2, 1, 16}

Returns: "YES"


3)
{94, 752, 94, 376, 1504}

Returns: "YES"


4)
{148, 298, 1184}

Returns: "NO"


5)
{7, 7, 7, 7}

Returns: "YES"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class LittleElephantAndDouble {
public:
	string getAnswer(vector <int> A) {
		for (int i = 1; i < (int)A.size(); ++i) {
			int a = min(A[0], A[i]);
			int b = max(A[0], A[i]);
			while (a < b) {
				a *= 2;
			}
			if (a != b) {
				return "NO";
			}
		}
		return "YES";
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
			int Arr0[] = {1, 2};
			string Arg1 = "YES";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getAnswer(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3};
			string Arg1 = "NO";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getAnswer(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 8, 2, 1, 16};
			string Arg1 = "YES";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getAnswer(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {94, 752, 94, 376, 1504};
			string Arg1 = "YES";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getAnswer(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {148, 298, 1184};
			string Arg1 = "NO";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getAnswer(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7, 7, 7, 7};
			string Arg1 = "YES";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getAnswer(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LittleElephantAndDouble ___test;
	___test.run_test(-1);
}
// END CUT HERE
