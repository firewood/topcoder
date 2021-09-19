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

static const int INF = 1 << 29;

int solve(int N, int X, int Y, std::vector<int> A, std::vector<int> B) {
	vector<vector<int>> dp(301, vector<int>(301, INF));
	dp[0][0] = 0;
	for (int i = 0; i < N; ++i) {
		vector<vector<int>> next = dp;
		for (int j = 0; j <= 300; ++j) {
			int a = min(300, j + A[i]);
			for (int k = 0; k <= 300; ++k) {
				int b = min(300, k + B[i]);
				next[a][b] = min(next[a][b], dp[j][k] + 1);
			}
		}
		dp = next;
	}
	int ans = INF;
	for (int j = X; j <= 300; ++j) {
		for (int k = Y; k <= 300; ++k) {
			ans = min(ans, dp[j][k]);
		}
	}
	return ans < INF ? ans : -1;
}

int main() {
	int N, X, Y;
	std::cin >> N >> X >> Y;
	std::vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i] >> B[i];
	}
	cout << solve(N, X, Y, A, B) << endl;
	return 0;
}
