// BEGIN CUT HERE
/*
TCO 2016 Round 1A Easy (250)

PROBLEM STATEMENT
Elly has invented a simple time machine!
Unfortunately, it cannot change the time by more than several hours.
But sometimes several hours is all a person needs...

The time machine has a wall clock with two hands: a small hand that shows the hour and a large hand that shows the minutes.
Both hands move in discrete steps.
The minute hand moves to show the correct time whenever the number of minutes reaches a multiple of 5.
The hour hand moves to show the correct time each whole hour.
This means that at any moment, the hour hand points to one of the numbers 01, 02, 03, ..., 11, and 12.
Additionally, at any moment, the minute hand also points to one of those numbers, but we interpret them as minutes: :05, :10, :15, ..., :55, and :00.

The time machine behaves in a peculiar way: when activated, it jumps to such a time that the two hands on the clock switch positions.
For example, suppose the current time is 11:20.
On the clock, the hour hand points to 11 and the minute hand points to 04 (that represents :20).
As Elly activated the time machine, the hands switched positions: now the hour hand points to 04 and the minute hand points to 11.
Thus, the time machine jumped to the time 04:55. See the sample test cases for other examples of how the time machine works.

You are given the current time in the string time in the format "HH:MM", where HH are the hours (a two-digit number between 01 and 12, inclusive), and MM are the minutes (a two-digit number between 00 and 55, inclusive).
Compute the new time after the time machine is activated.
Return that time in the same format.


DEFINITION
Class:EllysTimeMachine
Method:getTime
Parameters:string
Returns:string
Method signature:string getTime(string time)


NOTES
-Please note that the required time formatting always requires two digits both for the hour and the minutes (i.e. the numbers are padded with leading zeroes when needed).


CONSTRAINTS
-time will contain exactly 5 characters and will be formatted as "HH:MM".
-HH will be one of {01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11, 12}.
-MM will be one of {00, 05, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55}.


EXAMPLES

0)
"11:20"

Returns: "04:55"

The example from the problem statement.


1)
"02:25"

Returns: "05:10"


2)
"06:30"

Returns: "06:30"


3)
"05:55"

Returns: "11:25"


4)
"03:45"

Returns: "09:15"


5)
"01:00"

Returns: "12:05"

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

class EllysTimeMachine {
public:
	string getTime(string time) {
		const char *a[] = { "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12" };
		const char *b[] = { "05", "10", "15", "20", "25", "30", "35", "40", "45", "50", "55", "00" };
		string x = time.substr(0, 2);
		string y = time.substr(3, 2);
		string ans;
		for (int i = 0; i < 12; ++i) {
			if (y.compare(b[i]) == 0) {
				ans += a[i];
				break;
			}
		}
		ans += ":";
		for (int i = 0; i < 12; ++i) {
			if (x.compare(a[i]) == 0) {
				ans += b[i];
				break;
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
			string Arg0 = "11:20";
			string Arg1 = "04:55";

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "02:25";
			string Arg1 = "05:10";

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "06:30";
			string Arg1 = "06:30";

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "05:55";
			string Arg1 = "11:25";

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "03:45";
			string Arg1 = "09:15";

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "01:00";
			string Arg1 = "12:05";

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysTimeMachine ___test;
	___test.run_test(-1);
}
// END CUT HERE
