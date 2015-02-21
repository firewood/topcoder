// BEGIN CUT HERE
/*
SRM 650 Div1 Medium (500)

PROBLEM STATEMENT

Cat Taro likes strings.
You are given a string S.
Each character of S is 'A', 'B', or '?'.

To Taro, the ugliness of a string is the number of pairs of equal consecutive characters.
For example, the ugliness of "ABABAABBB" is 3: there is one pair "AA" and two (overlapping) pairs "BB".

Taro now wants to change each question mark in S either to 'A' or to 'B'.
His goal is to minimize the ugliness of the resulting string.
Return the smallest ugliness that can be achieved.


DEFINITION
Class:TaroFillingAStringDiv2
Method:getNumber
Parameters:string
Returns:int
Method signature:int getNumber(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-S will consist only of characters 'A', 'B' and '?'.


EXAMPLES

0)
"ABAA"

Returns: 1

There is initially one pair of consecutive digits that are equal in this case. There is no characters that Taro has to replace, hence the answer is 1.


1)
"??"

Returns: 0


2)
"A?A"

Returns: 0


3)
"A??B???AAB?A???A"

Returns: 3


4)
"?BB?BAAB???BAB?B?AAAA?ABBA????A?AAB?BBA?A?"

Returns: 10

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TaroFillingAStringDiv2 {
public:
	int getNumber(string S) {
		int ans = 0;
		char prev = '?';
		for (char c : S) {
			if (c == '?') {
				if (prev != '?') {
					c = (prev == 'A') ? 'B' : 'A';
				}
			} else {
				ans += (prev == c);
			}
			prev = c;
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
			string Arg0 = "ABAA";
			int Arg1 = 1;

			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "??";
			int Arg1 = 0;

			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "A?A";
			int Arg1 = 0;

			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "A??B???AAB?A???A";
			int Arg1 = 3;

			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "?BB?BAAB???BAB?B?AAAA?ABBA????A?AAB?BBA?A?";
			int Arg1 = 10;

			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TaroFillingAStringDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
