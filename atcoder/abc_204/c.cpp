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

int64_t solve(int N, int M, std::vector<int> A, std::vector<int> B) {
	int64_t ans = 0;
	vector<vector<int>> edges(N);
	for (int i = 0; i < M; ++i) {
		edges[A[i]].emplace_back(B[i]);
	}
	for (int i = 0; i < N; ++i) {
		vector<int> vis(N), q(1, i);
		vis[i] = 1;
		while (!q.empty()) {
			vector<int> nq;
			for (auto from : q) {
				for (auto to : edges[from]) {
					if (!vis[to]) {
						vis[to] = 1;
						nq.emplace_back(to);
					}
				}
			}
			q = nq;
		}
		ans += accumulate(vis.begin(), vis.end(), 0);
	}
	return ans;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> A(M), B(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i];
		--A[i], --B[i];
	}
	cout << solve(N, M, std::move(A), std::move(B)) << endl;
	return 0;
}
