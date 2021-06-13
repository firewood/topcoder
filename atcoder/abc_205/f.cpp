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
#include <atcoder/maxflow>

using namespace std;
using namespace atcoder;

int64_t solve(int64_t H, int64_t W, int64_t N, std::vector<int64_t> A, std::vector<int64_t> B, std::vector<int64_t> C, std::vector<int64_t> D) {
	mf_graph<int> g(2 + H + N * 2 + W);
	for (int r = 0; r < H; ++r) {
		g.add_edge(0, 1 + r, 1);
	}
	for (int i = 0; i < N; i++) {
		for (int r = A[i]; r <= C[i]; ++r) {
			g.add_edge(1 + r, 1 + H + i, 1);
		}
		g.add_edge(1 + H + i, 1 + H + N + i, 1);
		for (int c = B[i]; c <= D[i]; ++c) {
			g.add_edge(1 + H + N + i, 1 + H + N * 2 + c, 1);
		}
	}
	for (int c = 0; c < W; ++c) {
		g.add_edge(1 + H + N * 2 + c, 1 + H + N * 2 + W, 1);
	}
	int ans = g.flow(0, 1 + H + N * 2 + W);
	return ans;
}

int main() {
	int64_t H, W, N;
	std::cin >> H >> W >> N;
	std::vector<int64_t> A(N), B(N), C(N), D(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i] >> B[i] >> C[i] >> D[i];
		--A[i], --B[i], --C[i], --D[i];
	}
	cout << solve(H, W, N, A, B, C, D) << endl;
	return 0;
}
