// BEGIN CUT HERE
/*
SRM 583 Div2 Easy (250)

PROBLEM STATEMENT
Given is a string num. This string contains the digits of a (possibly large) positive integer.
For example, num="1147" represents the integer 1147. The string num will not have any leading zeros.

You are allowed to swap one pair of digits in the given number.
In other words, you may choose a pair of distinct indices i and j, and swap the characters num[i] and num[j].
Note that you may also leave the original number unchanged.
The new string must again describe a valid positive integer, i.e., it must not have any leading zeros.

Find and return the string that represents the smallest possible integer that can be obtained.


DEFINITION
Class:SwappingDigits
Method:minNumber
Parameters:string
Returns:string
Method signature:string minNumber(string num)


CONSTRAINTS
-The length of num will be between 2 and 50, inclusive.
-Each character of num will be between '0' and '9', inclusive.
-The first character of num will not be '0'.


EXAMPLES

0)
"596"

Returns: "569"

You can swap num[1] and num[2] to get the minimum integer.


1)
"93561"

Returns: "13569"


2)
"5491727514"

Returns: "1491727554"


3)
"10234"

Returns: "10234"

You can leave the original string num unchanged. Note that the result must not contain leading zeros.


4)
"93218910471211292416"

Returns: "13218910471211292496"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SwappingDigits {
public:
	string minNumber(string num) {
		string ans = num;
		int len = num.length();
		for (int i = 0; i < len; ++i) {
			for (int j = i + 1; j < len; ++j) {
				if (i == 0 && num[j] == '0') {
					continue;
				}
				string s = num;
				s[i] = num[j], s[j] = num[i];
				if (s < ans) {
					ans = s;
				}
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
			string Arg0 = "596";
			string Arg1 = "569";

			verify_case(n, Arg1, minNumber(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "93561";
			string Arg1 = "13569";

			verify_case(n, Arg1, minNumber(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "5491727514";
			string Arg1 = "1491727554";

			verify_case(n, Arg1, minNumber(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "10234";
			string Arg1 = "10234";

			verify_case(n, Arg1, minNumber(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "93218910471211292416";
			string Arg1 = "13218910471211292496";

			verify_case(n, Arg1, minNumber(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SwappingDigits ___test;
	___test.run_test(-1);
}
// END CUT HERE
