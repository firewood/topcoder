// BEGIN CUT HERE
/*
SRM 695 Div2 Medium (600)

PROBLEM STATEMENT
A substring of a string is any non-empty contiguous subsequence of its characters.
For example, both "abc" and "bcd" are substrings of "abcde", but "ace" is not a substring of "abcde".

A string is called constant if all of its characters are the same.
For example, "a" and "bbbbb" are constant strings, but "aba" is not a constant string.

Two substrings of the same string are considered distinct if they start or end at a different position.
For example, the string "ababab" contains three distinct copies of the substring "ab", and the string "aaaa" contains two distinct copies of the substring "aaa".

Bear Limak is creating a new account and he needs to choose a password.
His password should satisfy the following security requirements:

The password must be a string of length N.
Each character of the password must be either 'a' or 'b'.
For each i between 1 and N, inclusive, the password must contain exactly x[i-1] constant substrings of length i.


You are given the vector <int> x with N elements.
Help Limak: find and return a valid password!
If there are many valid passwords, you may return any of them.
If there are no valid passwords, return "" (i.e., an empty string).


DEFINITION
Class:BearPasswordAny
Method:findPassword
Parameters:vector <int>
Returns:string
Method signature:string findPassword(vector <int> x)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-x will contain exactly N elements.
-Each element in x will be between 0 and N, inclusive.


EXAMPLES

0)
{5,0,0,0,0}

Returns: "ababa"

Since the given vector <int> x has five elements, the password must contain exactly five characters.
A password must contain x[0] = 5 constant substrings of length 1, and 0 constant substrings of bigger lengths.
The only two valid passwords are "ababa" and "babab".
You may return any of them.


1)
{4,2,1,0}

Returns: "baaa"


2)
{3,1,1}

Returns: ""


3)
{4,3,2,1}

Returns: "aaaa"


4)
{0}

Returns: ""


5)
{4,0,3,2}

Returns: ""


6)
{6,3,1,0,0,0}

Returns: "abbaaa"


7)
{10,5,2,1,0,0,0,0,0,0}

Returns: "bbbbaababb"


8)
{5,4,2,1,0}

Returns: ""

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class BearPasswordAny {
public:
	string findPassword(vector <int> x) {
		int N = (int)x.size();
		int len = 0;
		for (int i = N - 1; i >= 0; --i) {
			for (int j = i + 1; j < N; ++j) {
				x[i] -= x[j] * (j - i + 1);
			}
			len += (i + 1) * x[i];
			if (x[i] < 0) {
				return "";
			}
		}
		if (len != N) {
			return "";
		}

		string ans;
		int high = N - 1, low = 0;
		bool f = true;
		while (ans.length() != N) {
			while (high > 0 && x[high] <= 0) {
				--high;
			}
			if (x[high]-- > 0) {
				ans += string(high + 1, f ? 'a' : 'b');
				f = !f;
			}
			while (low < (N - 1) && x[low] <= 0) {
				++low;
			}
			if (x[low]-- > 0) {
				ans += string(low + 1, f ? 'a' : 'b');
				f = !f;
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
			int Arr0[] = {5,0,0,0,0};
			string Arg1 = "ababa";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,2,1,0};
			string Arg1 = "baaa";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,1,1};
			string Arg1 = "";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,3,2,1};
			string Arg1 = "aaaa";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			string Arg1 = "";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,0,3,2};
			string Arg1 = "";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {6,3,1,0,0,0};
			string Arg1 = "abbaaa";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,5,2,1,0,0,0,0,0,0};
			string Arg1 = "bbbbaababb";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		// test_case_8
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,4,2,1,0};
			string Arg1 = "";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearPasswordAny ___test;
	___test.run_test(-1);
}
// END CUT HERE
