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
	}

	vector<long long> get_min_costs(long long start) {
		vector<long long> min_costs(edges.size(), 1LL << 60);
		priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> q;
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

void solve(long long N, long long M, std::vector<long long>& A, std::vector<long long>& B, std::vector<long long>& C) {
	Dijkstra dijkstra(N);
	dijkstra.add_edges(A, B, C);
	for (int i = 0; i < N; i++) {
		vector<LL> costs = dijkstra.get_min_costs(i);
		LL ans = costs[i];
		cout << (ans < INF ? ans : -1) << endl;
	}
}

int main() {
	long long N, M;
	std::cin >> N >> M;
	std::vector<long long> A(M), B(M), C(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i] >> C[i];
		--A[i];
		--B[i];
	}
	solve(N, M, A, B, C);
	return 0;
}
