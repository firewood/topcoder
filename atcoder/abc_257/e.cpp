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

string solve(int64_t N, std::vector<int64_t> C) {
	string ans;
#if 0
	vector<vector< int64_t>> dp(N + 1);
	vector<int64_t> mx(10);
	dp[0] = mx;
	for (int64_t i = 0; i <= N; ++i) {
		if (dp[i].empty()) continue;
		for (int j = 1; j <= 9; ++j) {
			int p = i + C[j];
			if (p <= N) {
				vector< int64_t> a = dp[i];
				a[0] += 1;
				a[10 - j] += 1;
				if (dp[p].empty() || dp[p] < a) {
					dp[p] = a;
				}
			}
		}
		mx = max(mx, dp[i]);
	}
	for (int j = 9; j >= 1; --j) {
		ans += string(mx[10 - j], char('0' + j));
	}
#else
	int64_t min_cost = *min_element(C.begin() + 1, C.end()), digits = N / min_cost;
	while (digits > 0) {
		--digits;
		int64_t r = N - digits * min_cost;
		for (int i = 9; i >= 1; --i) {
			if (r >= C[i]) {
				ans += char('0' + i);
				N -= C[i];
				break;
			}
		}
	}
#endif
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> C(10);
	for (int i = 1; i < 10; i++) {
		std::cin >> C[i];
	}
	cout << solve(N, C) << endl;
	return 0;
}
