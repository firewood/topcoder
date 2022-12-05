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

static const int MAX_N = 1000000;

bool is_small(int64_t x) {
	while (x > 0) {
		if ((x % 10) >= 5) {
			return false;
		}
		x /= 10;
	}
	return true;
}

int64_t solve(int64_t N, std::vector<int64_t> A) {
	int64_t ans = 0, b = 1;
	vector<int64_t> dp(MAX_N);
	for (int i = 0; i < N; ++i) {
		dp[A[i]] += 1;
	}
	for (int d = 0; d < 6; ++d) {
		for (int i = 0; i < MAX_N; ++i) {
			int j = (i / b) % 10;
			if (j < 9) {
				dp[i + b] += dp[i];
			}
		}
		b *= 10;
	}
	for (int i = 0; i < N; ++i) {
		ans += dp[MAX_N - A[i] - 1];
		ans -= is_small(A[i]);
	}
	return ans / 2;
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
