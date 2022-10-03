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

int64_t solve(int64_t N, int64_t M, int64_t K, std::vector<int64_t> A, std::vector<int64_t> B, std::vector<int64_t> C, std::vector<int64_t> E) {
	vector<int64_t> cost(N, INF);
	cost[0] = 0;
	for (int ei : E) {
		if (cost[A[ei]] < INF) {
			cost[B[ei]] = min(cost[B[ei]], cost[A[ei]] + C[ei]);
		}
	}
	return cost[N - 1] < INF ? cost[N - 1] : -1;
}

int main() {
	int64_t N, M, K;
	std::cin >> N >> M >> K;
	std::vector<int64_t> A(M), B(M), C(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i] >> C[i];
		--A[i]; --B[i];
	}
	std::vector<int64_t> E(K);
	for (int i = 0; i < K; i++) {
		std::cin >> E[i];
		--E[i];
	}
	cout << solve(N, M, K, A, B, C, E) << endl;
	return 0;
}
