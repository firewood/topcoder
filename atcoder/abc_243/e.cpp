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

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> A, std::vector<int64_t> B, std::vector<int64_t> C) {
	int64_t ans = 0;
	vector<vector< int64_t>> dist(N, vector< int64_t>(N, INF));
	for (int i = 0; i < M; ++i) {
		dist[A[i]][B[i]] = dist[B[i]][A[i]] = C[i];
	}
	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 0; i < M; ++i) {
		int64_t a = A[i], b = B[i], c = C[i];
		for (int j = 0; j < N; ++j) {
			if (dist[a][b] == dist[a][j] + dist[j][b]) {
				++ans;
				break;
			}
		}
	}
	return ans;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> A(M), B(M), C(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i] >> C[i];
		--A[i], --B[i];
	}
	cout << solve(N, M, A, B, C) << endl;
	return 0;
}
