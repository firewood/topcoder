// BEGIN CUT HERE
/*
// SRM 515 Div2 Middle (500)
// PROBLEM STATEMENT
// Lecette has a clock with an hour hand and a minute hand. 
The hour hand makes a full rotation in 12 hours, and the minute hand makes a full rotation in one hour. 
Both hands move smoothly, at constant speeds. 
The clock has a scale marked in 30 degree increments, and both hands point to the same mark at 00:00. 

Lecette wants to know what time it is, but the clock is rotated, so she can't tell where the top of the clock is. 
She measured the angles of hands from a certain mark, clockwise: 
hourHand and minuteHand (both in degrees). 
Return the earliest possible time that is consistent with these measurements. 
Format the return value as a string of the form "HH:MM" (quotes for clarity). 
Lecette might have measured the angles incorrectly. 
If there is no corresponding time, return an empty string instead. 


DEFINITION
Class:RotatedClock
Method:getEarliest
Parameters:int, int
Returns:string
Method signature:string getEarliest(int hourHand, int minuteHand)


CONSTRAINTS
-hourHand and minuteHand will each be between 0 and 359, inclusive. 


EXAMPLES

0)
70
300

Returns: "08:20"

This is how the clock were positioned when Lecette made her measurements: 



In order to show a valid time, the clock needs to be turned upside down: 




1)
90
120

Returns: "11:00"

2)
240
36

Returns: ""

3)
19
19

Returns: ""

4)
1
12

Returns: "00:02"

The time when the coding phase started. 


#line 76 "RotatedClock.cpp"
*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

class RotatedClock {
	public:
	string getEarliest(int hourHand, int minuteHand) {
		while (hourHand >= 30) {
			hourHand -= 30;
			minuteHand += 360 - 30;
		}

		int a;
		for (a = 0; a < 360; a += 30) {
			int h = (hourHand + a) % 360;
			int m = (minuteHand + a) % 360;
			int hm = (h % 30) * 12;
			if (hm != m) {
				continue;
			}
			char buff[16];
			sprintf(buff, "%02d:%02d", h / 30, m / 6);
			string s = buff;
			return s;
		}

		return "";
	}
};

// BEGIN CUT HERE
template <typename T> static T __str_to_val(const char *p)
{
	return p;
}
template <> static int __str_to_val(const char *p)
{
	return atoi(p);
}
template <typename T> vector<T> getVector(const char *s)
{
	static const int buffer_size = 1024000;
	static char buffer[buffer_size];
	strcpy(buffer, s);
	vector <T> v;
	char *p = strtok(buffer, " ,");
	while (p) {
		v.push_back(__str_to_val<T>(p));
		p = strtok(NULL, " ,");
	}
	return v;
}

static void Test(int h, int m, const char *expected)
{
	RotatedClock ___test;
	string result = ___test.getEarliest(h, m);
	printf("result: %s, %s\n", strcmp(result.c_str(), expected) == 0 ? "OK" : "FAILED", result.c_str());
}

int main() {
	Test(70, 300, "08:20");
	Test(90, 120, "11:00");
	Test(240, 36, "");
	Test(19, 19, "");
	Test(1, 12, "00:02");
	return 0;
}
// END CUT HERE
