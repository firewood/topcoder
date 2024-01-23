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

int64_t solve(int64_t N) {
	int64_t ans = 0;
	string ns = to_string(N);
	for (int dsum = 1; dsum <= 9 * 14; ++dsum) {
		vector dp(dsum + 1, vector(dsum, vector(2, int64_t(0))));
		dp[0][0][1] = 1;
		for (int i = 0; i < ns.length(); ++i) {
			vector next(dsum + 1, vector(dsum, vector(2, int64_t(0))));
			int digit = ns[i] - '0';
			for (int j = 0; j <= dsum; ++j) {
				for (int d = 0; d <= 9; ++d) {
					if (j + d > dsum) break;
					for (int k = 0; k < dsum; ++k) {
						for (int f = 0; f < 2; ++f) {
							if (f && d > digit) continue;
							next[j + d][(k * 10 + d) % dsum][f && digit == d] += dp[j][k][f];
						}
					}
				}
			}
			dp = next;
		}
		ans += dp[dsum][0][0] + dp[dsum][0][1];
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
