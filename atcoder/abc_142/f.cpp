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

vector<int> solve(int N, int M, std::vector<int> A, std::vector<int> B) {
	vector<int> ans, vis(N);
	vector<vector<int>> edges(N);
	for (int i = 0; i < M; ++i) {
		edges[A[i]].emplace_back(i);
	}
	for (int start = 0; start < M; ++start) {
		fill(vis.begin(), vis.end(), -1);
		vis[B[start]] = A[start];
		vector<int> q = { B[start] };
		while (!q.empty()) {
			vector<int> nq;
			for (auto node : q) {
				for (auto ei : edges[node]) {
					if (B[ei] == A[start]) {
						vector<int> path;
						while (node != A[start]) {
							path.emplace_back(node);
							node = vis[node];
						}
						path.emplace_back(node);
						if (ans.empty() || ans.size() > path.size()) {
							reverse(path.begin(), path.end());
							ans = path;
						}
						goto done;
					}
					if (vis[B[ei]] >= 0) {
						goto done;
					}
					vis[B[ei]] = node;
					nq.emplace_back(B[ei]);
				}
			}
			q = nq;
		}
	done:
		{}
	}
	return ans;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> A(M), B(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i];
		--A[i]; --B[i];
	}
	vector<int> ans = solve(N, M, A, B);
	if (!ans.empty()) {
		cout << ans.size() << endl;
		for (size_t i = 0; i < ans.size(); ++i) {
			cout << (ans[i] + 1) << endl;
		}
	} else {
		cout << -1 << endl;
	}
	return 0;
}
