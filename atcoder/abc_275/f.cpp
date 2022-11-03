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

vector<int> solve(int N, int M, std::vector<int> a) {
	vector<int> ans(M, INF);
	vector<vector<int>> dp(2, vector<int>(M + 1, INF));
	dp[0][0] = 0;
	for (int i = 0; i < N; ++i) {
		vector<vector<int>> next(2, vector<int>(M + 1, INF));
		for (int k = a[i]; k <= M; ++k) {
			next[0][k] = min({ next[0][k], dp[0][k - a[i]], dp[1][k - a[i]] });
		}
		for (int k = 0; k <= M; ++k) {
			next[1][k] = min(dp[1][k], dp[0][k] + 1);
		}
		dp = next;
	}
	for (int i = 1; i <= M; ++i) {
		int x = min(dp[0][i], dp[1][i]);
		ans[i - 1] = x < INF ? x : -1;
	}
	return ans;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	vector<int> ans = solve(N, M, a);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
