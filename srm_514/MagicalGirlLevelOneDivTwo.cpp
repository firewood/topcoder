// BEGIN CUT HERE
/*
// SRM 514 Div2 Easy (250)
// PROBLEM STATEMENT
// Magical Girls are girls who have magical powers. They fight against evil witches to protect the Earth.

You, one of the Magical Girls, are now at point (0, 0) on the plane. You found an evil witch at point (x, y), so you will attack her by Attack Magic.

The range of your Attack Magic is a square with side length 2d centered at your location. That is, if you are at point (u, v), the square which indicates the range of your magic has four vertices (u+d, v+d), (u-d, v+d), (u-d, v-d) and (u+d, v-d).

Before casting Attack Magic, you may move to any point in the plane. Return the minimum distance you have to move so that the evil witch is inside or on the edge of the square.

DEFINITION
Class:MagicalGirlLevelOneDivTwo
Method:theMinDistance
Parameters:int, int, int
Returns:double
Method signature:double theMinDistance(int d, int x, int y)


NOTES
-The distance between two points (x1, y1) and (x2, y2) is sqrt((x2-x1)^2 + (y2-y1)^2).
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-d will be between 1 and 500, inclusive.
-x and y will each be between -500 and 500, inclusive.


EXAMPLES

0)
5
10
10

Returns: 7.0710678118654755

Moving to (5, 5) achieves the minimum distance. The distance is sqrt(5*5 + 5*5) = 7.0710678118654755.

1)
5
10
3

Returns: 5.0

Moving to (5, 0) achieves the minimum distance. The distance is sqrt(5*5 + 0*0) = 5.

2)
5
-8
-6

Returns: 3.1622776601683795



3)
5
3
2

Returns: 0.0

The evil witch is already inside of the square.

4)
24
24
-24

Returns: 0.0



5)
345
-471
333

Returns: 126.0



#line 88 "MagicalGirlLevelOneDivTwo.cpp"
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

class MagicalGirlLevelOneDivTwo {
	public:
	double theMinDistance(int d, int x, int y) {
		double xx = max(0, abs(x) - d);
		double yy = max(0, abs(y) - d);
		return sqrt(xx * xx + yy * yy);
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

static void Test(int d, int x, int y, double expected)
{
	MagicalGirlLevelOneDivTwo ___test;
	double result = ___test.theMinDistance(d, x, y);
	printf("result: %s, %f\n", fabs(result - expected) < 0.00000001 ? "OK" : "FAILED", result);
}

int main() {
	Test(5, 10, 10, 7.0710678118654755);
	return 0;
}
// END CUT HERE
