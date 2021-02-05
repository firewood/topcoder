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

typedef long long LL;

static const LL INF = 1LL << 60;

struct Dijkstra {
	vector<vector<pair<long long, long long>>> edges;

	Dijkstra(long long size) : edges(size) { }

	void add_edges(std::vector<long long>& A, std::vector<long long>& B) {
		for (int i = 0; i < A.size(); ++i) {
			add_edge(A[i], B[i]);
		}
	}

	void add_edges(std::vector<long long>& A, std::vector<long long>& B, std::vector<long long>& C) {
		for (int i = 0; i < A.size(); ++i) {
			add_edge(A[i], B[i], C[i]);
		}
	}

	void add_edge(long long a, long long b, long long c = 1) {
		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}

	vector<long long> get_min_costs(long long start) {
		vector<long long> min_costs(edges.size(), 1LL << 60);
		priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> q;
		min_costs[start] = 0;
		q.emplace(make_pair(0, start));
		while (!q.empty()) {
			pair<long long, long long> top = q.top();
			q.pop();
			long long cost = top.first, node = top.second;
			if (cost > min_costs[node]) continue;
			for (auto kv : edges[top.second]) {
				long long next_node = kv.first;
				long long next_cost = top.first + kv.second;
				if (next_cost < min_costs[next_node]) {
					min_costs[next_node] = next_cost;
					q.emplace(make_pair(next_cost, next_node));
				}
			}
		}
		return min_costs;
	}
};

LL solve(long long N, long long M, std::vector<long long> &A, std::vector<long long> &B, long long K, std::vector<long long> &C) {
	vector<vector<LL>> dists(K, vector<LL>(K, INF)), costs(1LL << K, vector<LL>(K, INF));
	Dijkstra dijkstra(N);
	dijkstra.add_edges(A, B);
	for (int i = 0; i < K; i++) {
		costs[1LL << i][i] = 1;
		vector<long long> min_costs = dijkstra.get_min_costs(C[i]);
		for (int j = 0; j < K; ++j) {
			dists[i][j] = min_costs[C[j]];
		}
	}
	for (int b = 1; b < (1 << K); ++b) {
		for (int i = 0; i < K; ++i) {
			if (costs[b][i] >= INF) continue;
			for (int j = 0; j < K; ++j) {
				int next = b | (1 << j);
				if (next != b) {
					costs[next][j] = min(costs[next][j], costs[b][i] + dists[i][j]);
				}
			}
		}
	}
	LL ans = *min_element(costs[(1LL << K) - 1].begin(), costs[(1LL << K) - 1].end());
	return ans >= INF ? -1 : ans;
}

int main() {
    long long N, M, K;
	std::cin >> N >> M;
	std::vector<long long> A(M), B(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i];
		--A[i]; --B[i];
	}
	std::cin >> K;
	std::vector<long long> C(K);
	for (int i = 0; i < K; i++) {
		std::cin >> C[i];
		--C[i];
	}
	cout << solve(N, M, A, B, K, C) << endl;
	return 0;
}
