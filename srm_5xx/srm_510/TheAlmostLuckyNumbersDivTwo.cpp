// BEGIN CUT HERE
/*
// SRM 510 Div2 Easy (250)

問題

4と7がラッキーナンバーである。
ラッキーナンバーでない数値が高々1つであるような数を「ほぼラッキー数」とする。
aとbの間の「ほぼラッキー数」の数を求める。


#line 60 "TheAlmostLuckyNumbersDivTwo.cpp"
*/
// END CUT HERE
#include <stdio.h>

class TheAlmostLuckyNumbersDivTwo {
	static bool isLucky(int n) {
		if (n < 10) {
			return true;
		}
		int c = 0;
		while (n > 0) {
			int x = n % 10;
			if (x != 4 && x != 7) {
				++c;
				if (c >= 2) {
					return false;
				}
			}
			n /= 10;
		}
		return true;
	}

public:
	int find(int a, int b) {
		int result = 0;
		for (; a <= b; ++a) {
			if (isLucky(a)) {
				++result;
			}
		}
		return result;
	}
};

// BEGIN CUT HERE
static void Test(int a, int b, int expected)
{
	TheAlmostLuckyNumbersDivTwo ___test;
	int result = ___test.find(a, b);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	// example 0
	Test(4, 7, 4);

	// example 1
	Test(8, 19, 4);

	// example 2
	Test(28, 33, 0);

	// example 3
	Test(1234, 4321, 36);

	return 0;
}
// END CUT HERE
