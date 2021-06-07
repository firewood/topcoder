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
#include <bitset>

using namespace std;

int64_t solve(int64_t N, std::vector<int64_t> T) {
	int64_t sum = accumulate(T.begin(), T.end(), int64_t(0));
	vector<int> dp(100001);
	dp[0] = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 100000; j >= T[i]; --j) {
			if (dp[j - T[i]]) {
				dp[j] = 1;
			}
		}
	}
	int64_t ans = sum;
	for (int64_t i = 1; i < ans; ++i) {
		if (dp[i]) {
			ans = min(ans, max(i, sum - i));
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> T(N);
	for (int i = 0; i < N; i++) {
		std::cin >> T[i];
	}
	cout << solve(N, std::move(T)) << endl;
	return 0;
}
