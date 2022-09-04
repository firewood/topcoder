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

typedef pair<int64_t, int64_t> II;

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> A, std::vector<int64_t> U, std::vector<int64_t> V) {
	vector<int64_t> costs(N), done(N);
	vector<vector<int64_t>> e(N);
	for (int i = 0; i < M; ++i) {
		e[U[i]].emplace_back(V[i]);
		e[V[i]].emplace_back(U[i]);
		costs[U[i]] += A[V[i]];
		costs[V[i]] += A[U[i]];
	}
	priority_queue<II, vector<II>, greater<>> q;
	for (int64_t i = 0; i < N; ++i) {
		q.emplace(II(costs[i], i));
	}
	int64_t ans = 0;
	while (!q.empty()) {
		int64_t cost = q.top().first, node = q.top().second;
		q.pop();
		if (cost < ans || cost == costs[node]) {
			done[node] = 1;
			ans = max(ans, cost);
			for (auto x : e[node]) {
				costs[x] -= A[node];
				if (!done[x]) {
					q.emplace(II(costs[x], x));
				}
			}
		}
	}
	return ans;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<int64_t> U(M), V(M);
	for (int i = 0; i < M; i++) {
		std::cin >> U[i] >> V[i];
		--U[i];
		--V[i];
	}
	cout << solve(N, M, A, U, V) << endl;
	return 0;
}
