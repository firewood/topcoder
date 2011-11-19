// BEGIN CUT HERE
/*
// SRM 514 Div2 Medium (500)

問題

魔法少女が座標 (0, 0) にいる。
魔法少女は (0, 0) から、(±n, ±1) または (±1, ±n) だけ移動できる。
座標 (x, y) に到達可能かどうかを求める。


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
	// example 0
	Test("2", 5, 4, "YES");

	// example 1
	Test("3", 5, 4, "NO");

	// example 2
	Test("1,2,3,4,5,6,7,8,9,10", -30, 27, "YES");

	// example 3
	Test("29", 29, 0, "NO");

	Test("21,23,25,27,29", -30, 29, "NO");

	return 0;
}
// END CUT HERE
