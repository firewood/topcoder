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

int64_t solve(int H, int W, std::vector<string> c) {
	int ans = 0;
	vector<int> dp(W);
	for (int i = 0; i < H; ++i) {
		vector<int> next(W);
		for (int j = 0; j < W; ++j) {
			if (c[i][j] == '.') {
				if (i == 0 && j == 0) {
					next[j] = 1;
				}
				if (j > 0 && next[j - 1] > 0) {
					next[j] = max(next[j], next[j - 1] + 1);
				}
				if (i > 0 && dp[j] > 0) {
					next[j] = max(next[j], dp[j] + 1);
				}
				ans = max(ans, next[j]);
			}
		}
		dp = next;
	}
	return ans;
}

int main() {
	int H, W;
	std::cin >> H >> W;
	std::vector<string> c(H);
	for (int i = 0; i < H; i++) {
		std::cin >> c[i];
	}
	cout << solve(H, W, c) << endl;
	return 0;
}
