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
#include <atcoder/maxflow>

using namespace std;
using namespace atcoder;

typedef long long LL;

const int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

void solve(long long N, long long M, std::vector<std::string> &S) {
	mf_graph<int> g(N * M + 2);
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			if (S[r][c] == '#') continue;
			if ((r + c) % 2) {
				g.add_edge(r * M + c, N * M + 1, 1);
				continue;
			}
			g.add_edge(N * M, r * M + c, 1);
			for (int d = 0; d < 4; ++d) {
				int y = r + dy[d], x = c + dx[d];
				if (x >= 0 && x < M && y >= 0 && y < N) {
					if (S[y][x] != '#') {
						g.add_edge(r * M + c, y * M + x, 1);
					}
				}
			}
		}
	}
	int ans = g.flow(N * M, N * M + 1);
	cout << ans << endl;
	for (auto edge : g.edges()) {
		if (edge.flow != 1) continue;
		int a = edge.from;
		int b = edge.to;
		if (a > b) swap(a, b);
		if (b >= N * M) continue;
		if (a + M == b) {
			S[a / M][a % M] = 'v';
			S[b / M][b % M] = '^';
		} else {
			// a + 1 == b, except for M == 1
			S[a / M][a % M] = '>';
			S[b / M][b % M] = '<';
		}
	}
	for (auto s : S) {
		cout << s << endl;
	}
}

int main() {
	long long N, M;
	std::cin >> N >> M;
	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	solve(N, M, S);
	return 0;
}
