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

int64_t solve2(int64_t N, int64_t C, std::vector<int64_t> x, std::vector<int64_t> v) {
	int64_t ans = 0, sum = 0, rsum = 0;
	vector<int64_t> dp(N + 1);
	for (int i = N - 1; i > 0; --i) {
		rsum += v[i];
		dp[i] = max(rsum - (C - x[i]) * 2, dp[i + 1]);
	}
	for (int i = 0; i < N; ++i) {
		sum += v[i];
		ans = max(ans, sum - x[i] + dp[i + 1]);
	}
	return ans;
}

int64_t solve(int64_t N, int64_t C, std::vector<int64_t> x, std::vector<int64_t> v) {
	vector<int64_t> rx(N), rv = v;
	for (int i = 0; i < N; ++i) {
		rx[i] = C - x[N - 1 - i];
	}
	reverse(rv.begin(), rv.end());
	return max(solve2(N, C, x, v), solve2(N, C, rx, rv));
}

int main() {
	int64_t N, C;
	std::cin >> N >> C;
	std::vector<int64_t> x(N), v(N);
	for (int i = 0; i < N; i++) {
		std::cin >> x[i] >> v[i];
	}
	cout << solve(N, C, x, v) << endl;
	return 0;
}
