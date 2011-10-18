// BEGIN CUT HERE
/*
// SRM 519 Div2 Easy (250)

問題

6つの曜日が与えられるので、残った1つを答える。

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
	// example 0
	Test("Sunday Monday Tuesday Wednesday Thursday Friday", "Saturday");

	// example 1
	Test("Sunday Monday Tuesday Wednesday Friday Thursday", "Saturday");

	// example 2
	Test("Sunday Monday Tuesday Thursday Friday Saturday", "Wednesday");

	// example 3
	Test("Sunday Friday Tuesday Wednesday Monday Saturday", "Thursday");

	return 0;
}
// END CUT HERE
