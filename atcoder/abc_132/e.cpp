#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <queue>
#include <vector>

using namespace std;

static const int INF = 1 << 30;

void solve(int N, int M, std::vector<int>& u, std::vector<int>& v, int S, int T) {
	vector<int> vis(N * 3);
	vector<vector<int>> e(N * 3);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < 3; ++j) {
			e[u[i] * 3 + j].emplace_back(v[i] * 3 + ((j + 1) % 3));
		}
	}
	vector<int> q(1, S * 3);
	vis[S * 3] = 1;
	int ans = -1;
	for (int t = 0; !q.empty(); ++t) {
		vector<int> nq;
		for (int node: q) {
			if (node == T * 3) {
				ans = t / 3;
				break;
			}
			for (int next : e[node]) {
				if (!vis[next]) {
					vis[next] = 1;
					nq.emplace_back(next);
				}
			}
		}
		q = nq;
	}
	cout << ans << endl;
}

int main() {
	int N, M, S, T;
	std::cin >> N >> M;
	std::vector<int> u(M), v(M);
	for (int i = 0; i < M; i++) {
		std::cin >> u[i] >> v[i];
		u[i]--, v[i]--;
	}
	std::cin >> S >> T;
	--S, --T;
	solve(N, M, u, v, S, T);
	return 0;
}
