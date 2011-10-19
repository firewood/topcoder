// BEGIN CUT HERE
/*
// SRM 520 Div2 Hard (1000)
// PROBLEM STATEMENT
// Mr. Dengklek introduced you to an online programming contest called SRM (Special Round Match)!

You are now in the system test phase of the contest. There were N coders in the contest. There were 3 problems in the contest. The system has tested all submitted solutions in the contest. For each submitted solution, there are 3 possible outcomes: 'passed', 'failed', and 'challenged'.

The contest has a division summary containing a scoreboard of all coders in the contest. For each coder, the scoreboard shows the outcome of the submitted solution of each problem, or an 'X' if the coder didn't submit a solution to the problem. The coders in the scoreboard are sorted in descending order of the number of passed solutions. If there is a tie, then they are sorted in ascending order of the number of challenged solutions. If there is still a tie, the scoreboard may show them in arbitrary order.

Unfortunately, you lose your internet connection in this system test phase. So, you ask your friend how the scoreboard is currently like. However, your friend only tells you the solutions submitted by each coder. This is given in description. The j-th character of the i-th element of description will be 'Y' if the i-th coder submitted a solution to the j-th problem, or 'N' otherwise. description describes the scoreboard from top to bottom, i.e., description[0] describes the coder in the first position, description[1] (if any) describes the coder in the second position, and so on.

Return the number of different possible scoreboards that match your friend's description, modulo 1,000,000,007.

DEFINITION
Class:SRMSystemTestPhase
Method:countWays
Parameters:vector <string>
Returns:int
Method signature:int countWays(vector <string> description)


CONSTRAINTS
-description will contain between 1 and 50 elements, inclusive.
-Each element of description will contain exactly 3 characters.
-Each character in description will be 'Y' or 'N'.


EXAMPLES

0)
{"YYY"}

Returns: 27

There are 3 possible outcomes for each solution, so there are 3^3 = 27 different possible scoreboards.

1)
{"YNN",
 "NYN"}

Returns: 6

Here are the 6 different scoreboards:


+----------------------------------+----------------------------------+
| passed     X          X          | passed     X          X          |
| X          passed     X          | X          failed     X          |
+----------------------------------+----------------------------------+
| passed     X          X          | failed     X          X          |
| X          challenged X          | X          failed     X          |
+----------------------------------+----------------------------------+
| failed     X          X          | challenged X          X          |
| X          challenged X          | X          challenged X          |
+----------------------------------+----------------------------------+


2)
{"YNN",
 "NNN",
 "NNY"}

Returns: 4

Here are the 4 different scoreboards:


+----------------------------------+----------------------------------+
| passed     X          X          | passed     X          X          |
| X          X          X          | X          X          X          |
| X          X          failed     | X          X          challenged |
+----------------------------------+----------------------------------+
| failed     X          X          | failed     X          X          |
| X          X          X          | X          X          X          |
| X          X          failed     | X          X          challenged |
+----------------------------------+----------------------------------+


3)
{"NNN",
 "NNN"}

Returns: 1



4)
{"YYY",
 "YNY",
 "NYY",
 "YYN",
 "YYY",
 "YNN"}

Returns: 15176



#line 101 "SRMSystemTestPhase.cpp"
*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

class SRMSystemTestPhase {

public:
	int countWays(vector <string> description) {
		int result = 0;


		return result;
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

static void Test(const char *seq, int expected)
{
	vector <string> v = getVector<string>(seq);
	SRMSystemTestPhase ___test;
	int result = ___test.countWays(v);
	printf("result: %s, returned %d, expected %d\n", result == expected ? "OK" : "FAILED", result, expected);
}

int main() {
	// example 0
	Test("YYY", 27);

	// example 1
	Test("YNN,NYN", 6);

	// example 2
	Test("YNN,NNN,NNY", 4);

	// example 3
	Test("NNN,NNN", 1);

	// example 4
	Test("YYY,YNY,NYY,YYN,YYY,YNN", 15176);

	return 0;
}
// END CUT HERE
