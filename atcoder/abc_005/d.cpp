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

void solve(long long N, std::vector<std::vector<long long>> &D, long long Q, std::vector<long long> &P) {
	vector<vector<LL>> sum(N + 1, vector<LL>(N + 1));
	for (LL i = 0; i < N; ++i) {
		for (LL j = 0; j < N; ++j) {
			sum[i + 1][j + 1] = sum[i + 1][j] + D[i][j];
		}
	}
	for (LL i = 0; i < N; ++i) {
		for (LL j = 0; j < N; ++j) {
			sum[i + 1][j + 1] += sum[i][j + 1];
		}
	}
	for (LL q = 0; q < Q; ++q) {
		LL ans = 0;
		for (LL i = 0; i < N; ++i) {
			for (LL j = 0; j < N; ++j) {
				for (LL k = 1; i + k <= N; ++k) {
					for (LL l = 1; j + l <= N; ++l) {
						if (k * l > P[q]) break;
						ans = max(ans, sum[i + k][j + l] - sum[i][j + l] - sum[i + k][j] + sum[i][j]);
					}
				}
			}
		}
		cout << ans << endl;
	}
}

int main() {
    long long N;
	std::cin >> N;
	std::vector<std::vector<long long>> D(N, std::vector<long long>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> D[i][j];
		}
	}
	long long Q;
	std::cin >> Q;
	std::vector<long long> P(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> P[i];
	}
	solve(N, D, Q, P);
	return 0;
}
