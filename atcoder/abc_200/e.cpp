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

void solve(int64_t N, int64_t K) {
	vector<vector<int64_t>> dp(4, vector<int64_t>(3000002));
	dp[0][0] = 1;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j <= i * N; ++j) {
			dp[i + 1][j + 1] += dp[i][j];
			dp[i + 1][j + N + 1] -= dp[i][j];
		}
		for (int j = 0; j < (i + 1) * N; ++j) {
			dp[i + 1][j + 1] += dp[i + 1][j];
		}
	}
	int64_t ord = 0;
	for (int n = 3; ; ++n) {
		if (ord + dp[3][n] >= K) {
			for (int64_t a = max(int64_t(1), n - N * 2); a <= N; ++a) {
				int64_t low = max(int64_t(1), n - a - N), high = min(int64_t(N), n - a - 1);
				if (ord + high - low + 1 >= K) {
					int64_t b = max(int64_t(1), n - a - N) + (K - ord - 1);
					cout << a << " " << b << " " << (n - a - b) << endl;
					return;
				}
				ord += high - low + 1;
			}
		}
		ord += dp[3][n];
	}
}

int main() {
	int64_t N, K;
	std::cin >> N >> K;
	solve(N, K);
	return 0;
}
