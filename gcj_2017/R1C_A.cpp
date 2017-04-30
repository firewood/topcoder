// Google Code Jam 2017 Round 1C
// Problem A. Ample Syrup

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
typedef vector<II> IIVec;

double solve() {
	LL dp[1002][1002] = {};
	int N, K;
	cin >> N >> K;
	IIVec v;
	for (int i = 0; i < N; ++i) {
		LL r, h;
		cin >> r >> h;
		v.push_back(II(r, h));
	}
	sort(v.begin(), v.end());
	LL m = 0;
	for (int i = 0; i < N; ++i) {
		LL r = 2 * v[i].first * v[i].second;
		for (int j = 0; j < K; ++j) {
			dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i][j] + r);
		}
		m = max(m, dp[i][K - 1] + r + v[i].first * v[i].first);
	}
	return M_PI * m;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		double ans = solve();
		printf("Case #%d: %.7f\n", t, ans);
	}
	return 0;
}
