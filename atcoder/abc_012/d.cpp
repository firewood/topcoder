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

int64_t solve(int N, int M, std::vector<int> a, std::vector<int> b, std::vector<int64_t> t) {
	vector<vector<int64_t>> dist(N, vector<int64_t>(N, 1LL << 60));
	for (int i = 0; i < M; ++i) {
		dist[a[i]][b[i]] = t[i];
		dist[b[i]][a[i]] = t[i];
	}
	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int64_t ans = 1LL << 60;
	for (int i = 0; i < N; ++i) {
		int64_t mx = 0;
		for (int j = 0; j < N; ++j) {
			if (i != j) mx = max(mx, dist[i][j]);
		}
		ans = min(ans, mx);
	}
	return ans;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> a(M), b(M);
	std::vector<int64_t> t(M);
	for (int i = 0; i < M; i++) {
		std::cin >> a[i] >> b[i] >> t[i];
		--a[i], --b[i];
	}
	cout << solve(N, M, a, b, t) << endl;
	return 0;
}
