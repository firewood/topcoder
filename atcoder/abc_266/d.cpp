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

int64_t solve(int64_t N, std::vector<int64_t> T, std::vector<int64_t> X, std::vector<int64_t> A) {
	int64_t ans = 0;
	vector<map<int64_t, int64_t>> dp(5);
	dp[0][0] = 0;
	for (int64_t i = 0; i < N; ++i) {
		int64_t t = T[i], x = X[i], a = A[i];
		if (t < x) continue;
		int64_t best = 0;
		for (int64_t j = 0; j < 5; ++j) {
			for (auto kv : dp[j]) {
				if (kv.first + abs(x - j) <= t) {
					best = max(best, a + kv.second);
				}
			}
		}
		dp[x][t] = best;
		if (dp[x].size() > 5) {
			dp[x].erase(dp[x].begin());
		}
	}
	for (int64_t j = 0; j < 5; ++j) {
		for (auto kv : dp[j]) {
			ans = max(ans, kv.second);
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> T(N), X(N), A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> T[i] >> X[i] >> A[i];
	}
	cout << solve(N, T, X, A) << endl;
	return 0;
}
