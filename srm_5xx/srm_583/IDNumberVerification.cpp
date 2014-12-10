// BEGIN CUT HERE
/*
SRM 583 Div2 Medium (550)

PROBLEM STATEMENT
In People's Republic of China, every citizen has a unique ID string.
The length of the ID is 18 characters. The first 17 characters (called the body code) are all digits,
the last character (called the checksum code) can be either a digit or 'X'.

The body code is then divided into three parts: from left to right,
these are the region code, the birthday code, and the sequential code.
They look as follows:

The region code has 6 digits. Some 6-digit strings represent regions, other 6-digit strings are invalid.
You are given the valid region codes as a vector <string> regionCodes.
The birthday code has 8 digits.
It gives the citizen's birthday in the form YYYYMMDD.
That is, the first 4 digits is the year of birth, the next 2 is the month (01 to 12, with a leading zero if necessary),
and the last 2 digits is the day.
When verifying the birthday code, you should consider leap years (see the Notes).
Additionally, a valid birthday code must represent a date between Jan 1, 1900 and Dec 31, 2011, inclusive.
The sequential code has 3 digits.
These 3 digits may be arbitrary, with one exception: the sequential code "000" is invalid.
If the sequential code represents an odd number (e.g., "007"), the person is a male.
Otherwise (e.g., "420") the person is a female.

The last character of an ID string is the checksum code.
This is derived from the first 17 digits. Let a1, a2, ..., a17 denote the body code from left to right.
Consider the following modular equation: x + a1*217 + a2*216 + a3*215 + ... + a16*22 + a17*21 = 1 (mod 11).
This equation always has exactly one solution x such that 0 <= x <= 10.
If x=10, the checksum code is 'X'. Otherwise, the checksum code is the corresponding digit.
(E.g., if x=5, the checksum code is '5'.)

You are given a string id. If this is not a valid ID string, return "Invalid" (quotes for clarity).
If id represents a valid ID string of a male citizen, return "Male". Finally,
if id represents a valid ID string of a female citizen, return "Female".


DEFINITION
Class:IDNumberVerification
Method:verify
Parameters:string, vector <string>
Returns:string
Method signature:string verify(string id, vector <string> regionCodes)


NOTES
-A year is a leap year if and only if it satisfies one of the following two conditions:
 A: It is a multiple of 4, but not a multiple of 100. B: It is a multiple of 400.
 Therefore, 1904 and 2000 are leap years, while 1900 and 2011 are not.


CONSTRAINTS
-id will be 18 characters long.
-First 17 characters of id will be between '0' and '9', inclusive.
-Last character of id will be 'X' or between '0' and '9', inclusive.
-regionCodes will contain between 1 and 50 elements, inclusive.
-Each element of regionCodes will be 6 characters long.
-Each element of regionCodes will consist of characters between '0' and '9', inclusive.
-For each element of regionCodes, its first character will not be '0'.
-Elements of regionCodes will be pairwise distinct.


EXAMPLES

0)
"441323200312060636"
{"441323"}

Returns: "Male"

As you can see, region code, birthday code and sequential code are all valid. So we just need to check the equation of checksum code:
6 + 4*217 + 4*216 + 1*215 + 3*214 + 2*213 + 3*212 + 2*211 + 0*210 + 0*29 + 3*28 + 1*27 + 2*26 + 0*25 + 6*24 + 0*23 + 6*22 + 3*21 = 902276. It's easy to verify that 902276 mod 11 = 1. The sequential code ("063") is odd, thus this is a male.


1)
"62012319240507058X"
{"620123"}

Returns: "Female"


2)
"321669197204300886"
{"610111","659004"}

Returns: "Invalid"

Region code '321669' is invalid.


3)
"230231198306900162"
{"230231"}

Returns: "Invalid"

Birthday code '19830690' is invalid.


4)
"341400198407260005"
{"341400"}

Returns: "Invalid"

Sequential code '000' is invalid.


5)
"520381193206090891"
{"532922","520381"}

Returns: "Invalid"

Checksum code is incorrect.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

bool is_uruu(int year) {
	return (year % 4) == 0 && ((year % 100) != 0 || (year % 400) == 0);
}

class IDNumberVerification {

	bool check(string id, vector <string> regionCodes, bool &s) {
		bool r = false;
		for (string s : regionCodes) {
			if (s.compare(id.substr(0, 6)) == 0) {
				r = true;
				break;
			}
		}
		if (!r) {
			return false;
		}

		int year = atoi(id.substr(6, 4).c_str());
		int month = atoi(id.substr(10, 2).c_str());
		int day = atoi(id.substr(12, 2).c_str());
		if (year < 1900 || year > 2011) {
			return false;
		}
		int mdays[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month < 1 || month > 12) {
			return false;
		}
		if (day < 1 || day > mdays[month - 1]) {
			return false;
		}
		if (month == 2 && day == 29 && !is_uruu(year)) {
			return false;
		}

		int seq = atoi(id.substr(14, 3).c_str());
		if (seq == 0) {
			return false;
		}
		s = (seq % 2) != 0;

		int sum = 0;
		for (int i = 0; i < 17; ++i) {
			sum += (id[i] - '0') * (1 << (17 - i));
		}
		sum = (12 - sum % 11) % 11;
		if (sum == 10 && id[17] == 'X') {
			return true;
		}
		return sum == (id[17] - '0');
	}

public:
	string verify(string id, vector <string> regionCodes) {
		bool s;
		if (!check(id, regionCodes, s)) {
			return "Invalid";
		}
		return s ? "Male" : "Female";
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
			string Arg0 = "441323200312060636";
			string Arr1[] = {"441323"};
			string Arg2 = "Male";

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, verify(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "62012319240507058X";
			string Arr1[] = {"620123"};
			string Arg2 = "Female";

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, verify(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "321669197204300886";
			string Arr1[] = {"610111","659004"};
			string Arg2 = "Invalid";

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, verify(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "230231198306900162";
			string Arr1[] = {"230231"};
			string Arg2 = "Invalid";

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, verify(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "341400198407260005";
			string Arr1[] = {"341400"};
			string Arg2 = "Invalid";

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, verify(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "520381193206090891";
			string Arr1[] = {"532922","520381"};
			string Arg2 = "Invalid";

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, verify(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	IDNumberVerification ___test;
	___test.run_test(-1);
}
// END CUT HERE
