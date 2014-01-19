// BEGIN CUT HERE
/*
// SRM 509 Div2 Medium (500)

問題

n個の数値が与えられる。
その数を組み合わせてできる全ての数の合計を9で割った余りを求める。


#line 61 "LuckyRemainder.cpp"
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

class LuckyRemainder {
	public:
	int getLuckyRemainder(string X) {
		int r = 0;
		size_t length = X.length();
		size_t i;
		for (i = 0; i < length; ++i) {
			r += X[i] - '0';
		}
		for (i = 1; i < length; ++i) {
			r = (r * 2) % 9;
		}
		return r % 9;
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
	LuckyRemainder ___test;
	int result = ___test.getLuckyRemainder(seq);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	// example 0
	Test("123", 6);

	// example 1
	Test("24816", 3);

	// example 2
	Test("8", 8);

	// example 3
	Test("11235813213455", 7);

	return 0;
}
// END CUT HERE
