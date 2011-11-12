// BEGIN CUT HERE
/*
// SRM 516 Div2 Easy (250)

問題

文字'o'か'x'からなる文字列messageをネットワーク上に送信した。
messageの任意の偶数の長さの部分文字列の'o'と'x'の個数は等しい。
ネットワークの障害により、いくつかの文字が'?'に化けた。
元の文字列を求めよ。


#line 65 "NetworkXZeroOne.cpp"
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

class NetworkXZeroOne {
	public:
	string reconstruct(string message) {
		char buffer[100];
		strcpy(buffer, message.c_str());
		int length = strlen(buffer);
		char *p = strpbrk(buffer, "ox");
		if (p == NULL) {
			return buffer;
		}
		int pos = p - buffer;
		int is_x = *p == 'x';
		if (pos & 1) {
			is_x = !is_x;
		}
		int i;
		for (i = 0; i < length; ++i) {
			buffer[i] = is_x ? 'x' : 'o';
			is_x = !is_x;
		}
		return buffer;
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
	NetworkXZeroOne ___test;
	string result = ___test.reconstruct(seq);
	printf("result: %s, returned %s, expected %s\n", result == expected ? "OK" : "FAILED", result.c_str(), expected.c_str());
}

int main() {
	// example 0
	Test("x?x?", "xoxo");

	// example 1
	Test("?xo?", "oxox");

	// example 2
	Test("xo", "xo");

	// example 3
	Test("o??x??o", "oxoxoxo");

	// example 4
	Test("???????x", "oxoxoxox");

	return 0;
}
// END CUT HERE
