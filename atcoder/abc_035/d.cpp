#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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

void dijkstra(int start, const vector<vector<II>>& e, vector<LL> &min_cost) {
	priority_queue<II, vector<II>, greater<>> q;
	min_cost[start] = 0;
	q.emplace(II(0, start));
	while (!q.empty()) {
		II top = q.top();
		q.pop();
		LL cost = top.first, node = top.second;
		if (cost > min_cost[node]) continue;
		for (auto kv : e[top.second]) {
			LL next_node = kv.first;
			LL next_cost = top.first + kv.second;
			if (next_cost < min_cost[next_node]) {
				min_cost[next_node] = next_cost;
				q.emplace(II(next_cost, next_node));
			}
		}
	}
}

void solve(long long N, long long M, long long T, std::vector<long long> &A, std::vector<long long> &a, std::vector<long long> &b, std::vector<long long> &c) {
	vector<LL> min_cost_forward(N, INF), min_cost_reverse(N, INF);
	{
		vector<vector<II>> e(N);
		for (LL i = 0; i < M; ++i) {
			e[a[i]].emplace_back(II(b[i], c[i]));
		}
		dijkstra(0, e, min_cost_forward);
	}
	{
		vector<vector<II>> e(N);
		for (LL i = 0; i < M; ++i) {
			e[b[i]].emplace_back(II(a[i], c[i]));
		}
		dijkstra(0, e, min_cost_reverse);
	}
	LL ans = 0;
	for (LL i = 0; i < N; ++i) {
		if (min_cost_forward[i] <= T && min_cost_reverse[i] <= T) {
			ans = max(ans, A[i] * (T - min_cost_forward[i] - min_cost_reverse[i]));
		}
	}
	cout << ans << endl;
}

int main() {
	long long N, M, T;
	std::cin >> N >> M >> T;
	std::vector<long long> A(N), a(M), b(M), c(M);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		std::cin >> a[i]; a[i]--;
		std::cin >> b[i]; b[i]--;
		std::cin >> c[i];
	}
	solve(N, M, T, A, a, b, c);
	return 0;
}
