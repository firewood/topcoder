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
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;
static const LL INF = 1LL << 60;

void solve(long long N, long long M, std::vector<long long> u, std::vector<long long> v, std::vector<long long> l) {
	vector<vector<LL>> dist(N, vector<LL>(N, INF));
	for (int i = 0; i < M; i++) {
		if (u[i] != 0 && v[i] != 0) {
			dist[u[i]][v[i]] = l[i];
			dist[v[i]][u[i]] = l[i];
		}
	}
	for (LL k = 0; k < N; ++k) {
		for (LL i = 0; i < N; ++i) {
			for (LL j = 0; j < N; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 0; i < M; i++) {
		if (u[i] == 0 || v[i] == 0) {
			dist[u[i]][v[i]] = l[i];
			dist[v[i]][u[i]] = l[i];
		}
	}
	LL ans = INF;
	for (LL i = 1; i < N; ++i) {
		if (dist[0][i] < INF) {
			for (LL j = i + 1; j < N; ++j) {
				if (dist[0][j] < INF) {
					ans = min(ans, dist[0][i] + dist[0][j] + dist[i][j]);
				}
			}
		}
	}
	cout << (ans < INF ? ans : -1) << endl;
}

int main() {
    long long N;
	scanf("%lld", &N);
	long long M;
	scanf("%lld", &M);
	std::vector<long long> u(M);
	std::vector<long long> v(M);
	std::vector<long long> l(M);
	for (int i = 0; i < M; i++) {
		scanf("%lld", &u[i]); u[i]--;
		scanf("%lld", &v[i]); v[i]--;
		scanf("%lld", &l[i]);
	}
	solve(N, M, u, v, l);
	return 0;
}
