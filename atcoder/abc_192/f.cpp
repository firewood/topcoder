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

static const LL INF = 1LL << 60;

LL solve(long long N, long long X, std::vector<long long> &A) {
	LL ans = INF;
	for (LL m = 1; m <= A.size(); ++m) {
		vector<vector<LL>> dp(N + 1, vector<LL>(N + 1, -1));
		dp[0][0] = 0;
		for (LL i = 0; i < N; ++i) {
			vector<vector<LL>> next = dp;
			for (LL j = 0; j < N; ++j) {
				for (LL k = 0; k < m; ++k) {
					LL l = (k + A[i]) % m;
					if (dp[j][k] >= 0) {
						next[j + 1][l] = max(next[j + 1][l], dp[j][k] + A[i]);
					}
				}
			}
			dp = next;
		}
		if (dp[m][X % m] >= 0) {
			ans = min(ans, (X - dp[m][X % m]) / m);
		}
	}
	return ans;
}

int main() {
    long long N, X;
	std::cin >> N >> X;
	std::vector<long long> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, X, A) << endl;
	return 0;
}
