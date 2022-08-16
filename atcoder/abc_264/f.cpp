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

int64_t solve(int64_t H, int64_t W, vector<int64_t>& R, vector<int64_t>& C, const vector<string>& a) {
	int64_t ans = INF;
	vector<vector<int64_t>> dp(H + 1, vector<int64_t>(4, INF));
	dp[0] = { 0, R[0], C[0], R[0] + C[0] };
	for (int j = 0; j < W; ++j) {
		vector<vector<int64_t>> next(H + 1, vector<int64_t>(4, INF));
		for (int i = 0; i < H; ++i) {
			if (i == H - 1 && j == W - 1) {
				ans = *min_element(dp[i].begin(), dp[i].end());
			}
			for (int fi = 0; fi < 2; ++fi) {
				for (int fj = 0; fj < 2; ++fj) {
					int64_t cost = dp[i][fj * 2 + fi];
					if (cost >= INF) continue;
					int hflip = (a[i][j] ^ fj) != a[i][j + 1];
					next[i][hflip * 2 + fi] = min(next[i][hflip * 2 + fi], cost + (hflip ? C[j + 1] : 0));
					int vflip = (a[i][j] ^ fi) != a[i + 1][j];
					dp[i + 1][fj * 2 + vflip] = min(dp[i + 1][fj * 2 + vflip], cost + (vflip ? R[i + 1] : 0));
				}
			}
		}
		dp = next;
	}
	return ans;
}

int main() {
	int64_t H, W;
	cin >> H >> W;
	vector<int64_t> R(H + 1), C(W + 1);
	for (int i = 0; i < H; ++i) {
		cin >> R[i];
	}
	for (int i = 0; i < W; ++i) {
		cin >> C[i];
	}
	vector<string> a(H + 1);
	for (int i = 0; i < H; ++i) {
		cin >> a[i];
		a[i] += '0';
	}
	a[H] = string(W + 1, '0');
	cout << solve(H, W, R, C, a) << endl;
	return 0;
}
