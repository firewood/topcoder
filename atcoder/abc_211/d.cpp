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

static const int64_t MOD = 1000000007;

struct modint {
	int64_t x;
	modint() { }
	modint(int _x) : x(_x) { }
	operator int() const { return (int)x; }
	modint operator+(int y) { return (x + y + MOD) % MOD; }
	modint operator+=(int y) { x = (x + y + MOD) % MOD; return *this; }
	modint operator-(int y) { return (x - y + MOD) % MOD; }
	modint operator-=(int y) { x = (x - y + MOD) % MOD; return *this; }
	modint operator*(int y) { return (x * y) % MOD; }
	modint operator*=(int y) { x = (x * y) % MOD; return *this; }
	modint operator/(int y) { return (x * modpow(y, MOD - 2)) % MOD; }
	modint operator/=(int y) { x = (x * modpow(y, MOD - 2)) % MOD; return *this; }
	static modint modinv(int a) { return modpow(a, MOD - 2); }
	static modint modpow(int a, int b) {
		modint x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

struct Dijkstra {
	vector<vector<pair<int64_t, int64_t>>> edges;

	Dijkstra(int64_t size) : edges(size) { }

	void add_edges(std::vector<int64_t>& A, std::vector<int64_t>& B) {
		for (int i = 0; i < A.size(); ++i) {
			add_edge(A[i], B[i]);
		}
	}

	void add_edges(std::vector<int64_t>& A, std::vector<int64_t>& B, std::vector<int64_t>& C) {
		for (int i = 0; i < A.size(); ++i) {
			add_edge(A[i], B[i], C[i]);
		}
	}

	void add_edge(int64_t a, int64_t b, int64_t c = 1) {
		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}

	vector<modint> get_counts(int64_t start) {
		vector<int64_t> min_costs(edges.size(), 1LL << 60);
		vector<modint> counts(edges.size(), 0);
		priority_queue<II, vector<II>, greater<>> q;
		min_costs[start] = 0;
		counts[start] = 1;
		q.emplace(II(0, start));
		while (!q.empty()) {
			int64_t cost = q.top().first, node = q.top().second;
			q.pop();
			if (cost > min_costs[node]) {
				continue;
			}
			for (auto kv : edges[node]) {
				int64_t next_node = kv.first;
				int64_t next_cost = cost + kv.second;
				if (next_cost < min_costs[next_node]) {
					min_costs[next_node] = next_cost;
					counts[next_node] = counts[node];
					q.emplace(make_pair(next_cost, next_node));
				} else if (next_cost == min_costs[next_node]) {
					counts[next_node] += counts[node];
				}
			}
		}
		return counts;
	}
};

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> A, std::vector<int64_t> B) {
	Dijkstra dijkstra(N);
	dijkstra.add_edges(A, B);
	vector<modint> counts = dijkstra.get_counts(0);
	return counts[N - 1];
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> A(M), B(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i];
		--A[i]; --B[i];
	}
	cout << solve(N, M, std::move(A), std::move(B)) << endl;
	return 0;
}
