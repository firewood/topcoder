// BEGIN CUT HERE
/*
// SRM 504.5 Div2 Hard (1000)

問題

n人を一列に並ばせて、その中から一人だけ選ぶ。
一人しかいなければ選んで終了。
サイコロをふり、4が出たら先頭の一人を選んで終了。
奇数が出たら、先頭の一人を末尾に移動する。
偶数(2か6)が出たら、先頭の一人を取り除く。
k回の試行で誰も選ばれなければ、先頭の一人を選んで終了。
m番目の人が選ばれる確率を求める。

*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class TheTicketsDivTwo {

	double rec(int n, int m, int k) {
		if (n <= 1) {
			// only one person remains
			return 1.0;
		}
		if (k <= 0) {
			// exceeds maximum tries
			// first of the queue is chosen
			return m <= 0 ? 1.0 : 0.0;
		}

		// 4
		// chosen if on the first
		double res = m <= 0 ? 1.0 : 0;

		// odd (1,3,5)
		// rotation
		res += rec(n, (n + m - 1) % n, k - 1) * 3.0;

		// even (2,6)
		// remove
		if (m > 0) {
			res += rec(n - 1, m - 1, k - 1) * 2.0;
		}

		return res / 6.0;
	}

public:
	double find(int n, int m, int k) {
		return rec(n, m - 1, k);
	}
};

// BEGIN CUT HERE
static void Test(int n, int m, int k, double expected)
{
	TheTicketsDivTwo ___test;
	double result = ___test.find(n, m, k);
	printf("result: %s, returned %f, expected %f\n", fabs(result-expected)<=0.00000001 ? "OK" : "FAILED", result, expected);
}

int main() {
	// example 0
	Test(2, 1, 1, 0.16666666666666666);

	// example 1
	Test(2, 1, 2, 0.5833333333333334);

	// example 2
	Test(7, 7, 4, 0.0);

	// example 3
	Test(4, 2, 10, 0.25264033564814814);

	return 0;
}
// END CUT HERE
