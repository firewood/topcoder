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

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> X, std::vector<int64_t> C, std::vector<int64_t> Y) {
	vector<int64_t> bonus(N + 1);
	for (int i = 0; i < M; ++i) {
		bonus[C[i]] = Y[i];
	}
	vector<int64_t> dp(5002, -1);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		vector<int64_t> next(5002, -1);
		next[0] = *max_element(dp.begin(), dp.end());
		for (int j = 0; j <= i; ++j) {
			next[j + 1] = dp[j] + X[i] + bonus[j + 1];
		}
		dp = next;
	}
	return *max_element(dp.begin(), dp.end());
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> X(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i];
	}
	std::vector<int64_t> C(M), Y(M);
	for (int i = 0; i < M; i++) {
		std::cin >> C[i] >> Y[i];
	}
	cout << solve(N, M, X, C, Y) << endl;
	return 0;
}
