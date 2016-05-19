// BEGIN CUT HERE
/*
SRM 689 Div2 Medium (500)

PROBLEM STATEMENT
You are given two strings: A and B.
Each character in A is either '0' or '1'.
Each character in B is '0', '1', or '?'.

A string C matches B if we can change B into C by changing each '?' in B either to '0' or to '1'.
Different occurrences of '?' may be changed to different digits.
For example, C = "0101" matches B = "01??".
Note that each character in C must be either '0' or '1', there cannot be any '?' remaining.

Consider all possible strings that match B.
How many of these strings occur as a (contiguous) substring in A?
Compute and return their number.
Note that we only count each good string once, even if it has multiple occurrences in A.


DEFINITION
Class:NonDeterministicSubstring
Method:ways
Parameters:string, string
Returns:long long
Method signature:long long ways(string A, string B)


CONSTRAINTS
-A will contain between 1 and 50 characters, inclusive.
-B will contain between 1 and 50 characters, inclusive.
-Each character in A will be '0' or '1'.
-Each character in B will be '0', '1' or '?'.


EXAMPLES

0)
"00010001"
"??"

Returns: 3

There are four strings that match B: the strings "00", "01", "10", and "11".
Out of these, the string "11" does not occur in A as a substring.
The other three do occur, hence the answer is 3.


1)
"00000000"
"??0??0"

Returns: 1

There are 16 different strings that match B, but out of those only the string "000000" is a substring of A.


2)
"001010101100010111010"
"???"

Returns: 8

Each of the 8 strings that match B occurs somewhere in A.


3)
"00101"
"??????"

Returns: 0

Here, the length of B is greater than the length of A.
Clearly, a string that matches this B cannot be a substring of this A.


4)
"1101010101111010101011111111110001010101"
"???????????????????????????????????"

Returns: 6

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef set<string> StrSet;

class NonDeterministicSubstring {
public:
	long long ways(string A, string B) {
		long long ans = 0;
		StrSet m;
		int a_len = (int)A.length(), b_len = (int)B.length();
		for (int i = 0; i + b_len <= a_len; ++i) {
			string c = A.substr(i, b_len);
			if (m.find(c) == m.end()) {
				m.insert(c);
				int j;
				for (j = 0; j < b_len; ++j) {
					if (B[j] != '?' && A[i + j] != B[j]) {
						break;
					}
				}
				ans += j >= b_len;
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "00010001";
			string Arg1 = "??";
			long long Arg2 = 3LL;

			verify_case(n, Arg2, ways(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "00000000";
			string Arg1 = "??0??0";
			long long Arg2 = 1LL;

			verify_case(n, Arg2, ways(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "001010101100010111010";
			string Arg1 = "???";
			long long Arg2 = 8LL;

			verify_case(n, Arg2, ways(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "00101";
			string Arg1 = "??????";
			long long Arg2 = 0LL;

			verify_case(n, Arg2, ways(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "1101010101111010101011111111110001010101";
			string Arg1 = "???????????????????????????????????";
			long long Arg2 = 6LL;

			verify_case(n, Arg2, ways(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NonDeterministicSubstring ___test;
	___test.run_test(-1);
}
// END CUT HERE
