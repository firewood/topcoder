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

int64_t solve(int64_t L, std::vector<int64_t> A) {
	vector<int64_t> dp(5, INF);
	dp[0] = 0;
	for (int i = 0; i < L; ++i) {
		auto cost = [&](int s) -> int64_t {
			if (s == 0 || s == 4) {
				return A[i];
			}
			if (s == 1 || s == 3) {
				if (A[i] > 0) {
					return A[i] % 2;
				}
				return 2;
			}
			return (A[i] % 2) == 0;
		};
		vector<int64_t> next(5, INF);
		for (int j = 0; j < 5; ++j) {
			for (int k = j; k < 5; ++k) {
				next[k] = min(next[k], dp[j] + cost(k));
			}
		}
		dp = next;
	}
	return *min_element(dp.begin(), dp.end());
}

int main() {
	int64_t L;
	std::cin >> L;
	std::vector<int64_t> A(L);
	for (int i = 0; i < L; i++) {
		std::cin >> A[i];
	}
	cout << solve(L, A) << endl;
	return 0;
}
