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

int64_t solve(int64_t N, std::vector<int64_t> A) {
	vector<int64_t> dp = { 0, INF, INF, A[0] };
	for (int i = 1; i < N; ++i) {
		dp = {
				dp[1],
				min(dp[0], dp[1]) + A[i],
				dp[3],
				min(dp[2], dp[3]) + A[i]
		};
	}
	return *min_element(dp.begin() + 1, dp.end());
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
