// Google Code Jam 2022 Round 1B
// Problem B. Controlled Inflation (14pts, 21pts)

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>
#include <cassert>
#include <cmath>
#ifdef _WIN32
#include <Windows.h>
#endif

using namespace std;

const int64_t INF = 1LL << 60;

int64_t solve(int N, int P, const vector<vector<int64_t>> &x) {
	vector<vector<int64_t>> w(1, { 0, 0 });
	for (auto& y : x) {
		w.push_back({ *min_element(y.begin(), y.end()), *max_element(y.begin(), y.end()) });
	}
	vector<int64_t> dp(2);
	for (int i = 1; i <= N; ++i) {
		vector<int64_t> next(2, INF);
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				int64_t cost = dp[j] + abs(w[i - 1][j] - w[i][k ^ 1]) + abs(w[i][k ^ 1] - w[i][k]);
				next[k] = min(next[k], cost);
			}
		}
		dp = next;
	}
	return *min_element(dp.begin(), dp.end());
}

int main(int argc, char* argv[]) {
	int T, N, P;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N >> P;
		vector<vector<int64_t>> x(N, vector<int64_t>(P));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < P; ++j) {
				cin >> x[i][j];
			}
		}
		int64_t ans = solve(N, P, x);
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
