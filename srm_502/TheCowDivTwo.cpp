// BEGIN CUT HERE
/*
// SRM 502 Div2 Hard (1000)

問題
  0 から N-1 までの番号がついたN匹がいて、K匹逃げた。
  牛の番号の合計値が N で割り切れるとき、牛の番号の組み合わせの数を求める。

制約条件
  1 <= N <= 1000
  1 <= K <= 47
  K <= N

#line 67 "TheCowDivTwo.cpp"
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

class TheCowDivTwo {

public:
	int find(int N, int K) {
		const int M = 1000000007;
		LL dp[48][1001] = {0};
		int i, j, k;
		dp[0][0] = 1;
		for (i = 0; i < N; ++i) {
			LL prev[48][1001];
			memcpy(prev, dp, sizeof(dp));
			for (j = 1; j <= K; ++j) {
				for (k = 0; k < N; ++k) {
					// j匹つかって余りがk
					dp[j][k] += prev[j - 1][(k - i + N) % N];
					dp[j][k] %= M;
				}
			}
		}

		return (int)dp[K][0];
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

static void Test(int N, int K, int expected)
{
	TheCowDivTwo ___test;
	int result = ___test.find(N, K);
	printf("result: %s, returned %d, expected %d\n", result == expected ? "OK" : "FAILED", result, expected);
}

int main() {
	// example 0
	Test(7, 4, 5);

	// example 1
	Test(1, 1, 1);

	// example 2
	Test(58, 4, 7322);

	// example 3
	Test(502, 7, 704466492);

	// example 4
	Test(1000, 47, 219736903);

	return 0;
}
// END CUT HERE
