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

static const int64_t INF = 1LL << 60;

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> A) {
	vector<int64_t> dp(N + 1, -INF);
	dp[0] = 0;
	for (int64_t i = 0; i < N; ++i) {
		vector<int64_t> next = dp;
		for (int64_t j = 0; j <= i && j < M; ++j) {
			next[j + 1] = max(next[j + 1], dp[j] + A[i] * (j + 1));
		}
		dp = next;
	}
	return dp[M];
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, M, A) << endl;
	return 0;
}
