// BEGIN CUT HERE
/*
// SRM 510 Div2 Hard (1000)

問題
数Nが与えられる。
桁が4か7だけで表せるのがラッキーナンバーである。
NをB進数で表したとき、ラッキーナンバーになるBの総数を求める。

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

class TheLuckyBasesDivTwo {

public:
	long long find(long long n) {
		if (n == 4 || n == 7) {
			return -1;
		}
		LL result = 0;
		LL a, b, c, d;
		for (a = 4; a <= 7; a += 3) {
			c = n - a;
			if (c > 4) {
				result += ((c % 4) == 0 && (c / 4) > 4);
				result += ((c % 7) == 0 && (c / 7) > 7);
			}
		}
		for (b = 5; b*b <= n; ++b) {
			c = 0;
			d = n;
			while (d > b) {
				LL a = d % b;
				if (a != 4 && a != 7) {
					break;
				}
				++c;
				d /= b;
				if (d < b && (d == 4 || d == 7)) {
					result += c >= 2;
				}
			}
		}
		return result;
	}
};

// BEGIN CUT HERE
static void Test(LL n, LL expected)
{
	TheLuckyBasesDivTwo ___test;
	LL result = ___test.find(n);
	printf("result: %s, returned %lld, expected %lld\n", result == expected ? "OK" : "FAILED", result, expected);
}

int main() {

	// example 0
	Test(255, 1);

	// example 1
	Test(4, -1);

	// example 2
	Test(13, 0);

	// example 3
	Test(60, 2);

	Test(474747477747, 3);
	
	Test(5*4+4, 1);
	Test(25*4+5*4+4, 2);

	return 0;
}
// END CUT HERE
