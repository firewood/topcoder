// BEGIN CUT HERE
/*
// SRM 514 Div2 Easy (250)

問題

魔法少女が座標 (0, 0) にいる。
魔法少女は長さ d の正方形の範囲に魔法を発動できる。
座標 (x, y) にいる魔女を倒すための最小移動距離を求める。


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
	// example 0
	Test(5, 10, 10, 7.0710678118654755);

	// example 1
	Test(5, 10, 3, 5.0);

	// example 2
	Test(5, -8, -6, 3.1622776601683795);

	// example 3
	Test(5, 3, 2, 0.0);

	// example 4
	Test(24, 24, -24, 0.0);

	// example 5
	Test(345, -471, 333, 126.0);

	return 0;
}
// END CUT HERE
