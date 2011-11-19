// BEGIN CUT HERE
/*
// SRM 511 Div2 Easy (250)

問題

'0'と'1'のセルが円環状に並んでいるライフゲーム。
自分と両隣のセルの多数決で次の状態が決まる。
Tターン後の状態を求める。


#line 89 "GameOfLifeDivTwo.cpp"
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

class GameOfLifeDivTwo {
	public:
	string theSimulation(string init, int T) {
		char A[64] = {0};
		char B[64] = {0};
		char *r = A;
		char *w = B;
		strncpy(A, init.c_str(), 60);
		int length = (int)init.length();
		int m = length - 1;
		while (--T >= 0) {
			char *_w = w;
			int i;
			for (i = 0; i < length; ++i) {
				char d = (i == 0) ? r[length - 1] : r[i - 1];
				char e = r[i];
				char f = (i == m) ? r[0] : r[i + 1];
				char g = (d - '0') + (e - '0') + (f - '0');
				*w++ = '0' + (g / 2);
			}
			w = r;
			r = _w;
		}
		return r;
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

static void Test(const char *seq, int T, const char *expected)
{
	vector <int> v = getVector<int>(seq);
	GameOfLifeDivTwo ___test;
	string result = ___test.theSimulation(seq, T);
	printf("result: %s, %s\n", strcmp(result.c_str(), expected) == 0 ? "OK" : "FAILED", result.c_str());
}

int main() {
	// example 0
	Test("01010", 2, "00000");

	// example 1
	Test("010101", 5, "101010");

	// example 2
	Test("111010", 58, "111111");

	// example 3
	Test("111111111", 511, "111111111");

	// example 4
	Test("110010000010111110010100001001", 1000, "110000000001111110000000000001");

	// example 5
	Test("00101110011", 0, "00101110011");

	return 0;
}
// END CUT HERE
