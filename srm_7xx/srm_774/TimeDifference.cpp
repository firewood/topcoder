// BEGIN CUT HERE
/*
SRM 774 Div2 Easy (250)

PROBLEM STATEMENT

We have a timer that counts elapsed hours and minutes.

You are given two strings: time1 and time2.
Determine the amount of time that elapsed from the moment our timer showed time1 to the moment our timer showed time2.

Both times are given in the format "hhH:MM" (quotes added for clarity).
This means that:

There are always exactly two digits for minutes.
There are between one and three digits for hours.

Note that the number of hours in time1 and/or time2 may have unnecessary leading zeros. (See the Examples.)

You must return the answer in the format "[-]hhH:MM".
More precisely:

The answer must start with a minus if and only if the time difference is negative, i.e., if time2 was shown strictly sooner than time1.
The rest of the answer must be the absolute value of the time difference, in hours and minutes.
The number of minutes must always be given with exactly two digits.
The number of hours must not have unnecessary leading zeros.


DEFINITION
Class:TimeDifference
Method:calculate
Parameters:string, string
Returns:string
Method signature:string calculate(string startTime, string endTime)


NOTES
-There are 60 minutes in an hour, so the number of minutes will always be between 00 and 59, inclusive.


CONSTRAINTS
-time1 and time2 will be in the format described in the problem statement.


EXAMPLES

0)
"00:00"
"13:23"

Returns: "13:23"

The timer started at "00:00" and after 13 hours and 23 minutes it showed "13:23".


1)
"100:15"
"13:23"

Returns: "-86:52"

The timer showed "13:23" almost 87 hours earlier than "100:15".


2)
"001:00"
"8:15"

Returns: "7:15"

Unnecessary leading zeroes are allowed in the input, but not in the output. The answer "07:15" would be rejected.


3)
"123:45"
"543:21"

Returns: "419:36"


4)
"111:11"
"222:12"

Returns: "111:01"

The number of minutes must always be printed with exactly two digits. The answer should not be "111:1".


5)
"10:42"
"10:47"

Returns: "0:05"

If the number of hours in the difference is 0, the '0' still has to be printed as the number of hours. (This zero is not considered an unnecessary leading zero.)


6)
"10:47"
"010:47"

Returns: "0:00"

Even though the strings are not equal, they do represent the same time, so the time difference is zero hours and zero minutes. (Note that the answer in this case should not start with a '-'.)

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class TimeDifference {
public:
	string calculate(string startTime, string endTime) {
		int hs, ms, he, me, h, m;
		string sign;
		sscanf(startTime.c_str(), "%d:%d", &hs, &ms);
		sscanf(endTime.c_str(), "%d:%d", &he, &me);
		if (hs > he || (hs == he && ms > me)) {
			sign = "-";
			swap(hs, he);
			swap(ms, me);
		}
		h = he - hs - 1, m = me - ms + 60;
		string latter = "0" + to_string(m % 60);
		return sign + to_string(h + m / 60) + ":" + latter.substr(latter.length() - 2, 2);
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
			string Arg0 = "00:00";
			string Arg1 = "13:23";
			string Arg2 = "13:23";

			verify_case(n, Arg2, calculate(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "100:15";
			string Arg1 = "13:23";
			string Arg2 = "-86:52";

			verify_case(n, Arg2, calculate(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "001:00";
			string Arg1 = "8:15";
			string Arg2 = "7:15";

			verify_case(n, Arg2, calculate(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "123:45";
			string Arg1 = "543:21";
			string Arg2 = "419:36";

			verify_case(n, Arg2, calculate(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "111:11";
			string Arg1 = "222:12";
			string Arg2 = "111:01";

			verify_case(n, Arg2, calculate(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "10:42";
			string Arg1 = "10:47";
			string Arg2 = "0:05";

			verify_case(n, Arg2, calculate(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "10:47";
			string Arg1 = "010:47";
			string Arg2 = "0:00";

			verify_case(n, Arg2, calculate(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TimeDifference ___test;
	___test.run_test(-1);
}
// END CUT HERE
