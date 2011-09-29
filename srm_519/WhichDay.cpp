// BEGIN CUT HERE
/*
// SRM 519 Div2 Easy (250)
// PROBLEM STATEMENT
// This week there will be an important meeting of your entire department.
You clearly remember your boss telling you about it.
The only thing you forgot is the day of the week when the meeting will take place.

You asked six of your colleagues about the meeting. None of them knew the day when it will take place,
but each of them remembered one day when it will not take place.
The days they remembered were distinct. For a clever programmer like you,
this was enough to determine the day of the meeting.

You are given a vector <string> notOnThisDay containing six weekdays when the meeting will not take place.
Return the weekday of the meeting.

DEFINITION
Class:WhichDay
Method:getDay
Parameters:vector <string>
Returns:string
Method signature:string getDay(vector <string> notOnThisDay)


NOTES
-There are seven weekdays.
 Their names are: "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday".


CONSTRAINTS
-notOnThisDay will contain exactly 6 elements.
-Each element of notOnThisDay will be a name of a weekday (in the exact form specified in the Note above).
-No two elements of notOnThisDay will be equal.


EXAMPLES

0)
{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"}

Returns: "Saturday"



1)
{"Sunday", "Monday", "Tuesday", "Wednesday", "Friday", "Thursday"}

Returns: "Saturday"



2)
{"Sunday", "Monday", "Tuesday", "Thursday", "Friday", "Saturday"}

Returns: "Wednesday"



3)
{"Sunday", "Friday", "Tuesday", "Wednesday", "Monday", "Saturday"}

Returns: "Thursday"



#line 60 "WhichDay.cpp"
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

typedef map<string, int> StringIntMap;
typedef vector<string> StringVector;

class WhichDay {
	public:
	string getDay(vector <string> notOnThisDay) {
		StringIntMap M;
		M["Sunday"] = 0;
		M["Monday"] = 0;
		M["Tuesday"] = 0;
		M["Wednesday"] = 0;
		M["Thursday"] = 0;
		M["Friday"] = 0;
		M["Saturday"] = 0;
		StringVector::const_iterator it;
		for (it = notOnThisDay.begin(); it != notOnThisDay.end(); ++it) {
			M[*it] = 1;
		}
		StringIntMap::const_iterator s;
		for (s = M.begin(); s != M.end(); ++s) {
			if (s->second == 0) {
				return s->first;
			}
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

static void Test(const char *seq, const string &expected)
{
	vector <string> v = getVector<string>(seq);
	WhichDay ___test;
	string result = ___test.getDay(v);
	printf("result: %s, %s\n", result == expected ? "OK" : "FAILED", result.c_str());
}

int main() {
	Test("Sunday Monday Tuesday Wednesday Thursday Friday", "Saturday");
	Test("Sunday Monday Tuesday Wednesday Friday Thursday", "Saturday");
	Test("Sunday Monday Tuesday Thursday Friday Saturday", "Wednesday");
	Test("Sunday Friday Tuesday Wednesday Monday Saturday", "Thursday");
	return 0;
}
// END CUT HERE
