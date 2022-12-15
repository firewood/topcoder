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

int64_t solve(int64_t N, int64_t K, int64_t D, std::vector<int64_t> a) {
	vector<vector<int64_t>> dp(N + 1, vector<int64_t>(D, -1));
	dp[0][0] = 0;
	for (int i = 0; i < N; ++i) {
		vector<vector<int64_t>> next = dp;
		for (int j = 0; j <= i; ++j) {
			for (int k = 0; k < D; ++k) {
				if (dp[j][k] >= 0) {
					int64_t x = dp[j][k] + a[i];
					next[j + 1][x % D] = max(next[j + 1][x % D], x);
				}
			}
		}
		dp = next;
	}
	return dp[K][0];
}

int main() {
	int64_t N, K, D;
	std::cin >> N >> K >> D;
	std::vector<int64_t> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	cout << solve(N, K, D, a) << endl;
	return 0;
}
