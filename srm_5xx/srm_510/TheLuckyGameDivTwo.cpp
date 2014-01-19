// BEGIN CUT HERE
/*
// SRM 510 Div2 Medium (500)

問題

4と7がラッキーである。
4と7だけでできた数値をラッキーナンバーとする。
John と Brus がaからbまでの数値でゲームをする。
まず John が連続するjLen個の数値を選ぶ。
次に Brus が、そのjLen個の数値からbLen個の数値を選ぶ。
Brus が選んだ数値の中のラッキーナンバーの個数がゲームの得点となる。
最大化戦略での得点を求める。


#line 81 "TheLuckyGameDivTwo.cpp"
*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;

typedef map<int, int> IntMap;

class TheLuckyGameDivTwo {
	static bool isLucky(int n) {
		while (n > 0) {
			int x = n % 10;
			if (x != 4 && x != 7) {
				return false;
			}
			n /= 10;
		}
		return true;
	}

public:
	int find(int a, int b, int jLen, int bLen) {
		int result = 0;
		IntMap Brus;
		int j;
		int jm = b - jLen + 1;
		for (j = a; j <= jm; ++j) {
			int BrusScore = 9999;
			int k;
			int km = j + jLen - bLen;
			for (k = j; k <= km; ++k) {
				IntMap::const_iterator bf = Brus.find(k);
				if (bf == Brus.end()) {
					// not calculated yet
					int bs = 0;
					int l;
					int lm = k + bLen - 1;
					for (l = k; l <= lm; ++l) {
						bs += isLucky(l);
					}
					Brus[k] = bs;
					BrusScore = min(BrusScore, bs);
				} else {
					BrusScore = min(BrusScore, bf->second);
				}
			}
			result = max(result, BrusScore);
		}
		return result;
	}
};

// BEGIN CUT HERE
static void Test(int a, int b, int jLen, int bLen, int expected)
{
	TheLuckyGameDivTwo ___test;
	int result = ___test.find(a, b, jLen, bLen);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	// example 0
	Test(1, 10, 2, 1, 0);

	// example 1
	Test(1, 100, 100, 100, 6);

	// example 2
	Test(4,8,3,2,1);

	// example 3
	Test(1,100,75,50,2);

	return 0;
}
// END CUT HERE
