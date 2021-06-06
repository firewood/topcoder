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

static const int64_t INF = 1LL << 60;

struct Dijkstra {
	vector<vector<pair<int64_t, int64_t>>> edges;
	vector<int64_t> c;
	vector<int64_t> d;

	Dijkstra(int64_t size) : edges(size) { }

	void add_edges(std::vector<int64_t>& A, std::vector<int64_t>& B) {
		for (int i = 0; i < A.size(); ++i) {
			add_edge(A[i], B[i], i);
		}
	}

	void add_edge(int64_t a, int64_t b, int64_t c = 1) {
		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}

	vector<int64_t> get_min_costs(int64_t start) {
		vector<int64_t> min_costs(edges.size(), INF);
		priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>, greater<>> q;
		min_costs[start] = 0;
		q.emplace(make_pair(0, start));
		while (!q.empty()) {
			pair<int64_t, int64_t> top = q.top();
			q.pop();
			int64_t cost = top.first, node = top.second;
			if (cost > min_costs[node]) continue;
			for (auto kv : edges[top.second]) {
				int64_t next_node = kv.first, i = kv.second;
				int64_t next_cost = INF, t = max(cost, int64_t(sqrt(d[i]) - 2));
				auto calc = [&](int64_t t) {
					return t + c[i] + d[i] / (t + 1);
				};
				for (int64_t i = 0; i <= 4; ++i) {
					next_cost = min(next_cost, calc(t + i));
				}
				if (next_cost < min_costs[next_node]) {
					min_costs[next_node] = next_cost;
					q.emplace(make_pair(next_cost, next_node));
				}
			}
		}
		return min_costs;
	}
};

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> A, std::vector<int64_t> B, std::vector<int64_t> C, std::vector<int64_t> D) {
	Dijkstra d(N);
	d.c = C;
	d.d = D;
	d.add_edges(A, B);
	vector <int64_t> costs = d.get_min_costs(0);
	int64_t ans = costs[N - 1];
	return ans < INF ? ans : -1;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> A(M), B(M), C(M), D(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i] >> C[i] >> D[i];
		--A[i], --B[i];
	}
	cout << solve(N, M, std::move(A), std::move(B), std::move(C), std::move(D)) << endl;
	return 0;
}
