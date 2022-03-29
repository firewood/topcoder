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

int64_t solve(int64_t N, std::vector<int64_t> A, std::vector<int64_t> B) {
	auto loop = [&](vector<int64_t> dp) {
		for (int i = 1; i < N; ++i) {
			dp = {
				A[i] + min(dp[0] + B[i - 1], dp[1]),
				min(dp[0], dp[1] + B[i - 1])
			};
		}
		return dp;
	};
	vector<int64_t> a = loop({ A[0], INF });
	vector<int64_t> b = loop({ INF, 0 });
	return min({ a[0] + B.back(), a[1], b[0], b[1] + B.back() });
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<int64_t> B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}
	cout << solve(N, A, B) << endl;
	return 0;
}
