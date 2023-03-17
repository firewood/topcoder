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

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> A, std::vector<int64_t> C, std::vector<int64_t> X) {
	vector<int64_t> dp(N + 1, INF);
	dp[0] = 0;
	int xi = 0;
	for (int i = 0; i < N; ++i) {
		vector<int64_t> next(N + 1, INF);
		int64_t c = INF;
		if (xi < M && X[xi] == i) {
			for (int j = 0; j <= i; ++j) {
				c = min(c, C[i - j]);
				next[j + 1] = dp[j] + A[i] + c;
			}
			++xi;
		} else {
			next = dp;
			for (int j = 0; j <= i; ++j) {
				c = min(c, C[i - j]);
				next[j + 1] = min(next[j + 1], dp[j] + A[i] + c);
			}
		}
		dp = next;
	}
	return *min_element(dp.begin(), dp.end());
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<int64_t> C(N);
	for (int i = 0; i < N; i++) {
		std::cin >> C[i];
	}
	std::vector<int64_t> X(M);
	for (int i = 0; i < M; i++) {
		std::cin >> X[i];
		--X[i];
	}
	cout << solve(N, M, A, C, X) << endl;
	return 0;
}
