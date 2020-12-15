#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

LL nCr(LL n, LL r) {
	if (n < r) {
		return 0;
	}
	LL x = 1;
	for (LL i = 0; i < r; ++i) {
		x *= (n - i);
		x /= (i + 1);
	}
	return x;
}

int nHr(int n, int r) {
	return nCr(n + r - 1, r);
}

void solve(long long L) {
/*
	LL dp[202][16] = {};
	dp[0][0] = 1;
	for (LL i = 1; i <= L; ++i) {
		for (LL j = 0; j < i; ++j) {
			for (LL k = 0; k <= 11; ++k) {
				dp[i][k + 1] += dp[j][k];
			}
		}
	}
	LL ans = dp[L][12];
*/
	LL ans = nCr(L - 1, 11);
	cout << ans << endl;
}

int main() {
	long long L;
	std::cin >> L;
	solve(L);
	return 0;
}
