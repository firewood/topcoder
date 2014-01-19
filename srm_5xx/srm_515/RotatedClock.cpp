// BEGIN CUT HERE
/*
// SRM 515 Div2 Medium (500)

問題

時計の短針の角度 hourHand と長針の角度 minuteHand が与えられる。
短針のマークが真上になっているが、12時のマークとは限らない。
短針と長針が正しい時刻を示しているなら、そのうちの最も早い時刻を返す。


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
	// example 0
	Test(70, 300, "08:20");

	// example 1
	Test(90, 120, "11:00");

	// example 2
	Test(240, 36, "");

	// example 3
	Test(19, 19, "");

	// example 4
	Test(1, 12, "00:02");

	return 0;
}
// END CUT HERE
