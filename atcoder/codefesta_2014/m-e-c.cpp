#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> II;
static const int INF = 1 << 30;

vector<int> dijkstra(int n, int s, const vector<map<int, int>>& edges) {
	vector<int> dist(n, INF);
	dist[s] = 0;
	priority_queue<II, vector<II>, greater<>> q;
	q.emplace(II(0, s));
	while (!q.empty()) {
		II top = q.top();
		q.pop();
		for (auto kv : edges[top.second]) {
			int cost = dist[top.second] + kv.second;
			if (cost < dist[kv.first]) {
				dist[kv.first] = cost;
				q.emplace(II(cost, kv.first));
			}
		}
	}
	return dist;
}

void solve(int n, int m, int s, int t, std::vector<int> &x, std::vector<int> &y, std::vector<int> &d) {
	vector<map<int, int>> edges(n);
	for (int i = 0; i < m; ++i) {
		edges[x[i]][y[i]] = d[i];
		edges[y[i]][x[i]] = d[i];
	}
	vector<int> dist_forward = dijkstra(n, s, edges);
	vector<int> dist_reverse = dijkstra(n, t, edges);
	int ans = -1;
	for (int i = 0; i < n; ++i) {
		if (i == s || i == t) continue;
		if (dist_forward[i] < INF && dist_forward[i] == dist_reverse[i]) {
			ans = i + 1;
			break;
		}
	}
	cout << ans << endl;
}

int main() {
	int n, m, s, t;
	std::cin >> n >> m >> s >> t;
	--s, --t;
	std::vector<int> x(m), y(m), d(m);
	for (int i = 0; i < m; i++) {
		std::cin >> x[i] >> y[i] >> d[i];
		--x[i], --y[i];
	}
	solve(n, m, s, t, x, y, d);
	return 0;
}
