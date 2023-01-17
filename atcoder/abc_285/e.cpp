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

int64_t solve(int64_t N, std::vector<int64_t> A) {
	int64_t ans = 0;
	vector<int64_t> dp(N + 4);
	for (int k = 1; k < N; ++k) {
		int64_t sum = 0;
		for (int i = 0; i < k; ++i) {
			int m = min(i, k - i - 1);
			sum += A[m];
		}
		dp[k + 1] = sum;
	}
	for (int k = 4; k <= N; ++k) {
		for (int j = 2; j <= k - j; ++j) {
			dp[k] = max(dp[k], dp[j] + dp[k - j]);
		}
	}
	return dp[N];
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, A) << endl;
	return 0;
}
