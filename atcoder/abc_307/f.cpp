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

typedef pair<int64_t, int> II;

vector<int64_t> solve(int64_t N, int64_t M, std::vector<int> U, std::vector<int> V, std::vector<int64_t> W, int64_t K, std::vector<int> A, int64_t D, std::vector<int64_t> X) {
	vector<int64_t> ans(N, -1);

	vector<multimap<int64_t, int>> e(N);
	for (int i = 0; i < M; ++i) {
		e[U[i]].insert(make_pair(W[i], V[i]));
		e[V[i]].insert(make_pair(W[i], U[i]));
	}

	priority_queue<II, vector<II>, greater<>> q;

	for (int node : A) {
		ans[node] = 0;
		for (auto kv : e[node]) {
			q.emplace(kv);
		}
	}

	for (int d = 1; d <= D; ++d) {
		set<int> next_nodes;
		priority_queue<II> q2;
		int64_t x = X[d - 1];

		while (!q.empty() && q.top().first <= x) {
			int64_t r = x - q.top().first;
			int node = q.top().second;
			q.pop();
			if (ans[node] < 0) {
				next_nodes.insert(node);
				q2.emplace(II(r, node));
			}
		}

		while (!q2.empty()) {
			int64_t r = q2.top().first;
			int node = q2.top().second;
			q2.pop();
			if (ans[node] < 0) {
				ans[node] = d;
				while (!e[node].empty()) {
					auto it = e[node].begin();
					if (ans[it->second] < 0) {
						if (it->first > r) {
							break;
						}
						next_nodes.insert(it->second);
						q2.emplace(II(r - it->first, it->second));
					}
					e[node].erase(it);
				}
			}
		}

		for (auto node : next_nodes) {
			for (auto kv : e[node]) {
				if (ans[kv.second] < 0) {
					q.emplace(kv);
				}
			}
		}
	}

	return ans;
}

int main() {
	int64_t N, M, K, D;
	std::cin >> N >> M;
	std::vector<int> U(M), V(M);
	std::vector<int64_t> W(M);
	for (int i = 0; i < M; i++) {
		std::cin >> U[i] >> V[i] >> W[i];
		--U[i];
		--V[i];
	}
	std::cin >> K;
	std::vector<int> A(K);
	for (int i = 0; i < K; i++) {
		std::cin >> A[i];
		--A[i];
	}
	std::cin >> D;
	std::vector<int64_t> X(D);
	for (int i = 0; i < D; i++) {
		std::cin >> X[i];
	}
	vector<int64_t> ans = solve(N, M, U, V, W, K, A, D, X);
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;
}
