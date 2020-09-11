#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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

typedef long long LL;

void solve(int N, int M, std::vector<long long> &x, std::vector<long long> &y) {
	vector<vector<int>> edges(N, vector<int>(N));
	vector<LL> dp(1 << N);
	dp[0] = 1;
	for (LL i = 0; i < M; ++i) {
		edges[x[i]][y[i]] = 1;
	}
	for (int b = 1; b < (1 << N); ++b) {
		for (int i = 0; i < N; ++i) {
			if ((1 << i) & b) {
				int r = (1 << i) ^ b;
				bool ok = true;
				for (int j = 0; j < N; ++j) {
					if ((1 << j) & r) {
						if (edges[j][i]) {
							ok = false;
						}
					}
				}
				if (ok) {
					dp[b] += dp[r];
				}
			}
		}
	}
	LL ans = dp[(1 << N) - 1];
	cout << ans << endl;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<long long> x(M);
	std::vector<long long> y(M);
	for (int i = 0; i < M; i++) {
		std::cin >> x[i]; x[i]--;
		std::cin >> y[i]; y[i]--;
	}
	solve(N, M, x, y);
	return 0;
}
