// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	LL N, A, dp[51][5000] = {};
	cin >> N >> A;
	dp[0][2500] = 1;
	for (int i = 0; i < N; ++i) {
		LL x;
		cin >> x;
		memcpy(dp + i + 1, dp + i, sizeof(dp[0]));
		for (int j = 0; j < 5000; ++j) {
			int k = j - x + A;
			if (k >= 0 && k < 5000 && dp[i][k]) {
				dp[i + 1][j] += dp[i][k];
			}
		}
	}
	cout << dp[N][2500] - 1 << endl;
	return 0;
}
