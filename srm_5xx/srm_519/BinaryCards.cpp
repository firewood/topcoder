// BEGIN CUT HERE
/*
// SRM 519 Div2 Hard (900)

問題

0から63まで番号のついた64枚のカードがある。
番号xのカードは、片面に2^x個のドットが描かれている。
ドット数の総和がAからBまで、1ずつ増加する様子が見えるように
最小の手順でめくっていく。
ZからZ+1に遷移させるとき、複数のカードをめくる必要がある場合には
最大のカードからめくることとする。
途中経過で見える最大の和を答える。

#line 92 "BinaryCards.cpp"
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

typedef long long LL;
typedef unsigned long long ULL;

class BinaryCards {
	public:
	long long largestNumber(long long A, long long B) {
		ULL M;
		for (M = 1LL << 63; M > 0; M >>= 1) {
			if ((B & M) == 0) {
				continue;
			}
			if ((A & M) == (B & M)) {
				continue;
			}
			A |= (M << 1) - 1;
		}
		return A;
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

static void Test(LL a, LL b, LL expected)
{
	BinaryCards ___test;
	long long result = ___test.largestNumber(a, b);
	printf("result: %s, returned %lld, expected %lld\n", result == expected ? "OK" : "FAILED", result, expected);
}

int main() {
	// example 0
	Test(6, 6, 6);

	// example 1
	Test(6, 7, 7);

	// example 2
	Test(6, 8, 15);

	// example 3
	Test(1, 11, 15);

	// example 4
	Test(35, 38, 39);

	// example 5
	Test(1125899906842630, 1125899906842632, 1125899906842639);

	return 0;
}
// END CUT HERE
