// BEGIN CUT HERE
/*
// SRM 514 Div2 Middle (500)
// PROBLEM STATEMENT
// Magical Girls are girls who have magical powers. They fight against evil witches to protect the Earth.

You, one of the Magical Girls, are at point (0, 0) of the plane. You find another Magical Girl at (x, y) and she seems to be injured. So you decide to go to point (x, y) to help her.

You can move only by n-knight jump. For a positive integer n, the n-knight jump is 8 types of moves. You can go from (0, 0) to (n, 1), (n, -1), (-n, 1), (-n, -1), (1, n), (-1, n), (1, -n) or (-1, -n) by using n-knight jump once.

You are given a vector <int> jumpTypes containing the valid n-knight jumps you can perform. You can only use an n-knight jump if jumpTypes contains n. Return "YES" if you can reach (x, y) with the n-knight jumps of given numbers. Otherwise return "NO" (all quotes for clarity). You can use each n-knight jump as many times as you want.


DEFINITION
Class:MagicalGirlLevelTwoDivTwo
Method:isReachable
Parameters:vector <int>, int, int
Returns:string
Method signature:string isReachable(vector <int> jumpTypes, int x, int y)


CONSTRAINTS
-jumpTypes will contain between 1 and 10 elements, inclusive.
-Each element of jumpTypes will be between 1 and 30, inclusive.
-All elements of jumpTypes will be distinct.
-x and y will each be between -30 and 30, inclusive.


EXAMPLES

0)
{2}
5
4

Returns: "YES"

(0,?0)?->?(2,?1)?->?(4,?2)?->?(5,?4).

1)
{3}
5
4

Returns: "NO"



2)
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
-30
27

Returns: "YES"



3)
{29}
29
0

Returns: "NO"



#line 68 "MagicalGirlLevelTwoDivTwo.cpp"
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

typedef vector<int> VI;

class MagicalGirlLevelTwoDivTwo {
	public:
	string isReachable(vector <int> jumpTypes, int x, int y) {
		if (((x + y) % 2) == 0) {
			return "YES";
		}

		VI::const_iterator it;
		for (it = jumpTypes.begin(); it != jumpTypes.end(); ++it) {
			if ((*it % 2) == 0) {
				return "YES";
			}
		}

		return "NO";
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

static void Test(const char *seq, int x, int y, const char *expected)
{
	vector <int> v = getVector<int>(seq);
	MagicalGirlLevelTwoDivTwo ___test;
	string result = ___test.isReachable(v, x, y);
	printf("result: %s, %s\n", strcmp(result.c_str(), expected) == 0 ? "OK" : "FAILED", result.c_str());
}

int main() {
	Test("2", 5, 4, "YES");
	Test("3", 5, 4, "NO");
	Test("21,23,25,27,29", -30, 29, "NO");
	return 0;
}
// END CUT HERE
