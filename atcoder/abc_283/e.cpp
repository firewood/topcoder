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

static const int INF = 1 << 30;

int solve(int H, int W, std::vector<std::vector<int>> A) {
	int ans = INF;
	while (H <= 2) {
		++H;
		A.emplace_back(A.back());
	}
	auto check = [&](int top_y, bool check_top, bool check_bottom, const vector<int>& state) {
		for (int i = 0; i < 3; ++i) {
			if (i == 0 && !check_top) continue;
			if (i == 2 && !check_bottom) continue;
			int y = top_y + i;
			for (int j = 0; j < W; ++j) {
				if ((j > 0 && A[y][j - 1] == A[y][j]) || ((j < W - 1 && A[y][j] == A[y][j + 1]))) {
					continue;
				}
				if ((i <= 1 && (A[y][j] == A[y + 1][j]) == (state[i] == state[i + 1])) ||
					(i >= 1 && (A[y][j] == A[y - 1][j]) == (state[i] == state[i - 1]))) {
					;
				} else {
					return false;
				}
			}
		}
		return true;
	};
	vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(2, INF)));
	int last_y = H - 3;
	for (int y = 0; y <= last_y; ++y) {
		vector<vector<vector<int>>> next(2, vector<vector<int>>(2, vector<int>(2, INF)));
		for (int a = 0; a < 2; ++a) {
			for (int b = 0; b < 2; ++b) {
				for (int c = 0; c < 2; ++c) {
					int prev = y == 0 ? a + b : min(dp[0][a][b], dp[1][a][b]);
					if (prev < INF && check(y, y == 0, y == last_y, { a,b,c })) {
						next[a][b][c] = prev + c;
						if (y == last_y) {
							ans = min(ans, prev + c);
						}
					}
				}
			}
		}
		dp = next;
	}
	return ans < INF ? ans : -1;
}

int main() {
	int H, W;
	std::cin >> H >> W;
	std::vector<std::vector<int>> A(H, std::vector<int>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			std::cin >> A[i][j];
		}
	}
	cout << solve(H, W, A) << endl;
	return 0;
}
