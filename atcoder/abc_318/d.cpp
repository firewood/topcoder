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

int64_t solve(int64_t N, const vector<vector<int64_t>>& w) {
	vector<int64_t> dp(1 << 16);
	for (int b = 0; b < (1 << 16); ++b) {
		for (int i = 0; i < N; ++i) {
			if (b & (1 << i)) continue;
			for (int j = i + 1; j < N; ++j) {
				if (b & (1 << j)) continue;
				int k = b | (1 << i) | (1 << j);
				dp[k] = max(dp[k], dp[b] + w[i][j]);
			}
		}
	}
	return *max_element(dp.begin(), dp.end());
}

int main() {
	int64_t N;
	cin >> N;
	vector<vector<int64_t>> w(N, vector<int64_t>(N));
	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			cin >> w[i][j];
		}
	}
	cout << solve(N, w) << endl;
	return 0;
}
