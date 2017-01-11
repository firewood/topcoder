// BEGIN CUT HERE
/*
SRM 703 Div2 Easy (250)

PROBLEM STATEMENT
A string of zeros and ones is called an alternating string if no two adjacent characters are the same.
Examples of alternating strings: "1", "10101", "0101010101".

You are given a string s.
Each character of s is a '0' or a '1'.
Please find the longest contiguous substring of s that is an alternating string.
Return the length of that substring.


DEFINITION
Class:AlternatingString
Method:maxLength
Parameters:string
Returns:int
Method signature:int maxLength(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character in s will be '0' or '1'.


EXAMPLES

0)
"111101111"

Returns: 3

Among all substrings, there are 5 different alternating strings: "1", "0", "10", "01", "101". The one with maximal length is "101" and the length is 3.


1)
"1010101"

Returns: 7

The string s itself is an alternating string.


2)
"000011110000"

Returns: 2

Note that a substring must be contiguous. The longest alternating substrings of this s are "01" and "10". The string "010" is not a substring of this s.


3)
"1011011110101010010101"

Returns: 8


4)
"0"

Returns: 1

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class AlternatingString {
public:
	int maxLength(string s) {
		int ans = 0;
		for (int i = 0; i != 2; ++i) {
			for (int j = 0; j != s.length(); ++j) {
				int k;
				for (k = j; k != s.length(); ++k) {
					if ((s[k] - '0') != ((k & 1) ^ i)) {
						break;
					}
				}
				ans = max(ans, k - j);
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
			string Arg0 = "111101111";
			int Arg1 = 3;

			verify_case(n, Arg1, maxLength(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "1010101";
			int Arg1 = 7;

			verify_case(n, Arg1, maxLength(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "000011110000";
			int Arg1 = 2;

			verify_case(n, Arg1, maxLength(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "1011011110101010010101";
			int Arg1 = 8;

			verify_case(n, Arg1, maxLength(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "0";
			int Arg1 = 1;

			verify_case(n, Arg1, maxLength(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AlternatingString ___test;
	___test.run_test(-1);
}
// END CUT HERE
