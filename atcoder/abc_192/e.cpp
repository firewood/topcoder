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
typedef pair<LL, LL> II;

static const LL INF = 1LL << 60;

struct Dijkstra {
	vector<vector<pair<long long, II>>> edges;

	Dijkstra(long long size) : edges(size) { }

	void add_edges(std::vector<long long>& A, std::vector<long long>& B, std::vector<long long>& C, std::vector<long long>& D) {
		for (int i = 0; i < A.size(); ++i) {
			add_edge(A[i], B[i], C[i], D[i]);
		}
	}

	void add_edge(long long a, long long b, long long c, long long d) {
		edges[a].push_back({ b, II(c, d) });
		edges[b].push_back({ a, II(c, d) });
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
				LL k = kv.second.second;
				LL next_time = ((top.first + k - 1) / k) * k;
				long long next_cost = next_time + kv.second.first;
				if (next_cost < min_costs[next_node]) {
					min_costs[next_node] = next_cost;
					q.emplace(make_pair(next_cost, next_node));
				}
			}
		}
		return min_costs;
	}
};

LL solve(long long N, long long M, long long X, long long Y, std::vector<long long>& A, std::vector<long long>& B, std::vector<long long>& T, std::vector<long long>& K) {
	Dijkstra dijkstra(N);
	dijkstra.add_edges(A, B, T, K);
	vector<long long> costs = dijkstra.get_min_costs(X);
	LL ans = costs[Y];
	return ans < INF ? ans : -1;
}

int main() {
	long long N, M, X, Y;
	std::cin >> N >> M >> X >> Y;
	--X;
	--Y;
	std::vector<long long> A(M), B(M), T(M), K(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i] >> T[i] >> K[i];
		--A[i];
		--B[i];
	}
	cout << solve(N, M, X, Y, A, B, T, K) << endl;
	return 0;
}
